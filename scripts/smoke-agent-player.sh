#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
HOST="${HOST:-127.0.0.1}"
PORT="${PORT:-4303}"
PASSWORD="${PASSWORD:-C0dex!123}"
LOG_DIR="$ROOT_DIR/log"
TRANSCRIPT="${TRANSCRIPT:-$LOG_DIR/smoke-agent-player.$(date +%Y%m%d-%H%M%S).log}"

usage() {
  cat <<'EOF'
Usage:
  scripts/smoke-agent-player.sh [--ensure-running]

Environment overrides:
  HOST=127.0.0.1
  PORT=4303
  PASSWORD='C0dex!123'
  TRANSCRIPT=/path/to/logfile
  ACCOUNT_NAME=<generated if omitted>
  AVATAR_NAME=<generated if omitted>
EOF
}

random_letters() {
  local len="$1"
  local chars
  local i
  local idx
  local out

  chars="abcdefghijklmnopqrstuvwxyz"
  i=0
  out=""

  while [[ "$i" -lt "$len" ]]; do
    idx=$((RANDOM % 26))
    out="${out}${chars:$idx:1}"
    i=$((i + 1))
  done

  printf "%s" "$out"
}

ensure_running=0

if [[ "${1:-}" == "--ensure-running" ]]; then
  ensure_running=1
elif [[ -n "${1:-}" ]]; then
  usage
  exit 1
fi

if [[ -z "${ACCOUNT_NAME:-}" ]]; then
  ACCOUNT_NAME="agent$(random_letters 6)"
fi

if [[ -z "${AVATAR_NAME:-}" ]]; then
  AVATAR_NAME="Agent$(random_letters 5)"
fi

mkdir -p "$LOG_DIR"

if ! command -v nc >/dev/null 2>&1; then
  echo "Missing dependency: nc"
  exit 1
fi

if [[ "$ensure_running" -eq 1 ]]; then
  if ! lsof -nP -iTCP:"$PORT" -sTCP:LISTEN >/dev/null 2>&1; then
    "$ROOT_DIR/scripts/start-agent-fluffos.sh"
    sleep 1
  fi
fi

if ! lsof -nP -iTCP:"$PORT" -sTCP:LISTEN >/dev/null 2>&1; then
  echo "No listener detected on $HOST:$PORT"
  echo "Start the sandbox first: scripts/start-agent-fluffos.sh"
  exit 1
fi

{
  sleep 0.4
  printf "create\n"
  sleep 0.2
  printf "%s\n" "$ACCOUNT_NAME"
  sleep 0.2
  printf "%s\n" "$PASSWORD"
  sleep 0.2
  printf "%s\n" "$PASSWORD"
  sleep 0.2
  printf "%s\n" "$AVATAR_NAME"
  sleep 0.3
  printf "look\n"
  sleep 0.2
  printf "south\n"
  sleep 0.2
  printf "look\n"
  sleep 0.2
  printf "east\n"
  sleep 0.2
  printf "look\n"
  sleep 0.2
  printf "quit\n"
} | nc -w 8 "$HOST" "$PORT" >"$TRANSCRIPT" 2>&1 || true

required_patterns=(
  "Enter account name"
  "Choose a new account name"
  "Enter a name for your new avatar"
  "Exits:"
  "Bye."
)

for pattern in "${required_patterns[@]}"; do
  if ! rg -q "$pattern" "$TRANSCRIPT"; then
    echo "Smoke test failed: missing '$pattern' in transcript."
    echo "Transcript: $TRANSCRIPT"
    exit 1
  fi
done

echo "Smoke test passed."
echo "account:  $ACCOUNT_NAME"
echo "avatar:   $AVATAR_NAME"
echo "password: $PASSWORD"
echo "host:port $HOST:$PORT"
echo "log:      $TRANSCRIPT"
