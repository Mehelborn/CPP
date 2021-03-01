#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

const char filename[] = "students_results.dat";
FILE* file_ptr;

struct students {
    char lastname[15];
    short cs, mt, en, ru, al;
    students* prev;
    students* next;
};

struct students student;

void menu();
void createFile();
void printFile();
void search();

int main() {
    short c;
    while (1) {
        menu();
        printf("Choose the option number: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                createFile();
                printf("\nFile 'students_results.dat' was created and saved\n");
                break;
            case 2:
                printf("\nThe file:\n");
                printFile();
                break;
            case 3:
                search();
                break;      
            case 4:
                return 0;
        }
    }
}

void menu() {
    printf("\n1 - Create a new file\n");
    printf("2 - Print the file\n");
    printf("3 - Search\n");
    printf("4 - Exit\n");
}

void createFile() {
    int exit_key;
    file_ptr = fopen(filename, "wb");
    int i = 0;
    do {
        i++;
        printf("\nEnter information about a student");
        printf("\n%d. Lastname: ", i);
        scanf("%s", student.lastname);
        printf("\nComputer Science: ");
        scanf("%1d", &student.cs);
        printf("\nMathematics: ");
        scanf("%1d", &student.mt);
        printf("\nEnglish: ");
        scanf("%1d", &student.en);
        printf("\nRussian: ");
        scanf("%1d", &student.ru);
        printf("\nLinear Algebra: \n");
        scanf("%1d", &student.al);

        fwrite(&student, sizeof(student), 1, file_ptr);

        printf("Enter 0 for exit or 1 to continue...\n");
        scanf("%d", &exit_key);
    }
    while(exit_key != 0);
    fclose(file_ptr);
}

void printFile() {
    file_ptr = fopen(filename, "rb");

    fread(&student, sizeof(student), 1, file_ptr);

    printf("\n%-25s%-25s%-25s%-25s%-25s%-25s\n", 
        "lastname", "Computer Science", 
        "Mathematics", "English", 
        "Russian", "Linear Algebra");
    int i = 1;
    while (!feof(file_ptr)) {
        printf("\n\n%d. %-25s%-25d%-25d%-25d%-25d%-25d",
            i, student.lastname, student.cs, student.mt,
            student.en, student.ru, student.al);
        fread(&student, sizeof(student), 1, file_ptr);
        i++;
    }
    printf("\n\n");
}

void search() {
    file_ptr = fopen(filename, "rb");

    fread(&student, sizeof(student), 1, file_ptr);
   
    int i = 1;
    printf("\nThe best computer science students: \n");
    while (!feof(file_ptr)) {
        if (student.cs == 5) {
            printf("\n\n%d. %-25s", i, student.lastname);
        }
        fread(&student, sizeof(student), 1, file_ptr);
        i++;
    }
    printf("\n\n");
}
