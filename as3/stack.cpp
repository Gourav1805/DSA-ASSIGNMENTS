#include <iostream>
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

    void push(int value) {
        if(isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack" << endl;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if(isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
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
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    
    Stack s(size);
    int choice, value;

    while(true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            
            case 2:
                value = s.pop();
                if(value != -1)
                    cout << "Popped value: " << value << endl;
                break;
            
            case 3:
                s.display();
                break;
            
            case 4:
                value = s.peek();
                if(value != -1)
                    cout << "Top element: " << value << endl;
                break;
            
            case 5:
                return 0;
            
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}