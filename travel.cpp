#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include<fstream>
using namespace std;

class Country
{
public:
	string answer;
	string country_name;
	int population;
	int ticket_price;

	Country(string country_name, int population)
	{
		this->country_name = country_name;
		this->population = population;
		cout << "Creating country object..." << endl;

	}

	virtual int get_ticket_price(string name)
	{

		if (name == "Pinoy Traveler" && country_name=="Phillipines")
		{
			ticket_price = 100;
		}
		else
		{
			ticket_price = population * 5;
		}

		return ticket_price;
	}

	virtual void print_boarding_pass(string person_name)
	{

		stringstream ss(person_name);
		string first_name;
		string last_name;
		string filler = "boarding.txt";
		ss >> first_name >> last_name;
		string output_filename = first_name+filler;
		ofstream outfile(output_filename);
		if (!outfile.is_open())
		{
				cout << "unsucessful attempt at opening this file" << endl;
		}
			outfile << "Passenger name " << person_name << endl;
			outfile << "Destination " << country_name << endl;
			outfile << "---Enjoy Asia!---" << endl;



	}

};

class Asian_Country:public Country
{
public:
	Asian_Country(string country_name, int population) :Country(country_name, population)
	{

	}


};

class African_Country:public Country
{
public:
	string area;

	African_Country(string country_name, int population):Country(country_name, population)
	{
		cout << "Does Tunisia lie in the north, south, east or west Africa?" << endl;
		getline(cin, area);

		while (1)//loop is true until told to break
		{

			if (area == "north" || area=="south"||area=="east"||area=="west")
			{
				break;
			}
			cout << "Please enter a valid loacation:" << endl;
			getline(cin, area);

		}


	}


	int get_ticket_price(string person_name)
	{

		if (person_name == "Moe Traveler" && area == "north")
		{
			ticket_price = 100;

		}
		else
		{
			ticket_price = (population * 3) + 1000;
		}

		return ticket_price;

	}

	void print_boarding_pass(string person_name)
	{

		stringstream ss(person_name);
		string first_name;
		string last_name;
		string filler = "boarding.txt";
		ss >> first_name >> last_name;
		string output_filename = first_name+filler;
		ofstream outfile(output_filename);
		if (!outfile.is_open())
		{
				cout << "unsucessful attempt at opening this file" << endl;
		}

		outfile << "Passenger name " << person_name << endl;
		outfile << "Destination " << country_name << endl;
		outfile << "---Enjoy "<<area<<" Africa!---" << endl;





	}





};


int main(int argc, char** argv)
{

	Asian_Country a1("Phillipines", 109);
	African_Country a2("Tunisia", 11);

	string country;
	string person_name;
	string answer;



	while (1)
	{
		cout << "Do you want to go to the Phillipines or Tunisia?" << endl;
		getline(cin, country);
		if (country == "exit")
		{
			exit(0);
		}
		cout << "Enter your full name:" << endl;
		getline(cin, person_name);

		if (country == "Phillipines")
		{
			cout<<"Ticket price will be: "<<a1.get_ticket_price(person_name)<<" Do you still want to go?"<<endl;
			getline(cin, answer);
			if (answer == "yes")
			{
				a1.print_boarding_pass(person_name);
				cout <<"Boarding Pass Printed!\n"  << endl;

			}
		}
		else
		{
			cout << "Ticket price will be $" << a2.get_ticket_price(person_name) <<" Do you still want to go?" <<endl;
			getline(cin, answer);
			if (answer == "yes")
			{
				a2.print_boarding_pass(person_name);
				cout <<"Boarding Pass Printed!\n"<< endl;

			}

		}
	}



}
