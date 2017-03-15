cmake_minimum_required(VERSION 3.6)
project(Implementation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main/main.cpp Customer/customer.cpp Transactions/history.cpp "Data Structures/hashtable.cpp" Transactions/borrow.cpp "Data Structures/bst.cpp" Transactions/return.cpp Store/store.cpp Transactions/transaction.cpp "Factories/transactionfactory.cpp" Transactions/viewinventory.cpp "Data Structures/queue.cpp" Movies/classic.cpp Movies/drama.cpp Movies/comedy.cpp Movies/movie.cpp "Factories/moviefactory.cpp" "Factories/moviefactory.h" globals.h)
add_executable(Implementation ${SOURCE_FILES})