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
    return 0;
}
