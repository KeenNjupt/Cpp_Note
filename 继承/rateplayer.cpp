#include"rateplayer.h"
#include<iostream>
using std::string;
RatePlayer::RatePlayer(int r,const string &fn, const string &ln, int n):TablePlayer(fn,ln,n){ // 用初始化列表调用基类的构造函数
    rate = r;
}
void RatePlayer::view(){
    TablePlayer::view();
    std::cout<<"the rate is "<<rate<<std::endl;
}