#!/usr/bin/python3

import socketserver

import signal
import sys
import time
import threading

server = None

def shutdown():
	global server
	server.shutdown()
	
def handler(signal, frame):
	t = threading.Timer(0.1, shutdown)
	t.start()


class MyTCPHandler(socketserver.BaseRequestHandler):
    """
    The RequestHandler class for our server.

    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client
        self.data = self.request.recv(4096)
        #print("{} wrote:".format(self.client_address[0]))
        print(self.data )
        # just send back the same data, but upper-cased
        # self.request.sendall(self.data.upper())

if __name__ == "__main__":
    HOST, PORT = "localhost", 6666
    
    # Create the server, binding to localhost on port 9999
    server = socketserver.TCPServer((HOST, PORT), MyTCPHandler)

    signal.signal(signal.SIGINT, handler)
    signal.signal(signal.SIGTERM, handler)


    server.serve_forever(0.1)

