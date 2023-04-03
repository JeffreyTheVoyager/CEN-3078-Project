//
// Created by Jeffrey Abraham on 11/17/22.
//

#include "Account.h"

Account::Account(std::string& first_name, std::string& last_name) :  first_name(first_name), last_name(last_name){
    this->ID = Account::assignID();
};

Account::Account(std::string& first_name, std::string& last_name, float& saving_balance, float& checking_balance, int& ID, bool status) :
    first_name(first_name), last_name(last_name), saving_balance(saving_balance), checking_balance(checking_balance),
    ID(ID), status(status){};

int Account::getID() const {
    return this->ID;
}

bool Account::getStatus() const {
    return this->status;
}

void Account::changeStatus() {
    this->status = !this->status;
}

void Account::updateCheckingAccountBalance(const float &amount) {
    this->checkStatus();
    this->checking_balance.updateBalance(amount);
}

void Account::updateSavingAccountBalance(const float &amount) {
    this->checkStatus();
    this->saving_balance.updateBalance(amount);
}

float Account::getAccountCheckingBalance() const{
    return this->checking_balance.getBalance();
}

float Account::getAccountSavingBalance() const{
    return this->saving_balance.getBalance();
}

void Account::transferMoney(const float& amount, const char& accountType) {
    this->checkStatus();
    if(accountType == 's'){
        this->saving_balance.updateBalance(-amount);
        this->checking_balance.updateBalance(amount);
    }else if(accountType == 'c'){
        this->saving_balance.updateBalance(-amount);
        this->checking_balance.updateBalance(amount);
    }
}

int Account::assignID() {
    // Create a random number
    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());

    // Random number range
    std::uniform_int_distribution<int> dist(0, 99999);

    return dist(mt);
}

std::string Account::toStringAccount() const {
    std::string toString;
    std::ostringstream ss;
    ss << this->getID() << " " << this->getName() << " " << this->getAccountSavingBalance() <<
    " " << this->getAccountCheckingBalance() << " " << this->status;
    return ss.str();
}

std::string Account::getName() const {
    return this->first_name + " " + this->last_name;
}

void Account::checkStatus() const {
    if(this->status){
        throw std::invalid_argument("Account Lock");
    }
}