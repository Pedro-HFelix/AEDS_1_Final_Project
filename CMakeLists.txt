cmake_minimum_required(VERSION 3.28)
project(finalC__)

set(CMAKE_CXX_STANDARD 17)

add_executable(finalC__ main.cpp
        class/Date.h
        class/Date.cpp
        class/Person.h
        class/Person.cpp
        class/Student.h
        class/Student.cpp
        class/Teacher.cpp
        class/Teacher.h
)
