#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <time.h>
#include <iterator>

template <typename T>
void print(const std::vector<T>& v)
{
	for(auto x: v)
		std::cout << x << ", ";
	std::cout << "\n";
}

template <typename T>
void print(const std::list<T>& v)
{
	for(auto x: v)
		std::cout << x << ", ";
	std::cout << "\n";
}

void sort()
{
	std::vector<uint32_t> v = {22, 3, 1, 14, 34, 8, 90, 43};
	print(v);
	//template< class RandomIt > void sort( RandomIt first, RandomIt last );
	std::sort(begin(v), end(v));
	print(v);
}

void partial_sort()
{
	std::vector<uint32_t> v = {22, 3, 1, 14, 34, 8, 90, 43};
	print(v);
	//template< class RandomIt > void partial_sort( RandomIt first, RandomIt middle, RandomIt last );
	std::partial_sort(v.begin(), v.begin()+5, v.end());	//partial sorting first 5 elements
	print(v);
}

void nth_element()
{
	std::vector<uint32_t> v2 = {22, 21, 20, 17, 18, 19, 66, 15};
	print(v2);
	//template< class RandomIt > void nth_element( RandomIt first, RandomIt nth, RandomIt last );
	std::nth_element(v2.begin(), v2.begin()+3, v2.end());		//4th position in the sequence
	print(v2);
}

void copy()
{
	uint32_t arr[] = {34, 12, 54, 6, 76, 7};
	std::vector<uint32_t> v(6);
	//template< class InputIt, class OutputIt > OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
	std::copy(arr, arr+6, v.begin());	//Copies the elements in the range [first,last) into the range beginning at result.
	print(v);
	
	std::vector<int> v1(6);
	std::vector<int> v2 = {2,3,4,5,6,7,8,9};
	std::copy(v2.begin()+v2.size()/2, v2.end(), v1.begin());
	print(v1);
}

void inplace_merge()
{
	uint32_t arr[] = {34, 12, 54, 6, 76, 7};
	uint32_t arr2[] = {21, 22, 4, 61, 6, 17};
	std::vector<uint32_t> v(12);
	
	std::sort(arr, arr+6);			// sorting individual halves first
	std::sort(arr2, arr2+6);
	
	auto it = std::copy(arr, arr+6, v.begin());
	std::copy(arr2, arr2+6, it);
	//template< class BidirIt > void inplace_merge( BidirIt first, BidirIt middle, BidirIt last );
	std::inplace_merge(v.begin(), v.begin()+6, v.end());
	print(v);
}

struct DivisibleBy7
{
	bool operator() (int x) { return x%7 == 0; }
};

void partition()
{
	std::vector<uint32_t> v = {3,2,14,5,56,70,5,42,35};
	print(v);
	//template< class BidirIt, class UnaryPredicate > BidirIt partition( BidirIt first, BidirIt last, UnaryPredicate p );
	//std::partition(v.begin(), v.end(), DivisibleBy7());
	std::partition(v.begin(), v.end(), [](int x){ return x%7 == 0; });
	print(v);
}

void rotate()
{
	std::vector<uint32_t> v = {3,2,14,5,56,70,5,42,35};
	print(v);
	//template< class ForwardIt > void rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );
	std::rotate(v.begin(), v.begin()+3, v.end());
	print(v);
}

void shuffle()
{
	std::vector<uint32_t> v = {1,2,3,4,5,6,7,8};
	print(v);
    std::mt19937 g(time(nullptr));
	std::shuffle(v.begin(), v.end(), g);
	print(v);
}

void permutation()
{
	std::vector<uint32_t> v = {1,2,3,4,5,6,7,8};
	print(v);
	//template< class BidirIt > bool next_permutation( BidirIt first, BidirIt last );
	std::next_permutation(v.begin(), v.end());
	print(v);
	std::next_permutation(v.begin(), v.end());
	print(v);
	std::prev_permutation(v.begin(), v.end());
	print(v);
	std::reverse(v.begin(), v.end());
	print(v);
}

void list_splice()
{
	std::list<int> list1 = {1,2,3,4,5};
	std::list<int> list2 = {10,11,12,13,14};
	list1.splice(std::find(list1.begin(), list1.end(), 3), 
				list2, 
				std::find(list2.begin(), list2.end(), 11), 
				std::find(list2.rbegin(), list2.rend(), 13).base());
	print(list1);
}

