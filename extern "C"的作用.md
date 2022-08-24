# extern "C"的作用

由于cpp支持函数重载：即在编译时刻会将函数的参数列表加到函数名中，从而使汇编代码中的函数名不同来实现函数重载。  
这就导致当cpp由g++编译.cpp文件生成的.o文件和由gcc编译.c文件生成的.o文件链接时，会由于是否改变函数名的区别导致连接失败。  
如，在源文件中该函数体, 以及g++编译生成的汇编代码中该函数对应的部分：  
```
int f(int i, float j){//源文件中该函数体
    return 0;
}
//汇编代码中该函数对应的部分
Z1fif://第一个f是函数名后面的i,f表示两个参数分别是int、float类型
.LFB1522:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movss	%xmm0, -8(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```

## cpp文件中使用gcc编译.c文件生成的.o文件对应的头文件
如：我在test.cpp文件想使用 c.c文件中的函数，该文件已经被gcc编译成了.o文件。  
则在该文件中的函数名与源代码中的文件名一致，因为gcc并不改变函数名，函数名为`f`。  
假如该文件中有一个函数为`int f(){return 1;}`, 因此c.c文件对应的头文件c.h中包含该函数的声明`int f();`,  
如果在test.cpp文件中直接使用c.h文件的函数声明`int f();`, 则test.cpp经过g++编译后，该函数名会被改变成类似`Z1fv`的形式，v表示void,  
则将test.o与c.o链接时，函数名无法匹配，出错。  

改进方法：在c.h文件中添加extern "C"{}告诉g++编译器将该{}中的函数声明按照c语言格式编译，即不要改变函数名, 来保持编译后的test.o与c.o文件中的函数名保持一直，
当然这样就不能在extern "C"中使用函数重载。  
但extern "C"只是cpp中的关键字，在c语言中无法识别，为保证c.h文件在.c文件也能正常使用，需要设计该关键字只在g++编译时存在。  
使用一个特殊的宏__cpluscplus,该宏只在g++编译时存在，gcc时不存在。 该宏存在时extern "C"有效，反之无效。  
最终的c.h文件为：
```
#ifndef C_H
#define C_H

#ifdef __cplusplus//g++编译时该宏存在，预处理后为extern "C"{int f();}
extern "C"{  //gcc编译时该宏不存在，预处理后为 int f();
#endif

int f();
#ifdef __cplusplus
}
#endif

#endif
```
测试命令：
```
gcc -c c.c -o c.o //c.c中包含f()函数的实现，生成c.o
g++ -c test.cpp -o test.o //test.cpp使用c.h中声明的函数，生成test.o
g++ test.o c.o -o test //链接两个.o文件，生成可执行文件， 若不加extern "C"则出错：未找到 f()
```
## c文件中使用g++生成的.o文件对应的.h文件
如：我在test.c文件想使用 cpp.cpp文件中的函数，该文件已经被g++编译成了.o文件。  
因为gcc并不会改变函数名，因此要求.o文件中的函数名与cpp.h中的函数名相同，即不改变函数名，这可以利用extern "C"实现,  
将声明放在extern "C"中即可。但这样编译后，cpp.o文件中的函数名没有改变，便无法被其他.cpp文件使用。  
为了让.cpp文件也可以使用，需要在cpp.h中手动更改函数名放在extern "C"中，让.c文件使用手动更改函数名的声明，  
.cpp文件使用为更改函数名的声明。 并且在cpp.cpp中实现手动更改函数名的函数体，利用已有的函数即可。  
如：cpp.h文件
```
#ifndef CPP_H
#define CPP_H

#ifdef __cplusplus //使用g++编译时，__cplusplus宏已定义，gcc时，未定义
//所以该部分仅对g++可见
int f(int i);
float f(float i);
extern "C" {
#endif
//由于c语言中没有重载，因此需要手动更改函数名(将参数加到函数名中)，实现重载
//并且要求这一部分在编译时，按照c的编译方式，不允许编译器改变函数名，使用extern "C"
//否则该函数的cpp文件生成的.o文件与gcc生成的.o文件链接时，会找不到对应的函数名
int f_int(int i);
float f_float(float i);
#ifdef __cplusplus
}
#endif

#endif
```
cpp.cpp文件
```
#include"cpp.h"

int f(int i){
    return i;
}
float f(float i){
    return i;
}
int f_int(int i){ //利用已有的重载函数实现
    return f(i);
}
float f_float(float i){
    return f(i);
}
```
测试命令：
```
g++ -c cpp.cpp -o cpp.o //生成cpp.o文件
gcc -c test.c -o test.o //生成test.o文件
gcc test.o cpp.o -o test //链接两个.o文件，生成可执行文件
```

