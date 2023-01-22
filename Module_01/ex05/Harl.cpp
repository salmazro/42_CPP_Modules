#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<std::endl;
}
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" <<std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." <<std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;
}

void Harl::wrong(void)
{
	std::cout << "Invalid Complain" <<std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*ptr)(void);

	ptr = &Harl::wrong;
	(!level.compare("DEBUG") && (ptr = &Harl::debug));
	(!level.compare("INFO") && (ptr = &Harl::info));
	(!level.compare("WARNING") && (ptr = &Harl::warning));
	(!level.compare("ERROR") && (ptr = &Harl::error));
	(this->*ptr)();
}
