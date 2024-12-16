#include <iostream>
using namespace std;

class Node {
public:
    int data;           // Seat number
    Node* prev;        // Pointer to the previous node
    Node* next;        // Pointer to the next node
    bool isBooked = false; // Status of the seat

    // Constructor to initialize node
    Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class LinkedList {
public:
    Node* head; // Head of the linked list

    // Constructor
    LinkedList(Node* head = nullptr) {
        this->head = head;
    }

    // Function to create nodes
    void create(int n) {
        for (int i = 1; i <= n; i++) {
            Node* temp = new Node(i); // Create a new node with seat number i
            if (head == nullptr) {
                head = temp; // Set head if it's the first node
                head->next = temp;
                head->prev = temp;
            } else {
                Node* tail = head->prev; // Get the last node
                tail->next = temp;       // Link tail to new node
                temp->next = head;       // Link new node to head
                temp->prev = tail;       // Link new node back to tail
                head->prev = temp;       // Update head's prev to new node
            }
        }
    }

    // Function to display available seats
    void display() {
        Node* temp = head;
        do {
            if (!temp->isBooked) {
                cout << temp->data << " o "; // 'o' for available
            } else {
                cout << temp->data << " x "; // 'x' for booked
            }
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Function to book a seat
    bool book(int n) {
        Node* temp = head;
        do {
            if (temp->data == n) {
                if (!temp->isBooked) {
                    temp->isBooked = true; // Mark seat as booked
                    cout << "Seat " << n << " is booked." << endl;
                    return true;
                } else {
                    cout << "Seat " << n << " is already booked!" << endl;
                    return false;
                }
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat not found!" << endl;
        return false;
    }

    // Function to cancel a booking
    bool cancel(int n) {
        Node* temp = head;
        do {
            if (temp->data == n) {
                if (temp->isBooked) {
                    temp->isBooked = false; // Mark seat as not booked
                    cout << "Seat " << n << " is cancelled." << endl;
                    return true;
                } else {
                    cout << "Seat " << n << " is not booked." << endl;
                    return false;
                }
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Seat not found!" << endl;
        return false;
    }
};

int main() {
    const int ROWS = 10;               // Number of rows
    const int SEATS_PER_ROW = 7;      // Number of seats per row
    LinkedList* theater[ROWS];         // Array of linked lists for each row

    // Initialize each row
    for (int i = 0; i < ROWS; i++) {
        theater[i] = new LinkedList();
        theater[i]->create(SEATS_PER_ROW);
    }

    int choice;
    cout << "Ticket booking system: " << endl;

    do {
        cout << "1. Display available seats." << endl;
        cout << "2. Book a seat." << endl;
        cout << "3. Cancel a seat." << endl;
        cout << "4. Quit." << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < ROWS; i++) {
                    cout << "Row " << (i + 1) << ": ";
                    theater[i]->display();
                }
                break;

            case 2: {
                int row, n;
                cout << "Enter the row (1-10) and seat (1-7): " << endl;
                cin >> row >> n;
                if (row >= 1 && row <= ROWS && n >= 1 && n <= SEATS_PER_ROW) {
                    theater[row - 1]->book(n);
                } else {
                    cout << "Invalid row or seat number." << endl;
                }
                break;
            }

            case 3: {
                int row, n;
                cout << "Enter the row (1-10) and seat (1-7): " << endl;
                cin >> row >> n;
                if (row >= 1 && row <= ROWS && n >= 1 && n <= SEATS_PER_ROW) {
                    theater[row - 1]->cancel(n);
                } else {
                    cout << "Invalid row or seat number." << endl;
                }
                break;
            }

            case 4:
                cout << "Quitting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 4);

    // Clean up allocated memory
    for (int i = 0; i < ROWS; i++) {
        delete theater[i];
    }

    return 0;
}