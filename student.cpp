/* ******************************************************* 
 * Filename		:	student.cpp
 * Author		:	Muhammet Harun ATACAN
 * Date			:	08.01.2021
 * Description	:	student Class Implementation
 * ******************************************************/

#include "student.h"	  /// includes definition of class student
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

/// Default Constructor
student::student(const string &Name)
{
	setName(Name);					// calls setName function
}

/// Sets name of the student
void student::setName(const string &Name){
	studentName = Name;
}

/// Returns name of the student
string student::getName() const{
	return studentName;
}

/// Adds the studentName in harun format to the multimap
void student::addStudent(){
	Students::iterator it;
	it = Studentt.find(getName());				// find studentName in Studentt and find returns iterator
	if(it!=Studentt.end())						// if iterator not at end
		throw invalid_argument( "This name is available please try another name. **Hint: Assume that mustafa is available but Mustafa_Kemal is not." );
	else
		Studentt.insert(Students::value_type(getName(),0));				// inserts two value_type objects in Studentt
}

/// Adds the studentName and the courseID in harun 151214002 format they have chosen to the multimap if there are no negative conditions
void student::addStudentandCourseID(course &a){
	// Definitions
	int *ctr, *ctr2, *ctr3;
	
	ctr = new int, ctr2 = new int, ctr3 = new int;			// Requests memory for the variable
	*ctr = 0, *ctr2 = 0, *ctr3 = 0;			// Stores value at allocated address
	
	for(Students::iterator it=Studentt.begin(); it!=Studentt.end(); it++){					// uses iterator to walk through elements of Studentt
		if(it->first == getName() && it->second == getcourseID())							// checks whether the student has taken this lesson before
			(*ctr)++;
	}
	for(Students::iterator it=Studentt.begin(); it!=Studentt.end(); it++){					// uses iterator to walk through elements of Studentt
		if(it->first == getName())															// checks whether the student has registered before
			(*ctr2)++;
	}
	for(Courses::iterator ito2=a.Coursee.begin();ito2!=a.Coursee.end();ito2++){				// uses iterator to walk through elements of Coursee
		if(ito2->first == getcourseID())													// checks whether the entered course is enrolled
			(*ctr3)++;
	}
		
	// This 'if' block eliminates undesireable situations
	if(a.x==17)
		throw invalid_argument( "Schedule is not available and you can't add course." );
	else if(*ctr2 == 0)
		throw invalid_argument( "This student is not registered." );
	else if(*ctr3 == 0)
		throw invalid_argument( "This course is not available." );
	else if(*ctr != 0)
		throw invalid_argument( "This student has already taken this course please try another course." );
	else
		Studentt.insert(Students::value_type(getName(), getcourseID()));									// inserts two value_type objects in Studentt
	delete ctr, ctr2, ctr3; 					// frees up the memory
}

/// Prints the studentName and the courseID in harun --> 151214002, 151214003 format
void student::printStudentandCourseID(){
	//	Definitions
	Students::iterator it, location1, location2;
	string *temp;
	int *ctr;
	
	temp = new string;					// Requests memory for the variable
	ctr = new int;						// Requests memory for the variable
	*ctr = 0;			// Stores value at allocated address
	for(it=Studentt.begin();it!=Studentt.end();it++){				// uses iterator to walk through elements of Studentt
		if(it->second == 0){
			// determines lower and upper bound of it->first in student
			location1 = Studentt.lower_bound(it->first);
			location2 = Studentt.upper_bound(it->first);
			for(location1;location1!=location2;location1++){
				(*ctr)++;
			}
			if(*ctr<2)
				cout << setw(15) << it->first << " is free at any time of the week." << endl;
			*ctr=0;
		}
	}
	delete ctr; 			// frees up the memory
	for(it=Studentt.begin();it!=Studentt.end();it++){				// uses iterator to walk through elements of Studentt
		if(it->second != 0){
			if(*temp==it->first)
				cout << ", " << it->second;
			else
				cout << "\n" << setw(15) << it->first << " --> " << it->second;
			*temp = it->first;
		}
	}
	cout << endl;
	delete temp; 			// frees up the memory
}

/// Destructor
student::~student()
{
}
