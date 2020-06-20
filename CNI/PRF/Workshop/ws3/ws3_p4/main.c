/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 7, 2020, 11:18 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
double factorial(int n) {
    double p = 1;
    int i;
    for (i = 2; i <= n; i++) {
        p *= i;
    }
    return p;
}

int main(int argc, char** argv) {
    int n;
    do {
        printf("Enter a number (n>0): ");
        scanf("%d", &n);
    } while (n < 0);
    printf("factorial of %d! is: %lf",n,factorial(n));

    return (EXIT_SUCCESS);
}

