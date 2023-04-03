//
// Created by Jeffrey Abraham on 12/3/22.
//

#include "File.h"


std::map<int, Account> File::readMemberFile() {
    std::ifstream member_file(this->member_file_path);
    std::map<int, Account> members;

    // Check if member_file is empty
    if(member_file.peek() == std::ifstream::traits_type::eof())
        return members;

    if(member_file.is_open()){
        std::string line;

        while(std::getline(member_file, line)){
            std::vector<std::string> member = splitString(line);

            // Convert string to Int
           int ID = std::stoi(member[0]);

            std::string first_name = member[1];
            std::string last_name = member[2];

            // Convert string to Float
            float savingBalance = std::stof(member[3]);
            float checkingBalance = std::stof(member[4]);

            bool status = (std::stoi(member[5]) != 0);

            Account account(first_name, last_name, savingBalance, checkingBalance, ID, status);

            members.insert(std::pair<int, Account>(ID, account));
        }
        member_file.close();
    }

    return members;
}

std::vector<std::string> File::splitString(const std::string& account) {
    std::stringstream stream(account);

    std::istream_iterator<std::string> begin(stream);
    std::istream_iterator<std::string> end;

    std::vector<std::string> vec(begin, end);
    std::copy(vec.begin(), vec.end(), std::back_inserter(vec));

    return vec;
}

void File::writeMemberFile(const std::map<int, Account>& account) {
    std::ofstream file(this->member_file_path, std::fstream::out);

    for(auto& [ID, member] : account){
        file << member.toStringAccount() << '\n';
    }

    file.close();
}
