/* *********************************************************************** 
 * Filename		:	main.cpp
 * Author		:	Muhammet Harun ATACAN
 * Date			:	08.01.2021
 * Description	:	Driver program for class student and for class course
 * ***********************************************************************/

#include <iostream>
#include "course.h"		// includes definition of class course
#include "student.h"	// includes definition of class student
#include <cstdlib>
#include <stdexcept>

using namespace std;

int main(int argc, char** argv){
	
	// Definitions
	int *choice, *courseID, *hour;
	string *studentName;
	
	// creates an object
	student studenttt;
	
	// creates an object
	course courseee;
	
	// Shows user-interface
	do{
		if (system("CLS")) system("clear");
		cout << "******************************************************\n";
		cout << "***** 1-)Add a new lessons to the courselist     *****\n";
		cout << "***** 2-)Add a new student to the studentList    *****\n";
		cout << "***** 3-)Add a new lessons for a student         *****\n";
		cout << "***** 4-)Print the schedule                      *****\n";
		cout << "***** 5-)Exit the menu                           *****\n";
		cout << "******************************************************\n";
		cout << "Enter the choice please\n";
		choice = new int;					// Requests memory for the variable
		cin >> *choice;
		switch(*choice){
			case 1:
				if (system("CLS")) system("clear");
				cout << "*****Enter the courseID and hour like 151214002 8 or press -1 to quit*****\n";
				courseID = new int;			// Requests memory for the variable
				hour = new int;				// Requests memory for the variable
				cin >> *courseID;
				if(*courseID != -1)
					cin >> *hour;
				while(*courseID != -1){
					// attempts to call functions and detect the undesirable situations
					try
					{
						// calls setcourseID function
						courseee.setcourseID(*courseID);
						// calls sethour function
						courseee.sethour(*hour);
						// calls addCourse function
						courseee.addCourse();
					}
					catch(invalid_argument &e)
					{
						cout << e.what() << endl;
					}
					cin >> *courseID;
					if(*courseID != -1)
						cin >> *hour;
				}
				delete courseID,hour; 			// frees up the memory
				break;
			case 2:
				if (system("CLS")) system("clear");
				studentName = new string;			// Requests memory for the variable
				cout << "*****Enter the studentName like harun or press -1 to quit*****\n";
				cin >> *studentName;
				while(*studentName != "-1"){
					try
					{
						// calls setName function
						studenttt.setName(*studentName);
						// calls addStudent function
						studenttt.addStudent();
					}
					catch(invalid_argument &e)
					{
						cout << e.what() << endl;
					}
					cin >> *studentName;
				}
				delete studentName; 			// frees up the memory
				break;
			case 3:
				if (system("CLS")) system("clear");
				// calls makeSchedule function
				courseee.makeSchedule();
				cout << endl;
				// calls printStudentandCourseID function
				if(courseee.x!=17){
					studenttt.printStudentandCourseID();
					cout << "\n*****Registered courses and registered students are listed above if they available  *****";
				}
				studentName = new string;		// Requests memory for the variable
				courseID = new int;				// Requests memory for the variable
				cout << "\n*****Enter the studentName and courseID like harun 151214002 or press -1 to quit    *****\n\n";
				cin >> *studentName;
				if(*studentName != "-1")
					cin >> *courseID;
				while(*studentName != "-1"){
					// attempts to call functions and detect the undesirable situations
					try
					{
						// calls setName function
						studenttt.setName(*studentName);
						// calls setcourseID function
						studenttt.setcourseID(*courseID);
						// calls addStudentandCourseID function
						studenttt.addStudentandCourseID(courseee);
					}
					catch(invalid_argument &e)
					{
						cout << e.what() << endl;
					}
					cout << endl;
					system("pause");
					if (system("CLS")) system("clear");
					// calls makeSchedule function
					courseee.makeSchedule();
					cout << endl;
					// calls printStudentandCourseID function
					if(courseee.x!=17){
						studenttt.printStudentandCourseID();
						cout << "\n*****Registered courses and registered students are listed above if they available  *****";
					}
					cout << "\n*****Enter the studentName and courseID like harun 151214002 or press -1 to quit    *****\n\n";
					cin >> *studentName;
					if(*studentName != "-1")
						cin >> *courseID;
				}
				delete studentName,courseID; 		// frees up the memory
				break;
			case 4:
				if (system("CLS")) system("clear");
				// calls printCourseIDandHour function
				courseee.printCourseIDandHour();
				// calls makeSchedule function
				courseee.makeSchedule();
				cout << endl;
				// calls printStudentandCourseID function
				studenttt.printStudentandCourseID();
				cout << "\n\n\n\n\n";
				system("pause");
				break;
		}
	}while(*choice != 5);							// if choice==5, while loop ends
	
	delete choice; 									// frees up the memory
	
	
	
	return 0;
}
