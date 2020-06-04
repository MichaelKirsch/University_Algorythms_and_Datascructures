#include <iostream>
#include <vector>
#include <chrono>
#include "../ALGO_stack/STack.h"


int main() {
    Stack<char> myStack;

    std::string to_solve;
    std::cout << "Please insert your Equation in Infix-Notation:" << std::endl;
    std::cin >> to_solve;
    for(auto& c:to_solve)
        myStack.push(c);
    while (!myStack.empty())
        std::cout << myStack.pop();
    std::cout << std::endl;

    return 0;
}
