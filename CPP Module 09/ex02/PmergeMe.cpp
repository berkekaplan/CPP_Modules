#include "PmergeMe.hpp"

std::list<int>		PmergeMe::_list;
std::vector<int>	PmergeMe::_vector;
int					PmergeMe::_insertSortingLimit = 100;

std::string PmergeMe::intToString( int num )
{

	std::stringstream ss;
	ss << num;
	return (ss.str());
}

void PmergeMe::checkArg( int argc, char **argv )
{
	if ( argc < 2 )
		throw PmergeMe::NotEnoughtInputs();

	for ( int i = 0; i < argc; i++ )
	{
		std::string str = argv[i];
		for (int k = 0; k < (int)str.length() ; k++)
		{
			if ( !std::isdigit(str[k]) )
				throw PmergeMe::WrongInputs();
		}
	}
}

void PmergeMe::setContainers(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		PmergeMe::_list.push_back(std::atoi(argv[i]));
		PmergeMe::_vector.push_back(std::atoi(argv[i]));
	}
}

double PmergeMe::measureTime(clock_t start, clock_t end)
{
	return (end - start);
}

/* ------------------------------------------------ List Methods ------------------------------------------------ */

bool PmergeMe::isListSorted(std::list<int>& list)
{
	if (list.empty() || list.size() == 1)
		return (true);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator next = it;

	++next;
	while (next != list.end())
	{
		if (*next < *it)
			return (false);
		++it;
		++next;
	}
	return (true);
}

void PmergeMe::printerList(std::string line)
{
	int l = 0;

	std::cout << line;
	for (std::list<int>::iterator i = _list.begin(); i != _list.end(); ++i, l++)
	{
		if (_list.size() > 10 && l == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *i;
		if (PmergeMe::ListGetNext(i) != _list.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

std::list<int>::iterator PmergeMe::ListGetNext(std::list<int>::iterator it)
{
	return ++it;
}

std::list<int>::iterator PmergeMe::ListGetPrev(std::list<int>::iterator it)
{
	return --it;
}

void PmergeMe::ListMergeSorting(std::list<int>& list, std::list<int>& left, std::list<int>& right )
{

	std::list<int>::iterator leftIt = left.begin();
	std::list<int>::iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end()) {
		if (*leftIt <= *rightIt) {
			list.push_back(*leftIt);
			++leftIt;
		} else {
			list.push_back(*rightIt);
			++rightIt;
		}
	}

	while (leftIt != left.end()) {
		list.push_back(*leftIt);
		++leftIt;
	}

	while (rightIt != right.end()) {
		list.push_back(*rightIt);
		++rightIt;
	}
}

void PmergeMe::ListInsertSorting( std::list<int>::iterator begin, std::list<int>::iterator end )
{
	for (std::list<int>::iterator it1 = begin; it1 != end; ++it1)
	{
		std::list<int>::value_type temp = *it1;
		std::list<int>::iterator it2 = it1;
		while (it2 != begin && *ListGetPrev(it2)  > temp)
		{
			*it2 = *ListGetPrev(it2);
			--it2;
		}
		*it2 = temp;
	}
}

void PmergeMe::ListMergeInsertSorting( std::list<int>& list )
{

	if ((int)list.size() <= _insertSortingLimit)
	{
		ListInsertSorting(list.begin(), list.end());
	}
	else
	{
		std::list<int> left, right;
		int mid = list.size() / 2;
		std::list<int>::iterator it = list.begin();
		for (int i = 0; i < mid; i++)
		{
			left.push_back(*it);
			++it;
		}
		while (it != list.end())
		{
			right.push_back(*it);
			++it;
		}

		ListMergeInsertSorting(left);
		ListMergeInsertSorting(right);

		list.clear();
		ListMergeSorting(list, left, right);
	}
}

void PmergeMe::sortListContainer( void )
{

	std::cout << CYAN "\n--------------------------------List Sorted--------------------------------------\n" << std::endl;
	PmergeMe::printerList("Before	(_list):	");
	clock_t start = clock();
	ListMergeInsertSorting(_list);
	clock_t end = clock();
	PmergeMe::printerList("After	(_list):	");
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list<int> : ";
	std::cout << PmergeMe::measureTime(start, end) << " us" << std::endl;
	std::cout << "List is " << (PmergeMe::isListSorted(_list) ? GREEN "sorted" : RED "not sorted") << END << std::endl;
}

/* ------------------------------------------------ Vector Methods ------------------------------------------------ */

bool PmergeMe::isVectorSorted(std::vector<int>& vector)
{
	if (vector.empty() || vector.size() == 1)
		return (true);

	for (std::vector<int>::size_type i = 1; i < vector.size(); ++i) {
		if (vector[i] < vector[i - 1]) {
			return false;
		}
	}
	return (true);
}

void PmergeMe::printerVector(std::string line)
{
	int l = 0;

	std::cout << line;
	for (std::vector<int>::iterator i = _vector.begin(); i != _vector.end(); ++i, l++)
	{
		if (_vector.size() > 10 && l == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *i;
		std::vector<int>::iterator l = i;
		++l;
		if (l != _vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::VectorInsertSorting( std::vector<int>& vector, int left, int right )
{

	for (int i = left + 1; i <= right; i++) {
		int key = vector[i];
		int j = i - 1;

		while (j >= left && vector[j] > key) {
			vector[j + 1] = vector[j];
			j--;
		}

		vector[j + 1] = key;
	}
}

void PmergeMe::VectorMergeSorting( std::vector<int>& vector, int left, int middle, int right )
{

	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = vector[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = vector[middle + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vector[k] = L[i];
			i++;
		} else {
			vector[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		vector[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		vector[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::VectorMergeInsertSorting( std::vector<int>& vector, int left, int right )
{

	if (right - left <= _insertSortingLimit)
	{
		VectorInsertSorting(vector, left, right);
	}
	else
	{
		int middle = left + (right - left) / 2;

		VectorMergeInsertSorting(vector, left, middle);
		VectorMergeInsertSorting(vector, middle + 1, right);

		VectorMergeSorting(vector, left, middle, right);
	}
}

void PmergeMe::sortVectorContainer( void )
{

	std::cout << BLUE "\n-------------------------------Vector Sorted-------------------------------------" << std::endl;
	PmergeMe::printerVector("\nBefore	(_vector):	");
	clock_t start = clock();
	VectorMergeInsertSorting(_vector, 0, _vector.size() - 1);
	clock_t end = clock();
	PmergeMe::printerVector("After	(_vector):	");
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<int> : ";
	std::cout << PmergeMe::measureTime(start, end) << " us" << std::endl;
	std::cout << "Vector is " << (PmergeMe::isVectorSorted(_vector) ? GREEN "sorted" : RED "not sorted") << END << std::endl << std::endl;
}
