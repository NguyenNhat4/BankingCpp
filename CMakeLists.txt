cmake_minimum_required(VERSION 3.25)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankingSystem main.cpp Account.cpp Account.h Bank.cpp Bank.h)
