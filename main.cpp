#include <iostream>
#include <stdexcept>
#include <array>
#include "User/Account.h"
#include "Bank/Bank.h"
#include "File/File.h"

void displayOptions();

int main() {
    try{
        std::cout << "Welcome\n\n";

        bool running = true;
        Bank bank;
        File file;
        bank.storeMemberAccount(file.readMemberFile());

        while(running){
            displayOptions();

            int choice = 0;
            std::cout << "\nPlease pick an option: ";
            std::cin >> choice;


            switch(choice){
                case 0: {
                    std::string first_name, last_name;

                    std::cout << "Please enter your first name: ";
                    std::cin >> first_name;
                    std::cout << "Please enter your last name: ";
                    std::cin >> last_name;

                    Account account(first_name, last_name);
                    bank.addMemberAccount(account);
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                case 1:{
                    bank.showAllMembersAccount();
                    break;
                }
                case 2:{
                    Account account = bank.findMemberAccount();
                    break;
                }
                case 3:{
                    Account account  = bank.findMemberAccount();
                    account.checkStatus();

                    char accountType;
                    std::cout << "Withdraw from saving or checking: (s/c): ";
                    std::cin >> accountType;

                    float amount;
                    std::cout << "How much?: ";
                    std::cin >> amount;

                    account.transferMoney(amount, accountType);
                    bank.updateMemberAccount(account);
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                case 4:{
                    Account account  = bank.findMemberAccount();
                    account.checkStatus();

                    char accountType;
                    std::cout << "Saving or Checking: (s/c): ";
                    std::cin >> accountType;

                    float amount;
                    std::cout << "Please enter the amount(negative number if withdraw): ";
                    std::cin >> amount;

                    if(accountType == 's'){
                        account.updateSavingAccountBalance(amount);
                    }else{
                        account.updateCheckingAccountBalance(amount);
                    }

                    bank.updateMemberAccount(account);
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                case 5:{
                    bank.wireMoney();
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                case 6:{
                    bank.changeAccountStatus();
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                case 7:{
                    bank.removeAccount();
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                case 8:{
                    running = false;
                    std::cout << "GoodBye!!!";
                    file.writeMemberFile(bank.getAllMemberAccount());
                    break;
                }
                default:
                    throw std::invalid_argument("Please input a valid choice");
            }
        }


    }catch(std::invalid_argument const& error){
        std::cout << error.what() << std::endl;
    }

    return 0;
}

void displayOptions(){
    std::array<std::string, 9> options = {"Open Account","Show All Accounts",
                                          "Find Account", "Transfer Money",
                                          "Deposit or Withdraw Money", "Wire Transfer", "Change Account Status", "Close Account", "Quit"};

    for(int i = 0; i < options.size(); i++){
        std::cout << i << ". " << options[i] << std::endl;
    }
}