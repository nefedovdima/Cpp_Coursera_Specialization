cmake_minimum_required(VERSION 3.23)
project(Cpp_Coursera_Specialization)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(White_1)
include_directories(Yellow_2)

add_executable(Cpp_Coursera_Specialization
        .metadata/.plugins/org.eclipse.cdt.make.core/specs.c
        .metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp
        White_1/Week_1/main.cpp
        White_1/Week_2/week_2.cpp
        White_1/Week_3/week_3.cpp
        White_1/Week_4/week_4.cpp
        White_1/Week_5/final.cpp
        Yellow_2/Week_1/max_repetition.cpp
        Yellow_2/Week_1/week_1.cpp
        .gitignore
        LICENSE
        README.md
        Yellow_2/Week_1/all_in_sqr.cpp
        Yellow_2/Week_1/get_ref_strict.cpp Yellow_2/Week_2/synonyms.cpp Yellow_2/Week_2/sum_unit_test.cpp)
