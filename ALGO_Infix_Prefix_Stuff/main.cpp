#include <iostream>
#include <vector>
#include <chrono>
#include "../ALGO_stack/STack.h"
#include <thread>

//Example:

//1. Scan the infix expression from left to right.
//2. If the scanned character is an operand, output it.
//3. Else,
//…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
//…..3.2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
//4. If the scanned character is an ‘(‘, push it to the stack.
//5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis.
//6. Repeat steps 2-6 until infix expression is scanned.
//7. Print the output
//8. Pop and output from the stack until it is not empty.

//Example:
//Input:
//2
//a+b*(c^d-e)^(f+g*h)-i
//A*(B+C)/D
//
//Output:
//abcd^e-fgh*+^*+i-
//ABC+*D/

int get_precedance(char op_to_check)
{
    switch (op_to_check) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '^':
            return 2;
        case '(':
        case ')':
            return 3;
    }
}

bool is_operand(char input)
{
    const std::string not_operands ="+-*/^()";
    for(auto& d:not_operands)
        if(input==d)
            return false;
    return true;
}

void conv_inf_to_post(const std::string to_solve)
{
    std::cout << "Solving:" << to_solve<< std::endl << "Result:";
    Stack<char> myStack;
    for(auto& c:to_solve)
    {
        if(is_operand(c))
            std::cout << c;
        else
        {
            if(c==')')
            {
                while (myStack.top()!='(')
                    std::cout <<myStack.pop();
                myStack.pop(); //discard the paranthesis
            } else
            {
                //its an operator
                if(myStack.empty()||get_precedance(myStack.top())<get_precedance(c)||myStack.top()=='('||c=='(')
                {
                    myStack.push(c);
                } else
                {
                    bool found_paranthesis = false;
                    while (get_precedance(myStack.top())>=c &&!found_paranthesis)

                        if(myStack.top()=='(')
                        {
                            found_paranthesis= true;
                            myStack.push(c);
                        } else
                            std::cout<<myStack.pop();
                }
            }
        }
    }
    while (!myStack.empty())
        std::cout << myStack.pop();
    std::cout << std::endl;
}

int main() {
    conv_inf_to_post("a+b*(c^d-e)^(f+g*h)-i");
    conv_inf_to_post("A*(B+C)/D");
    std::string custom_solve;
    std::cout << "Please insert your Equation in Infix-Notation:" << std::endl;
    std::cin >> custom_solve;
    conv_inf_to_post(custom_solve);
    return 0;
}
