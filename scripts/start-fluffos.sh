#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DRIVER_BIN="$ROOT_DIR/fluffos/build/bin/driver"
LOG_DIR="$ROOT_DIR/log"
PID_FILE="$LOG_DIR/driver.pid"
STDOUT_LOG="$LOG_DIR/driver.stdout"

if [[ ! -x "$DRIVER_BIN" ]]; then
  echo "Driver not found or not executable: $DRIVER_BIN"
  echo "Build FluffOS first (binary expected at fluffos/build/bin/driver)."
  exit 1
fi

mkdir -p "$LOG_DIR"

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
