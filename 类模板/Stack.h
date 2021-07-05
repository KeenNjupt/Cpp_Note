#define Maxsize 10

template <typename T>
class Stack{
    private:
        T Data[Maxsize];
        int top;
    public:
        Stack();
        void Push(T X);
        T Pop();
};
template <typename T>
void Stack<T>::Push(T X){   // 相关函数的实现要放在头文件中，这样进行实例化时，不会出错
    if(top<Maxsize-1)
        Data[++top] = X;
}
template <typename T>
T Stack<T>::Pop(){
    if(top>-1)
    return Data[top--];
    else return -1;
}
template <typename T>
Stack<T>::Stack(){top = 0;}