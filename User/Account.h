//
// Created by Jeffrey Abraham on 11/17/22.
//

#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H

#include <string>
#include <sstream>
#include <utility>
#include <random>
#include "../Payment Account/Balance.h"

class Account : public Balance{
    std::string first_name, last_name;
    int ID;
    bool status;
    Balance saving_balance, checking_balance;

    static int assignID();
public:
    Account() = default;
    Account(std::string&, std::string&);
    Account(std::string&, std::string&, float&, float&, int&, bool);

    // Setter
    void updateCheckingAccountBalance(const float& amount);
    void updateSavingAccountBalance(const float& amount);
    void changeStatus();
    void transferMoney(const float&, const char&);

    // Getter
    bool getStatus() const;
    int getID() const;
    float getAccountCheckingBalance() const;
    float getAccountSavingBalance() const;
    std::string toStringAccount() const;
    std::string getName() const;
    void checkStatus() const;
};


#endif //ATM_ACCOUNT_H
