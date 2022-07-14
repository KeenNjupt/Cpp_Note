#include<iostream>
#include<vector>
#include<functional>
#include<memory>
#include<utility>


using namespace std;


class Base{
public:
    Base(int& b,int&&cc,int ii=0, string ss = ""):i(ii),s(ss),a(b),c(std::move(cc)){cout<<"in Base(int&b, int ii=0, string ss="")"<<endl;}
    bool operator<(const Base& t)const {    
        cout<<"in Base::operator<"<<endl;
        return i<t.i;
    }
    void print()const{cout<<i<<' '<<s<<' '<<a<<' '<<c<<endl;}
private:
    int i = 0;
    string s;
    int& a;
    int&& c;
};


template <typename T, typename...Args>
shared_ptr<T> my_makeshared(Args&&... args){ //右值引用保证传进来的参数在my_makeshared函数中保持类型
    // return new T(args...); //若T()中的形参args为右值引用，则出错，因为my_makeshared函数中参数均为变量(左值)，无法将左值实参传给右值引用形参
    //因此需要std::forward<Args>,保持参数传进来的类型

    return shared_ptr<T>(new T(std::forward<Args>(args)...));//std::forward<Args>(args)保证args参数保持类型,其返回Args&& args;
    //例，若args实参为int右值引用，则Args为int，则std::forward<Args>(args) 为int&& args, 仍保持原来的右值引用类型
    //若 args实参为int左值引用，则Args为int&，则std::forward<Args>(args) 为int& && args,通过引用折叠变为 int& args 仍保持原来的左值引用类型
}

int main(int argc, char* argv[]){
    int b = 10;
    shared_ptr<Base> p = my_makeshared<Base>(b,std::move(1),0,"ll");
    p->print();
    b = 20;
    p->print(); //p所指向的对象中的int引用a绑定到b上，a的值随b变化则说明绑定成功
    return 0;
}
