#include<iostream>

using namespace std;
int main()
{
    char c;
    char name[20];
    string s1;
    cin.get(c);  //读入单个字符
    while(c!='#'){
        cout<<'\''<<c<<'\''<<',';
        cin.get(c);
    }
    cin.getline(name,20); // 读入一行字符串，包括空格
    cout<<name<<endl;
    getline(cin,s1); // 使用string类，读入一行字符串，包括空格
    cout<<s1<<endl;
    return 0;
}
