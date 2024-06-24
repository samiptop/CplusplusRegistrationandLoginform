#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
using namespace std;

class Login {

    private:
     string LoginID,Password;

    public:
    Login():LoginID(""),Password("") {}
     
    void setID(string id) {
    LoginID=id;
    }

    void setPW (string pw) {
    Password=pw;
    }
      
    string getID() {
        return LoginID;
    }

    string getPW() {
        return Password;
    }

};

void registration(Login log) {

    system("cls");
    string id,pw;
    cout<<"\tEnter Login ID: ";
    cin>>id;
    log.setID(id);

    start:
    cout<<"\tEnter A Strong Password";
    cin>>pw;
    if(pw.length() >=8){
    log.setPW(pw);
    }
    else {
        cout<<"\tEnter Minimum 8 Characters!"<<endl;
        goto start;
    }
    
    ofstream outfile("D:\C++\Beginner Projects !\Registration and Login Form\Ofile.txt", ios::app);
    if(!outfile) {
        cout <<"\tError: File Cannot  Be Open"<< endl;
    }
    else {
        outfile<<"\t"<<log.getID()<<" : "<<log.getPW()<<endl;
        cout<<"\tUser Registered Successfully!"<<endl;

    }
    outfile.close();
    Sleep(3000);

}

void Logine(){
    system("cls");
    string id,pw;
    cout<<"\tEnter Login ID: ";
    cin>>id;

    cout<<"\tEnter Password: ";
    cin>>pw;
    ifstream infile("D:\C++\Beginner Projects !\Registration and Login Form\Ofile.txt");
    if(!infile) {
        cout<<"\tError: File Cannnot Be Opened!"<<endl;
    } 
    else {
        string line;
        bool found=false;
        while(getline(infile,line)) {
            stringstream ss;
            ss<<line;
            string userID,userPW;
            char delimiter;
            ss>>userID>>delimiter>>userPW;

            if(id==userID && pw==userPW) {
                found=true;
                cout <<"\tPlease Wait";
                for (int i=0; i<3; i++) {
                    cout <<".";
                    Sleep(800);
                }
                system("cls");
                cout <<"\t Welcome To This Page"<<endl;
            }
        }
        if(!found) {
            cout << "\tError: Incorrect Login ID or Password"<<endl;
        }
        infile.close();
    }
    Sleep(5000);
}

int main(){

 Login log; 

 bool exit = false;
 while(!exit){
 system("cls");
 int val;
 cout<<"\tWelcome To Registration & Login Page"<<endl;
 cout<<"\t************************************"<<endl;
 cout<<"\t1.Register"<<endl;
 cout<<"\t2.Login"<<endl;
 cout<<"\t3.Exit"<<endl;
 cout<<"\tEnter Choice: ";
 cin>>val;

 if(val==1) {
  registration(log);
 }

 else if(val==2) {
    Logine();
 }

 else if(val==3) {
    system("cls");
    exit=true;
    cout<<"\tGood Luck!"<<endl;
    Sleep(3000);
 }
 Sleep(3000);
 
 }

}
