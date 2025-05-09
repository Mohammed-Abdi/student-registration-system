#include<iostream>
#include<string>
#include<fstream>
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
            cout << "\n[✘] There Is No Student with ID [" << target << "]!\n\n";
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
        string storeId;

        current = start;

        if(start -> next == NULL){
            string choice;
            cout << "➤  Are you sure you want to delete \""<< current -> firstName <<"\"? [Y/N]: ";
            cin >> choice;
            if(choice == "Y" || choice == "y"){
                storeId = current -> id;
                 delete current;
                 start = NULL;
                 cout << "\n[✔] First Student with ID [" << storeId << "] Record Deleted Successfully!\n\n";
             } else if(choice == "N" || choice == "n"){
                 cout << "\n➤  Redirecting to Deletion Page...\n\n";
             } else {
                 cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
             }
            
        } else {
            string choice;
            cout << "➤  Are you sure you want to delete \""<< current -> firstName <<"\"? [Y/N]: ";
            cin >> choice;
            if(choice == "Y" || choice == "y"){
                 nextStudent = start -> next;
                 start = nextStudent;
                 nextStudent -> pre = NULL;
                 storeId = current -> id;
                 delete current;
                 cout << "\n[✔] First Student with ID [" << storeId << "] Record Deleted Successfully!\n\n";
             } else if(choice == "N" || choice == "n"){
                 cout << "\n➤  Redirecting to Deletion Page...\n\n";
             } else {
                 cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
             }
            
        }
        
    }
}


void deleteLast(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records to Delete!\n\n";
    } else {
        struct student *pointer1, *pointer2;
        string storeId;
        pointer1 = start;

        if(start -> next == NULL){
            
            string choice;
            cout << "➤  Are you sure you want to delete \""<< pointer1 -> firstName <<"\"? [Y/N]: ";
            cin >> choice;
            if(choice == "Y" || choice == "y"){
                    storeId = pointer1 -> id;
                    delete pointer1;
                    start = NULL;
                    cout << "\n[✔] Last Student with ID [" << storeId << "] Record Deleted Successfully!\n\n";
                } else if(choice == "N" || choice == "n"){
                    cout << "\n➤  Redirecting to Deletion Page...\n\n";
                } else {
                    cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
                }
                
        } else {
            while(pointer1 -> next != NULL){
                pointer2 = pointer1;
                pointer1 = pointer1 -> next;
            }

            
            string choice;
            cout << "➤  Are you sure you want to delete \""<< pointer1 -> firstName <<"\"? [Y/N]: ";
            cin >> choice;
            if(choice == "Y" || choice == "y"){
                 storeId = pointer1 -> id;
                 pointer2 -> next = NULL;
                 delete pointer1;
                 cout << "\n[✔] Last Student with ID [" << storeId << "] Record Deleted Successfully!\n\n";
             } else if(choice == "N" || choice == "n"){
                 cout << "\n➤  Redirecting to Deletion Page...\n\n";
             } else {
                 cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
             }
            
        }

    }
}


void deleteById(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records to Delete!\n\n";  
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

                    if(start -> next == NULL){
                        string choice;
                        cout << "➤  Are you sure you want to delete \""<< current -> firstName <<"\"? [Y/N]: ";
                        cin >> choice;

                        if(choice == "Y" || choice == "y"){
                            delete current;
                            start = NULL;
                            cout << "\n[✔] Student with ID [" << target <<"] Deleted Successfully!\n\n";
                            break;
                        } else if(choice == "N" || choice == "n"){
                            cout << "\n➤  Redirecting to Deletion Page...\n\n";
                        } else {
                            cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
                        }
                    
                    } else if(current -> pre == NULL){
                        cout << "\n➤  Student with ID [" << target <<"] is The First Student...!\n";
                        deleteFirst();
                        break;
                    } else if(current -> next == NULL){
                        cout << "\n➤  Student with ID [" << target <<"] is The Last Student...!\n";
                        deleteLast();
                        break;
                    } else {
                        string choice;
                        cout << "➤  Are you sure you want to delete \""<< current -> firstName <<"\"? [Y/N]: ";
                        cin >> choice;

                        if(choice == "Y" || choice == "y"){
                            current -> pre -> next = current -> next;
                            current -> next -> pre = current -> pre;
        
                            delete current;
                            cout << "\n[✔] Student with ID [" << target <<"] Deleted Successfully!\n\n";
                            break;
                        } else if(choice == "N" || choice == "n"){
                            cout << "\n➤  Redirecting to Deletion Page...\n\n";
                        } else {
                            cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
                        }
                    }
            }
            current = current -> next;
        }
        if(!isFound){
            cout << "\n[✘] There Is No Student with ID [" << target << "]!\n\n";
        }
    }
}


