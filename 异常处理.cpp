#include<iostream>

using namespace std;
double divide(double n, double m);
int main(){
    double n,m,z;
    cout<<"please input two numbers(or 'q' to quit): \n";
    while(cin>>n>>m){
        try{
            z = divide(n,m);
            cout<<"n/m = "<<z<<endl;
        }
        catch(const char *s){
            cout<<s<<endl;
        }
        cout<<"please input two numbers(or 'q' to quit): \n";
    }


    return 0;
}

double divide(double n, double m){
    if(m==0){
        throw "the second should not be zero!\n";
    }
    return n/m;
}
