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