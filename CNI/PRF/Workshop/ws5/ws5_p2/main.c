/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 24, 2020, 8:25 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int randomBall() {
    return rand() % 10 + 1;
}

int main(int argc, char** argv) {
    srand((int) time(0));
    int number, x, y, count = -1;
    do {
        printf("Enter a number (2 < x < 20)");
        scanf("%d", &number);
    } while (number < 2 || number > 20);
    printf("Ball Lottery\n");
    printf("=====================\n");
    printf("total sought: %d\n", number);
    do {
        count += 2;
        x = randomBall();
        y = randomBall();
        printf("Result of picks %d and %d: %d + %d\n", count, count + 1, x, y);
        if (x + y == number) printf("you got your total in %d picks", count + 1);
    } while (x + y != number);
    return (EXIT_SUCCESS);
}

