// file id pattern of data which stored in computer in specific manner
#include<iostream>
#include<fstream>
using namespace std;

class student{
     char name[20];
     int roll;
     int age;
     char fav_sub[20];

     public:
     void getdata(){
        cout<<"Enter the name of Student "<<endl;
        cin>>name;
        cout<<"Enter the roll of Student "<<endl;
        cin>>roll;
        cout<<"Enter the age of Student "<<endl;
        cin>>age;
        cout<<"Enter the fav subject of Student "<<endl;
        cin>>fav_sub;
     }

     void readIn(){
        istream file;
        file.open("database.txt");
        string st;
        while(!file.eof()){
           getline(file,st);
           cout<<st<<endl;
        }
        file.close();
     }

     void WriteIn(){
        ostream out;
        out.open("database.txt");
        char y;
        do{
            getdata();
            out<<"The name of student is "<<name<<endl;
            out<<"The roll of student is "<<roll<<endl;
            out<<"The age of student is "<<age<<endl;
            out<<"The fav sub of student is "<<fav_sub<<endl;

            cout<<"do u want more records (y/n)";
            cin>>y;
        }while(y!='n');
        // out.close();
     }
};
int main(){
student S;
S.WriteIn();
S.readIn();
}