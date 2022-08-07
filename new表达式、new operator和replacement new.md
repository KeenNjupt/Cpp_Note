# new表达式<br>
string *sp = new string("a value") <br>
实际执行了三步操作：<br>
1. new表达式调用一个名为operator new的标准库函数，该函数分配一块足够大的内存<br>
2. 编译器运行相应的构造函数，构造对象<br>
3. 对象被分配空间，返回该对象的指针<br>

# new operator<br>
可以重载new operator函数，当new表达式处理类类型的对象时，编译器首先在类及其基类的作用域中查找<br>
是否有重载的operator new函数，有则调用，没有则在全局作用域中查找，再没有就使用标准库函数<br>

# replacement new(定位new)<br>
类似与allocator类的construct函数<br>
用来在已经申请的空间中构造对象，operator new分配的内存，程序员无法使用构造函数构造对象<br>
使用实例：new (place_address) type [size] {initializer list}<br>
place_address 是一个指向我们申请了的内存的指针<br>
我们可以显式地调用析构函数销毁对象，但不释放空间。之后利用定位new表达式在该空间中构造对象

代码：
```
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<memory>

using std::cin;
using std::cout;
using std::endl;
using std::allocator;

void* operator new(size_t size){
        
    cout<<"in ::operator new(), the size is "<<size<<endl;
    if(void* m = malloc(size)){
        return m;
    }
    else throw std::bad_alloc();
}
void operator delete(void* m) noexcept{ //将该函数声明为不抛出异常
    cout<<"in ::delete(), the add is "<<m<<endl;
    free(m);
}

class A{
public:
    A(int ii=0):i(ii){
        cout<<"in A::A()"<<endl;
    }
    ~A(){
        cout<<"in A::~A()"<<endl;
    }
    void f(){
        cout<<"in A::f()"<<endl;
    }
    void* operator new(size_t size){
        
        cout<<"in A::operator new(), the size is "<<size<<endl;
        if(void* m = malloc(size)){
            return m;
        }
        else throw std::bad_alloc();
    }
    void operator delete(void* m) noexcept{ //将该函数声明为不抛出异常
        cout<<"in A::delete(), the add is "<<m<<endl;
        free(m);
    }
    void* operator new(std::size_t, void* __p) noexcept // 定位new调用此版本函数，类内自定义的函数
    { 
        cout<<"in A::operator new(size_t, void*)"<<endl;
        return __p; 
    }
    int i = 0;
};
// void* operator new(std::size_t, void* __p) noexcept // 定位new调用此版本函数，该版本已在头文件中定义，无法自定义，但可在类中自定义
// { 
//     cout<<"in operator new(size_t, void*)"<<endl;
//     return __p; 
// }



int main(int argc, char* argv[]){
    A* p = new A(); //对于new表达式，第一步：调用operator new函数申请空间；第二步：调用A的构造函数构造对象
    //第三步：将对象的指针返回
    cout<<p<<endl;
    delete p; //对于delete表达式，第一步：调用A的析构函数，销毁A的对象；第二步：调用operator delete函数释放空间
    //因为operator new函数和operator delete函数是在构造对象前，销毁对象后执行，所以必须为static函数，
    //编译器会自动隐式地将其设置为static，因此定义时可以不声明为static函数

    //new A()在构造对象时执行值初始化，new A在构造对象时执行默认初始化，
    //对于类类型对象都是执行默认构造函数，对于内置类型有区别

    //operator new函数的编译器查找顺序：若对象为类类型，则1.在类及其基类作用域中查找；2.在全局中查找；
    //3.都未找到，调用标准库的operator new函数
    // ::operator new函数或::new表达式只在全局作用域中查找，找不到调用标准库函数


    allocator<A> alloc; //allocator申请内存和构造对象分布进行
    A* p1 = alloc.allocate(1);//分配一个未初始化的A对象空间，
    //使用全局作用域的operator new : return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
    alloc.construct(p1,10); //构造A对象,可传入构造函数所需的参数
    cout<<p1->i<<endl;
    alloc.destroy(p1);//析构A对象
    alloc.deallocate(p1,1);//释放内存空间

    A *p2 = new A;
    p2->~A();//显式地销毁对象，但不释放空间
    ::new(p2)A(20); //定位new表达式，在已申请空间中构造对象,在全局作用域中查找函数operator new(std::size_t, void* __p)
    //不加::则编译器会在类的作用域中查找，查找名字先于匹配函数；因为A中未定义此同参函数，查找到同名的函数，但参数类型不匹配，编译器报错
    //可以在A中自定义该函数
    //加了::, 在全局作用域中查找，最终调用库函数中的void* operator new(std::size_t, void* __p) noexcept版本
    cout<<p2->i<<endl;
    delete p2;

    return 0;
}
```
