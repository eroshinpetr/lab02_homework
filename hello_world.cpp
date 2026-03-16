#include <iostream>
#include <string>

int main() {
    std::string name;  // переменная для хранения имени пользователя
    
    // Запрашиваем имя пользователя
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    // Выводим приветствие
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
