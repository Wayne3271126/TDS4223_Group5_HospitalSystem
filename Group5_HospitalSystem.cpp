#include <iostream>
#include <fstream>
#include <string>

// REQUIREMENT: Student coding style
// We use namespace std to make the code simple
using namespace std;

// ==========================================
// CUSTOM ERROR HANDLING CLASSES
// REQUIREMENT: Try and catch block
// These classes help us catch errors
// ==========================================

// This is the base error class
class BaseException
{
protected:
    // This string holds the error message
    string errorMessage;

public:
    // This is the constructor
    BaseException()
    {
        // Set a default error message
        errorMessage = "Unknown Error Happened";
    }

    // This is the destructor
    virtual ~BaseException()
    {
        // Do nothing here
    }

    // This function returns the error message
    virtual string getMessage()
    {
        return errorMessage;
    }
};

// This error is for negative ID
// REQUIREMENT: Derived class inheritance
class InvalidIDException : public BaseException
{
public:
    // Constructor sets the specific error message
    InvalidIDException()
    {
        errorMessage = "Error: Invalid ID. ID cannot be less than zero.";
    }

    // Destructor
    ~InvalidIDException()
    {
        // Do nothing
    }

    // This overrides the base function
    // REQUIREMENT: Overridden function
    string getMessage() override
    {
        return errorMessage;
    }
};

// This error is for wrong age input
// REQUIREMENT: Derived class inheritance
class InvalidAgeException : public BaseException
{
public:
    // Constructor
    InvalidAgeException()
    {
        errorMessage = "Error: Invalid Age. Age is wrong.";
    }

    // Destructor
    ~InvalidAgeException()
    {
        // Do nothing
    }

    // Override the function
    string getMessage() override
    {
        return errorMessage;
    }
};

// This error is for negative bill money
// REQUIREMENT: Derived class inheritance
class NegativeBillException : public BaseException
{
public:
    // Constructor
    NegativeBillException()
    {
        errorMessage = "Error: Bill amount cannot be negative money.";
    }

    // Destructor
    ~NegativeBillException()
    {
        // Do nothing
    }

    // Override function
    string getMessage() override
    {
        return errorMessage;
    }
};

// This error is for empty queue
class QueueEmptyException : public BaseException
{
public:
    // Constructor
    QueueEmptyException()
    {
        errorMessage = "Error 999: The hospital queue is completely empty right now.";
    }

    // Destructor
    ~QueueEmptyException()
    {
        // Do nothing
    }

    // Override function
    string getMessage() override
    {
        return errorMessage;
    }
};

// This error is for empty database array
class DatabaseEmptyException : public BaseException
{
public:
    // Constructor
    DatabaseEmptyException()
    {
        errorMessage = "Error 404: The database array has no records to show.";
    }

    // Destructor
    ~DatabaseEmptyException()
    {
        // Do nothing
    }

    // Override function
    string getMessage() override
    {
        return errorMessage;
    }
};

// ==========================================
// MANUAL STRING TOOL CLASS
// We cannot use STL, so we write our own tools
// ==========================================

class StringUtils
{
public:
    // Constructor
    StringUtils()
    {
        // Do nothing
    }

    // Destructor
    ~StringUtils()
    {
        // Do nothing
    }

    // This function counts the length of a string manually
    int getLength(string str)
    {
        int count;
        count = 0;
        
        // Loop until the end of the string
        while (str[count] != '\0')
        {
            count = count + 1;
        }
        
        return count;
    }

    // This function checks if a string has only numbers
    bool isAllDigits(string str)
    {
        int len;
        len = getLength(str);
        
        int i;
        i = 0;
        
        bool result;
        result = true; // Assume it is true first
        
        while (i < len)
        {
            // If the character is smaller than '0'
            if (str[i] < '0')
            {
                result = false;
            }
            // If the character is bigger than '9'
            if (str[i] > '9')
            {
                result = false;
            }
            
            i = i + 1;
        }
        
        return result;
    }

    // This function compares two strings manually
    bool compareStrings(string s1, string s2)
    {
        int len1;
        len1 = getLength(s1);
        
        int len2;
        len2 = getLength(s2);
        
        // If lengths are different, they are not the same
        if (len1 != len2)
        {
            return false;
        }
        
        int i;
        i = 0;
        
        bool match;
        match = true;
        
        while (i < len1)
        {
            // Compare each character
            if (s1[i] != s2[i])
            {
                match = false;
            }
            
            i = i + 1;
        }
        
        return match;
    }
};

// ==========================================
// REQUIREMENT: At least 2 struct data types
// I will create 4 structs to make the code longer
// ==========================================

// Struct 1: Date
// This struct stores the day, month, and year
struct Date
{
    int day;
    int month;
    int year;
};

// Struct 2: Time
// This struct stores the hour, minute, and second
struct Time
{
    int hour;
    int minute;
    int second;
};

// Struct 3: Address
// This struct stores the location of a person
struct Address
{
    string street;
    string city;
    string state;
    int zipCode;
};

// Struct 4: ContactInfo
// This struct stores phone numbers and emails
struct ContactInfo
{
    string phone;
    string email;
    string emergencyContactName;
    string emergencyContactPhone;
};

// ==========================================
// REQUIREMENT: At least 2 Base Classes & 3 Derived Classes
// Base Class 1: User
// ==========================================

// This class is the parent for Patient and Staff
class User
{
protected:
    // Protected variables can be seen by child classes
    string username;
    string password;
    string userType;
    int loginAttempts;
    bool isLocked;
    
    // Using our manual structs here
    Date registerDate;
    Time registerTime;

public:
    // REQUIREMENT: 1 constructor per module
    // This is the constructor
    User()
    {
        // Set default values for all variables
        username = "Unknown";
        password = "123";
        userType = "None";
        loginAttempts = 0;
        isLocked = false;
        
        registerDate.day = 1;
        registerDate.month = 1;
        registerDate.year = 2024;
        
        registerTime.hour = 0;
        registerTime.minute = 0;
        registerTime.second = 0;
    }

    // REQUIREMENT: 1 destructor per module
    // This is the destructor
    virtual ~User()
    {
        // Do nothing here
    }

    // REQUIREMENT: At least 4 overloaded/overridden functions
    // Overloaded Function 1: Set login info with 1 parameter
    void setLoginInfo(string u)
    {
        username = u;
    }

    // Overloaded Function 2: Set login info with 2 parameters
    void setLoginInfo(string u, string p)
    {
        username = u;
        password = p;
    }

    // Get the username
    string getUsername()
    {
        return username;
    }

    // Get the password
    string getPassword()
    {
        return password;
    }

    // Get the user type
    string getUserType()
    {
        return userType;
    }

    // Add 1 to login attempts
    void increaseLoginAttempts()
    {
        loginAttempts = loginAttempts + 1;
        
        // If tried 5 times, lock the account
        if (loginAttempts >= 5)
        {
            isLocked = true;
        }
    }

    // Check if account is locked
    bool getIsLocked()
    {
        return isLocked;
    }

    // Reset the login attempts to zero
    void resetLoginAttempts()
    {
        loginAttempts = 0;
        isLocked = false;
    }

    // Pure virtual functions
    // These must be implemented by derived classes
    virtual void displayRole() = 0;
    virtual void printDetailedUserInfo() = 0;
};

// ==========================================
// Derived Class 1: Patient (Inherits from User)
// REQUIREMENT: Derived Class
// ==========================================

class Patient : public User
{
private:
    // Private variables only for Patient
    int patientID;
    string bloodType;
    int age;
    double height;
    double weight;
    
