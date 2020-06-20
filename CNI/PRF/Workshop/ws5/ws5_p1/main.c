/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 21, 2020, 5:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int randomMinMax(int min, int max) {
    return (min + rand() % (max - min + 1));
}

int main(int argc, char** argv) {
    srand((int) time(0));
    int x, y, total, count = 1;

    do {
        printf("Enter total (total 2 - 12): ");
        scanf("%d", &total);
    } while (total < 2 || total > 12);
    printf("Total %d\n", total);
    do {
        x = randomMinMax(1, 6);
        y = randomMinMax(1, 6);
        printf("Result of throw %d:\t%d + %d\n", count, x, y);
        if(x + y == total) printf("You got your total in %d throws\n", count);
        count++;
    } while (x + y != total);
    return (EXIT_SUCCESS);
}

