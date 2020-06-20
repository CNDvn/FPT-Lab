/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 18, 2020, 9:41 AM
 */

#include <stdio.h>
#include <stdlib.h>

     /*
 * 
 */int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
     return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(int argc, char** argv) {
    int a, b;
    do {
        printf("Enter a and b: ");
        scanf("%d %d", &a, &b);
    } while (a <= 0 || b <= 0);
    printf("gcd: %d\n", gcd(a, b));
    printf("lcm: %d", lcm(a, b));
    return (EXIT_SUCCESS);
}

