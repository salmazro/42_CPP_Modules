#include "PmergeMe.hpp"

// Constructor that initializes PmergeMe with a vector of vectors
PmergeMe::PmergeMe(std::vector<std::vector<int> > argv)
{
	// Initialize the args member with the provided vector of vectors
	this->args = argv;

	// Call the fill() function to populate vectorStack and listStack with data
	fill();

	// Display the elements of vectorStack before sorting
	std::cout << "Before: ";
	for (size_t i =0; i < vectorStack.size(); i++)
		std::cout<< " " <<vectorStack[i];
	std::cout << std::endl;

	// Measure the time taken to perform the Ford-Johnson sort on vectorStack
	struct timeval startT,endT;
	gettimeofday(&startT,NULL);
	fordJohnsonSortVec(vectorStack,0,vectorStack.size() - 1);
	gettimeofday(&endT, NULL);

	// Display the elements of vectorStack after sorting and the time taken
	std::cout << "After: ";
	for (size_t i =0; i < vectorStack.size(); i++)
		std::cout<< " " <<vectorStack[i];
	std::cout << std::endl;
	std::cout <<"Time it took to sort vectorStack: "<< (endT.tv_sec * 1000000 + endT.tv_usec) - (startT.tv_sec * 1000000 + startT.tv_usec) << " us" << std::endl;

	// // Display a separator
	// std::cout << "-----------------------------------" << std::endl;

	// Measure the time taken to perform the Ford-Johnson sort on listStack
	struct timeval startL,endL;
	gettimeofday(&startL,NULL);
	fordJohnsonSortList(listStack,0,listStack.size() - 1);
	gettimeofday(&endL,NULL);

	// Display the elements of listStack after sorting and the time taken
	// std::cout << "After list: ";
	// std::list<int>::iterator it = listStack.begin();
	// for (; it != listStack.end(); it++)
	// 	std::cout<< " " <<*it;
	// std::cout << std::endl;
	std::cout <<"Time it took to sort listStack: "<< (endL.tv_sec * 1000000 + endL.tv_usec) - (startL.tv_sec * 1000000 + startL.tv_usec) << " us" << std::endl;
}

// Copy constructor that creates a deep copy of the PmergeMe object
PmergeMe::PmergeMe(PmergeMe const &copy)
{
	// Copy the vectorStack data
	this->vectorStack = copy.vectorStack;

	// Copy the listStack data
	this->listStack = copy.listStack;

	// Copy the args data, creating a new instance of the vector of vectors
	this->args = copy.args;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Assignment operator overload that assigns the content of one PmergeMe object to another
PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	// Check for self-assignment
	if (this != &copy)
	{
		// Copy the vectorStack data from the source object
		// Note: listStack and args are not updated, only vectorStack is copied
		this->vectorStack = copy.vectorStack;
	}

	// Return the updated object
	return (*this);
}

// Function to populate vectorStack and listStack with values from args
void	PmergeMe::fill()
{
	for (size_t i = 0; i < this->args.size(); i++)
	{
		for (size_t j = 0; j < this->args[i].size(); j++)
		{
			// Check if the value is negative
			if (args[i][j] < 0)
			{
				std::cout << "the numbers is negative" << std::endl;
				exit(0);
			}

			// Check if the value is outside the range of INT_MIN to INT_MAX
			if (args[i][j] > INT_MAX || args[i][j] < INT_MIN)
			{
				std::cout << "Error: value not in range" << std::endl;
				exit(1);
			}

			// Check for duplicate numbers in vectorStack
			if (std::find(vectorStack.begin(), vectorStack.end(), args[i][j]) != vectorStack.end())
			{
				std::cout << "Duplicate number found: " << args[i][j] << std::endl;
				exit(0);
			}

			// Add the value to both vectorStack and listStack
			vectorStack.push_back(args[i][j]);
			listStack.push_back(args[i][j]);
		}
	}

	// Check if the stacks have at least two arguments
	if (vectorStack.size() <= 1 || listStack.size() <= 1){
		std::cout << "Error insert more than one argument" << std::endl;
		return;
	}
}

