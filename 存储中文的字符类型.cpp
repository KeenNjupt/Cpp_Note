#include<iostream>

using namespace std;
int main()
{
    char16_t s16[] = {u"你好"}; // 每个字符占两个字节
    cout<<sizeof(char16_t)<<endl;
    cout<<sizeof(s16)<<endl;
    cout<<s16<<endl;
    return 0;
}
