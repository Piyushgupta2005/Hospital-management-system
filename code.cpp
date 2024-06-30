#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

void displayMenu();
int login();
void addNewPatient();
void addDiagnosisInformation();
void displayPatientHistory();
void displayHospitalInfo();

int main() {
    // Note: Run the program in full screen only
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Printing the welcome note
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t"
         << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    cout << "Press any key to continue...";
    cin.get();
    system("cls");

    login();
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                addNewPatient();
                break;
            case 2:
                addDiagnosisInformation();
                break;
            case 3:
                displayPatientHistory();
                break;
            case 4:
                displayHospitalInfo();
                break;
            case 5:
                cout << "Exiting the program. Thank you for using the Hospital Management System.\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
    cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
    cout << "\t\t\t\t\t\t|             2  >> Add Diagnosis Information                     |\n";
    cout << "\t\t\t\t\t\t|             3  >> Full History of the Patient                   |\n";
    cout << "\t\t\t\t\t\t|             4  >> Information About the Hospital                |\n";
    cout << "\t\t\t\t\t\t|             5  >> Exit the Program                              |\n";
    cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
    cout << "\t\t\t\t\t\tEnter your choice: ";
}

int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) { // Character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
        cout << "Press any key to continue...";
        cin.get();
        system("cls");
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
        cout << "Press any key to continue...";
        cin.get();
        system("cls");
        login();
    }
    return 0;
}

void addNewPatient() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    cout << "\n\n\t\t\t\t\t\t\t\t" << asctime(timeinfo);

    ofstream pat_file;
    string fname;
    cout << "\n\n\n\nEnter the patient's file name: ";
    getline(cin, fname);
    pat_file.open(fname.c_str());
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    }

    struct patient_info {
        string name;
        string address;
        string contact;
        string age;
        string sex;
        string blood_gp;
        string disease_past;
        string id;
    } ak;

    cout << "\n********************************************************************\n";
    pat_file << "\n********************************************************************\n\n";
    cout << "\nName: ";
    pat_file << "Name: ";
    getline(cin, ak.name);
    pat_file << ak.name << "\n";

    cout << "\nAddress: ";
    pat_file << "Address: ";
    getline(cin, ak.address);
    pat_file << ak.address << "\n";

    cout << "\nContact Number: ";
    pat_file << "Contact Number: ";
    getline(cin, ak.contact);
    pat_file << ak.contact << "\n";

    cout << "\nAge: ";
    pat_file << "Age: ";
    getline(cin, ak.age);
    pat_file << ak.age << "\n";

    cout << "\nSex: ";
    pat_file << "Sex: ";
    getline(cin, ak.sex);
    pat_file << ak.sex << "\n";

    cout << "\nBlood Group: ";
    pat_file << "Blood Group: ";
    getline(cin, ak.blood_gp);
    pat_file << ak.blood_gp << "\n";

    cout << "\nAny Major disease suffered earlier: ";
    pat_file << "Any Major disease suffered earlier: ";
    getline(cin, ak.disease_past);
    pat_file << ak.disease_past << "\n";

    cout << "\nPatient ID: ";
    pat_file << "Patient ID: ";
    getline(cin, ak.id);
    pat_file << ak.id << "\n";

    cout << "\n********************************************************************\n";
    pat_file << "\n********************************************************************\n\n";
    cout << "\nInformation Saved Successfully\n";
    pat_file.close();
    cout << "Press any key to continue...";
    cin.get();
    system("cls");
}

void addDiagnosisInformation() {
    fstream pat_file;
    string fname;
    cout << "\n\nEnter the patient's file name to be opened: ";
    getline(cin, fname);
    system("cls");
    pat_file.open(fname.c_str(), ios::in);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    }

    cout << "\n\n\n\n\t\t\t\t........................................ Information about " << fname << " ........................................\n\n\n\n";
    string info;
    while (getline(pat_file, info)) {
        cout << info << "\n";
    }
    pat_file.close();

    pat_file.open(fname.c_str(), ios::out | ios::app);
    cout << "Adding more information in patient's file on: " << asctime(localtime(&time(nullptr))) << "\n";
    pat_file << "Description of " << asctime(localtime(&time(nullptr))) << "\n";

    struct app {
        string symptom;
        string diagnosis;
        string medicine;
        string addmission;
        string ward;
    } add;

    cout << "\nSymptoms: ";
    pat_file << "Symptoms: ";
    getline(cin, add.symptom);
    pat_file << add.symptom << "\n";

    cout << "\nDiagnosis: ";
    pat_file << "Diagnosis: ";
    getline(cin, add.diagnosis);
    pat_file << add.diagnosis << "\n";

    cout << "\nMedicines: ";
    pat_file << "Medicines: ";
    getline(cin, add.medicine);
    pat_file << add.medicine << "\n";

    cout << "\nAdmission Required?: ";
    pat_file << "Admission Required?: ";
    getline(cin, add.addmission);
    pat_file << add.addmission << "\n";

    cout << "\nType of ward: ";
    pat_file << "Type of ward: ";
    getline(cin, add.ward);
    pat_file << add.ward << "\n";
    pat_file << "\n*************************************************************************\n";
    cout << "\n\n" << add.ward << " ward is allotted Successfully\n";
    pat_file.close();
    cout << "Press any key to continue...";
    cin.get();
    system("cls");
}

void displayPatientHistory() {
    fstream pat_file;
    string fname;
    cout << "\n\nEnter the patient's file name to be opened: ";
    getline(cin, fname);
    system("cls");
    pat_file.open(fname.c_str(), ios::in);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    }

    cout << "\n\n\n\n\t\t\t\t........................................ Full Medical History of " << fname << " ........................................\n\n\n\n";
    string info;
    while (getline(pat_file, info)) {
        cout << info << "\n";
    }
    pat_file.close();
    cout << "Press any key to continue...";
    cin.get();
    system("cls");
}

void displayHospitalInfo() {
    cout << "\n\n\t\t\t\t\t\t\t\t........................................ Information about Hospital ........................................\n\n";
    cout << "\t\t\t\t\t\t\t\tHOSPITAL NAME: HEALTH CARE HOSPITAL\n\n";
    cout << "\t\t\t\t\t\t\t\tAddress: ABC Road, XYZ City\n\n";
    cout << "\t\t\t\t\t\t\t\tContact: +123-456-7890\n\n";
    cout << "\t\t\t\t\t\t\t\tEmail: info@healthcarehospital.com\n\n";
    cout << "\t\t\t\t\t\t\t\tWebsite: www.healthcarehospital.com\n\n";
    cout << "Press any key to continue...";
    cin.get();
    system("cls");
}
