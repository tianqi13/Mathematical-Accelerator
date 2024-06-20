import socket

def send_message(client, message):
    client.send(message.encode('utf-8'))
    response = client.recv(1024).decode('utf-8')
    print(f"Received from server: {response}")

def start_client(ip='192.168.2.99', port=65434):
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((ip, port))
    print(f"Connected to server {ip}:{port}")
    return client