#include <iostream>
using namespace std;

// Task structure
struct Task {
    int id, priority;
    string description;
    Task* next;
};

// Function to add a task at the end
void addTask(Task*& head, int id, string desc, int priority) {
    Task* newTask = new Task{id, priority, desc, NULL};

    if (head == NULL) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTask;
    }
}

// Function to display tasks
void displayTasks(Task* head) {
    while (head != NULL) {
        cout << "ID: " << head->id << ", Desc: " << head->description 
             << ", Priority: " << head->priority << endl;
        head = head->next;
    }
}

// Function to remove the first task
void removeTask(Task*& head) {
    if (head != NULL) {
        Task* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to display the menu
void menu() {
    cout << "\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\n";
}

int main() {
    Task* head = NULL;
    int choice, id, priority;
    string desc;
    bool running = true;

    while (running) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Task ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Description: "; getline(cin, desc);
            cout << "Enter Priority: "; cin >> priority;
            addTask(head, id, desc, priority);
        } 
        else if (choice == 2) {
            displayTasks(head);
        } 
        else if (choice == 3) {
            removeTask(head);
        } 
        else if (choice == 4) {
            running = false;
        }
    }

    return 0;
}
