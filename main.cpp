//
// Created by likai on 2021/11/11.
//
#include <iostream>
#include <cstdio>
#include "type.h"
#include "mysql.h"
using namespace std;
struct Student {
    struct IntColumn id;
    CString name;
};

int main() {
//    sql::Driver *driver;
//    sql::Connection *conn;
//    driver = get_driver_instance();
//    conn = driver->connect("tcp://127.0.0.1:3306", "user", "password");
//    std::cout<<conn->getDriver()->getName();
    MYSQL mysqlConnect;
    mysql_init(&mysqlConnect);
    if (!mysql_real_connect(&mysqlConnect, "127.0.0.1", "root", "likai123456", NULL, MYSQL_PORT, NULL, 0)) {
        printf("failed\n");
        return -1;
    }
    mysql_select_db(&mysqlConnect, "test");
    int a = mysql_query(&mysqlConnect, "SELECT * FROM course");
    printf("%d\n", a);
    return 0;
}

