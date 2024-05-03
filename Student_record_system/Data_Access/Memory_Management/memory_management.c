#include<stdlib.h>
#include "../../Business_Logic/Student/student.h"
#include "memory_management.h"

void DMEMORY_freeStudent (Student* student){
	free(student);
}
void DMEMORY_allocateStudent(){
    Student* student = (Student*) malloc(sizeof(Student));
}