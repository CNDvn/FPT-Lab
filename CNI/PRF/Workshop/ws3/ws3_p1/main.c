/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 3, 2020, 7:48 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int prime(int n) {
    int m = sqrt(n);
    int i;
    if (n < 2) {
        return 0;
    }
    for (i = 2; i <= m; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    int n;

    do {
        printf("nhap vao so n: ");
        scanf("%d", &n);
    } while (n < 2);

    for (int i = 2; i <= n; i++) {
        if(prime(i) == 1){
            printf("%i la so nguyen to \n", i);
        }
    }
    return (EXIT_SUCCESS);
}