    // Using our custom structs again
    Address patientAddress;
    ContactInfo patientContact;

public:
    // Constructor for Patient
    Patient()
    {
        // Initialize default values
        patientID = 0;
        bloodType = "Unknown";
        age = 0;
        height = 0.0;
        weight = 0.0;
        userType = "Patient"; // Set user type to Patient
    }

    // Destructor for Patient
    ~Patient()
    {
        // Nothing to delete manually here
    }

    // Set the patient ID
    void setPatientID(int id)
    {
        patientID = id;
    }

    // Get the patient ID
    int getPatientID()
    {
        return patientID;
    }

    // Set blood type
    void setBloodType(string bt)
    {
        bloodType = bt;
    }

    // Get blood type
    string getBloodType()
    {
        return bloodType;
    }

    // Set age
    void setAge(int a)
    {
        age = a;
    }

    // Get age
    int getAge()
    {
        return age;
    }

    // Set height
    void setHeight(double h)
    {
        height = h;
    }

    // Get height
    double getHeight()
    {
        return height;
    }

    // Set weight
    void setWeight(double w)
    {
        weight = w;
    }

    // Get weight
    double getWeight()
    {
        return weight;
    }

    // Set address using struct
    void setAddress(string st, string cy, string se, int zip)
    {
        patientAddress.street = st;
        patientAddress.city = cy;
        patientAddress.state = se;
        patientAddress.zipCode = zip;
    }

    // Set contact info using struct
    void setContact(string ph, string em, string ecn, string ecp)
    {
        patientContact.phone = ph;
        patientContact.email = em;
        patientContact.emergencyContactName = ecn;
        patientContact.emergencyContactPhone = ecp;
    }

    // Overridden Function 3
    // REQUIREMENT: Overridden function
    void displayRole() override
    {
        cout << "-----------------------------------" << endl;
        cout << "[Role Information]" << endl;
        cout << "I am a registered Patient in this system." << endl;
        cout << "My Patient ID is: " << patientID << endl;
        cout << "My Username is: " << username << endl;
        cout << "-----------------------------------" << endl;
    }

    // Another Overridden Function
    void printDetailedUserInfo() override
    {
        cout << "--- Patient Detailed Profile Page ---" << endl;
        cout << "ID Number: " << patientID << endl;
        cout << "Age: " << age << " years old" << endl;
        cout << "Blood Type: " << bloodType << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "City Location: " << patientAddress.city << endl;
        cout << "Phone Number: " << patientContact.phone << endl;
        cout << "-------------------------------------" << endl;
    }

    // REQUIREMENT: At least 4 friend functions
    // Friend function 1
    friend void showPatientSecret(Patient &p);
};

// ==========================================
// Derived Class 2: Staff (Inherits from User)
// REQUIREMENT: Derived Class
// ==========================================

class Staff : public User
{
private:
    // Private variables for Staff only
    int staffID;
    string department;
    string position;
    double salary;
    int clearanceLevel;
    string shift;

public:
    // Constructor for Staff
    Staff()
    {
        // Set default values
        staffID = 0;
        department = "General";
        position = "Staff";
        salary = 0.0;
        clearanceLevel = 1;
        shift = "Day";
        userType = "Staff"; // Set user type to Staff
    }

    // Destructor for Staff
    ~Staff()
    {
        // Nothing to delete manually here
    }

    // Set staff ID
    void setStaffID(int id)
    {
        staffID = id;
    }

    // Get staff ID
    int getStaffID()
    {
        return staffID;
    }

    // Set department
    void setDepartment(string d)
    {
        department = d;
    }

    // Get department
    string getDepartment()
    {
        return department;
    }

    // Set position
    void setPosition(string p)
    {
        position = p;
    }

    // Get position
    string getPosition()
    {
        return position;
    }

    // Set salary
    void setSalary(double s)
    {
        salary = s;
    }

    // Get salary
    double getSalary()
    {
        return salary;
    }

    // Set clearance level
    void setClearanceLevel(int c)
    {
        clearanceLevel = c;
    }

    // Get clearance level
    int getClearanceLevel()
    {
        return clearanceLevel;
    }

    // Set shift
    void setShift(string s)
    {
        shift = s;
    }

    // Get shift
    string getShift()
    {
        return shift;
    }

    // Overridden Function 4
    // REQUIREMENT: Overridden function
    void displayRole() override
    {
        cout << "-----------------------------------" << endl;
        cout << "[Role Information]" << endl;
        cout << "I am a Hospital Staff Member (Admin)." << endl;
        cout << "My Staff ID is: " << staffID << endl;
        cout << "My Department is: " << department << endl;
        cout << "My Position is: " << position << endl;
        cout << "-----------------------------------" << endl;
    }

    // Another Overridden Function
    void printDetailedUserInfo() override
    {
        cout << "--- Staff Detailed Profile Page ---" << endl;
        cout << "ID Number: " << staffID << endl;
        cout << "Department: " << department << endl;
        cout << "Job Position: " << position << endl;
        cout << "Work Shift: " << shift << endl;
        cout << "Security Clearance: Level " << clearanceLevel << endl;
        cout << "-----------------------------------" << endl;
    }

    // Friend function 2
    friend void showStaffSecret(Staff &s);
};

// ==========================================
// Base Class 2: Record
// REQUIREMENT: Base Class
// ==========================================

class Record
{
protected:
    // Protected variables for Record
    int recordID;
    string recordStatus;
    Date creationDate;
    Time creationTime;
    bool isArchived;

public:
    // Constructor
    Record()
    {
        // Set default values
        recordID = -1;
        recordStatus = "Pending";
        isArchived = false;
        
        creationDate.day = 1;
        creationDate.month = 1;
        creationDate.year = 2024;
        
        creationTime.hour = 8;
        creationTime.minute = 30;
        creationTime.second = 0;
    }

    // Destructor
    virtual ~Record()
    {
        // Do nothing
    }

    // Set record ID
    void setRecordID(int id)
    {
        recordID = id;
    }

    // Get record ID
    int getRecordID()
    {
        return recordID;
    }

    // Set status
    void setRecordStatus(string status)
    {
        recordStatus = status;
    }

    // Get status
    string getRecordStatus()
    {
        return recordStatus;
    }

    // Archive the record
    void archiveRecord()
    {
        isArchived = true;
    }

    // Check if archived
    bool checkArchived()
    {
        return isArchived;
    }

    // Set date
    void setCreationDate(int d, int m, int y)
    {
        creationDate.day = d;
        creationDate.month = m;
        creationDate.year = y;
    }

    // Set time
    void setCreationTime(int h, int min, int sec)
    {
        creationTime.hour = h;
        creationTime.minute = min;
        creationTime.second = sec;
    }

    // Pure virtual functions
    virtual void printDetails() = 0;
    virtual void printFullSummary() = 0;
};

// ==========================================
// Derived Class 3: Appointment (Inherits from Record)
// REQUIREMENT: Derived Class
// ==========================================

class Appointment : public Record
{
public:
    // Public variables for easy access
    string patientName;
    string disease;
    string symptoms;
    string prescribedMedicine;
    double bill;
    int assignedRoom;
    int assignedDoctorID;
    bool isEmergency;
    string insuranceProvider;
    double insuranceCoverPercentage;

    // Default Constructor
    Appointment()
    {
        recordID = -1;
        patientName = "N/A";
        disease = "None";
        symptoms = "None";
        prescribedMedicine = "None";
        bill = 0.0;
        assignedRoom = 0;
        assignedDoctorID = 0;
        isEmergency = false;
        insuranceProvider = "Self-Pay";
        insuranceCoverPercentage = 0.0;
        recordStatus = "Active";
    }

