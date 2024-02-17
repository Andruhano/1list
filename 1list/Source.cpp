#include <iostream>
using namespace std;

template<typename T>
class Stack 
{

struct Node 
{
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() 
    {
        while (!isEmpty()) 
        {
            pop();
        }
    }

    void push(const T& value) 
    {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Error: Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T& top() const 
    {
        if (isEmpty()) 
        {
            cout << "Error: Stack is empty. Cannot access top element.";
        }
        return topNode->data;
    }

    bool isEmpty() const 
    {
        return topNode == nullptr;
    }
};

int main() 
{
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.top() << endl;
    intStack.pop();
    cout << "Top element after pop: " << intStack.top() << endl;

    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    cout << "Top element: " << stringStack.top() << endl;
    stringStack.pop();
    cout << "Top element after pop: " << stringStack.top() << endl;

    return 0;
}
