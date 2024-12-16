#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    Node* prev;

    int time;
    bool isAvailable;

    Node(int time, bool isAvailable = true){
        this->time = time;
        this->isAvailable = isAvailable;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class schedule{
private:
    static const int slot_per_day = 8;
    static const int slot_duration = 1;

    Node* start = new Node(-1);

public:
    schedule(){
        Node* head = nullptr;
        Node* last = nullptr;

        for(int i = 0; i<slot_per_day; i++){
            Node* newNode = new Node(i + 9, true);

            if(head == nullptr){
                head = newNode;
                last = newNode;
                head->next = newNode;
                last->next = newNode;
            }
            else{
                last->next = newNode;
                newNode->prev = last;
                head->prev = newNode;
                newNode->next = head;
                last = newNode;
            }
        }
        start = head;
    }

    void displayAvailable(){
        cout<< "\nAvailble Slots are:\n";

        Node* temp = start;
        for(int i = 0; i<slot_per_day; i++){
            if(temp->isAvailable) cout<<temp->time<<" ";
            else    cout<<"B ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void bookSlot(int time){
        if(time < 9 || time > 17){
            cout<<"Enter valid time : 9 to 17"<<endl;
        }
        Node* temp = start;
        for(int i = 0; i<time - 9; i++){
            temp = temp->next;
        }

        if(temp->isAvailable){
            temp->isAvailable = false;
            cout<<"Slot Booked Successfully"<<endl;
        }
        else{
            cout<<"Seat is Already Booked"<<endl;
        }

    }

    void cancelSlot(int time){
        if(time < 9 || time > 17){
            cout<<"Enter valid time : 9 to 17"<<endl;
        }
        Node* temp = start;
        for(int i = 0; i<time - 9; i++){
            temp = temp->next;
        }
        if(temp->isAvailable)   cout<<"Slot is not Booked"<<endl;
        else{
            temp->isAvailable = true;
            cout<<"Slot cancelled"<<endl;
        }
    }

    void sortListByTime() {
        if (start == nullptr || start->next == start) {
            return; // List is empty or has only one element
        }

        Node* current = start;
        bool swapped;
        do {
            swapped = false;
            Node* nextNode = current->next;
            for (int i = 0; i < slot_per_day - 1; i++) {
                if (current->time > nextNode->time) {
                    swap(current->time, nextNode->time);
                    swap(current->isAvailable, nextNode->isAvailable);
                    swapped = true;
                }
                current = nextNode;
                nextNode = nextNode->next;
            }
            current = start;
        } while (swapped);
    }

    void sortListByTimePointerManipulation() {
        if (start == nullptr || start->next == start) {
            return; // List is empty or has only one element
        }

        bool swapped;
        Node* left;
        Node* right;
        do {
            swapped = false;
            left = start;
            right = start->next;
            for (int i = 0; i < slot_per_day - 1; i++) {
                if (left->time > right->time) {
                    swap(left->time, right->time);
                    swap(left->isAvailable, right->isAvailable);
                    swapped = true;
                }
                left = right;
                right = right->next;
            }
        } while (swapped);
    }
};

int main() {

    schedule t;


    cout<<"\n1 for book seat\n2 for display available seat\n3 for cancel booking \nAny key for exit ";
        int choice;
        do{
            cout<<"Enter choice: ";

            cin>>choice;

            int time;

            switch(choice){
            case 1:
                cout<<"Enter time: ";
                cin>>time;
                t.bookSlot(time);
                break;

            case 2:
                t.displayAvailable();
                break;
            case 3:
                cout<<"Enter time : ";
                cin>>time;
                t.cancelSlot(time);
                break;

            case 4:
                t.sortListByTime();
                cout<<"List sorted by time. "<<endl;
                break;

            case 5:
                t.sortListByTimePointerManipulation();
                cout<<"List sorted using pointer manipulation. "<<endl;
                break;

            default:
                cout<<"EXITING...."<<endl;
                break;
            }
        }while(choice <=5 && choice>0);
    return 0;
}