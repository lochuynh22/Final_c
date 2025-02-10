#include <stdio.h>
#include"function.c"
#include<stdbool.h>


typedef struct accountInfo accountInfo;
typedef struct User User;
int main(){
    accountInfo tkn[100];
    User tkn_user[100];
    int choice;
    int n=0;
    do{
        printf("\n***Bank Management System Using C***");
        printf("\n");
        printf("\tCHOOSE YOUR ROLE\n");
        printf("%-5s======================\n"," ");
        printf("%-5s[1] Admin.\n"," ");
        printf("%-5s[2] User.\n"," ");
        printf("%-5s[0] Exit the Program.\n"," ");
        printf("%-5s======================\n","");
        printf("%-5sEnter The Choice:"," ");
        scanf("%d", &choice);
        getchar();
    switch(choice){
        case 1:{
        int admin_choice;
        do{
            menuAdmin();
            scanf("%d",&admin_choice);
            getchar();
        switch (admin_choice)
        {
            case 1:
                themnguoidung(tkn,tkn_user,&n);
                break;
            case 2:
                hienthidanhsach(tkn,tkn_user,&n);
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!!");
                break;
        }
        }while (admin_choice != 0);
        break;
    }
        case 2:{
        break;
    }
        case 0:
        break;
    }
    }while(choice!=0);

    return 0;   
}
