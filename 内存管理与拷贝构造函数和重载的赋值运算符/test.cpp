#include<iostream>
#include"strbad.h"



int main(){
    using namespace std;
    
    Strbad s1("Keen");
    Strbad s2(s1); // 调用拷贝构造函数
    Strbad s3 = s1; // 调用拷贝构造函数
    Strbad s4; 
    s4 = s1;  // 调用重载的操作符“=”
    s1.show();
    s2.show();
    s3.show();
    return 0; 
}
