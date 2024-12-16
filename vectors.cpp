#include<iostream>
#include<vector>
using namespace std;


void lastOccurance(vector<int> vect, int target){
    int occurance, i = 0;
    for(int element: vect){
        if(element == target){
            occurance = i;
        }
        i++;
    }
    cout<<occurance<<endl;
    
}

int main(){
    vector<int> v;

    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl<<endl;
    
    v.push_back(1);
    cout<<v[0]<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl<<endl;


    v.push_back(3);
    cout<<v[1]<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl<<endl;

    v.push_back(5);
    cout<<v[2]<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl<<endl;

    v.push_back(7);
    cout<<v[3]<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl<<endl;

    vector<int> vect{0,1,3,4,5,1,23,2,3,1,15,23};
    lastOccurance(vect , 1);

}
