#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map <string , long long> statePopulations;
    int n;
    cout<<"Enter the no. of states you want to enter: "<<endl;
    cin>>n;
    cin.ignore();

    for(int i=0; i<n; i++){
        string stateName;
        long long population;

        cout<<"Enter the state "<<(i+1)<<" : ";
        getline(cin,stateName);
        cout<<"Enter the population: "<<endl;
        cin>>population;
        cin.ignore();
        
        statePopulations[stateName]=population;
    }

        cout<<"You have entered the following states: "<<endl;
        for(map<string,long long>::iterator it=statePopulations.begin(); it!=statePopulations.end(); it++){
            cout<<"State : "<<it->first<<" , "<<"Population : "<<it->second<<endl;
        }

        string searchState;
        cout<<"Enter the state you want to know the population of: "<<endl;
        getline(cin,searchState);

        map<string,long long>::iterator it=statePopulations.find(searchState);
        if(it!=statePopulations.end()){
            cout<<"State : "<<it->first<<" Population : "<<it->second<<endl;
        }
        else{
            cout<<"Sate not found in map!"<<endl;
        }

    return 0;
}