#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* binaryTree(int values[], int index, int size) {
    if (index >= size) return nullptr;

    Node* root = new Node(values[index]);
    root->left = binaryTree(values, 2 * index + 1, size);
    root->right = binaryTree(values, 2 * index + 2, size);
    return root;
}

void minHeapify(Node* root) {
    if (!root) return;

    Node* smallest = root;

    if (root->left && root->left->data < smallest->data)
        smallest = root->left;
    if (root->right && root->right->data < smallest->data)
        smallest = root->right;

    if (smallest != root) {
        swap(root->data, smallest->data);
        minHeapify(smallest);
    }

    minHeapify(root->left);
    minHeapify(root->right);
}

void maxHeapify(Node* root) {
    if (!root) return;

    Node* largest = root;

    if (root->left && root->left->data > largest->data)
        largest = root->left;
    if (root->right && root->right->data > largest->data)
        largest = root->right;

    if (largest != root) {
        swap(root->data, largest->data);
        maxHeapify(largest);
    }

    maxHeapify(root->left);
    maxHeapify(root->right);
}

void printLevelOrder(Node* root, const string& title) {
    cout << title << ": ";
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(values) / sizeof(values[0]);

    Node* minHeapTree = binaryTree(values, 0, size);
    Node* maxHeapTree = binaryTree(values, 0, size);

    minHeapify(minHeapTree);
    maxHeapify(maxHeapTree);

    printLevelOrder(minHeapTree, "Min Heap");
    printLevelOrder(maxHeapTree, "Max Heap");

    return 0;
}