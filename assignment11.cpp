#include<iostream>
using namespace std;

class Job{

    int size, front, rear;
    string *arr;

    public:

    Job(int n){
        size = n;
        front = rear = -1;
        arr = new string[n];
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == size-1;
    }

    void push(string x){
        if(isEmpty()){
            rear = front = 0;
            arr[0] = x;
        }
        else if(isFull()){
            return;
        }
        else{
            rear = rear+1;
            arr[rear] = x;
        }
        
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        else{
            if(rear == front){
                front = rear = -1;
            }
            else{
                front = front+1;
            }
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Job queue is empty."<<endl;
        }
        else{
            for(int i = front; i<=rear; i++){
            cout<<arr[i]<<endl;
        }
        }
        }

};

int main(){
    int n;
    cout<<"Enter the size of queue: "<<endl;
    cin>>n;

    Job j(n);
    int choice;
    string job;

    do{

        cout<<"1. Add a new job."<<endl;
        cout<<"2. Delete a job."<<endl;
        cout<<"3. Display the Job Queue."<<endl;
        cout<<"4. Exit."<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter a job name to be added in the Queue: "<<endl;
            cin>>job;
            j.push(job);
            break;

            case 2:
            j.pop();
            break;

            case 3:
            j.display();
            break;

            case 4:
            cout<<"Exiting..."<<endl;
            break;

            default :
            cout<<"Invalid choice!"<<endl;
        }
    }while(choice!=4);

    return 0;
}