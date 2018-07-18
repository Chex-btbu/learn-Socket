#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include "ServerSocket.h"

void* startServer( void* args  )
{
	
}

int main ( int argc, int argv[] )
{
	std::cout << "Server running....\n";
	try
	{
		// Create the socket
		ServerSocket server ( 30000 );
		
		while ( 1 )
		{
			ServerSocket new_sock;
			server.accept ( new_sock );
			try
			{
				while ( 1 )
				{
					std::string data;
					new_sock >> data;
					new_sock << "I receive: " + data;
				}
			}
			catch ( SocketException& ){}
		}
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}
	

	return 0;
}

