#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> a;  // 元素类型为int的vector
    vector<int>::iterator p; // 迭代器
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    for(p=a.begin();p!=a.end();p++){
        cout<<*p<<endl;
    }

   return 0; 
} 
