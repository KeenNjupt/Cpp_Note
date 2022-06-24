#include<iostream>
using namespace std;

class mySharedString{
public:
    mySharedString(string* s = nullptr):ps(s),cnt(new size_t(1)){} //初始化时为ps和cnt申请动态内存，并将*cnt设为1，表示当前只有1个对象共享ps
    mySharedString(const mySharedString& t):ps(t.ps),cnt(t.cnt){++(*cnt);} //拷贝构造时，拷贝指针共享ps，(*cnt)加一
    mySharedString& operator=(const mySharedString& rvalue){ // 赋值号右侧的对象(*cnt)加一，左侧对象(*cnt)减一，(*cnt)为0时，delete申请的内存
        ++(*(rvalue.cnt));
        if(--(*cnt)==0){
        cout<<"int operator=()"<<"the string is"<<(*ps)<<endl;
            delete ps;
            delete cnt;
        }
        ps = rvalue.ps;
        cnt = rvalue.cnt;
        return *this;
    }
    ~mySharedString(){//析构对象时，(*cnt)减一，(*cnt)为0时，delete申请的内存
        cout<<"int ~my()"<<"the string is"<<(*ps)<<endl;
        if(--(*cnt)==0){
            delete ps;
            delete cnt;
        }
    }
    void print(){
        cout<<(*ps)<<' '<<(*cnt)<<endl;
    }
private:
    string *ps; //拷贝和赋值时共享底层内存
    size_t *cnt; //保存共享ps的对象数量，以指针的形式实现在共享ps的对象之间同步
};
int main(int argc, char* argv[]){
    mySharedString a(new string("abc"));
    a.print();
    mySharedString b = a;
    b.print();
    mySharedString c(new string("def"));
    c.print();
    c = a;
    c.print();

    return 0;
}
