#include<iostream>
#define glue(a,b) a##b // 链接a和b

int main(){

    std::glue(c,out)<<"hello, world!"<<std::endl;
    return 0;
}
