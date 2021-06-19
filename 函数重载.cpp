#include<iostream>

using namespace std;
void square(int a); // 函数重载，函数名相同，参数列表不同（数目、类型、顺序），返回类型没有要求，可以相同，也可以不同
void square(double a);
int main(){
    int a = 3;
    double b = 4.5;
    square(a);
    square(b);
    return 0;
}
void square(int a){
    cout<<"the data is int\n";
    cout<<"the square = "<<a*a<<endl;
}
void square(double a){
    cout<<"the data is double\n";
    cout<<"the square = "<<a*a<<endl;
}
