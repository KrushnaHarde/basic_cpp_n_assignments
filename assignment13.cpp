#include <iostream>
using namespace std;

class Deque
{
private:
    int arr[100];
    int front, rear, size;

public:
    // Constructor to initialize deque
    Deque(int size)
    {
        this->size = size;
        front = -1;
        rear = 0;
    }

    // Check if the deque is full
    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    // Check if the deque is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Insert element at the front
    void insertFront(int key)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        if (front == -1)
        { // If deque is initially empty
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        { // Wrap around
            front = size - 1;
        }
        else
        {
            front = front - 1;
        }

        arr[front] = key;
    }

    // Insert element at the rear
    void insertRear(int key)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        if (front == -1)
        { // If deque is initially empty
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
        { // Wrap around
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        arr[rear] = key;
    }

    // Delete element from the front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear)
        { // Queue has only one element
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }

    // Delete element from the rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear)
        { // Queue has only one element
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear = rear - 1;
        }
    }

    // Get the front element of the deque
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element of the deque
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rear];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % size; // Move to the next index in circular fashion
        }
        cout << endl;
    }
};

// Driver program to test the deque
int main()
{
    int size, item;
    cout << "Enter the size of the deque: ";
    cin >> size;
    Deque dq(size);

    char choice;
    do
    {
        cout << "\n--- Deque Operations ---" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter the item to insert at front: ";
            cin >> item;
            dq.insertFront(item);
            break;
        case '2':
            cout << "Enter the item to insert at rear: ";
            cin >> item;
            dq.insertRear(item);
            break;
        case '3':
            dq.deleteFront();
            break;
        case '4':
            dq.deleteRear();
            break;
        case '5':
            dq.display();
            break;
        default:
            cout << "Invalid choice. Exiting...." << endl;
            break;
        }
    } while ('0' < choice && choice <= '5');

    return 0;
}
