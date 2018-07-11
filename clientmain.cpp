#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, int argv[] )
{

  std::string strIp = "";
  std::string strPort = "";
  try
    {
      std::cout << "please input ip to connect:\n";
      std::cin >> strIp;
      std::cout << "please input port to connect\n";
      std::cin >> strPort;
      std::cout << "connecting Ip: " << strIp << " Port: " << strPort;


      ClientSocket client_socket ( strIp, 30000 );

      std::string reply;
      std::string getStr;
      while(true)
      {
          try
	  {
              std::cin >> getStr;
	      client_socket << getStr;
	      client_socket >> reply;
	  }
          catch ( SocketException& ) {}

          std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
      }

    }
    catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}

