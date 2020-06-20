/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 14, 2020, 2:39 AM
 */

#include <stdio.h>
#include <stdlib.h>

     /*
 * 
 */double fibo(int n) {
    int t1 = 1, t2 = 1, f = 1;
    for (int i = 3; i <= n; i++) {
        f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    return f;
}

int main(int argc, char** argv) {
    int n;
    do {
        printf("Enter a number (n>1): ");
        scanf("%d", &n);
    } while (n < 1);
        printf("Fibo: %.0lf",fibo(n));
    return (EXIT_SUCCESS);
}

