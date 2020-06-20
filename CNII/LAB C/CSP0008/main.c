/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on June 3, 2020, 7:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

/*
 * 
 */

int checkString(char* String) {
    for (int i = 0; i < strlen(String); i++) {
        if (String[i] >= '0' && String[i] <= '9')
            return 0;
    }
    return 1;
}

void inputString(char* String) {
    int flag = 1;
    int i = -1;
    do {
        fpurge(stdin);
        scanf("%[^\n]", String);
        if (checkString(String) == 1) {
            flag = 0;
        } else {
            printf("Input wrong\n");
            printf("Please input again: ");
        }
    } while (flag == 1);
}

void input(char* String) {
    printf("Enter a string: ");
    //inputString(String);
    scanf("%[^\n]",String);
}

void process(char* String) {
    char characters[MAX];
    int flag = 0;
    int k = 0;
    char str[MAX];
    strcpy(str, String);
    strupr(str);

    for (int i = 0; i < strlen(str); i++) {
        flag = 0;
        for (int j = 0; j < strlen(str); j++) {
            if (i == j) continue;
            if (str[i] == str[j])
                flag = 1;
        }
        if (flag == 0) {
            characters[k] = String[i];
            k++;
        }
    }
//    printf("%d\n",k);
//    printf("%zd\n", strlen(characters));
    for (int i = 0; i < k; i++) {   //phai de i < k chu neu de i < strlen(characters) thi no se in thua gia tri (co le do loi cap phat bo nho)
        printf("%c\t", characters[i]);
    }
}

int main(int argc, char** argv) {
    char* str1 = "Hotmail Login was made by Microsoft and its essential concentration is to enable you to hold every one of your messages and access them easily at whatever point and anyway you need.";
    char* str2 = "VBA stands for Visual Basic for Applications, an event-driven programming language from Microsoft";
    char* str3 = "based on my understanding";
    char String[MAX];
    input(String);
    process(String);
    return (EXIT_SUCCESS);
}

