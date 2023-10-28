cmake_minimum_required(VERSION 3.10)
set(PACKAGE_NAME OpenCV_study)
project(${PACKAGE_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WEEK_DAY week1_day4)

add_subdirectory(src)

# Declare the executable target built from your sources
add_executable(main src/${WEEK_DAY}/main.cpp)

# 라이브러리를 링킹해주기
target_link_libraries(main PRIVATE ${WEEK_DAY})
