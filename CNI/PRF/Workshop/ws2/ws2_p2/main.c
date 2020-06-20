/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 16, 2020, 10:17 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int dependents, income, incomeTax;
    int pa = 9000000;
    int pd = 3600000;
    int tf;
    int ti;
    printf("Enter your income: ");
    scanf("%d", &income);
    printf("How many dependent: ");
    scanf("%d", &dependents);

    tf = 12 * (pa + dependents * pd); // tính tax-free income
    ti = income - tf; // tính tax income

    //Tính income tax của người thu nhập
    if (ti <= 0) {
        ti = 0;
    } else {
        if (ti > 18000000) {
            incomeTax = 1950000 + (ti - 18000000)*0.2;
        } else if (ti > 10000000) {
            incomeTax = 750000 + (ti - 10000000)*0.15;
        } else if (ti > 5000000) {
            incomeTax = 250000 + (ti - 5000000)*0.1;
        } else if (ti < 5000000) {
            incomeTax = ti * 0.05;
        }
    }

    //in kết quả
    printf("Your income of this year: %d \n", income);
    printf("Number of dependent: %d \n", dependents);
    printf("Tax-free income: %d \n", tf);
    printf("Taxable income: %d \n", ti);
    printf("Income tax: %d \n", incomeTax);

    return (EXIT_SUCCESS);
}

