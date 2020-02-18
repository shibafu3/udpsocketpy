import socket

# データバッファとアドレスバッファ
data=''
address=''
# ソケット作成
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# 受信IP指定なし、ポート6000
sock.bind(('',12345))
# ブロッキング無し
sock.setblocking(0)

while True:
    try:
        data,address = sock.recvfrom(120)
    except socket.error:
        pass
    else:
        print(str(data))
