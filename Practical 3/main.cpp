#include "MyString.h"
#include <iostream>
#include <fstream>

int main() {
    // Test 1: Using constructor with string input
    MyString myStringObj1("aBC % $k$48J f {}d 1\n23\nkl - D");
    std::cout << "Test 1: Initial myStringObj1: ";
    myStringObj1.print();

    // Test 2: Using constructor with std::string
    MyString myStringObj2("Hello, World!");
    std::cout << "Test 2: Initial myStringObj2: ";
    myStringObj2.print();

    // Test 3: Using operator+ with std::string
    std::string concatStr = myStringObj1 + "XYZ";
    std::cout << "Test 3: Concatenated string: " << concatStr << std::endl;

    // Test 4: Using operator+=
    myStringObj1 += myStringObj2;
    std::cout << "Test 4: myStringObj1 after +=: ";
    myStringObj1.print();

    // Test 5: Using comparison operators
    if (myStringObj1 < myStringObj2) {
        std::cout << "Test 5: myStringObj1 is smaller than myStringObj2." << std::endl;
    } else if (myStringObj1 > myStringObj2) {
        std::cout << "Test 5: myStringObj1 is larger than myStringObj2." << std::endl;
    } else if (myStringObj1 == myStringObj2) {
        std::cout << "Test 5: myStringObj1 is equal to myStringObj2." << std::endl;
    } else {
        std::cout << "Test 5: myStringObj1 and myStringObj2 are not equal or comparable." << std::endl;
    }

    // Test 6: Using operator! with an empty string
    MyString emptyString("");
    if (!emptyString) {
        std::cout << "Test 6: emptyString is empty." << std::endl;
    } else {
        std::cout << "Test 6: emptyString is not empty." << std::endl;
    }

    // Test 7: Using operator= with file input
    std::fstream inputFile("input.txt", std::ios::in);
    MyString myStringFromFile("Initial Value");
    myStringFromFile = inputFile;
    std::cout << "Test 7: After file read: ";
    myStringFromFile.print();

    // Test 8: Using clear function
    myStringFromFile.clear();
    std::cout << "Test 8: After clear: ";
    myStringFromFile.print();

    // Test 9: Using copy constructor
    MyString myStringCopy(myStringObj1);
    std::cout << "Test 9: Copy of myStringObj1: ";
    myStringCopy.print();

    // Test 10: Using assignment operator with another MyString
    myStringCopy = myStringObj2;
    std::cout << "Test 10: Copy after assignment: ";
    myStringCopy.print();

    // Test 11: Using assignment operator with std::string
    myStringCopy = "Updated Value";
    std::cout << "Test 11: Copy after assignment with string: ";
    myStringCopy.print();

    MyString myStringObj3("aBC % $k$48J f {}d 1\n23\nkl - D");
    MyString myStringObj4("BAA 25");

    // Testing print
    std::cout << "myStringObj1: ";
    myStringObj3.print();

    // Testing operator+ with std::string
    std::string concatStr1 = myStringObj3 + "XYZ";
    std::cout << "Concatenated string: " << concatStr1 << std::endl;

    // Testing operator+ with MyString
    MyString concatMyString1 = myStringObj3 + myStringObj4;
    std::cout << "Concatenated MyString: ";
    concatMyString1.print();

    // Testing operator+=
    myStringObj3 += myStringObj4;
    std::cout << "myStringObj1 after +=: ";
    myStringObj3.print();

    // Testing comparison operators
    if (myStringObj3 < myStringObj4) {
        std::cout << "myStringObj1 is smaller than myStringObj2." << std::endl;
    } else if (myStringObj3 > myStringObj4) {
        std::cout << "myStringObj1 is larger than myStringObj2." << std::endl;
    } else if (myStringObj3 == myStringObj4) {
        std::cout << "myStringObj1 is equal to myStringObj2." << std::endl;
    }

    // Testing operator!
    if (!myStringObj4) {
        std::cout << "myStringObj1 is empty." << std::endl;
    } else {
        std::cout << "myStringObj1 is not empty." << std::endl;
    }

    // Testing operator=
    std::fstream inputFile1("input.txt", std::ios::in);
    MyString myStringFromFile1("Initial Value");

    myStringFromFile1 = inputFile1;
    std::cout << "After file read: ";
    myStringFromFile1.print();

    // Testing clear
    myStringFromFile1.clear();
    std::cout << "After clear: ";
    myStringFromFile1.print();
    return 0;
}
