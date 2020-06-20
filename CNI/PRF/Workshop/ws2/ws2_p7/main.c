/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 13, 2020, 9:04 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char c1, c2, c, t;
    int d;
    printf("enter 2 character: ");
    scanf("%c %c", &c1, &c2);
    if (c1 > c2) {
        t = c1;
        c1 = c2;
        c2 = t;
    }
    d = c2 - c1;
    printf("%d", d);
    for (c = c1; c <= c2; c++) {
        printf("%c: %d, %o, %X\n", c, c, c, c);
    }
    return (EXIT_SUCCESS);
}

