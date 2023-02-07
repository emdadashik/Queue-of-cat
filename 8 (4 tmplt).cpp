#include <iostream>
using namespace std;

template <typename T>
class Queue {
public:
    class Node {
    public:
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    Queue() : head(nullptr), tail(nullptr), size(0) {}

    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void dequeue() {
        if (!head) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T front() {
        if (!head) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return head->data;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout << "Queue size: " << q.getSize() << endl;
    cout << q.front() << endl;
    q.dequeue();

    cout << q.front() << endl;
    q.dequeue();

    cout << q.front() << endl;
    q.dequeue();

    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}
