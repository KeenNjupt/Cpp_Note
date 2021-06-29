#include"stock.h"
#include<iostream>
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
void Stock::show(){
    std::cout<<"the company is "<<company<<", ";
    std::cout<<"the shares are "<<shares<<", ";
    std::cout<<"the total is "<<total_value<<"\n";
}


