#ifndef RATEPLAYER
#define RATEPLAYER
#include"tableplayer.h"
class RatePlayer : public TablePlayer{ // 继承类，public表示不能直接使用基类中private成员
    private:
        int rate;
    public:
        RatePlayer(int r=0, const std::string &fn = "none", const std::string &ln = "none", int n = 0);
        virtual void view();
        virtual void sayhello();
};



#endif