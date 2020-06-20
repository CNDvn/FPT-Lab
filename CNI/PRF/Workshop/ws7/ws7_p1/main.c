/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on April 8, 2020, 3:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 100
#define COL 15

/*
 * 
 */
char* lTrim(char s[]);
char* rTrim(char s[]);
char* trim(char s[]);
char* nameStr(char s[]);

void add(char list[][COL], int* n); // Add one more student
void delete(char list[][COL], int *n);
void search(char list[][COL], int n);
void printTheList(char list[][15], int n); // print list student follow a - z
void menu();

int main(int argc, char** argv) {
    short operation;
    char list[ROW][COL];
    int n = 0;
    do {
        menu();
        scanf("%d", &operation);

        switch (operation) {
            case 1:if (n >= ROW) {
                    printf("The list was full");
                } else {
                    add(list, &n);
                }
                break;
            case 2: delete(list, &n);
                break;
            case 3: search(list, n);
                break;
            case 4: printTheList(list, n);
                break;
            case 5: printf("Good Bye!");
        }
    } while (operation != 5);
    return (EXIT_SUCCESS);
}

void add(char list[][COL], int* n) {
    printf("Enter student's name: ");
    fpurge(stdin);
    scanf("%[^\n]", list[*n]);
    nameStr(list[*n]);
    *n = *n + 1;
}

void delete(char list[][COL], int *n) {
    char name[COL];
    printf("What is student's name that you want to remove: ");
    fpurge(stdin);
    scanf("%[^\n]", name);
    nameStr(name);
    for (int i = 0; i < *n; i++) {
        if (strcmp(list[i], name) == 0) {
            for (int j = i; j < *n; j++) {
                strcpy(list[j], list[j + 1]);
            }
            (*n)--;
            break;
        }
    }
}

void search(char list[][COL], int n) {
    char name[COL];
    int check = 0;
    printf("Enter student's name that you want to search: ");
    fpurge(stdin);
    scanf("%[^\n]", name);
    nameStr(name);
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i], name) == 0) {
            printf("%s stay position %d\n", list[i], i);
            check = 1;
        }
    }
    if (check == 0) {
        printf("not find %s\n", name);
    }
}

void printTheList(char list[][15], int n) {
    char temp[15];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (list[i][0] < list[j][0]) {
                strcpy(temp, list[j]);
                strcpy(list[j], list[i]);
                strcpy(list[i], temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", list[i]);
    }
}

void menu() {
    printf("1. Add a student\n");
    printf("2. Remove a student\n");
    printf("3. Search a student\n");
    printf("4. Print the list in ascending order\n");
    printf("5. Quit\n");
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