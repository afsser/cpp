#include <iostream>
#include <MutantStack.hpp>
#include "colors.hpp"
#include <list>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>

int main()
{
    // std::srand(std::time(0));
    std::cout << ORG "=== SUBJECT TEST with MutantStack ===" RST << std::endl;
    {
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
    }
    std::cout << std::endl;
    std::cout << ORG "=== SUBJECT TEST with List ===" RST << std::endl;
    {
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(lst);
        
    }
    std::cout << std::endl;
    std::cout << ORG "=== METHODS TEST ===" RST << std::endl;
    {
		std::cout << YEL "MutantStack" RST << std::endl;
		MutantStack<int> mstack2;
		int n[] = {1, 12, 3, 11, 33};
		for (int i = 0; i < 5; i++)
			mstack2.push(n[i]);
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		while (it2 != ite2)
		{
			std::cout << BLU << *it2 << RST << std::endl;
			++it2;
		}
		std::cout << GRN "top: " BLU << mstack2.top() << std::endl;
		std::cout << GRN "size: " BLU << mstack2.size() << std::endl;
		std::cout << GRN "pop" RST << std::endl;
		mstack2.pop();
		std::cout << GRN "top: " BLU << mstack2.top() << std::endl;
		std::cout << GRN "size: " BLU << mstack2.size() << std::endl;
		std::cout << std::endl;
		std::cout << YEL "List" RST << std::endl;
		std::list<int> list;
		for (int i = 0; i < 5; i++)
			list.push_back(n[i]);
		std::list<int>::iterator it3 = list.begin();
		std::list<int>::iterator ite3 = list.end();
		while (it3 != ite3)
		{
			std::cout << BLU << *it3 << RST <<std::endl;
			++it3;
		}
		std::cout << RED "top: " BLU << list.back() << std::endl;
		std::cout << RED "size: " BLU << list.size() << std::endl;
		std::cout << RED "pop" RST << std::endl;
		list.pop_back();
		std::cout << RED "top: " BLU << list.back() << std::endl;
		std::cout << RED "size: " BLU << list.size() << std::endl;
    }
    // std::cout << std::endl;
    // std::cout << ORG "=== INSUFFICIENT TEST ===" RST << std::endl;
    // {
    //     Span insufficientTest(1);
    //     std::cout << YEL "Added number: " BLU << 42 << std::endl;
    //     insufficientTest.addNumber(42);
    //     try {
    //         int span = insufficientTest.shortestSpan();
    //         std::cout << YEL "Shortest Span: " RST << span << std::endl;
    //     } catch (std::exception &e) {
    //         std::cout << RED "Error: " RST << e.what() << std::endl;
    //     }
    //     try {
    //         int span = insufficientTest.longestSpan();
    //         std::cout << YEL "Longest Span: " RST << span << std::endl;
    //     } catch (std::exception &e) {
    //         std::cout << RED "Error: " RST << e.what() << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // std::cout << ORG "=== SPAN FULL TEST ===" RST << std::endl;
    // {
    //     int size = 5;
    //     std::cout << YEL "Creating Span with size: " BLU << size << std::endl;
    //     Span fullTest(size);
    //     for (int i = 0; i < size; i++) {
    //         fullTest.addNumber(i * 10);
    //         std::cout << YEL "Added number[" << i << "]: " BLU << i * 10 << std::endl;
    //     }
    //     try {
    //         fullTest.addNumber(100);
    //     } catch (std::exception &e) {
    //         std::cout << RED "Error: " RST << e.what() << std::endl;
    //     }
    // }
    return 0;
}