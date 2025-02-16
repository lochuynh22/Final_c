//trien khai ham da khai bao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/datatype.h"


//doc ki tu xuong dong
void clear_buffer() {
    int c;
    while ((c= getchar()) !='\n'&&c != EOF);
}
void clear_system(){
    int c;
    printf("Press (1) back: ");
    scanf("%d", &c);
    fflush(stdin);
    if(c==1)
    system("cls");
    return;
}
//ham xem trung ko
int is_duplicate(struct accountInfo tkn[], struct User tkn_user[], int count, 
    const char *new_id, const char *new_email, 
    const char *new_phone, const char *new_username, 
    const char *filename) {
// trung trong du lieu nhap
for (int i = 0; i < count; i++) {
if ((new_id && strcmp(tkn[i].userId, new_id) == 0) ||
(new_email && strcmp(tkn_user[i].email, new_email) == 0) ||
(new_phone && strcmp(tkn_user[i].phone, new_phone) == 0) ||
(new_username && strcmp(tkn[i].username, new_username) == 0)) {
return 1; // trung
}
}

// trung trong file txt
FILE *file = fopen(filename, "r");
if (file == NULL) {
printf("Error: File %s not found, assuming no duplicates in file.\n", filename);
return 0; // ko co trong file ko trung
}

char userId[20], email[30], phone[15], username[10];
while (fscanf(file, "%[^,], %*[^,], %[^,], %[^,], %*d-%*d-%*d, %[^,], %*f, %*s\n",
 userId, email, phone, username) == 4) {

if ((new_id && strcmp(userId, new_id) == 0) ||
(new_email && strcmp(email, new_email) == 0) ||
(new_phone && strcmp(phone, new_phone) == 0) ||
(new_username && strcmp(username, new_username) == 0)) {
fclose(file);
return 1; // trung
}
}

fclose(file);
return 0; //0 trung
}

void menuAdmin(){
    printf("***Admin Management System Using C***");
    printf("\n");
    printf("%-10s Menu\n", " ");
    printf("%-5s==================\n", " ");
    printf("%-5s[1] Add A New user.\n"," ");
    printf("%-5s[2] Show All users.\n"," ");
    printf("%-5s[3] Search by username .\n"," ");
    printf("%-5s[4] Lock(Unlock)an user.\n"," ");
    printf("%-5s[5] Sort the list.\n"," ");
    printf("%-5s[6] About Us.\n"," ");
    printf("%-5s[0] Exit the program.\n"," ");
    printf("%-5s==================\n", " ");
    printf("%-5sEnter The Choice:"," ");

};