void deleteAll(){
    if(start == NULL){
        cout << "\n[✘] There Is No Student Records to Delete!\n\n";       
    } else {
        
        string choice;
        cout << "➤  Are you sure you want to delete All student records? [Y/N]: ";
        cin >> choice;

        if(choice == "Y" || choice == "y"){
            struct student *current, *nextStudent;
            current = start;
    
            if(start -> next == NULL){
                delete current;
            } else {
                while(current != NULL){
                    nextStudent = current -> next;
                    delete current;
                    current = nextStudent;
                }
            }
    
            start = NULL;
    
            cout << "\n[✔] All Student Records Deleted Successfully!\n\n";
        } else if(choice == "N" || choice == "n"){
            cout << "\n➤  Redirecting to Deletion Page...\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n\n";
        }
    }
}


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


void updateMenu(){
    string choice;
    do{
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
                string choiceX, newFirstName, newLastName, newId, newDepartment;
                int newAge;
                do{
                    
                    cout << "\n╔═══════════════════════════════════╗\n"
                 << "║ ➤  Name : " << current -> firstName << " " << current -> lastName << "\n"
                 << "║ ➤  Age  : " << current -> age << "\n"
                 << "║ ➤  ID   : " << current -> id << "\n"
                 << "║ ➤  Dep  : " << current -> department << "\n"
                 << "║══════════════════════════════════║\n"
                 << "║ 1. Update Name                   ║\n"
                 << "║ 2. Update Age                    ║\n"
                 << "║ 3. Update ID                     ║\n"
                 << "║ 4. Update Department             ║\n"
                 << "║ 5. Back\n║ ➤  choose[1-5]: ";
                 cin >> choice;
                 cout << "╚══════════════════════════════════╝\n";
                 if(choice == "1"){
                    cout << "➤  Update First Name: ";
                    cin >> newFirstName;
                    current -> firstName = newFirstName;
                    cout << "➤  Update Last Name: ";
                    cin >> newLastName;
                    current -> lastName = newLastName;
                } else if(choice == "2"){
                    cout << "➤  Update Age: ";
                    cin >> newAge;
                    current -> age = newAge;
                } else if(choice == "3"){
                    cout << "➤  Update ID: ";
                    cin >> newId;
                    current -> id = newId;
                 } else if(choice == "4"){
                    cout << "➤  Update Department: ";
                    cin.ignore();
                    getline(cin , newDepartment);
                    current -> department = newDepartment;
                 } else if(choice == "5"){
                     cout << "\n➤   Redirecting to homepage...\n\n";
                 } else {
                     cout << "\n[✘] There is no option \"" << choice << "\"\n";
                 }
                } while(choice != "5");
                
            }
            current = current -> next;
        }

        if(!isFound){
            cout << "\n[✘] There Is No Student with ID [" << target << "]!\n\n";
        }
    }

    } while(choice != "5");
}


void saveToFile(){
    ofstream outFile("students.txt");
    if(!outFile){
        cout << "\n[✘] Error opening file for writing!\n\n";
        return;
    }

    struct student* current = start;
    while(current != NULL){
        outFile << current->firstName << "|"
                << current->lastName << "|"
                << current->age << "|"
                << current->id << "|"
                << current->department << "\n";
        current = current->next;
    }
    
    outFile.close();
    cout << "\n[✔] Student records saved to file successfully!\n\n";
}


void loadFromFile(){
    ifstream inFile("students.txt");
    if(!inFile){
        return;
    }

    string line;
    while(getline(inFile, line)){
        size_t pos = 0;
        string token;
        string delimiter = "|";
        
        pos = line.find(delimiter);
        string firstName = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        
        pos = line.find(delimiter);
        string lastName = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        
        pos = line.find(delimiter);
        int age = stoi(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
        
        pos = line.find(delimiter);
        string id = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        
        string department = line;

        struct student* temp = new student;
        temp->firstName = firstName;
        temp->lastName = lastName;
        temp->age = age;
        temp->id = id;
        temp->department = department;
        temp->pre = NULL;
        temp->next = NULL;

        if(start == NULL){
            start = temp;
        } else {
            struct student* current = start;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = temp;
            temp->pre = current;
        }
    }
    
    inFile.close();
}


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
           updateMenu();
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
            cout << "Program Ended, Thank You!\n\n"
                 << "╔══════════════════════════════════════════╗\n"
                 << "║ GroupMembers         ║    ID             ║\n"
                 << "║══════════════════════════════════════════║\n"
                 << "║ Mohammed Abdi        ║  DDU1600554       ║\n"
                 << "║ Samuel Solomon       ║  DDU16000644      ║\n"
                 << "║ Sena Alemayehu       ║  DDU1600663       ║\n"
                 << "║ Abdulfetah Ibrahim   ║  DDU1600029       ║\n"
                 << "║ Adnan Mohammed       ║  DDU16001164      ║\n"
                 << "╚══════════════════════════════════════════╝\n\n";
        } else {
            cout << "\n[✘] There is no option \"" << choice << "\"\n";
        }
    } while(choice != "2");

}


int main(){
    loadFromFile();
    login();
    saveToFile();
}