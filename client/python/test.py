import zmq

def subscribe():
    ctx = zmq.Context()
    socket = ctx.socket(zmq.SUB)
    socket.connect("tcp://localhost:5556")
    socket.setsockopt(zmq.SUBSCRIBE, b"")

    while True:
        msg = socket.recv_multipart()
        print("-> {0}".format(msg))

if __name__ == "__main__":
    subscribe()