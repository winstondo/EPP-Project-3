#include "Person.h"


//Default Constructor
Person::Person()
	:firstName("f_name"),lastName("l_name"),employeeID(0),companyName("co_name"),hoursWorked(0.0),payRate(0.0)
{

}


//Overloaded Default constructor with the class variables passed in as arguments
Person::Person(std::string f_name, std::string l_name, int id, std::string co_name, float hrs, float payrate)
	:firstName(f_name), lastName(l_name), employeeID(id), companyName(co_name), hoursWorked(hrs), payRate(payrate)
{

}


Person::~Person()
{
}

void Person::setFirstName(std::string fName) {firstName = fName;}

std::string Person::getFirstName() {return firstName;}

void Person::setLastName(std::string lName)	 {lastName = lName;}

std::string Person::getLastName()	{return lastName;}

void Person::setEmployeeId(int id)	{employeeID = id;}

int Person::getEmployeeId() {return employeeID;}

void Person::setCompanyName(std::string coName)	{companyName = coName;}

std::string Person::getCompanyName()	{return companyName;}

void Person::setPayRate(float rate) {payRate = rate;}

float Person::getPayRate() { return payRate; }

float Person::getHoursWorked() { return hoursWorked; }

void Person::setHoursWorked(float hrswrk) { hoursWorked = hrswrk; }

float Person::totalPay()
{
	return payRate * hoursWorked;
}

std::string Person::fullName()
{
	return firstName + " " + lastName;
}

