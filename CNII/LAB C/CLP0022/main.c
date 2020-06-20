#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

char* lTrim(char* s) {
    int i = 0;
    while (s[i] == ' ') i++;
    if (i > 0) strcpy(&s[0], &s[i]);
    return s;
}

char* rTrim(char* s) {
    int i = strlen(s) - 1;
    while (s[i] == ' ') i--;
    s[i + 1] = '\0';
    return s;
}

char* trim(char* s) {
    lTrim(rTrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL) {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, "  ");
    }
    return s;
}

char* nameStr(char* s) {
    trim(s);
    strlwr(s);
    int L = strlen(s);
    int i;
    for (i = 0; i < L; i++)
        if (i == 0 || i > 0 && s[i - 1] == ' ')
            s[i] = toupper(s[i]);
    return s;
}

int checkNumber(float number, char c) {
    if (number == 2 && c == '\n')
        return 1;
    return 0;
}

int checkString(char* String) {
    for (int i = 0; i < strlen(String); i++) {
        if (String[i] >= '0' && String[i] <= '9')
            return 0;
    }
    return 1;
}
//check ngay thang ton tai hay khong

int validDate(int day, int month, int year) {
    int maxday = 31;
    if (day < 1 || day > 31 || month < 1 || month > 12) return 0;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxday = 30;
    } else if (month == 2) {
        if (year % 400 == 0 || year % 4 == 0 & year % 100 != 0) {
            maxday = 29;
        } else {
            maxday = 28;
        }
    }
    return day <= maxday;
}
//ep char ve so

int ep(char a) {
    switch (a) {
        case '0': return 0;
            break;
        case '1': return 1;
            break;
        case '2': return 2;
            break;
        case '3': return 3;
            break;
        case '4': return 4;
            break;
        case '5': return 5;
            break;
        case '6': return 6;
            break;
        case '7': return 7;
            break;
        case '8':return 8;
            break;
        case '9': return 9;
            break;
        default: return -1;
            break;
    }
}

int checkDate(char* String) {

    if (strlen(String) != 10) return 0;
    int a = ep(String[0]);
    a = a * 10 + ep(String[1]);
    int b = ep(String[3]);
    b = b * 10 + ep(String[4]);
    int c = ep(String[6]);
    c = c * 10 + ep(String[7]);
    c = c * 10 + ep(String[8]);
    c = c * 10 + ep(String[9]);

    for (int i = 0; i < strlen(String); i++) {
        if (String[i] < '0' || String[i] > '9')
            if (i != 2 && i != 5)
                return 0;
    }

    if (String[2] != '/' || String[5] != '/')
        return 0;
    if (validDate(a, b, c) == 0) {
        return 0;
    }
    return 1;
}
//khởi tạo (định nghĩa) biến Student

struct Student {
    char code[MAX];
    char name[MAX];
    char DOB[MAX];
    float point;
};
// hàm kiểm tra xem file có tồn tại hay không

int exist() {
    FILE *f = fopen("Student.txt", "r");
    fclose(f);
    if (f == NULL)
        return 0;
    return 1;
}
// hàm tải dữ liệu vào mảng st của kiểu Student

void loadStudent(struct Student* st, char* a, int* n) {
    FILE *f = fopen("Student.txt", "r");
    fscanf(f, "%[^\n]", a);
    char b[MAX];
    while (feof(f) == 0) {
        fseek(f, 1, SEEK_CUR);
        fscanf(f, "%[^\t\n]", &st[*n].code);
        fseek(f, 2, SEEK_CUR);
        fscanf(f, "%[^\n\t]", &st[*n].name);
        fseek(f, 2, SEEK_CUR);
        fscanf(f, "%[^\n\t]", &st[*n].DOB);
        fseek(f, 2, SEEK_CUR);
        fscanf(f, "%f%[^\n]", &st[*n].point, &b);
        (*n)++;
    }
    fclose(f);

}

int checkCode(struct Student* st, int n, char* code) {
    for (int i = 0; i < n; i++) {
        if (strcmp(code, st[i].code) == 0) {
            return 1;
        }
    }
    return 0;
}

// hàm nhập dữ liệu sinh viên vào mảng và cập nhật vô file Student qua hàm saveFile()

void inputStudent(struct Student* st, int* n) {
    do {
        printf("Enter Student code: ");
        scanf("%s", &st[*n].code);
        fpurge(stdin);
    } while (checkCode(st, *n, st[*n].code));
    do {
        printf("Enter Student name: ");
        scanf("%[^\n]", &st[*n].name);
        fpurge(stdin);
    } while (checkString(st[*n].name) == 0);
    nameStr(st[*n].name); // chỉnh tên cho đẹp đẹp

    do {
        printf("Enter Date of birth (dd/mm/yyyy): ");
        scanf("%s", &st[*n].DOB);
        fpurge(stdin);
    } while (checkDate(st[*n].DOB) == 0);

    //nhập điểm cho học sinh
    char c;
    int s;
    do {
        printf("Enter point: ");
        fpurge(stdin);
        s = scanf("%f%c", &st[*n].point, &c);
    } while (checkNumber(s, c) == 0);

    (*n)++; // tăng n lên 1 nếu nhập thành công (việc này để giúp cho việc xác định chỗ để lưu data nếu tiếp tục thêm data student)
    sortAscend(st, *n); //dùng hàm sortAscending để sắp xếp lại dữ liệu theo tên sinh viên tăng dần
}
// hàm 

