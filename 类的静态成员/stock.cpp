#include"stock.h"
#include<iostream>
int Stock::numofobject = 0; // 定义并初始化静态成员
Stock::Stock(){  // default constructor
    std::cout<<"call for the default constructor\n";
    company = "lalala";
    shares = 0;
    share_value = 0.0;
    total_value = 0.0;
    numofobject++;
}
Stock::Stock(const std::string &com, int nums, double prices){ // self-defined constructor
    std::cout<<"call for the self-defined constructor\n";
    company = com;
    shares = nums;
    share_value = prices;
    total_value = shares*share_value;
    numofobject++;
}
Stock::~Stock(){
    std::cout<<company<<" call for the destructor\n";
    numofobject--;
}
void Stock::acquire(const std::string &com, int share_nums, double prices){
    company = com;
    if(share_nums<0){
        std::cout<<"the number should be a positive\n";
        shares = 0;
    }
    else shares = share_nums;
    share_value = prices;
    set_total();
}
void Stock::buy(int share_nums, double prices){
    if(share_nums>0){
        shares += share_nums;
        share_value = prices;
        set_total();
    }
}
void Stock::sell(int share_nums, double prices){
    if(share_nums>0){
        shares -= share_nums;
        share_value = prices;
        set_total();
    }
}
void Stock::update(double prices){
    share_value = prices;
}
void Stock::show () const{
    std::cout<<"the company is "<<company<<", ";
    std::cout<<"the shares are "<<shares<<", ";
    std::cout<<"the total is "<<total_value<<"\n";
}
void Stock::show_this(){
    std::cout<<"this->company = "<<this->company<<std::endl;
}
void Stock::show_num(){
    std::cout<<numofobject<<std::endl;
}



