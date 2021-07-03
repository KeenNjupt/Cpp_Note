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
用来在已经申请的空间中构造对象，operator new分配的内存，程序员无法使用构造函数构造对象<br>
使用实例：new (place_address) type [size] {initializer list}<br>
place_address 是一个指向我们申请了的内存的指针<br>
当delete这些内存时，并不会调用相应的析构函数，因此需要我们显式地调用析构函数
