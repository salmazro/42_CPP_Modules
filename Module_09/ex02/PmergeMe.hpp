#ifndef PMERGEME
#define PMERGEME

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <list>
#include <sys/time.h>
#include <sstream>

class PmergeMe
{
	private:

		// Vector to store integers
		std::vector<int> vectorStack;

		// List to store integers
		std::list<int>  listStack;

		// Vector of vectors to store arguments
		std::vector<std::vector<int> >  args;

	public:

		// Constructor that initializes PmergeMe with a vector of vectors
		PmergeMe(std::vector<std::vector<int> > argv);

		// Copy constructor
		PmergeMe(PmergeMe const &copy);

		// Destructor
		~PmergeMe();

		// Assignment operator overload
		PmergeMe &operator=(PmergeMe const &copy);

		// Function to fill vectorStack and listStack with data
		void	fill();

		// Function to perform the Ford-Johnson sort on a vector
		void	fordJohnsonSortVec(std::vector<int> &number, int left, int right);

		// Function to perform the Ford-Johnson sort on a list
		void	fordJohnsonSortList(std::list<int> &number, int left, int right);

		// Function to merge subarrays in a vector
		void	merge(std::vector<int> &number, int left, int midd, int right);

		// Function to merge subarrays in a list
		void	merge(std::list<int> &number, int left, int midd, int right);
};

#endif
