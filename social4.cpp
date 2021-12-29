/*
This program will display Mario's and Yoshi's timeline used the given main function.
*/

#include <iostream>

using namespace std;

struct Post {
    string username, message;
};
//define class
class Profile {
//private variable
private:
    string username;
    string displayname;
// all function and varaible is puclic inside in public:
public:
// Profile constructor for a user(initalizing
// private variables username=usrn,displayname=dspn)
    Profile(string usrn, string dspn) {
        username = usrn;
        displayname = dspn;
    }
//Deafault Profile constructor (username="",displayname="")
    Profile() {

        username = "";
        displayname = "";
    }
//Return username
    string getUsername() {
        return username;
    }
// Return name is the format: "displayname(@username)"
    string getFullName() {
        return displayname + " (@" + username + ")";
    }
// change display name
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};

class Network {
private:
    static const int MAX_USERS = 20;
    static const int MAX_POSTS = 100;
    int numUsers = 0;
    Post posts[MAX_POSTS];
    int numPosts = 0;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];

    int findID(string usrn) {
        for (int i = 0; i < numUsers; i++) {
            if (profiles[i].getUsername() == usrn) {
                return i;
            }
        }

        return -1;
    }
//indentation was good before dont know why it changed all of a sudden after save pls forgive this offence
public:
    Network() {
                for (int i=0; i< MAX_USERS; i++) {
                        for (int j=0; j< MAX_USERS; j++) {
                                following[i][j] = false;
                    }
                }
                numPosts = 0;
        }

        bool addUser(string usrn, string dspn) {
            Profile newUser(usrn, dspn);

            if (numUsers < MAX_USERS) {
                profiles[numUsers++] = newUser;
                return true;
            }

            return false;
        }

        bool follow(string usrn1, string usrn2) {
            int usrnID1 = findID(usrn1);
            int usrnID2 = findID(usrn2);

            if (usrnID1 != -1 && usrnID2 != -1) {
                following[usrnID1][usrnID2] = true;
                return true;
            }

            return false;
        }

        void printDot() {
            cout << "digraph {" << "\n";

                for (int i=0; i<numUsers; i++) {
                        cout << " \"@" << profiles[i].getUsername() << "\"\n";
                }

                for (int i=0; i<numUsers; i++) {
                        for (int j=0; j<numUsers; j++) {
                                if(following[i][j]) {
                                    cout << " \"@" << profiles[i].getUsername() << "\" -> \"@"
                                    << profiles[j].getUsername() << "\"\n";
                                }
                        }
                }

                cout << "}" << "\n";
        }

        bool writePost(string usern, string msg) {
                int index = findID(usern);
                if(index == -1 || numPosts == MAX_POSTS) {
                        return false;
                }

                posts[numPosts].username = usern;
                posts[numPosts].message = msg;

                numPosts++;

                return true;
        }

        bool printTimeline(string usern) {

                int userIndex = findID(usern);
                if(userIndex == -1) {
                        return false;
                }

                for(int i=numPosts-1; i>=0; i--) {

                        Post p = posts[i];
                        int writerindex = findID(p.username);

                        if(p.username == usern) {
                                cout << profiles[userIndex].getFullName() << ": " << p.message << endl;
                        } else if(following[userIndex][writerindex]) {
                                cout << profiles[writerindex].getFullName() << ": " << p.message << endl;
                        }

                }

                return true;
        }
};
//just copy and paste  the given main function so ndentation is diff
int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
