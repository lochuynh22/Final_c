//trien khai ham da khai bao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/datatype.h"

//login admin
void login_admin(){
    char username[20], password[20];
    while(1){
        printf("Enter username: ");
        fgets(username,sizeof(username),stdin);
        username[strcspn(username,"\n")] = '\0';
        printf("Enter password: ");
        fgets(password, sizeof(password),stdin);
        password[strcspn(password,"\n")]='\0';
    }
}
//kt dang nhap
// int check_login(char *username, char *password){
//     File *f;

// }

//doc ki tu xuong dong
void clear_buffer() {
    int c;
    while ((c= getchar()) !='\n'&&c != EOF);
}
//xoa man hinh console 
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
int is_duplicate(const char *id, const char *email, const char *phone, const char *username, const char *filename) {
FILE *file = fopen(filename, "rb");
if (!file) return 0;  //neu o co file ko trung

struct accountInfo tempAccount;
struct User tempUser;

while (fread(&tempAccount, sizeof(struct accountInfo), 1, file) &&
fread(&tempUser, sizeof(struct User), 1, file)) {
if (id && strcmp(tempAccount.userId, id) == 0) {
fclose(file);
return 1;
}
    if (email && strcmp(tempUser.email, email) == 0) {
    fclose(file);
return 1;
}
    if (phone && strcmp(tempUser.phone, phone) == 0) {
    fclose(file);
return 1;
}
    if (username && strcmp(tempAccount.username, username) == 0) {
    fclose(file);
return 1;
}
}
fclose(file);
return 0;
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


void addUser(struct accountInfo tkn[], struct User tkn_user[], int *n) {
    FILE *file = fopen("user.bin", "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n\t*** Add a New User ***\n");
    strcpy(tkn[*n].status, "LOCK");

    int len;

    //id
    do {
        printf("Enter the ID (10-20 characters): ");
        fgets(tkn[*n].userId, sizeof(tkn[*n].userId), stdin);
        tkn[*n].userId[strcspn(tkn[*n].userId, "\n")] = '\0';

        len = strlen(tkn[*n].userId);
        if (len < 10 || len > 20) {
            printf("Error: ID must be between 10-20 characters!\n");
            continue;
        }
        if (is_duplicate(tkn[*n].userId, NULL, NULL, NULL, "user.bin")) {
            printf("Error: Duplicate ID!!!\n");
            continue;
        }
        break;
    } while (1);

    //full name
    do {
        printf("Enter full name: ");
        fgets(tkn_user[*n].name, sizeof(tkn_user[*n].name), stdin);
        tkn_user[*n].name[strcspn(tkn_user[*n].name, "\n")] = '\0';
        len = strlen(tkn_user[*n].name);
    } while (len < 5 || len > 25);

    //email
    do {
        printf("Enter email: ");
        fgets(tkn_user[*n].email, sizeof(tkn_user[*n].email), stdin);
        tkn_user[*n].email[strcspn(tkn_user[*n].email, "\n")] = '\0';
        len = strlen(tkn_user[*n].email);
        if (len < 10 || len > 30) {
            printf("Error: Email must be between 10-30 characters!\n");
            continue;
        }
        if (is_duplicate(NULL, tkn_user[*n].email, NULL, NULL, "user.bin")) {
            printf("Error: Duplicate email!!!\n");
            continue;
        }
        break;
    } while (1);

    //phone
    do {
        printf("Enter phone number: ");
        fgets(tkn_user[*n].phone, sizeof(tkn_user[*n].phone), stdin);
        tkn_user[*n].phone[strcspn(tkn_user[*n].phone, "\n")] = '\0';
        len = strlen(tkn_user[*n].phone);
        if (len < 5 || len > 15) {
            printf("Error: Phone number must be between 5-15 characters!\n");
            continue;
        }
        if (is_duplicate(NULL, NULL, tkn_user[*n].phone, NULL, "user.bin")) {
            printf("Error: Duplicate phone number!!!\n");
            continue;
        }
        break;
    } while (1);

    //ngay sinh 
    printf("Enter Date of Birth:\n");
    printf("\tEnter the Day: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.day);
    getchar(); 
    printf("\tEnter the Month: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.month);
    getchar(); 
    printf("\tEnter the Year: ");
    scanf("%d", &tkn_user[*n].dateOfBirth.year);
    getchar(); 

    //username
    do {
        printf("Enter username: ");
        fgets(tkn[*n].username, sizeof(tkn[*n].username), stdin);
        tkn[*n].username[strcspn(tkn[*n].username, "\n")] = '\0';
        len = strlen(tkn[*n].username);
        if (len < 5 || len > 15) {
            printf("Error: Username must be between 5-15 characters!\n");
            continue;
        }
        if (is_duplicate(NULL, NULL, NULL, tkn[*n].username, "user.bin")) {
            printf("Error: Duplicate username!!!\n");
            continue;
        }
        break;
    } while (1);

    //so du
    do {
        printf("Enter the balance: ");
        scanf("%f", &tkn[*n].balance);
        getchar();  
        if (tkn[*n].balance < 0) {
            printf("Error: Balance cannot be negative!\n");
        }
    } while (tkn[*n].balance < 0);

    //ghi de du lieu vao file
    fwrite(&tkn[*n], sizeof(struct accountInfo), 1, file);
    fwrite(&tkn_user[*n], sizeof(struct User), 1, file);

    fclose(file);
    (*n)++;
    
    printf("\nUser added successfully!\n");
}

void displaylistuser(struct accountInfo tkn[], struct User tkn_user[], int *n) {
    FILE *file = fopen("user.bin", "rb"); // mở tệp để đọc
    if (file == NULL) {
        printf("Error: Cannot open file user.bin\n");
        return;
    }
    if (*n == 0) {
        printf("*** EMPTY LIST ***\n");
        printf("Press (1) to go back: ");
        int choice_1;
        scanf("%d",&choice_1);
        getchar();
        system("cls");
        return; 
    }

    int choice;

    printf("+======================+======================+==============================+====================+============+\n");
    printf("|        ID            |        Name          |            Email             |       Phone        |   Status   |\n");
    printf("+======================+======================+==============================+====================+============+\n");

    *n = 0;

    // Đọc dữ liệu từ tệp và xử lý
    while (fread(&tkn[*n], sizeof(struct accountInfo), 1, file) == 1 &&
           fread(&tkn_user[*n], sizeof(struct User), 1, file) == 1) {
        printf("| %-20s | %-20s | %-28s | %-18s | %-10s |\n",
               tkn[*n].userId, tkn_user[*n].name, tkn_user[*n].email, tkn_user[*n].phone, tkn[*n].status);
        printf("+======================+======================+==============================+====================+============+\n");
        
        (*n)++; 
    }

    fclose(file);

    printf("Pree (1) back: ");
    scanf("%d", &choice);
    system("cls");

    if (choice == 1) {
        return;
    }
}

void finduser(struct accountInfo tkn[], struct User tkn_user[], int *n) {
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Error: Cannot open file user.bin!\n");
        return;
    }
    *n=0;
    while  (fread(&tkn[*n], sizeof(struct accountInfo), 1, file) == 1 &&
            fread(&tkn_user[*n], sizeof(struct User), 1, file) == 1) {
 (*n)++;
}
    fclose(file);

    if (*n == 0) {
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
            for (int i =0; i <*n;i++) {
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
            for (int i = 0; i < *n; i++) {
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

void lockUnlockUser(struct accountInfo tkn[],struct User tkn_user[], int *n) {
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Error: Cannot open file user.bin!\n");
        return;
    }
    *n=0;
    while (fread(&tkn[*n], sizeof(struct accountInfo), 1, file) == 1 &&
    fread(&tkn_user[*n], sizeof(struct User), 1, file) == 1) {
 (*n)++;
}
    fclose(file);

    if (*n == 0) {
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
    for (int i = 0; i<*n;i++) {
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
                FILE *fileWrite = fopen("user.bin", "wb");
                if (fileWrite == NULL) {
                    printf("Error: Cannot open file user.bin for writing!\n");
                    return;
                }

                for (int j = 0; j < *n; j++) {
                    fwrite(&tkn[j], sizeof(struct accountInfo), 1, fileWrite);
                    fwrite(&tkn_user[j], sizeof(struct User), 1, fileWrite);
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
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("Error: Cannot open file user.bin!\n");
        return;
    }

    *n = 0;

    //doc du lieu tu file txt
    while (fread(&tkn[*n], sizeof(struct accountInfo), 1, file) == 1 &&
           fread(&tkn_user[*n], sizeof(struct User), 1, file) == 1) {
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
                system("cls");
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
                system("cls");
            }
        } else {
            return;
        }

        //ghi de vao file
        file = fopen("user.bin", "wb");
        if (file == NULL) {
            printf("Error: Cannot open file user.bin to save!\n");
            return;
        }
        for (int i = 0; i < *n; i++) {
            fwrite(&tkn[i], sizeof(struct accountInfo), 1, file);
            fwrite(&tkn_user[i], sizeof(struct User), 1, file);
        }
        fclose(file);
        printf("*** Sort successful! ***\n");
    }
}
