#include<iostream>
#include"stock.h"



int main(){
    Stock jhon;
    std::cout<<"this is start\n";
    jhon.acquire("tesla",100,1000);
    jhon.show();
    jhon.buy(10,1100);
    jhon.show();
    jhon.sell(100,500);
    jhon.show();
    
    return 0; 
}
