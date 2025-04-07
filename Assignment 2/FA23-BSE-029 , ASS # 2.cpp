#include <iostream>
#include <string>
using namespace std;

// Structure for patient
struct Patient {
    string name;
    int emergencyLevel; // 1 = High, 2 = Medium, 3 = Low
};

// Global array and counter
Patient patients[100];
int patientCount = 0;

// Function to add a new patient
void addPatient() {
    if (patientCount >= 100) {
        cout << "Patient list is full!\n";
        return;
    }

    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, patients[patientCount].name);

    cout << "Enter emergency level (1 = High, 2 = Medium, 3 = Low): ";
    cin >> patients[patientCount].emergencyLevel;

    patientCount++;
    cout << "Patient added successfully.\n";
}

// Function to sort patients by emergency level
void sortPatientsByPriority() {
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
            if (patients[j].emergencyLevel > patients[j + 1].emergencyLevel) {
                // Swap patients
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

// Function to show treatment order
void showTreatmentOrder() {
    if (patientCount == 0) {
        cout << "No patients in the queue.\n";
        return;
    }

    // Sort before showing
    sortPatientsByPriority();

    cout << "\n--- Treatment Order ---\n";
    for (int i = 0; i < patientCount; i++) {
        cout << i + 1 << ". " << patients[i].name
             << " - Emergency Level: " << patients[i].emergencyLevel << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Add Patient\n";
        cout << "2. Show Treatment Order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addPatient();
            showTreatmentOrder(); // Show after every addition
        } else if (choice == 2) {
            showTreatmentOrder();
        } else if (choice == 3) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

