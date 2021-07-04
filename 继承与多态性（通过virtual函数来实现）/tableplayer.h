#ifndef TABLEPLAYER
#define TABLEPLAYER
#include<string>

class TablePlayer{
    private:
        std::string firstname;
        std::string lastname;
        int hastable;
    public:
        TablePlayer(const std::string &fn = "none", const std::string &ln = "none", int n = 0);
        virtual void view();
        virtual ~TablePlayer();

};

#endif