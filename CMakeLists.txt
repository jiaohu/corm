cmake_minimum_required(VERSION 3.19.6)
project(corm)


#set(MYSQL_CPPCONN_DIR /usr/local/mysql-connector-c++-8.0)
#
#include_directories(${MYSQL_CPPCONN_DIR}/include/jdbc)
#
#link_libraries(/usr/local/mysql-connector-c++/lib64/libmysqlcppconn8.dylib)
if (WIN32)
    message(1111)
    set(MYSQL_ROOT_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0)
    set(MYSQL_ROOT_LIB_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0\\lib)
    set(MYSQL_ROOT_INC_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0\\include)
elseif (APPLE)
    set(MYSQL_ROOT_LIB_DIR /usr/local/Cellar/mysql/8.0.23)
    set(MYSQL_ROOT_LIB_DIR /usr/local/Cellar/mysql/8.0.23/lib)
    set(MYSQL_ROOT_INC_DIR /usr/local/Cellar/mysql/8.0.23/include)
endif ()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(mysql REQUIRED_VARS MYSQL_ROOT_DIR)

set(CMAKE_CXX_STANDARD 11)

# include_directories(.)

#add_subdirectory(test)


message(${MYSQL_ROOT_INC_DIR})
include_directories(${MYSQL_ROOT_INC_DIR})
link_directories(${MYSQL_ROOT_LIB_DIR})
link_libraries(libmysql)
add_executable(corm
        type.h main.cpp)
if (WIN32)
    target_link_libraries(corm  libmysql)
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} -L${MYSQL_ROOT_LIB_DIR} -lmysqlclient -lz)
endif ()