void adduser(struct accountInfo tkn[100], struct User tkn_user[100], int *n) {
    FILE *file = fopen("user.txt", "a"); //mo file che do ghi them
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\t*** Add a New User ***\n");
    strcpy(tkn[*n].status, "LOCK");
    fflush(stdin);
    
    int len;  

    // Nhập ID
    do {
        printf("Enter the ID (10-20 characters): ");
        fgets(tkn[*n].userId, sizeof(tkn[*n].userId), stdin);
        tkn[*n].userId[strcspn(tkn[*n].userId, "\n")] = '\0';

        len = strlen(tkn[*n].userId);
        if (len < 10 || len > 20) {
            printf("Error: ID must be between 10-20 characters!\n");
            continue;
        }
        if (is_duplicate(tkn, tkn_user, *n, tkn[*n].userId, NULL, NULL, NULL, "user.txt")) {
            printf("Error: Duplicate ID!!!\n");
            continue;
        }
        break;
    } while (1);

    // Nhập họ tên
    do {
        printf("Enter full name: ");
        fgets(tkn_user[*n].name, sizeof(tkn_user[*n].name), stdin);
        tkn_user[*n].name[strcspn(tkn_user[*n].name, "\n")] = '\0';
        len = strlen(tkn_user[*n].name);
    } while (len < 5 || len > 25);

    // Nhập email
    do {
        printf("Enter email: ");
        fgets(tkn_user[*n].email, sizeof(tkn_user[*n].email), stdin);
        tkn_user[*n].email[strcspn(tkn_user[*n].email, "\n")] = '\0';
        len = strlen(tkn_user[*n].email);
        if (len < 10 || len > 30) {
            printf("Error: Email must be between 10-30 characters!\n");
            continue;
        }
        if (is_duplicate(tkn, tkn_user, *n, NULL, tkn_user[*n].email, NULL, NULL, "user.txt")) {
            printf("Error: Duplicate email!!!\n");
            continue;
        }
        break;
    } while (1);

    // Nhập số điện thoại
    do {
        printf("Enter phone number: ");
        fgets(tkn_user[*n].phone, sizeof(tkn_user[*n].phone), stdin);
        tkn_user[*n].phone[strcspn(tkn_user[*n].phone, "\n")] = '\0';
        len = strlen(tkn_user[*n].phone);
        if (len < 5 || len > 15) {
            printf("Error: Phone number must be between 5-15 characters!\n");
            continue;
        }
        if (is_duplicate(tkn, tkn_user, *n, NULL, NULL, tkn_user[*n].phone, NULL, "user.txt")) {
            printf("Error: Duplicate phone number!!!\n");
            continue;
        }
        break;
    } while (1);

    // Nhập ngày sinh
    printf("Enter Date of Birth:\n");
    printf("\tEnter the Day: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.day);
    printf("\tEnter the Month: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.month);
    printf("\tEnter the Year: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.year);
    fflush(stdin);

    // Nhập tên đăng nhập
    do {
        printf("Enter username: ");
        fgets(tkn[*n].username, sizeof(tkn[*n].username), stdin);
        tkn[*n].username[strcspn(tkn[*n].username, "\n")] = '\0';
        len = strlen(tkn[*n].username);
        if (len < 5 || len > 15) {
            printf("Error: Username must be between 5-15 characters!\n");
            continue;
        }
        if (is_duplicate(tkn, tkn_user, *n, NULL, NULL, NULL, tkn[*n].username, "user.txt")) {
            printf("Error: Duplicate username!!!\n");
            continue;
        }
        break;
    } while (1);

    // Nhập số dư tài khoản (balance)
    do {
        printf("Enter the balance: ");
        scanf("%f", &tkn[*n].balance);
        fflush(stdin);
        if (tkn[*n].balance < 0) {
            printf("Error: Balance cannot be negative!\n");
        }
    } while (tkn[*n].balance < 0);

    //ghi du lieu vao file
    fprintf(file, "%s, %s, %s, %s, %d-%d-%d, %s, %.2f, %s\n", 
            tkn[*n].userId,
            tkn_user[*n].name,
            tkn_user[*n].email,
            tkn_user[*n].phone,
            tkn_user[*n].dateOfBirth.day,
            tkn_user[*n].dateOfBirth.month,
            tkn_user[*n].dateOfBirth.year,
            tkn[*n].username,
            tkn[*n].balance,
            tkn[*n].status);

    fclose(file);
    (*n)++;
    system("cls");
    printf("User added successfully!\n");
}

void displaylistuser() {
    FILE *file = fopen("user.txt", "r"); // mo file che do doc
    if (file == NULL) {
        printf("Error: Cannot open file users.txt!\n");
        return;
    }

    char userId[25], name[30], email[40], phone[20], username[20], status[10];
    int day, month, year;
    float balance;
    int choice;

    printf("+======================+======================+==============================+====================+============+\n");
    printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
    printf("+======================+======================+==============================+====================+============+\n");

    while (fscanf(file, " %[^,], %[^,], %[^,], %[^,], %d-%d-%d, %[^,], %f, %s\n", 
                  userId, name, email, phone, &day, &month, &year, username, &balance, status) != EOF) {
        printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
               userId, name, email, phone, status);
        printf("+======================+======================+==============================+====================+============+\n");
    }

    fclose(file); // Đóng file sau khi đọc xong

    // Quay lại menu chính
    printf("Press (1) to go back: ");
    scanf("%d", &choice);
    system("cls");
    if (choice == 1) {
        return;
    }
}

void login(){

}
void finduser(struct accountInfo tkn[], struct User tkn_user[], int n) {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file user.txt!\n");
        return;
    }
    while (fscanf(file, "%[^,], %[^,], %[^,], %[^,], %d-%d-%d, %[^,], %f, %s\n",
                  tkn[n].userId, tkn_user[n].name, tkn_user[n].email,
                  tkn_user[n].phone, &tkn_user[n].dateOfBirth.day,
                  &tkn_user[n].dateOfBirth.month, &tkn_user[n].dateOfBirth.year,
                  tkn[n].username, &tkn[n].balance, tkn[n].status) == 10) {
        n++;
    }
    fclose(file);

    if (n == 0) {
        printf("*** EMPTY LIST ***\n");
        clear_system();
        return;
    }

    int choice_1;
    printf("\t*** SEARCH BY *** \n");
    printf("\t  1. ID\n");
    printf("\t  2. Name\n");
    printf("\t  0. Back to Menu\n");
    printf("\t  Enter choice: ");
    scanf("%d", &choice_1);
    getchar();

    system("cls");

    switch (choice_1) {
        //id
        case 1: { 
            char id[23];
            printf("Enter ID to find: ");
            fgets(id, sizeof(id),stdin);
            id[strcspn(id,"\n")] ='\0'; 

            int found = 0;
            for (int i =0; i<n;i++) {
                if (strcmp(tkn[i].userId, id)==0) { 
                    printf("Find by ID\n");
                    printf("+======================+======================+==============================+====================+============+\n");
                    printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
                    printf("+======================+======================+==============================+====================+============+\n");
                    printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
                        tkn[i].userId, tkn_user[i].name, tkn_user[i].email, tkn_user[i].phone, tkn[i].status);
                    printf("+======================+======================+==============================+====================+============+\n");
                    printf("+ Username: %s\n",tkn[i].username);
                    printf("+ Date of Birth: %02d/%02d/%4d\n",tkn_user[i].dateOfBirth.day, tkn_user[i].dateOfBirth.month, tkn_user[i].dateOfBirth.year);
                    printf("+ Balance: %.2f\n",tkn[i].balance);
                    found=1;
                    break;
                }
            }

            if (!found) {
                printf("Error: User ID not found!\n");
            }
            break;
        }

        case 2: {
            //name
            char find_user[50];
            printf("Enter name to find: ");
            fgets(find_user,sizeof(find_user),stdin);
            find_user[strcspn(find_user, "\n")]='\0'; 

            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strstr(tkn_user[i].name, find_user) != NULL) { 
                    printf("Find by Name\n");
                    printf("+======================+======================+==============================+====================+============+\n");
                    printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
                    printf("+======================+======================+==============================+====================+============+\n");
                    printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
                        tkn[i].userId, tkn_user[i].name, tkn_user[i].email, tkn_user[i].phone, tkn[i].status);
                    printf("+======================+======================+==============================+====================+============+\n");
                    found = 1;
                }
            }

            if (!found) {
                printf("Error: User ID not found!\n");
            }
            break;
        }

        case 0:
            return;

        default:
            printf("Invalid choice!\n");
            break;
    }

    clear_system();
}

