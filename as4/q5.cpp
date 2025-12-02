#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
    int max_size;

public:
    Queue(int size) {
        max_size = size;
        front = -1;
        rear = -1;
    }
    
    bool is_empty() {
        if(front == -1) {
            return true;
        }
        return false;
    }
    
    bool is_full() {
        if((rear + 1) % max_size == front) {
            return true;
        }
        return false;
    }
    
    void add_element(int x) {
        if(is_full()) {
            cout << "Queue is full!" << endl;
            return;
        }
        
        if(is_empty()) {
            front = 0;
        }
        
        rear = (rear + 1) % max_size;
        arr[rear] = x;
        cout << "Added " << x << " to queue" << endl;
    }
    
    int remove_element() {
        if(is_empty()) {
            cout << "Queue is empty!" << endl;
            return -999;
        }
        
        int element = arr[front];
        
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max_size;
        }
        
        return element;
    }
    
    int get_size() {
        if(is_empty()) {
            return 0;
        }
        return (rear - front + max_size) % max_size + 1;
    }
};

class StackWithTwoQueues {
    Queue queue1;
    Queue queue2;
    int stack_size;

public:
    StackWithTwoQueues(int size) : queue1(size), queue2(size) {
        stack_size = size;
    }
    
    void push_element(int x) {
        if(queue1.get_size() >= stack_size) {
            cout << "Stack is full!" << endl;
            return;
        }
        
        queue2.add_element(x);
        
        while(!queue1.is_empty()) {
            int temp = queue1.remove_element();
            queue2.add_element(temp);
        }
        
        Queue temp_queue = queue1;
        queue1 = queue2;
        queue2 = temp_queue;
        
        cout << "Pushed " << x << " to stack" << endl;
    }
    
    int pop_element() {
        if(queue1.is_empty()) {
            cout << "Stack is empty!" << endl;
            return -999;
        }
        
        int popped = queue1.remove_element();
        cout << "Popped " << popped << " from stack" << endl;
        return popped;
    }
    
    bool stack_empty() {
        return queue1.is_empty();
    }
};

class StackWithOneQueue {
    Queue my_queue;
    int stack_size;

public:
    StackWithOneQueue(int size) : my_queue(size) {
        stack_size = size;
    }
    
    void push_element(int x) {
        if(my_queue.get_size() >= stack_size) {
            cout << "Stack is full!" << endl;
            return;
        }
        
        my_queue.add_element(x);
        
        int current_size = my_queue.get_size();
        for(int i = 0; i < current_size - 1; i++) {
            int temp = my_queue.remove_element();
            my_queue.add_element(temp);
        }
        
        cout << "Pushed " << x << " to stack" << endl;
    }
    
    int pop_element() {
        if(my_queue.is_empty()) {
            cout << "Stack is empty!" << endl;
            return -999;
        }
        
        int popped = my_queue.remove_element();
        cout << "Popped " << popped << " from stack" << endl;
        return popped;
    }
    
    bool stack_empty() {
        return my_queue.is_empty();
    }
};

int main() {
    cout << "Stack Implementation Using Queues" << endl;
    cout << "===================================" << endl;
    
    int stack_size;
    cout << "How big should the stack be? ";
    cin >> stack_size;
    
    StackWithTwoQueues stack_two_queues(stack_size);
    StackWithOneQueue stack_one_queue(stack_size);
    
    int user_choice;
    
    while(true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Push to Stack (using 2 queues)" << endl;
        cout << "2. Pop from Stack (using 2 queues)" << endl;
        cout << "3. Push to Stack (using 1 queue)" << endl;
        cout << "4. Pop from Stack (using 1 queue)" << endl;
        cout << "5. Quit program" << endl;
        cout << "What do you want to do? ";
        cin >> user_choice;
        
        if(user_choice == 1) {
            int number;
            cout << "Enter number to push: ";
            cin >> number;
            stack_two_queues.push_element(number);
        }
        else if(user_choice == 2) {
            if(!stack_two_queues.stack_empty()) {
                stack_two_queues.pop_element();
            }
        }
        else if(user_choice == 3) {
            int number;
            cout << "Enter number to push: ";
            cin >> number;
            stack_one_queue.push_element(number);
        }
        else if(user_choice == 4) {
            if(!stack_one_queue.stack_empty()) {
                stack_one_queue.pop_element();
            }
        }
        else if(user_choice == 5) {
            cout << "Thanks for using the program! Goodbye!" << endl;
            break;
        }
        else {
            cout << "That's not a valid choice! Please try again." << endl;
        }
    }
    
    return 0;
}