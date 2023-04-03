//
// Created by Jeffrey Abraham on 12/3/22.
//

#ifndef ATM_BALANCE_H
#define ATM_BALANCE_H

#include <stdexcept>
#include <cmath>

class Balance {
    // Start at 1000
    float balance = 1000;
    static float normalizeBalance(float);

public:
    Balance() = default;
    explicit Balance(float&);

    float getBalance() const;
    float updateBalance(const float&);
};


#endif //ATM_BALANCE_H
