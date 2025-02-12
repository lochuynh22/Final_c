#include"datatype.h"

void giaodiendangnhap();
void menuAdmin(accountInfo tkn[], int *n);
void themnguoidung(accountInfo tkn[], int *n);
void hienthidanhsach(accountInfo tkn[], accountInfo tkn_user[], int n);
void timkiemtennguoidung(accountInfo tkn[], int n);
int is_duplicate(struct accountInfo tkn[], struct User tkn_user[], int count, 
    const char *new_id, const char *new_email, const char *new_phone, const char *new_username);