/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 13, 2020, 8:51 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    for (int code = 0; code <= 255; code++) {
        printf("%c: %d:, %o, %X\n", code, code, code, code);
        if(code !=0 && code%20==0) getchar();
    }
    return (EXIT_SUCCESS);
}

