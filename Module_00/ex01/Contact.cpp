#include "Contact.hpp"
// constructor
Contact::Contact()
{
	filled = 0; // 0-> filled // 1-> empty filled
}

// destructor
Contact::~Contact()
{
}

// Setter Methods
void Contact::setFirstName(std::string fname)
{
	this->firstName = fname;
}
void Contact::setLastName(std::string lname)
{
	this->lastName = lname;
}
void Contact::setNickname(std::string nn)
{
	this->nickname = nn;
}
void Contact::setNumber(std::string num)
{
	this->number = num;
}
void Contact::setSecret(std::string sec)
{
	this->secret = sec;
}

// Getter Methods
std::string Contact::getFirstName()
{
	return(this->firstName);
}
std::string Contact::getLastName()
{
	return(this->lastName);
}
std::string Contact::getNickname()
{
	return(this->nickname);
}
std::string Contact::getNumber()
{
	return(this->number);
}
std::string Contact::getSecret()
{
	return(this->secret);
}
