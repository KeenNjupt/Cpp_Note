#include<string>
class Strbad{
    static int numofstr;
    private:
        char *str;
        int lenofstr;
    public:
        Strbad(); // default constructor
        Strbad(const char *s);  // self-defined constructor
        Strbad(const Strbad &s); // copy constructor
        const Strbad & operator=(const Strbad &s);  // overload the operator "="
        ~Strbad();
        void show()const;
};