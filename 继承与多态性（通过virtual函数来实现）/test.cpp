#include<iostream>
#include"tableplayer.h"
#include"rateplayer.h"



int main(){
    using namespace std;
    TablePlayer player1("keen","njupt",23);
    RatePlayer rateplayer1(2,"jhon","white",1);
    TablePlayer *p1 = &rateplayer1; 
    p1->view();         // view前没有virtual时，调用基类的view(), 在基类和子类头文件的view函数前加上virtual则会调用子类的view
    RatePlayer *p2 = dynamic_cast<RatePlayer*>(p1); // 强制类型转换
    p2->sayhello();
    p1 = &player1;
    p1->view(); // 将调用基类中的view函数，当view函数为虚函数时，具体调用基类还是子类中的函数是由指针指向的对象的类型决定的，与指针类型无关
    
    return 0; 
}
