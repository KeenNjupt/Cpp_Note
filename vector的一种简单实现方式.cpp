#include<iostream>
#include<memory>

using namespace std;

class myStrVec{
public:
    myStrVec():first_element(nullptr),first_free(nullptr),past_end(nullptr){}
    myStrVec(const myStrVec& t);
    myStrVec& operator=(const myStrVec& lv);
    ~myStrVec(){free();}
    void push_back(const string& t);
    size_t size()const{return first_free-first_element;}
    size_t capcity()const{return past_end-first_element;}
    string* begin()const{return first_element;}
    string* end()const{return first_free;}


private:
    string* copy(string* first_ele, string* first_fr){
        auto newdata = alloc.allocate(first_fr-first_ele);
        uninitialized_copy(first_ele,first_fr,newdata);
        return newdata;
    }
    void free(){
        if(first_element){
            for(auto p=first_free;p!=first_element;){
                alloc.destroy(--p);
            }
        }
        alloc.deallocate(first_element,capcity());
    }
    void check_free(){ //判断是否有空闲空间、若没有，则至少分配一个新的空间
        if(first_free==past_end) realloc();
    }
    void realloc(){
        auto old_size = size();
        auto newcap = old_size?old_size*2:1; //当前没有空间时，分配一个空间；有空间时，分配当前空间的二倍
        auto newdata = alloc.allocate(newcap);
        auto new_element = newdata;
        auto old_element = first_element;
        for(;old_element!=first_free;){
            alloc.construct(new_element++,std::move(*(old_element++))); //使用移动构造，减少不必要的string的拷贝和空间释放
        }
        free(); //释放原空间
        first_element = newdata;
        first_free = new_element;
        past_end = first_element+newcap;
    }
    
    static allocator<string> alloc; //用来分配空间
    string* first_element; //指向第一个元素的位置
    string* first_free; //指向最后一个元素的后面的位置
    string* past_end; // 指向分配的空间的后面位置
};
allocator<string> myStrVec::alloc = allocator<string>();
myStrVec::myStrVec(const myStrVec& t){//拷贝构造，拷贝的空间为lv中元素的数量
    first_element = copy(t.first_element,t.first_free);
    first_free = first_element+ t.size();
    past_end = first_element+t.size();
}
myStrVec& myStrVec:: operator=(const myStrVec& lv){ //拷贝赋值，拷贝的空间为lv中元素的数量
    auto newdata = copy(lv.first_element,lv.first_free);
    free();
    first_element = newdata;
    first_free = first_element+lv.size();
    past_end = first_element + lv.size();
    return *this;
}
void myStrVec::push_back(const string& t){
    check_free();
    alloc.construct(first_free++,t);
}
int main(int argc, char* argv[]){
    myStrVec sv;
    cout<<sv.size()<<' '<<sv.capcity()<<endl;
    sv.push_back("this");
    cout<<sv.size()<<' '<<sv.capcity()<<endl;
    sv.push_back("hello");
    cout<<sv.size()<<' '<<sv.capcity()<<endl;
    sv.push_back("world");
    cout<<sv.size()<<' '<<sv.capcity()<<endl;
    myStrVec sv1;
    sv1 = sv;
    cout<<sv1.size()<<' '<<sv1.capcity()<<endl;
    for(string s:sv1){
        cout<<s<<' ';
    }
    cout<<endl;
    myStrVec sv2 = sv;
    cout<<sv2.size()<<' '<<sv2.capcity()<<endl;
    for(string s:sv2){
        cout<<s<<' ';
    }
    return 0;
}
