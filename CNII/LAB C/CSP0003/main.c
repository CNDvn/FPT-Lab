/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on June 3, 2020, 1:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
 * 
 */
// kiem tra xem co phai la so khong hay co ki tu ben trong

int checkNumber(int number, char c) {
    if (number == 2 && c == '\n')
        return 1;
    return 0;
}
// kiem tra xem co phai la chuoi khong hay co so lan ben trong

int checkString(char* String) {
    for (int i = 0; i < strlen(String); i++) {
        if (String[i] >= '0' && String[i] <= '9')
            return 0;
    }
    return 1;
}
//ham nhap cac so nguyen va dung checkNumber de kiem tra

void inputNumber(int* number) {
    char c;
    int s;
    int flag = 1;
    do {
        fpurge(stdin);
        s = scanf("%d%c", number, &c);
        s = checkNumber(s, c);
        if (s == 1) {
            flag = 0;
        } else {
            printf("Input wrong\n");
            printf("Please input again: ");
        }
    } while (flag == 1);
}
//ham nhap vao chuoi va dung checkString de kiem tra xem chuoi do co so gi khong

void inputString(char* String) {
    int flag = 1;
    do {
        fpurge(stdin);
        scanf("%[^\n]", String);
        if (checkString(String) == 1) {
            flag = 0;
        } else {
            printf("Input wrong\n");
            printf("Please input again: ");
        }
    } while (flag == 1);
}
/*------------------------------------------------------------------------------*/

//ham out ra cac gia tri trong mang

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
//ham nhap vao chieu dai mang

void inputLengthOfArray(int* size) {
    do {
        printf("Please enter size of array: ");
        inputNumber(size);
    } while (size <= 0);
}
//ham nhap gia tri vao mang

void inputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element [%d]", i);
        inputNumber(&arr[i]);
    }
}

//ham sap xep gia tri tang dan trong mang

void sortAscending(int* arr, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printArray(arr, size);
}

void addNewValue(int* arr, int* size) {
    printf("Enter new value: ");
    inputNumber(&arr[*size]);
    (*size)++;

    printf("New array: \n");
    sortAscending(arr, *size);
}

int main(int argc, char** argv) {
    int arr[MAX];
    int sizeOfArray;
    inputLengthOfArray(&sizeOfArray);
    inputArray(arr, sizeOfArray);
    sortAscending(arr, sizeOfArray);

    addNewValue(arr, &sizeOfArray);
    return (EXIT_SUCCESS);
}

