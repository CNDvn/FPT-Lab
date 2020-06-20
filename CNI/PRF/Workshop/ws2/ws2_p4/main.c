/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 12, 2020, 5:28 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x, y;
    do {
        printf("Enter (0 to stop) number x = ");
        scanf("%d", &x);
        printf("Enter (0 to stop) number y = ");
        scanf("%d",&y);
        int t = x;
        x = y;
        y = t;
        printf("x = %d \ny = %d\n",x,y);
    } while (x != 0 && y != 0);
    return (EXIT_SUCCESS);
}

