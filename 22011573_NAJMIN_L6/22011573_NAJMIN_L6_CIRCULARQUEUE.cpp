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

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* newNode = new Node(name);
        if (front == nullptr) {
            front = rear = newNode;
            rear->next = front;
        } else {
            newNode->next = front;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "The queue is empty. Nothing to dequeue." << endl;
            return;
        }

        Node* temp = front;
        string dequeuedName = temp->name;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            rear->next = front;  front
        }

        delete temp;
        cout << "Dequeued: " << dequeuedName << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "The queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: [FRONT] -> ";
        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != front);
        cout << "[REAR - points back to FRONT]" << endl;
    }

    ~CircularQueue() {
        if (front == nullptr) {
            return;
        }
        Node* current = front;
        Node* temp;
        rear->next = nullptr; 
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    CircularQueue line;
    int choice;
    string name;

    do {
        cout << "\nCircular Queue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display line\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        } else {
            cin.ignore();
        }

        switch (choice) {
        case 1:
            cout << "Enter name to add to the line: ";
            getline(cin, name);
            line.enqueue(name);
            break;
        case 2:
            line.dequeue();
            break;
        case 3:
            line.display();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}