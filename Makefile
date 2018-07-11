# Makefile for the socket programming example
#

simple_server_objects = ServerSocket.o Socket.o servermain.o
simple_client_objects = ClientSocket.o Socket.o clientmain.o

#GPP = arm-none-linux-gnueabi-g++
GPP = g++ -pthread

all : simple_server simple_client

simple_server: $(simple_server_objects)
	$(GPP) -o simple_server $(simple_server_objects)


simple_client: $(simple_client_objects)
	$(GPP) -o simple_client $(simple_client_objects)

%.o : %.cpp
	$(GPP) -c $^ -o $@


#Socket: Socket.cpp
#ServerSocket: ServerSocket.cpp
#ClientSocket: ClientSocket.cpp
#servermain: servermain.cpp
#clientmain: clientmain.cpp


clean:
	rm -f *.o simple_server simple_client
