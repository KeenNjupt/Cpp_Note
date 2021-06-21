#include<iostream>

using namespace std;
template <typename T>
void square(T a);       // 函数模板，T表示参数类型，typename、template是关键字
template<> void square<char>(char a); // 模板的特化，当传入参数的类型为char时，调用此函数
int main(){
    int a = 3;
    double b = 4.5;
    char c = 'K';
    square(a);
    square(b);
    square(c);
    return 0;
}
template <typename T>
void square(T a){
    cout<< a*a<<endl;
}
template<> void square<char>(char a){ // 对模板特化函数的定义
    cout<<a<<a<<endl;
}
