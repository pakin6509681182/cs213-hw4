#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements in the vector
    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Second element: " << numbers[1] << std::endl;
    std::cout << "Third element: " << numbers[2] << std::endl;

    // Modify elements in the vector
    numbers[1] = 50;

    // Iterate over the vector using a range-based for loop
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Get the size of the vector
    std::cout << "Size of the vector: " << numbers.size() << std::endl;

    // Remove elements from the vector
    numbers.pop_back();
    std::cout << "Size of the vector: " << numbers.size() << std::endl;

    // Check if the vector is empty
    if (numbers.empty()) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        std::cout << "Vector is not empty" << std::endl;
    }

    return 0;
}
