#include<iostream>
#include<string>
using namespace std;
class Student{
public:
string name;
 int rollno;
float marks;

// Student(string name,int rollno, float marks){
//    this->name=name;
//    this->rollno=rollno;
//     this->marks=marks;
// }

void display(){
    cout<<"       STUDENT INFORMATION"<<endl;
     cout<<"Name:"<<name<<endl;
     cout<<"Roll NO:"<<rollno<<endl;
     cout<<"Marks:"<<marks<<endl;
}  

};

int main() {
   Student S[2];
 
     for(int i=0; i<2; i++){
      cout<<"Name:"<<endl;
      cin>>S[i].name;

       cout<<"ROLL NO:"<<endl;
       cin>>S[i].rollno;

      cout<<"Marks:"<<endl;
      cin>>S[i].marks;    


     }
   
    for(int i=0; i<2; i++){

        S[i].display();
    }

return 0; 
}