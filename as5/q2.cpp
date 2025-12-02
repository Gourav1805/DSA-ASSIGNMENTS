// count_and_delete.cpp
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

int deleteKey(Node*& head, int key) {
    int cnt = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        cnt++;
    }
    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* t = p->next;
            p->next = p->next->next;
            delete t;
            cnt++;
        } else {
            p = p->next;
        }
    }
    return cnt;
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
    int key; cin >> key;

    int cnt = deleteKey(head, key);
    cout << cnt << "\n";
    printList(head);
}
