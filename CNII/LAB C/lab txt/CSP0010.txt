/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on May 27, 2020, 1:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*
 * 
 */
//ham nhap vao gia tri cua mang
int inputSize();
// ham nhap gia tri vao mang
void inputArray(double *arr, int n);
// ham dung de kiem tra xem dau vao do dai mang da chinh xac chua
int checkSize(int s, char c, float number);
//ham xuat gia tri cua mang 
void output(double *arr, int n);
//ham xu ly xoa cac phan tu trong mang (xoa o vi tri pos)
void removeDulicate(double *arr, int *n, int pos);
//ham xu ly tim cac phan tu trung nhau
void findDuplicate(double *arr, int *n);

int main(int argc, char** argv) {
    int n = 0;
    double arr[MAX];
    n = inputSize();
    inputArray(arr, n);
    findDuplicate(arr, &n);
    output(arr, n);
    return (EXIT_SUCCESS);
}

//ham nhap vao gia tri cua mang
int inputSize() {
    int n = 0;
    char c;
    int flag = 0;
    do {
        float temp;
        fpurge(stdin);
        printf("Please enter size of array: ");
        int s = scanf("%f%c", &temp, &c);
        if (checkSize(s, c, temp) == 1) { // dung ham checkSize de kiem tra xem nguoi dung nhap dung theo yeu cau chua
            printf("successful\n");
            n = (int) temp;
            flag = 1;
        } else {
            printf("Input wrong\n");
        }
    } while (flag == 0);
}

// ham nhap gia tri vao mang
void inputArray(double *arr, int n) {
    char c;
    printf("Input value:\n");
    for (int i = 0; i < n; i++) {
        int flag = 0;
        do {
            printf("Element[%d] = ", i);
            fpurge(stdin);
            if (scanf("%lf%c", &arr[i], &c) != 2 || c != '\n') {
                printf("Input wrong\n");
            } else {
                flag = 1;
            }
        } while (flag == 0);
    }
}

// ham dung de kiem tra xem dau vao do dai mang da chinh xac chua
int checkSize(int s, char c, float number) {
    int n;
    if (s == 2 && c == '\n' && number > 0) {
        n = (int) number;
        if (number == n) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
//ham xuat gia tri cua mang 

void output(double *arr, int n) {
    printf("values of array: ");
    for (int i = 0; i < n; i++) {
        printf("%0.1lf\t", arr[i]);
    }
}

/* ham xu ly xoa cac phan tu trong mang (xoa o vi tri pos)
 *chuc nang la ham se gan gia tri o phan tu sau vo cac phan tu truoc no
 *sau do se giam do dai cua mang xuong 1 don vi 
 */
void removeDulicate(double *arr, int *n, int pos) {
    for (int i = pos; i < *n; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

/*ham xu ly tim cac phan tu trung nhau
 * dung for va if de tim xem co phan tu trung nhau khong neu co thi goi ham removeDulicate()
 * va truyen vao cac gia tri gom mang, do sai mang, va vi tri phan tu bi trung lap (phan tu sau) 
 */
void findDuplicate(double *arr, int *n) {
    for (int i = 0; i < *n - 1; i++) {
        int temp = *n;
        for (int j = i + 1; j < *n; j++) {
            if (arr[i] == arr[j]) {
                while (arr[i] == arr[j]) {
                    removeDulicate(arr, n, j);
                }
            }
        }
    }
}
