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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Added: " << name << endl;
    }

    void delete_element(string name) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->name == name) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                if (current == tail) {
                    tail = previous;
                }
                delete current;
                cout << "Deleted: " << name << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Element not found: " << name << endl;
    }

    void view_elements() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "List: ";
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. View elements\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        switch (choice) {
        case 1:
            cout << "Enter name to add: ";
            getline(cin, name);
            list.add_element(name);
            break;
        case 2:
            cout << "Enter name to delete: ";
            getline(cin, name);
            list.delete_element(name);
            break;
        case 3:
            list.view_elements();
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
