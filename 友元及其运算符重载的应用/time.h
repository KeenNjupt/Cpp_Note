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
        Time(int h, int m);
};