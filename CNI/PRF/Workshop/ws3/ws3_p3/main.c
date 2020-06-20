/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on March 5, 2020, 7:44 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int getRelPos(double x, double y, double r) {
    double d2 = x * x + y*y;
    double r2 = r*r;
    if (d2 < r2) {
        return 1;
    } else if (d2 == r2) {
        return 0;
    }
}

int main(int argc, char** argv) {
    double x, y, r;
    int result;
    printf("\nNhap toa do x y cua diem: \n");
    scanf("%d%d", &x, &y);
    do {
        printf("\nnhap vao ban kinh cua hinh tron: \n");
        scanf("%d", &r);
    } while (r < 0);
    result = getRelPos(x, y, r);
    if (result == 1) {
        printf("\nDiem nam trong vong tron");
    } else if (result == 0) {
        printf("\nDiem nam tren vong tron");
    } else {
        printf("\nDiem nam ngoai vong tron");
    }
    return (EXIT_SUCCESS);
}

