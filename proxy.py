#!/usr/bin/env python3

from http.server import BaseHTTPRequestHandler, HTTPServer
import json

HOST = "127.0.0.1"
PORT = 8000

class Handler(BaseHTTPRequestHandler):
    # 🔑 CRITICAL: ERQ behaves correctly with HTTP/1.0
    protocol_version = "HTTP/1.0"

    def do_POST(self):
        if self.path != "/query":
            self.send_error(404, "Not Found")
            return

        try:
            length = int(self.headers.get("Content-Length", 0))
            body = self.rfile.read(length)
            data = json.loads(body.decode("utf-8"))
        except Exception:
            self.send_error(400, "Bad Request")
            self.close_connection = True
            return

        response = {
            "status": "ok",
            "received": data,
            "message": "Hello from AI proxy"
        }

        out = json.dumps(response).encode("utf-8")

        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(out)))
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