void list_iterator()
{
	std::list<uint32_t> li = {1,2,3,4,5,6,7,8};
	//std::cout << li[2] << "\n";				// list does not support [], random_access_iterator. It is traversed by a bidirectional_iterator
	//li.insert(li.begin()+2, 23);				// bidirectional takes one step at a time (like forward_iterator/input_iterator/output_iterator) & unlike random_access_iterator
	std::list<uint32_t>::iterator itr = li.begin();
	std::advance(itr, 2);
	li.insert(itr, 23);
	print(li);
}

struct LessThan3
{
	bool operator()(const int& num)
	{
		return num < 3;
	}
};

struct SumLessThan3
{
	int operator()(int& s, const int& n)
	{
		if (n < 3) s+=n;
		return s;
	}
};

template<typename Iter>
typename Iter::value_type acm(Iter start, Iter end)
{
	typename Iter::value_type result = 0;
	for(; start != end; start++)
		result += *start;
	return result;
}

void summing()
{
	std::list<int> list1 = {3,2,3,4,5, 3, 2, 12, 3};
	int cnt = std::count(list1.begin(), list1.end(), 3);
	std::cout << "Occurence: "<< cnt << "\n";
	//int cond_cnt = std::count_if(list1.begin(), list1.end(), LessThan3());
	int cond_cnt = std::count_if(list1.begin(), list1.end(), [](int num){ return num < 3; });
	std::cout << "Condition Occurence: "<< cond_cnt << "\n";
	//int sum = std::accumulate(list1.begin(), list1.end(), 0, SumLessThan3());
	int sum = acm(list1.begin(), list1.end());

	std::cout << "Sum: "<< sum << "\n";
}

void remove()
{
	std::vector<uint32_t> v = {4,2,3,4,5,4,7,8};
	std::copy(v.begin(), v.end(), std::ostream_iterator<uint32_t>(std::cout, ", "));
	// template< class ForwardIt, class T > ForwardIt remove( ForwardIt first, ForwardIt last, const T& value );
	std::remove(v.begin(), v.end(), 4);	//remove only shunts non-deleted elements forwards on top of deleted elements
	print(v);
}

void iota_fill()
{
	std::vector<int> v;
	v.resize(10);
	// template< class ForwardIt, class T > void iota( ForwardIt first, ForwardIt last, T value );
	std::iota(begin(v), end(v), 11);	
	print(v);
	// template< class ForwardIt, class T > void fill( ForwardIt first, ForwardIt last, const T& value );
	std::fill(begin(v), end(v), 12);
	print(v);
}

void adjacent_find()
{
	std::vector<int> v(10);
	std::iota(begin(v), end(v), 11);
	print(v);
	
	bool found = std::binary_search(v.begin(), v.end(), 123);
	std::cout << std::boolalpha << found << "\n";
	
	v[4] = 14;
	// template< class ForwardIt > ForwardIt adjacent_find( ForwardIt first, ForwardIt last );
	auto itr = std::adjacent_find(begin(v), end(v));
	if(itr != v.end())
	std::cout << *itr << "\n";
	
	auto itrPair = std::equal_range(v.begin(), v.end(), 14);
	for(auto i = itrPair.first; i != itrPair.second; ++i)
		std::cout << std::distance(v.begin(), i) << " ";
	
	v[3] = 2;
	// template< class ForwardIt, class BinaryPredicate> ForwardIt adjacent_find( ForwardIt first, ForwardIt last, BinaryPredicate p );
	itr = std::adjacent_find(begin(v), end(v), std::greater<int>());
	if(itr != v.end())
	std::cout << "\n" << *itr << "\n";
}

void lexicographical_compare()
{
	std::string str1 = "Shobhit";
	std::string str2 = "Shanky";
	bool order = std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end());
	if(order)
	std::cout << str1 << " is lexicographically less than " << str2;
	else
	std::cout << str1 << " is not lexicographically less than " << str2;
}

void transform()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
	auto square = [](int x){return pow(x, 2); };
	print(v);
	std::transform(v.begin(), v.end(), v.begin(), square);
	print(v);
}

int main()
{	
	//sort();
	//partial_sort();
	//nth_element();
	//copy();
	//inplace_merge();
	//partition();
	//rotate();
	//shuffle();
	//permutation();
	//list_splice();
	//list_iterator();
	//summing();
	//remove();
	iota_fill();
	//adjacent_find();
	//lexicographical_compare();
	//transform();
	return 0;
}