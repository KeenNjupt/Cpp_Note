#include<iostream>
#include<string>

using namespace std;
int main()
{
    string s1,s2;
    int lens1;
    s1 = "keen";
    s2 = "qinqin";
    lens1 = s1.size(); // 取字符串的长度
    s1 += s2; // 类似于整数的运算，连接s1和s2，再把字符串赋给s1
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<lens1<<endl;
    return 0;
}
