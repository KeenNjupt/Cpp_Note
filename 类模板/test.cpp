#include<iostream>
#include"Stack.h"
using namespace std;
int main(){
    Stack<int> S1; // 生成一个int类型的Stack类的对象
    for(int i=0;i<5;i++) S1.Push(i);
    for(int i=0;i<5;i++) cout<<S1.Pop()<<endl;
    
    return 0; 
}
