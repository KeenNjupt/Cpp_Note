#include<iostream>

using namespace std;

class A{
public:
    virtual ~A(){}
    virtual void f(){
        cout<<"in void A::f()"<<endl;
    }
    void print(){
        cout<<i<<endl;
    }
private:
    int64_t i = 2;

};
class B{
public:
    B(int ci=0):c(ci),c2(ci){}
    void set(int ci){
        c = ci;
        c2 = ci;
    }
    void print(){
        cout<<c<<' '<<c2<<endl;
    }
private:
    int c = 0;
    int c2 = 0;
};

class C:public A{
public:
    void print(){
        cout<<j<<endl;
    }
private:
    int64_t j = 3;
};
using PF = void (*)();
int main(int argc, char* argv[]){
    B b;
    B* pb = &b;
    int *ib = (int*)pb; //ib指向b的地址，并且将该地址连续一个int大小的内存空间作为int解释
    cout<<(*ib)<<endl;  //在B中第一个int大小的内存空间正好是存放成员变量c的空间，因此ib等价于指向c的指针
    *ib = 10; // b.c = 10
    b.print();
    ++ib; //ib想后增加一个int大小的内存空间，此时ib等价于指向c2的指针
    *ib = 20; //b.c2 = 20;
    b.print();

    A a,a1;
    int64_t* pa = (int64_t*)&a; // 此系统为64位，所以指针有64位;pa指向a的地址，并将该地址连续64位大小(一个指针大小)的内存空间作为整形解释
    int64_t* pa1 = (int64_t*)&a1; //此时pa为指向A中虚函数表的指针，该虚函数表为整个类共用，因此pa,pa1指向同一个表, *pa == *pa1, 表示虚函数表的地址

    cout<<(*pa)<<' '<<(*pa1)<<endl;
    a.print();
    ++pa; //此时pa指向a.i
    *pa = 10;
    a.print();
    
    --pa;
    int64_t* f1 = (int64_t*)(*pa); 
    cout<<(f1)<<endl; //f1表示虚函数表的地址，并以地址的形式打印，即以16进制的形式打印
    cout<<hex<<(*pa)<<endl<<dec; // 直接以16进制的形式打印
    // PF fp = (PF)(*pa1); //尝试访问a.f(), 没成功
    // fp();

    C c;
    C* pc = &c;
    pc->f(); //C中未重定义f()，沿用A中的f()
    int64_t* vptrc = (int64_t*)&c; //C继承A,但C的虚函数表是独立与A的虚函数表
    cout<<(*vptrc)<<endl;
    int64_t *pci = vptrc;
    ++pci;// pci指向A中的i
    cout<<(*pci)<<endl;
    ++pci; //pci指向C中的j
    cout<<(*pci)<<endl;
    
    return 0;
}
