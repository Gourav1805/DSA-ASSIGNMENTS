// reverse_list.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

void insertEnd(Node*& head, int x) {
    Node* t = new Node(x);
    if (!head) { head = t; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = t;
}

Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insertEnd(head, x);
    }
    head = reverseList(head);
    printList(head);
}
