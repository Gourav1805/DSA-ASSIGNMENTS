#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
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
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return;
        }
        cout << arr[top] << " popped from stack" << endl;
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of stack: ";
    cin >> size;

    Stack stack(size);
    int choice, value;

    do {
        cout << "\n----- Stack Operations Menu -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                if (stack.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;

            case 4:
                if (stack.isFull())
                    cout << "Stack is full" << endl;
                else
                    cout << "Stack is not full" << endl;
                break;

            case 5:
                stack.display();
                break;

            case 6:
                stack.peek();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}