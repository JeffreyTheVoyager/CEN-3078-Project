cmake_minimum_required(VERSION 3.21)
project(ATM)

set(CMAKE_CXX_STANDARD 23)

add_executable(ATM main.cpp User/Account.cpp User/Account.h Bank/Bank.cpp Bank/Bank.h "Payment Account/Balance.cpp" "Payment Account/Balance.h" File/File.cpp File/File.h)
