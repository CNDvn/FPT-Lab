/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 18, 2020, 6:51 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */int sumDigits(int n){
         int sum = 0;
         do{
             int remainder = n %10;
             n /= 10;
             sum += remainder;
         }while(n>0);
         return sum;
     }
int main(int argc, char** argv) {
    int n;
    do{
        printf("Enter the number: ");
        scanf("%d",&n);
        if(n >= 0){
            printf("%d \n",sumDigits(n));
        }
    }while(n >= 0);
    
    return (EXIT_SUCCESS);
}

