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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* newNode = new Node(name);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
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
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
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
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "[REAR]" << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue line;
    int choice;
    string name;

    do {
        cout << "\nQueue Menu:\n";
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