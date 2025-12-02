#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(char value) {  
        if(isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop() {  
        if(isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return '\0';  
        }
        return arr[top--];
    }

    char peek() {  
        if(isEmpty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        return arr[top];
    }

    void display() {
        if(isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for(int i = top; i >= 0; i--)
            cout << (char)arr[i] << " ";  
        cout << endl;
    }
};

bool isBalanced(string expr) {
    Stack s(expr.size());  
    
    for(char c : expr) {
        if(c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(s.isEmpty()) {  
                return false;
            }
            
            char top = s.peek();  
            s.pop();
            
            if((c == ')' && top != '(') || 
               (c == ']' && top != '[') || 
               (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return s.isEmpty();  
    
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    
    if(isBalanced(expression))
        cout << "Expression has balanced parentheses" << endl;
    else
        cout << "Expression has unbalanced parentheses" << endl;
    
    return 0;
}