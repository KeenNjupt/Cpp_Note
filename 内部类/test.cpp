#include<iostream>
#include"list.h"

using namespace std;

int main(){
    List<int> l;
    for(int i=1;i<10;i++) l.addlist(i);
    l.show();

    return 0;
}
