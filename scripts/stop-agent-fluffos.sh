#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
LOG_DIR="$ROOT_DIR/log"
PID_FILE="$LOG_DIR/driver.agent.pid"
PORT="${PORT:-4303}"

stop_pid_if_running() {
  local pid="$1"
  local i

  if [[ -z "$pid" ]]; then
    return 0
  fi

  if ! kill -0 "$pid" 2>/dev/null; then
    return 0
  fi

  echo "Stopping agent FluffOS process (pid $pid)..."
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

if [[ -f "$PID_FILE" ]]; then
  OLD_PID="$(cat "$PID_FILE" 2>/dev/null || true)"

  if [[ -n "${OLD_PID}" ]]; then
    stop_pid_if_running "$OLD_PID"
  fi

  rm -f "$PID_FILE"
fi

LISTEN_PID="$(find_listen_pid_for_port || true)"

if [[ -n "${LISTEN_PID}" ]]; then
  stop_pid_if_running "$LISTEN_PID"
fi

echo "Agent FluffOS stopped (or was not running)."
