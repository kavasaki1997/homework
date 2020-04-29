#include <iostream>
#include "ATM.h"
#include <thread>
#include <string>
using namespace std;
void f(ATM& user,int pCode,int money)
{
    user.getMoney(pCode);
    user.tookMoney(pCode,money);
    user.getMoney(pCode);
}
void transferMoney(ATM& user1, ATM& user2, int code1, int code2, int money)
{
    if(user1.tookMoney(code1,money))
        user2.addMoney(code2, money);
}
int main()
{
    int code, id;
    cout << "Write code and ID\n";
    cin >> code >> id;
    ATM user(code);
    thread t1(f, ref(user), code, 23);
    thread t2(f, ref(user), code, 23);
    thread t3(f, ref(user), code, 23);
    thread t4(f, ref(user), code, 23);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
  
    
    return 0;
}
