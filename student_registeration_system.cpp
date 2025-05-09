#include<iostream>
#include<string>
using namespace std;

struct student {
    string firstName, lastName, id, department;
    int age;
    struct student *pre;
    struct student *next;
};

struct student *start = NULL;

void insertFirst(){
    string firstNameData, lastNameData, idData, departmentData;
    int ageData;
    cout << "\n╔════ Inserting First ═════════════════════╗\n"
         << "║ ➤  Enter First Name: ";
    cin  >> firstNameData;
    cout << "║ ➤  Enter Last Name: ";
    cin  >> lastNameData;
    cout << "║ ➤  Enter Age: ";
    cin  >> ageData;
    cout << "║ ➤  Enter Student ID: ";
    cin  >> idData;
    cout << "║ ➤  Enter Department: ";
    cin.ignore();
    getline(cin, departmentData);
    cout << "╚══════════════════════════════════════════╝\n";

    struct student *temp;
    temp = new student;
    temp -> firstName = firstNameData;
    temp -> lastName = lastNameData;
    temp -> age = ageData;
    temp -> id = idData;
    temp -> department = departmentData;

    if(start == NULL){
        start = temp;
        temp -> pre = NULL;
        temp -> next = NULL;
    } else {
        start -> pre = temp;
        temp -> next = start;
        start = temp;
        start -> pre = NULL;
        
    }

    cout << "\n[✔] Student Inserted at First Successfully!\n\n";
}

void insertMoreFirst(){
    string choice;
    do{
        cout << "➤  Do you want to add more? [Y/N]: ";
        cin >> choice;
        if(choice == "Y" || choice == "y"){
            insertFirst();
        } else if(choice == "N" || choice == "n"){
            cout << "\n➤  Redirecting to Insert Page...\n\n";
            break;
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
        }
    } while(choice != "N" && choice != "n");
}

void insertLast(){}

void insertMoreLast(){}

void insertAfter(){}

void insertMoreAfter(){}

void insertBefore(){}

void insertMoreBefore(){}

void insertionMenu(){
    string choice;
    do{
        cout << "\n╔════ Insert ═════════════════════════╗\n"
             << "║ 1. Insert First                     ║\n"
             << "║ 2. Insert Last                      ║\n"
             << "║ 3. Insert After a Student (By ID)   ║\n"
             << "║ 4. Insert Before a Student (By ID)  ║\n"
             << "║ 5. Back\n║ ➤  choose[1-5]: ";
        cin >> choice;
        cout << "╚═════════════════════════════════════╝\n";

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
            cout << "\n➤   Redirecting to homepage...\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
        }

    } while(choice != "5");
}

void displayAll(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Record To Display!\n\n";
    } else {
        struct student *displayAll;
        displayAll = start;

        while(displayAll != NULL){
            cout << "\n╔═══════════════════════════════════╗\n"
                 << "║ ➤  Name : " << displayAll -> firstName << " " << displayAll -> lastName << "\n"
                 << "║ ➤  Age  : " << displayAll -> age << "\n"
                 << "║ ➤  ID   : " << displayAll -> id << "\n"
                 << "║ ➤  Dep  : " << displayAll -> department << "\n"
                 << "╚══════════════════════════════════╝\n";
            displayAll = displayAll -> next;
        }
    }
}

void search(){}

void displayMenu(){
    string choice;
    do{
        cout << "\n╔════ Display ═════════╗\n"
             << "║ 1. Display All       ║\n"
             << "║ 2. Search By ID      ║\n"
             << "║ 3. Back\n║ ➤  choose[1-5]: ";
        cin >> choice;
        cout << "╚═══════════════════════╝\n";

        if(choice == "1"){
            displayAll();
        } else if(choice == "2"){
            search();
        } else if(choice == "3"){
            cout << "\n➤   Redirecting to homepage...\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
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
        cout << "\n╔════ Deleting ═════════╗\n"
             << "║ 1. Delete First\n"
             << "║ 2. Delete Last\n"
             << "║ 3. Delete By ID\n"
             << "║ 4. Delete All\n"
             << "║ 5. Back\n║ ➤choose[1-5]: ";
        cin >> choice;
        cout << "╚═══════════════════════╝\n";
        if(choice == "1"){
            deleteFirst();
        } else if(choice == "2"){
            deleteLast();
        } else if(choice == "3"){
            deleteById();
        } else if(choice == "4"){
            deleteAll();
        } else if(choice == "5"){
            cout << "\n➤   Redirecting to homepage...\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
        }

    } while(choice != "5");
}

void updatingMenu(){
    string choice;
    do{
        cout << "\n╔════ Updating ═════════╗\n"
             << "║ 1. Update Name        ║\n"
             << "║ 2. Update Age         ║\n"
             << "║ 3. Update ID          ║\n"
             << "║ 4. Update Department  ║\n"
             << "║ 5. Back\n║ ➤  choose[1-5]: ";
        cin >> choice;
        cout << "╚═══════════════════════╝\n";
        if(choice == "1"){
            insertFirst();
        } else if(choice == "2"){
            insertLast();
        } else if(choice == "3"){
            insertAfter();
        } else if(choice == "4"){
            insertBefore();
        } else if(choice == "5"){
            cout << "\n➤   Redirecting to homepage...\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
        }

    } while(choice != "5");
}

void saveToFile(){}

void loadFromFile(){}

void homePage(){
    string choice;
    do{
       cout << "\n╔════ HomePage ═════════╗\n"
            << "║ 1. Insert Student     ║\n"
            << "║ 2. Display Student    ║\n"
            << "║ 3. Delete Student     ║\n"
            << "║ 4. Update Student     ║\n"
            << "║ 5. Logout\n║ ➤  choose[1-5]: ";
       cin >> choice;
       cout << "╚═══════════════════════╝\n";

       if(choice == "1"){
           insertionMenu();
       } else if(choice == "2"){
           displayMenu();
       } else if(choice == "3"){
           deletionMenu();
       } else if(choice == "4"){
           updatingMenu();
       } else if(choice == "5"){
           cout << "\n[✔] Logout Successful\n\n";
       } else {
           cout << "\n[✘] There Is No Student Record To Display!\n\n";
       }
    } while(choice != "5");
}

void login(){
    string choice;
    
    do{
        cout << "\n╔════ Welcome ══════════╗\n"
             << "║ 1. Login              ║\n"
             << "║ 2. Exit               ║\n"
             << "║ ➤  choose[1-2]: ";
        cin >> choice;
        cout << "╚═══════════════════════╝\n";
        if(choice == "1"){
            
            string username, password;
            bool loginSuccessful = false;
            int attempt = 3;

            cout << "\n╔════ Login ════════════╗\n";
        
            while(loginSuccessful == false && attempt != 0){
                cout << "║ Enter Username: ";
                cin >> username;
                cout << "║ Enter Password: ";
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
                        cout << "\n[✘] Incorrect username or password\n"
                             << "[!] You have " << attempt <<  " " << isPlural << " left!\n\n";
                    }
                    
                }
                }
                cout << "╚═══════════════════════╝\n";
        
                if(loginSuccessful == true){
                    cout << "\n[✔] Login Successful!\n\n";
                    homePage();
                } else if(loginSuccessful == false){
                    cout << "\n[SYSTEM LOCKED] ➤ Too many attemps!\n\n";
                    break;
                }
    
        } else if (choice == "2"){
            cout << "\n[✔] Program Ended, Thank You!\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
        }
    } while(choice != "2");

}


int main(){
    login();
}