# cmake needs this line
cmake_minimum_required(VERSION 3.10)

# Define project name
set(PACKAGE_NAME OpenCV_study)
project(${PACKAGE_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WEEK_DAY week1_day4)

# 1_2_SOURCE_FILES라는 변수를 만들려고 함
set(SOURCE_FILES
        main.cpp
        )

# 소스 파일들을 기반으로 라이브러리를 빌드할 명령어 추가
add_library(${WEEK_DAY}
        ${SOURCE_FILES}
        )

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# 소스 파일들이 사용할 헤더 파일 엮기
target_include_directories(${WEEK_DAY} PUBLIC ${OpenCV_INCLUDE_DIRS})

# Link your application with OpenCV libraries
target_link_libraries(${WEEK_DAY} PRIVATE ${OpenCV_LIBS})
