#include<iostream>
#include<vector>
#include<functional>


using namespace std;


class Base{
public:
    Base(int ii=0):i(ii){cout<<"in Base(int ii=0)"<<endl;}
    bool operator<(const Base& t)const {    
        cout<<"in Base::operator<"<<endl;
        return i<t.i;
    }
    int get()const{return i;}
private:
    int i = 0;
};

template <typename T, typename F = less<T>>  //默认模板参数F为可调用类，默认该类为less<T>
int cmp(T a, T b, F f = F()){ // 默认模板函数参数f为一个可调用对象, 默认该对象为F类的默认初始化对象
    if(f(a,b)) return -1;     //实例化的T、F、f由函数的实参类型决定
    if(f(b,a)) return 1;
    return 0;
}
bool BaseLess(const Base& a, const Base& b){
    cout<<"in BaseLess"<<endl;
    return a.get()<b.get();
}
int main(int argc, char* argv[]){
    Base a(1),b(2);
    int r1 = cmp(a,b); //使用默认参数，T为Base，F为less<Base>, f为less<Base>默认初始化对象, 该less<Base>类会使用Base的"<"运算符
    int r2 = cmp(a,b,BaseLess);//f为传入的实参，T为Base，f为BaseLess，则F为BaseLess类型
    cout<<r1<<' '<<r2<<endl;
    return 0;
}
