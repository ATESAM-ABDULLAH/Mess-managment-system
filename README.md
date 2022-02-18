# Mess-managment-system
It is always hard and time-consuming for a messing staff to maintain an
“In/Out” record of every student on a register daily. There are also chances of human error during
the record keeping. Hence, GIKI Central Mess wants to digitize its record-keeping system of
students’ data. Being a programmer, you are required to design a C++ program for a mess
Lala/Khala to automate “In/Out” record keeping. Record of a student includes student
registration number, name, billing information, “In/Out” status, and total number of “In” days.

Your program will perform the following functionalities.
• Register a new student.
• Search a student record.
• Change student mess status (“In/Out”).
• Delete a student record.
• Show a total number of “In/Out” students.
• Calculate total bill.

Further details about each functionality are described below:

**Register a new student:** This functionality will add a new student record. Your program will ask
about student name, registration number, and “In/Out” status. Initially, the current bill and
number of “In” days will be zero, and by default, the mess status will be “Out.” After successful
registration, your program will sort the whole table based on the registration numbers. Add an
exception if a student is already registered.

**Search a student record:** This function will search a student from the record table based on the
registration number. If the record is found, display all the details of the student. If no record is
found, your program should inform the mess Lala/Khala and ask if registration is required or not.

**Change student mess status (“In/Out”):** In this chunk of code, your program will ask about a
student registration number, display the current mess status and ask to change the status. After
changing the status, you should update that student’s status in the record table.

**Delete a student record:** Your program will delete a student record and update the data table
accordingly. If Lala/Khala wants to delete a non-registered student record, add an exception.
Show a total number of “In/Out” students: If Lala/Khala wants to check the total number of “In”
students or “Out” students, your program will help to show the information.

**Calculate total bill:** This function will keep record of total number of “In” days of a student. Each
day will be multiplied with PKR 300/- per day. You are required to keep record of days. Add a day
to total number of “In” days if a student changes its status from “Out” to “In”.
