#include<iostream>
#include<cstring>
using namespace std;

//class
class BankAccount{

private:   
 int accNo;
string owner;
float balance;

public:
BankAccount(string s,int a,float b){

       accNo=a;
       balance=b;
       owner=s;
}

// BankAccount(){
//     accNo=0;
//   owner="unknown";
//     balance=0;
 
// }

 void deposit(int a){
     
   
   int  newAmount=a+balance;
    cout<<"NEW AMOUNT:"<<newAmount<<endl;
   
 }

  void withdraw(int w){

       if (balance>=w){
          balance-=w;
       } else 
         cout<<"insufficient balance"<<endl;
     
         cout<<"REMAINING BALANCE:"<<balance<<endl;
  }  
  void display() {

      cout<<"     ACCOUNT INFORMATION"<<endl;
   cout<<"Account Number:"<<accNo<<endl;
   cout<<"Owner Name:"<<owner<<endl;
   cout<<"Balance:"<<balance<<endl;

  }
};



int main(){ 
   
  BankAccount s1("Waqar",4823122,100000.000);

  BankAccount s2("hanan",3428342,5000.00);

   int amount;
    cout<<"enter amount:"<<endl;
     cin>>amount;

 s1.deposit(amount);
 s2.deposit(amount);
  s1.withdraw(2000);
 s2.withdraw(500);
  s1.display();
   s2.display();
 return 0;   
}
