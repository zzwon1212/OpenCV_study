cmake_minimum_required(VERSION 3.10)
set(PACKAGE_NAME HelloCV)
project(${PACKAGE_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(weeks_days)

# Declare the executable target built from your sources
add_executable(1_2_main weeks_days/week1_day2/main.cpp)

# 라이브러리를 링킹해주기
target_link_libraries(1_2_main PRIVATE week1_day2)
