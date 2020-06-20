/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 12, 2020, 5:08 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    double num1, num2, result;
    char op;
    printf("Enter number 1 operator number (Ex: 1 + 4):  ");
    scanf("%lf %c %lf", &num1, &op, &num2);
    switch (op) {
        case '+': result = num1 + num2;
            printf("result: %.2lf", result);
            break;
        case '-': result = num1 - num2;
            printf("result: %.2lf", result);
            break;
        case '*': result = num1 * num2;
            printf("result: %.2lf", result);
            break;
        case '/': if (num2 == 0)printf("Divide by 0");
            else {
                result = num1 / num2;
                printf("result: %.2lf", result);
            }
            break;
        default: printf("Oop is not supported");
    }
    return (EXIT_SUCCESS);
}

