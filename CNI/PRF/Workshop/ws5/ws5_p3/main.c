/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 23, 2020, 9:41 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void validDate(int day, int month, int year) {
    int maxday = 31;
    if (day < 1 || day > 31 || month < 1 || month > 12) return 0;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxday = 30;
    } else if (month == 2) {
        if (year % 400 == 0 || year % 4 == 0 & year % 100 != 0) {
            maxday = 29;
        } else {
            maxday = 28;
        }
    }
    if (day <= maxday) {
        printf("this date is valid\n");
    } else {
        printf("this date is not valid\n");
    }
}

void characterData() {
    char a, b;
    printf("Enter two characters: ");
    fpurge(stdin);
    scanf("%c %c", &a, &b);
    if (a > b) {
        char temp = a;
        a = b;
        b = temp;
    }

    for (char code = a; code <= b; code++) {
        printf("%c: %d:, %xh\n", code, code, code, code);
    }
}

int main(int argc, char** argv) {
    short choise;
    int day, month, year;
    do {
        printf("1. Processing date data\n");
        printf("2. Character data\n");
        printf("3. Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choise);
        switch (choise) {
            case 1: printf("Enter day, month and year: ");
                scanf("%d %d %d", &day, &month, &year);
                validDate(day, month, year);
                break;
            case 2: characterData();
                break;
            case 3: printf("bye bye");
                break;
        }
    } while (choise != 3);
    return (EXIT_SUCCESS);
}

