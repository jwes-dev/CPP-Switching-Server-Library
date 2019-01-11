class Exception
{
protected:
    int _code;
    char _msg[100];
public:
    int get_code()
    {
        return _code;
    }

    char* get_msg()
    {
        return (char*)_msg;
    }
};

class Server_Create : public Exception
{
public:
    Server_Create(int code, char message[])
    {
        _code = code;
        strcpy(_msg, message);
    }
};

class Bind_Error : public Exception
{
public:
    Bind_Error(int code, char message[])
    {
        _code = code;
        strcpy(_msg, message);
    }
};

class Accept_Error : public Exception
{
public:
    Accept_Error(int code, char message[])
    {
        _code = code;
        strcpy(_msg, message);
    }
};

class Server_Error : public Exception
{
public:
    Server_Error(int code, char message[])
    {
        _code = code;
        strcpy(_msg, message);
    }
};