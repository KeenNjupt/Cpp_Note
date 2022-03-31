
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
int main()
{
    int val,sum;
    val = sum = 0;
    while(cin>>val){ // cin>>val表达式返回istream的对象cin,当遇到无效输入(EOF,或者类型不匹配时）,cin状态变为无效，该表达式为false
        sum += val;  // 但当文件以/n结尾时，由于cin读入数据时默认不处理空格和'/n'所以程序会一直循环
    }
    cout<<"sum is "<<sum<<endl;
    return 0;
}
