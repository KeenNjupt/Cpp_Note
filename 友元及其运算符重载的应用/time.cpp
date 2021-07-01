#include"time.h"
#include<iostream>
void Time::show()const{
    std::cout<<"the period are "<<hours<<" hours ";
    std::cout<<minutes<<" minutes\n";
}
Time Time::operator+(const Time &t){
    Time sum;
    sum.minutes = (minutes+t.minutes)%60;
    sum.hours = hours+t.hours+(minutes+t.minutes)/60;
    return sum;
}
Time::Time(){
    hours = 0;
    minutes = 0;
}
Time::Time(int h, int m){
    hours = h;
    minutes = m;
}
Time operator*(int n, const Time &t2){  // 因为该函数被Time类声明为友元函数，因此能访问private成员
    Time mult;
    mult.minutes = (t2.minutes*n)%60;
    mult.hours = t2.hours*n+(t2.minutes*n)/60;
    return mult;
}
std::ostream & operator<<(std::ostream &out, const Time &t){      // 函数返回类型为std::ostream可以使多个输出串联起来
    out<<"the hours are "<<t.hours<<" the minutes are "<<t.minutes;
    return out;
}