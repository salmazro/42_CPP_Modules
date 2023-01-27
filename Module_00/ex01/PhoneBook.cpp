#include "PhoneBook.hpp"

// constructor
PhoneBook::PhoneBook()
{
	size = 0;
}

// destructor
PhoneBook::~PhoneBook()
{
}

void print_table(void)
{
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

std::string Layout(std::string str)
{
	if (str.length() > 10)
	{
		std::string less = str;
		less.resize(9);
		less.append(".");
		return (less);
	}
	return(str);
}

void PhoneBook::readLine(void)
{
	std::string com;
	int i = 0;

	while (1)
	{
		std::cout << "\nChoose one of the below options:\n";
		std::cout << "1. ADD: Save a new contact\n";
		std::cout << "2. SEARCH: Display a specific contact\n";
		std::cout << "3. EXIT: Close the application\n";
		getline(std::cin, com);
		// Ctrl D detected, Exiting the program ....
		if(std::cin.eof())
			break;
		if (com == "EXIT")
			break;
		else if (com == "SEARCH")
		{
			std::string tab;
			print_table();
			displayTab();
			std::cout << "\nEnter 1 for full user information\nEnter 0 for previous menu\n";
			getline(std::cin, tab);
			if (tab == "1")
			{
				std::string st1 = "";
				std::cout << "Enter index number: ";
				getline(std::cin, st1);
				int choice;
				choice = atoi(st1.c_str());
				if (!(isdigit(st1[0])) && choice == 0)
					std::cout << "\nNot an index. Try again" << std::endl;
				else if (choice < 0 || choice >= size)
				{
					std::cout << "\nOut of range. Try again" << std::endl;
				}
				else
					contactInfo(choice);
			}
			else if (tab == "0")
				;
			else
				std::cout << "\nInvalid entry back to main page" << std::endl;
		}
		else if (com == "ADD")
		{
			std::string temp = "";
			do
			{
				std::cout << "\nEnter first name: ";
				getline(std::cin, temp);
			}while(temp.size() < 1);
			person[i].setFirstName(temp);
			do
			{
				std::cout << "Enter last name: ";
				getline(std::cin, temp);
			}while(temp.size() < 1);
			person[i].setLastName(temp);
			do
			{
				std::cout << "Enter nickname: ";
				getline(std::cin, temp);
			}while(temp.size() < 1);
			person[i].setNickname(temp);
			do
			{
				std::cout << "Enter phone number: ";
				getline(std::cin, temp);
			}while(temp.size() < 1);
			person[i].setNumber(temp);
			do
			{
				std::cout << "Enter darkest secret: ";
				getline(std::cin, temp);
			}while(temp.size() < 1);
			person[i].setSecret(temp);
			person[i].filled = 1;
			i = (i + 1) % 8;
			size = (size + 1) % 8;
		}
		else
			std::cout << "\nPlease try again!!" << std::endl;

	}
}

void PhoneBook::displayTab(void)
{

	for (int i = 0; i < 8 ; i++)
	{
		if (person[i].filled == 1)
		{
			std::cout << std::right << "|" << std::setw(10) << i << "|";
			std::cout << std::right << std::setw(10) << Layout(person[i].getFirstName()) << "|";
			std::cout << std::right << std::setw(10) << Layout(person[i].getLastName()) << "|";
			std::cout << std::right << std::setw(10) << Layout(person[i].getNickname()) << "|"<<std::endl;
			std::cout << "|__________|__________|__________|__________|" << std::endl;
		}

	}
}

void PhoneBook::contactInfo(int i)
{
	std::cout <<"Name: " << person[i].getFirstName() << " ";
	std::cout << person[i].getLastName() << std::endl;
	std::cout << "Nickname: " << person[i].getNickname() << std::endl;
	std::cout << "Phone number: " << person[i].getNumber() << std::endl;
	std::cout << "Secret: " << person[i].getSecret() << std::endl;

}

int main (void)
{
	PhoneBook obj;
	obj.readLine();
	return (0);
}
