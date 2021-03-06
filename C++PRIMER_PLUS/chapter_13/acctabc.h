// acctabc.h -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_

// Abstract Base Class
class AcctABC
{
private:
    enum {MAX = 35};
    char fullName[MAX];
    long acctNum;                                       // 编号
    double balance;                                     // 余额
protected:
    const char* FullName()const { return fullName; };
    long AcctNum()const { return acctNum; };
    std::ios_base::fmtflags SetFormat() const;
public:
    AcctABC(const char *s = "Nullbody", long an = -1,
        double bal = 0.0);
    void Deposit(double amt);                           // 存款    
    virtual void Withdraw(double amt) = 0;              // 取钱 pure virtual function
    double Balance()const { return balance; }           // 余额
    virtual void ViewAcct()const = 0;                   // 输出账户信息 pure virtual function
    virtual ~AcctABC() {}                               // 析构函数
};


// Brass Account Class
class Brass: public AcctABC
{
public:
    Brass(const char *s = "Nullbody", long an = -1,
        double bal = 0.0): AcctABC(s, an, bal) {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct()const;
    virtual ~Brass() {}  
};

// Brass Plus Account Class
class BrassPlus: public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const char *s = "Nullbody", long an = -1,
        double bal = 0.0, double ml = 500,
        double r = 0.10);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif