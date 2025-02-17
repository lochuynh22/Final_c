#include"datatype.h"
//ham giao dien chinh
void giaodiendangnhap();
//ham giao dien admin
void menuAdmin();
//ham them nguoi dung
void adduser(accountInfo tkn[], int *n);
//ham hien thi danh sach
void displaylistuser(accountInfo tkn[], accountInfo tkn_user[], int n);
//ham tim kiem nguoi dung
void finduser(accountInfo tkn[], int n);
//ham kiem tra trung
int is_duplicate(const char *new_id, const char *new_email, const char *new_phone, const char *new_username);
//ham mo khoa
void lockunclockuser(struct accountInfo tkn[], struct User tkn_user[],int n);