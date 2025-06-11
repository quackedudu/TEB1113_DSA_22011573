#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added: " << name << endl;
    }

    void delete_element(string name) {
        Node* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) head->prev = nullptr;
                } else {
                    current->prev->next = current->next;
                }

                if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr) tail->next = nullptr;
                } else if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }

                delete current;
                cout << "Deleted: " << name << endl;
                return;
            }

            current = current->next;
        }

        cout << "Element not found: " << name << endl;
    }

    void view_forward() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Forward: ";
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void view_backward() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Backward: ";
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->prev;
        }
        cout << "nullptr" << endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. View forward\n";
        cout << "4. View backward\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

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
            list.view_forward();
            break;
        case 4:
            list.view_backward();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
