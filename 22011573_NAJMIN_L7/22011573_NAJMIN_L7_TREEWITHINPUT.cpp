#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string val) : name(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;

    bool add(Node*& node, const string& path, const string& val, int depth = 0) {
        if (depth == path.size()) {
            if (node == nullptr) {
                node = new Node(val);
                return true;
            } else {
                return false;
            }
        }
        if (node == nullptr) return false;

        if (path[depth] == 'L') return add(node->left, path, val, depth + 1);
        else if (path[depth] == 'R') return add(node->right, path, val, depth + 1);
        return false;
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    bool remove(Node*& node, const string& path, int depth = 0) {
        if (!node) return false;
        if (depth == path.size()) {
            deleteTree(node);
            node = nullptr;
            return true;
        }
        if (path[depth] == 'L') return remove(node->left, path, depth + 1);
        else if (path[depth] == 'R') return remove(node->right, path, depth + 1);
        return false;
    }

    void printPaths(Node* node, vector<string>& path) {
        if (!node) return;
        path.push_back(node->name);
        if (!node->left && !node->right) {
            for (const auto& val : path) cout << val << " -> ";
            cout << "NULL\n";
        } else {
            printPaths(node->left, path);
            printPaths(node->right, path);
        }
        path.pop_back();
    }

    Node* findNode(Node* node, const string& val) {
        if (!node) return nullptr;
        if (node->name == val) return node;
        Node* leftResult = findNode(node->left, val);
        if (leftResult) return leftResult;
        return findNode(node->right, val);
    }

public:
    Tree() : root(nullptr) {}

    void addElement(const string& path, const string& val) {
        if (path.empty() && !root) {
            root = new Node(val);
        } else {
            add(root, path, val);
        }
    }

    void removeElement(const string& path) {
        if (path.empty()) {
            deleteTree(root);
            root = nullptr;
        } else {
            remove(root, path);
        }
    }

    void viewPaths() {
        vector<string> path;
        printPaths(root, path);
    }

    void insertAfter(const string& target, const string& direction, const string& newVal) {
        Node* targetNode = findNode(root, target);
        if (!targetNode) return;

        if (direction == "L") {
            if (!targetNode->left) {
                targetNode->left = new Node(newVal);
            }
        } else if (direction == "R") {
            if (!targetNode->right) {
                targetNode->right = new Node(newVal);
            }
        }
    }
};

int main() {
    Tree tree;
    int choice;
    string path, name, dir, newVal;

    while (true) {
        cout << "\n1. Add Element (by Path)\n2. Remove Element (by Path)\n3. View Paths\n4. Insert After a Node (by Name)\n5. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter path (L/R, empty for root): ";
            getline(cin, path);
            cout << "Enter value: ";
            getline(cin, name);
            tree.addElement(path, name);
        } else if (choice == 2) {
            cout << "Enter path to remove (empty = root): ";
            getline(cin, path);
            tree.removeElement(path);
        } else if (choice == 3) {
            tree.viewPaths();
        } else if (choice == 4) {
            cout << "Enter existing node name: ";
            getline(cin, name);
            cout << "Insert on (L/R): ";
            getline(cin, dir);
            cout << "Enter new node value: ";
            getline(cin, newVal);
            tree.insertAfter(name, dir, newVal);
        } else if (choice == 5) {
            break;
        }
    }

    return 0;
}
