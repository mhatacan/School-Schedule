/* ******************************************************* 
 * Filename		:	student.h
 * Author		:	Muhammet Harun ATACAN
 * Date			:	08.01.2021
 * Description	:	student Class Interface
 * ******************************************************/

/// prevents multiple inclusions of header
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>
#include "course.h"			/// includes definition of class course

using namespace std;

/// defines short name for multimap type used in this program
typedef multimap<string,int> Students;

/// student class definition
class student : public course
{
	public:
		
		/// Default Constructor	
		student(const string &Name = "");
		
		/// Sets name of the student
		void setName(const string &);
		
		/// Returns name of the student
		string getName() const;
		
		/// Adds the studentName in harun format to the multimap
		void addStudent();
		
		/// Adds the studentName and the courseID in harun 151214002 format they have chosen to the multimap if there are no negative conditions.
		void addStudentandCourseID(course &a);
		
		/// Prints the studentName and the courseID in harun --> 151214002, 151214003 format
		void printStudentandCourseID();
		
		/// Destructor
		~student();
	protected:
		
		/// Stores studentName
		string studentName;
		
		/// Stores studentName and courseID using multimap
		Students Studentt;
};
#endif
