#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Personal{
    string name;
    string dob;
    string tele;
    public:
    Personal(){
        name = dob = tele = " ";
    }
    Personal(string name){
        this->name = name;
    }
    void input(){
        cout<<"Enter the name: "<<endl;
        cin>>name;
        cout<<"Enter the date of birth: "<<endl;
        cin>>dob;
        cout<<"Enter the telephone no.: "<<endl;
        cin>>tele;
    }
    void display(){
        cout<<"Name : "<<name<<"Date of birth: "<<dob<<"Telephone no.: "<<tele<<endl;
    }

    friend bool comparename(Personal& ,Personal& );
    friend bool operator == (const Personal&, const Personal& );
};

bool comparename(Personal&p1, Personal&p2){
    return p1.name<p2.name;
}

bool operator == (const Personal&p1, const Personal&p2){
    return(p1.name==p2.name);
}

int main(){
    vector<Personal>records;
    Personal p1;
    int n;

    cout<<"Enter the no. of records you want to add: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        p1.input();
        records.push_back(p1);
    }

    sort(records.begin(),records.end(),comparename);
    cout<<"Sorted records: "<<endl;
        for(auto ele : records){
            ele.display();
        }
    

    string nm;
    cout<<"Enter the name to be searched: "<<endl;
    cin>>nm;

    Personal target(nm);

    vector<Personal>::iterator it;
    it = find(records.begin(),records.end(),target);

    if(it!=records.end()){
        cout<<"Record Found!"<<endl;
        it->display();
    }
    else{
        cout<<"Record not found"<<endl;
    }

    return 0;
}