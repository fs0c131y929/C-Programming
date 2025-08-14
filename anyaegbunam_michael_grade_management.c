//Author: Michael Anyaegbunam
//Program Name: Grade Management System
//Description: This is a grade management system written in C to determine the grades and averages of all students.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Student {
    char name[50];
    char studentID[11]; 
    float grades[5];
    float avgGrade;
    char letterGrade;
};

struct Course {
    int courseNum;
    char courseName[50];
    struct Student* students;
    int roster;
};



void classSize(struct Course* course);
void gradeCalculation(struct Course* course);
void getstudentData(struct Course* course);
void table(struct Course* course);

int main() {
    struct Course course;

    printf("Enter the Course number: ");
    scanf("%d", &course.courseNum);
    getchar(); 


    printf("Enter the course name: ");
    fgets(course.courseName, sizeof(course.courseName), stdin);
    course.courseName[strcspn(course.courseName, "\n")] = '\0';


    classSize(&course);
    getstudentData(&course);
    gradeCalculation(&course);
    table(&course);

    free(course.students);


    return 0;
}

void classSize(struct Course* course) {
    printf("Enter the number of students in the course: ");
    scanf("%d", &course->roster);
    getchar(); 

    course->students = (struct Student*)malloc(course->roster * sizeof(struct Student));
}

void getstudentData(struct Course* course) {
    for (int i = 0; i < course->roster; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter name: ");
        fgets(course->students[i].name, sizeof(course->students[i].name), stdin);
        course->students[i].name[strcspn(course->students[i].name, "\n")] = '\0';

        printf("Enter your PantherID: ");
        fgets(course->students[i].studentID, sizeof(course->students[i].studentID), stdin);
        course->students[i].studentID[strcspn(course->students[i].studentID, "\n")] = '\0';

        printf("Enter your 5 assignment grades:\n");
        for (int j = 0; j < 5; j++) {
            do {
                printf("Assignment %d: ", j + 1);
                scanf("%f", &course->students[i].grades[j]);

                while (getchar() != '\n');
                if (course->students[i].grades[j] < 0 || course->students[i].grades[j] > 100) {
                    printf("Score must be between 0 and 100.\n");

                }

            } while (course->students[i].grades[j] < 0 || course->students[i].grades[j] > 100);
        }
    }
}

void gradeCalculation(struct Course* course) {
    for (int i = 0; i < course->roster; i++) {
        float grade_total = 0;
        for (int j = 0; j < 5; j++) {
            grade_total += course->students[i].grades[j];
        }

        course->students[i].avgGrade = grade_total / 5;

        if (course->students[i].avgGrade >= 90) {
            course->students[i].letterGrade = 'A';
        } else if (course->students[i].avgGrade >= 80) {

            course->students[i].letterGrade = 'B';
        } else if (course->students[i].avgGrade >= 70) {

            course->students[i].letterGrade = 'C';
        } else if (course->students[i].avgGrade >= 60) {

            course->students[i].letterGrade = 'D';
        } else {
            course->students[i].letterGrade = 'F';
        }
    }
}

void table(struct Course* course) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("%-20s %-11s %5s %5s %5s %5s %5s %5s %5s\n", 
           "Name", "ID", "A1", "A2", "A3", "A4", "A5", "avg", "grade");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < course->roster; i++) {
        printf("%-20s %-11s", course->students[i].name, course->students[i].studentID);
        for (int j = 0; j < 5; j++) {
            printf(" %5.1f", course->students[i].grades[j]);
        }
        printf(" %5.1f %5c\n", course->students[i].avgGrade, course->students[i].letterGrade);
    }
}    