


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include "Person.h"
//#include <set>
//#include <unordered_map>



std::vector<Person> readData(std::string );
//void getCompanies(std::vector<Person> &, std::vector<std::string> &);
typedef std::map<std::string, std::vector<Person>> comp_map;
void getCompanies(std::vector<Person> &, comp_map &);
//void getCompanies(std::vector<Person> &, std::multimap<std::string, Person> &);
//void getCompanies(std::vector<Person> &, std::unordered_multimap<std::string, Person> &);
void printHighestPaid(std::vector<Person> &);
void seperateAndSave(comp_map &);
void writeFile(std::vector<Person> &, std::string);
//debug func
void printEmployeeList(std::vector<Person> &);
void printcolist(comp_map &);
//void printcolist(std::unordered_multimap<std::string, Person> &);
//void printcolist(std::multimap<std::string, Person> &);


int main()
{
	std::vector<Person> employee;
	//std::unordered_multimap<std::string, Person> companyMap;
	comp_map companyMap;
	employee = readData("input.txt");	
	
	getCompanies(employee, companyMap);
	printcolist(companyMap);
	std::cout << std::endl;
	seperateAndSave(companyMap);
	//printHighestPaid(employee);


}

void printcolist(comp_map &comap)
{
	comp_map::iterator it;
	for (it = comap.begin(); it != comap.end(); ++it)
	{
		for (unsigned i = 0; i < it->second.size(); i++) {
			std::cout << it->second[i].getFirstName() << "\n";
		}
	}
}


void getCompanies(std::vector<Person> &elist, comp_map &comap)
{
	comp_map::iterator it;
	for (unsigned i = 0; i < elist.size(); i++)
	{
		it = comap.find(elist[i].getCompanyName());
		if (it == comap.end()) 
		//if the does NOT find the companies name amoung the map
		{
			//creates a new vector of persons 
			std::vector<Person> company_elist;
			company_elist.push_back(elist[i]);
			comap.emplace(elist[i].getCompanyName(), company_elist);
		}
		else
		{
			it->second.push_back(elist[i]);
		}
	}
}


void writeFile(std::vector<Person> &e, std::string filename)
{
	std::ofstream ofile(filename);
	//ofile.open(filename, std::ios::app);
	float total = 0;
	for (unsigned i = 0; i < e.size(); i++)
	{
		ofile << e[i].getFirstName() << " " << e[i].getLastName() << " eID: " << e[i].getEmployeeId() << " "
			<< e[i].getCompanyName() << " " << e[i].totalPay() << "\n";
		total += e[i].totalPay();
	}
	ofile << "TOTAL: $" << total << "\n";
}

void seperateAndSave(comp_map &comap)
{
	std::string filename;
	float totalpay = 0;
	comp_map::iterator it;
	for (it = comap.begin(); it != comap.end(); ++it)
	{
		filename = it->first + ".txt";
		writeFile(it->second, filename);
	}
	
}

//linear search
void printHighestPaid(std::vector<Person> &elist)
{
	float highestpay = 0;
	unsigned it;
	for (unsigned i = 0; i < elist.size(); i++) {
		if (elist[i].totalPay() > highestpay) {
			highestpay = elist[i].totalPay();
			it = i;
		}
	}
	std::cout << "Highest Paid: " << elist[it].getFirstName() << " " << elist[it].getLastName() << "\n"
			<< "Employee ID: " << elist[it].getEmployeeId() << "\n"
			<< "Employer: " << elist[it].getCompanyName() << "\n"
			<< "Total Pay: $" << elist[it].totalPay() << "\n";


}

//INPUT: takes a vector of persons (employee list), takes an unordered multimap (this is used as an "output")
//OUTPUT: none but writes to the unordered multimap that was passed in by reference as an argument
//takes the list of employees and adds it to an unordered multimap. the unordered multimap was chosen due to its lienency for collisions
//employee's with the same company are collisions and are grouped in the same group
//void getCompanies(std::vector<Person> &elist, std::unordered_multimap<std::string, Person> &comap)
//{
//	
//	for (unsigned i = 0; i < elist.size(); i++) {
//		comap.emplace(elist[i].getCompanyName(), elist[i]);
//	}
//}
//
//void getCompanies(std::vector<Person> &elist, std::multimap<std::string, Person> &comap)
//{
//	for (unsigned i = 0; i < elist.size(); i++) {
//		comap.emplace(elist[i].getCompanyName(), elist[i]);
//	}
//}
//
////overloaded debug fucntion that prints out the unordered map
//void printcolist(std::unordered_multimap<std::string, Person> &comap)
//{
//	std::unordered_map<std::string, Person>::iterator it;
//	for (it = comap.begin(); it != comap.end(); ++it)
//	{
//		std::cout << it->first << " " << it->second.getFirstName() << "\n";
//	}
//	 
//}
//
//void printcolist(std::multimap<std::string, Person> &comap)
//{
//	std::multimap<std::string, Person>::iterator it;
//	for (it = comap.begin(); it != comap.end(); ++it)
//	{
//		std::cout << it->first << " " << it->second.getFirstName() << "\n";
//	}
//
//}
//
////void getCompanies(std::vector<Person> &empl, std::vector<std::string> &co_list)
////{
////	for (unsigned i = 0; i < empl.size(); i++)
////	{
////		co_list.push_back(empl[i].getCompanyName());
////	}
////}
//
void printEmployeeList(std::vector<Person> &employee)
{
	for (unsigned i = 0; i < employee.size(); i++) {
		std::cout << employee[i].getFirstName() << " " << employee[i].getLastName() << " eID: " << employee[i].getEmployeeId()
			<< "\n " << employee[i].getCompanyName() << " hrs_wrk: " << employee[i].getHoursWorked() << " || pay rate: " << employee[i].getPayRate() << "\n";
	}
}

std::vector<Person> readData(std::string filename)
{
	std::vector<Person> employee;
	
	std::string fName, lName, coName;
	int coID;
	float payrate, hrswrk;
	std::ifstream ifile(filename);
	while (ifile >> fName && ifile >> lName && ifile >> coID && ifile >> coName && ifile >> payrate && ifile >> hrswrk)
	{
		Person p(fName, lName, coID, coName, payrate, hrswrk);
		employee.push_back(p);
	}
	return employee;
	
}