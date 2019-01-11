#include "global.h"

int main()
{
    std::cout<<"\nstarting server\n";
    TCPServer server(10000);
    server.Start();
    std::cout<<"\nstarted\nWaiting for connection\n";
    NetworkStream stream(server.Accept());
    std::cout<<"\ngot message\n";
    {
        msg_pkt pkt(stream.ReadToEnd());
        std::cout<<"msg from client = "<<pkt.pkt_msg()<<"\n\n";
    }
    stream.Write((char*)"Hello client");
    stream.CloseStream();
    std::cout<<"\nDone";
}