#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 20

void sortScores(int scores[], char students[][20], int numStudents);
void printBelowAverage(int scores[], char students[][20], int numStudents, double average);
void printTopStudent(int score, char student[]);

int main()
{
    char students[MAX_STUDENTS][20];
    int scores[MAX_STUDENTS];
    int numStudents;
    int totalScore = 0;
    double average;
    int highestScoreIndex = 0;

    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Number of students exceeds the maximum limit.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%19s", students[i]);

        printf("Enter the test score of student %d: ", i + 1);
        scanf("%d", &scores[i]);

        totalScore += scores[i];

        if (scores[i] > scores[highestScoreIndex]) {
            highestScoreIndex = i;
        }
    }

    average = (double)totalScore / numStudents;

    printf("\nAverage score: %.2lf\n", average);
    printBelowAverage(scores, students, numStudents, average);
    printf("Highest test score: %d\n", scores[highestScoreIndex]);
    printTopStudent(scores[highestScoreIndex], students[highestScoreIndex]);

    return 0;
}

void sortScores(int scores[], char students[][20], int numStudents)
{
    for (int i = 0; i < numStudents - 1; i++)
    {
        for (int j = 0; j < numStudents - i - 1; j++)
        {
            if (scores[j] > scores[j + 1])
            {
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                char tempStudent[20];
                strcpy(tempStudent, students[j]);
                strcpy(students[j], students[j + 1]);
                strcpy(students[j + 1], tempStudent);
            }
        }
    }
}

void printBelowAverage(int scores[], char students[][20], int numStudents, double average)
{
    printf("Students below the average score:\n");

    for (int i = 0; i < numStudents; i++)
    {
        if (scores[i] < average)
        {
            printf("%s\n", students[i]);
        }
    }

    printf("\n");
}

void printTopStudent(int score, char student[])
{
    printf("Top student: %s\n", student);
    printf("Congratulations to %s for the outstanding achievement!\n", student);
}
