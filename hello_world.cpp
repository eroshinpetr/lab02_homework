#include <iostream>
#include <string>

int
main()
{
    std::string name; // variable to store user name

    // Request user name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Print greeting
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
