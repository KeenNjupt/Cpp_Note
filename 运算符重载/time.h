#include<string>
class Time{
    private:
        int hours;
        int minutes;
    public:
        void show()const;
        Time operator+(const Time &t);
        Time();
        Time(int h, int m);
};