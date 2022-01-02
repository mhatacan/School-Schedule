/* ******************************************************* 
 * Filename		:	course.cpp
 * Author		:	Muhammet Harun ATACAN
 * Date			:	08.01.2021
 * Description	:	course Class Implementation
 * ******************************************************/

#include "course.h"		/// include definition of class course
#include <iostream>
#include <stdexcept>
#include <map>
#include <iomanip>

using namespace std;

/// Default Constructor
course::course(int COURSEID, int HOUR)
{
	setcourseID(COURSEID);					// calls setCourseID function
	sethour(HOUR);							// calls sethour function
}

/// Sets ID of the course
void course::setcourseID(int COURSEID){
	courseID = COURSEID;
}

/// Sets hour of the course
void course::sethour(int HOUR){
	hour = HOUR;
}

/// Returns ID of the course
int course::getcourseID() const{
	return courseID;
}

/// Returns hour of the course
int course::gethour() const{
	return hour;
}

/// Adds courseID and hour in 151214002 8 format
void course::addCourse(){
	Courses::iterator it;
	it = Coursee.find(getcourseID());				// find courseID in Coursee and find returns iterator
	if(it!=Coursee.end())							// if iterator not at end
		throw invalid_argument( "This course is available please try another course." );
	else if(getcourseID()<-1 || gethour()<=0)
		throw invalid_argument( "You entered an invalid value please try again." );
	else
		Coursee.insert(Courses::value_type(getcourseID(), gethour()));
}

/// Makes schedule starting from Monday to Friday and everyday have 6 slots
void course::makeSchedule(){
	//	Definitions
	Courses Monday, Tuesday, Wednesday, Thursday, Friday;
	int *size, *ctrMonday, *ctrTuesday, *ctrWednesday, *ctrThursday, *ctrFriday;
	
	size=new int, ctrMonday=new int, ctrTuesday=new int, ctrWednesday=new int, ctrThursday=new int, ctrFriday=new int;						// Requests memory for the variable
	*ctrMonday=1, *ctrTuesday=1, *ctrWednesday=1, *ctrThursday=1, *ctrFriday=1;																// Stores value at allocated address
	x=0;																			// x is indicator and initialize to 0
	for(Courses::iterator it=Coursee.begin();it!=Coursee.end();it++){				// uses iterator to walk through elements of Coursee
		*size = it->second;
		for(int i=0;i<*size;i++){
			if(*ctrMonday < 7){														// everyday have 6 slots so *ctrMonday should have 1,2,3,4,5,6
				Monday.insert(Courses::value_type(*ctrMonday,it->first));			// it->first represents the courseID and *ctrMonday shows the time of the course
				(*ctrMonday)++;														// counter should increase for can take value of 1,2,3,4,5,6
			}
			else if(*ctrTuesday < 7){												// everyday have 6 slots so *ctrTuesday should have 1,2,3,4,5,6
				Tuesday.insert(Courses::value_type(*ctrTuesday,it->first));			// it->first represents the courseID and *ctrTuesday shows the time of the course
				(*ctrTuesday)++;													// counter should increase for can take value of 1,2,3,4,5,6
			}
			else if(*ctrWednesday < 7){												// everyday have 6 slots so *ctrWednesday should have 1,2,3,4,5,6
				Wednesday.insert(Courses::value_type(*ctrWednesday,it->first));		// it->first represents the courseID and *ctrWednesday shows the time of the course
				(*ctrWednesday)++;													// counter should increase for can take value of 1,2,3,4,5,6
			}
			else if(*ctrThursday < 7){												// everyday have 6 slots so *ctrThursday should have 1,2,3,4,5,6
				Thursday.insert(Courses::value_type(*ctrThursday,it->first));		// it->first represents the courseID and *ctrThursday shows the time of the course
				(*ctrThursday)++;													// counter should increase for can take value of 1,2,3,4,5,6
			}
			else if(*ctrFriday < 7){												// everyday have 6 slots so *ctrFriday should have 1,2,3,4,5,6
				Friday.insert(Courses::value_type(*ctrFriday,it->first));			// it->first represents the courseID and *ctrFriday shows the time of the course
				(*ctrFriday)++;														// counter should increase for can take value of 1,2,3,4,5,6
			}
			else
				x=17;																// x is indicator and if x=17, schedule is not available.
		}
	}
	delete size, ctrMonday, ctrTuesday, ctrWednesday, ctrThursday, ctrFriday; 		// frees up the memory.
	if(getResult(17))																// if x=17, schedule is not available and calls bool function for comparison
		cout << "\nSchedule is not available." << endl;
	else																			// if x!=17, schedule is available
		printSchedule(Monday, Tuesday, Wednesday, Thursday, Friday);				// calls printSchedule function
}

/// Prints schedule in 151214002 --> Monday123456 Tuesday12 format
void course::printSchedule(Courses Monday, Courses Tuesday, Courses Wednesday, Courses Thursday, Courses Friday){
	int *ctr;
	ctr = new int;											// Requests memory for the variable
	*ctr = 0;												// Stores value at allocated address
	for(Courses::iterator it=Coursee.begin();it!=Coursee.end();it++){						// uses iterator to walk through elements of Coursee
		cout << setw(15) << it->first << " -->";
		for(Courses::iterator ito2=Monday.begin(); ito2!=Monday.end(); ito2++){						// uses iterator to walk through elements of Monday
			if(it->first == ito2->second){
				(*ctr)++;
				if(*ctr == 1)
					cout << " Monday " << ito2->first;
				else
					cout << ito2->first;
			}
		}*ctr=0;												// Stores value at allocated address
		for(Courses::iterator ito2=Tuesday.begin(); ito2!=Tuesday.end(); ito2++){							// uses iterator to walk through elements of Tuesday
			if(it->first == ito2->second){
				(*ctr)++;
				if(*ctr == 1)
					cout << " Tuesday " << ito2->first;
				else
					cout << ito2->first;
			}
		}*ctr=0;												// Stores value at allocated address
		for(Courses::iterator ito2=Wednesday.begin(); ito2!=Wednesday.end(); ito2++){						// uses iterator to walk through elements of Wednesday
			if(it->first == ito2->second){
				(*ctr)++;
				if(*ctr == 1)
					cout << " Wednesday " << ito2->first;
				else
					cout << ito2->first;
			}
		}*ctr=0;												// Stores value at allocated address
		for(Courses::iterator ito2=Thursday.begin(); ito2!=Thursday.end(); ito2++){							// uses iterator to walk through elements of Thursday
			if(it->first == ito2->second){
				(*ctr)++;
				if(*ctr == 1)
					cout << " Thursday " << ito2->first;
				else
					cout << ito2->first;
			}
		}*ctr=0;												// Stores value at allocated address
		for(Courses::iterator ito2=Friday.begin(); ito2!=Friday.end(); ito2++){								// uses iterator to walk through elements of Friday
			if(it->first == ito2->second){
				(*ctr)++;
				if(*ctr == 1)
					cout << " Friday " << ito2->first;
				else
					cout << ito2->first;
			}
		}
		cout << endl;
	}
	delete ctr; 			// frees up the memory
}

/// Returns bool value for the correct situation
bool course::getResult(int counter) const{
	return x==counter;
}

/// Prints courseID and hour in 151214002 --> 8 hours format
void course::printCourseIDandHour(){
	// uses iterator to walk through elements of Coursee
	for(Courses::iterator it=Coursee.begin();it!=Coursee.end();it++)
		cout << setw(15) << it->first << " --> " << it->second << " hours" << endl;
	cout << endl;
}

/// Destructor
course::~course()
{
}
