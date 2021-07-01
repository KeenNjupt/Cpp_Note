#include<iostream>
#include"time.h"



int main(){
    using namespace std;
    Time plan(2,45);
    Time coding(3,20);
    Time total;
    Time threesum;
    std::cout<<"the plan is ";
    plan.show();
    std::cout<<"\n";
    std::cout<<"the coding is ";
    coding.show();
    std::cout<<"\n";
    std::cout<<"the toal is ";
    total.show();
    std::cout<<"\n";

    total = plan+coding;
    std::cout<<"the  plan+coding is ";
    total.show();
    std::cout<<"\n";

    total = plan.operator+(coding);
    std::cout<<"the  plan.operator+(coding) is ";
    total.show();
    std::cout<<"\n";

    threesum = plan+coding+total;
    std::cout<<"the  plan+coding+total is ";
    threesum.show();
    std::cout<<"\n";

    threesum = plan.operator+(coding+total);
    std::cout<<"the  plan.operator+(coding+total) is ";
    threesum.show();
    std::cout<<"\n";

    threesum = plan.operator+(coding.operator+(total));
    std::cout<<"the  plan.operator+(coding.operator+(total)) is ";
    threesum.show();
    std::cout<<"\n";
    return 0; 
}