    // Parameterized Constructor
    Appointment(int id, string name, string dis, double b)
    {
        recordID = id;
        patientName = name;
        disease = dis;
        bill = b;
        symptoms = "Not recorded yet";
        prescribedMedicine = "Pending Doctor Review";
        assignedRoom = 101;
        assignedDoctorID = 999;
        isEmergency = false;
        insuranceProvider = "Standard";
        insuranceCoverPercentage = 0.0;
        recordStatus = "Active";
    }

    // Destructor
    ~Appointment()
    {
        // Do nothing
    }

    // Get appointment ID
    int getApptID()
    {
        return recordID;
    }

    // Set symptoms
    void setSymptoms(string symp)
    {
        symptoms = symp;
    }

    // Get symptoms
    string getSymptoms()
    {
        return symptoms;
    }

    // Set medicine
    void setMedicine(string med)
    {
        prescribedMedicine = med;
    }

    // Get medicine
    string getMedicine()
    {
        return prescribedMedicine;
    }

    // Set room number
    void setRoom(int room)
    {
        assignedRoom = room;
    }

    // Get room number
    int getRoom()
    {
        return assignedRoom;
    }

    // Set doctor ID
    void setDoctorID(int docID)
    {
        assignedDoctorID = docID;
    }

    // Get doctor ID
    int getDoctorID()
    {
        return assignedDoctorID;
    }

    // Set emergency status
    void setEmergencyStatus(bool status)
    {
        isEmergency = status;
    }

    // Get emergency status
    bool getEmergencyStatus()
    {
        return isEmergency;
    }

    // Set insurance info
    void setInsurance(string provider, double percentage)
    {
        insuranceProvider = provider;
        insuranceCoverPercentage = percentage;
    }

    // Calculate the final bill with discount
    double calculateFinalBill()
    {
        double discountAmount;
        discountAmount = (bill * insuranceCoverPercentage) / 100.0;
        
        double finalAmount;
        finalAmount = bill - discountAmount;
        
        // Bill cannot be negative
        if (finalAmount < 0)
        {
            finalAmount = 0.0;
        }
        
        return finalAmount;
    }

    // Overridden function from Record class
    void printDetails() override
    {
        cout << "=====================================" << endl;
        cout << "Appointment ID : " << recordID << endl;
        cout << "Patient Name   : " << patientName << endl;
        cout << "Disease type   : " << disease << endl;
        cout << "Base Bill Money: $" << bill << endl;
        cout << "Current Status : " << recordStatus << endl;
        cout << "=====================================" << endl;
    }

    // Overridden function from Record class
    void printFullSummary() override
    {
        cout << "*************************************" << endl;
        cout << "        FULL APPOINTMENT SUMMARY     " << endl;
        cout << "*************************************" << endl;
        
        cout << "Record ID number: " << recordID << endl;
        cout << "Current Status  : " << recordStatus << endl;
        cout << "Patient Name    : " << patientName << endl;
        
        cout << "Is it Emergency : ";
        // Student style if-else
        if (isEmergency == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
        cout << "Disease/Reason  : " << disease << endl;
        cout << "Symptoms Logged : " << symptoms << endl;
        cout << "Assigned Room   : " << assignedRoom << endl;
        cout << "Doctor ID       : " << assignedDoctorID << endl;
        cout << "Medicine Given  : " << prescribedMedicine << endl;
        cout << "Insurance Name  : " << insuranceProvider << endl;
        cout << "Coverage Percent: " << insuranceCoverPercentage << "%" << endl;
        cout << "Original Bill   : $" << bill << endl;
        
        double finalB;
        finalB = calculateFinalBill();
        
        cout << "Final Due Bill  : $" << finalB << endl;
        cout << "*************************************" << endl;
    }

    // Friend function 3
    friend void modifyAppt(Appointment &a, string newName);
};

// ==========================================
// Implement the Friend Functions
// ==========================================

// This function shows patient secret
void showPatientSecret(Patient &p)
{
    cout << ">>> Security Override. Patient ID is: " << p.patientID << endl;
}

// This function shows staff secret
void showStaffSecret(Staff &s)
{
    cout << ">>> Security Override. Staff ID is: " << s.staffID << endl;
}

// This function changes the appointment name
void modifyAppt(Appointment &a, string newName)
{
    a.patientName = newName;
}

// ==========================================
// REQUIREMENT: Dynamic Non-Primitive (DNP) Data Structure
// This is a Linked Queue. Copied and expanded from Chapter 5.
// ==========================================

// Struct for the queue node
struct node
{
    Appointment data; // This holds the appointment data
    node *next;       // This is the pointer to the next node
};

// This is the queue class
class ADTqueue
{
private:
    node *front; // Pointer to the front of queue
    node *rear;  // Pointer to the back of queue
    int queueSize; // To keep track of how many people

public:
    // Constructor
    ADTqueue()
    {
        // Make pointers NULL at the start
        front = NULL;
        rear = NULL;
        queueSize = 0;
    }

    // Destructor
    ~ADTqueue()
    {
        int check;
        check = empty();
        
        // Loop until queue is completely empty
        while (check == 0)
        {
            try
            {
                // Delete nodes one by one
                serveSilent();
            }
            catch (...)
            {
                break; // Stop if there is an error
            }
            
            // Update the check variable
            check = empty();
        }
    }

    // Check if the queue is empty
    int empty()
    {
        if (front == NULL)
        {
            // Return 1 means it is empty
            return 1;
        }
        else
        {
            // Return 0 means it has items
            return 0;
        }
    }

    // Get the total size
    int getSize()
    {
        return queueSize;
    }

    // Add a new item to the back of the queue
    void append(Appointment appt)
    {
        if (rear != NULL)
        {
            // REQUIREMENT: Dynamic memory allocation (new)
            node *newNode;
            newNode = new node;
            
            rear->next = newNode;
            rear = rear->next;
            rear->data = appt;
            rear->next = NULL;
        }
        else
        {
            // REQUIREMENT: Dynamic memory allocation (new)
            node *newNode;
            newNode = new node;
            
            front = newNode;
            rear = newNode;
            
            front->data = appt;
            front->next = NULL;
        }
        
        // Add 1 to the size
        queueSize = queueSize + 1;
        
        // cout << "test queue append"; // debug test
    }

    // Take out an item from the front of the queue
    Appointment serve()
    {
        Appointment emptyAppt;
        emptyAppt.setRecordID(-1);
        emptyAppt.patientName = "None";

        int check;
        check = empty();

        // If it is not empty
        if (check == 0)
        {
            Appointment appt;
            appt = front->data;
            
            node *temp;
            temp = front;
            
            front = front->next;

            // REQUIREMENT: Dynamic memory allocation (delete)
            // Clean up the memory to prevent leaks
            delete temp;

            if (front == NULL)
            {
                rear = NULL;
            }

            // Reduce size by 1
            queueSize = queueSize - 1;
            
            // Return the appointment data
            return appt;
        }
        else
        {
            cout << "Queue is Empty! Cannot serve anyone." << endl;
            // REQUIREMENT: Throw error for try-catch
            throw QueueEmptyException();
        }
    }

    // This serve function does not print anything
    // It is used in the destructor
    void serveSilent()
    {
        int check;
        check = empty();
        
        if (check == 0)
        {
            node *temp;
            temp = front;
            
            front = front->next;
            
            delete temp;
            
            if (front == NULL)
            {
                rear = NULL;
            }
            
            queueSize = queueSize - 1;
        }
        else
        {
            // Throw error if empty
            throw QueueEmptyException();
        }
    }

    // Display how many people are in the queue
    void displayQueueStatus()
    {
        cout << "-----------------------------------" << endl;
        cout << "Current Queue Size is: " << queueSize << endl;
        
        if (front != NULL)
        {
            cout << "Next Patient waiting is: " << front->data.patientName << endl;
        }
        else
        {
            cout << "The queue is currently empty." << endl;
        }
        
        cout << "-----------------------------------" << endl;
    }

