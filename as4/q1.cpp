#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Add element to queue
    void enqueue(int value) {
        if(isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        
        // If queue is empty
        if(isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        
        arr[rear] = value;
        cout << value << " enqueued to queue" << endl;
    }

    // Remove element from queue
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
            return -1;
        }

        int value = arr[front];

        // If queue has only one element
        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        return value;
    }

    // Get front element without removing it
    int peek() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Display all elements
    void display() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        
        if(front <= rear) {
            while(i <= rear)
                cout << arr[i++] << " ";
        }
        else {
            while(i < capacity)
                cout << arr[i++] << " ";
            i = 0;
            while(i <= rear)
                cout << arr[i++] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of queue: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Check if Empty";
        cout << "\n6. Check if Full";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if(value != -1)
                    cout << "Dequeued value is: " << value << endl;
                break;
            case 3:
                value = q.peek();
                if(value != -1)
                    cout << "Front element is: " << value << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                if(q.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;
            case 6:
                if(q.isFull())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue is not full" << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 7);

    return 0;
}