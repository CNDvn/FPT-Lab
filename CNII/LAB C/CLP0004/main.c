/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Duc Hieu
 *
 * Created on June 25, 2020, 9:33 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define MAX 200

/*
 * 
 */
char* abc(int x);

void play(char* fileName, int end, int* score);

void checkNumber() {

}

int main(int argc, char** argv) {
    char playerFirstName[MAX];
    char playerLastName[MAX];
    char fileName[MAX];
    int n;
    int numOfQuest;
    int score = 0;

    //    printf("What is your first name?\n");
    //    scanf("%[^\n]", &playerFirstName);
    //    fpurge(stdin);
    //    printf("What is your last name?\n");
    //    scanf("%[^\n]", &playerLastName);
    //    printf("What file stores your question?\n");
    //    scanf("%s", &fileName);
    //    
    //    FILE *f = fopen(fileName, "r");
    //    fscanf(f, "%d", &numOfQuest);
    //    printf("%d",numOfQuest);
    //    fclose(f);
    //
    //    printf("How many question would you like (out of %d)?\n", numOfQuest);
    //    scanf("%d", &n);
    //    fpurge(stdin);
    play("sample.txt", 3, &score);
    printf("%s %s, your game is over!\n", playerFirstName, playerLastName);
    printf("You final score is %d points\n", score);
    printf("Better luck next time!");

    return (EXIT_SUCCESS);
}

void play(char* fileName, int end, int* score) {

    //    int numOfQuest;
    int pointTmp;
    int point;
    char typeOfQuest[2];
    char quest[MAX];
    char answer[MAX];
    char userAnswer[MAX];
    FILE *f;
    f = fopen(fileName, "r");

    //    int m = ftell(f);
    //    printf("vi tri %d\n", m);

    //    fscanf(f, "%d", &numOfQuest);
    fseek(f, 1, SEEK_SET);
    int i = 0;
    while (i < end) {
        i++;
        int check = 0;
        check = fscanf(f, "%s%d\n", typeOfQuest, &pointTmp);

        point = pointTmp;
        typeOfQuest[2] = '\0';

        if (check != 2 || strcmp(typeOfQuest, "TF") != 0 && strcmp(typeOfQuest, "MC") != 0 && strcmp(typeOfQuest, "SA") != 0) {
            printf("File wrong!\n");
            break;
        }

        //        printf("%s\n", typeOfQuest);
        printf("Point: %d\n", point);

        if (strcmp(typeOfQuest, "TF") == 0) {
            fscanf(f, "%[^\n] ", &quest);
            printf("Question: %s\n", quest);

            fscanf(f, "%s", &answer);

            if (strcmp(answer, "true") != 0 && strcmp(answer, "false") != 0) {
                printf("File wrong!, Ban format sai cau %d\n", i);
                break;
            }
            do {
                scanf("%[^\n]", userAnswer);
                fpurge(stdin);
                if (strcmp(userAnswer, "true") != 0 && strcmp(userAnswer, "false") != 0 && strcmp(userAnswer, "SKIP") != 0) {
                    printf("Just true or false\n");
                }
            } while (strcmp(userAnswer, "true") != 0 && strcmp(userAnswer, "false") != 0 && strcmp(userAnswer, "SKIP") != 0);
            fpurge(stdin);
            if (strcmp(userAnswer, answer) == 0) {
                printf("Correct! You get %d points\n", point);
                *score += point;
            } else if (strcmp(userAnswer, "SKIP") == 0) {
                printf("You have elected to skip that question\n");
            } else {
                point *= 2;
                printf("Incorrect, the answer was %s. You lose %d points\n", answer, point);
                *score -= point;
            }
        } else if (strcmp(typeOfQuest, "MC") == 0) {
            fscanf(f, "%[^\n] ", &quest);
            printf("Question: %s\n", quest);
            int numOfAnswer;

            int check = fscanf(f, "%d ", &numOfAnswer);
            if (check != 1) {
                printf("File wrong!, please edit again question %d\n", i);
                break;
            }
            int j = 0;
            while (j < numOfAnswer) {
                fscanf(f, "%[^\n]\n", &answer);
                printf("%s ", abc(j));
                printf("%s\n", answer);
                j++;
            }
            fscanf(f, "%s", &answer);
            scanf("%s", userAnswer);
            fpurge(stdin);
            if (strcmp(userAnswer, answer) == 0) {
                printf("Correct! You get %d points\n", point);
                *score += point;
            } else if (strcmp(userAnswer, "SKIP") == 0) {
                printf("You have elected to skip that question\n");
            } else {
                point *= 2;
                printf("Incorrect, the answer was %s. You lose %d points\n", answer, point);
                *score -= point;
            }
        } else if (strcmp(typeOfQuest, "SA") == 0) {
            fscanf(f, "%[^\n]\n", &quest);
            printf("Question: %s\n", quest);
            fscanf(f, "%s", &answer);
            scanf("%[^\n]", userAnswer);
            fpurge(stdin);


            //            printf("%s\n%s\n",answer,userAnswer);


            int j = 0;
            int flag = 0;
            do {
                if (answer[j] != userAnswer[j]) {
                    flag = 1;
                }
                j++;
            } while (answer[j] != '\0' && userAnswer[j] != '\0');

            if (flag == 0) {
                printf("Correct! You get %d points\n", point);
                *score += point;
            } else if (strcmp(userAnswer, "SKIP") == 0) {
                printf("You have elected to skip that question\n");
            } else {
                point *= 2;
                printf("Incorrect, the answer was %s. You lose %d points\n", answer, point);
                *score -= point;
            }
        }
    }
    fclose(f);
}

char* abc(int x) {
    switch (x) {
        case 0: return "A";
        case 1: return "B";
        case 2: return "C";
        case 3: return "D";
        case 4: return "E";
        case 5: return "F";
        case 6: return "G";
    }
}