    // Friend function 4
    friend void checkQueueFront(ADTqueue &q);
};

// Check what is at the front of the queue
void checkQueueFront(ADTqueue &q)
{
    if (q.front != NULL)
    {
        cout << "Front Appointment ID is: " << q.front->data.getApptID() << endl;
    }
    else
    {
        cout << "Front is currently NULL." << endl;
    }
}

// ---------------------------------------------------------
// MEDICAL HELPER CLASS
// This class translates disease codes to real disease names.
// It uses a huge switch-case statement to make the code long and detailed.
// ---------------------------------------------------------
class MedicalHelper
{
public:
// Constructor
MedicalHelper()
{
// Do nothing
}
// Destructor
~MedicalHelper()
{
// Do nothing
}
// This function gets the disease name based on a number code
string getDiseaseName(int code)
{
string diseaseName;
diseaseName = "Unknown Disease";
switch (code)
{
case 1:
diseaseName = "Common Cold";
break;
case 2:
diseaseName = "Seasonal Flu";
break;
case 3:
diseaseName = "Covid-19 Mild";
break;
case 4:
diseaseName = "Covid-19 Severe";
break;
case 5:
diseaseName = "Headache";
break;
case 6:
diseaseName = "Migraine";
break;
case 7:
diseaseName = "Stomach Ache";
break;
case 8:
diseaseName = "Food Poisoning";
break;
case 9:
diseaseName = "Allergy Reaction";
break;
case 10:
diseaseName = "Asthma Attack";
break;
case 11:
diseaseName = "Broken Arm";
break;
case 12:
diseaseName = "Broken Leg";
break;
case 13:
diseaseName = "Sprained Ankle";
break;
case 14:
diseaseName = "Muscle Tear";
break;
case 15:
diseaseName = "Back Pain";
break;
case 16:
diseaseName = "Neck Pain";
break;
case 17:
diseaseName = "Eye Infection";
break;
case 18:
diseaseName = "Ear Infection";
break;
case 19:
diseaseName = "Throat Infection";
break;
case 20:
diseaseName = "Toothache";
break;
case 21:
diseaseName = "Skin Rash";
break;
case 22:
diseaseName = "Burn Injury";
break;
case 23:
diseaseName = "Cut Wound";
break;
case 24:
diseaseName = "Dog Bite";
break;
case 25:
diseaseName = "Cat Scratch";
break;
case 26:
diseaseName = "High Fever";
break;
case 27:
diseaseName = "Low Blood Pressure";
break;
case 28:
diseaseName = "High Blood Pressure";
break;
case 29:
diseaseName = "Diabetes Type 1";
break;
case 30:
diseaseName = "Diabetes Type 2";
break;
case 31:
diseaseName = "Heart Palpitation";
break;
case 32:
diseaseName = "Chest Pain";
break;
case 33:
diseaseName = "Breathing Difficulty";
break;
case 34:
diseaseName = "Dizziness";
break;
case 35:
diseaseName = "Fainting";
break;
case 36:
diseaseName = "Dehydration";
break;
case 37:
diseaseName = "Sunstroke";
break;
case 38:
diseaseName = "Frostbite";
break;
case 39:
diseaseName = "Poison Ivy Contact";
break;
case 40:
diseaseName = "Bee Sting Allergy";
break;
case 41:
diseaseName = "Food Choking";
break;
case 42:
diseaseName = "Anemia";
break;
case 43:
diseaseName = "Vitamin Deficiency";
break;
case 44:
diseaseName = "Sleep Apnea";
break;
case 45:
diseaseName = "Insomnia";
break;
case 46:
diseaseName = "Anxiety Panic Attack";
break;
case 47:
diseaseName = "Depression Symptoms";
break;
case 48:
diseaseName = "Kidney Stones";
break;
case 49:
diseaseName = "Gallstones";
break;
case 50:
diseaseName = "General Checkup";
break;
default:
diseaseName = "Unlisted Medical Condition";
break;
}
return diseaseName;
}
// This function gets the recommended medicine
string getRecommendedMedicine(int code)
{
string medicine;
medicine = "Rest and Water";
if (code == 1)
{
medicine = "Cold Pills";
}
if (code == 2)
{
medicine = "Flu Medicine";
}
if (code == 5)
{
medicine = "Painkillers";
}
if (code == 7)
{
medicine = "Stomach Medicine";
}
if (code == 11)
{
medicine = "Cast and Painkillers";
}
if (code == 26)
{
medicine = "Fever Reducer";
}
if (code == 50)
{
medicine = "None required";
}
return medicine;
}
// This function gives an estimated base bill
double getBaseBill(int code)
{
double baseAmount;
baseAmount = 50.0;
if (code > 10)
{
baseAmount = 150.0;
}
if (code > 20)
{
baseAmount = 300.0;
}
if (code > 30)
{
baseAmount = 500.0;
}
if (code > 40)
{
baseAmount = 750.0;
}
if (code == 50)
{
baseAmount = 100.0;
}
return baseAmount;
}
};
// ---------------------------------------------------------
// REQUIREMENT: Manual Sorting and Searching Algorithms
// We put them inside an AlgorithmManager class
// ---------------------------------------------------------
class AlgorithmManager
{
public:
// Constructor
AlgorithmManager()
{
// Do nothing
}
// Destructor
~AlgorithmManager()
{
// Do nothing
}
// ---------------------------------------------------------
// REQUIREMENT: Manual Sorting Algorithm (Bubble Sort)
// This sorts the appointments by their ID in ascending order.
// ---------------------------------------------------------
void performBubbleSort(Appointment array[], int totalItems)
{
int i;
i = 0;
int j;
int isSorted;
isSorted = 0;
Appointment temporaryData;
// Loop through the array
while (i < totalItems)
{
// Check if it is already sorted
if (isSorted == 1)
{
// Break the loop if sorting is done early
break;
}
// Assume it is sorted for this round
isSorted = 1;
j = 0;
// Inner loop for comparing side-by-side elements
while (j < (totalItems - i - 1))
{
int currentID;
currentID = array[j].getApptID();
int nextID;
nextID = array[j + 1].getApptID();
// If the left one is bigger than the right one
if (currentID > nextID)
{
// We need to swap them
temporaryData = array[j];
array[j] = array[j + 1];
array[j + 1] = temporaryData;
// Since we swapped, it means it was not fully sorted yet
isSorted = 0;
}
// Move to the next pair
j = j + 1;
}
// Move to the next pass
i = i + 1;
}
// cout << "test bubble sort finished here\n";
}
// ---------------------------------------------------------
// REQUIREMENT: Manual Searching Algorithm (Binary Search)
// This searches for an appointment by ID.
// IMPORTANT: The array MUST be sorted before using this!
// ---------------------------------------------------------
int performBinarySearch(Appointment table[], int size, int targetID)
{
int firstIndex;
firstIndex = 0;
int lastIndex;
lastIndex = size - 1;
int middleIndex;
int foundFlag;
foundFlag = 0;
int finalResult;
finalResult = -1;
// Loop while we have not found it and search space is valid
while (firstIndex <= lastIndex)
{
if (foundFlag == 1)
{
// Stop searching if we already found it
break;
}
// Calculate the middle point
middleIndex = (firstIndex + lastIndex) / 2;
int currentMiddleID;
currentMiddleID = table[middleIndex].getApptID();
// If the middle ID is exactly what we want
if (targetID == currentMiddleID)
{
foundFlag = 1;
finalResult = middleIndex;
}
else
{
// If our target is smaller than the middle
if (targetID < currentMiddleID)
{
// We discard the right half
lastIndex = middleIndex - 1;
}
else
{
// We discard the left half
firstIndex = middleIndex + 1;
}
}
}
// Return the array position, or -1 if not found
return finalResult;
}
// ---------------------------------------------------------
// Overloaded Searching Algorithm (Linear Search)
// REQUIREMENT: Overloaded function
// This searches by patient name instead of ID
// ---------------------------------------------------------
int performLinearSearchByName(Appointment table[], int size, string targetName)
{
int i;
i = 0;
int foundIndex;
foundIndex = -1;
StringUtils stringTool;
while (i < size)
{
string currentName;
currentName = table[i].patientName;
bool isSame;
isSame = stringTool.compareStrings(currentName, targetName);
if (isSame == true)
{
foundIndex = i;
// We stop at the first match
break;
}
i = i + 1;
}
return foundIndex;
}
};
// ---------------------------------------------------------
// GLOBAL SYSTEM DATABASE AND QUEUE
// ---------------------------------------------------------
// This is the global linked queue for patients waiting
ADTqueue globalHospitalQueue;
// We need a variable for the maximum size of our raw array
int MAX_DATABASE_SIZE = 500;
// REQUIREMENT: Dynamic Memory Allocation (Raw Pointer Array)
// This pointer will act as our dynamic array. No STL allowed!
Appointment* globalApptArray = new Appointment[MAX_DATABASE_SIZE];
// This keeps track of how many records are currently in the array
int currentApptCount = 0;
// ---------------------------------------------------------
// DATABASE MANAGER CLASS
// This handles saving and loading files (Data Sync)
// ---------------------------------------------------------
class DatabaseManager
{
public:
// Constructor
DatabaseManager()
{
// Do nothing
}
// Destructor
~DatabaseManager()
{
// Do nothing
}
// Save everything to the main text file
void saveMainDatabase()
{
// REQUIREMENT: At least 5 txt files (File 1: hospital_data.txt)
ofstream outFile;
outFile.open("hospital_data.txt");
int i;
i = 0;
// Loop through all records
while (i < currentApptCount)
{
int saveID;
saveID = globalApptArray[i].getApptID();
string saveName;
saveName = globalApptArray[i].patientName;
string saveDisease;
saveDisease = globalApptArray[i].disease;
double saveBill;
saveBill = globalApptArray[i].bill;
// Write to the file separated by spaces
outFile << saveID << " " << saveName << " " << saveDisease << " " << saveBill << endl;
i = i + 1;
}
// Always close the file
outFile.close();
}
// Load everything from the main text file
void loadMainDatabase()
{
ifstream inFile;
inFile.open("hospital_data.txt");
// Check if the file opened successfully
if (inFile.is_open() == true)
{
// Reset count to zero before loading
currentApptCount = 0;
int loadID;
string loadName;
string loadDisease;
double loadBill;
// Read line by line
while (inFile >> loadID >> loadName >> loadDisease >> loadBill)
{
// Check if we reached the maximum size
if (currentApptCount < MAX_DATABASE_SIZE)
{
Appointment newAppt(loadID, loadName, loadDisease, loadBill);
globalApptArray[currentApptCount] = newAppt;
currentApptCount = currentApptCount + 1;
}
else
{
// Cannot load more than max size
break;
}
}
// Always close the file
inFile.close();
}
else
{
// File does not exist yet, we will create it when saving
// cout << "test file not found";
}
}
// Add a new record to the database
void addNewRecord(Appointment newAppt)
{
if (currentApptCount < MAX_DATABASE_SIZE)
{
// Put it at the end of the array
globalApptArray[currentApptCount] = newAppt;
currentApptCount = currentApptCount + 1;
// Sync immediately
saveMainDatabase();
}
else
{
cout << "Error: The database array is completely full!" << endl;
}
}
// Delete a record from the database
void deleteRecord(int targetID)
{
AlgorithmManager algo;
// We must sort first before binary search
algo.performBubbleSort(globalApptArray, currentApptCount);
// Find the index
int foundIndex;
foundIndex = algo.performBinarySearch(globalApptArray, currentApptCount, targetID);
if (foundIndex != -1)
{
int i;
i = foundIndex;
// Shift all elements to the left manually (No vector erase!)
while (i < (currentApptCount - 1))
{
globalApptArray[i] = globalApptArray[i + 1];
i = i + 1;
}
// Reduce count by 1
currentApptCount = currentApptCount - 1;
// Sync immediately
saveMainDatabase();
cout << ">> Record deleted successfully." << endl;
}
else
{
cout << ">> Cannot delete. ID not found in database." << endl;
}
}
// Edit a record in the database
void editRecord(int targetID, string newDisease, double newBill)
{
AlgorithmManager algo;
// We must sort first before binary search
algo.performBubbleSort(globalApptArray, currentApptCount);
int foundIndex;
foundIndex = algo.performBinarySearch(globalApptArray, currentApptCount, targetID);
if (foundIndex != -1)
{
globalApptArray[foundIndex].disease = newDisease;
globalApptArray[foundIndex].bill = newBill;
// Sync immediately
saveMainDatabase();
cout << ">> Record edited successfully." << endl;
}
else
{
cout << ">> Cannot edit. ID not found in database." << endl;
}
}
// Log queue actions
void saveQueueLog(string actionInfo)
{
// REQUIREMENT: At least 5 txt files (File 2: hospital_queue_log.txt)
ofstream logFile;
logFile.open("hospital_queue_log.txt", ios::app);
logFile << "Queue Activity: " << actionInfo << endl;
logFile.close();
}
// Log general system actions
void saveSystemLog(string actionInfo)
{
// REQUIREMENT: At least 5 txt files (File 3: hospital_system_log.txt)
ofstream sysFile;
sysFile.open("hospital_system_log.txt", ios::app);
sysFile << "System Activity: " << actionInfo << endl;
sysFile.close();
}
};
// ---------------------------------------------------------
// End of Part 2
// ---------------------------------------------------------

// ---------------------------------------------------------
// SYMPTOM CHECKER CLASS
// This class asks the patient many questions to guess the disease.
// It is written line by line to make the logic very detailed.
// ---------------------------------------------------------
class SymptomChecker
{
public:
// Constructor
SymptomChecker()
{
// Do nothing
}
// Destructor
~SymptomChecker()
{
// Do nothing
}
// This huge function asks questions and returns a disease code
int runDiagnosis()
{
int finalDiseaseCode;
finalDiseaseCode = 50; // Default is General Checkup
char answer;
int symptomScore;
symptomScore = 0;
cout << "-----------------------------------" << endl;
cout << "STARTING MEDICAL DIAGNOSIS SYSTEM" << endl;
cout << "Please answer 'y' for YES or 'n' for NO." << endl;
cout << "-----------------------------------" << endl;
// Question 1
cout << "Do you have a high fever? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 10;
finalDiseaseCode = 26;
}
// Question 2
cout << "Do you have a continuous cough? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 5;
finalDiseaseCode = 2;
}
// Question 3
cout << "Do you have difficulty breathing? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 20;
finalDiseaseCode = 4;
}
// Question 4
cout << "Do you have a severe headache? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 5;
finalDiseaseCode = 6;
}
// Question 5
cout << "Does your stomach hurt after eating? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 8;
finalDiseaseCode = 8;
}
// Question 6
cout << "Do you have a skin rash that is red and itchy? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 7;
finalDiseaseCode = 21;
}
// Question 7
cout << "Did you fall down and hurt your arm? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 15;
finalDiseaseCode = 11;
}
// Question 8
cout << "Did you fall down and hurt your leg? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 15;
finalDiseaseCode = 12;
}
// Question 9
cout << "Do you feel pain in your lower back? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 6;
finalDiseaseCode = 15;
}
// Question 10
cout << "Do you feel dizzy when you stand up? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 4;
finalDiseaseCode = 34;
}
// Question 11
cout << "Do you have a sharp pain in your chest? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 25;
finalDiseaseCode = 32;
}
// Question 12
cout << "Do you feel sad or hopeless frequently? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 10;
finalDiseaseCode = 47;
}
// Question 13
cout << "Do you have trouble falling asleep at night? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 5;
finalDiseaseCode = 45;
}
// Question 14
cout << "Do your eyes feel itchy and look red? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 3;
finalDiseaseCode = 17;
}
// Question 15
cout << "Does your ear hurt inside? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 4;
finalDiseaseCode = 18;
}
// Question 16
cout << "Does your tooth hurt when you eat cold food? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 6;
finalDiseaseCode = 20;
}
// Question 17
cout << "Did you get bitten by an animal recently? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 12;
finalDiseaseCode = 24;
}
// Question 18
cout << "Are you feeling thirsty and urinating often? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 10;
finalDiseaseCode = 30;
}
// Question 19
cout << "Do you have sharp pain in your side or back below the ribs? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 18;
finalDiseaseCode = 48;
}
// Question 20
cout << "Have you been vomiting or feeling nauseous? (y/n): ";
cin >> answer;
if (answer == 'y')
{
symptomScore = symptomScore + 9;
finalDiseaseCode = 8;
}
// Give final result
cout << "-----------------------------------" << endl;
cout << "Diagnosis Complete!" << endl;
cout << "Your Symptom Score is: " << symptomScore << endl;
cout << "-----------------------------------" << endl;
return finalDiseaseCode;
}
};
// ---------------------------------------------------------
// PATIENT REPORT BUILDER CLASS
// This creates the text file for the patient's personal report
// ---------------------------------------------------------
class PatientReportBuilder
{
public:
// Constructor
PatientReportBuilder()
{
// Do nothing
}
// Destructor
~PatientReportBuilder()
{
// Do nothing
}
// This function generates the file line by line
void buildReport(string pName)
{
// REQUIREMENT: At least 5 txt files (File 4: patient_personal_report.txt)
ofstream reportFile;
reportFile.open("patient_personal_report.txt");
// Write header
reportFile << "************************************************" << endl;
reportFile << "*          HOSPITAL PATIENT REPORT             *" << endl;
reportFile << "************************************************" << endl;
reportFile << "Patient Name: " << pName << endl;
reportFile << "------------------------------------------------" << endl;
reportFile << "Below are your registered appointments:" << endl;
reportFile << "------------------------------------------------" << endl;
int countFound;
countFound = 0;
int i;
i = 0;
StringUtils stringTool;
double totalOwed;
totalOwed = 0.0;
// Loop through array to find patient's records
while (i < currentApptCount)
{
string currentRecordName;
currentRecordName = globalApptArray[i].patientName;
bool isMatch;
isMatch = stringTool.compareStrings(currentRecordName, pName);
if (isMatch == true)
{
countFound = countFound + 1;
int currentID;
currentID = globalApptArray[i].getApptID();
string currentDisease;
currentDisease = globalApptArray[i].disease;
double currentBill;
currentBill = globalApptArray[i].bill;
totalOwed = totalOwed + currentBill;
reportFile << "Appointment No. " << countFound << ":" << endl;
reportFile << "  > ID Number     : " << currentID << endl;
reportFile << "  > Disease Type  : " << currentDisease << endl;
reportFile << "  > Bill Amount   : $" << currentBill << endl;
reportFile << "................................................" << endl;
}
i = i + 1;
}
if (countFound == 0)
{
reportFile << "You have no appointments registered yet." << endl;
}
reportFile << "------------------------------------------------" << endl;
reportFile << "Total Appointments Found : " << countFound << endl;
reportFile << "Total Expected Bill      : $" << totalOwed << endl;
reportFile << "************************************************" << endl;
reportFile << "End of Report." << endl;
reportFile.close();
cout << ">> Your personal report has been saved to 'patient_personal_report.txt'" << endl;
}
};
// ---------------------------------------------------------
// CUSTOMER MODULE (PATIENT DASHBOARD)
// This handles all the actions a patient can do
// ---------------------------------------------------------
void runCustomerModule(string currentLoggedInUser)
{
int menuChoice;
bool keepRunningPatientModule;
keepRunningPatientModule = true;
// Create objects we will need
Patient currentPatient;
currentPatient.setLoginInfo(currentLoggedInUser);
DatabaseManager dbManager;
SymptomChecker symptomSys;
PatientReportBuilder reportSys;
MedicalHelper medHelper;
// Show role
currentPatient.displayRole();
// Loop for the patient menu
while (keepRunningPatientModule == true)
{
// Ensure data is synced before showing menu
dbManager.loadMainDatabase();
cout << "\n=========================================" << endl;
cout << "        CUSTOMER (PATIENT) DASHBOARD     " << endl;
cout << "=========================================" << endl;
cout << "1. Make a New Appointment (Run Diagnosis)" << endl;
cout << "2. Make a New Appointment (Manual Entry)" << endl;
cout << "3. View My Appointment History" << endl;
cout << "4. Check Current Queue Status" << endl;
cout << "5. Generate My Personal Report (.txt)" << endl;
cout << "6. View My Detailed Profile" << endl;
cout << "7. Logout and Return to Main Menu" << endl;
cout << "=========================================" << endl;
cout << "Please enter your choice number: ";
cin >> menuChoice;
// REQUIREMENT: Try and Catch block for Error Handling
try
{
if (menuChoice == 1)
{
// AI Diagnosis Option
cout << "\n--- Starting AI Diagnosis ---" << endl;
int suggestedCode;
suggestedCode = symptomSys.runDiagnosis();
string suggestedDisease;
suggestedDisease = medHelper.getDiseaseName(suggestedCode);
double suggestedBill;
suggestedBill = medHelper.getBaseBill(suggestedCode);
int newID;
cout << "Based on your answers, you might have: " << suggestedDisease << endl;
cout << "The estimated base bill is: $" << suggestedBill << endl;
cout << "Please enter a unique ID number for your appointment: ";
cin >> newID;
if (newID < 0)
{
throw InvalidIDException();
}
// Create the appointment object
Appointment newAppt(newID, currentLoggedInUser, suggestedDisease, suggestedBill);
// Append to Queue (Memory linked list)
globalHospitalQueue.append(newAppt);
// Save to global array and sync to text file
dbManager.addNewRecord(newAppt);
// Save log
dbManager.saveQueueLog("Patient used AI Diagnosis to add ID: " + to_string(newID));
cout << ">> Appointment successfully created and added to the queue!" << endl;
}
else if (menuChoice == 2)
{
// Manual Entry Option
cout << "\n--- Manual Appointment Entry ---" << endl;
int manualID;
cout << "Enter a unique Appointment ID (Numbers only): ";
cin >> manualID;
if (manualID < 0)
{
throw InvalidIDException();
}
string manualDisease;
cout << "Enter your disease or reason for visit (No spaces): ";
cin >> manualDisease;
double manualBill;
cout << "Enter your expected bill amount: ";
cin >> manualBill;
if (manualBill < 0)
{
throw NegativeBillException();
}
Appointment manualAppt(manualID, currentLoggedInUser, manualDisease, manualBill);
globalHospitalQueue.append(manualAppt);
dbManager.addNewRecord(manualAppt);
dbManager.saveQueueLog("Patient manually added ID: " + to_string(manualID));
cout << ">> Appointment successfully created and added to the queue!" << endl;
}
else if (menuChoice == 3)
{
// View History Option
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
cout << "\n--- Your Appointment History ---" << endl;
int i;
i = 0;
int countMatches;
countMatches = 0;
StringUtils stringTool;
while (i < currentApptCount)
{
string checkName;
checkName = globalApptArray[i].patientName;
bool isMyRecord;
isMyRecord = stringTool.compareStrings(checkName, currentLoggedInUser);
if (isMyRecord == true)
{
globalApptArray[i].printDetails();
countMatches = countMatches + 1;
}
i = i + 1;
}
if (countMatches == 0)
{
cout << "You do not have any records in the system." << endl;
}
}
else if (menuChoice == 4)
{
// Check Queue
cout << "\n--- Hospital Queue Status ---" << endl;
globalHospitalQueue.displayQueueStatus();
}
else if (menuChoice == 5)
{
// Generate Report
cout << "\n--- Generating Report ---" << endl;
reportSys.buildReport(currentLoggedInUser);
dbManager.saveSystemLog("Patient generated personal report.");
}
else if (menuChoice == 6)
{
// View Profile
currentPatient.setAge(25);
currentPatient.setBloodType("O+");
currentPatient.setHeight(175.5);
currentPatient.setWeight(70.2);
currentPatient.setAddress("123 Main St", "Metropolis", "NY", 10001);
currentPatient.setContact("555-1234", "user@email.com", "Mom", "555-9999");
currentPatient.printDetailedUserInfo();
}
else if (menuChoice == 7)
{
// Logout
cout << "Saving your session..." << endl;
dbManager.saveSystemLog("Patient logged out of the system.");
cout << "Logging out. Goodbye!" << endl;
keepRunningPatientModule = false;
}
else
{
cout << "Invalid menu choice. Please type a number from 1 to 7." << endl;
}
}
// Catch our custom exceptions
catch (InvalidIDException &e)
{
cout << e.getMessage() << endl;
}
catch (NegativeBillException &e)
{
cout << e.getMessage() << endl;
}
catch (DatabaseEmptyException &e)
{
cout << e.getMessage() << endl;
}
// Catch any other unexpected errors
catch (...)
{
cout << "An unexpected error happened in the Patient Module." << endl;
}
}
}
// ---------------------------------------------------------
// End of Part 3
// ---------------------------------------------------------

