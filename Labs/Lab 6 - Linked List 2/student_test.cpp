//----------------------------------------------
// Purpose: Test student linked list 
// Author:  John Gauch
//----------------------------------------------

#include "student_list.h"

//----------------------------------------------
int main()
{
   // Test the student list class
   StudentList list;
   list.insertTail("John", "Johnson, AR", 3.2);
   list.insertTail("Sara", "Sarason, AR", 3.3);
   list.insertTail("Juliet", "Julietson, AR", 3.4);
   list.insertTail("Keira", "Keirason, AR", 3.5);
   list.insertTail("Tyrone", "Tyroneson, AR", 3.6);
   
   cout << "Searching names..." << endl;
   if (list.searchName("Julia") != NULL) list.searchName("Julia")->print();
   if (list.searchName("Juliet") != NULL) list.searchName("Juliet")->print();
   
   cout << endl << "Searching GPA..." << endl;
   if (list.searchGPA(3.6) != NULL) list.searchGPA(3.6)->print();
   if (list.searchGPA(4.0) != NULL) list.searchGPA(4.0)->print();
}
