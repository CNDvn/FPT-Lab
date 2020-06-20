/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 3, 2020, 8:43 AM
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

int main(int argc, char** argv) {
    int day, month, year;
    printf("Enter day month and year: ");
    scanf("%d %d %d", &day, &month, &year);
    if (validDate(day, month, year) == 1) {
        printf("valid date");
    } else {
        printf("invalid date");
    }
    return (EXIT_SUCCESS);
}

