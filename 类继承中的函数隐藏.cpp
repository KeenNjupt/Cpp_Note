using namespace std;
class B{
    private:
        int i;
    public:
        B():i(0){}
        void show(int j){cout<<"B::show(int j) "<<j<<endl;}
        void show(){cout<<"B::i = "<<i<<endl;}
};

class A: public B{
    public:
        void show(){cout<<"A::show"<<endl;}


};

// 在类B中，两个show()函数构成函数重载，但对于派生类A，由于两个没有参数的show()函数，函数名和参数列表相同，导致无法重载，于是B中所有show()的重载函数都不会在A中存在，
//A中只有自己定义的show（）

