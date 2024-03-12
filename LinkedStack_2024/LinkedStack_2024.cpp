// LinkedStack_2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert> // For assert()
#include<string>

// Node structure template
template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T data, Node* next = nullptr) : data(data), next(next) {}
};

// Stack class template using a linked list
template<typename T>
class LinkedListStack {
public:
    LinkedListStack() : top(nullptr), _size(0) {} // Constructor

    ~LinkedListStack(); // Destructor

    void push(T data); // Push data on stack
    T pop(); // Pop data from stack
    T peek() const; // Get the top element
    bool isEmpty() const { return top == nullptr; } // Check if stack is empty
    int size() const { return _size; } // Get the size of the stack

private:
    Node<T>* top; // Top of the stack
    int _size; // Size of the stack
};

template<typename T>
LinkedListStack<T>::~LinkedListStack() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
void LinkedListStack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data, top);
    top = newNode;
    _size++;
}

template<typename T>
T LinkedListStack<T>::pop() {
    assert(!isEmpty() && "Stack is empty. Cannot pop.");
    Node<T>* temp = top;
    T data = top->data;
    top = top->next;
    delete temp;
    _size--;
    return data;
}

template<typename T>
T LinkedListStack<T>::peek() const {
    assert(!isEmpty() && "Stack is empty. Cannot peek.");
    return top->data;
}
bool isWellParenthesized(std::string expr)
{
    LinkedListStack<char> symbols;
    int n = expr.size();
    for (size_t i = 0; i < n; ++i)
    {
        if (expr.at(i) == '(' or expr.at(i) == '[' or expr.at(i) == '{')
        {
            symbols.push(expr.at(i));
            std::cout << "pushed" << expr.at(i) << "\n";
        }

        else if (expr.at(i) == ']' or expr.at(i) == ')' or expr.at(i) == '}')
        {
            char c = expr.at(i);
            bool matches = false;
            switch (c) {
            case ']':
                matches = symbols.peek() == '[';
                break;
            case '}':
                matches = symbols.peek() == '{';
                break;
            case ')':
                matches = symbols.peek() == '(';
            }
            if (matches)
                std::cout << "poped " << symbols.pop() << "\n";
            else
                return false;
        }
    }
    return symbols.isEmpty();
}
void convertInBinary(int a)
{
    assert(a >= 0 && "Argument should be a positive integer");
    LinkedListStack<int> stack;
    while (a != 0)
    {
        stack.push(a % 2);
        a /= 2;
    }

    while (!stack.isEmpty())
        std::cout << stack.pop();
}
bool isPalindrome(std::string s)
{
    return s == reverse(s);
}
std::string reverse(std::string s)
{
    std::string rev = "";
    LinkedListStack<char> stack;
    for (auto i : s)
        stack.push(i);
    while (!stack.isEmpty())
        rev += stack.pop();
    return rev;
}
// Example usage
int main() {
    LinkedListStack<char> stack;
    std::string expr;
    std::cout << "Enter expression\n";
    std::getline(std::cin, expr);
    if (isWellParenthesized(expr))
        std::cout << "The expression is well parenthesized\n";
    else
        std::cout << "The expression is not well paranthesized\n";
    convertInBinary(23);
    std::string a;
    std::cout << "Enter string to check\n";
    std::getline(std::cin, a);
    if (isPalindrome(a))
        std::cout << a << " is a palindrome\n";
    else
        std::cout << a << " is not a palindrome\n";
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
