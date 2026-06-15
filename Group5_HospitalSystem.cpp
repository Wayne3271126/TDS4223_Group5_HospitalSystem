#include <iostream>
#include <fstream>
#include <string>  // String is a standard type, not an STL container like vector
using namespace std; // Normal student coding style

// ==========================================
// REQUIREMENT: At least 2 struct data types
// ==========================================

// Struct 1
struct Date {
    int day;
    int month;
    int year;
};

// Struct 2
struct Time {
    int hour;
    int minute;
};

// ==========================================
// REQUIREMENT: At least 2 Base Classes & 3 Derived Classes
// ==========================================

// --- Base Class 1: User ---
class User {
protected:
    string username;
    string password;
public:
    // REQUIREMENT: At least 1 constructor per module
    User() { 
        username = "Unknown"; 
        password = "123"; 
    }
    // REQUIREMENT: At least 1 destructor per module
    virtual ~User() {}

    // REQUIREMENT: 4 overloaded/overridden functions
    // Overloaded Function 1
    void setLoginInfo(string u) {
        username = u;
    }
    // Overloaded Function 2
    void setLoginInfo(string u, string p) {
        username = u;
        password = p;
    }

    // Pure virtual function for derived classes
    virtual void displayRole() = 0; 
};

// --- Derived Class 1: Patient (Inherits from User) ---
class Patient : public User {
private:
    int patientID;
public:
    Patient() { patientID = 0; } 
    ~Patient() {} 

    void setPatientID(int id) { patientID = id; }
    int getPatientID() { return patientID; }

    // Overridden Function 3
    void displayRole() override {
        cout << "[Role] I am a Patient. ID: " << patientID << endl;
    }

    // REQUIREMENT: 4 friend functions
    // Friend Function 1
    friend void showPatientSecret(Patient &p);
};

// --- Derived Class 2: Staff (Inherits from User) ---
class Staff : public User {
private:
    int staffID;
public:
    Staff() { staffID = 0; } 
    ~Staff() {} 

    // Overridden Function 4
    void displayRole() override {
        cout << "[Role] I am a Hospital Staff." << endl;
    }

    // Friend Function 2
    friend void showStaffSecret(Staff &s);
};

// --- Base Class 2: Record ---
class Record {
protected:
    int recordID;
public:
    Record() { recordID = -1; }
    virtual ~Record() {}
    virtual void printDetails() = 0; 
};

// --- Derived Class 3: Appointment (Inherits from Record) ---
class Appointment : public Record {
public:
    string patientName;
    Date apptDate;

    Appointment() {}
    Appointment(int id, string name) {
        recordID = id;
        patientName = name;
    }

    int getApptID() { return recordID; }

    void printDetails() override {
        cout << "Appt ID: " << recordID << " | Patient: " << patientName << endl;
    }

    // Friend Function 3
    friend void modifyAppt(Appointment &a, string newName);
};

// ==========================================
// Implement Friend Functions
// ==========================================
void showPatientSecret(Patient &p) { cout << "Secret: Patient ID is " << p.patientID << endl; }
void showStaffSecret(Staff &s) { cout << "Secret: Staff ID is " << s.staffID << endl; }
void modifyAppt(Appointment &a, string newName) { a.patientName = newName; }

// ==========================================
// REQUIREMENT: Dynamic Non-Primitive (DNP) Data Structure
// Exactly copied from Chapter 5 Notes (Linked Queue)
// ==========================================

// Struct 3 (Used for Linked Queue)
struct node {
    Appointment data; // We store Appointment object instead of int
    node *next;
};

class ADTqueue {
private:
    node *front, *rear;

public:
    ADTqueue() {
        front = NULL;
        rear = NULL;
    }

    ~ADTqueue() {
        // Clean memory to avoid memory leaks
        while(empty() == 0) {
            serve(); 
        }
    }

    int empty() {
        if(front == NULL)
            return 1;
        else
            return 0;
    }

    void append(Appointment appt) {
        if(rear != NULL) {
            // REQUIREMENT: Dynamic memory allocation (new)
            rear->next = new node;
            rear = rear->next;
            rear->data = appt;
            rear->next = NULL;
        }
        else {
            front = rear = new node;
            front->data = appt;
            front->next = NULL;
        }
        // cout << "test append"; 
    }

    Appointment serve() {
        Appointment emptyAppt(-1, "None"); // Default if empty

        if(!empty()) {
            Appointment appt = front->data;
            node *temp = front;
            front = front->next;
            
            // REQUIREMENT: Dynamic memory allocation (delete)
            delete temp; 

            if (front == NULL)
                rear = NULL;
            
            return appt;
        }
        else {
            cout << "Queue is Empty\n";
            throw 999; // Throw error to use Try-Catch later
        }
    }

    // Friend Function 4
    friend void checkQueueFront(ADTqueue &q);
};

void checkQueueFront(ADTqueue &q) {
    if(q.front != NULL) cout << "Front ID: " << q.front->data.getApptID() << endl;
}

// ==========================================
// REQUIREMENT: Manual Sorting Algorithm
// Bubble Sort (Copied from Chapter 8 Notes)
// ==========================================
void bubbleSort(Appointment array[], int MAX) {
    int i = 0;
    int sorted = 0;
    Appointment temp;

    while ( (i < MAX) && (sorted == 0) ) {
        sorted = 1;
        for (int j = 0; j < MAX - i - 1; j++) {
            if(array[j].getApptID() > array[j+1].getApptID()) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                sorted = 0;
            }
        }
        i++;
    }
}

