import socket

dstip = "127.0.0.1"
dstport = 12345
message = b"from RPi2"

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(message, (dstip, dstport))
