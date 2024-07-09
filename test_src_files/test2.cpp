#include <iostream>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::cout << "The first number is: " << numbers[0 << std::endl;
    std::cout << "The second number is: " << numbers[1] << std::endl;

    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << "Number " << i << ": " << numbers[i] << std::endl;
    }

    numbers.push_back("four");
    return 0;
}
