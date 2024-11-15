#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

class student {
public:
    string name[10000], email[10000], address[10000];
    string ph[10000];
    int roll[10000];
    int total = 0;

    void get_details() {
        int no = 0;
        cout << "HOW MANY STUDENTS DO YOU WANT TO ENTER: ";
        cin >> no;
        cin.ignore();
        for (int i = total; i < total + no; i++) {
            cout << "REGISTER NUMBER: " << i+1 << endl;
            roll[i] = i+1;
            cout << "ENTER STUDENT NAME: ";
            getline(cin, name[i]);
            transform(name[i].begin(), name[i].end(), name[i].begin(), ::toupper);
            cout << "ENTER STUDENT EMAIL ADDRESS: ";
            getline(cin, email[i]);

            while (true) {
                cout << "ENTER STUDENT PHONE NUMBER (10 digits): ";
                cin >> ph[i];
                cin.ignore();
                if (ph[i].length() == 10 && all_of(ph[i].begin(), ph[i].end(), ::isdigit)) {
                    break;
                } else {
                    cout << "INVALID PHONE NUMBER, PLEASE ENTER A VALID PHONE NUMBER" << endl;
                }
            }

            cout << "ENTER STUDENT ADDRESS: ";
            getline(cin, address[i]);
        }
        total += no;
    }

    void show_details() {
        if (total == 0) {
            cout << "NO DATA ENTERED" << endl;
        } else {
            for (int i = 0; i < total; i++) {
                cout << "REGISTER NUMBER: " << roll[i] << endl;
                cout << "NAME: " << name[i] << endl;
                cout << "EMAIL ID: " << email[i] << endl;
                cout << "PHONE NUMBER: " << ph[i] << endl;
                cout << "ADDRESS: " << address[i] << endl;
                cout << "-------------------------------" << endl;
            }
        }
    }

    void search_details() {
        if (total == 0) {
            cout << "NO DATA ENTERED" << endl;
        } else {
            int roll_no;
            cout << "ENTER STUDENT REGISTER NUMBER TO SEARCH: ";
            cin >> roll_no;
            bool found = false;
            for (int i = 0; i < total; i++) {
                if (roll_no == roll[i]) {
                    found = true;
                    cout << "REGISTER NUMBER: " << roll[i] << endl;
                    cout << "NAME: " << name[i] << endl;
                    cout << "EMAIL ID: " << email[i] << endl;
                    cout << "PHONE NUMBER: " << ph[i] << endl;
                    cout << "ADDRESS: " << address[i] << endl;
                    break;
                }
            }
            if (!found) {
                cout << "STUDENT NOT FOUND" << endl;
            }
        }
    }

    void update_details() {
        if (total == 0) {
            cout << "NO RECORD FOUND TO UPDATE" << endl;
        } else {
            int roll_no;
            cout << "ENTER STUDENT REGISTER NUMBER TO UPDATE: ";
            cin >> roll_no;
            cin.ignore(); 
            bool found = false;
            for (int i = 0; i < total; i++) {
                if (roll_no == roll[i]) {
                    found = true;
                    cout << "PREVIOUS DATA OF THE STUDENT:" << endl;
                    cout << "REGISTER NUMBER: " << roll[i] << endl;
                    cout << "NAME: " << name[i] << endl;
                    cout << "EMAIL ID: " << email[i] << endl;
                    cout << "PHONE NUMBER: " << ph[i] << endl;
                    cout << "ADDRESS: " << address[i] << endl;

                    cout << "\nENTER NEW DATA OF STUDENT:" << endl;
                    cout << "ENTER STUDENT NAME: ";
                    getline(cin, name[i]);
                    transform(name[i].begin(), name[i].end(), name[i].begin(), ::toupper);
                    cout << "ENTER STUDENT EMAIL ADDRESS: ";
                    getline(cin, email[i]);

                    while (true) {
                        cout << "ENTER STUDENT PHONE NUMBER (10 digits): ";
                        cin >> ph[i];
                        cin.ignore(); // To ignore newline character left in the input buffer
                        if (ph[i].length() == 10 && all_of(ph[i].begin(), ph[i].end(), ::isdigit)) {
                            break;
                        } else {
                            cout << "INVALID PHONE NUMBER, PLEASE ENTER A VALID PHONE NUMBER" << endl;
                        }
                    }

                    cout << "ENTER STUDENT ADDRESS: ";
                    getline(cin, address[i]);
                    break;
                }
            }
            if (!found) {
                cout << "STUDENT NOT FOUND" << endl;
            }
        }
    }

    void delete_details() {
        if (total == 0) {
            cout << "NO DATA ENTERED" << endl;
        } else {
            int choice;
            cout << "PRESS 1 TO DELETE A PARTICULAR RECORD" << endl;
            cout << "PRESS 2 TO DELETE ALL RECORDS" << endl;
            cin >> choice;

            if (choice == 2) {
                total = 0;
                cout << "ALL RECORDS ARE DELETED" << endl;
            } else if (choice == 1) {
                int roll_no;
                cout << "ENTER STUDENT REGISTER NUMBER TO DELETE: ";
                cin >> roll_no;
                bool found = false;
                for (int i = 0; i < total; i++) {
                    if (roll_no == roll[i]) {
                        found = true;
                        for (int j = i; j < total - 1; j++) {
                            name[j] = name[j + 1];
                            email[j] = email[j + 1];
                            ph[j] = ph[j + 1];
                            address[j] = address[j + 1];
                            roll[j] = roll[j + 1];
                        }
                        total--;
                        cout << "REQUIRED DATA IS DELETED" << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "STUDENT NOT FOUND" << endl;
                }
            } else {
                cout << "INVALID INPUT" << endl;
            }
        }
    }
};

int main() {
    student sd;
    string ch;
    int choice;

    while (true) {
        cout << "\t\t\t\t-------------------------" << endl;
        cout << "\t\t\t\tSTUDENT MANAGEMENT SYSTEM" << endl;
        cout << "\t\t\t\t-------------------------" << endl;
        cout << "\t\t\t\t1. ADD A STUDENT" << endl;
        cout << "\t\t\t\t2. SHOW THE STUDENT DETAILS" << endl;
        cout << "\t\t\t\t3. EDIT THE STUDENT DETAILS" << endl;
        cout << "\t\t\t\t4. SEARCH A STUDENT" << endl;
        cout << "\t\t\t\t5. DELETE THE STUDENT DETAILS" << endl;
        cout << "\t\t\t\t6. EXIT" << endl;

        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ADD A STUDENT" << endl;
                sd.get_details();
                break;
            case 2:
                cout << "SHOW THE STUDENT DETAILS" << endl;
                sd.show_details();
                break;
            case 3:
                cout << "EDIT A STUDENT DETAILS" << endl;
                sd.update_details();
                break;
            case 4:
                cout << "SEARCH FOR A STUDENT" << endl;
                sd.search_details();
                break;
            case 5:
                cout << "DELETE A STUDENT" << endl;
                sd.delete_details();
                break;
            case 6:
                cout << "FOR RECONFIRMATION PRESS 'Y' FOR YES TO EXIT (OR) 'N' FOR NO: ";
                cin >> ch;
                if (ch == "Y" || ch == "y") {
                    cout << "STUDENT DATABASE HAS BEEN EXITED" << endl;
                    return 0;
                } else if (ch == "N" || ch == "n") {
                    continue;
                } else {
                    cout << "INVALID INPUT PLEASE ENTER AGAIN" << endl;
                }
                break;
            default:
                cout << "INVALID CHOICE PLEASE ENTER AGAIN!" << endl;
        }
    }

    return 0;
}
