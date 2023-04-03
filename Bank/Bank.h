//
// Created by Jeffrey Abraham on 11/30/22.
//

#ifndef ATM_BANK_H
#define ATM_BANK_H

#include <map>
#include <utility>
#include <iostream>
#include <stdexcept>
#include "../User/Account.h"

class Bank : public Account {
    std::map<int, Account> members;
public:
    Bank() = default;

    // Member
    void showAllMembersAccount();
    std::map<int, Account> getAllMemberAccount();
    void storeMemberAccount(std::map<int, Account>);
    [[nodiscard]] Account findMemberAccount();
    void removeAccount();
    void updateMemberAccount(Account);
    void addMemberAccount(Account&);
    void wireMoney();
    void changeAccountStatus();
};


#endif //ATM_BANK_H
