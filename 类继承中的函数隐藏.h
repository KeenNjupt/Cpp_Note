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



//解决方法：全部重载太麻烦，可以使用using声明，将基类的所用同名函数添加到派生类中，再覆盖指定的函数
#include<iostream>

using namespace std;


class Base{
public:
    virtual void f(){cout<<"in Base f()"<<endl;}
    virtual void f(int){cout<<"in Base f(int)"<<endl;}
private:
    int i = 0;
};

class Derive: public Base{
public:
    using Base::f; // 将Base类中所有的f函数添加到Derive类的作用域中
    void f(){ //覆盖指定形参列表的f函数
        cout<<"in Derive f()"<<endl;
    }
};

using PF = void (*)();
int main(int argc, char* argv[]){

    Derive d;
    d.f(0); //访问void Base::f(int)
    d.f();
    return 0;
}
