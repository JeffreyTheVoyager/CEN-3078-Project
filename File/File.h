//
// Created by Jeffrey Abraham on 12/3/22.
//

#ifndef ATM_FILE_H
#define ATM_FILE_H


#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include "../Bank/Bank.h"
#include "../User/Account.h"

class File : public Account {
    const std::string member_file_path = "../File/Member.txt";
    static std::vector<std::string> splitString(const std::string&);

public:
    File() = default;

    std::map<int, Account> readMemberFile();
    void writeMemberFile(const std::map<int, Account> &account);
};


#endif //ATM_FILE_H
