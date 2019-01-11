char only_alpha(int x)
{
    return (char)((x % 26) + 65);
}

class msg_pkt
{
protected:
    std::string f, t, m;
    std::string _data;
public:

    msg_pkt(std::string from, std::string to, std::string msg)
    {
        int i;
        f = ""; t = "";
        f += from;
        for(i = from.size() ; i < 15; i++)
            f += only_alpha(i);
        t += to;
        for(i = to.size() ; i < 15; i++)
            t += only_alpha(i);
        std::cout<<f<<" "<<t<<" "<<msg<<"\n\n";
        m = msg;
    }

    msg_pkt(std::string data)
    {
        _data = data;
    }

    std::string pkt_to()
    {
        if(t.size() > 0)
            return t;
        else if(_data.size() > 0)
            return _data.substr(0, 15);
        return NULL;
    }

    std::string pkt_from()
    {
        if(f.size() > 0)
            return f;
        else if(_data.size() > 0)
            return _data.substr(15, 15);
        else
            return NULL;
    }

    std::string pkt_msg()
    {
        if(_data.size() > 0)
            return _data.substr(30, _data.size() - 30);
        else if(m.size() > 0)
            return m;
        else
            return NULL;
    }

    std::string pkt_string()
    {
        if(_data.size() > 0)
            return _data;      
        return t + f + m;
    }
};