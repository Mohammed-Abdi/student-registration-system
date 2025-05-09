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
    string choice;
    do{
        cout << "\n═══ Insertion Menu ══════════\n"
             << "1. Insert First\n"
             << "2. Insert Last\n"
             << "3. Insert After a Student (By ID)\n"
             << "4. Insert Before a Student (By ID)\n"
             << "5. Back\n\nchoose[1-5]: ";
        cin >> choice;

        if(choice == "1"){
            insertFirst();
            insertMoreFirst();
        } else if(choice == "2"){
            insertLast();
            insertMoreLast();
        } else if(choice == "3"){
            insertAfter();
            insertMoreAfter();
        } else if(choice == "4"){
            insertBefore();
            insertMoreBefore();
        } else if(choice == "5"){
            cout << "-----------------------\n"
                 << "Redirecting to homepage ...\n"
                 << "-----------------------\n";
        } else {
            cout << "There is no option \"" << choice << "\"\n";
        }

    } while(choice != "5");
}

void displayAll(){}

void search(){}

void displayMenu(){
    string choice;
    do{
        cout << "\n═══ Display Menu ══════════\n"
             << "1. Display All\n"
             << "2. Search By ID\n"
             << "3. Back\n\nchoose[1-5]: ";
        cin >> choice;

        if(choice == "1"){
            displayAll();
        } else if(choice == "2"){
            search();
        } else if(choice == "3"){
            cout << "------------------\n"
                 << "Redirecting to homepage ...\n"
                 << "------------------\n";
        } else {
            cout << "There is no option \"" << choice << "\"\n";
        }

    } while(choice != "3");
}

void deleteFirst(){}

void deleteLast(){}

void deleteById(){}

void deleteAll(){}

void deletionMenu(){
    string choice;
    do{
        cout << "\n═══ Deletion Menu ══════════\n"
             << "1. Delete First\n"
             << "2. Delete Last\n"
             << "3. Delete By ID\n"
             << "4. Delete All\n"
             << "5. Back\n\nchoose[1-5]: ";
        cin >> choice;

        if(choice == "1"){
            deleteFirst();
        } else if(choice == "2"){
            deleteLast();
        } else if(choice == "3"){
            deleteById();
        } else if(choice == "4"){
            deleteAll();
        } else if(choice == "5"){
            cout << "------------------\n"
                 << "Redirecting to homepage ...\n"
                 << "------------------\n";
        } else {
            cout << "There is no option \"" << choice << "\"\n";
        }

    } while(choice != "5");
}

void updatingMenu(){
    string choice;
    do{
        cout << "\n═══ Updating Menu ══════════\n"
             << "1. Update Name\n"
             << "2. Update Age\n"
             << "3. Update ID\n"
             << "4. Update Department\n"
             << "5. Back\n\nchoose[1-5]: ";
        cin >> choice;

        if(choice == "1"){
            insertFirst();
        } else if(choice == "2"){
            insertLast();
        } else if(choice == "3"){
            insertAfter();
        } else if(choice == "4"){
            insertBefore();
        } else if(choice == "5"){
            cout << "------------------\n"
                 << "Redirecting to homepage ...\n"
                 << "------------------\n";
        } else {
            cout << "There is no option \"" << choice << "\"\n";
        }

    } while(choice != "5");
}

void saveToFile(){}

void loadFromFile(){}

void homePage(){
    string choice;
    do{
       cout << "\n═══ HomePage ══════════"
            << "\n1. Insert Student\n"
            << "2. Display Student\n"
            << "3. Delete Student\n"
            << "4. Update Student\n"
            << "5. Logout\n\nchoose[1-5]: ";
       cin >> choice;
       if(choice == "1"){
           insertionMenu();
       } else if(choice == "2"){
           displayMenu();
       } else if(choice == "3"){
           deletionMenu();
       } else if(choice == "4"){
           updatingMenu();
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