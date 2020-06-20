/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 18, 2020, 10:03 AM
 */

#include <stdio.h>
#include <stdlib.h>

     /*
 * 
 */void printMinMaxDigits(int n) {
    int digit;
    int min, max;
    digit = n % 10;
    n /= 10;
    min = max = digit;
    while (n > 0) {
        digit = n % 10;
        n /= 10;
        if (min > digit) min = digit;
        if (max < digit) max = digit;
    }
    printf("min: %d\nmax: %d", min, max);
}

int main(int argc, char** argv) {
    int n;
    do {
        printf("Enter the number: ");
        scanf("%d", &n);
        printMinMaxDigits(n);
    } while (n < 0);
    return (EXIT_SUCCESS);
}

