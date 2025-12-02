#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if(isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        
        if(isEmpty()) {
            front = 0;
        }
        
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " enqueued to queue" << endl;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
            return -1;
        }
        
        int value = arr[front];
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return value;
    }

    int peek() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue elements are: ";
        int count = 0;
        int index = front;
        
        while(count < size) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the size of circular queue: ";
    cin >> capacity;
    
    CircularQueue q(capacity);
    int choice, value;
    
    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Check if empty";
        cout << "\n6. Check if full";
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
                    cout << "Dequeued value: " << value << endl;
                break;
                
            case 3:
                value = q.peek();
                if(value != -1)
                    cout << "Front element: " << value << endl;
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
                cout << "Exiting program" << endl;
                break;
                
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 7);
    
    return 0;
}