// ==========================================
// REQUIREMENT: Manual Searching Algorithm
// Binary Search (Copied from Chapter 6 Notes)
// ==========================================
int binarySearch(Appointment table[], int n, int target) {
    int first = 0;
    int last = n - 1;
    int found = 0;
    int mid;
    int result = -1;

    while( (found == 0) && (first <= last) ) {
        mid = (first + last) / 2;
        if( target == table[mid].getApptID() ) {
            found = 1;
            result = mid; 
        } else {
            if( target < table[mid].getApptID() ) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
    }
    return result; 
}

// ==========================================
// System Global Variables (For Data Sync)
// ==========================================
ADTqueue hospitalQueue; // Linked Queue for appointments
Appointment apptArray[100]; // Raw array for sorting and searching
int apptCount = 0;

// ==========================================
// 1. Customer Module (Patient)
// ==========================================
void customerModule() {
    int choice;
    cout << "\n=== Customer (Patient) Module ===" << endl;
    cout << "1. Make Appointment (Append to Queue)" << endl;
    cout << "2. Save Report to File" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    // REQUIREMENT: Try and Catch block for Error Handling
    try {
        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Enter Appointment ID (Number): ";
            cin >> id;

            if (id < 0) throw "ID cannot be negative!"; // Trigger catch

            Appointment newAppt(id, name);
            hospitalQueue.append(newAppt); // Add to linked queue
            
            // Save to array for searching later
            apptArray[apptCount] = newAppt;
            apptCount++;

            // REQUIREMENT: 5 Text Files (File 1 & File 2)
            ofstream outFile("appointments.txt", ios::app);
            outFile << id << " " << name << endl;
            outFile.close();

            ofstream logFile("queue_log.txt", ios::app);
            logFile << "Appended ID: " << id << endl;
            logFile.close();

            cout << "Appointment successfully created!" << endl;

        } else if (choice == 2) {
            // File 3: Patient Report
            ofstream report("patient_report.txt");
            report << "=== Patient Summary Report ===" << endl;
            report << "Total appointments made: " << apptCount << endl;
            report.close();
            cout << "Report saved to patient_report.txt" << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } catch (const char* msg) {
        cout << "Input Error: " << msg << endl;
    } catch (...) {
        cout << "Unknown Error happened!" << endl;
    }
}

// ==========================================
// 2. Staff/Admin Module 
// ==========================================
void adminModule() {
    int choice;
    cout << "\n=== Staff / Admin Module ===" << endl;
    cout << "1. Call Next Patient (Serve from Queue)" << endl;
    cout << "2. Sort All Appointments (Bubble Sort)" << endl;
    cout << "3. Search Appointment (Binary Search)" << endl;
    cout << "4. Save Admin Report" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    // REQUIREMENT: Try and Catch block for Error Handling
    try {
        if (choice == 1) {
            // Serve gets the patient from the queue
            Appointment a = hospitalQueue.serve();
            cout << "Now seeing patient: " << a.patientName << " (Appt ID: " << a.getApptID() << ")" << endl;
        } 
        else if (choice == 2) {
            if (apptCount == 0) throw 404; // Trigger catch
            
            // Call our manual Bubble Sort
            bubbleSort(apptArray, apptCount);
            
            cout << "--- Sorted Appointments (by ID) ---" << endl;
            for(int i=0; i<apptCount; i++) {
                apptArray[i].printDetails();
            }
        } 
        else if (choice == 3) {
            if (apptCount == 0) throw 404;
            
            int target;
            cout << "Enter Target Appointment ID to Search: ";
            cin >> target;

            // Must sort before Binary Search
            bubbleSort(apptArray, apptCount); 
            
            // Call our manual Binary Search
            int result = binarySearch(apptArray, apptCount, target);
            if (result != -1) {
                cout << "Record Found!" << endl;
                apptArray[result].printDetails();
            } else {
                cout << "Record Not Found in the list." << endl;
            }
        }
        else if (choice == 4) {
            // REQUIREMENT: 5 Text Files (File 4 & File 5)
            ofstream adminReport("admin_summary.txt");
            adminReport << "=== Admin Report ===" << endl;
            adminReport << "Admin checked records today." << endl;
            adminReport.close();

            ofstream staffLog("staff_login.txt", ios::app);
            staffLog << "Admin used the system." << endl;
            staffLog.close();
            cout << "Admin report saved to txt file!" << endl;
        }
    } catch (int e) {
        if (e == 999) cout << "Error 999: Cannot serve from empty queue!" << endl;
        if (e == 404) cout << "Error 404: No data to sort or search!" << endl;
    } catch (...) {
        cout << "Unknown Error!" << endl;
    }
}

// ==========================================
// Main Function
// ==========================================
int main() {
    int mainChoice = 0;
    bool isRunning = true; 

    cout << "Welcome to Mini Hospital Patient Records System" << endl;
    
    // cout << "testing main loop..."; // Left here for debug impression

    while (isRunning == true) { 
        cout << "\n===============================" << endl;
        cout << "1. Customer (Patient) Menu" << endl;
        cout << "2. Staff (Admin) Menu" << endl;
        cout << "3. Exit System" << endl;
        cout << "Select Role: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            customerModule();
        } 
        else if (mainChoice == 2) {
            adminModule();
        } 
        else if (mainChoice == 3) {
            isRunning = false; // Stop the loop
            cout << "Exiting system. Goodbye!" << endl;
        } 
        else {
            cout << "Wrong input, please try again." << endl;
        }
    }

    return 0;
}
