template<typename item>
class List{
    private:
        class Node{ // 类Node为内部类
            public:
                item Data;
                Node *next;
                Node(const item &X):Data(X),next(NULL){}
        };
        Node* head;
        Node* tail;
        int size;
    public:
        List():head(NULL),tail(NULL),size(0){}
        List(const List& l);
        List & operator=(const List &l);
        void addlist(item X);
        void deletelist();
        void show();
        ~List();
};
template<typename item>
void List<item>::addlist(item X){
    Node* t = new Node(X);
    t->next = NULL;
    if(tail!=NULL){
        tail->next = t;
        tail = t;
    }
    else{
        head = tail = t;
    }
    size++;
}
template<typename item>
void List<item>::show(){
    for(Node*p=head;p;p=p->next){
        std::cout<<p->Data<<' ';
    }
}
template<typename item>
List<item>::~List(){
    for(Node*p=head;p;){
        Node* q = p;
        p=p->next;
        delete q;
    }
}