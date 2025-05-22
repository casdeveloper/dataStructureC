cmake_minimum_required(VERSION 3.29)
project(doublyLinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(doublyLinkedList main.cpp
        doublyLinkedList.h
        DoublyLinkedList.cpp)
