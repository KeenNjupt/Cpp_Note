#include<iostream>

using namespace std;
union test{
    int a;
    char b[4];
};
int main()
{
    union test t;
    t.a = 0X1A2B3C4D;
    for(int i=0;i<4;i++) cout<<hex<<uppercase<<int(t.b[i])<<endl;
    //小端模式为：4D 3C 2B 1A， 低位地址(端)放数据低位字节(小)
    //大端模式为：1A 2B 3C 4D   低位地址(端)放数据高位字节(大)
    return 0;
}
