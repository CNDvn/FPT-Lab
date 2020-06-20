/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 18, 2020, 7:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

     /*
 * 
 */double makeDouble(int ipart, int fraction) {
    double d_f = fraction;
    while (d_f >= 1) d_f = d_f / 10;
    if (ipart < 0) {
        return ipart - d_f;
    }
    return ipart + d_f;
}

int main(int argc, char** argv) {
    int ipart, fraction;
    printf("Enter ipart: ");
    scanf("%d", &ipart);

    do {
        printf("Enter fraction: ");
        scanf("%d", &fraction);
    } while (fraction < 0);

    printf("%lf", makeDouble(ipart, fraction));
    return (EXIT_SUCCESS);
}

