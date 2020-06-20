/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on April 2, 2020, 5:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
 * 
 */
void addValue(int arr[MAX], int* n);
int searchValue(int arr[MAX], int n);
void printOutArr(int arr[MAX], int n);
void printOutValue(int arr[MAX], int n);
void printOutSortArr(int arr[MAX], int n);

int main(int argc, char** argv) {
    int arr[MAX], n = 0;
    int operation;
    
    do {
        printf("0. Quit\n"
                "1. Add a value\n"
                "2. Search a value\n"
                "3. Print out the array\n"
                "4. Print out values in a range\n"
                "5.Print out the array in ascending order\n");
        printf("Select option: ");
        scanf("%d", &operation);
        switch (operation) {
            case 1: addValue(arr, &n);
                break;
            case 2: (searchValue(arr, n) == 1) ? printf("The value is exist\n"):printf("The value is not exist\n");
                break;
            case 3: printOutArr(arr, n);
                break;
            case 4:printOutValue(arr, n);
                break;
            case 5: printOutSortArr(arr, n);
                break;
            default:    printf("Have a Nice Day!");
        }
    } while (operation >= 1 && operation <= 5);
    return (EXIT_SUCCESS);
}

void addValue(int arr[MAX], int* n) {
    printf("Enter a value: ");
    scanf("%d", &arr[*n]);
    *n += 1;
}

int searchValue(int arr[MAX], int n) {
    int check;
    printf("Enter value you want to find: ");
    scanf("%d", &check);
    for (int i = 0; i < n; i++) {
        if (arr[i] == check)
            return 1;
    }
    return 0;
}

void printOutArr(int arr[MAX], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printOutValue(int arr[MAX], int n) {
    int min, max;
    int arr2[MAX];
    int count = 0;
    printf("Enter value min: ");
    scanf("%d", &min);
    printf("Enter value max: ");
    scanf("%d", &max);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= min && arr[i] <= max) {
            arr2[count] = arr[i];
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}

void printOutSortArr(int arr[MAX], int n) {
    int arr2[MAX];
    int temp;
    // Copy value from arr to arr2
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }
    //sort arr2 ascending
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr2[i] < arr2[j]) {
                temp = arr2[j];
                arr2[j] = arr2[i];
                arr2[i] = temp;
            }
        }
    }
    //print out arr2
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}