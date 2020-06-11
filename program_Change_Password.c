#include <stdio.h>
#include <stdlib.h>

int login(int pass) {
    int check;
    printf("Mời nhập mật khẩu: ");
    scanf("%d", &check);
    for (int i = 0; i < 3; i++) {
        if (check != pass) {
            system("cls");
            printf("Mật khẩu sai, mời nhập lại: ");
            scanf("%d", &check);
        } else {
            system("cls");
            printf("Đăng nhập thành công\n");
            return 1;
        }
    }
    system("cls");
    printf("Đăng nhập tạm khóa");
    return 0;
}
void changePass(int* pass) {
    int check;
    printf("Nhập mật khẩu mới: ");
    scanf("%d", &check);
    int check2;
    system("cls");
    printf("Xác nhận mật khẩu mới: ");
    scanf("%d", &check2);
    if (check2 != check) {
        for (int i = 0; i < 3; i++) {
            system("cls");
            printf("Xác nhận không trùng khớp\nMời nhập lại: ");
            scanf("%d", &check2);
            if (check == check2) {
                *pass = check2;
                system("cls");
                printf("Đổi mật khẩu thành công.\nMời đăng nhập lại.\n");
                return;
            }
        }
        system("cls");
        printf("Mời đặt lại mật khẩu. ");
        changePass(pass);
    } else {
        *pass = check2;
    }
}

int main(void) {
    int pass = 123456;
    if (login(pass)) {
        changePass(&pass);
        goto loginAgain;
    } else {
        return 0;
    }
loginAgain : {
    system("cls");
    printf("Bạn đã đổi mật khẩu thành công\nMời bạn đăng nhập lại\n");
    login(pass);
    printf("\nMời thí sinh tiếp theo");
}
    return 0;
}