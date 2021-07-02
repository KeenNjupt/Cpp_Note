#include<iostream>
#include"time.h"



int main(){
    using namespace std;
    
    // Time plan = 125; // 隐式的调用Time(int m)
    Time plan(125); // 函数声明中加上了explicit，只能显式地调用该函数
    plan.show();

    Time coding(3,40); 
    coding.show();
    int t = coding;  // 将coding转换为int类型，具体过程应该自定义
    cout<<"t = "<<t<<endl;

    return 0; 
}
