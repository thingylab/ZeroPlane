import ZeroPlane_pb2
import zmq

def subscribe():
    ctx = zmq.Context()
    socket = ctx.socket(zmq.SUB)
    socket.connect("tcp://localhost:5556")
    socket.setsockopt(zmq.SUBSCRIBE, b"")
    
    while True:
        msg = socket.recv()

        pb = ZeroPlane_pb2.Message()
        pb.ParseFromString(msg)
        print(pb)

if __name__ == "__main__":
    subscribe()