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

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void add_element(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Added: " << name << endl;
    }

    void delete_element(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->name == name) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if (current == head) {
                        head = current->next;
                    }
                    delete current;
                }
                cout << "Deleted: " << name << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Element not found: " << name << endl;
    }

    void view_forward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Forward: ";
        Node* current = head;
        do {
            cout << current->name << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head)" << endl;
    }

    void view_backward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Backward: ";
        Node* current = head->prev;
        Node* tail = current;
        do {
            cout << current->name << " <-> ";
            current = current->prev;
        } while (current != tail);
        cout << "(back to tail)" << endl;
    }

    ~DoublyLinkedList() {
        if (head == nullptr) return;

        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
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
