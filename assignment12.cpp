#include <iostream>
#include <list>
using namespace std;

// Template class for items in the priority queue
template <typename T>
class Item {
public:
    T data;
    int priority;

    Item(T data, int priority) : data(data), priority(priority) {}

    // Overload the <= operator to compare priority
    bool operator<=(const Item<T>& other) const {
        return priority >= other.priority; // Higher priority comes first
    }
};

// Template class for Priority Queue
template <typename T>
class PriorityQueue {
private:
    list<Item<T>> pq; // List to store the priority queue

public:
    // Insert an item into the priority queue
    void insert(T data, int priority) {
        Item<T> newItem(data, priority);
        // Find the appropriate position to insert based on priority
        auto it = pq.begin();
        while (it != pq.end() && (*it) <= newItem) {
            ++it;
        }
        pq.insert(it, newItem);
    }

    // Retrieve and remove the item with the highest priority
    T pop() {
        if (pq.empty()) {
            throw runtime_error("Priority Queue is empty");
        }
        T highestPriorityData = pq.front().data;
        pq.pop_front();
        return highestPriorityData;
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return pq.empty();
    }

    // Display the priority queue (for debugging purposes)
    void display() const {
        for (const auto& item : pq) {
            cout << "Data: " << item.data << ", Priority: " << item.priority << endl;
        }
    }
};

int main() {
    PriorityQueue<string> pq;

    // Insert data items with priority
    pq.insert("Task A", 2);
    pq.insert("Task B", 1);
    pq.insert("Task C", 3);

    cout << "Priority Queue after insertion:" << endl;
    pq.display();

    // Remove the highest priority item
    cout << "\nPopped item with highest priority: " << pq.pop() << endl;

    cout << "\nPriority Queue after popping:" << endl;
    pq.display();

    return 0;
}
