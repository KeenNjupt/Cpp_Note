#include "tableplayer.h"
#include<iostream>
using std::string;
TablePlayer::TablePlayer(const string &fn , const string &ln, 
int n): firstname(fn), lastname(ln), hastable(n){} // 初始化列表
void TablePlayer::view(){
    std::cout<<"the first name is "<<firstname<<
    " the last name is "<<lastname<<
    " the hastable is "<<hastable<<std::endl;
}
