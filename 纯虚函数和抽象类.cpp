#include<iostream>


using namespace std;


class disc_quote{
public:
    disc_quote(size_t qty = 0, double r = 0):quantity(qty),rate(r){}
    virtual void net_price()const = 0; //纯虚函数
    virtual ~disc_quote(){}
private:
    size_t quantity = 0;
    double rate = 0;
};

class bulk_quote:public disc_quote{
public:
    bulk_quote(size_t qty = 0, double r = 0):disc_quote(qty,r){}
    virtual ~bulk_quote(){}
    void net_price()const override{
        cout<<"in bulk_quote::net_price"<<endl;
    }

};

using PF = void (*)();
int main(int argc, char* argv[]){
    // 因为disc_quote是被用来派生的，该类类型的对象并没有实际的意义，因此我们不希望生成该类类型的对象，便将该类声明为抽象类
    // disc_quote d; //disc_quote类有纯虚函数，该类为抽象类，不能直接声明该类的对象
    bulk_quote b;
    disc_quote &rb = b;
    b.net_price();
    rb.net_price();
    

    return 0;
}
