#ifndef STUDENTRECORDSYSTEM_STUDENT_H
#define STUDENTRECORDSYSTEM_STUDENT_H
void BSTUDENT_editYourDetail(int cpy_id , char password[20]);
void BSTUDENT_viewRecord(int cpy_id , char password[20]);

typedef struct{
   char name[20];
   int age;
   int id;
   float grade;
   char password[20];
} Student;

Student students[500];

#endif //STUDENTRECORDSYSTEM_STUDENT_H
