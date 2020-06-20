/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 12, 2020, 5:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char ch;
    int nVowels = 0, nConsonants = 0, nOthers = 0;
    
    printf("Enter you string: ");
    do {
        ch = toupper(getchar());
        if (ch >= 'A' && ch <= 'Z') {
            switch (ch) {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U': nVowels++;
                    break;
                default: nConsonants++;
            }
        } else nOthers++;
    } while (ch != '\n');
    
    printf("nVowels: %d\n", nVowels);
    printf("nConsonants: %d\n", nConsonants);
    printf("nOthers: %d", nOthers);
    return (EXIT_SUCCESS);
}

