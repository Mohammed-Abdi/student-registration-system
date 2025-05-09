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

void insertLast(){
    string firstNameData, lastNameData, idData, departmentData;
    int ageData;
    cout << "\n╔════ Inserting Last ══════════════════════╗\n"
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
        struct student *pointer;
        pointer = start;

        while(pointer -> next != NULL){
            pointer = pointer -> next;
        }

        pointer -> next = temp;
        temp -> pre = pointer;
        temp -> next = NULL;
        
    }

    cout << "\n[✔] Student Inserted at Last Successfully!\n\n";
}

void insertMoreLast(){
    string choice;
    do{
        cout << "➤  Do you want to add more? [Y/N]: ";
        cin >> choice;
        if(choice == "Y" || choice == "y"){
            insertLast();
        } else if(choice == "N" || choice == "n"){
            cout << "\n➤  Redirecting to Insert Page...\n\n";
            break;
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
        }
    } while(choice != "N" && choice != "n");
}

void insertAfter(){
    string target;
    cout << "\n➤  Enter ID: ";
    cin  >> target;
    
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records!\n\n";
    } else {
        bool isFound = false;
        struct student *current;
        current = start;

        struct student *studentFound;

        while(current != NULL){
            if(current -> id == target){
                isFound = true;
                studentFound = current;
                break;
            }

            current = current -> next;
        }

        if(isFound){
            cout << "\n➤  Student with ID \"" << target << "\" Is Found!\n\n";

            string firstNameData, lastNameData, idData, departmentData;
            int ageData;
            cout << "\n╔════ Inserting After [" << target << "] ═════════════════\n"
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
            cout << "╚══════════════════════════════════════════\n";
        
            struct student *temp, *nextStudent;
            temp = new student;
            temp -> firstName = firstNameData;
            temp -> lastName = lastNameData;
            temp -> age = ageData;
            temp -> id = idData;
            temp -> department = departmentData;

            nextStudent = studentFound -> next;
            
            
            temp -> next = nextStudent;
            studentFound -> next = temp;
            temp -> pre = studentFound;

            if(nextStudent != NULL){
                nextStudent -> pre = temp;
            } else {
                temp -> next = NULL;
            }
                
            cout << "\n[✔] Student Inserted after [" << studentFound -> id << "] Successfully!\n\n";
        } else {
            cout << "\n➤  Student with ID \"" << target << "\" Was Not Found!\n\n";
        }
    }
}

void insertBefore(){
    string target;
    cout << "\n➤  Enter ID: ";
    cin  >> target;
    
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records!\n\n";
    } else {
        bool isFound = false;
        struct student *current;
        current = start;

        struct student *studentFound;

        while(current != NULL){
            if(current -> id == target){
                isFound = true;
                studentFound = current;
                break;
            }

            current = current -> next;
        }

        if(isFound){
            cout << "\n➤  Student with ID \"" << target << "\" Is Found!\n\n";

            string firstNameData, lastNameData, idData, departmentData;
            int ageData;
            cout << "\n╔════ Inserting Before [" << target << "] ═════════════════\n"
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
            cout << "╚══════════════════════════════════════════\n";
        
            struct student *temp,*previousStudent;
            temp = new student;
            temp -> firstName = firstNameData;
            temp -> lastName = lastNameData;
            temp -> age = ageData;
            temp -> id = idData;
            temp -> department = departmentData;

            temp -> next = studentFound;
            temp -> pre = studentFound -> pre;
            previousStudent = studentFound -> pre;

            if(previousStudent != NULL){
                previousStudent -> next = temp;
            } else {
                start = temp;
            }

            studentFound -> pre = temp;
                
            cout << "\n[✔] Student Inserted Before [" << studentFound -> id << "] Successfully!\n\n";
        } else {
            cout << "\n➤  Student with ID \"" << target << "\" Was Not Found!\n\n";
        }
    }
}

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
        } else if(choice == "4"){
            insertBefore();
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

void search(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records to Search!\n\n";
    } else {
        bool isFound = false;
        string target;
        cout << "\n➤  Enter ID: ";
        cin  >> target;
        struct student *current;
        current = start;

        while(current != NULL){
            if(current -> id == target){
                isFound = true;
                cout << "\n╔═══════════════════════════════════╗\n"
                 << "║ ➤  Name : " << current -> firstName << " " << current -> lastName << "\n"
                 << "║ ➤  Age  : " << current -> age << "\n"
                 << "║ ➤  ID   : " << current -> id << "\n"
                 << "║ ➤  Dep  : " << current -> department << "\n"
                 << "╚══════════════════════════════════╝\n";
                 break;
            }
            current = current -> next;
        }

        if(!isFound){
            cout << "\n➤  Student with ID \"" << target << "\" Was Not Found!\n\n";
        }
    }
}

void displayMenu(){
    string choice;
    do{
        cout << "\n╔════ Display ═════════╗\n"
             << "║ 1. Display All       ║\n"
             << "║ 2. Search By ID      ║\n"
             << "║ 3. Back\n║ ➤  choose[1-5]: ";
        cin >> choice;
        cout << "╚══════════════════════╝\n";

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

void deleteFirst(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records to Delete!\n\n";
    } else {
        struct student *current, *nextStudent;

        current = start;

        if(start -> next == NULL){
            delete current;
            start = NULL;
        } else {
            nextStudent = start -> next;
            start = nextStudent;
            nextStudent -> pre = NULL;
    
            delete current;
        }
        
    }
}

void deleteLast(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records to Delete!\n\n";
    } else {
        struct student *pointer1, *pointer2;

        pointer1 = start;

        if(start -> next == NULL){
            delete pointer1;
            start = NULL;
        } else {
            while(pointer1 -> next != NULL){
                pointer2 = pointer1;
                pointer1 = pointer1 -> next;
            }

            pointer2 -> next = NULL;
            delete pointer1;
        }

    }
}

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
             << "║ 5. Back\n║ ➤  choose[1-5]: ";
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
            cout << "\n[✔] Program Ended, Thank You!\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
        }
    } while(choice != "2");

}


int main(){
    login();
}