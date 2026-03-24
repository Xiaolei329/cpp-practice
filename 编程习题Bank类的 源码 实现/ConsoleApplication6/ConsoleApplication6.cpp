
//Author:Xiaolei   Date:2023.3.29

#include <iostream>
using  namespace std;

//本程序主要功能：
//设计一个Bank类 
//1.创建账户：账号  创建日期 余额，创建账户时候存入的钱
//2.存钱，并记录存钱日期和存钱数目
//3.取钱，并记录取钱日期和取钱数目
//4.查询交易明细：查询近一个月的账户交易记录


//交易记录的结构定义
struct DealRecord {
    string type; //"存钱" "取钱"
    string date; //日期 
    double dealMoney; //交易的金额
};

#define MAXRECORDNUM 30 //默认存30条记录 模拟一个月

class Bank{

private:
    string account;//账号
    string creatTime;//创建日期
    double money;//账户余额

    //交易记录
    struct DealRecord dealRecord[MAXRECORDNUM];
    //当前账户 记录的位置索引（数组下标位置）
    int index;

public:

    //构造函数创建账户
    Bank(string account, string creatTime, double money);
    
    //存钱
    void SaveMoney(double money, string time);

    //取钱
    void GetMoney(double money, string time);

    //查询交易记录
    void showDealRecord();
};


//构造函数的实现
Bank::Bank(string account, string creatTime, double money) {
    
    this->account = account;
    this->creatTime = creatTime;
    this->money = money;

    index = 0;//当前用户的交易记录索引位置 

}

//存钱实现
void Bank::SaveMoney(double money, string time) {

    //余额增加
    this->money = this->money + money;

    //记录操作
    struct DealRecord record;
    record.date = time;
    record.dealMoney = money;
    record.type = "存钱";
    this->dealRecord[this->index] = record;

    //循环记录最近的30条
    this->index = (this->index + 1) % MAXRECORDNUM;
}


//取钱实现
void Bank::GetMoney(double money, string time) {
    
    if (this->money < money) {
        cout << "余额不够" << endl;
        return;
    }

    //余额减少
    this->money = this->money - money;

    //记录操作
    struct DealRecord record;
    record.date = time;
    record.dealMoney = money;
    record.type = "取钱";
    this->dealRecord[this->index] = record;

    //循环记录最近的30条
    this->index = (this->index + 1) % MAXRECORDNUM;
}

//查询交易记录
void Bank::showDealRecord() {

    cout <<endl << "账户号:" << this->account << " 交易记录:" << endl;

    for (int i = 0; i < MAXRECORDNUM; i++) {
        if (this->dealRecord[i].type.empty()) {
            break;
        }
        cout << "账号:" << this->account <<
            " 交易类型:" << this->dealRecord[i].type <<
            " 交易金额:" << this->dealRecord[i].dealMoney<<
            " 交易时间:" << this->dealRecord[i].date <<endl;
    }
}


int main()
{
    //创建账户1 
    //账号123123  初始化金额1000
    Bank user1 = Bank("123123", "2023-3-27", 1000);

    //创建账户2 
    //账号456456  初始化金额5000
    Bank user2 = Bank("456456", "2023-3-27", 5000);

    //账户1存钱
    user1.SaveMoney(200, "2023-3-27");
    //账户2存钱
    user2.SaveMoney(100, "2023-3-27");
    //账户2取钱
    user2.GetMoney(600, "2023-3-29");

    //账户1存钱
    user1.SaveMoney(300, "2023-3-28");

    //账户1存钱
    user1.SaveMoney(500, "2023-3-29");
    //账户2存钱
    user2.SaveMoney(1000, "2023-3-29");

    //账户1取钱
    user1.GetMoney(100, "2023-3-30");
    //账户2存钱
    user2.SaveMoney(1000, "2023-3-30");
    //账户2存钱
    user2.SaveMoney(350, "2023-3-31");


    //账户1查询交易记录
    user1.showDealRecord();

    //账户2查询交易记录
    user2.showDealRecord();
}