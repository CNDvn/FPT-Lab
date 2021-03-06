#include <stdio.h>
#include <time.h>
#define MAX 100

int random(int minN, int maxN) {
    return minN + rand() % (maxN + 1 - minN);
}

void menu(double money) {
    printf("You have $%.2lf\n", money);
    printf("Choose one of the following menu options:\n");
    printf("1) Play the slot machine\n");
    printf("2) Save game\n");
    printf("3) Cash out\n");
}
//int check
//hàm kiểm tra xem dãy số đó có giống nhau hết không. có == 1; không == 0 

int checkWinAll(int* rand, int n) {
    for (int i = 1; i < n; i++) {
        if (rand[0] != rand[i]) {
            return 0;
        }
    }
    return 1;
}

int checkWin(int* rand, int n) {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10];
    int count;
    int price = 0;
    for (int i = 0; i < 10; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == rand[j])
                count++;
        }
        b[i] = count;
    }
    
    for(int i = 0; i < 10; i++){
        if(b[i] > 1)
            price += b[i];
    }
    return price;
}
//
//void delArr(int* arr, int* n, int pos) {
//    for (int i = pos; i < *n; i++) {
//        arr[i] = arr[i + 1];
//    }
//    (*n)--;
//}
//hàm random n số và cho vào mảng rand[] 

void getRand(int* rand, int n) {
    for (int i = 0; i < n; i++) {
        rand[i] = random(1, 9);
    }
}

void outRandNum(int* rand, int n) {
    for (int i = 0; i < n; i++)
        printf("%d", rand[i]);
}

void play(double *money, int* arr, int* rand, int n) {
    int win = checkWin(arr, n);
    *money -= 0.25;
    if (checkWinAll(rand, n)) {
        printf("congratulations\n");
        printf("congratulations\n");
        printf("congratulations\n");
        printf("congratulations\n");
        printf("congratulations\n");
        printf("congratulations\n");
        printf("The slot machine shows ");
        outRandNum(rand, n);
        printf("\n");
        printf("You won with 100$\n");
        *money += 100;
    } else if (win == 0) {
        printf("The slot machine shows ");
        outRandNum(rand, n);
        printf("\n");
        printf("Sorry you don't win anything\n");
    } else {
        printf("The slot machine shows ");
        outRandNum(rand, n);
        printf("\n");
        printf("you win $%d!\n", win);
        *money += win;
    }
}

void save(double money) {
    FILE *f = fopen("money.txt", "w");
    fprintf(f, "%.2lf\n", money);
    fclose(f);

    printf("You money had saved!\n");
}

void cashOut(char* fileName, double money) {
    printf("Thank you for playing! You end with $%.2lf", money);
    FILE *f = fopen(fileName, "w");
    fprintf(f, "%.2lf\n", "0");
    fclose(f);
}

int checkMoney(double money) {
    if (money == 0) {
        return 0;
    }
    return 1;
}

int checkFile(char* fileName) {
    int exist = 1;
    FILE *f = fopen("money.txt", "r");
    if (f == NULL) exist = 0;
    fclose(f);
    return exist;
}

int main() {
    srand((int) time(0));

    char* fileName = "money.txt";
    int choice;
    double money;

    FILE *f = fopen(fileName, "r");

    if (checkFile(fileName) == 1) {
        fscanf(f, "%lf", &money);
    } else {
        money = 10;
    }
    fclose(f);

    int n;
    int rand[MAX];

    int flag = 1;
    if (checkMoney(money) <= 0) {
        flag = 0;
        printf("you have no money\n");
    }

    while (flag == 1) {
        menu(money);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("nhap n: ");
                    scanf("%d", &n);
                } while (n < 3);
                getRand(rand, n);

                int arr[20];
                for (int i = 0; i < n; i++)
                    arr[i] = rand[i];

                play(&money, arr, rand, n);
                break;
            case 2: save(money);
                flag = 0;
                break;
            case 3: cashOut(fileName, money);
                flag = 0;
                break;
        }

        if (checkMoney(money) <= 0) {
            flag = 0;
            printf("you have no money\n");
        }
    }
}