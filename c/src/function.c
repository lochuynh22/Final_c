//trien khai ham da khai bao

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/datatype.h"


//doc ki tu xuong dong
void clear_buffer() {
    int c;
    while ((c= getchar()) !='\n'&&c != EOF);
}
//ham xem trung ko
int is_duplicate(struct accountInfo tkn[], struct User tkn_user[], int count, 
    const char *new_id, const char *new_email, const char *new_phone, const char *new_username) {
for (int i=0; i<count;i++) {
    if ((new_id &&strcmp(tkn[i].userId, new_id)==0)||
        (new_email &&strcmp(tkn_user[i].email, new_email)==0)||
        (new_phone &&strcmp(tkn_user[i].phone, new_phone)==0)||
        (new_username &&strcmp(tkn[i].username, new_username)== 0)){
            return 1;  // Phát hiện trùng lặp
    }
}
return 0;  // Không trùng lặp
}
void menuAdmin(){
    printf("***Admin Management System Using C***");
    printf("\n");
    printf("%-10s Menu\n", " ");
    printf("%-5s==================\n", " ");
    printf("%-5s[1] Add A New user.\n"," ");
    printf("%-5s[2] Show All users.\n"," ");
    printf("%-5s[3] Search by username .\n"," ");
    printf("%-5s[4] Loock(Unlock)an user.\n"," ");
    printf("%-5s[5] User Guideline.\n"," ");
    printf("%-5s[6] About Us.\n"," ");
    printf("%-5s[0] Exit the program.\n"," ");
    printf("%-5s==================\n", " ");
    printf("%-5sEnter The Choice:"," ");
};

void themnguoidung(struct accountInfo tkn[100], struct User tkn_user[100], int *n) {
    printf("\t*** Add a New User ***\n");

    //Nhap du lieu ID
    int len;
    do {
        printf("Enter the ID (10-20 characters): ");
        fgets(tkn[*n].userId, sizeof(tkn[*n].userId),stdin);
        tkn[*n].userId[strcspn(tkn[*n].userId, "\n")]='\0';

        len = strlen(tkn[*n].userId);
        if (len <10||len>20) {
            printf("Error:ID can not be less than 10 char!!!\n");
            continue;
        }
        if (is_duplicate(tkn, tkn_user, *n, tkn[*n].userId, NULL, NULL, NULL)) {
            printf("Error: Duplicate ID!!!\n");
            continue;
        }
        break;
        
    } while (1);

    //nhap ho ten
    do{
        printf("Enter full name: ");
        fgets(tkn_user[*n].name,sizeof(tkn_user[*n].name),stdin);
        tkn_user[*n].name[strcspn(tkn_user[*n].name,"\n")] ='\0';
        len = strlen(tkn_user[*n].name);
        // if() them dk

    }while(len<5 || len>25);

    //email
    do{
        printf("Enter email: ");
        fgets(tkn_user[*n].email,sizeof(tkn_user[*n].email),stdin);
        tkn_user[*n].email[strcspn(tkn_user[*n].email,"\n")]='\0';
        len=strlen(tkn_user[*n].email);
        if(len<10 || len>30){
            printf("Error: Email can not be less 10 char");
            continue;
        }
        if(is_duplicate(tkn, tkn_user,*n,NULL, tkn_user[*n].email, NULL, NULL)){
            printf("Error: Duplicate email !!!\n");
            continue;
        }
        break;
    }while(1);
    

    //so dien thoai
    do{
        printf("Enter phone number: ");
        fgets(tkn_user[*n].phone,sizeof(tkn_user[*n].phone),stdin);
        tkn_user[*n].phone[strcspn(tkn_user[*n].phone,"\n")]='\0';
        len=strlen(tkn_user[*n].phone);
        if(len<5||len>15){
            printf("Error: Phone number can not be less 5 num!!\n");
            continue;
        }
        if(is_duplicate(tkn, tkn_user,*n,NULL, NULL, tkn_user[*n].phone, NULL)){
            printf("Error: Duplicate phone number !!!\n");
            continue;
        }
        break;
    }while(1);

    // //gioi tinh    
    // printf("Enter the gender (0:female 1: male):");
    // scanf("%d", &tkn_user[*n].gender);
        
    //ngay sinh
    printf("Enter Date of Birth:\n");
    printf("\tEnter the Day: ");
    scanf("%d",&tkn_user[*n].dateOfBirth.day);
    printf("\tEnter the Month: ");
    scanf("%d",&tkn_user[*n].dateOfBirth.month);
    printf("\tEnter the Year: ");
    scanf("%d",&tkn_user[*n].dateOfBirth.year);
    clear_buffer();

    //ten dang nhap
    do{
        printf("Enter username: ");
        fgets(tkn[*n].username, sizeof(tkn[*n].username),stdin);
        tkn[*n].username[strcspn(tkn[*n].username,"\n")] ='\0';
        len=strlen(tkn[*n].username);
        if(len<5||len>15){
            printf("Error: Username can not less than 5 char!!\n");
            continue;
        }
        if(is_duplicate(tkn, tkn_user,*n,NULL, NULL, NULL, tkn[*n].username)){
            printf("Error: Duplicate Username !!!\n");
            continue;
        }
        break;
    }while(len<5);

    //so du banlance
    do{
        printf("Enter the balance:");
        scanf("%f",&tkn[*n].balance);
        if(tkn[*n].balance!=1){
            clear_buffer();
            continue;
        }
        if(tkn[*n].balance<0){
            printf("Error!!!"); 
        }
    }while(tkn[*n].balance<0);

    printf("User added successfully!\n");
    (*n)++;
}

