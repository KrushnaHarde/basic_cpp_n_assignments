#include <iostream>
using namespace std;

class Deque
{
private:
    int front, rear, size;
    int *deqArray;

public:
    Deque(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        deqArray = new int[size];
    }

    ~Deque()
    {
        delete[] deqArray;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front = rear + 1));
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void insertFront(int item)
    {
        if (isFull())
        {
            cout << "Already full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        deqArray[front] = item;
        cout << "The item '" << item << " ' inserted." << endl;
    }

    void insertRear(int item)
    {
        if (isFull())
        {
            cout << "Already full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        deqArray[rear] = item;
        cout << "The item '" << item << " ' inserted." << endl;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Queue already empty!" << endl;
            return;
        }

        cout << "The item '" << deqArray[front] << " ' deleted." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Queue already empty!" << endl;
            return;
        }

        cout << "The item '" << deqArray[rear] << " ' deleted." << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
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
            cout << deqArray[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % size; // Move to the next index in circular fashion
        }
        cout << endl;
    }
};

int main()
{
    int size, choice, item;
    cout << "Enter the size of the deque: ";
    cin >> size;
    Deque dq(size);

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
        case 1:
            cout << "Enter the item to insert at front: ";
            cin >> item;
            dq.insertFront(item);
            break;
        case 2:
            cout << "Enter the item to insert at rear: ";
            cin >> item;
            dq.insertRear(item);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:4
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}