Student Database Management System
Overview
The Student Database Management System is a C-based application designed to manage student records efficiently. It supports functionalities such as adding, updating, deleting, and viewing student information. The system can use either an array-based or linked list-based queue implementation to manage the student records.

Features
Add Student: Add student records from a file or manually.
View Student: Retrieve student details using roll number or first name.
Update Student: Modify existing student information.
Delete Student: Remove student records from the system.
View All Students: Display all student records.
View Students in a Course: List students enrolled in a specific course.
Count Number of Students: Show the total number of students in the system.

Usage
After running the program, you'll be prompted with a menu to choose one of the following options:

Add Student From File: Load student data from a file into the system.
Add Student Manually: Enter student details manually.
View Student Using Roll Number: Retrieve student information based on roll number.
View Student Using First Name: Retrieve student information based on first name.
View Students in A Course: List students enrolled in a specific course.
Count Number Of Students: Display the total number of students.
Delete Student: Remove a student record from the system.
Update Student: Modify student information.
View All Students: Display all student records.
Exit: Exit the program.

File Structure
Queue.c: Contains the implementation of queue operations.
main.c: Main program file with user interface and menu options.
Queue.h: Header file declaring functions and data structures for Queue.c.
FileHandling.h: Functions for reading from and writing to files.
Makefile: Build script for compiling the project.
Testing
Test the system by performing operations such as adding, viewing, updating, and deleting student records. Verify that the system correctly manages student data and handles all user inputs as expected.




