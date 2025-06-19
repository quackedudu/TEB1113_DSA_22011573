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
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        cout << "Added: " << name << endl;
    }

    void delete_element(string name) {
        if (head == nullptr) {
            cout << "Element not found: " << name << endl;
            return;
        }

        Node* current = head;
        Node* previous = tail;
        bool found = false;

        do {
            if (current->name == name) {
                found = true;
                break;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        if (!found) {
            cout << "Element not found: " << name << endl;
            return;
        }

        if (head == tail && current == head) {
            delete current;
            head = tail = nullptr;
        } else {
            previous->next = current->next;
            if (current == head)
                head = current->next;
            if (current == tail)
                tail = previous;
            tail->next = head;
            delete current;
        }

        cout << "Deleted: " << name << endl;
    }

    void view_elements() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        cout << "List: ";
        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != head);
        cout << head->name << "(back to start)" << endl;
    }

    ~LinkedList() {
        if (head == nullptr) return;

        tail->next = nullptr;

        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
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
