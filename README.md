## Chit chat server
To build this project, follow the steps below:
```
cd build
cmake ../
make
```
This will generate two executables, `server` and `client`, which you can run by `./server` and `./client` respectively. 

## 💬 Server (server.cpp)

- [ ] Create and bind a TCP socket (socket(), bind(), listen())

- [ ]  Use select() to handle multiple client sockets

- [ ] Accept new client connections and store their file descriptors

- [ ]  Read data from connected clients

- [ ] Broadcast each received message to all other clients

- [ ] Handle client disconnects (remove closed sockets)

## 👤 Client (client.cpp)

- [ ] Connect to server using socket() + connect()

- [ ] Launch a std::thread to receive messages from server continuously

- [ ] Use the main thread to read user input and send to server

- [ ] Gracefully handle disconnects (e.g., Ctrl+C)
