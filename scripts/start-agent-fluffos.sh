#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DRIVER_BIN="$ROOT_DIR/fluffos/build/bin/driver"
CONFIG_FILE="$ROOT_DIR/core/config.agent.local"
LOG_DIR="$ROOT_DIR/log"
PID_FILE="$LOG_DIR/driver.agent.pid"
STDOUT_LOG="$LOG_DIR/driver.agent.stdout"

if [[ ! -x "$DRIVER_BIN" ]]; then
  echo "Driver not found or not executable: $DRIVER_BIN"
  echo "Build FluffOS first (binary expected at fluffos/build/bin/driver)."
  exit 1
fi

if [[ ! -f "$CONFIG_FILE" ]]; then
  echo "Config not found: $CONFIG_FILE"
  exit 1
fi

mkdir -p "$LOG_DIR"
: > "$STDOUT_LOG"

cd "$ROOT_DIR"
nohup "$DRIVER_BIN" "$CONFIG_FILE" >> "$STDOUT_LOG" 2>&1 &
NEW_PID="$!"
echo "$NEW_PID" > "$PID_FILE"

sleep 1

if kill -0 "$NEW_PID" 2>/dev/null; then
  echo "Agent FluffOS started."
  echo "pid: $NEW_PID"
  echo "stdout: $STDOUT_LOG"
  echo "debug:  $LOG_DIR/debug.agent"
  echo "ports:  telnet=4303 websocket=4304 websocket_tls=4305 telnet_tls=4306"
else
  echo "Agent FluffOS failed to stay running."
  echo "Recent stdout:"
  tail -n 80 "$STDOUT_LOG" || true
  exit 1
fi