void lockUnlockUser(struct accountInfo tkn[],struct User tkn_user[], int n) {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file user.txt!\n");
        return;
    }
    n=0;
    while (fscanf(file, "%[^,], %[^,], %[^,], %[^,], %d-%d-%d, %[^,], %f, %s\n",
                  tkn[n].userId, tkn_user[n].name, tkn_user[n].email,
                  tkn_user[n].phone, &tkn_user[n].dateOfBirth.day,
                  &tkn_user[n].dateOfBirth.month, &tkn_user[n].dateOfBirth.year,
                  tkn[n].username, &tkn[n].balance, tkn[n].status) == 10) {
        n++;
    }
    fclose(file);

    if (n == 0) {
        printf("*** EMPTY LIST ***\n");
        printf("Press (1) to go back: ");
        int choice_1;
        scanf("%d",&choice_1);
        getchar();
        system("cls");
        return; 
    }

    char userId[21];
    int choice, found = 0;
    printf("\t***LOCK UNLOCK USER***\n");
    printf("Enter the User ID to lock/unlock: ");
    fflush(stdin);
    fgets(userId, sizeof(userId), stdin);
    userId[strcspn(userId,"\n")] ='\0';
    for (int i = 0; i<n;i++) {
        if (strcmp(tkn[i].userId, userId) == 0) { 
            found = 1;
            system("cls");
            printf("===============*INFO*===============\n");
            printf("ID:%s\nName:%s\nStatus:%s\n",tkn[i].userId, tkn_user[i].name,tkn[i].status);
            printf("====================================\n");
            printf("Choose an option:\n");
            if(strcmp(tkn[i].status, "LOCK")==0){
                printf("1. Unlock Account\n");
            }else{
                printf("1. Lock Account\n");
            }
            printf("2. Back Menu\n");
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &choice);
            getchar(); 
            system("cls");

            if (choice == 1) {
                system("cls");
                if (strcmp(tkn[i].status, "LOCK") == 0) {
                    strcpy(tkn[i].status, "UNLOCK");
                    printf("====================================\n");
                    printf("ID: %s has been UNLOCKED.\n", userId);
                    printf("====================================\n");
                    clear_system();
                } else {
                    strcpy(tkn[i].status, "LOCK");    
                    printf("====================================\n");
                    printf("ID: %s has been LOCKED.\n", userId);
                    printf("====================================\n");
                    clear_system();
                }
                FILE *fileWrite = fopen("user.txt", "w");
                if (fileWrite == NULL) {
                    printf("Error: Cannot open file user.txt for writing!\n");
                    return;
                }

                for (int j = 0; j < n; j++) {
                    fprintf(fileWrite, "%s, %s, %s, %s, %d-%d-%d, %s, %.2f, %s\n",
                            tkn[j].userId, tkn_user[j].name, tkn_user[j].email,
                            tkn_user[j].phone, tkn_user[j].dateOfBirth.day,
                            tkn_user[j].dateOfBirth.month, tkn_user[j].dateOfBirth.year,
                            tkn[j].username, tkn[j].balance, tkn[j].status);
                }
                fclose(fileWrite);
            } else if (choice == 2) {
                system("cls");
                return;
            } else {
                system("cls");
                printf("Invalid choice!\n");
                clear_system();
            }
            return;
        }
    }

    if (!found) {
        system("cls");
        printf("Error: User ID not found!\n");
        clear_system();
        
    }
}


