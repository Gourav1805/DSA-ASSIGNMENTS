#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
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
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
};

class ExpressionConverter {
private:
    int precedence(char op) {
        if(op == '^') return 3;
        if(op == '*' || op == '/') return 2;
        if(op == '+' || op == '-') return 1;
        return -1;
    }

public:
    string infixToPostfix(string infix) {
        Stack stack(infix.length());
        string postfix;
        
        for(char c : infix) {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                postfix += c;
            }
            else if(c == '(') {
                stack.push(c);
            }
            else if(c == ')') {
                while(!stack.isEmpty() && stack.peek() != '(') {
                    postfix += stack.pop();
                }
                stack.pop(); // Remove '('
            }
            else {
                while(!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                    postfix += stack.pop();
                }
                stack.push(c);
            }
        }
        
        while(!stack.isEmpty()) {
            postfix += stack.pop();
        }
        
        return postfix;
    }
};

class PostfixEvaluator {
private:
    int* arr;
    int top;
    int capacity;

public:
    PostfixEvaluator(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~PostfixEvaluator() {
        delete[] arr;
    }

    void push(int value) {
        if(top == capacity-1) return;
        arr[++top] = value;
    }

    int pop() {
        if(top == -1) return -1;
        return arr[top--];
    }

    int evaluatePostfix(string postfix) {
        for(char c : postfix) {
            if(isdigit(c)) {
                push(c - '0');
            }
            else {
                int val1 = pop();
                int val2 = pop();
                
                switch(c) {
                    case '+': push(val2 + val1); break;
                    case '-': push(val2 - val1); break;
                    case '*': push(val2 * val1); break;
                    case '/': push(val2 / val1); break;
                }
            }
        }
        return pop();
    }
};

int main() {
    int choice;
    ExpressionConverter converter;
    
    do {
        cout << "\n1. Convert Infix to Postfix";
        cout << "\n2. Evaluate Postfix Expression";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                string infix;
                cout << "Enter infix expression: ";
                cin >> infix;
                string postfix = converter.infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            }
            case 2: {
                string postfix;
                cout << "Enter postfix expression (single digits only): ";
                cin >> postfix;
                PostfixEvaluator evaluator(postfix.length());
                cout << "Result: " << evaluator.evaluatePostfix(postfix) << endl;
                break;
            }
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);

    return 0;
}