void hienthidanhsach(struct accountInfo tkn[100], struct User tkn_user[100], int *n) {
    if(*n>0){
    printf("+======================+======================+==============================+====================+============+\n");
    printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
    printf("+======================+======================+==============================+====================+============+\n");

    for (int i=0;i<*n;i++) {
        printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
               tkn[i].userId,
               tkn_user[i].name,
               tkn_user[i].email,
               tkn_user[i].phone,
               "lock");
        printf("+======================+======================+==============================+====================+============+\n");
    }}else 
    printf("***EMPTY LIST***\n");
}

void timkiemtennguoidung(struct accountInfo tkn[100], struct User tkn_user[100], char a[],int n){
    if(n==0){
        printf("***EMPTY LIST***\n");
        return;
    }
    int choice_1;
    printf("\t***SEARCH BY*** \n");
    printf("\t  1.ID\n");
    printf("\t  2.Name\n");
    printf("\t  Enter choice: ");
    scanf("%d", &choice_1);
    getchar();
    if(choice_1==0){
        return;
    }
    if(choice_1==1){
        char id[23];
        printf("Enter id find:");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] ='\0';
        int found=0;

    for (int i=0;i<n;i++) {
        if (strcmp(tkn[i].userId,id) == 0) { 
            printf("+======================+======================+==============================+====================+============+\n");
            printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
            printf("+======================+======================+==============================+====================+============+\n");
            printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
                tkn[i].userId,
                tkn_user[i].name,
                tkn_user[i].email,
                tkn_user[i].phone,
                "lock");
            printf("+======================+======================+==============================+====================+============+\n");
            found = 1;
            break;     
        }
    }

    if (!found) {
        printf("\t***No find***!!\n");
    }
    }
    if(choice_1==2){
    char find_user[50];
    printf("Enter name user find:");
    fgets(find_user, sizeof(find_user), stdin);
    
    int len= strlen(find_user);
    if(len>0 &&find_user[len-1]=='\n')
        find_user[len-1]='\0';
    int found=0;
    for(int i=0; i< n;i++){
        //timkiemchuoicontrongchuoilon
        if (strstr(tkn_user[i].name, find_user)!= NULL) {
            printf("+======================+======================+==============================+====================+============+\n");
            printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
            printf("+======================+======================+==============================+====================+============+\n");
            printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
                tkn[i].userId,
                tkn_user[i].name,
                tkn_user[i].email,
                tkn_user[i].phone,
                "lock");
         printf("+======================+======================+==============================+====================+============+\n");
            found = 1;
        }
    }
    if(!found){
        printf("\t***No find***!!\n");
    }
}
}