/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 21, 2020, 2:56 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int prime(int n) {
    int m = sqrt(n);
    int i;
    if (n < 2) {
        return 0;
    }
    for (i = 2; i <= m; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printMinMaxDigits(int n) {
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
    printf("min: %d\nmax: %d\n", min, max);
}

int main(int argc, char** argv) {
    short choise;
    int n;
    do {
        printf("1. Process primes\n");
        printf("2. Print min, max digit in an integer\n");
        printf("3. Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choise);
        switch (choise) {
            case 1: do {
                    printf("Enter number: ");
                    scanf("%d", &n);
                } while (n < 0);
                if (prime(n) == 1) {
                    printf("It is prime\n");
                } else {
                    printf("It is not prime\n");
                }
                break;
            case 2: do {
                    printf("Enter number: ");
                    scanf("%d", &n);
                } while (n < 0);
                printMinMaxDigits(n);
                break;
            case 3: printf("bye bye");
                break;
            default: printf("Error");
        }
    } while (choise > 0 && choise < 3);
    return (EXIT_SUCCESS);
}

