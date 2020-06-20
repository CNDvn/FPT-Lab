/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 12, 2020, 5:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
void operation_1();
void operation_2();

int main(int argc, char** argv) {
    int operation;
    do {
        printf("1. Quadratic equation\n"
                "2. Bank deposit problem\n"
                "3. Quit\n"
                "Choose an operation: ");
        scanf("%d", &operation);
        switch (operation) {
            case 1: operation_1();
                break;
            case 2: operation_2();
                break;
            case 3: printf("Bye bye");
                break;
        }
    } while (operation != 3);
    return (EXIT_SUCCESS);
}

void operation_1() {
    int a, b, c, dental;
    do {
        printf("Input a, b, c: (a not 0): ");
        scanf("%d %d %d", &a, &b, &c);
    } while (a == 0);
    dental = b * b - (4 * a * c);
    if (dental < 0) {
        printf("Equation is no solution\n1");
    } else if (dental == 0) {
        printf("x = %f\n", (float) ((-b) / (2 * a)));
    } else {
        printf("x1 = %f\n", (-b + sqrt(dental)) / (2 * a));
        printf("x2 = %f\n", (-b - sqrt(dental)) / (2 * a));
    }

}

void operation_2() {
    int d, n, a;
    float r;
    do {
        printf("Input your deposit: (deposit>0): ");
        scanf("%d", &d);
        printf("Input yearly rate (0 < rate < 0.1): ");
        scanf("%f", &r);
        printf("Input number of years(n > 0): ");
        scanf("%d", &n);
    } while (d < 0 || (r < 0 || r > 0.1) || n < 0);
    for(int i = 1; i <= n; i++){
        a = d*(1 + r);
    }
    printf("Amount at the %d year: %d\n", n, a);
}