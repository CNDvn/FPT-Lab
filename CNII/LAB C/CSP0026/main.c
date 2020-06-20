/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 29, 2020, 12:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*
 * 
 */

int inputDecimal() {
    int d;
    char c;
    int flag = 1;
    do {
        fpurge(stdin);
        printf("Enter a positive number: ");
        if (scanf("%d%c", &d, &c) == 2 && c == '\n' && d >= 0) {
            return d;
            flag = 0;
        } else {
            printf("Please! input again\n");
        }
    } while (flag == 1);
}

void convert(int d) {
    int binary[MAX];
    int i = 0;
    do {
        binary[i] = d % 2;
        d /= 2;
        i++;
    } while (d != 0);

    output(binary, i);
}

void output(int binary[], int n) {
    printf("Binary number: ");
    for (int i = n - 1; i >= 0; i--) {
        if ((i + 1) % 4 == 0) printf(" ");
        printf("%d", binary[i]);
    }
}

int main(int argc, char** argv) {
    int decimal;
    int flag = 0;
    char c;
    do {
        printf("Convert Decimal to Binary program\n");
        decimal = inputDecimal();
        convert(decimal);
        printf("\nEnter 1 to continue\n");
        scanf("%d", &flag);
    } while (flag == 1);
    return (EXIT_SUCCESS);
}

