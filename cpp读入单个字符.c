#include<iostream>

using namespace std;
int main()
{
    char c;
    cin.get(c);  //读入单个字符
    while(c!='#'){
        cout<<'\''<<c<<'\''<<',';
        cin.get(c);
    }
    return 0;
}
