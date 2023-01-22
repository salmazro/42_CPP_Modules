# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string number;
		std::string secret;

	public:
		Contact();
		~Contact();
		int filled;
		void setFirstName(std::string fname);
		std::string getFirstName();
		void setLastName(std::string lname);
		std::string getLastName();
		void setNickname(std::string nn);
		std::string getNickname();
		void setNumber(std::string num);
		std::string getNumber();
		void setSecret(std::string sec);
		std::string getSecret();
};

# endif
