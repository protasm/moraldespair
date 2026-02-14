#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DRIVER_BIN="$ROOT_DIR/fluffos/build/bin/driver"
LOG_DIR="$ROOT_DIR/log"
PID_FILE="$LOG_DIR/driver.pid"
STDOUT_LOG="$LOG_DIR/driver.stdout"
PORT="${PORT:-3003}"

if [[ ! -x "$DRIVER_BIN" ]]; then
  echo "Driver not found or not executable: $DRIVER_BIN"
  echo "Build FluffOS first (binary expected at fluffos/build/bin/driver)."
  exit 1
fi

mkdir -p "$LOG_DIR"

stop_pid_if_running() {
  local pid="$1"
  local i

  if [[ -z "$pid" ]]; then
    return 0
  fi

  if ! kill -0 "$pid" 2>/dev/null; then
    return 0
  fi

  echo "Stopping existing FluffOS process (pid $pid)..."
  kill "$pid" 2>/dev/null || true

  i=0
  while kill -0 "$pid" 2>/dev/null; do
    if [[ "$i" -ge 20 ]]; then
      echo "Process did not exit after 10s, sending SIGKILL..."
      kill -9 "$pid" 2>/dev/null || true
      break
    fi

    sleep 0.5
    i=$((i + 1))
  done
}

find_listen_pid_for_port() {
  lsof -nP -iTCP:"$PORT" -sTCP:LISTEN 2>/dev/null | awk 'NR>1 {print $2; exit}'
}

stop_listener_on_port() {
  local port_pid

  port_pid="$(find_listen_pid_for_port || true)"

  if [[ -z "$port_pid" ]]; then
    return 0
  fi

  stop_pid_if_running "$port_pid"
}

if [[ -f "$PID_FILE" ]]; then
  OLD_PID="$(cat "$PID_FILE" 2>/dev/null || true)"

  if [[ -n "${OLD_PID}" ]]; then
    stop_pid_if_running "$OLD_PID"
  fi

  rm -f "$PID_FILE"
fi

stop_listener_on_port

# Start each run with fresh logs for easier debugging.
: > "$LOG_DIR/debug"
: > "$LOG_DIR/compile"
: > "$STDOUT_LOG"

cd "$ROOT_DIR"
nohup "$DRIVER_BIN" core/config.local >> "$STDOUT_LOG" 2>&1 &
NEW_PID="$!"
echo "$NEW_PID" > "$PID_FILE"

sleep 1

if kill -0 "$NEW_PID" 2>/dev/null; then
  echo "FluffOS started."
  echo "pid: $NEW_PID"
  echo "stdout: $STDOUT_LOG"
  echo "debug:  $LOG_DIR/debug"
  echo "compile:$LOG_DIR/compile"
else
  echo "FluffOS failed to stay running."
  echo "Recent stdout:"
  tail -n 60 "$STDOUT_LOG" || true
  exit 1
fi
