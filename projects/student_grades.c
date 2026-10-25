#include <stdio.h>

#define MAX 50
#define SUBJECTS 3

struct Student {
    char  name[50];
    int   roll;
    float marks[SUBJECTS];
    float average;
    char  grade;
};

char get_grade(float avg) {
    if (avg >= 90) return 'A';
    if (avg >= 75) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 40) return 'D';
    return 'F';
}

void add_student(struct Student s[], int *count) {
    if (*count >= MAX) {
        printf("Class is full!\n");
        return;
    }
    struct Student *st = &s[*count];
    float total = 0;

    printf("Enter name: ");
    scanf(" %49[^\n]", st->name);
    printf("Enter roll number: ");
    scanf("%d", &st->roll);

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Marks in subject %d (out of 100): ", i + 1);
        scanf("%f", &st->marks[i]);
        total += st->marks[i];
    }

    st->average = total / SUBJECTS;
    st->grade = get_grade(st->average);
    (*count)++;
    printf("Student added!\n");
}

void display_all(struct Student s[], int count) {
    if (count == 0) {
        printf("No students yet.\n");
        return;
    }
    printf("\n%-6s %-20s %-10s %-6s\n", "Roll", "Name", "Average", "Grade");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-10.2f %-6c\n",
               s[i].roll, s[i].name, s[i].average, s[i].grade);
    }
}

void show_topper(struct Student s[], int count) {
    if (count == 0) {
        printf("No students yet.\n");
        return;
    }
    int best = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].average > s[best].average)
            best = i;
    }
    printf("\nTopper: %s (Roll %d) with average %.2f, grade %c\n",
           s[best].name, s[best].roll, s[best].average, s[best].grade);
}

int main(void) {
    struct Student students[MAX];
    int count = 0, choice;

    do {
        printf("\n===== Student Grade Manager =====\n");
        printf("1. Add student\n2. Show all students\n3. Show topper\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice) {
            case 1: add_student(students, &count); break;
            case 2: display_all(students, count); break;
            case 3: show_topper(students, count); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
