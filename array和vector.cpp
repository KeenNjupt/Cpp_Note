#include<iostream>
#include<array>
#include<vector>

using namespace std;

int main(){
    array<int,5> a;// 声明一个大小为5的int数组a，类型为array，大小固定
    for(size_t i=0;i<a.size();i++) a[i] = i;
    for(size_t i=-a.size();i<a.size();i++) 
    {
        cout<<"a["<<i<<"] = "<<a[i]<<endl; // 当array类型的数组下标越界时，会将下标取模
    }
    array<int,5>a1 = a; // 可以直接拷贝
    for(size_t i=0;i<a1.size();i++) cout<<a1[i]<<endl;
    /*-----------------------------------------------*/
    vector<int> b(10); // 声明一个大小为10的int数组b，类型为vector，大小可变
    cout<<"the size of b is "<<b.size()<<endl;
    b.push_back(10); // 在b的末尾增加一个元素10
    cout<<"the size of b is "<<b.size()<<endl; 
      
    return 0;
}
