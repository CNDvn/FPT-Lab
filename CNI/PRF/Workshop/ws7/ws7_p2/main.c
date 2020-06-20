/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on April 10, 2020, 2:33 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
/*
 * 
 */
char* lTrim(char s[]);
char* rTrim(char s[]);
char* trim(char s[]);
char* nameStr(char s[]);

void printList(char code[][9], char name[][21], double salary[], int n);
void delete(char code[][9], char name[][21], double salary[], int* n);
void search(char code[][9], char name[][21], double salary[], int n);
void add(char code[][9], char name[][21], double salary[], int* n);
void menu();

int main(int argc, char** argv) {
    char code[MAX][9], name[MAX][21];
    double salary[MAX];
    int choise, n = 0;
    do {
        menu();
        scanf("%d", &choise);

        switch (choise) {
            case 1: if (n >= MAX) {
                    printf("Full employee\n");
                } else {
                    add(code, name, salary, &n);
                }
                break;
            case 2: search(code, name, salary, n);
                break;
            case 3:delete(code, name, salary, &n);
                break;
            case 4: printList(code, name, salary, n);
                break;
            case 5:printf("Have a good day!");
        }
    } while (choise != 5);
    return (EXIT_SUCCESS);
}

void menu() {
    printf("================= MANAGER =================\n");
    printf("1. Adding a new employee\n");
    printf("2. Find data about employee\n");
    printf("3. Remove an employee\n");
    printf("4. Print the list employee\n");
    printf("5. Quit\n");
    printf("=========================================\n");
    printf("select your option: ");
}

void add(char code[][9], char name[][21], double salary[], int* n) {
    printf("================ ADD ===================\n");
    printf("Enter ID for employee: ");
    fpurge(stdin);
    scanf("%8s", code[*n]);
    printf("Enter name of employee: ");
    fpurge(stdin);
    scanf("%20[^\n]", name[*n]);
    nameStr(name[*n]);
    printf("Enter salary for employee: ");
    fpurge(stdin);
    scanf("%lf", &salary[*n]);
    printf("=========================================\n");
    (*n)++;
}

void search(char code[][9], char name[][21], double salary[], int n) {
    char sName[21];
    int temp = 0;
    printf("Enter employee's name: ");
    fpurge(stdin);
    scanf("%20[^\n]", sName);
    nameStr(sName);
    for (int i = 0; i < n; i++) {
        if (strcmp(name[i], sName) == 0) {
            temp = 1;
            printf("================ Information ==========\n");
            printf("ID: \t\t%s\n", code[i]);
            printf("Name: \t\t%s\n", name[i]);
            printf("Salary: \t%0.1lf\n", salary[i]);
            printf("========================================\n");
        }
    }

    if (temp == 0) {
        printf("%s not find\n", sName);
    }
}

void delete(char code[][9], char name[][21], double salary[], int* n) {
    char id[9];
    printf("Enter ID of employee: ");
    fpurge(stdin);
    scanf("%8[^\n]", id);
    for (int i = 0; i < *n; i++) {
        if (strcmp(code[i], id) == 0) {
            for (int j = i; j < *n; j++) {
                strcpy(code[j], code[j + 1]);
                strcpy(name[j], name[j + 1]);
                salary[j] = salary[j + 1];
            }
            (*n)--;
            break;
        }
    }
}

void printList(char code[][9], char name[][21], double salary[], int n) {
    char pCode[MAX][9], pName[MAX][21];
    double pSalary[MAX];
    char sCode[9], sName[21];
    double sSalary;

    for (int i = 0; i < n; i++) {
        strcpy(pCode[i], code[i]);
        strcpy(pName[i], name[i]);
        pSalary[i] = salary[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pSalary[i] > pSalary[j]) {
                sSalary = pSalary[j];
                strcpy(sCode, pCode[j]);
                strcpy(sName, pName[j]);

                pSalary[j] = pSalary[i];
                strcpy(pCode[j], pCode[i]);
                strcpy(pName[j], pName[i]);

                pSalary[i] = sSalary;
                strcpy(pCode[i], sCode);
                strcpy(pName[i], sName);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("================ Information ============\n");
        printf("ID: \t\t%s\n", pCode[i]);
        printf("Name: \t\t%s\n", pName[i]);
        printf("Salary: \t%0.1lf\n", pSalary[i]);
        printf("=========================================\n");
    }
}

char* lTrim(char s[]) {
    int i = 0;
    while (s[i] == ' ') i++;
    if (i > 0) strcpy(&s[0], &s[i]);
    return s;
}

char* rTrim(char s[]) {
    int i = strlen(s) - 1;
    while (s[i] == ' ') i--;
    s[i + 1] = '\0';
    return s;
}

char* trim(char s[]) {
    rTrim(lTrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL) {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, "  ");
    }
    return s;
}

char* nameStr(char s[]) {
    trim(s);
    strlwr(s);
    int L = strlen(s);
    int i;
    for (i = 0; i < L; i++) {
        if (i == 0 || (i > 0 && s[i - 1] == ' ')) s[i] = toupper(s[i]);
    }
    return s;
}


