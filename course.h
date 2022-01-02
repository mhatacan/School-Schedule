/* ******************************************************* 
 * Filename		:	course.h
 * Author		:	Muhammet Harun ATACAN
 * Date			:	08.01.2021
 * Description	:	course Class Interface
 * ******************************************************/

/// prevent multiple inclusions of header
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <map>

using namespace std;

/// defines short name for map type used in this program
typedef map<int,int> Courses;

/// course class definition
class course
{
	/// determines friend to student class to read map data from course class
	friend class student;
	
	public:
		
		/// Default Constructor	
		course(int COURSEID=0, int HOUR=0);
		
		/// Set functions
		/// Sets ID of the course
		void setcourseID(int);
		
		/// Sets hour of the course
		void sethour(int);
		
		/// Gets functions should be const
		/// Returns ID of the course
		int getcourseID() const;
		
		/// Returns hour of the course
		int gethour() const;
		
		/// Returns bool value for the correct situation
		bool getResult(int) const;
		
		/// Adds courseID and hour in 151214002 8 format
		void addCourse();
		
		/// Prints courseID and hour in 151214002 --> 8 hours format
		void printCourseIDandHour();
		
		/// Makes schedule starting from Monday to Friday and everyday have 6 slots
		void makeSchedule();
		
		/// Prints schedule in 151214002 --> Monday123456 Tuesday12 format
		void printSchedule(Courses, Courses, Courses, Courses, Courses);
		
		/// Defines variable
		int x;
		
		/// Destructor
		~course();
	protected:
		
		/// Stores courseID
		int courseID;
		
		/// Stores hour
		int hour;
		
		/// Stores courseID and hour using map
		Courses Coursee;
};
#endif
