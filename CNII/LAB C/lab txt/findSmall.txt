/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 25, 2020, 12:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

/*
 * 
 */
void input(double arr[], int n) {
    char c;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        do {

            printf("Element[%d]", i);
            fpurge(stdin);
            if (scanf("%lf%c", &arr[i], &c) != 2 || c != '\n') {
                printf("Input wrong\n");
            } else {
                flag = 1;
            }
        } while (flag == 0);
    }
}

double small(double arr[], int n) {
    double tSmall = arr[0];
    for (int i = 0; i < n; i++) {
        if (tSmall > arr[i]) {
            tSmall = arr[i];
        }
    }
    return tSmall;
}

void output(double arr[], int n) {
    double s = small(arr, n);
    for (int i = 0; i < n; i++) {
        if (s == arr[i]) {
            printf("The smallest element: %0.1lf and Its position: %d\n", s, i);
        }
    }
}

int main(int argc, char** argv) {
    int n = 0;
    char c;
    int flag = 0;
    double arr[MAX];
    do {
        do {
            float temp;
            fpurge(stdin);
            printf("Please enter size of array: ");
            if (scanf("%f%c", &temp, &c) == 2 && c == '\n' && temp > 0) {
                n = (int) temp;
                if (temp == n) {
                    flag = 1;
                    printf("Success\n");
                } else {
                    printf("Input wrong\n");
                }
            } else {
                printf("Input Wrong\n");
            }
        } while (flag == 0);

        input(arr, n);
        output(arr, n);

    } while (n <= 0);
    return (EXIT_SUCCESS);
}

