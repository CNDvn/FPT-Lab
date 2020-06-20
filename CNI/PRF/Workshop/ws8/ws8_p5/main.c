/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on April 11, 2020, 9:57 PM
 */

#include <stdio.h>

void processFile(char *fname, int*pCount, double*pSum) {
    FILE* f = fopen(fname, "r");
    *pCount = 0;
    *pSum = 0;
    double x;
    while (fscanf(f, "%lf", &x) == 1) {
        (*pCount)++;
        (*pSum) += x;
    }
    fclose(f);
}

int main() {
    char infName[] = "array3.txt";
    int count = 0;
    double sum = 0;
    processFile(infName, &count, &sum);
    printf("Number of values in the file: %d\n", count);
    printf("Average of values in the file: %lf\n", sum / count);
    getchar();
    return 0;
}


