#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int maxSize;
    int currentSize;

public:
    Stack(int size) {
        top = nullptr;
        maxSize = size;
        currentSize = 0;
    }

    bool isFull() {
        return currentSize >= maxSize;
    }

    void push(string name) {
        if (isFull()) {
            cout << "Stack is full. Cannot push '" << name << "'." << endl;
            return;
        }
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
        currentSize++;
        cout << "Pushed: " << name << endl;
    }

    void pop(string name) {
        Node* current = top;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->name == name) {
                if (previous == nullptr) {
                    top = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                currentSize--;
                cout << "Popped: " << name << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Element not found: " << name << endl;
    }

    void view_stack() {
        if (top == nullptr) {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << "Stack:\nTOP ---> | ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->name << " | ";
            current = current->next;
        }
        cout << endl;
    }

    void peek() {
        if (top == nullptr) {
            cout << "The stack is empty." << endl;
            return;
        }
        cout << "Current top element: " << top->name << endl;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    int maxSize;
    cout << "Enter maximum size of the stack: ";
    cin >> maxSize;
    cin.ignore();

    Stack list(maxSize);
    int choice;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push stack\n";
        cout << "2. Pop stack\n";
        cout << "3. Peek stack\n";
        cout << "4. View elements in stack\n";
        cout << "5. Check if stack has space\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter name to push: ";
            getline(cin, name);
            list.push(name);
            break;
        case 2:
            cout << "Enter name to pop: ";
            getline(cin, name);
            list.pop(name);
            break;
        case 3:
            list.peek();
            break;
        case 4:
            list.view_stack();
            break;
        case 5:
            if (list.isFull()) {
                cout << "Stack is full." << endl;
            } else {
                cout << "Stack has space." << endl;
            }
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
