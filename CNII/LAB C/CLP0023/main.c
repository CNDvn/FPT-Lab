/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on June 13, 2020, 3:13 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

char *myStrcat(char *dest, const char *src) {

    int i = -1;
    int j = 0;
    do {
        i++;
        if (dest[i] == '\0') {
            do {
                dest[i] = src[j];
                j++;
                i++;
            } while (src[j] != '\0');
            break;
        }
    } while (dest[j] != '\0');
}

int myStrcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0')) {
        i++;
    }
    return str1[i] - str2[i];
}

char *myStrcpy(char *dest, const char *src) {
    int i = 0;
    do {
        dest[i] = src[i];
        i++;
        dest[i] = '\0';
    } while (src[i] != '\0');
}

char *myStrncpy(char *dest, const char *src, size_t n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

char *myStrstr(char* string, char* match) {
    int i = 0;
    int flag = 0;
    do {
        int j = 0;
        do {
            if (match[j] == string[i]) {
                flag++;
                j++;
                i++;
            } else {
                flag = 0;
                break;
            }
        } while (match[j] != '\0');
        if (flag > 0) {
            return string + i - flag;
        }
        i++;
    } while (string[i] != '\0');
    return "(null)";
}

char *myStrchr(const char *str, int c) {
    int i = 0;
    do {
        if (c == str[i])
            return str + i;
        i++;
    } while (str[i] != '\0');
    return NULL;
}

int main(int argc, char** argv) {
    //    char str[80];
    //    strcpy(str,"these ");
    //    strcat(str, "strings ");
    //    strcat(str, "are ");
    //    strcat(str, "concatenated. ");
    //    puts(str);
    //    
    //    char mstr[80];
    //    myStrcpy(mstr,"these ");
    //    myStrcat(mstr, "strings ");
    //    myStrcat(mstr, "are ");
    //    myStrcat(mstr, "concatenated. ");
    //    puts(mstr);

    //    char key[] = "apple";
    //    char keyb[] = "";
    //    char keyc[] = "apple";
    //    char keyd[] = "A";
    //    char buffer[80];
    //    char keye[] = "0";
    //    printf("%d\n",strcmp(key,keyb));
    //    printf("%d\n",strcmp(key,keyc));
    //    printf("%d\n",strcmp(key,keyd));
    //    printf("%d\n",strcmp(key,keye));
    //    
    //    printf("%d\n",myStrcmp(key,keyb));
    //    printf("%d\n",myStrcmp(key,keyc));
    //    printf("%d\n",myStrcmp(key,keyd));
    //    printf("%d\n",myStrcmp(key,keye));

    //    char str1[] = "Sample string";
    //    char str2[40];
    //    char str3[40];
    //    strcpy(str2, str1);
    //    strcpy(str3, "copy successful");
    //    printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
    //
    //    char str4[] = "Sample string";
    //    char str5[40];
    //    char str6[40];
    //    myStrcpy(str5, str4);
    //    myStrcpy(str6, "copy successful");
    //    printf("str1: %s\nstr2: %s\nstr3: %s\n", str4, str5, str6);

    //    char str1[] = "To be or not to be";
    //    char str2[40];
    //    char str3[40];
    //    strncpy(str2,str1, sizeof(str2));
    //    strncpy(str3,str2,5);
    //    str3[5] = '\0';
    //    puts(str1);
    //    puts(str2);
    //    puts(str3);
    //    
    //    char mstr1[] = "To be or not to be";
    //    char mstr2[40];
    //    char mstr3[40];
    //    myStrncpy(mstr2,mstr1, sizeof(mstr2));
    //    myStrncpy(mstr3,mstr2,5);
    //    mstr3[5] = '\0';
    //    puts(mstr1);
    //    puts(mstr2);
    //    puts(mstr3);

    //    char str[] = "This is a simple string";
    //    char * pch;
    //    pch = strstr (str,"simple");
    //    strncpy(pch,"sample",6);
    //    puts(str);
    //    
    //    char mstr[] = "This is a simple string";
    //    char * mpch;
    //    mpch = myStrstr (mstr,"simple");
    //    myStrncpy(mpch,"sample",6);
    //    puts(mstr);

    char str[] = "This is a sample string";
    char * pch;
    printf("Looking for the 's' character in \"%s\"...\n", str);
    pch = strchr(str, 's');
    while (pch != NULL) {
        printf("found at %d\n", pch - str + 1);
        pch = strchr(pch + 1, 's');
    }
    
    char mstr[] = "This is a sample string";
    char * mpch;
    printf("Looking for the 's' character in \"%s\"...\n", mstr);
    mpch = myStrchr(mstr, 's');
    while (mpch != NULL) {
        printf("found at %d\n", mpch - mstr + 1);
        mpch = myStrchr(mpch + 1, 's');
    }

    return (EXIT_SUCCESS);
}

