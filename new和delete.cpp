#include<iostream>

using namespace std;
struct Person
{
    char name[10];
    int age;
};
int main()
{
    Person *p1 = new Person; // 申请一个结构体的内存，并让p1指向它
    cin>>p1->name; // 使用该结构体变量
    cin>>p1->age;
    cout<<"name is "<<p1->name<<endl;
    cout<<"age is "<<p1->age<<endl;
    delete p1; // 释放内存
    /*-------------------------------*/

    int *a = new int[10];  // 申请一个大小为10的int数组
    for(int i=0;i<10;i++) cin>>a[i];
    for(int i=0;i<10;i++) cout<<a[i]<<' ';
    delete []a; // 释放数组型的内存
    return 0;
}
