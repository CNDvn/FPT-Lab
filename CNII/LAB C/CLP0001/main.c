/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on June 3, 2020, 12:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define MAX_FILE 349900

/*
 * 
 */
//cac ham goi y 
//xem no co phai substring khong. Tra ve 1 neu phai va 0 neu khong phai

int substring(char shortstr[], char longstr[]) {
    char* ptr = strstr(longstr, shortstr);
    if (ptr == NULL) {
        return 0;
    } else {
        return 1;
    }
}
//xem no co phai subsequence khong, tra ve 1 neu phai va 0 neu khong phai

int subsequence(char shortstr[], char longstr[]) {
    char strs[MAX];
    char strl[MAX];
    strcpy(strs,shortstr);
    strcpy(strl,longstr);
    
    int s = strlen(strs);
    int l = strlen(strl);
    if(l<s){
        char a[MAX];
        strcpy(a,strl);
        strcpy(strl,strs);
        strcpy(strs,a);
    }
    
    int j = -1;
    int temp = 0;
    int i;
    int lenLongstr = strlen(strl);
    for (i = 0; i < strlen(strs); i++) {
        while (j < lenLongstr) {
            j++;
            if (strs[i] == strl[j]) {
                temp++;
                break;
            }
        }
    }

    if (strlen(strs) == temp) {
        return 1;
    } else {
        return 0;
    }
    
    
}
//xem no co phai permutation cua nhau khong. Tra ve 1 neu phai va 0 neu  khong phai

void delete(char* str, int n, int* k){
    for(int i = n; i < strlen(str)-1; i++){
        str[i] = str[i+1];
    }
    (*k)--;
}

int permutation(char string1[], char string2[]) {
    int n = strlen(string1);
    int k = n;
    char s[MAX];
    strcpy(s, string2);
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < k; j++) {
            if (string1[i] == s[j]) {
                delete(s,j,&k);
                flag = 1;
            }
        }
        if (flag == 0)
            return 0;
    }
    return 1;
}
//xem no co matchscore khong, neu co tra ve 1 va 0 neu khong co

int matchscore(char string1[], char string2[]) {
    int temp = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != string2[i])
            temp++; // temp dang am chi so lan ma o vi tri do no khong nhu nhau
    }
    if (temp >= 3)
        return 0;
    return 1;
}
//ham kiem tra xem file co ton tai hay khong

int checkExist(char* file) {
    FILE* f = fopen(file, "r");
    if (f == NULL) {
        return 0;
    } else {
        return 1;
    }
}
//ham kiem tra xem tu can tra co ton tai hay khong

/*
 * bang cach tao 1 mang 1 chieu kieu char dung mang nay de doc 1 chuoi o 1 dong trong file
 * sau do mo file de doc 
 * roi dung do while de doc het file
 * vua doc vua kiem tra neu co thi return 1 con khong thi thoi 
 * cu lap nhu vay cho den het ma khong co thi return ve 1
 */
int findWord(char* word) {
    char dic[MAX];
    int temp = 0;
    FILE *f = fopen("dictionary.txt", "r");
    do {
        temp++;
        fscanf(f, "%s", dic);
        if (strcmp(word, dic) == 0)
            return 1;
    } while (temp < MAX_FILE);
    fclose(f);
    return 0;
}
//ham kiem tra xem co tu de recommend cho nguoi dung khong

int checkRecommend(char* word) {
    char dic[MAX];
    int temp = 0;
    FILE *f = fopen("dictionary.txt", "r");
    int lWord = strlen(word);
    do {
        temp++;
        fscanf(f, "%s", dic);
        int lDic = strlen(dic);
        int deviant = lDic - lWord;

                if (lWord < lDic && deviant == 1) {
                    if (subsequence(word, dic) || substring(word, dic)) {
                        return 1;
                    }
                } else if (lWord == lDic) {
                    if (permutation(word, dic) || matchscore(word, dic)) {
                        return 1;
                    }
                }
    } while (temp < MAX_FILE);
    return 0;
    fclose(f);
}
//Ham goi y nguoi dung 1 so tu co the la chinh tu ho can tim

/*
 * dua vao thuat toan nhu ham findWord() de doc chuoi 1 dong trong file 
 * roi mang di thuc hien cac thuat toan goi y 
 */
void recommend(char* word) {
    int sll = 0;
    char dic[MAX];
    int temp = 0;
    FILE *f = fopen("dictionary.txt", "r");
    int lWord = strlen(word);
    do {
        temp++;
        fscanf(f, "%s", dic);
        int lDic = strlen(dic);        
        int deviant = lDic - lWord;
        if(deviant < 0){
            deviant = lWord - lDic;
        }

        if (deviant == 1) {
            if (subsequence(word, dic) || substring(word, dic)) {
                printf("%s\n", dic);
                sll++;
            }
        } else if (lWord == lDic || lDic < lWord) {
            if (permutation(word, dic) || matchscore(word, dic)) {
                printf("%s\n", dic);
                sll++;
            }
        }

    } while (temp < MAX_FILE);
    fclose(f);
    printf("%d\n", sll);
}

int exist() {
    FILE *f = fopen("dictionary.txt", "r");
    fclose(f);
    if (f == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int checkWord(char* word) {
    for (int i = 0; i < strlen(word); i++)
        if (word[i] < 'a' || word[i] > 'z')
            return 1;
    return 0;
}

void input(char* word) {
    do {
        printf("Please, enter the word you would like checked: ");
        scanf("%s", word);
    } while (checkWord(word));
}

int main(int argc, char** argv) {
//    char* a = "peice";
//    char* b = "epics";
//    if (permutation(a, b) == 1) {
//        printf("dung");
//    } else {
//        printf("sai");
//    }



        char word[MAX];
        char choice[3];
        printf("Welcome to the Spell Checker!\n");
        if (exist() == 1) {
            printf("The dictionary exist\n");
            char* choice = "yes";
        } else {
            printf("The dictionary not exist\n");
            printf("Please, check your file dictionary\n");
            char* choice = "no";
        }
    
        while (strcmp(choice, "no") != 0) {
            input(word);
            if (findWord(word) == 1) {
                printf("Great, %s is in the dictionary!\n", word);
            } else if (checkRecommend(word) == 1) {
                printf("Here are the possible words you could have meant: \n");
                recommend(word);
            } else {
                printf("This word not exist\n");
            }
            do {
                printf("Would you like enter another word? (yes/no)\n");
                fpurge(stdin);
                scanf("%s", &choice);
            } while (strcmp(choice, "no") != 0 && strcmp(choice, "yes") != 0);
        }
    return (EXIT_SUCCESS);
}

