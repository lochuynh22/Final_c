#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Date {
    int day, month, year;
};

struct accountInfo {
    char userId[20];
    float balance;
    bool status;
    char username[20];
    char password[20];
};

struct User {
    char userId[20];
    char name[50];
    struct Date dateOfBirth;
    bool gender;  // 0: Female, 1: Male
    char phone[15];
    char email[50];
};

void clear_buffer() {
    int c;
    while ((c= getchar()) !='\n'&&c != EOF);
}
void menuAdmin(){
    printf("***Admin Management System Using C***");
    printf("\n");
    printf("%-10s Menu\n", " ");
    printf("%-5s==================\n", " ");
    printf("%-5s[1] Add A New user.\n"," ");
    printf("%-5s[2] Show All users.\n"," ");
    printf("%-5s[3] Show detail an user.\n"," ");
    printf("%-5s[4] Loock(Unlock)an user.\n"," ");
    printf("%-5s[5] User Guideline.\n"," ");
    printf("%-5s[6] About Us.\n"," ");
    printf("%-5s[0] Exit the program.\n"," ");
    printf("%-5s==================\n", " ");
    printf("%-5sEnter The Choice:"," ");
};

void themnguoidung(struct accountInfo tkn[100], struct User tkn_user[100], int *n) {
    printf("\t*** Add a New User ***\n");

    //ID
    int len;
    do {
        printf("Enter the ID (10-20 characters): ");
        fgets(tkn[*n].userId, sizeof(tkn[*n].userId),stdin);
        tkn[*n].userId[strcspn(tkn[*n].userId, "\n")]='\0';
        len = strlen(tkn[*n].userId);

        if (len <10||len>20) {
            printf("Enter the ID (10-20 characters):\n");
        }
    } while (len <10||len> 20);

    //nhap ho ten
    printf("Enter full name: ");
    fgets(tkn_user[*n].name,sizeof(tkn_user[*n].name),stdin);
    tkn_user[*n].name[strcspn(tkn_user[*n].name,"\n")] ='\0';

    //email
    printf("Enter email: ");
    fgets(tkn_user[*n].email,sizeof(tkn_user[*n].email),stdin);
    tkn_user[*n].email[strcspn(tkn_user[*n].email,"\n")]='\0';

    //so dien thoai
    printf("Enter phone number: ");
    fgets(tkn_user[*n].phone,sizeof(tkn_user[*n].phone),stdin);
    tkn_user[*n].phone[strcspn(tkn_user[*n].phone,"\n")]='\0';

    //gioi tinh
    

    //ngay sinh
    printf("Enter Date of Birth:\n");
    printf("\tDay: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.day);
    printf("\tMonth: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.month);
    printf("\tYear: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.year);
    clear_buffer();

    //ten dang nhap
    printf("Enter username: ");
    fgets(tkn[*n].username, sizeof(tkn[*n].username),stdin);
    tkn[*n].username[strcspn(tkn[*n].username,"\n")] ='\0';

    //so du banlance
    printf("Enter the balance:");
    scanf("%f",&tkn[*n].balance);
    clear_buffer();

    printf("User added successfully!\n");
    (*n)++;
}

void hienthidanhsach(struct accountInfo tkn[100], struct User tkn_user[100], int *n) {
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
    }
}