// Function to merge subarrays in a list
void	PmergeMe::merge(std::list<int>& arr, int left, int mid, int right)
{
	// Calculate the size of the left subarray
	int leftSize = mid - left + 1;

	// Calculate the size of the right subarray
	int rightSize = right - mid;

	// Create a temporary list for the left subarray
	std::list<int> leftArr;

	// Create a temporary list for the right subarray
	std::list<int> rightArr;

	// Create iterators to traverse the original list to extract subarrays
	std::list<int>::iterator it = arr.begin();

	// Move the iterator to the starting position of the left subarray
	std::advance(it, left);

	// Copy elements from the original list to the leftArr
	for (int i = 0; i < leftSize; ++i)
	{
		leftArr.push_back(*it);
		std::advance(it, 1);
	}

	// Copy elements from the original list to the rightArr
	for (int j = 0; j < rightSize; ++j)
	{
		rightArr.push_back(*it);
		std::advance(it, 1);
	}

	// Create iterators for leftArr, rightArr, and the original list
	std::list<int>::iterator leftIt = leftArr.begin();
	std::list<int>::iterator rightIt = rightArr.begin();
	std::list<int>::iterator arrIt = arr.begin();

	// Move the iterator to the starting position of the merge
	std::advance(arrIt, left);

	// Merge the left and right subarrays back into the original list
	while (leftIt != leftArr.end() && rightIt != rightArr.end())
	{
		if (*leftIt <= *rightIt)
		{
			*arrIt = *leftIt;
			++leftIt;
		}

		else
		{
			*arrIt = *rightIt;
			++rightIt;
		}

		++arrIt;
	}

	// Copy any remaining elements from leftArr to the original list
	while (leftIt != leftArr.end())
	{
		*arrIt = *leftIt;
		++leftIt;
		++arrIt;
	}

	// Copy any remaining elements from rightArr to the original list
	while (rightIt != rightArr.end())
	{
		*arrIt = *rightIt;
		++rightIt;
		++arrIt;
	}
}

// Function to perform the Ford-Johnson sort on a list
void	PmergeMe::fordJohnsonSortList(std::list<int>& number, int left, int right)
{
	// Check if there are more than one element in the subarray
	if (left < right)
	{
		// Calculate the middle index of the subarray
		int midd = (left + right) / 2;

		// Recursively sort the left and right halves of the subarray
		fordJohnsonSortList(number, left, midd);
		fordJohnsonSortList(number, midd + 1, right);

		// Merge the sorted subarrays to achieve the final sorted result
		merge(number, left, midd, right);
	}
}

// Function to merge subarrays in a vector
void	PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
	// Calculate the size of the left subarray
	int leftSize = mid - left + 1;

	// Calculate the size of the right subarray
	int rightSize = right - mid;

	// Create temporary vectors for the left and right subarrays
	std::vector<int> leftArr(leftSize);
	std::vector<int> rightArr(rightSize);

	// Copy elements from the original vector to the leftArr
	for (int i = 0; i < leftSize; ++i)
	{
		leftArr[i] = arr[left + i];
	}

	// Copy elements from the original vector to the rightArr
	for (int j = 0; j < rightSize; ++j)
	{
		rightArr[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	// Merge the left and right subarrays back into the original vector
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			++i;
		}

		else
		{
			arr[k] = rightArr[j];
			++j;
		}

		++k;
	}

	// Copy any remaining elements from leftArr to the original vector
	while (i < leftSize)
	{
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	// Copy any remaining elements from rightArr to the original vector
	while (j < rightSize)
	{
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}

// Function to perform the Ford-Johnson sort on a vector
void	PmergeMe::fordJohnsonSortVec(std::vector<int> &number, int left, int right)
{
	// Check if there are more than one element in the subarray
	if (left < right)
	{
		// Calculate the middle index of the subarray
		int midd = (left + right) / 2;

		// Recursively sort the left and right halves of the subarray
		fordJohnsonSortVec(number, left, midd);
		fordJohnsonSortVec(number, midd + 1, right);

		// Merge the sorted subarrays to achieve the final sorted result
		merge(number, left, midd, right);
	}
}
