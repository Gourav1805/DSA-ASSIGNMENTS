#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    ~LinkedList() {
        Node* current = head;
        while(current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning" << endl;
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if(head == nullptr) {
            head = newNode;
            cout << value << " inserted at end" << endl;
            return;
        }
        
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        cout << value << " inserted at end" << endl;
    }
    
    void insertBefore(int searchValue, int newValue) {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if(head->data == searchValue) {
            insertAtBeginning(newValue);
            return;
        }
        
        Node* current = head;
        while(current->next != nullptr && current->next->data != searchValue) {
            current = current->next;
        }
        
        if(current->next == nullptr) {
            cout << searchValue << " not found in list" << endl;
            return;
        }
        
        Node* newNode = new Node(newValue);
        newNode->next = current->next;
        current->next = newNode;
        cout << newValue << " inserted before " << searchValue << endl;
    }
    
    void insertAfter(int searchValue, int newValue) {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* current = head;
        while(current != nullptr && current->data != searchValue) {
            current = current->next;
        }
        
        if(current == nullptr) {
            cout << searchValue << " not found in list" << endl;
            return;
        }
        
        Node* newNode = new Node(newValue);
        newNode->next = current->next;
        current->next = newNode;
        cout << newValue << " inserted after " << searchValue << endl;
    }
    
    void deleteFromBeginning() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning" << endl;
        delete temp;
    }
    
    void deleteFromEnd() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if(head->next == nullptr) {
            cout << head->data << " deleted from end" << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node* current = head;
        while(current->next->next != nullptr) {
            current = current->next;
        }
        
        cout << current->next->data << " deleted from end" << endl;
        delete current->next;
        current->next = nullptr;
    }
    
    void deleteValue(int value) {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if(head->data == value) {
            deleteFromBeginning();
            return;
        }
        
        Node* current = head;
        while(current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        
        if(current->next == nullptr) {
            cout << value << " not found in list" << endl;
            return;
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        cout << value << " deleted from list" << endl;
        delete temp;
    }
    
    void search(int value) {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* current = head;
        int position = 1;
        
        while(current != nullptr) {
            if(current->data == value) {
                cout << value << " found at position " << position << endl;
                return;
            }
            current = current->next;
            position++;
        }
        
        cout << value << " not found in list" << endl;
    }
    
    void display() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* current = head;
        cout << "List elements: ";
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, searchValue;
    
    while(true) {
        cout << "\n=== Singly Linked List Operations ===" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert before value" << endl;
        cout << "4. Insert after value" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete specific value" << endl;
        cout << "8. Search value" << endl;
        cout << "9. Display list" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter value to search for: ";
                cin >> searchValue;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertBefore(searchValue, value);
                break;
                
            case 4:
                cout << "Enter value to search for: ";
                cin >> searchValue;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAfter(searchValue, value);
                break;
                
            case 5:
                list.deleteFromBeginning();
                break;
                
            case 6:
                list.deleteFromEnd();
                break;
                
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;
                
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
                
            case 9:
                list.display();
                break;
                
            case 10:
                cout << "Exiting program..." << endl;
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}