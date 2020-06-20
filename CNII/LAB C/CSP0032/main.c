/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 20, 2020, 12:54 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void input(int* a){
    char c;
    int flag = 1;
    do{
    fpurge(stdin);
    printf("\nEnter an integer n= ");
      if (scanf("%d%c", &*a, &c) != 2 || c != '\n') {
        printf("Only input number");
    } else {
        printf("\nSuccess");
        flag = 2;
    }
    }while(flag == 1);
}
int sumOfDigit(int a) {
    int flag = 1, sum = 0;
    do{
        if (a / 10 != 0) {
            sum += a%10;
            a /= 10;
        }else{
            flag = 2;
            sum += a;
        }
    }while (flag == 1);
    if(sum < 0){
        sum = sum * (-1);
    }
    return sum;
}
void output(int a){
    printf("\nSum digit = %d", sumOfDigit(a));
}
int main(int argc, char** argv) {
    int a = 0;
    int flag = 2;

    printf("Sum Digit Program");
    do{
        input(&a);
        output(a);
        printf("\nPress 1 to exist");
        scanf("%d", &flag);
    }while(flag != 1);
    return (EXIT_SUCCESS);
}

