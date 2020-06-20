/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 14, 2020, 2:48 AM
 */

#include <stdio.h>
#include <stdlib.h>

     /*
 * 
 */int isFibonacci(int n) {
    int t1 = 1, t2 = 1, f = 1;
    while (f < n) {
        f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    return f == n;
}

int main(int argc, char** argv) {
    int n;
    do {
        printf("Enter a number (n>0): ");
        scanf("%d", &n);
    } while (n < 1);
    if (isFibonacci(n) == 1) {
        printf("%d is Fibonacci", n);
    } else {
        printf("%d is\'n Fibonacci ");
    }
    return (EXIT_SUCCESS);
}

