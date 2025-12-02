#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) { data = x; left = right = NULL; }
};


/*#question-1
   Binary Tree Traversals (Recursive)*/

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


/* #question-2
   BST Functions: Search, Max, Min, successor, predecessor*/

// Insert helper (used later also)
Node* bstInsert(Node* root, int key) {
    if (root == NULL) return new Node(key);

    if (key < root->data)
        root->left = bstInsert(root->left, key);
    else if (key > root->data)
        root->right = bstInsert(root->right, key);

    return root;
}

// (a) Search recursive
Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) return root;

    if (key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}

// (a) Search non-recursive
Node* searchIter(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// (b) Maximum
Node* bstMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}

// (c) Minimum
Node* bstMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchIter(root, key);
    if (target == NULL) return NULL;

    if (target->right != NULL)
        return bstMin(target->right);

    Node* succ = NULL;
    Node* cur = root;
    while (cur != NULL) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIter(root, key);
    if (target == NULL) return NULL;

    if (target->left != NULL)
        return bstMax(target->left);

    Node* pred = NULL;
    Node* cur = root;
    while (cur != NULL) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}


/* #question-3
   Insert, Delete, Max depth, Min depth */

// Delete a node
Node* bstDelete(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = bstDelete(root->left, key);
    else if (key > root->data)
        root->right = bstDelete(root->right, key);

    else {
        // Case 1: Leaf
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        // Case 3: Two children
        else {
            Node* succ = bstMin(root->right);
            root->data = succ->data;
            root->right = bstDelete(root->right, succ->data);
        }
    }
    return root;
}

// Maximum depth (height)
int maxDepth(Node* root) {
    if (root == NULL) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}

// Minimum depth
int minDepth(Node* root) {
    if (root == NULL) return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (root->left == NULL) return 1 + right;
    if (root->right == NULL) return 1 + left;

    return 1 + (left < right ? left : right);
}


/* #question-4  
   Check if a Binary Tree is BST*/

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal || root->data >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -10000000, 10000000);
}


/* #question-5  
   Heapsort (without STL)*/

void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        int temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        maxHeapify(a, n, largest);
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        maxHeapify(a, i, 0);
    }
}


/* #question-6  
   Priority Queue using Heap (min-heap)*/

struct MinHeap {
    int arr[100];
    int size;

    MinHeap() { size = 0; }

    void push(int x) {
        arr[size] = x;
        int i = size;
        size++;

        while (i != 0 && arr[(i-1)/2] > arr[i]) {
            int t = arr[i];
            arr[i] = arr[(i-1)/2];
            arr[(i-1)/2] = t;
            i = (i-1)/2;
        }
    }

    int top() {
        return (size > 0 ? arr[0] : -1);
    }

    void pop() {
        if (size <= 0) return;

        arr[0] = arr[size-1];
        size--;

        int i = 0;
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int smallest = i;

            if (l < size && arr[l] < arr[smallest]) smallest = l;
            if (r < size && arr[r] < arr[smallest]) smallest = r;

            if (smallest != i) {
                int t = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = t;
                i = smallest;
            } else break;
        }
    }
};



int main() {
    cout << "Code compiled successfully (all questions implemented).\n";
    return 0;
}

