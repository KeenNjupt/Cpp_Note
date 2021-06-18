#include<iostream>
inline int  fac(int n);  // 在函数前加上关键字inline
int main(){
    using namespace std;
    int a = fac(5);
    int b = fac(6);
    cout<<"5! = "<<a<<endl;
    cout<<"6! = "<<b<<endl;
    
    return 0;
}
inline int  fac(int n){
    int ret = 1;
    for(int i=1;i<=n;i++)
        ret*=i;
    return ret;
}
