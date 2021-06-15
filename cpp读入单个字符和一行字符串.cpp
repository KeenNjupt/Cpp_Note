#include<iostream>

using namespace std;
int main()
{
    char c;
    char name[20];
    cin.get(c);  //读入单个字符
    while(c!='#'){
        cout<<'\''<<c<<'\''<<',';
        cin.get(c);
    }
    cin.getline(name,20); // 读入一行字符串，包括空格
    return 0;
}
