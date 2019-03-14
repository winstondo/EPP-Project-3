#pragma once
#include <string>

class Person
{
private:
	std::string firstName;
	std::string lastName;
	int employeeID;
	std::string companyName;
	float  hoursWorked;
	float  payRate;

public:
	Person();
	Person(std::string, std::string, int, std::string, float, float);
	~Person();
	void   setFirstName(std::string fName);
	std::string getFirstName();
	void   setLastName(std::string lName);
	std::string getLastName();
	void   setEmployeeId(int id);
	int    getEmployeeId();
	void   setCompanyName(std::string coName);
	std::string getCompanyName();
	void   setPayRate(float rate);
	float  getPayRate();
	void   setHoursWorked(float hours);
	float  getHoursWorked();
	float  totalPay();
	std::string fullName();
};


