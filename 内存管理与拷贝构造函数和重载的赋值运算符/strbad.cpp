#include"strbad.h"
#include<iostream>
#include<cstring>

int Strbad::numofstr = 0;
Strbad::Strbad(){  // 默认构造函数
    std::cout<<"here is default constructor\n";
    str = new char[4];
    lenofstr = 3;
    std::strcpy(str,"C++");
    numofstr++;
    std::cout<<"the number of str = "<<numofstr<<std::endl;
}
Strbad::Strbad(const char *s){ // 自定义的构造函数
    std::cout<<"here is self-defined constructor\n";
    int len = std::strlen(s);
    lenofstr = len;
    str = new char[lenofstr+1];
    std::strcpy(str,s);
    numofstr++;
    std::cout<<"the number of str = "<<numofstr<<std::endl;
}
Strbad::Strbad(const Strbad &s){
    std::cout<<"here is copy constructor\n";
    lenofstr = s.lenofstr;
    str = new char[lenofstr+1];
    std::strcpy(str,s.str);
    numofstr++;
    std::cout<<"the number of str = "<<numofstr<<std::endl;
}
Strbad::~Strbad(){
    std::cout<<"here is  destructor\n";
    delete []str;
    numofstr--;
    std::cout<<"the number of str = "<<numofstr<<std::endl;
}
const Strbad& Strbad::operator=(const Strbad &s){
    std::cout<<"here is overloaded assignment\n";
    if(this==&s) return *this;
    else{
        delete []str;
        lenofstr = s.lenofstr;
        str = new char[lenofstr+1];
        std::strcpy(str,s.str);
        return *this;
    }
}
void Strbad::show() const{
    std::cout<<"the string is "<<str<<"the address is "<<static_cast<const void*>(str)<<std::endl;
}        