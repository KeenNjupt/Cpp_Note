#include<iostream>
#include"stock.h"



int main(){
    Stock kelly;  // call for default constructor
    kelly.show();
    Stock jhon("keen",30,100); // implicitly call for self-defined constructor
    jhon.show();
    Stock bob = Stock("seu",20,500); // explicitly call for self-defined constructor
    bob.show(); 
    kelly = Stock("njupt",50,100); // create a object and assign to kelly,then the object will be destructed
    kelly.show();
    Stock initial_Kin{"Kin",30,150}; // 初始化列表
    initial_Kin.show(); 
    return 0; 
}
