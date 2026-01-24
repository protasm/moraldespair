#!/usr/bin/env python3

from http.server import BaseHTTPRequestHandler, HTTPServer
import json
import sys

HOST = "127.0.0.1"
PORT = 8000

class Handler(BaseHTTPRequestHandler):
    # 🔑 CRITICAL: ERQ behaves correctly with HTTP/1.0
    protocol_version = "HTTP/1.0"

    def do_POST(self):
        print(f"[proxy] incoming request: method={self.command} path={self.path} "
              f"client={self.client_address}", flush=True)
        print(f"[proxy] incoming headers: {dict(self.headers)}", flush=True)
        if self.path != "/query":
            print("[proxy] reject: unexpected path", flush=True)
            self.send_error(404, "Not Found")
            return

        try:
            length = int(self.headers.get("Content-Length", 0))
            body = self.rfile.read(length)
            print(f"[proxy] incoming body length={length} raw={body!r}",
                  flush=True)
            print(f"[proxy] incoming body decoded={body.decode('utf-8', 'replace')}",
                  flush=True)
            data = json.loads(body.decode("utf-8"))
        except Exception as exc:
            print(f"[proxy] error parsing request: {exc!r}", flush=True)
            self.send_error(400, "Bad Request")
            self.close_connection = True
            return

        response = {
            "status": "ok",
            "received": data,
            "message": "Hello from AI proxy"
        }

        out = json.dumps(response).encode("utf-8")
        print(f"[proxy] outgoing status=200 body={response!r}", flush=True)
        print(f"[proxy] outgoing bytes length={len(out)} raw={out!r}",
              flush=True)

        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(out)))
        self.send_header("Connection", "close")
        self.end_headers()

        self.wfile.write(out)
        self.wfile.flush()

        # Explicit close (belt + suspenders)
        self.close_connection = True

    def log_message(self, format, *args):
        return

def main():
    server = HTTPServer((HOST, PORT), Handler)
    print(f"AI proxy listening on http://{HOST}:{PORT}/query (HTTP/1.0)")
    server.serve_forever()

if __name__ == "__main__":
    main()
