#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "stack.h"

int main(int argc, char *argv[])
{
    stack testDrive = {34, 4, 5, 86, 20};
    std::cout << "New stack testDrive created: " << testDrive << "\n";

    testDrive.push(56);
    std::cout << "After pushing 56: " << testDrive << "\n";

    testDrive.pop();
    std::cout << "After popping: " << testDrive << "\n";

    std::cout << "Peek test: " << testDrive.peek() << "\n";
    std::cout << "Current size of testDrive stack: " << testDrive.current_size << "\n";

    testDrive.push(567);
    testDrive.push(7);
    testDrive.push(102);
    testDrive.push(45);
    testDrive.push(987);

    std::cout << "After pushing 5 values: " << testDrive << "\n";
    std::cout << "Current capacity of testDrive stack: " << testDrive.current_capacity << "\n";

    testDrive.reset(4);
    std::cout << "After shrinking to 4: " << testDrive << "\n";

    testDrive.clear();
    std::cout << "After clearing: " << testDrive << "\n";
    return 0;
}