void saveFile(struct Student* st, int n, char* a) {
    FILE *f = fopen("Student.txt", "w");
    fprintf(f, "%s", a);
    for (int i = 0; i < n; i++) {
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n");
        fprintf(f, "%s\t\t", st[i].code);
        fprintf(f, "%s\t\t", st[i].name);
        fprintf(f, "%s\t\t", st[i].DOB);
        fprintf(f, "%.1f", st[i].point);
    }
    fclose(f);
}
// hàm output danh sách sinh viên ra ngoài màn hình

void outputList(struct Student* st, char* a, int n) {
    if (n < 1) {
        printf("No data\n");
    } else {
        printf("%s\n", a);
        for (int i = 0; i < n; i++) {
            printf("%s\t\t", st[i].code);
            printf("%s\t\t", st[i].name);
            printf("%s\t\t", st[i].DOB);
            printf("%.1f\n", st[i].point);
        }
    }
}
// hàm tìm kiếm và hiển thị thông tin tên sinh viên muốn tìm

void lookUp(struct Student* st, int n, char* a) {
    char name[MAX];
    int pos[n];
    do {
        fpurge(stdin);
        printf("Enter name's student: ");
        scanf("%[^\n]", name);
    } while (checkString(name) == 0);
    nameStr(name);
    int len = findPos(st, n, name, pos);

    if (len == 0) {
        //        printf("%s not exist\n", name);
        recommend(name, st, n, a);
    } else {
        printf("%s\n", a);
        for (int i = 0; i < len; i++) {
            printf("%s\t\t", st[pos[i]].code);
            printf("%s\t\t", st[pos[i]].name);
            printf("%s\t\t", st[pos[i]].DOB);
            printf("%.1f\n", st[pos[i]].point);
        }
    }
}
// hàm tìm kiếm tên sinh viên muốn tìm, nó sẽ return số vị trí sinh viên có tên như yêu cầu và cho 1 mảng các vị trí của 
// từng sinh viên có tên như yêu cầu

int findPos(struct Student* st, int n, char* name, int* pos) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(name, st[i].name) == 0) {
            pos[flag] = i;
            flag++;
        }
    }
    return flag;
}
//hàm menu
// hàm sắp xếp tên theo thứ tự tăng dần A-B

void sortAscend(struct Student* st, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (st[i].name[0] > st[j].name[0])
                swapList(&st[i], &st[j]);
        }
    }
}
//hàm hoán đổi vị trí cho nhau

void swapList(struct Student *st1, struct Student *st2) {
    struct Student a;
    a = *st1;
    *st1 = *st2;
    *st2 = a;
}

void menu() {
    printf("\n1. Enter student list\n");
    printf("2. Look up student\n");
    printf("3. Display student list\n");
    printf("4. Exit\n");
    printf("Please choose menu (1-4): ");
}








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

void recommend(char* word, struct Student* st, int n, char* th) {
    int i = 0;
    int flag = 0;
    char a[MAX];
    printf("%s\n", th);
    while (i < n) {
        strupr(word);
        strcpy(a, st[i].name);
        strupr(a);
        if (substring(word, a) == 1) {
            printf("%s\t\t", st[i].code);
            printf("%s\t\t", st[i].name);
            printf("%s\t\t", st[i].DOB);
            printf("%.1f\n", st[i].point);
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        printf("%s not exist\n", word);
    }
}

int main(int argc, char** argv) {
    struct Student *st = (struct Student*) malloc(MAX * sizeof (struct Student));
    //        struct Student st[MAX];
    int n = 0;
    char a[MAX];
    int choose = 0;
    char c;


    if (exist() == 0) {
        char c;
        printf("File Student.txt not exist\n");
        printf("Do you want to create new file (Y/N)\n");
        scanf("%c", &c);
        if (c == 'N' || c == 'n') {
            printf("See you again!");
            choose = 4;
        } else {
            FILE* f = fopen("Student.txt", "a");
            fprintf(f, "Student Code\t\tStudent Name\t\tDate of birth\t\tlearning point");
            fclose(f);
            loadStudent(st, a, &n);
        }
    } else {
        loadStudent(st, a, &n);
    }

    while (choose != 4) {

        menu();
        scanf("%d", &choose);
        switch (choose) {
            case 1:do {
                    inputStudent(st, &n);
                    saveFile(st, n, a);
                    printf("please enter to continue ");
                    fpurge(stdin);
                    scanf("%c", &c);
                } while (c == '\n');
                break;
            case 2:do {
                    lookUp(st, n, a);
                    printf("please enter to continue ");
                    fpurge(stdin);
                    scanf("%c", &c);
                } while (c == '\n');
                break;
            case 3:do {
                    outputList(st, a, n);
                    printf("please enter to continue ");
                    fpurge(stdin);
                    scanf("%c", &c);
                } while (c == '\n');
                break;
            case 4: printf("bye bye");
                break;
            default: printf("bye bye");
                choose = 4;
                break;
        }
    }


    //    loadStudent(st, a, &n);
    //    inputStudent(st, &n);
    //    outputList(st, a, n);
    //    lookUp(st,n,a);

    return (EXIT_SUCCESS);
}