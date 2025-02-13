#include"datatype.h"

void giaodiendangnhap();
void menuAdmin();
void adduser(accountInfo tkn[], int *n);
void displaylistuser(accountInfo tkn[], accountInfo tkn_user[], int n);
void finduser(accountInfo tkn[], int n);
int is_duplicate(struct accountInfo tkn[], struct User tkn_user[], int count, 
    const char *new_id, const char *new_email, const char *new_phone, const char *new_username);
void lockunclockuser(struct accountInfo tkn[], struct User tkn_user[],int n);