# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact person[8];
		int		size;
	public:
		PhoneBook();
		~PhoneBook();
		void readLine(void);
		void displayTab(void);
		void contactInfo(int i);
};

# endif
