#include <stdio.h>

int main() {
    FILE *file = fopen("D:\\Rikkei\\Final_C\\c\\src\\tk.bin", "wb"); 
    if (file == NULL) {
        printf("0");
        return;
    }

    char username[] = "admin123";
    char password[] = "123456";

    fwrite(username, sizeof(char), strlen(username) + 1, file); //  username
    fwrite(password, sizeof(char), strlen(password) + 1, file); // password

    fclose(file);
    printf("1");
}