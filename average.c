#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int math;
    int english;
    int subject3;
    int subject4;
    float average;
} Student;

void calculate_average(Student* student) {
    // Math and English coefficients are 5, other subjects coefficients are 3
    int total_coefficients = 5 + 5 + 3 + 3;
    float weighted_sum = (student->math * 5) + (student->english * 5) + (student->subject3 * 3) + (student->subject4 * 3);
    student->average = weighted_sum / total_coefficients;
}

void sort_students_by_average(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Name: ");
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove the newline character
        printf("Math score: ");
        scanf("%d", &students[i].math);
        printf("English score: ");
        scanf("%d", &students[i].english);
        printf("Subject 3 score: ");
        scanf("%d", &students[i].subject3);
        printf("Subject 4 score: ");
        scanf("%d", &students[i].subject4);
        getchar(); // To consume the newline character left by scanf

        calculate_average(&students[i]);
    }

    sort_students_by_average(students, n);

    printf("\nStudent Positions and Averages:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Average: %.2f\n", i + 1, students[i].name, students[i].average);
    }

    return 0;
}
