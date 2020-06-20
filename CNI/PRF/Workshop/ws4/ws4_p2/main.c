/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 21, 2020, 3:14 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int validDate(int day, int month, int year) {
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
    return day <= maxday;
}

void fibo(int n) {
    int t1 = 1, t2 = 1, f = 1;
    if (n == 1) {
        printf("1");
    } else if (n == 2) {
        printf("1 1");
    } else {
        printf("1 1 ");
        for (int i = 3; i <= n; i++) {
            f = t1 + t2;
            t1 = t2;
            t2 = f;
            printf("%d ", f);
        }
    }


}

int main(int argc, char** argv) {
    short choise;
    int n, day, month, year;
    do {
        printf("\n1. Fibonacci sequence\n");
        printf("2. Check a date\n");
        printf("3. Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choise);
        switch (choise) {
            case 1: do {
                    printf("Enter a number: ");
                    scanf("%d", &n);
                } while (n < 0);
                fibo(n);
                break;
            case 2: printf("Enter day month and year: ");
                scanf("%d %d %d", &day, &month, &year);
                if (validDate(day, month, year) == 1) {
                    printf("valid date\n");
                } else {
                    printf("invalid date\n");
                }
                break;
            default: printf("Error\n");
        }
    } while (choise > 0 && choise < 3);
    return (EXIT_SUCCESS);
}

