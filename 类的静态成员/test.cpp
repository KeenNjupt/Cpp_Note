#include<iostream>
#include"stock.h"



int main(){
    using namespace std;
    Stock::show_num();
    Stock jhon("keen",30,100); // implicitly call for self-defined constructor
    Stock::show_num();
    Stock bob = Stock("seu",20,500); // explicitly call for self-defined constructor
    Stock::show_num();
    return 0; 
}
