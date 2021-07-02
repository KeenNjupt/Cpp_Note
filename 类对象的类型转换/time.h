#include<string>
class Time{
    friend Time operator*(int n, const Time &t2); // 声明该函数为类Time的友元，可以在该函数中访问private成员
    friend std::ostream & operator<<(std::ostream &out, const Time &t);
    private:
        int hours;
        int minutes;
    public:
        void show()const;
        Time operator+(const Time &t);
        Time();
        explicit Time(int m); // 表示必须显式地调用该函数
        Time(int h, int m);
        operator int() const;  // 将Time类型的对象转换为int类型
};