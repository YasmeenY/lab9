/*
This program will display usernme, fullname from tthe given main function.
*/

#include <iostream>

using namespace std;
// define class
class Profile{
// private variable
private:
    string username;
    string displayname;
  
// all function and varaible is puclic inside in public:
public:
// Profile constructor for a user(initalizing
// private variables username=usrn,displayname=dspn)
    Profile(string usrn, string dspn) {
      username=usrn;
      displayname=dspn;
    }
  
//Deafault Profile constructor (username="",displayname="")
Profile();
  
//Return username
// Return username
   string getUsername() {
     return username;
}
  
// Return name is the format: "displayname(@username)"
   string getFullName() {
     return displayname+" (@"+username+")";
}
  
// change display name
   void setDisplayName(string dspn) {
       displayname=dspn;
   }
};

// main function
int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
