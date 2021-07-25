#include<iostream>
using namespace std;
class Rational{
    private:
        int numerator;
        int denominator;
    public:
        Rational(int n, int m):numerator(n),denominator(m){}
        operator double()const{return numerator/(double)denominator;}
};

