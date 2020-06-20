/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 21, 2020, 12:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
/*
 * 
 */
// xoa khoang trang ben trai

char* lTrim(char s[]) {
    int i = 0;
    while (s[i] == ' ') i++;
    if (i > 0) strcpy(&s[0], &s[i]);
    return s;
}
// xoa khoang trang ben phai

char* rTrim(char s[]) {
    int i = strlen(s) - 1;
    while (s[i] == ' ') i--;
    s[i + 1] = '\0';
    return s;
}
// xoa khoang trang o giua

char* trim(char s[]) {
    lTrim(rTrim(s)); // ltrim va rtrim de xoa khoang trang trai va phai
    char *ptr = strstr(s, "  "); //cho con tro dung strstr de lay 2 khoang trang o giua
    while (ptr != NULL) { // dong while...do de de tim cac 2 khoang trang tiep theo den khi nao con tro = null thi dung
        strcpy(ptr, ptr + 1); // dung strcpy de copy chuoi moi vo con tro
        ptr = strstr(s, "  "); // tiep tuc de con tro tim 2 khoang trang ke tiep trong chuoi
    }
    return s; // tra ve chuoi mo sau khi da xoa het khoang trang
}
// kiem tra xem nguoi dung nhap dung theo dieu kien chua

int checkInput(char s[]) {
    char a[] = "@#![]{}()";
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < strlen(a); j++) {
            if (s[i] == a[j]) {
                return 0;
            }
        }
    }
    return 1;
}
//cho nguoi dung nhap chuoi vao va kiem tra dieu kien checkInput

void input(char s[]) {
    int flag = 0;
    do {
        printf("Enter a string: ");
        fpurge(stdin);
        scanf("%[^\n]", s);
        //kiem tra checkInput xem nguoi dung nhap dung chua. neu dung thi out con sai thi nhap lai
        if (checkInput(s) == 1) {
            printf("\nSuccess");
            flag = 1;
        } else {
            printf("\nOnly input character\n");
        }
    } while (flag != 1);
}
// output ket qua ra man hinh

void output(char s[]) {
    trim(s);
    printf("\nThe string after removing: %s", s);
}

int main(int argc, char** argv) {
    char flag = '\n';
    char s[MAX];
    do {
        input(s);
        output(s);
        fpurge(stdin);
        printf("\nPress Enter to continue\n");
        flag = getchar();
    } while (flag == '\n');
    return (EXIT_SUCCESS);
}

