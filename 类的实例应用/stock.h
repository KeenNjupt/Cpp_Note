#include<string>
class Stock{
    private:
        std::string company;
        int shares;
        double share_value; // 每股价格
        double total_value; // 总共持有的价格 
        void set_total(){total_value = shares*share_value;};
    public:
        void acquire(const std::string &com, int share_nums, double prices);
        void buy(int share_nums, double prices); // 以一定的价格买入股票
        void sell(int share_nums, double prices);
        void update(double prices); // 更新股票价格
        void show(); // 显示相关的信息
};
