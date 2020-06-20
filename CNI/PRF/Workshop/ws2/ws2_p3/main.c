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

/*
 * 
 */
int main(int argc, char** argv) {
    int s, x;
    do {
        printf("Enter value (0 to stop): ");
        scanf("%d", &x);
        if (x != 0) s += x;
    } while (x != 0);
    printf("Sum: %d",s);
    return (EXIT_SUCCESS);
}

