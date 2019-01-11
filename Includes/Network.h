class Servers
{
protected:
    int port, server_handle, addr_len;
    struct sockaddr_in server_address;
};

class NetworkStream
{
protected:
    int vport;
public:
    NetworkStream()
    {
        //empty
    }

    NetworkStream(int virtual_port)
    {
        vport = virtual_port;
        std::cout<<"creating stream for "<<vport<<"\n\n";
    }
    
    std::string ReadToEnd()
    {
        char buf[1024] = {0};
        std::string ret = "";
        int rd;
        std::cout<<"\nstarting read 1\n";
        std::cout<<"\nstarting read 2\n";
        do{
            std::cout<<"vport = "<<vport<<"\n";
            rd = read(vport, buf, 1024);
            std::cout<<"read = "<<rd<<"\n";
            if(rd > 0)
                ret += buf;
        }while(rd > 0 && rd == 1023);
        std::cout<<"\ndone reading\n";
        return ret;
    }

    int Write(std::string line)
    {
        return send(vport, line.c_str(), line.size(), 0);
    }

    void CloseStream()
    {
        close(vport);
        // try{
            
        // }
        // catch(exception e){
        //     perror("close failed");
        // }
    }

    ~NetworkStream()
    {
        CloseStream();
    }
};

class TCPServer : protected Servers
{
protected:
    char buffer[1024] = {0};
public:
    TCPServer(int Port)
    {
        port = Port;
        int opt = 1;
        if((server_handle = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
            throw new Server_Create(-1, (char*)"server create failed");
            return;
        }
        if(setsockopt(server_handle, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        {
            throw new Bind_Error(-1, (char*)"Unable to set socket options");
            return;
        }
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(port);
        addr_len = sizeof(server_address);
        if (bind(server_handle, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        {
            throw new Bind_Error(-1, (char*)"Unable to bind with socket");
            return;
        }
    }

    void Start()
    {
        if (listen(server_handle, 3) < 0)
        {
            throw new Server_Error(-1, (char*)"server listen failed");
            return;
        }
    }

    int Accept()
    {
        return accept(server_handle, (struct sockaddr *)&server_address, (socklen_t*)&addr_len);
    }
};

