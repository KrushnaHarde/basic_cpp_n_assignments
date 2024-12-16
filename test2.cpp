// Binary Numbers:

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};

class BinaryNumber{
    public:
    Node* head;
    Node* tail;

    BinaryNumber(){
        head=nullptr;
        tail=nullptr;
    }

    void insertBit(int bit){
        Node* newNode=new Node(bit);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;    
        }
    }

    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }

    void onesComp(){
        Node* temp=head;
        while(temp!=nullptr){
            temp->data=1-temp->data;
            temp=temp->next;
        }
    }

    void twosComp(){
        // onesComp();
        Node* temp=tail;
        int carry=1;
        while(temp!=nullptr && carry>0){
            int sum=temp->data+carry;
            temp->data=sum%2;
            carry=sum/2;
            temp=temp->prev;
        }

    }

    BinaryNumber binaryAddition(BinaryNumber& other){
        BinaryNumber result;
        Node* temp1=tail;
        Node* temp2=other.tail;
        int carry =0;

        while(temp1!=nullptr || temp2!=nullptr || carry>0){
            int sum=carry;
            if(temp1!=nullptr){
                sum+=temp1->data;
                temp1=temp1->prev;
            }
            if(temp2!=nullptr){
                sum+=temp2->data;
                temp2=temp2->prev;
            }

            result.insertBit(sum%2);
            carry=sum/2;
        }
        return result;

    }
};

int main(){
    BinaryNumber bin1, bin2, sum;
    int bit, n;

    cout << "Enter number of bits for the first binary number: ";
    cin >> n;
    cout << "Enter binary number: ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        bin1.insertBit(bit);
    }

    cout << "1's Complement of the first binary number: ";
    bin1.onesComp();
    bin1.display();

    cout << "2's Complement of the first binary number: ";
    bin1.twosComp();
    bin1.display();

    cout << "Enter number of bits for the second binary number: ";
    cin >> n;
    cout << "Enter binary number: ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        bin2.insertBit(bit);
    }

    sum = bin1.binaryAddition(bin2);
    cout << "Sum of two binary numbers: ";
    sum.display();

    return 0;
}