#include <iostream>
#include <string>


using namespace std;


class	Person
{
public:
	bool	mean; //true	means	they	are	mean,	false	they	are	not	mean
	bool	stung; //true	means	they	got	stung,	false	means	they	did	not	get	stung
	Person(bool	mean)
	{
		this->mean = mean;
		stung = false; //all	people	start	out	not	being	stung
	}
};






class	Bee 
{
public:
	virtual	bool sting(Person& p) = 0;
};//inherit the two classes with public access, access wether person is mean and change the stung (not sting) accordingly
//change the action of the bee which is "sting" from 0 to 1 accordingly


class Friendly_bee :public Bee
{	
public:

	string answer;
	
	bool sting(Person& p)
	{
		if (p.mean == true)
		{
			cout << "\n-----\nFriendly bee says: Hello! :) If you stop being mean, I won't sting you. Will you stop being mean?" << endl;
			getline(cin, answer);

			if (answer == "no")
			{
				cout << "------\nFriendly bee says: Sorry, but then I have no choice but to sting you! :(\n" << endl;

				

				p.stung = true;
				return 1;
			}
			else
			{
				cout << "Ok, I won't sting you!\n" << endl;
				return 0;
			}


		}
		else
		{
			cout << "-----\nFriendly bee says: Hello! :) You're not mean, so I won't sting you!\n" << endl;
		}

		return 0;

	}

};


class Mean_bee:public Bee
{
public:
	string answer;

	bool sting(Person& p)
	{
		if (p.mean == true)//
		{
			cout << "-----\nMean bee says: You're mean like me so I have to sting you!\n" << endl;
			p.stung = true;
		

		}
		else
		{
			cout << "-----\nMean bee says: Sorry but I have to sting you even if you are nice...\n" << endl;
			p.stung = true;

		}

		return 1;

	}

};










int	main(int	argc, char** argv) {
	Person	p(true);
	Person	p2(false);
	Person	p3(true);
	Person	p4(false);
	cout << "p:	mean-" << p.mean << ",	stung-" << p.stung << endl;
	cout << "p2:	mean-" << p2.mean << ",	stung-" << p2.stung << endl;
	cout << "p3:	mean-" << p3.mean << ",	stung-" << p3.stung << endl;
	cout << "p4:	mean-" << p4.mean << ",	stung-" << p4.stung << endl;
	Friendly_bee	b1;
	Mean_bee	b2;
	b1.sting(p);
	b1.sting(p2);
	b2.sting(p3);
	b2.sting(p4);
	cout << "p:	mean-" << p.mean << ",	stung-" << p.stung << endl;
	cout << "p2:	mean-" << p2.mean << ",	stung-" << p2.stung << endl;
	cout << "p3:	mean-" << p3.mean << ",	stung-" << p3.stung << endl;
	cout << "p4:	mean-" << p4.mean << ",	stung-" << p4.stung << endl;
}