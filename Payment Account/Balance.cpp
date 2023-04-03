//
// Created by Jeffrey Abraham on 12/3/22.
//

#include "Balance.h"

Balance::Balance(float& balance) : balance(balance) {}

float Balance::getBalance() const {
    return Balance::normalizeBalance(this->balance);
}

float Balance::updateBalance(const float& amount) {
    if(this->balance + amount < 0){
        throw std::invalid_argument("Insufficient Funds");
    }
    this->balance += Balance::normalizeBalance(amount);
    return this->balance;
}

float Balance::normalizeBalance(float amount) {
    // Format amount
    float dollar;
    float cents = std::modf(amount, &dollar);
    return (dollar + cents);
}
