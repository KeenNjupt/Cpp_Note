#include<iostream>
int max(int a,int b = 3); // b默认为3
int main(){
    using namespace std;
    
    cout<<max(1)<<endl; // a = 1, b = 3（默认）
    cout<<max(4,5)<<endl; // a = 4, b = 5
    
    return 0;
}
int max(int a,int b){ // 函数体中含有默认参数
    return a>b?a:b;
}
