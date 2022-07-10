#include<iostream>

using namespace std;
template <typename T>
T square(T a);       // 函数模板，T表示参数类型，typename、template是关键字
int main(){
    int a = 3;
    double b = 4.5;
    cout<<square(a)<<endl;
    cout<<square(b)<<endl;
    return 0;
}
template <typename T>
T square(T a){
    return a*a;
}

//使用非类型模板参数，如下面的无符号整数N，该数用来表示数组的大小
//当模板被实例化时，非类型参数被用户提供、编译器推断的值代替，该值必须是常量表达式
template <unsigned N, typename T>
void print(const T (&arr)[N]){ //因为数组类型不能拷贝，因此使用数组的引用类型, arr为元素类型为T、大小为N的const数组类型
    for(unsigned i=0;i<N;++i){
        cout<<arr[i]<<' ';
    }
}
int main(int argc, char* argv[]){
    int arr[] = {1,5,6,8,9};
    print(arr);
    return 0;
}
