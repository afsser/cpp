#include <iostream>
#include <Span.hpp>
#include <ctime>
#include <cstdlib>
#include "colors.hpp"
#include <cmath>

int main()
{
    std::srand(std::time(0));
    std::cout << ORG "=== BASIC TEST ===" RST << std::endl;
    {
        int     size;
        int     nbr;
        size = 3;
        Span    test(size);
        for (int i = 0; i < size; i++){
            nbr = std::rand() % 100;
            test.addNumber(nbr);
            std::cout << nbr << " " << std::endl;
        }
        try {
            std::cout << YEL "Shortest Span: " BLU << test.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
        try {
            std::cout << YEL "Longest Span: " BLU << test.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }

    }
    std::cout << std::endl;
    std::cout << ORG "=== ADD RANGE TEST ===" RST << std::endl;
    {
        Span rangeTest(10);
        std::vector<int> numbers;
        for (int i = 0; i < 5; i++) {
            int num = std::rand() % 100;
            numbers.push_back(num);
            std::cout << YEL "Generated number: " BLU << num << std::endl;
        }

        std::cout << BLU "Adding range of numbers to Span." RST << std::endl;
        std::cout << MAG "From 2nd to 4th element:" RST << std::endl;
        try {
            rangeTest.addRange(numbers.begin() + 1, numbers.begin() + 4);
            std::cout << GRN "Added range successfully:" RST << std::endl;
            std::cout << rangeTest << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
        
    }
    std::cout << std::endl;
    std::cout << ORG "=== HUGE TEST ===" RST << std::endl;
    {
        Span hugeTest(20000);
        for (int i = 0; i < 20000; i++) {
            int nbr = std::rand() % 20000;
            if (nbr < 5000)
                nbr += std::rand() % 1000;
            else if (nbr > 15000)
                nbr -= std::rand() % 1000;
            hugeTest.addNumber(nbr);
        }
        try {
            int span = hugeTest.shortestSpan();
            std::cout << YEL "Shortest Span: " BLU << span << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
        try {
            int span = hugeTest.longestSpan();
            std::cout << YEL "Longest Span: " BLU << span << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << ORG "=== INSUFFICIENT TEST ===" RST << std::endl;
    {
        Span insufficientTest(1);
        std::cout << YEL "Added number: " BLU << 42 << std::endl;
        insufficientTest.addNumber(42);
        try {
            int span = insufficientTest.shortestSpan();
            std::cout << YEL "Shortest Span: " BLU << span << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
        try {
            int span = insufficientTest.longestSpan();
            std::cout << YEL "Longest Span: " BLU << span << std::endl;
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << ORG "=== SPAN FULL TEST ===" RST << std::endl;
    {
        int size = 5;
        std::cout << YEL "Creating Span with size: " BLU << size << std::endl;
        Span fullTest(size);
        for (int i = 0; i < size; i++) {
            fullTest.addNumber(i * 10);
            std::cout << YEL "Added number[" << i << "]: " BLU << i * 10 << std::endl;
        }
        try {
            fullTest.addNumber(100);
        } catch (std::exception &e) {
            std::cout << RED "Error: " RST << e.what() << std::endl;
        }
    }
    return 0;
}