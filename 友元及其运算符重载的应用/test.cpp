#include<iostream>
#include"time.h"



int main(){
    using namespace std;
    Time plan(2,45);
    Time coding(3,20);
    Time multi;
    Time threesum;

    std::cout<<"the 2*plan is ";
    multi = 2*plan;   // 等价于 multi = operator*(2,plan);，调用友元函数
    multi.show();
    std::cout<<"\n";
    
    multi = operator*(2,plan);
    std::cout<<"the operator*(2,plan) is ";
    multi.show();
    std::cout<<"\n";

    cout<<multi<<"\n"<<plan<<endl;  // 重载了<<操作符，并且可以串联输出
    operator<<(cout,multi);

    
    return 0; 
}
