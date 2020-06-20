/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 29, 2020, 8:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*
 * 
 */
void menu() {
    printf("\n\t\t ============Menu============\n");
    printf("1. Add a value\n");
    printf("2. Search a value\n");
    printf("3. Remove the first existence of a value\n");
    printf("4. Remove all existences of a value\n");
    printf("5. Print out the array\n");
    printf("6. Sort the array in ascending order\n");
    printf("7- Sort the array in descending order\n");
}
//kiem tra gia tri dau vao co phai chu khong

int checkInput(int s, char c) {
    if (s == 2 && c == '\n') {
        return 1;
    } else {
        return 0;
    }
}

//ham nhan gia tri input va dung ham checkInput() de kiem tra

int input() {
    int s;
    char c;
    int findValue;
    printf("\n=================\n");
    do {
        fpurge(stdin);
        printf("Enter a value: ");
        s = scanf("%d%c", &findValue, &c);
        s = checkInput(s, c);
        printf("=================\n");
    } while (s == 0);

    return findValue;
}
//ham them mot gia tri vao mang

void add(int *arr, int *n) {
    arr[*n] = input();
    (*n)++;
}
//ham tim kiem gia tri

void search(int *arr, int n) {
    int findValue = input();

    int checkEmpty = 0;
    for (int i = 0; i < n; i++) {
        if (findValue == arr[i]) {
            printf("\n=========================\n");
            printf(" location of %d is: %d \n", findValue, i);
            printf("=========================\n");
            checkEmpty = 1;
        }
    }

    if (checkEmpty != 1) {
        printf("\n\n=====================================\n");
        printf(" There is no value %d in the array \n", findValue);
        printf("=====================================\n\n");
    }
}
//ham xoa gia tri dau tien trong mang

void removeFirst(int *arr, int *n) {
    int findValue = input();

    int temp = 1;
    for (int i = 0; i < *n; i++) {
        if (findValue == arr[i]) {
            for (int j = i; j < *n; j++) {
                arr[j] = arr[j + 1];
            }
            temp = 0;
            (*n)--;
            break;
        }

    }
    if (temp == 1) {
        printf("The value not exist");
    }
}
//ham xoa het cac gia tri trong mang

void removeAll(int *arr, int *n) {
    int findValue = input();

    int temp = 1;
    for (int i = 0; i < *n; i++) {
        if (findValue == arr[i]) {
            for (int j = i; j < *n; j++) {
                arr[j] = arr[j + 1];
            }
            temp = 0;
            i = 0;
            (*n)--;
        }
    }

    if (temp == 1) {
        printf("The value not exist");
    }

}
//ham in cac gia tri ra ngoai mang

void printOut(int *arr, int n) {
    if (n == 0) {
        printf("\n===========================================\n");
        printf("No value in the array");
        printf("\n===========================================\n");
    } else {
        printf("\n===========================================\n");
        for (int i = 0; i < n; i++) {
            printf("%d  ", arr[i]);
        }
        printf("\n===========================================\n");
    }
}
//ham sap xep theo thu tu tang dan va in ra bang cach goi ham outPrint()

void sortAscending(int *arr, int n) {
    int arrTemp[n];

    for (int i = 0; i < n; i++) {
        arrTemp[i] = arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrTemp[j] > arrTemp[j + 1]) {
                int temp = arrTemp[j];
                arrTemp[j] = arrTemp[j + 1];
                arrTemp[j + 1] = temp;
            }
        }
    }
    printOut(arrTemp, n);
}
//ham sap xep theo thu tu giam dan va in ra bang cach goi ham outPrint()

void sortDescending(int *arr, int n) {
    int arrTemp[n];

    for (int i = 0; i < n; i++) {
        arrTemp[i] = arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrTemp[j] < arrTemp[j + 1]) {
                int temp = arrTemp[j];
                arrTemp[j] = arrTemp[j + 1];
                arrTemp[j + 1] = temp;
            }
        }
    }
    printOut(arrTemp, n);
}

int main(int argc, char** argv) {
    int arr[MAX];
    int n = 0;
    int option, s;
    char c;
    int a[] = {-7, 5, 5, 2, 2, 8, -1, 7};
    for (int i = 0; i < 8; i++) {
        arr[i] = a[i];
    }
    n = 8;
    do {
        menu();
        do {
            fpurge(stdin);
            printf("Select a option: ");
            s = scanf("%d%c", &option, &c);
            s = checkInput(s, c);
        } while (s == 0);
        switch (option) {
            case 1: add(arr, &n);
                break;
            case 2: search(arr, n);
                break;
            case 3: removeFirst(arr, &n);
                break;
            case 4: removeAll(arr, &n);
                break;
            case 5: printOut(arr, n);
                break;
            case 6: sortAscending(arr, n);
                break;
            case 7: sortDescending(arr, n);
                break;
            default: option = 0;
                printf("GoodBye!");
        }
    } while (option != 0);

    return (EXIT_SUCCESS);
}

