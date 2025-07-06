cmake_minimum_required(VERSION 3.16)
project(MyDataTypes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MyADT STATIC
    MyADT/dummy.cpp
    MyADT/mybinarytree.h
    MyADT/mydlist.h
    MyADT/myhashtable.h
    MyADT/mylist.h
    MyADT/myqueue.h
    MyADT/MySharedPtr.h
    MyADT/MyStack.h
    MyADT/myuniqueptr.h
    MyADT/myvector.h
    MyADT/smart_hastable.h
)

target_include_directories(MyADT PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/MyADT
)

