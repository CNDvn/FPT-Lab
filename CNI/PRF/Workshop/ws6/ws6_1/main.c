/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on April 2, 2020, 1:32 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int numberISBN(int n);

int main(int argc, char** argv) {
    long n;
    short check;
    char c;
    do {
        do {
            printf("ISBN Validator ============== ISBN (0 to quit):");
            printf("\nEnter a number: ");
            fpurge(stdin);
            check = scanf("%ld%c", &n, &c);
            if (check != 2 || c != '\n') {
                printf("not enter character\n");
            }
        } while (check != 2 || c != '\n' || n < 0 || n > 10000000000);

        if (n != 0) {
            (numberISBN(n) == 1) ? printf("Valid\n") : printf("Invalid\n");
        }
    } while (n != 0);
    return 0;
}

int numberISBN(int n) {
    int arr[10];
    int t = 0;
    int count = 10, result = 0;
    for (int i = 9; i >= 0; i--) {
        arr[i] = n % 10;
        n /= 10;
    }

    for (int i = 0; i <= 8; i++) {
        t += arr[i] * count;
        count--;

    }
    t += arr[9];
    if (t % 11 == 0) result = 1;
    return result;
}

