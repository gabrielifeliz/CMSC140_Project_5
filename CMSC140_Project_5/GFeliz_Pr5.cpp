/*
* Class: CMSC140 CRN # 20780
* Instructor: Madvhi Shah
* Description: A program that calculates the average number of days
			a company's employees are absent during the year and outputs a report
			on a file named "employeeAbsences.txt".
* Due date: 11/14/2017
* Platform/Compiler: Windows 7, Microsoft Visual Studio 2015
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Gabriel I Feliz
*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//This function is in charge of asking the user for the number of employees in the company.
// The data type for this function is int because number of employees will be returned as an integer.
int employees()
{
	int numOfEmployees = 0;
	cout << "Please enter the number of employees in the company: ";
	cin >> numOfEmployees;
	/* Input validation for number of employees in the company. The program will continue
	asking the user to enter values greater than one until it gets the valid input*/
	while (numOfEmployees < 1)
	{
		cout << "The number of employees in the company may not be less than one. " << endl;
		cout << "Please enter the number of employees in the company: ";
		cin >> numOfEmployees;
	}
	// This statement ends the execution of the employee function.
	return numOfEmployees;
}

/* This function is in charge of calculating the average number of days absent
for all employees during the year*/

/* The data type for this function is double because average number of days absent
will be returned as a double precision number*/

/* Arguments accepted are total of days absent and number of employees.
Both arguments are integers and derived from employee and absences functions*/
double averageAbsences(int total_employee_DaysAbsent, int numOfEmployees)
{
	double avg_DaysAbsent;
	avg_DaysAbsent =
		// static_cast is used to convert the int variable to a double variable
		/* This is needed because at least one of the variables has to be double in a
		mathematical operation for a C++ program to display a double result*/
		static_cast<double>(total_employee_DaysAbsent) / numOfEmployees;
	// This statement ends the execution of the averageAbsences function.
	return avg_DaysAbsent;
}

/* This function is in charge of asking the user for employee ID and number of
days absent for each employee.
Then, data will be written to the report file.*/

/* The data type for this function is int because total of days absent
will be returned as an integer*/

/* Arguments accepted are days absent (of data type ofstream) and
number of employees (of data type int)*/
int absences(ofstream& daysAbsent, int numOfEmployees)
{
	int employee_ID, employee_DaysAbsent,
		// Initialized at zero to accumulate days absent from each employee
		total_employee_DaysAbsent = 0;

	// The program creates new file or opens an existing file named employeeAbsences.txt 
	daysAbsent.open("employeeAbsences.txt");
	// Data starts to be entered into the file, such as title of the report.
	daysAbsent << "EMPLOYEE  ABSENCE  REPORT  " << endl;
	daysAbsent << "Employee ID    Days absent " << endl;

	/* For loop is used to repeat asking the user for employee ID and days absent, ,
	depending on how many employees are entered in the employee function */
	for (int count = 0; count < numOfEmployees; count++)
	{
		cout << "Please enter an employee ID: ";
		cin >> employee_ID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> employee_DaysAbsent;
		/* Input validation for days absent in the company. The program will continue
		asking the user to enter values greater than or equal to zero until it gets the valid input*/
		while (employee_DaysAbsent < 0)
		{
			cout << "The number of days must not be negative." << endl;
			cout << "Please re-enter the number of days absent: ";
			cin >> employee_DaysAbsent;
		}
		// Once days absent is validated, this will be our running total for days absent
		total_employee_DaysAbsent += employee_DaysAbsent;
		/*Each employee ID and days absent are written to the report file */
		daysAbsent << setw(7) << right << employee_ID << setw(16) << right << employee_DaysAbsent << endl;
	}

	daysAbsent << endl;
	// Number of employees from employee function and completed running total are written to the report file
	daysAbsent << "The " << numOfEmployees << " employees were absent a total of " << total_employee_DaysAbsent << " days." << endl;
	// Average number of days absent is set to one place after the decimal point
	daysAbsent << "The average number of days absent is " << fixed << setprecision(1)
		<< averageAbsences(total_employee_DaysAbsent, numOfEmployees) << " days." << endl;
	daysAbsent << endl;
	daysAbsent << "Programmer: Gabriel I Feliz" << endl;

	cout << "Programmer: Gabriel I Feliz" << endl;
	system("pause");
	// This statement ends the execution of the averageAbsences function.
	return total_employee_DaysAbsent;
}

// This function is in charge of calling the previous three functions

// It accepts no arguments

int main()
{
	// Declaring local variables to call the functions
	int numOfEmployees, total_employee_DaysAbsent;
	double avg_DaysAbsent;
	ofstream daysAbsent;

	cout << "Calculate the average number of days a company's employees are absent. " << endl << endl;

	// employee function is called
	/* The value returned in the employee function is stored in
	local int variable numOfEmployees*/
	numOfEmployees = employees();

	// absences function is called
	/* The value returned in the absences function is stored in
	local int variable total_employee_DaysAbsent*/
	total_employee_DaysAbsent = absences(daysAbsent, numOfEmployees);

	// averageAbsences function is called
	/* The value returned in the averageAbsences function is stored in
	local double variable avg_DaysAbsent*/
	avg_DaysAbsent = averageAbsences(total_employee_DaysAbsent, numOfEmployees);

	// File closes
	daysAbsent.close();

	return 0;
}