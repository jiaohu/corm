//
// Created by likai on 2021/11/11.
//

#ifndef CORM_TYPE_H
#define CORM_TYPE_H

struct ColumnType {
    char *tag;
};

struct IntColumn {
    struct ColumnType name;
    int value;
};

struct FloatColumn {
    struct ColumnType name;
    float value;
};

struct StringColumn {
    struct ColumnType name;
    char* value;
};

typedef struct IntColumn CInt;

typedef struct FloatColumn CFloat;

typedef struct StringColumn CString;


#endif //CORM_TYPE_H
