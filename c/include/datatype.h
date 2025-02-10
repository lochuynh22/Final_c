#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdbool.h>

struct Date {
    int month, day, year;
};

struct Transaction {
    char transferId[10];
    char receivingId[10];
    double amount;
    char type[10];
    char message[50];
    struct Date transactionDate;
};

struct accountInfo {
    char userId[20];
    float balance;
    bool status;
    char username[10];
    char password[10];
    struct Transaction transactionHistory[100]; // kích thước ví dụ
};

struct User {
    char userId[10];
    char name[20];
    struct Date dateOfBirth;
    bool gender;
    char phone[10];
    char email[20];
};

#endif // DATATYPE_H
