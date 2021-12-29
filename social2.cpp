/*
This program will display the profile ID  users in the given main function.
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

    Profile(string usrn, string dspn) {
       username=usrn;
       displayname=dspn;
    }
Profile(){

    username="";
    displayname="";
}
string getUsername() {

     return username;
}

string getFullName() {

     return displayname + " (@" +username + ")";
}

// change display name
   void setDisplayName(string dspn) {
       displayname=dspn;
   }
};

class Network {
private:
static const int MAX_USERS = 20;
int numUsers;
Profile profiles[MAX_USERS];
int findID(string usrn){
    for (int i=0; i<numUsers; i++) {
      if (profiles[i].getUsername() == usrn) {
        return i;
      }
    }
    return -1;
}

public:
Network() {
   numUsers = 0;
}
bool addUser(string usrn, string dspn) {
   std::string::size_type i=0;
   while ( i<usrn.length() ) {
     bool test = std::isalnum(usrn[i]) == 0;
     if(test)
     return false;
     i++;
   }
   i = 0;
   while ( i<dspn.length() ) {
     bool test = std::isalnum(dspn[i]) == 0;
     if(test)
     return false;
     i++;
   }
if (!usrn.empty() && !dspn.empty() && findID(usrn) == -1 && numUsers < MAX_USERS) {
   Profile newUser(usrn, dspn);
   profiles[numUsers++] = newUser;
   return true;
}
return false;
}

};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
