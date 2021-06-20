#include<iostream>

using namespace std;
template <typename T>
T square(T a);       // 函数模板，T表示参数类型，typename、template是关键字
int main(){
    int a = 3;
    double b = 4.5;
    cout<<square(a)<<endl;
    cout<<square(b)<<endl;
    return 0;
}
template <typename T>
T square(T a){
    return a*a;
}
