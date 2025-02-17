
#include <stdbool.h>

struct Date {
    int month, day, year;
};

struct accountInfo {
    char userId[20];
    float balance;
    char status[10];
    char username[10];
};

struct User {
    char name[20];
    struct Date dateOfBirth;
    char phone[15];
    char email[30];
};

