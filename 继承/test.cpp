#include<iostream>
#include"tableplayer.h"
#include"rateplayer.h"



int main(){
    using namespace std;
    TablePlayer player1("keen","njupt",23);
    player1.view();
    RatePlayer rateplayer1(2,"jhon","white",1);
    rateplayer1.view();
    TablePlayer *p1 = & rateplayer1; 
    p1->view();         // view前没有virtual时，调用基类的view(), 在基类和子类头文件的view函数前加上virtual则会调用子类的view
    return 0; 
}
