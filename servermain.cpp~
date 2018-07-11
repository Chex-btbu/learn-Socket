#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <pthread.h>
#include "ServerSocket.h"

static bool isruning;

void* getinput( void* args  )
{
	std::string sr = "v";	
	while(isruning)
	{
		std::cin >> sr;
		if(sr.compare("c")==0)
		{
			isruning = false;
		}
	}
}

int main ( int argc, int argv[] )
{
	isruning = true;

	std::cout << "running....\n";

	pthread_t t;
	pthread_create(&t,NULL,getinput,NULL);
	
	try
	{
		// Create the socket
		ServerSocket server ( 30000 );
		
		while ( isruning )
		{
			ServerSocket new_sock;
			server.accept ( new_sock );
			try
			{
				while ( isruning )
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
	pthread_exit(NULL);

	return 0;
}

