#include <iostream>
#include <stdexcept>
using namespace std;

class CircularQueue {
private:
    static const int MAX_SIZE = 100;
    int* arr;
    int rear;
    int front;
    int count;

public:
    // Constructor
    CircularQueue() {
        arr = new int[MAX_SIZE];
        rear = 0;
        front = 0;
        count = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // enqueue
    void enqueue(int value) {
        if (count == MAX_SIZE) {
            throw runtime_error("Queue is full");
        }
        arr[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
        count++;
    }

    // dequeue
    int dequeue() {
        if (count == 0) {
            throw runtime_error("Queue is empty");
        }
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        return value;
    }

    // front value
    int frontValue() const {
        if (count == 0) {
            throw runtime_error("Queue is empty");
        }
        return arr[front];
    }

    // print all elements
    void display() const {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SIZE;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == MAX_SIZE; }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}
