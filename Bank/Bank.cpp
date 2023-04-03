//
// Created by Jeffrey Abraham on 11/30/22.
//

#include "Bank.h"

void Bank::showAllMembersAccount() {
    std::cout << "======Accounts======\n\n";
    if(this->members.empty()){
        throw std::invalid_argument("No Members has been created");
    }
    for(auto& [id, account] : this->members){
        std::cout << account.toStringAccount() << "\n\n";
    }
}

std::map<int, Account> Bank::getAllMemberAccount() {
    return this->members;
}

Account Bank::findMemberAccount() {
    int id;
    std::cout << "Enter Account ID: ";
    std::cin >> id;

    // Search for member
    auto member = this->members.find(id);

    if(member == this->members.end()){
        throw std::invalid_argument("Please enter a valid ID");
    }

    std::cout << member->second.toStringAccount() << "\n\n";

    return member->second;
}

void Bank::updateMemberAccount(Account account) {
    const int id = account.getID();
    this->members[id] = std::move(account);

    std::cout << "======Updated Account======\n\n";

}

void Bank::addMemberAccount(Account& account) {
    this->members.insert(std::pair<int, Account>(account.getID(), account));
    std::cout << "======Account Added======\n\n";
}

void Bank::removeAccount() {
    Account account = this->findMemberAccount();
    auto member = this->members.find(account.getID());
    this->members.erase(member);

    std::cout << "======Account Remove======\n\n";
}

void Bank::storeMemberAccount(std::map<int, Account> m) {
    this->members = std::move(m);
}

void Bank::wireMoney() {
    std::cout << "Sender\n";
    Account sender = this->findMemberAccount();
    sender.checkStatus();

    std::cout << "Receiver\n";
    Account receiver = this->findMemberAccount();
    sender.checkStatus();

    if(sender.getID() == receiver.getID()){
        throw std::invalid_argument("Sender and Receiver match");
    }

    float sender_amount;
    std::cout << "How much will " << sender.getName() << " send: ";
    std::cin >> sender_amount;

    char sender_account_type;
    std::cout << "Which account will " << sender.getName() << " withdraw from (s/c): ";
    std::cin >> sender_account_type;

    if(sender_account_type == 'c'){
        sender.updateCheckingAccountBalance(-sender_amount);
    }else{
        sender.updateSavingAccountBalance(-sender_amount);
    }
    receiver.updateCheckingAccountBalance(sender_amount);

    this->updateMemberAccount(sender);
    this->updateMemberAccount(receiver);

    std::cout << "======Wire Complete======\n\n";
}

void Bank::changeAccountStatus() {
    Account account = this->findMemberAccount();
    account.changeStatus();
    if(!account.getStatus()){
        std::cout << account.getName() << " Is Open\n\n";
    }else{
        std::cout << account.getName() << " Is Lock\n\n";
    }
    this->updateMemberAccount(account);
}