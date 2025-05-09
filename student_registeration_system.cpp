#include<iostream>
#include<string>
using namespace std;

void insertFirst(){}

void insertLast(){}

void insertAfter(){}

void insertBefore(){}

void insertMenu(){}

void displayAll(){}

void search(){}

void displayMenu(){}

void deleteFirst(){}

void deleteLast(){}

void deleteById(){}

void deleteAll(){}

void deleteMenu(){}

void update(){}

void saveToFile(){}

void loadFromFile(){}

void homePage(){
    cout << "home page is called";
}

void login(){
    string choice;
    
    do{
        cout << "\n═══ Welcome ══════════\n1. Login\n2. Exit\n\nchoose[1-2]: ";
        cin >> choice;
        if(choice == "1"){
            
            string username, password;
            bool loginSuccessful = false;
            int attempt = 3;

            cout << "\n══ Login ════════════════\n";
        
            while(loginSuccessful == false && attempt != 0){
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
            
                if(username == "admin" && password == "admin"){
                    loginSuccessful = true;
                } else {
                    attempt--;
        
                    string isPlural = "attempt";
        
                    if(attempt > 1){
                        isPlural = "attempts";
                    }
        
                    if(attempt != 0){
                        cout << "═════════════════════════\n"
                             << "Incorrect username or password\n"
                             << "You have " << attempt <<  " " << isPlural << " left!\n"
                             << "═════════════════════════\n";
                    }
                    
                }
                }
        
                cout << "═════════════════════════\n";
        
                if(loginSuccessful == true){
                    cout << "Login Successful!\n";
                    homePage();
                } else if(loginSuccessful == false){
                    cout << "System Locked, Too many attemps!\n";
                    break;
                }
    
        } else if (choice == "2"){
            cout << "Program Ended, Thank You!\n";
        } else {
            cout << "There is no option \"" << choice << "\"\n";
        }
    } while(choice != "2");

}


int main(){
    login();
}