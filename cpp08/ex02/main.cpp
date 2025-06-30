#include <iostream>
#include <Array.hpp>
#include <ctime>
#include <cstdlib>
#include "colors.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << ORG "=== EMPTY ARRAY ===" RST << std::endl;
    {
        Array<int> emptyArray;
        std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
    }
    std::cout << ORG "=== CHAR ARRAY ===" RST << std::endl;
    {
        Array<char> charArray(5);
        charArray[0] = 'H';
        charArray[1] = 'e';
        charArray[2] = 'l';
        charArray[3] = 'l';
        charArray[4] = 'o';
        std::cout << "Size of char array: " << charArray.size() << std::endl;
        for (size_t i = 0; i < charArray.size(); ++i)
            std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
    }
    std::cout << ORG "=== STRING ARRAY ===" RST << std::endl;
    {
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!!!";
        std::cout << "Size of string array: " << stringArray.size() << std::endl;
        for (size_t i = 0; i < stringArray.size(); ++i)
            std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }
    std::cout << ORG "=== DEEP COPY TEST ===" RST << std::endl;
    {
        Array<int> original(5);
        for (int i = 0; i < 5; ++i)
            original[i] = i * 10;

        Array<int> copy(original);
        std::cout << "Original array: ";
        for (int i = 0; i < 5; ++i)
            std::cout << original[i] << " ";
        std::cout << std::endl;

        std::cout << "Copied array: ";
        for (int i = 0; i < 5; ++i)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

        copy[0] = 100;
        std::cout << "After modifying copy[0]: ";
        for (int i = 0; i < 5; ++i)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Original array after modification: ";
        for (int i = 0; i < 5; ++i)
            std::cout << original[i] << " ";
        std::cout << std::endl;
    }
    std::cout << ORG "=== ASSIGNMENT OPERATOR TEST ===" RST << std::endl;
    {
        Array<int> array1(3);
        array1[0] = 1;
        array1[1] = 2;
        array1[2] = 3;
        Array<int> array2;
        array2 = array1;
        std::cout << "Array1: ";
        for (size_t i = 0; i < array1.size(); ++i)
            std::cout << array1[i] << " ";
        std::cout << std::endl;
        std::cout << "Array2 after assignment: ";
        for (size_t i = 0; i < array2.size(); ++i)
            std::cout << array2[i] << " ";
        std::cout << std::endl;
        array2[1] = 42;
        std::cout << "Array2 after modification: ";
        for (size_t i = 0; i < array2.size(); ++i)
            std::cout << array2[i] << " ";
        std::cout << std::endl;
        std::cout << "Array1 after Array2 modification: ";
        for (size_t i = 0; i < array1.size(); ++i)
            std::cout << array1[i] << " ";
        std::cout << std::endl;
    }
    std::cout << ORG "=== SUBJECT TEST ===" RST << std::endl;
    {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    }
    return 0;
}