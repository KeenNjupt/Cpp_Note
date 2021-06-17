#include<iostream>

void swap(int &a, int &b); // 使用引用作为形参，进行值的交换
int main(){
    using namespace std;
    int a,b;
    a = 3;
    b = 5;
    swap(a,b);  // 直接用变量进行传参
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    int &c = a; // c为a的引用 reference
    cout<<"c = "<<c<<endl; 
    return 0;
}
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
