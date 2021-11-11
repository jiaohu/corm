cmake_minimum_required(VERSION 3.19.6)
project(corm)


#set(MYSQL_CPPCONN_DIR /usr/local/mysql-connector-c++-8.0)
#
#include_directories(${MYSQL_CPPCONN_DIR}/include/jdbc)
#
#link_libraries(/usr/local/mysql-connector-c++/lib64/libmysqlcppconn8.dylib)
if (WIN32)
    set(MYSQL_ROOT_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0)
    message(${MYSQL_ROOT_DIR})
elseif (APPLE)
    set(MYSQL_ROOT_DIR /usr/local/Cellar/mysql/8.0.23)
    message(${MYSQL_ROOT_DIR})
endif ()

message(${MYSQL_ROOT_DIR})
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(mysql REQUIRED_VARS MYSQL_ROOT_DIR)

set(CMAKE_C_STANDARD 11)

include_directories(.)

#add_subdirectory(test)


add_executable(corm
        type.h main.cpp)
include_directories(${MYSQL_ROOT_DIR}/include)
link_directories(${MYSQL_ROOT_DIR}/lib)
#link_libraries(libmysql)
if (WIN32)
    target_link_libraries(${PROJECT_NAME}  -L${MYSQL_ROOT_DIR}/lib -llibmysql -lz)
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} -L${MYSQL_ROOT_DIR}/lib -lmysqlclient -lz)
endif ()