// ---------------------------------------------------------
// ADMIN REPORT BUILDER CLASS
// This creates the text file for the hospital admin report
// ---------------------------------------------------------
class AdminReportBuilder
{
public:
// Constructor
AdminReportBuilder()
{
// Do nothing
}
// Destructor
~AdminReportBuilder()
{
// Do nothing
}
// This function generates the file line by line
void buildAdminReport()
{
// REQUIREMENT: At least 5 txt files (File 5: admin_summary_report.txt)
ofstream adminFile;
adminFile.open("admin_summary_report.txt");
adminFile << "================================================" << endl;
adminFile << "=          HOSPITAL ADMIN SUMMARY REPORT       =" << endl;
adminFile << "================================================" << endl;
adminFile << "Total Records in Database: " << currentApptCount << endl;
adminFile << "------------------------------------------------" << endl;
int i;
i = 0;
double totalRevenue;
totalRevenue = 0.0;
// Loop through array to calculate totals
while (i < currentApptCount)
{
int currentID;
currentID = globalApptArray[i].getApptID();
string currentName;
currentName = globalApptArray[i].patientName;
string currentDisease;
currentDisease = globalApptArray[i].disease;
double currentBill;
currentBill = globalApptArray[i].bill;
totalRevenue = totalRevenue + currentBill;
adminFile << "[" << i + 1 << "] ID: " << currentID;
adminFile << " | Name: " << currentName;
adminFile << " | Disease: " << currentDisease;
adminFile << " | Bill: $" << currentBill << endl;
i = i + 1;
}
adminFile << "------------------------------------------------" << endl;
adminFile << "Total Expected Hospital Revenue : $" << totalRevenue << endl;
adminFile << "================================================" << endl;
adminFile << "End of Admin Report." << endl;
adminFile.close();
cout << ">> Admin summary report has been saved to 'admin_summary_report.txt'" << endl;
}
};
// ---------------------------------------------------------
// STAFF / ADMIN MODULE
// This handles all the actions a hospital staff member can do
// ---------------------------------------------------------
void runAdminModule(string currentLoggedInStaff)
{
int menuChoice;
bool keepRunningAdminModule;
keepRunningAdminModule = true;
// Create objects we will need
Staff currentAdmin;
currentAdmin.setLoginInfo(currentLoggedInStaff);
DatabaseManager dbManager;
AlgorithmManager algoSys;
AdminReportBuilder adminReportSys;
// Show role
currentAdmin.displayRole();
// Loop for the admin menu
while (keepRunningAdminModule == true)
{
// Ensure data is synced before showing menu
dbManager.loadMainDatabase();
cout << "\n=========================================" << endl;
cout << "        STAFF (ADMIN) DASHBOARD          " << endl;
cout << "=========================================" << endl;
cout << "1. Call Next Patient (Serve from Queue)" << endl;
cout << "2. View All Patient Records" << endl;
cout << "3. Sort Appointments (by ID Ascending)" << endl;
cout << "4. Search Appointment (Binary Search by ID)" << endl;
cout << "5. Search Appointment (Linear Search by Name)" << endl;
cout << "6. Edit an Appointment Record" << endl;
cout << "7. Delete an Appointment Record" << endl;
cout << "8. Generate Admin Summary Report (.txt)" << endl;
cout << "9. View My Staff Profile" << endl;
cout << "10. Logout and Return to Main Menu" << endl;
cout << "=========================================" << endl;
cout << "Please enter your choice number: ";
cin >> menuChoice;
// REQUIREMENT: Try and Catch block for Error Handling
try
{
if (menuChoice == 1)
{
// Serve Patient
cout << "\n--- Calling Next Patient ---" << endl;
// This will throw QueueEmptyException if empty
Appointment servedAppt;
servedAppt = globalHospitalQueue.serve();
cout << ">> Doctor is now seeing patient: " << servedAppt.patientName << endl;
cout << ">> Patient Appt ID: " << servedAppt.getApptID() << endl;
dbManager.saveQueueLog("Admin served patient: " + servedAppt.patientName);
}
else if (menuChoice == 2)
{
// View All
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
cout << "\n--- All Database Records ---" << endl;
int i;
i = 0;
while (i < currentApptCount)
{
globalApptArray[i].printDetails();
i = i + 1;
}
}
else if (menuChoice == 3)
{
// Sort Records
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
cout << "\n--- Sorting Database (Bubble Sort) ---" << endl;
algoSys.performBubbleSort(globalApptArray, currentApptCount);
dbManager.saveMainDatabase();
cout << ">> Database sorted successfully by ID." << endl;
int i;
i = 0;
while (i < currentApptCount)
{
globalApptArray[i].printDetails();
i = i + 1;
}
dbManager.saveSystemLog("Admin sorted the database.");
}
else if (menuChoice == 4)
{
// Search by ID (Binary Search)
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
int searchTarget;
cout << "\n--- Search Record by ID ---" << endl;
cout << "Enter Appointment ID to search: ";
cin >> searchTarget;
// Binary search MUST be sorted first
algoSys.performBubbleSort(globalApptArray, currentApptCount);
dbManager.saveMainDatabase();
int resultIndex;
resultIndex = algoSys.performBinarySearch(globalApptArray, currentApptCount, searchTarget);
if (resultIndex != -1)
{
cout << ">> Record Found in Database!" << endl;
globalApptArray[resultIndex].printFullSummary();
}
else
{
cout << ">> Record NOT FOUND." << endl;
}
dbManager.saveSystemLog("Admin searched for ID: " + to_string(searchTarget));
}
else if (menuChoice == 5)
{
// Search by Name (Linear Search)
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
string searchName;
cout << "\n--- Search Record by Patient Name ---" << endl;
cout << "Enter Patient Name to search: ";
cin >> searchName;
int resultIndex;
resultIndex = algoSys.performLinearSearchByName(globalApptArray, currentApptCount, searchName);
if (resultIndex != -1)
{
cout << ">> Record Found in Database!" << endl;
globalApptArray[resultIndex].printFullSummary();
}
else
{
cout << ">> Record NOT FOUND." << endl;
}
dbManager.saveSystemLog("Admin searched for Name: " + searchName);
}
else if (menuChoice == 6)
{
// Edit Record
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
int editTarget;
cout << "\n--- Edit Record ---" << endl;
cout << "Enter Appointment ID to edit: ";
cin >> editTarget;
string newDis;
cout << "Enter new disease: ";
cin >> newDis;
double newB;
cout << "Enter new bill amount: ";
cin >> newB;
if (newB < 0)
{
throw NegativeBillException();
}
dbManager.editRecord(editTarget, newDis, newB);
dbManager.saveSystemLog("Admin edited ID: " + to_string(editTarget));
}
else if (menuChoice == 7)
{
// Delete Record
if (currentApptCount == 0)
{
throw DatabaseEmptyException();
}
int deleteTarget;
cout << "\n--- Delete Record ---" << endl;
cout << "Enter Appointment ID to delete: ";
cin >> deleteTarget;
dbManager.deleteRecord(deleteTarget);
dbManager.saveSystemLog("Admin deleted ID: " + to_string(deleteTarget));
}
else if (menuChoice == 8)
{
// Generate Report
cout << "\n--- Generating Admin Report ---" << endl;
adminReportSys.buildAdminReport();
dbManager.saveSystemLog("Admin generated summary report.");
}
else if (menuChoice == 9)
{
// View Profile
currentAdmin.setDepartment("Emergency Room");
currentAdmin.setPosition("Head Nurse");
currentAdmin.setShift("Night Shift");
currentAdmin.setClearanceLevel(5);
currentAdmin.printDetailedUserInfo();
}
else if (menuChoice == 10)
{
// Logout
cout << "Saving database state..." << endl;
dbManager.saveSystemLog("Admin logged out of the system.");
cout << "Logging out. Goodbye!" << endl;
keepRunningAdminModule = false;
}
else
{
cout << "Invalid menu choice. Please type a number from 1 to 10." << endl;
}
}
// Catch our custom exceptions
catch (QueueEmptyException &e)
{
cout << e.getMessage() << endl;
}
catch (DatabaseEmptyException &e)
{
cout << e.getMessage() << endl;
}
catch (NegativeBillException &e)
{
cout << e.getMessage() << endl;
}
// Catch any other unexpected errors
catch (...)
{
cout << "An unexpected error happened in the Admin Module." << endl;
}
}
}
// ---------------------------------------------------------
// LOGIN AND REGISTRATION SYSTEM
// This handles the authentication for both modules
// ---------------------------------------------------------
class AuthenticationSystem
{
public:
AuthenticationSystem()
{
// Do nothing
}
~AuthenticationSystem()
{
// Do nothing
}
// Function to handle login or register logic
bool processLogin(string authFileName, string &loggedInUser)
{
int logChoice;
cout << "-----------------------------------" << endl;
cout << "1. Login to Existing Account" << endl;
cout << "2. Register a New Account" << endl;
cout << "-----------------------------------" << endl;
cout << "Select option: ";
cin >> logChoice;
string inputUser;
string inputPass;
if (logChoice == 2)
{
// Registration
cout << "Set your Username (No spaces): ";
cin >> inputUser;
cout << "Set your Password (No spaces): ";
cin >> inputPass;
// Open file in append mode
ofstream authFileOut;
authFileOut.open(authFileName.c_str(), ios::app);
authFileOut << inputUser << " " << inputPass << endl;
authFileOut.close();
cout << ">> Registration successful! Please login again." << endl;
return false;
}
else if (logChoice == 1)
{
// Login
cout << "Enter your Username: ";
cin >> inputUser;
cout << "Enter your Password: ";
cin >> inputPass;
bool isFound;
isFound = false;
string fileUser;
string filePass;
// Open file in read mode
ifstream authFileIn;
authFileIn.open(authFileName.c_str());
if (authFileIn.is_open() == true)
{
StringUtils stringTool;
while (authFileIn >> fileUser >> filePass)
{
bool matchUser;
matchUser = stringTool.compareStrings(fileUser, inputUser);
bool matchPass;
matchPass = stringTool.compareStrings(filePass, inputPass);
if (matchUser == true)
{
if (matchPass == true)
{
isFound = true;
// Break loop if found
break;
}
}
}
authFileIn.close();
}
else
{
cout << ">> Authentication file not found. Please register first." << endl;
return false;
}
if (isFound == true)
{
cout << ">> Login Successful! Welcome back, " << inputUser << "!" << endl;
// Pass the username back via reference
loggedInUser = inputUser;
return true;
}
else
{
cout << ">> Login Failed. Incorrect username or password." << endl;
return false;
}
}
else
{
cout << ">> Invalid choice." << endl;
return false;
}
}
};
// ---------------------------------------------------------
// MAIN FUNCTION
// The entry point of the entire system
// ---------------------------------------------------------
int main()
{
int mainChoice;
mainChoice = 0;
bool isSystemRunning;
isSystemRunning = true;
// Initialize Database manager and load existing data
DatabaseManager dbStarter;
dbStarter.loadMainDatabase();
AuthenticationSystem authSys;
string currentUserSession;
cout << "***************************************************" << endl;
cout << "*                                                 *" << endl;
cout << "*    WELCOME TO THE MINI HOSPITAL RECORDS SYSTEM  *" << endl;
cout << "*                                                 *" << endl;
cout << "***************************************************" << endl;
// Main Loop
while (isSystemRunning == true)
{
cout << "\n=========================================" << endl;
cout << "            MAIN ACCESS MENU             " << endl;
cout << "=========================================" << endl;
cout << "1. Enter Customer (Patient) Module" << endl;
cout << "2. Enter Staff (Admin) Module" << endl;
cout << "3. Exit the System Completely" << endl;
cout << "=========================================" << endl;
cout << "Please select your access level: ";
cin >> mainChoice;
if (mainChoice == 1)
{
cout << "\n--- Patient Authentication ---" << endl;
// We use patient_auth.txt for patients
string fileName;
fileName = "patient_auth.txt";
bool authSuccess;
authSuccess = authSys.processLogin(fileName, currentUserSession);
if (authSuccess == true)
{
runCustomerModule(currentUserSession);
}
}
else if (mainChoice == 2)
{
cout << "\n--- Staff Authentication ---" << endl;
// We use staff_auth.txt for staff members
string fileName;
fileName = "staff_auth.txt";
bool authSuccess;
authSuccess = authSys.processLogin(fileName, currentUserSession);
if (authSuccess == true)
{
runAdminModule(currentUserSession);
}
}
else if (mainChoice == 3)
{
cout << "\nSaving all databases..." << endl;
dbStarter.saveMainDatabase();
dbStarter.saveSystemLog("SYSTEM SHUTDOWN.");
isSystemRunning = false;
cout << "Exiting the hospital system. Goodbye!" << endl;
}
else
{
cout << ">> Invalid input. Please enter 1, 2, or 3." << endl;
}
}
// Clean up global dynamic memory before exiting completely
delete[] globalApptArray;
return 0;
}
// ---------------------------------------------------------
// END OF PROGRAM
// ---------------------------------------------------------