void listsort(struct accountInfo tkn[], struct User tkn_user[], int *n) {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file user.txt!\n");
        return;
    }


    *n = 0;

    //doc du lieu tu file txt
    while (fscanf(file, "%[^,], %[^,], %[^,], %[^,], %d-%d-%d, %[^,], %f, %s\n",
                  tkn[*n].userId, tkn_user[*n].name, tkn_user[*n].email,
                  tkn_user[*n].phone, &tkn_user[*n].dateOfBirth.day,
                  &tkn_user[*n].dateOfBirth.month, &tkn_user[*n].dateOfBirth.year,
                  tkn[*n].username, &tkn[*n].balance, tkn[*n].status) == 10) {
        (*n)++;
    }
    fclose(file);

    //check
    printf("Total accounts read from file: %d\n", *n);

    if (*n == 0) {
        printf("*** EMPTY LIST ***\n");
        return;
    }

    int choice;
    printf("\t***SORT LIST***\n");
    printf("[1] Sort by NAME\n");
    printf("[0] Back to Admin menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("\t***SORT BY NAME***\n");
        printf("[1] A -> Z\n");
        printf("[2] Z -> A\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) { //a-z
            for (int i = 0; i < *n - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < *n; j++) {
                    if (strcmp(tkn_user[j].name, tkn_user[minIndex].name) < 0) {
                        minIndex = j;
                    }
                }
                
                struct User tempUser = tkn_user[i];
                tkn_user[i] = tkn_user[minIndex];
                tkn_user[minIndex] = tempUser;

                struct accountInfo tempAcc = tkn[i];
                tkn[i] = tkn[minIndex];
                tkn[minIndex] = tempAcc;
            }
        } else if (choice == 2) { //z-a
            for (int i = 0; i < *n - 1; i++) {
                int maxIndex = i;
                for (int j = i + 1; j < *n; j++) {
                    if (strcmp(tkn_user[j].name, tkn_user[maxIndex].name) > 0) {
                        maxIndex = j;
                    }
                }
                struct User tempUser = tkn_user[i];
                tkn_user[i] = tkn_user[maxIndex];
                tkn_user[maxIndex] = tempUser;

                struct accountInfo tempAcc = tkn[i];
                tkn[i] = tkn[maxIndex];
                tkn[maxIndex] = tempAcc;
            }
        } else {
            return;
        }

        //ghi de vao file
        file = fopen("user.txt", "w");
        if (file == NULL) {
            printf("Error: Cannot open file user.txt to save!\n");
            return;
        }
        for (int i = 0; i < *n; i++) {
            fprintf(file, "%s, %s, %s, %s, %d-%d-%d, %s, %.2f, %s\n",
                    tkn[i].userId,
                    tkn_user[i].name,
                    tkn_user[i].email,
                    tkn_user[i].phone,
                    tkn_user[i].dateOfBirth.day,
                    tkn_user[i].dateOfBirth.month,
                    tkn_user[i].dateOfBirth.year,
                    tkn[i].username,
                    tkn[i].balance,
                    tkn[i].status);
        }
        fclose(file);
        printf("*** Sort successful! Data saved to file. ***\n");
    }
}
