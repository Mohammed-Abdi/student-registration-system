#include<iostream>
#include<string>
using namespace std;

void insertFirst(){}

void insertMoreFirst(){}

void insertLast(){}

void insertMoreLast(){}

void insertAfter(){}

void insertMoreAfter(){}

void insertBefore(){}

void insertMoreBefore(){}

void insertionMenu(){
    cout << "\n═══ Insertion Menu ══════════\n";
}

void displayAll(){}

void search(){}

void displayMenu(){
    cout << "display function is called";
}

void deleteFirst(){}

void deleteLast(){}

void deleteById(){}

void deleteAll(){}

void deletionMenu(){
    cout << "delete function is called";
}

void updatingMenu(){
    cout << "update function is called";
}

void saveToFile(){}

void loadFromFile(){}

void homePage(){
    string choice;
    cout << "\n═══ Welcome! Admin ══════════";
    do{

    cout << "\n1. Insert Student\n"
         << "2. Display Student\n"
         << "3. Delete Student\n"
         << "4. Update Student\n"
         << "5. Logout\n\nchoose[1-5]: ";
    cin >> choice;
    if(choice == "1"){
        insertMenu();
    } else if(choice == "2"){
        displayMenu();
    } else if(choice == "3"){
        deleteMenu();
    } else if(choice == "4"){
        updateMenu();
    } else if(choice == "5"){
        cout << "------------------\n"
             << "Logout Successful\n"
             << "------------------\n";
    } else {
        cout << "There is no option \"" << choice << "\"\n";
    }

    } while(choice != "5");
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
                        cout << "------------------------------\n"
                             << "Incorrect username or password\n"
                             << "You have " << attempt <<  " " << isPlural << " left!\n"
                             << "------------------------------\n";
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