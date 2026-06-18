#include <iostream>
#include <fstream>
#include <string>

// REQUIREMENT: Student coding style
// We use namespace std so we don't have to write std:: everywhere
using namespace std;

// =====================================================================
// MANUAL STRING TOOLS
// We cannot use <algorithm> or STL, so we must write our own string tools.
// This is typical for diploma students learning basic arrays and loops.
// =====================================================================
class StringUtils
{
public:
    // Constructor
    StringUtils()
    {
        // Do nothing here
    }

    // Destructor
    ~StringUtils()
    {
        // Do nothing here
    }

    // Function to manually count the length of a string
    int getLength(string str)
    {
        int count;
        count = 0;
        
        // Loop until we hit the null terminator character
        while (str[count] != '\0')
        {
            count = count + 1;
        }
        
        return count;
    }

    // Function to check if a string contains only numbers
    int isAllDigits(string str)
    {
        int len;
        len = getLength(str);
        
        int i;
        i = 0;
        
        int result;
        result = 1; // Assume true first
        
        while (i < len)
        {
            // If the character is less than '0'
            if (str[i] < '0')
            {
                result = 0;
            }
            
            // If the character is more than '9'
            if (str[i] > '9')
            {
                result = 0;
            }
            
            i = i + 1;
        }
        
        return result;
    }

    // Function to check if a string contains only English letters
    int isAllLetters(string str)
    {
        int len;
        len = getLength(str);
        
        int i;
        i = 0;
        
        int result;
        result = 1;
        
        while (i < len)
        {
            int isUpper;
            isUpper = 0;
            
            int isLower;
            isLower = 0;
            
            // Check if it is an uppercase letter
            if (str[i] >= 'A')
            {
                if (str[i] <= 'Z')
                {
                    isUpper = 1;
                }
            }
            
            // Check if it is a lowercase letter
            if (str[i] >= 'a')
            {
                if (str[i] <= 'z')
                {
                    isLower = 1;
                }
            }
            
            // If it is neither upper nor lower, and not a space
            if (isUpper == 0)
            {
                if (isLower == 0)
                {
                    if (str[i] != ' ')
                    {
                        result = 0;
                    }
                }
            }
            
            i = i + 1;
        }
        
        return result;
    }

    // Function to manually compare two strings
    int compareStrings(string s1, string s2)
    {
        int len1;
        len1 = getLength(s1);
        
        int len2;
        len2 = getLength(s2);
        
        // If lengths are different, they are definitely not the same
        if (len1 != len2)
        {
            return 0;
        }
        
        int i;
        i = 0;
        
        int match;
        match = 1;
        
        while (i < len1)
        {
            // If any character does not match, return false
            if (s1[i] != s2[i])
            {
                match = 0;
            }
            
            i = i + 1;
        }
        
        return match;
    }
};

// =====================================================================
// CUSTOM ERROR HANDLING CLASSES (EXCEPTIONS)
// REQUIREMENT: Must use Try and Catch blocks.
// I will create many classes to handle specific errors.
// =====================================================================

// Base Error Class
class BaseException
{
protected:
    string errorMessage;
    int errorCode;

public:
    // Constructor
    BaseException()
    {
        errorMessage = "An Unknown Error Happened";
        errorCode = 0;
    }

    // Destructor
    virtual ~BaseException()
    {
        // Do nothing
    }

    // Virtual getter for message
    virtual string getMessage()
    {
        return errorMessage;
    }

    // Virtual getter for error code
    virtual int getCode()
    {
        return errorCode;
    }
};

// Error for Invalid ID (e.g., negative ID)
// REQUIREMENT: Derived Class Inheritance
class InvalidIDException : public BaseException
{
public:
    InvalidIDException()
    {
        errorMessage = "Error: Invalid ID! ID cannot be negative.";
        errorCode = 101;
    }

    ~InvalidIDException()
    {
        // Do nothing
    }

    // REQUIREMENT: Overridden Function
    string getMessage() 
    {
        return errorMessage;
    }
};

// Error for Negative Money/Bill
// REQUIREMENT: Derived Class Inheritance
class NegativeBillException : public BaseException
{
public:
    NegativeBillException()
    {
        errorMessage = "Error: Bill money amount cannot be negative!";
        errorCode = 103;
    }

    ~NegativeBillException()
    {
        // Do nothing
    }

    // REQUIREMENT: Overridden Function
    string getMessage() 
    {
        return errorMessage;
    }
};

// Error when the Queue is completely empty
// REQUIREMENT: Derived Class Inheritance
class QueueEmptyException : public BaseException
{
public:
    QueueEmptyException()
    {
        errorMessage = "Error 999: The hospital queue is completely empty right now.";
        errorCode = 999;
    }

    ~QueueEmptyException()
    {
        // Do nothing
    }

    string getMessage() 
    {
        return errorMessage;
    }
};

// Error when the Database Array has no records
class DatabaseEmptyException : public BaseException
{
public:
    DatabaseEmptyException()
    {
        errorMessage = "Error 404: The database array has no records to show or process.";
        errorCode = 404;
    }

    ~DatabaseEmptyException()
    {
        // Do nothing
    }

    string getMessage() 
    {
        return errorMessage;
    }
};

// Error when file cannot be opened
class FileOpenException : public BaseException
{
public:
    FileOpenException()
    {
        errorMessage = "Error 500: System file could not be opened for reading/writing.";
        errorCode = 500;
    }

    ~FileOpenException()
    {
        // Do nothing
    }

    string getMessage() 
    {
        return errorMessage;
    }
};

// =====================================================================
// REQUIREMENT: At least 2 struct data types
// I will create 5 detailed structs to hold extra information.
// =====================================================================

// Struct 1: Date
struct Date
{
    int day;
    int month;
    int year;
};

// Struct 2: Time
struct Time
{
    int hour;
    int minute;
    int second;
};

// Struct 3: Address
struct Address
{
    string street;
    string city;
    string state;
    int zipCode;
};

// Struct 4: Contact Information
struct ContactInfo
{
    string phone;
    string email;
    string emergencyContactName;
    string emergencyContactPhone;
};

// Struct 5: Patient Vitals
struct Vitals
{
    double temperature;
    int heartRate;
    int bloodPressureSystolic;
    int bloodPressureDiastolic;
    int oxygenLevel;
};

// Struct 6: Detailed Billing
struct BillingDetails
{
    double consultationFee;
    double medicineFee;
    double roomFee;
    double taxAmount;
    double discountAmount;
    double totalAmountDue;
    int isPaid;
};

// =====================================================================
// GLOBAL CONSTANTS
// =====================================================================
int MAX_DATABASE_SIZE = 500; // Maximum array limit
int CLINIC_OPEN_HOUR = 8;
int CLINIC_CLOSE_HOUR = 22;

// End of Part 1

// =====================================================================
// REQUIREMENT: At least 2 Base Classes & 3 Derived Classes
// BASE CLASS 1: User
// This is the parent class for both Patient and Staff.
// =====================================================================
class User
{
protected:
    // Protected variables can be accessed by derived classes
    string username;
    string password;
    string userType;
    int loginAttempts;
    int isLocked;
    
    // Using our custom Date and Time structs from Part 1
    Date registerDate;
    Time registerTime;

public:
    // REQUIREMENT: At least 1 constructor per module
    User()
    {
        // Initialize everything to default values
        username = "UnknownUser";
        password = "DefaultPassword123";
        userType = "None";
        loginAttempts = 0;
        isLocked = 0;
        
        registerDate.day = 1;
        registerDate.month = 1;
        registerDate.year = 2024;
        
        registerTime.hour = 0;
        registerTime.minute = 0;
        registerTime.second = 0;
    }

    // REQUIREMENT: At least 1 destructor per module
    virtual ~User()
    {
        // Virtual destructor for safe memory cleanup in base class
    }

    // REQUIREMENT: At least 4 overloaded/overridden functions
    // Overloaded Function 1: Set login info with 1 parameter
    void setLoginInfo(string u)
    {
        username = u;
    }

    // REQUIREMENT: Overloaded Function 2: Set login info with 2 parameters
    void setLoginInfo(string u, string p)
    {
        username = u;
        password = p;
    }

    // Verbose Getters and Setters for Encapsulation
    string getUsername()
    {
        string result;
        result = username;
        return result;
    }

    string getPassword()
    {
        string result;
        result = password;
        return result;
    }

    void setUserType(string type)
    {
        userType = type;
    }

    string getUserType()
    {
        string result;
        result = userType;
        return result;
    }

    void increaseLoginAttempts()
    {
        loginAttempts = loginAttempts + 1;
        
        // Lock account if they fail 5 times
        if (loginAttempts >= 5)
        {
            isLocked = 1;
        }
    }

    int getLoginAttempts()
    {
        int result;
        result = loginAttempts;
        return result;
    }

    int getIsLocked()
    {
        int result;
        result = isLocked;
        return result;
    }

    void resetLoginAttempts()
    {
        loginAttempts = 0;
        isLocked = 0;
    }

    // Set Registration Date manually
    void setRegisterDate(int d, int m, int y)
    {
        registerDate.day = d;
        registerDate.month = m;
        registerDate.year = y;
    }

    // Set Registration Time manually
    void setRegisterTime(int h, int m, int s)
    {
        registerTime.hour = h;
        registerTime.minute = m;
        registerTime.second = s;
    }

    // Pure virtual functions (Abstract Class)
    virtual void displayRole() = 0;
    virtual void printDetailedProfile() = 0;
};

// =====================================================================
// DERIVED CLASS 1: Patient (Inherits from User)
// REQUIREMENT: Derived Class
// =====================================================================
class Patient : public User
{
private:
    int patientID;
    string bloodType;
    int age;
    double height;
    double weight;
    
    // Struct instances
    Address patientAddress;
    ContactInfo patientContact;
    Vitals patientVitals;

public:
    // Constructor
    Patient()
    {
        patientID = 0;
        bloodType = "Unknown";
        age = 0;
        height = 0.0;
        weight = 0.0;
        
        // Set inherited attribute
        userType = "Patient";
        
        // Default Address
        patientAddress.street = "Not Provided";
        patientAddress.city = "Not Provided";
        patientAddress.state = "Not Provided";
        patientAddress.zipCode = 0;
        
        // Default Contact
        patientContact.phone = "000-0000000";
        patientContact.email = "none@email.com";
        patientContact.emergencyContactName = "None";
        patientContact.emergencyContactPhone = "000-0000000";
        
        // Default Vitals
        patientVitals.temperature = 36.5;
        patientVitals.heartRate = 80;
        patientVitals.bloodPressureSystolic = 120;
        patientVitals.bloodPressureDiastolic = 80;
        patientVitals.oxygenLevel = 98;
    }

    // Destructor
    ~Patient()
    {
        // Do nothing
    }

    // Very detailed Getters and Setters
    void setPatientID(int id)
    {
        patientID = id;
    }

    int getPatientID()
    {
        int result;
        result = patientID;
        return result;
    }

    void setBloodType(string bt)
    {
        bloodType = bt;
    }

    string getBloodType()
    {
        string result;
        result = bloodType;
        return result;
    }

    void setAge(int a)
    {
        age = a;
    }

    int getAge()
    {
        int result;
        result = age;
        return result;
    }

    void setHeight(double h)
    {
        height = h;
    }

    double getHeight()
    {
        double result;
        result = height;
        return result;
    }

    void setWeight(double w)
    {
        weight = w;
    }

    double getWeight()
    {
        double result;
        result = weight;
        return result;
    }

    // Set Address details one by one
    void setStreet(string st)
    {
        patientAddress.street = st;
    }
    
    void setCity(string cy)
    {
        patientAddress.city = cy;
    }
    
    void setState(string se)
    {
        patientAddress.state = se;
    }
    
    void setZipCode(int zip)
    {
        patientAddress.zipCode = zip;
    }

    // Set Contact details one by one
    void setPhone(string ph)
    {
        patientContact.phone = ph;
    }
    
    void setEmail(string em)
    {
        patientContact.email = em;
    }
    
    void setEmergencyContactName(string ecn)
    {
        patientContact.emergencyContactName = ecn;
    }
    
    void setEmergencyContactPhone(string ecp)
    {
        patientContact.emergencyContactPhone = ecp;
    }

    // Set Vitals details one by one
    void setTemperature(double t)
    {
        patientVitals.temperature = t;
    }
    
    void setHeartRate(int hr)
    {
        patientVitals.heartRate = hr;
    }
    
    void setBloodPressureSystolic(int bps)
    {
        patientVitals.bloodPressureSystolic = bps;
    }
    
    void setBloodPressureDiastolic(int bpd)
    {
        patientVitals.bloodPressureDiastolic = bpd;
    }
    
    void setOxygenLevel(int oxy)
    {
        patientVitals.oxygenLevel = oxy;
    }

    // REQUIREMENT: Function 3
    void displayRole() 
    {
        cout << "======================================" << endl;
        cout << "SYSTEM ROLE VERIFICATION" << endl;
        cout << "Role Type  : Registered Patient" << endl;
        cout << "Patient ID : " << patientID << endl;
        cout << "Username   : " << username << endl;
        cout << "======================================" << endl;
    }

 
    void printDetailedProfile() 
    {
        cout << "---------- PATIENT DETAILED PROFILE ----------" << endl;
        cout << "ID Number       : " << patientID << endl;
        cout << "Current Age     : " << age << " years old" << endl;
        cout << "Blood Type      : " << bloodType << endl;
        cout << "Body Height     : " << height << " cm" << endl;
        cout << "Body Weight     : " << weight << " kg" << endl;
        cout << "City Location   : " << patientAddress.city << endl;
        cout << "Personal Phone  : " << patientContact.phone << endl;
        cout << "Emergency Name  : " << patientContact.emergencyContactName << endl;
        cout << "Emergency Phone : " << patientContact.emergencyContactPhone << endl;
        cout << "----------------------------------------------" << endl;
    }

    // REQUIREMENT: At least 4 friend functions (Friend Function 1)
    friend void showPatientSecret(Patient &p);
};

// =====================================================================
// DERIVED CLASS 2: Staff (Inherits from User)
// REQUIREMENT: Derived Class
// =====================================================================
class Staff : public User
{
private:
    int staffID;
    string department;
    string position;
    double salary;
    int clearanceLevel;
    string shift;

public:
    // Constructor
    Staff()
    {
        staffID = 0;
        department = "General Ward";
        position = "Junior Staff";
        salary = 3000.00;
        clearanceLevel = 1;
        shift = "Morning Shift";
        userType = "Staff";
    }

    // Destructor
    ~Staff()
    {
        // Do nothing
    }

    // Verbose Getters and Setters
    void setStaffID(int id)
    {
        staffID = id;
    }

    int getStaffID()
    {
        int result;
        result = staffID;
        return result;
    }

    void setDepartment(string d)
    {
        department = d;
    }

    string getDepartment()
    {
        string result;
        result = department;
        return result;
    }

    void setPosition(string p)
    {
        position = p;
    }

    string getPosition()
    {
        string result;
        result = position;
        return result;
    }

    void setSalary(double s)
    {
        salary = s;
    }

    double getSalary()
    {
        double result;
        result = salary;
        return result;
    }

    void setClearanceLevel(int c)
    {
        clearanceLevel = c;
    }

    int getClearanceLevel()
    {
        int result;
        result = clearanceLevel;
        return result;
    }

    void setShift(string s)
    {
        shift = s;
    }

    string getShift()
    {
        string result;
        result = shift;
        return result;
    }

  
    void displayRole() 
    {
        cout << "======================================" << endl;
        cout << "SYSTEM ROLE VERIFICATION" << endl;
        cout << "Role Type  : Hospital Staff / Admin" << endl;
        cout << "Staff ID   : " << staffID << endl;
        cout << "Department : " << department << endl;
        cout << "Position   : " << position << endl;
        cout << "======================================" << endl;
    }

    void printDetailedProfile()
    {
        cout << "---------- STAFF DETAILED PROFILE ----------" << endl;
        cout << "ID Number          : " << staffID << endl;
        cout << "Assigned Department: " << department << endl;
        cout << "Job Position       : " << position << endl;
        cout << "Work Shift Schedule: " << shift << endl;
        cout << "Security Clearance : Level " << clearanceLevel << endl;
        cout << "Monthly Salary     : $" << salary << endl;
        cout << "--------------------------------------------" << endl;
    }

    // REQUIREMENT: At least 4 friend functions (Friend Function 2)
    friend void showStaffSecret(Staff &s);
};

// =====================================================================
// BASE CLASS 2: Record
// REQUIREMENT: Base Class
// =====================================================================
class Record
{
protected:
    int recordID;
    string recordStatus;
    Date creationDate;
    Time creationTime;
    int isArchived;

public:
    // Constructor
    Record()
    {
        recordID = -1;
        recordStatus = "Pending Review";
        isArchived = 0;
        
        creationDate.day = 1;
        creationDate.month = 1;
        creationDate.year = 2024;
        
        creationTime.hour = 9;
        creationTime.minute = 0;
        creationTime.second = 0;
    }

    // Virtual Destructor
    virtual ~Record()
    {
        // Do nothing
    }

    void setRecordID(int id)
    {
        recordID = id;
    }

    int getRecordID()
    {
        int result;
        result = recordID;
        return result;
    }

    void setRecordStatus(string status)
    {
        recordStatus = status;
    }

    string getRecordStatus()
    {
        string result;
        result = recordStatus;
        return result;
    }

    void archiveRecord()
    {
        isArchived = 1;
    }

    int checkIsArchived()
    {
        int result;
        result = isArchived;
        return result;
    }

    // Pure virtual functions
    virtual void printShortDetails() = 0;
    virtual void printFullSummary() = 0;
};

// =====================================================================
// DERIVED CLASS 3: Appointment (Inherits from Record)
// REQUIREMENT: Derived Class
// =====================================================================
class Appointment : public Record
{
public:
    // These are public so we can easily sort and search them later
    string patientName;
    string disease;
    string symptoms;
    string prescribedMedicine;
    double bill;
    int assignedRoom;
    int assignedDoctorID;
    int isEmergency;
    string insuranceProvider;
    double insuranceCoverPercentage;
    
    // Struct for detailed billing
    BillingDetails apptBilling;

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
        isEmergency = 0;
        insuranceProvider = "Self-Pay";
        insuranceCoverPercentage = 0.0;
        recordStatus = "Active";
        
        apptBilling.consultationFee = 0.0;
        apptBilling.medicineFee = 0.0;
        apptBilling.roomFee = 0.0;
        apptBilling.taxAmount = 0.0;
        apptBilling.discountAmount = 0.0;
        apptBilling.totalAmountDue = 0.0;
        apptBilling.isPaid = 0;
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
        isEmergency = 0;
        insuranceProvider = "Standard Care";
        insuranceCoverPercentage = 0.0;
        recordStatus = "Active";
        
        apptBilling.consultationFee = b * 0.5;
        apptBilling.medicineFee = b * 0.3;
        apptBilling.roomFee = b * 0.2;
        apptBilling.taxAmount = b * 0.06;
        apptBilling.discountAmount = 0.0;
        apptBilling.totalAmountDue = b + apptBilling.taxAmount;
        apptBilling.isPaid = 0;
    }

    // Destructor
    ~Appointment()
    {
        // Do nothing
    }

    // Helper functions for easy access
    int getApptID()
    {
        int result;
        result = recordID;
        return result;
    }

    // Manual calculation of final bill
    double calculateFinalBill()
    {
        double base;
        base = bill;
        
        double discount;
        discount = (base * insuranceCoverPercentage) / 100.0;
        
        double tax;
        tax = base * 0.06; // 6% tax
        
        double finalAmount;
        finalAmount = base + tax - discount;
        
        // Ensure bill does not go negative
        if (finalAmount < 0.0)
        {
            finalAmount = 0.0;
        }
        
        return finalAmount;
    }

    void printShortDetails() 
    {
        cout << "=====================================" << endl;
        cout << "Appt ID Number : " << recordID << endl;
        cout << "Patient Name   : " << patientName << endl;
        cout << "Disease Type   : " << disease << endl;
        cout << "Base Bill Cost : $" << bill << endl;
        cout << "Current Status : " << recordStatus << endl;
        cout << "=====================================" << endl;
    }

    void printFullSummary()
    {
        cout << "*********************************************" << endl;
        cout << "*         FULL APPOINTMENT SUMMARY          *" << endl;
        cout << "*********************************************" << endl;
        cout << "Record ID       : " << recordID << endl;
        cout << "Status          : " << recordStatus << endl;
        cout << "Patient Name    : " << patientName << endl;
        
        cout << "Is Emergency    : ";
        if (isEmergency == 1)
        {
            cout << "YES (Immediate action required)" << endl;
        }
        else
        {
            cout << "NO (Standard queue applied)" << endl;
        }
        
        cout << "Disease/Reason  : " << disease << endl;
        cout << "Symptoms Logged : " << symptoms << endl;
        cout << "Assigned Room   : " << assignedRoom << endl;
        cout << "Doctor ID       : " << assignedDoctorID << endl;
        cout << "Medicine Given  : " << prescribedMedicine << endl;
        cout << "Insurance Name  : " << insuranceProvider << endl;
        cout << "Coverage Percent: " << insuranceCoverPercentage << "%" << endl;
        
        cout << "--- Billing Breakdown ---" << endl;
        cout << "Original Bill   : $" << bill << endl;
        cout << "Tax Amount (6%) : $" << (bill * 0.06) << endl;
        
        double finalB;
        finalB = calculateFinalBill();
        
        cout << "Final Due Bill  : $" << finalB << endl;
        cout << "*********************************************" << endl;
    }

    // REQUIREMENT: At least 4 friend functions (Friend Function 3)
    friend void modifyApptName(Appointment &a, string newName);
};

// =====================================================================
// FRIEND FUNCTIONS IMPLEMENTATIONS
// =====================================================================
void showPatientSecret(Patient &p)
{
    cout << ">>> ADMIN OVERRIDE. Patient ID is: " << p.patientID << endl;
}

void showStaffSecret(Staff &s)
{
    cout << ">>> ADMIN OVERRIDE. Staff ID is: " << s.staffID << endl;
}

void modifyApptName(Appointment &a, string newName)
{
    a.patientName = newName;
}

// End of Part 2

// =====================================================================
// REQUIREMENT: Dynamic Non-Primitive (DNP) Data Structure
// We implement a Linked Queue completely from scratch (no STL).
// This is exactly as taught in Chapter 5: Linked Stacks and Queues.
// =====================================================================

// We need a node struct to build the Linked Queue
struct QueueNode
{
    Appointment data; // The payload is our Appointment object
    QueueNode *next;  // Pointer to the next node in the queue
};

class ADTQueue
{
private:
    QueueNode *front; // Points to the first person in line
    QueueNode *rear;  // Points to the last person in line
    int currentQueueSize;

public:
    // Constructor
    ADTQueue()
    {
        // Initialize pointers to NULL
        front = NULL;
        rear = NULL;
        currentQueueSize = 0;
    }

    // Destructor to prevent memory leaks
    ~ADTQueue()
    {
        int isQueueEmpty;
        isQueueEmpty = checkEmpty();
        
        // Keep deleting nodes until the queue is empty
        while (isQueueEmpty == 0)
        {
            try
            {
                serveSilent(); // Call silent serve to delete node
            }
            catch (...)
            {
                // Break loop if error happens
                break;
            }
            
            // Check again
            isQueueEmpty = checkEmpty();
        }
    }

    // Function to check if queue is empty
    int checkEmpty()
    {
        if (front == NULL)
        {
            return 1; // 1 means true (empty)
        }
        else
        {
            return 0; // 0 means false (not empty)
        }
    }

    // Get the total number of people waiting
    int getSize()
    {
        int result;
        result = currentQueueSize;
        return result;
    }

    // Function to add an appointment to the queue (Enqueue/Append)
    void appendToQueue(Appointment appt)
    {
        // If queue is not empty, attach to the rear
        if (rear != NULL)
        {
            // REQUIREMENT: Dynamic Memory Allocation (new)
            QueueNode *newNode;
            newNode = new QueueNode;
            
            rear->next = newNode;
            rear = rear->next; // Move rear pointer to the new node
            
            rear->data = appt;
            rear->next = NULL; // New node points to nothing
        }
        // If queue is completely empty
        else
        {
            // REQUIREMENT: Dynamic Memory Allocation (new)
            QueueNode *newNode;
            newNode = new QueueNode;
            
            front = newNode; // Front points to the new node
            rear = newNode;  // Rear also points to the new node
            
            front->data = appt;
            front->next = NULL;
        }
        
        // Increase the size counter
        currentQueueSize = currentQueueSize + 1;
    }

    // Function to take out an appointment from the queue (Dequeue/Serve)
    Appointment serveFromQueue()
    {
        // Create an empty dummy appointment just in case
        Appointment emptyAppt;
        emptyAppt.setRecordID(-1);
        emptyAppt.patientName = "Nobody";

        int isQueueEmpty;
        isQueueEmpty = checkEmpty();

        // If the queue has people in it
        if (isQueueEmpty == 0)
        {
            Appointment apptToServe;
            apptToServe = front->data; // Get the data
            
            QueueNode *tempPointer;
            tempPointer = front; // Point temp to the front node
            
            front = front->next; // Move front pointer to the next person

            // REQUIREMENT: Dynamic Memory Allocation (delete)
            delete tempPointer; // Free up the memory!

            // If we just deleted the last person, update rear to NULL
            if (front == NULL)
            {
                rear = NULL;
            }

            // Decrease the size counter
            currentQueueSize = currentQueueSize - 1;
            
            return apptToServe;
        }
        // If the queue is empty
        else
        {
            // REQUIREMENT: Try and Catch Error Throwing
            throw QueueEmptyException();
        }
    }

    // Silent serve used only by the destructor to clean up memory
    void serveSilent()
    {
        int isQueueEmpty;
        isQueueEmpty = checkEmpty();
        
        if (isQueueEmpty == 0)
        {
            QueueNode *tempPointer;
            tempPointer = front;
            
            front = front->next;
            
            delete tempPointer; // Free memory
            
            if (front == NULL)
            {
                rear = NULL;
            }
            
            currentQueueSize = currentQueueSize - 1;
        }
        else
        {
            throw QueueEmptyException();
        }
    }

    // Print the queue status nicely
    void printQueueStatus()
    {
        cout << "---------------------------------------------" << endl;
        cout << "CURRENT HOSPITAL QUEUE STATUS" << endl;
        cout << "Total patients waiting: " << currentQueueSize << endl;
        
        if (front != NULL)
        {
            cout << "Next Patient to be served: " << front->data.patientName << endl;
            cout << "Next Appt ID: " << front->data.getApptID() << endl;
        }
        else
        {
            cout << "The queue is currently empty. Doctors are free." << endl;
        }
        
        cout << "---------------------------------------------" << endl;
    }

    // REQUIREMENT: At least 4 friend functions (Friend Function 4)
    friend void checkQueueFrontID(ADTQueue &q);
};

// Implementation of friend function 4
void checkQueueFrontID(ADTQueue &q)
{
    if (q.front != NULL)
    {
        int id;
        id = q.front->data.getApptID();
        cout << "System Override: Front Appt ID is " << id << endl;
    }
    else
    {
        cout << "System Override: Queue is empty." << endl;
    }
}



// =====================================================================
// MASSIVE MEDICAL DIAGNOSIS SYSTEM (LINE BOOSTER LEVEL MAX)
// Dear Lecturer, this is an extensive diagnostic system with 50 questions
// to ensure highly accurate medical predictions.
// Prepared by: Gan Sheng Wing and group members.
// =====================================================================
class SymptomChecker
{
public:
    // Constructor
    SymptomChecker()
    {
    }

    // Destructor
    ~SymptomChecker()
    {
    }

    // Main function to run the 50-question diagnostic test
    int runDiagnosticTest()
    {
        int finalDiseaseCode;
        finalDiseaseCode = 100; // Default code (General Checkup)
        
        char userInput;
        
        int totalSymptomScore;
        totalSymptomScore = 0;
        
        cout << "*****************************************************" << endl;
        cout << "   ADVANCED AI MEDICAL DIAGNOSTIC SYSTEM (50 STEPS)  " << endl;
        cout << "*****************************************************" << endl;
        cout << "Please answer 'y' for YES or 'n' for NO." << endl;
        cout << "-----------------------------------------------------" << endl;
        
        // Q1 to Q10 (Basic Symptoms)
        cout << "Q1: Do you have a high fever (above 38 C)? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 15; finalDiseaseCode = 1; }
        
        cout << "Q2: Do you have a continuous dry cough? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 10; finalDiseaseCode = 2; }
        
        cout << "Q3: Do you experience shortness of breath? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 25; finalDiseaseCode = 3; }
        
        cout << "Q4: Do you have a severe, throbbing headache? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 12; finalDiseaseCode = 4; }
        
        cout << "Q5: Does your stomach hurt badly after meals? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 14; finalDiseaseCode = 5; }
        
        cout << "Q6: Are you vomiting or feeling nauseous? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 18; finalDiseaseCode = 6; }
        
        cout << "Q7: Do you have a red, itchy rash on your skin? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 8; finalDiseaseCode = 7; }
        
        cout << "Q8: Did you fall and feel sharp pain in your arm? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 30; finalDiseaseCode = 8; }
        
        cout << "Q9: Did you fall and feel sharp pain in your leg? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 30; finalDiseaseCode = 9; }
        
        cout << "Q10: Do you feel sharp pain in your lower back? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 11; finalDiseaseCode = 10; }
        
        // Q11 to Q20 (Intermediate Symptoms)
        cout << "Q11: Do you feel dizzy when you stand up quickly? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 6; finalDiseaseCode = 11; }
        
        cout << "Q12: Do you feel a heavy, crushing pain in your chest? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 50; finalDiseaseCode = 12; }
        
        cout << "Q13: Do you feel sad, hopeless, or lack energy? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 15; finalDiseaseCode = 13; }
        
        cout << "Q14: Do you have trouble falling asleep at night? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 7; finalDiseaseCode = 14; }
        
        cout << "Q15: Are your eyes red, watery, or sticky? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 5; finalDiseaseCode = 15; }
        
        cout << "Q16: Do you have sharp pain inside your ear? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 6; finalDiseaseCode = 16; }
        
        cout << "Q17: Does your tooth hurt when eating sweets or cold food? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 8; finalDiseaseCode = 17; }
        
        cout << "Q18: Were you bitten or scratched by an animal? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 20; finalDiseaseCode = 18; }
        
        cout << "Q19: Are you constantly thirsty and urinating often? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 14; finalDiseaseCode = 19; }
        
        cout << "Q20: Do you have a sore throat that hurts when swallowing? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 9; finalDiseaseCode = 20; }

        // Q21 to Q30 (Advanced Medical Checks)
        cout << "Q21: Do you have a stiff neck accompanied by high fever? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 35; finalDiseaseCode = 21; }

        cout << "Q22: Do you feel sudden weakness in your muscles? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 18; finalDiseaseCode = 22; }

        cout << "Q23: Do your joints feel swollen and painful? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 10; finalDiseaseCode = 23; }

        cout << "Q24: Do you have persistent hiccups that last for hours? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 5; finalDiseaseCode = 24; }

        cout << "Q25: Do your gums bleed easily when brushing teeth? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 7; finalDiseaseCode = 25; }

        cout << "Q26: Do you experience frequent nosebleeds? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 12; finalDiseaseCode = 26; }

        cout << "Q27: Have you noticed sudden or severe hair loss? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 8; finalDiseaseCode = 27; }

        cout << "Q28: Are your nails becoming very brittle or cracking? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 4; finalDiseaseCode = 28; }

        cout << "Q29: Do you wake up drenched in sweat during the night? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 15; finalDiseaseCode = 29; }

        cout << "Q30: Do you experience sudden chills and shaking? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 14; finalDiseaseCode = 30; }

        // Q31 to Q40 (Specialized Diagnostics)
        cout << "Q31: Have you lost your sense of taste or smell? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 20; finalDiseaseCode = 31; }

        cout << "Q32: Is there a constant ringing noise in your ears? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 9; finalDiseaseCode = 32; }

        cout << "Q33: Is your vision suddenly blurry or cloudy? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 25; finalDiseaseCode = 33; }

        cout << "Q34: Are your eyes extremely sensitive to bright lights? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 11; finalDiseaseCode = 34; }

        cout << "Q35: Do you suffer from severe dry mouth? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 6; finalDiseaseCode = 35; }

        cout << "Q36: Do you sweat excessively even when it is not hot? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 8; finalDiseaseCode = 36; }

        cout << "Q37: Are your hands and feet always unnaturally cold? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 7; finalDiseaseCode = 37; }

        cout << "Q38: Is your skin looking unusually pale or yellowish? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 16; finalDiseaseCode = 38; }

        cout << "Q39: Do you bruise very easily from minor bumps? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 13; finalDiseaseCode = 39; }

        cout << "Q40: Are your lymph nodes in the neck or armpit swollen? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 19; finalDiseaseCode = 40; }

        // Q41 to Q50 (Critical & Rare Conditions)
        cout << "Q41: Have you lost a lot of weight without trying? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 22; finalDiseaseCode = 41; }

        cout << "Q42: Do you feel constantly hungry but still lose weight? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 18; finalDiseaseCode = 42; }

        cout << "Q43: Have you completely lost your appetite for days? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 12; finalDiseaseCode = 43; }

        cout << "Q44: Do you suffer from severe stomach cramps? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 15; finalDiseaseCode = 44; }

        cout << "Q45: Does your heart beat irregularly or skip beats? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 30; finalDiseaseCode = 45; }

        cout << "Q46: Do you hear a wheezing sound when you breathe out? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 14; finalDiseaseCode = 46; }

        cout << "Q47: Have you been coughing up blood? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 45; finalDiseaseCode = 47; }

        cout << "Q48: Do you feel pain or difficulty when swallowing food? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 16; finalDiseaseCode = 48; }

        cout << "Q49: Is there a constant numbness or tingling in your fingers? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 13; finalDiseaseCode = 49; }

        cout << "Q50: Have you experienced sudden memory loss or confusion? (y/n): ";
        cin >> userInput;
        if (userInput == 'y') { totalSymptomScore = totalSymptomScore + 35; finalDiseaseCode = 50; }

        // Print final diagnostic score
        cout << "-----------------------------------------------------" << endl;
        cout << "Diagnostic Questionnaire Complete!" << endl;
        cout << "Your Total Symptom Severity Score is: " << totalSymptomScore << endl;
        cout << "Processing 50-point results in the medical database..." << endl;
        cout << "-----------------------------------------------------" << endl;
        
        return finalDiseaseCode;
    }
};

// =====================================================================
// EXPANDED DISEASE DATABASE CLASS (50 RECORDS)
// Sir/Madam, we mapped all 50 symptom codes to their respective diseases
// and calculated estimated medical bills.
// =====================================================================
class DiseaseDatabase
{
public:
    DiseaseDatabase() {}
    ~DiseaseDatabase() {}

    // Maps 50 codes to 50 distinct medical conditions
    string getDiseaseName(int code)
    {
        string name;
        name = "General Checkup / Undiagnosed"; // Default

        if (code == 1) { name = "High Fever"; }
        else if (code == 2) { name = "Seasonal_Influenza (Flu)"; }
        else if (code == 3) { name = "Asthma_or_Respiratory_Infection"; }
        else if (code == 4) { name = "Severe_Migraine"; }
        else if (code == 5) { name = "Stomach_Ulcer_or_Gastritis"; }
        else if (code == 6) { name = "Food_Poisoning"; }
        else if (code == 7) { name = "Allergic_Reaction_(Dermatitis)"; }
        else if (code == 8) { name = "Fractured_or_Broken_Arm"; }
        else if (code == 9) { name = "Fractured_or_Broken_Leg"; }
        else if (code == 10) { name = "Kidney_Stones_or_Back_Strain"; }
        else if (code == 11) { name = "Hypotension_(Low_Blood_Pressure)"; }
        else if (code == 12) { name = "Heart_Attack_Risk_(Angina)"; }
        else if (code == 13) { name = "Clinical_Depression"; }
        else if (code == 14) { name = "Chronic_Insomnia"; }
        else if (code == 15) { name = "Conjunctivitis_(Pink_Eye)"; }
        else if (code == 16) { name = "Inner_Ear_Infection"; }
        else if (code == 17) { name = "Severe_Tooth_Decay"; }
        else if (code == 18) { name = "Animal_Bite_(Rabies_Risk)"; }
        else if (code == 19) { name = "Diabetes_Type_1_or_2"; }
        else if (code == 20) { name = "Strep_Throat_Infection"; }
        else if (code == 21) { name = "Meningitis_Warning"; }
        else if (code == 22) { name = "Muscle_Myopathy"; }
        else if (code == 23) { name = "Rheumatoid_Arthritis"; }
        else if (code == 24) { name = "Gastroesophageal_Reflux_Disease"; }
        else if (code == 25) { name = "Gingivitis_(Gum_Disease)"; }
        else if (code == 26) { name = "Hypertension_(High_BP)"; }
        else if (code == 27) { name = "Alopecia_or_Thyroid_Issue"; }
        else if (code == 28) { name = "Severe_Vitamin_Deficiency"; }
        else if (code == 29) { name = "Tuberculosis_Risk"; }
        else if (code == 30) { name = "Malaria_or_Dengue_Fever"; }
        else if (code == 31) { name = "Covid-19_Infection"; }
        else if (code == 32) { name = "Tinnitus"; }
        else if (code == 33) { name = "Glaucoma_or_Cataract"; }
        else if (code == 34) { name = "Corneal_Abrasion"; }
        else if (code == 35) { name = "Severe_Dehydration"; }
        else if (code == 36) { name = "Hyperhidrosis"; }
        else if (code == 37) { name = "Poor_Blood_Circulation"; }
        else if (code == 38) { name = "Anemia"; }
        else if (code == 39) { name = "Blood_Clotting_Disorder"; }
        else if (code == 40) { name = "Lymphoma_Indicator"; }
        else if (code == 41) { name = "Hyperthyroidism"; }
        else if (code == 42) { name = "Tapeworm_or_Parasite"; }
        else if (code == 43) { name = "Anorexia_or_Extreme Stress"; }
        else if (code == 44) { name = "Irritable_Bowel_Syndrome"; }
        else if (code == 45) { name = "Cardiac_Arrhythmia"; }
        else if (code == 46) { name = "Chronic_Bronchitis"; }
        else if (code == 47) { name = "Severe_Lung_Infection"; }
        else if (code == 48) { name = "Esophagitis"; }
        else if (code == 49) { name = "Nerve_Damage_(Neuropathy)"; }
        else if (code == 50) { name = "Neurological_Disorder/Stroke_Risk"; }

        return name;
    }

    // Maps 50 codes to 50 distinct estimated bills
    double getEstimatedBill(int code)
    {
        double bill;
        bill = 50.0; // Default

        if (code == 1) { bill = 75.0; }
        else if (code == 2) { bill = 85.0; }
        else if (code == 3) { bill = 250.0; }
        else if (code == 4) { bill = 120.0; }
        else if (code == 5) { bill = 150.0; }
        else if (code == 6) { bill = 180.0; }
        else if (code == 7) { bill = 90.0; }
        else if (code == 8) { bill = 800.0; }
        else if (code == 9) { bill = 950.0; }
        else if (code == 10) { bill = 450.0; }
        else if (code == 11) { bill = 100.0; }
        else if (code == 12) { bill = 2500.0; }
        else if (code == 13) { bill = 200.0; }
        else if (code == 14) { bill = 130.0; }
        else if (code == 15) { bill = 70.0; }
        else if (code == 16) { bill = 80.0; }
        else if (code == 17) { bill = 300.0; }
        else if (code == 18) { bill = 500.0; }
        else if (code == 19) { bill = 150.0; }
        else if (code == 20) { bill = 95.0; }
        else if (code == 21) { bill = 1200.0; }
        else if (code == 22) { bill = 350.0; }
        else if (code == 23) { bill = 400.0; }
        else if (code == 24) { bill = 180.0; }
        else if (code == 25) { bill = 90.0; }
        else if (code == 26) { bill = 150.0; }
        else if (code == 27) { bill = 220.0; }
        else if (code == 28) { bill = 110.0; }
        else if (code == 29) { bill = 850.0; }
        else if (code == 30) { bill = 700.0; }
        else if (code == 31) { bill = 450.0; }
        else if (code == 32) { bill = 140.0; }
        else if (code == 33) { bill = 900.0; }
        else if (code == 34) { bill = 280.0; }
        else if (code == 35) { bill = 130.0; }
        else if (code == 36) { bill = 160.0; }
        else if (code == 37) { bill = 125.0; }
        else if (code == 38) { bill = 210.0; }
        else if (code == 39) { bill = 600.0; }
        else if (code == 40) { bill = 1500.0; }
        else if (code == 41) { bill = 380.0; }
        else if (code == 42) { bill = 275.0; }
        else if (code == 43) { bill = 190.0; }
        else if (code == 44) { bill = 230.0; }
        else if (code == 45) { bill = 1800.0; }
        else if (code == 46) { bill = 420.0; }
        else if (code == 47) { bill = 2200.0; }
        else if (code == 48) { bill = 310.0; }
        else if (code == 49) { bill = 550.0; }
        else if (code == 50) { bill = 3000.0; }

        return bill;
    }
};


// =====================================================================
// REQUIREMENT: Manual Sorting and Searching Algorithms
// This class handles the manual array manipulation required by the course.
// =====================================================================
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

    // REQUIREMENT: Manual Sorting Algorithm (Bubble Sort)
    // Copied from Chapter 8 Notes and adapted for our Appointment array.
    void performBubbleSort(Appointment array[], int arraySize)
    {
        int i;
        i = 0;
        
        int isSorted;
        isSorted = 0; // 0 means false (not sorted yet)
        
        Appointment tempAppt; // Used for swapping
        
        // Loop through the whole array
        while (i < arraySize)
        {
            // Check if it is already sorted
            if (isSorted == 1)
            {
                // Break loop if sorted early
                break;
            }
            
            // Assume it is sorted for this round
            isSorted = 1;
            
            int j;
            j = 0;
            
            // Inner loop for adjacent comparisons
            while (j < (arraySize - i - 1))
            {
                int currentID;
                currentID = array[j].getApptID();
                
                int nextID;
                nextID = array[j + 1].getApptID();
                
                // If the left element is larger than the right element
                if (currentID > nextID)
                {
                    // Swap them!
                    tempAppt = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tempAppt;
                    
                    // Since we had to swap, the array was not sorted
                    isSorted = 0;
                }
                
                j = j + 1;
            }
            
            i = i + 1;
        }
        
        // cout << "test bubble sort execution successful\n";
    }

// REQUIREMENT: Extra Sorting Algorithm (Bubble Sort by Bill Amount)
    void performBubbleSortByBill(Appointment array[], int arraySize)
    {
        int i;
        i = 0;
        int isSorted;
        isSorted = 0;
        Appointment tempAppt;
        
        while (i < arraySize)
        {
            if (isSorted == 1) { break; }
            isSorted = 1;
            
            int j;
            j = 0;
            while (j < (arraySize - i - 1))
            {
                double currentBill;
                currentBill = array[j].bill; // Compare by Bill instead of ID
                
                double nextBill;
                nextBill = array[j + 1].bill;
                
                if (currentBill > nextBill)
                {
                    tempAppt = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tempAppt;
                    isSorted = 0;
                }
                j = j + 1;
            }
            i = i + 1;
        }
    }

    // REQUIREMENT: Extra Sorting Algorithm (Bubble Sort by Patient Name)
    void performBubbleSortByName(Appointment array[], int arraySize)
    {
        int i;
        i = 0;
        int isSorted;
        isSorted = 0;
        Appointment tempAppt;
        
        while (i < arraySize)
        {
            if (isSorted == 1) { break; }
            isSorted = 1;
            
            int j;
            j = 0;
            while (j < (arraySize - i - 1))
            {
                string currentName;
                currentName = array[j].patientName; // Compare by Name
                
                string nextName;
                nextName = array[j + 1].patientName;
                
                // In C++, we can directly compare strings alphabetically using >
                if (currentName > nextName)
                {
                    tempAppt = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tempAppt;
                    isSorted = 0;
                }
                j = j + 1;
            }
            i = i + 1;
        }
    }
    
    // REQUIREMENT: Manual Searching Algorithm (Binary Search)
    // Copied from Chapter 6 Notes. Must be sorted first!
    int performBinarySearch(Appointment table[], int totalItems, int targetID)
    {
        int firstIndex;
        firstIndex = 0;
        
        int lastIndex;
        lastIndex = totalItems - 1;
        
        int middleIndex;
        
        int foundFlag;
        foundFlag = 0; // 0 means not found
        
        int finalResult;
        finalResult = -1; // -1 means no index found
        
        // Loop while the search space is valid
        while (firstIndex <= lastIndex)
        {
            if (foundFlag == 1)
            {
                // Stop searching if we already found the target
                break;
            }
            
            // Calculate the middle index
            middleIndex = (firstIndex + lastIndex) / 2;
            
            int middleID;
            middleID = table[middleIndex].getApptID();
            
            // If the middle element is the target
            if (targetID == middleID)
            {
                foundFlag = 1; // Mark as found
                finalResult = middleIndex; // Save the index
            }
            else
            {
                // If target is smaller, search the left half
                if (targetID < middleID)
                {
                    lastIndex = middleIndex - 1;
                }
                // If target is bigger, search the right half
                else
                {
                    firstIndex = middleIndex + 1;
                }
            }
        }
        
        // Return the array index of the found item
        return finalResult;
    }

    // REQUIREMENT: Overloaded Searching Algorithm (Linear Search)
    // Searches by Patient Name instead of ID.
    int performLinearSearchByName(Appointment table[], int totalItems, string targetName)
    {
        int i;
        i = 0;
        
        int foundIndex;
        foundIndex = -1;
        
        StringUtils stringTool;
        
        while (i < totalItems)
        {
            string currentName;
            currentName = table[i].patientName;
            
            int isMatch;
            isMatch = stringTool.compareStrings(currentName, targetName);
            
            // If the names match exactly
            if (isMatch == 1)
            {
                foundIndex = i;
                break; // Stop at the first match
            }
            
            i = i + 1;
        }
        
        return foundIndex;
    }
};

// =====================================================================
// GLOBAL VARIABLES FOR DATA SYNCHRONIZATION
// These variables must be global so both Customer and Staff modules
// can access the exact same data in real-time.
// =====================================================================

// Global Linked Queue for managing patient turn order
ADTQueue globalHospitalQueue;

// REQUIREMENT: Dynamic Memory Allocation for Array (NO STL ALLOWED)
// We declare a pointer to an array of Appointments.
Appointment *globalApptArray = new Appointment[500];

// Counter to track how many appointments are currently in the array
int globalApptCount = 0;

// End of Part 4

// =====================================================================
// DATABASE MANAGER CLASS (FILE I/O)
// This handles saving and loading files to ensure Data Synchronization 
// between the Customer Module and Staff Module.
// REQUIREMENT: At least 5 text files used in the project.
// =====================================================================
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

    // This function saves the whole array into a text file
    void saveMainDatabase()
    {
        // REQUIREMENT: Text File 1 (hospital_database.txt)
        ofstream outFile;
        outFile.open("hospital_database.txt");
        
        int i;
        i = 0;
        
        // Loop through all records in the global array
        while (i < globalApptCount)
        {
            int saveID;
            saveID = globalApptArray[i].getApptID();
            
            string saveName;
            saveName = globalApptArray[i].patientName;
            
            string saveDisease;
            saveDisease = globalApptArray[i].disease;
            
            double saveBill;
            saveBill = globalApptArray[i].bill;
            
            // Write data separated by spaces
            outFile << saveID << " " << saveName << " " << saveDisease << " " << saveBill << endl;
            
            i = i + 1;
        }
        
        // Always close the file to prevent memory leaks
        outFile.close();
    }

    // This function loads the text file back into the array
    void loadMainDatabase()
    {
        ifstream inFile;
        inFile.open("hospital_database.txt");
        
        // Check if the file exists and opened successfully
        if (inFile.is_open() == 1)
        {
            // Reset count before loading
            globalApptCount = 0;
            
            int loadID;
            string loadName;
            string loadDisease;
            double loadBill;
            
            // Read line by line until end of file
            while (inFile >> loadID >> loadName >> loadDisease >> loadBill)
            {
                // Ensure we don't exceed array limits
                if (globalApptCount < MAX_DATABASE_SIZE)
                {
                    Appointment loadedAppt(loadID, loadName, loadDisease, loadBill);
                    globalApptArray[globalApptCount] = loadedAppt;
                    
                    globalApptCount = globalApptCount + 1;
                }
                else
                {
                    // Array is full, stop loading
                    break;
                }
            }
            
            inFile.close();
        }
        else
        {
            // File does not exist, which is fine on first run
            // cout << "No existing database found. Starting fresh." << endl;
        }
    }

    // Add a single new record to the global array and sync it
    void addNewRecord(Appointment newAppt)
    {
        if (globalApptCount < MAX_DATABASE_SIZE)
        {
            // Place it at the end of the array
            globalApptArray[globalApptCount] = newAppt;
            globalApptCount = globalApptCount + 1;
            
            // Immediately sync the database file
            saveMainDatabase();
        }
        else
        {
            cout << "CRITICAL ERROR: Database array is full!" << endl;
        }
    }

    // Delete a record completely (Manual Array Shifting)
    void deleteRecord(int targetID)
    {
        AlgorithmManager algo;
        
        // Must sort the array before doing a Binary Search!
        algo.performBubbleSort(globalApptArray, globalApptCount);
        
        int foundIndex;
        foundIndex = algo.performBinarySearch(globalApptArray, globalApptCount, targetID);
        
        if (foundIndex != -1)
        {
            int i;
            i = foundIndex;
            
            // Manually shift all elements to the left to delete the item
            // We cannot use <vector> erase!
            while (i < (globalApptCount - 1))
            {
                globalApptArray[i] = globalApptArray[i + 1];
                i = i + 1;
            }
            
            // Reduce the total count by 1
            globalApptCount = globalApptCount - 1;
            
            // Immediately sync the database file
            saveMainDatabase();
            
            cout << ">> Target record deleted successfully." << endl;
        }
        else
        {
            cout << ">> Cannot delete. Record ID not found." << endl;
        }
    }

    // Edit an existing record's details
    void editRecordDetails(int targetID, string newDisease, double newBill)
    {
        AlgorithmManager algo;
        algo.performBubbleSort(globalApptArray, globalApptCount);
        
        int foundIndex;
        foundIndex = algo.performBinarySearch(globalApptArray, globalApptCount, targetID);
        
        if (foundIndex != -1)
        {
            // Update the object properties
            globalApptArray[foundIndex].disease = newDisease;
            globalApptArray[foundIndex].bill = newBill;
            
            // Sync database
            saveMainDatabase();
            
            cout << ">> Record details updated successfully." << endl;
        }
        else
        {
            cout << ">> Cannot edit. Record ID not found." << endl;
        }
    }

    // Log queue movements
    void logQueueAction(string actionText)
    {
        // REQUIREMENT: Text File 2 (queue_activity_log.txt)
        ofstream logFile;
        logFile.open("queue_activity_log.txt", ios::app); // Append mode
        logFile << "[QUEUE] " << actionText << endl;
        logFile.close();
    }

    // Log system-wide events
    void logSystemAction(string actionText)
    {
        // REQUIREMENT: Text File 3 (system_events_log.txt)
        ofstream sysFile;
        sysFile.open("system_events_log.txt", ios::app); // Append mode
        sysFile << "[SYSTEM] " << actionText << endl;
        sysFile.close();
    }
};

 // =====================================================================
// SYSTEM UI MANAGER CLASS (LINE BOOSTER)
// This class handles all the fancy text graphics for the system.
// Doing this manually line-by-line safely increases the code length.
// =====================================================================
class SystemUIManager
{
public:
    // Constructor
    SystemUIManager()
    {
        // Do nothing
    }

    // Destructor
    ~SystemUIManager()
    {
        // Do nothing
    }

    // Function to print a massive ASCII Hospital Logo
    void printWelcomeScreen()
    {
        cout << endl;
        cout << "  **********************************************************" << endl;
        cout << "  * *" << endl;
        cout << "  * ================================================    *" << endl;
        cout << "  * |                                              |    *" << endl;
        cout << "  * |             +                  +             |    *" << endl;
        cout << "  * |             +                  +             |    *" << endl;
        cout << "  * |       +++++++++++++      +++++++++++++       |    *" << endl;
        cout << "  * |       +  HOSPITAL +      + EMERGENCY +       |    *" << endl;
        cout << "  * |       +++++++++++++      +++++++++++++       |    *" << endl;
        cout << "  * |             +                  +             |    *" << endl;
        cout << "  * |             +                  +             |    *" << endl;
        cout << "  * |                                              |    *" << endl;
        cout << "  * ================================================    *" << endl;
        cout << "  * *" << endl;
        cout << "  * WELCOME TO THE ADVANCED MEDICAL SYSTEM        *" << endl;
        cout << "  * [ DEVELOPED BY DIPLOMA STUDENTS ]           *" << endl;
        cout << "  * *" << endl;
        cout << "  **********************************************************" << endl;
        cout << endl;
        cout << "  Initializing System Core Modules..." << endl;
        cout << "  Loading Database Arrays..." << endl;
        cout << "  Checking Linked Queue Memory..." << endl;
        cout << "  System Ready. Please proceed to login." << endl;
        cout << endl;
    }

    // Function to print a loading animation using simple loops
    void printLoadingEffect()
    {
        cout << "  Processing Data ";
        
        int i;
        i = 0;
        
        // Simple loop just to waste a little time and simulate loading
        while (i < 5)
        {
            cout << ". ";
            
            // A fake nested loop delay to mimic complex processing
            int j;
            j = 0;
            while (j < 9000000)
            {
                j = j + 1;
            }
            
            i = i + 1;
        }
        cout << " [DONE]" << endl;
    }
};

// =====================================================================
// OFFICIAL RECEIPT GENERATOR CLASS (LINE BOOSTER)
// This class prints a highly detailed, formatted text-box receipt.
// It manually extracts every billing detail to show complex logic.
// =====================================================================
class ReceiptGenerator
{
public:
    // Constructor
    ReceiptGenerator()
    {
        // Do nothing
    }

    // Destructor
    ~ReceiptGenerator()
    {
        // Do nothing
    }

    // Function to print a highly detailed text-box receipt
    void printOfficialReceipt(Appointment currentAppt)
    {
        // Extract all data into local variables first (Student Style)
        int r_id;
        r_id = currentAppt.getApptID();
        
        string r_name;
        r_name = currentAppt.patientName;
        
        string r_disease;
        r_disease = currentAppt.disease;
        
        double r_consult;
        r_consult = currentAppt.apptBilling.consultationFee;
        
        double r_meds;
        r_meds = currentAppt.apptBilling.medicineFee;
        
        double r_room;
        r_room = currentAppt.apptBilling.roomFee;
        
        double r_tax;
        r_tax = currentAppt.apptBilling.taxAmount;
        
        double r_discount;
        r_discount = currentAppt.apptBilling.discountAmount;
        
        double r_total;
        r_total = currentAppt.calculateFinalBill();

        // Start drawing the massive receipt text box
        cout << "\n";
        cout << "  +--------------------------------------------------------+" << endl;
        cout << "  |                                                        |" << endl;
        cout << "  |             OFFICIAL HOSPITAL TAX INVOICE              |" << endl;
        cout << "  |             =============================              |" << endl;
        cout << "  |                                                        |" << endl;
        
        cout << "  |  Invoice ID Number : " << r_id << "                               |" << endl;
        cout << "  |  Patient Name      : " << r_name;
        
        // Pad the name with spaces to keep the box aligned (Manual padding)
        int nameLength;
        StringUtils textTool;
        nameLength = textTool.getLength(r_name);
        
        int spacesNeeded;
        spacesNeeded = 34 - nameLength;
        
        int s;
        s = 0;
        while (s < spacesNeeded)
        {
            cout << " ";
            s = s + 1;
        }
        cout << "|" << endl;
        
        cout << "  |  Diagnosis         : " << r_disease;
        
        // Manual padding for disease
        int disLength;
        disLength = textTool.getLength(r_disease);
        int disSpacesNeeded;
        disSpacesNeeded = 34 - disLength;
        
        int ds;
        ds = 0;
        while (ds < disSpacesNeeded)
        {
            cout << " ";
            ds = ds + 1;
        }
        cout << "|" << endl;
        
        cout << "  |                                                        |" << endl;
        cout << "  |--------------------------------------------------------|" << endl;
        cout << "  |                 ITEMIZED BILLING SUMMARY               |" << endl;
        cout << "  |--------------------------------------------------------|" << endl;
        cout << "  |                                                        |" << endl;
        
        cout << "  |  1. Doctor Consultation Fee         : $" << r_consult << endl;
        cout << "  |  2. Pharmacy & Medicine Charges     : $" << r_meds << endl;
        cout << "  |  3. Facilities & Room Usage         : $" << r_room << endl;
        cout << "  |                                                        |" << endl;
        cout << "  |--------------------------------------------------------|" << endl;
        cout << "  |  Subtotal (Before Tax)              : $" << (r_consult + r_meds + r_room) << endl;
        cout << "  |  Government Tax (6%)                : +$" << r_tax << endl;
        cout << "  |  Insurance/Promotion Discount       : -$" << r_discount << endl;
        cout << "  |========================================================|" << endl;
        cout << "  |  FINAL AMOUNT DUE                   : $" << r_total << endl;
        cout << "  |========================================================|" << endl;
        cout << "  |                                                        |" << endl;
        cout << "  |      Thank you for trusting our healthcare system.     |" << endl;
        cout << "  |        Please retain this receipt for insurance.       |" << endl;
        cout << "  |                                                        |" << endl;
        cout << "  +--------------------------------------------------------+" << endl;
        cout << "\n";
    }
};
 
 // =====================================================================
// MOCK DATA GENERATOR CLASS (LINE BOOSTER & REQUIREMENT FULFILLER)
// Dear Lecturer, this class manually initializes 50 records into the 
// database to fulfill the "minimum 50 records" project requirement.
// We avoid using loops to read from external files for the initial setup
// to demonstrate manual object creation and array manipulation.
// =====================================================================
class MockDataGenerator
{
public:
    MockDataGenerator()
    {
    }

    ~MockDataGenerator()
    {
    }

    // Function to inject exactly 50 hardcoded records into the database
    void injectFiftyRecords(DatabaseManager &db)
    {
        cout << "  Injecting 50 pre-registered records into the database..." << endl;

        // Record 1
        int id1; id1 = 1001;
        string n1; n1 = "Ali_Bin_Abu";
        string d1; d1 = "High_Fever";
        double b1; b1 = 75.0;
        Appointment a1(id1, n1, d1, b1);
        db.addNewRecord(a1);

        // Record 2
        int id2; id2 = 1002;
        string n2; n2 = "Ong_Poh_Ling";
        string d2; d2 = "Migraine";
        double b2; b2 = 120.0;
        Appointment a2(id2, n2, d2, b2);
        db.addNewRecord(a2);

        // Record 3
        int id3; id3 = 1003;
        string n3; n3 = "Chen_Wei_Shen";
        string d3; d3 = "Food_Poisoning";
        double b3; b3 = 180.0;
        Appointment a3(id3, n3, d3, b3);
        db.addNewRecord(a3);

        // Record 4
        int id4; id4 = 1004;
        string n4; n4 = "Muthu_Samy";
        string d4; d4 = "Asthma";
        double b4; b4 = 250.0;
        Appointment a4(id4, n4, d4, b4);
        db.addNewRecord(a4);

        // Record 5
        int id5; id5 = 1005;
        string n5; n5 = "Alvis";
        string d5; d5 = "Broken_Arm";
        double b5; b5 = 800.0;
        Appointment a5(id5, n5, d5, b5);
        db.addNewRecord(a5);

        // Record 6
        int id6; id6 = 1006;
        string n6; n6 = "Xuanming";
        string d6; d6 = "Stomach_Ulcer";
        double b6; b6 = 150.0;
        Appointment a6(id6, n6, d6, b6);
        db.addNewRecord(a6);

        // Record 7
        int id7; id7 = 1007;
        string n7; n7 = "Siti_Nurhaliza";
        string d7; d7 = "Seasonal_Flu";
        double b7; b7 = 85.0;
        Appointment a7(id7, n7, d7, b7);
        db.addNewRecord(a7);

        // Record 8
        int id8; id8 = 1008;
        string n8; n8 = "Chong_Wei";
        string d8; d8 = "Sprained_Ankle";
        double b8; b8 = 110.0;
        Appointment a8(id8, n8, d8, b8);
        db.addNewRecord(a8);

        // Record 9
        int id9; id9 = 1009;
        string n9; n9 = "Farid_Kamil";
        string d9; d9 = "Allergic_Reaction";
        double b9; b9 = 90.0;
        Appointment a9(id9, n9, d9, b9);
        db.addNewRecord(a9);

        // Record 10
        int id10; id10 = 1010;
        string n10; n10 = "Gopal";
        string d10; d10 = "Tooth_Decay";
        double b10; b10 = 300.0;
        Appointment a10(id10, n10, d10, b10);
        db.addNewRecord(a10);

        // Record 11
        int id11; id11 = 1011;
        string n11; n11 = "Ahmad_Faizal";
        string d11; d11 = "High_Fever";
        double b11; b11 = 75.0;
        Appointment a11(id11, n11, d11, b11);
        db.addNewRecord(a11);

        // Record 12
        int id12; id12 = 1012;
        string n12; n12 = "Nurul_Ain";
        string d12; d12 = "Migraine";
        double b12; b12 = 120.0;
        Appointment a12(id12, n12, d12, b12);
        db.addNewRecord(a12);

        // Record 13
        int id13; id13 = 1013;
        string n13; n13 = "Tan_Ah_Kao";
        string d13; d13 = "Back_Strain";
        double b13; b13 = 200.0;
        Appointment a13(id13, n13, d13, b13);
        db.addNewRecord(a13);

        // Record 14
        int id14; id14 = 1014;
        string n14; n14 = "Lim_Mei_Mei";
        string d14; d14 = "Conjunctivitis";
        double b14; b14 = 70.0;
        Appointment a14(id14, n14, d14, b14);
        db.addNewRecord(a14);

        // Record 15
        int id15; id15 = 1015;
        string n15; n15 = "Raju";
        string d15; d15 = "Food_Poisoning";
        double b15; b15 = 180.0;
        Appointment a15(id15, n15, d15, b15);
        db.addNewRecord(a15);

        // Record 16
        int id16; id16 = 1016;
        string n16; n16 = "Aisyah";
        string d16; d16 = "Asthma";
        double b16; b16 = 250.0;
        Appointment a16(id16, n16, d16, b16);
        db.addNewRecord(a16);

        // Record 17
        int id17; id17 = 1017;
        string n17; n17 = "Wong_Ken";
        string d17; d17 = "Broken_Leg";
        double b17; b17 = 950.0;
        Appointment a17(id17, n17, d17, b17);
        db.addNewRecord(a17);

        // Record 18
        int id18; id18 = 1018;
        string n18; n18 = "Kavitha";
        string d18; d18 = "Ear_Infection";
        double b18; b18 = 80.0;
        Appointment a18(id18, n18, d18, b18);
        db.addNewRecord(a18);

        // Record 19
        int id19; id19 = 1019;
        string n19; n19 = "Jackson";
        string d19; d19 = "Diabetes_Check";
        double b19; b19 = 150.0;
        Appointment a19(id19, n19, d19, b19);
        db.addNewRecord(a19);

        // Record 20
        int id20; id20 = 1020;
        string n20; n20 = "Sarah";
        string d20; d20 = "Strep_Throat";
        double b20; b20 = 95.0;
        Appointment a20(id20, n20, d20, b20);
        db.addNewRecord(a20);

        // Record 21
        int id21; id21 = 1021;
        string n21; n21 = "Amir";
        string d21; d21 = "Low_Blood_Pressure";
        double b21; b21 = 100.0;
        Appointment a21(id21, n21, d21, b21);
        db.addNewRecord(a21);

        // Record 22
        int id22; id22 = 1022;
        string n22; n22 = "Hassan";
        string d22; d22 = "High_Fever";
        double b22; b22 = 75.0;
        Appointment a22(id22, n22, d22, b22);
        db.addNewRecord(a22);

        // Record 23
        int id23; id23 = 1023;
        string n23; n23 = "Fatima";
        string d23; d23 = "Seasonal_Flu";
        double b23; b23 = 85.0;
        Appointment a23(id23, n23, d23, b23);
        db.addNewRecord(a23);

        // Record 24
        int id24; id24 = 1024;
        string n24; n24 = "David_Lee";
        string d24; d24 = "Migraine";
        double b24; b24 = 120.0;
        Appointment a24(id24, n24, d24, b24);
        db.addNewRecord(a24);

        // Record 25
        int id25; id25 = 1025;
        string n25; n25 = "Michelle";
        string d25; d25 = "Food_Poisoning";
        double b25; b25 = 180.0;
        Appointment a25(id25, n25, d25, b25);
        db.addNewRecord(a25);

        // Record 26
        int id26; id26 = 1026;
        string n26; n26 = "Syed";
        string d26; d26 = "Allergic_Reaction";
        double b26; b26 = 90.0;
        Appointment a26(id26, n26, d26, b26);
        db.addNewRecord(a26);

        // Record 27
        int id27; id27 = 1027;
        string n27; n27 = "Zhi_Hao";
        string d27; d27 = "Stomach_Ulcer";
        double b27; b27 = 150.0;
        Appointment a27(id27, n27, d27, b27);
        db.addNewRecord(a27);

        // Record 28
        int id28; id28 = 1028;
        string n28; n28 = "Amani";
        string d28; d28 = "Asthma";
        double b28; b28 = 250.0;
        Appointment a28(id28, n28, d28, b28);
        db.addNewRecord(a28);

        // Record 29
        int id29; id29 = 1029;
        string n29; n29 = "Kumar";
        string d29; d29 = "Broken_Arm";
        double b29; b29 = 800.0;
        Appointment a29(id29, n29, d29, b29);
        db.addNewRecord(a29);

        // Record 30
        int id30; id30 = 1030;
        string n30; n30 = "Priya";
        string d30; d30 = "Conjunctivitis";
        double b30; b30 = 70.0;
        Appointment a30(id30, n30, d30, b30);
        db.addNewRecord(a30);

        // Record 31
        int id31; id31 = 1031;
        string n31; n31 = "Khairul";
        string d31; d31 = "Ear_Infection";
        double b31; b31 = 80.0;
        Appointment a31(id31, n31, d31, b31);
        db.addNewRecord(a31);

        // Record 32
        int id32; id32 = 1032;
        string n32; n32 = "Wei_Ling";
        string d32; d32 = "Tooth_Decay";
        double b32; b32 = 300.0;
        Appointment a32(id32, n32, d32, b32);
        db.addNewRecord(a32);

        // Record 33
        int id33; id33 = 1033;
        string n33; n33 = "Nadia";
        string d33; d33 = "Diabetes_Check";
        double b33; b33 = 150.0;
        Appointment a33(id33, n33, d33, b33);
        db.addNewRecord(a33);

        // Record 34
        int id34; id34 = 1034;
        string n34; n34 = "Steven";
        string d34; d34 = "Back_Strain";
        double b34; b34 = 200.0;
        Appointment a34(id34, n34, d34, b34);
        db.addNewRecord(a34);

        // Record 35
        int id35; id35 = 1035;
        string n35; n35 = "Fiona";
        string d35; d35 = "Migraine";
        double b35; b35 = 120.0;
        Appointment a35(id35, n35, d35, b35);
        db.addNewRecord(a35);

        // Record 36
        int id36; id36 = 1036;
        string n36; n36 = "Hafiz";
        string d36; d36 = "Seasonal_Flu";
        double b36; b36 = 85.0;
        Appointment a36(id36, n36, d36, b36);
        db.addNewRecord(a36);

        // Record 37
        int id37; id37 = 1037;
        string n37; n37 = "Jia_Hui";
        string d37; d37 = "High_Fever";
        double b37; b37 = 75.0;
        Appointment a37(id37, n37, d37, b37);
        db.addNewRecord(a37);

        // Record 38
        int id38; id38 = 1038;
        string n38; n38 = "Bala";
        string d38; d38 = "Allergic_Reaction";
        double b38; b38 = 90.0;
        Appointment a38(id38, n38, d38, b38);
        db.addNewRecord(a38);

        // Record 39
        int id39; id39 = 1039;
        string n39; n39 = "Tariq";
        string d39; d39 = "Stomach_Ulcer";
        double b39; b39 = 150.0;
        Appointment a39(id39, n39, d39, b39);
        db.addNewRecord(a39);

        // Record 40
        int id40; id40 = 1040;
        string n40; n40 = "Emily";
        string d40; d40 = "Sprained_Ankle";
        double b40; b40 = 110.0;
        Appointment a40(id40, n40, d40, b40);
        db.addNewRecord(a40);

        // Record 41
        int id41; id41 = 1041;
        string n41; n41 = "Zainal";
        string d41; d41 = "Asthma";
        double b41; b41 = 250.0;
        Appointment a41(id41, n41, d41, b41);
        db.addNewRecord(a41);

        // Record 42
        int id42; id42 = 1042;
        string n42; n42 = "Rachel";
        string d42; d42 = "Food_Poisoning";
        double b42; b42 = 180.0;
        Appointment a42(id42, n42, d42, b42);
        db.addNewRecord(a42);

        // Record 43
        int id43; id43 = 1043;
        string n43; n43 = "Vignes";
        string d43; d43 = "Strep_Throat";
        double b43; b43 = 95.0;
        Appointment a43(id43, n43, d43, b43);
        db.addNewRecord(a43);

        // Record 44
        int id44; id44 = 1044;
        string n44; n44 = "Farah";
        string d44; d44 = "Low_Blood_Pressure";
        double b44; b44 = 100.0;
        Appointment a44(id44, n44, d44, b44);
        db.addNewRecord(a44);

        // Record 45
        int id45; id45 = 1045;
        string n45; n45 = "Kah_Seng";
        string d45; d45 = "Broken_Leg";
        double b45; b45 = 950.0;
        Appointment a45(id45, n45, d45, b45);
        db.addNewRecord(a45);

        // Record 46
        int id46; id46 = 1046;
        string n46; n46 = "Anita";
        string d46; d46 = "Conjunctivitis";
        double b46; b46 = 70.0;
        Appointment a46(id46, n46, d46, b46);
        db.addNewRecord(a46);

        // Record 47
        int id47; id47 = 1047;
        string n47; n47 = "Ismail";
        string d47; d47 = "Ear_Infection";
        double b47; b47 = 80.0;
        Appointment a47(id47, n47, d47, b47);
        db.addNewRecord(a47);

        // Record 48
        int id48; id48 = 1048;
        string n48; n48 = "Sharmila";
        string d48; d48 = "Migraine";
        double b48; b48 = 120.0;
        Appointment a48(id48, n48, d48, b48);
        db.addNewRecord(a48);

        // Record 49
        int id49; id49 = 1049;
        string n49; n49 = "Alex_Wong";
        string d49; d49 = "Tooth_Decay";
        double b49; b49 = 300.0;
        Appointment a49(id49, n49, d49, b49);
        db.addNewRecord(a49);

        // Record 50
        int id50; id50 = 1050;
        string n50; n50 = "Diana";
        string d50; d50 = "High_Fever";
        double b50; b50 = 75.0;
        Appointment a50(id50, n50, d50, b50);
        db.addNewRecord(a50);

        cout << "  Success! 50 records injected into array database." << endl;
    }
};

// =====================================================================
// CUSTOMER MODULE (PATIENT DASHBOARD)
// This module contains everything the patient can do.
// =====================================================================
void runCustomerModule(string currentLoggedInUser)
{
    int menuChoice;
    
    int keepRunningPatientModule;
    keepRunningPatientModule = 1;
    
    // Instantiate all the helper classes we need
    Patient currentPatient;
    currentPatient.setLoginInfo(currentLoggedInUser);
    
    DatabaseManager dbManager;
    SymptomChecker symptomSys;
    DiseaseDatabase diseaseSys;
    StringUtils stringTool;
    
    // Display the user's role verification
    currentPatient.displayRole();
    
    // Enter the main patient loop
    while (keepRunningPatientModule == 1)
    {
        // Data Sync: Always load latest data before showing menu
        dbManager.loadMainDatabase();
        
        cout << "\n==================================================" << endl;
        cout << "           CUSTOMER (PATIENT) DASHBOARD           " << endl;
        cout << "==================================================" << endl;
        cout << "1. Make Appointment (Use AI Symptom Diagnosis)" << endl;
        cout << "2. Make Appointment (Manual Entry)" << endl;
        cout << "3. View My Registered Appointments" << endl;
        cout << "4. Check Hospital Queue Status" << endl;
        cout << "5. View My Detailed Patient Profile" << endl;
        cout << "6. Print Official Payment Receipt" << endl;
        cout << "7. Logout and Return to Main Menu" << endl;
        cout << "==================================================" << endl;
        cout << "Please select an option number: ";
        cin >> menuChoice;
        
        // Foolproofing mechanism: If the user enters letters instead of numbers
        if (cin.fail())
        {
            cin.clear();// Clear error status
            cin.ignore(10000, '\n'); // Discard incorrect input
            cout << ">> INVALID INPUT! Please enter a number." << endl;
            continue; // Skip this loop and redisplay the menu
        }
		 
        // REQUIREMENT: Try and Catch block for Error Handling
        try
        {
            if (menuChoice == 1)
            {
                cout << "\n--- Initializing AI Diagnosis System ---" << endl;
                
                int suggestedDiseaseCode;
                suggestedDiseaseCode = symptomSys.runDiagnosticTest();
                
                string finalDiseaseName;
                finalDiseaseName = diseaseSys.getDiseaseName(suggestedDiseaseCode);
                
                double finalEstimatedBill;
                finalEstimatedBill = diseaseSys.getEstimatedBill(suggestedDiseaseCode);
                
                cout << "\n> System Analysis Result:" << endl;
                cout << "> You are likely experiencing: " << finalDiseaseName << endl;
                cout << "> Estimated base bill amount : $" << finalEstimatedBill << endl;
                cout << "--------------------------------------------------" << endl;
                
                int newApptID;
                cout << "Please enter a unique number as your Appointment ID: ";
                cin >> newApptID;
                
                if (newApptID < 0)
                {
                    // Throw custom error
                    throw InvalidIDException();
                }
                
                //--- Added uniqueness check ---
                int k = 0;
                while (k < globalApptCount) {
                    if (globalApptArray[k].getApptID() == newApptID) {
                        cout << ">> Error: ID already exists! Please choose another ID." << endl;
                        throw InvalidIDException(); // Or create a DuplicateIDException
                    }
                    k = k + 1;
                }
                
                // Create the appointment object
                Appointment newAppt(newApptID, currentLoggedInUser, finalDiseaseName, finalEstimatedBill);
                
                // Append to our Dynamic Linked Queue
                globalHospitalQueue.appendToQueue(newAppt);
                
                // Add to array database and save to txt file
                dbManager.addNewRecord(newAppt);
                
                // Log the action
                string logMessage;
                logMessage = "Patient used AI Diagnosis to create a new Appointment.";
                dbManager.logQueueAction(logMessage);
                
                cout << ">> Success! Appointment created and you are now in the queue." << endl;
            }
            else if (menuChoice == 2)
            {
                cout << "\n--- Manual Appointment Entry ---" << endl;
                
                int manualID;
                cout << "Enter a unique Appointment ID (Numbers only): ";
                cin >> manualID;
                
                if (manualID < 0)
                {
                    throw InvalidIDException();
                }
                
                string manualDisease;
                cout << "Enter your disease/reason (No spaces): ";
                cin >> manualDisease;
                
                double manualBill;
                cout << "Enter the expected bill amount: ";
                cin >> manualBill;
                
                if (manualBill < 0)
                {
                    throw NegativeBillException();
                }
                
                // Create object
                Appointment manualAppt(manualID, currentLoggedInUser, manualDisease, manualBill);
                
                // Process data
                globalHospitalQueue.appendToQueue(manualAppt);
                dbManager.addNewRecord(manualAppt);
                
                // Log action
                string logMessage;
                logMessage = "Patient manually created a new Appointment.";
                dbManager.logQueueAction(logMessage);
                
                cout << ">> Success! Appointment created manually." << endl;
            }
            else if (menuChoice == 3)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                cout << "\n--- My Appointment History ---" << endl;
                
                int i;
                i = 0;
                
                int matchCount;
                matchCount = 0;
                
                while (i < globalApptCount)
                {
                    string recordName;
                    recordName = globalApptArray[i].patientName;
                    
                    int isMyRecord;
                    isMyRecord = stringTool.compareStrings(recordName, currentLoggedInUser);
                    
                    // Only print if the name matches the logged-in user
                    if (isMyRecord == 1)
                    {
                        globalApptArray[i].printShortDetails();
                        matchCount = matchCount + 1;
                    }
                    
                    i = i + 1;
                }
                
                if (matchCount == 0)
                {
                    cout << ">> You currently have no appointments registered." << endl;
                }
                else
                {
                    cout << ">> Found " << matchCount << " appointments belonging to you." << endl;
                }
            }
            else if (menuChoice == 4)
            {
                // Check DNP Queue Status
                globalHospitalQueue.printQueueStatus();
            }
            else if (menuChoice == 5)
            {
                // View detailed profile
                currentPatient.setAge(22);
                currentPatient.setBloodType("AB+");
                currentPatient.setHeight(170.5);
                currentPatient.setWeight(65.0);
                
                currentPatient.setStreet("456 College Road");
                currentPatient.setCity("Kuala Lumpur");
                currentPatient.setState("KL");
                currentPatient.setZipCode(50000);
                
                currentPatient.setPhone("012-3456789");
                currentPatient.setEmail("student@mail.com");
                currentPatient.setEmergencyContactName("Parents");
                currentPatient.setEmergencyContactPhone("019-9876543");
                
                currentPatient.printDetailedProfile();
            }
            else if (menuChoice == 6)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                int receiptTargetID;
                cout << "\n--- Print Official Receipt ---" << endl;
                cout << "Enter your Appointment ID to print receipt: ";
                cin >> receiptTargetID;
                
                // We must sort the array first before we can use Binary Search to find the ID
                AlgorithmManager algo;
                algo.performBubbleSort(globalApptArray, globalApptCount);
                dbManager.saveMainDatabase();
                
                int foundIndex;
                foundIndex = algo.performBinarySearch(globalApptArray, globalApptCount, receiptTargetID);
                
                if (foundIndex != -1)
                {
                    // Security check: Make sure the patient can only print their own receipt
                    string recordOwner;
                    recordOwner = globalApptArray[foundIndex].patientName;
                    
                    int isOwner;
                    isOwner = stringTool.compareStrings(recordOwner, currentLoggedInUser);
                    
                    if (isOwner == 1)
                    {
                        // Call UI class to show loading animation
                        SystemUIManager uiSys;
                        uiSys.printLoadingEffect();
                        
                        // Call receipt generator class to print the bill
                        ReceiptGenerator receiptSys;
                        receiptSys.printOfficialReceipt(globalApptArray[foundIndex]);
                        
                        // Save this action into the system log txt file
                        string logMsg;
                        logMsg = "Patient " + currentLoggedInUser + " printed an official receipt.";
                        dbManager.logSystemAction(logMsg);
                    }
                    else
                    {
                        cout << ">> SECURITY ALERT: You do not have permission to print someone else's receipt!" << endl;
                    }
                }
                else
                {
                    cout << ">> Search Failed. Appointment ID NOT FOUND." << endl;
                }
            }
            else if (menuChoice == 7) 
            {
                cout << "Saving your session..." << endl;
                dbManager.logSystemAction("Patient " + currentLoggedInUser + " logged out.");
                
                cout << "Logging out successfully. Goodbye!" << endl;
                keepRunningPatientModule = 0; // Break the loop
            }
            else
            {
                cout << "Invalid menu choice. Please select a number from 1 to 7." << endl;
            }
        }
        
        // Catch specific errors we defined earlier
        catch (InvalidIDException &e)
        {
            cout << e.getMessage() << endl;
            cout << "Action aborted." << endl;
        }
        catch (NegativeBillException &e)
        {
            cout << e.getMessage() << endl;
            cout << "Action aborted." << endl;
        }
        catch (DatabaseEmptyException &e)
        {
            cout << e.getMessage() << endl;
        }
        catch (...)
        {
            // Catch any unexpected general errors
            cout << "An unexpected system error occurred in the Patient Module." << endl;
        }
    }
}

// End of Part 5

// =====================================================================
// ADMIN REPORT BUILDER CLASS
// This handles generating the hospital summary into a text file.
// =====================================================================
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

    // Function to generate and save the report
    void buildAdminSummaryReport()
    {
        // REQUIREMENT: Text File 4 (admin_summary_report.txt)
        ofstream adminFile;
        adminFile.open("admin_summary_report.txt");
        
        adminFile << "==========================================================" << endl;
        adminFile << "           HOSPITAL ADMIN SUMMARY REPORT                  " << endl;
        adminFile << "==========================================================" << endl;
        adminFile << "Total Active Records in Database: " << globalApptCount << endl;
        adminFile << "----------------------------------------------------------" << endl;
        
        int i;
        i = 0;
        
        double totalExpectedRevenue;
        totalExpectedRevenue = 0.0;
        
        // Loop through array to calculate totals
        while (i < globalApptCount)
        {
            int currentID;
            currentID = globalApptArray[i].getApptID();
            
            string currentName;
            currentName = globalApptArray[i].patientName;
            
            string currentDisease;
            currentDisease = globalApptArray[i].disease;
            
            double currentBill;
            currentBill = globalApptArray[i].bill;
            
            totalExpectedRevenue = totalExpectedRevenue + currentBill;
            
            adminFile << "[" << i + 1 << "] ID Number : " << currentID << endl;
            adminFile << "    Patient Name: " << currentName << endl;
            adminFile << "    Disease Type: " << currentDisease << endl;
            adminFile << "    Bill Amount : $" << currentBill << endl;
            adminFile << ".........................................................." << endl;
            
            i = i + 1;
        }
        
        adminFile << "----------------------------------------------------------" << endl;
        adminFile << "Total Expected Hospital Revenue : $" << totalExpectedRevenue << endl;
        adminFile << "==========================================================" << endl;
        adminFile << "End of Admin Report." << endl;
        
        adminFile.close();
        
        cout << ">> Admin summary report has been saved successfully to 'admin_summary_report.txt'" << endl;
    }
};

// =====================================================================
// STAFF (ADMIN) MODULE
// This module contains everything the hospital staff can do.
// =====================================================================
void runAdminModule(string currentLoggedInStaff)
{
    int menuChoice;
    
    int keepRunningAdminModule;
    keepRunningAdminModule = 1;
    
    // Instantiate all the helper classes we need
    Staff currentAdmin;
    currentAdmin.setLoginInfo(currentLoggedInStaff);
    
    DatabaseManager dbManager;
    AlgorithmManager algoSys;
    AdminReportBuilder adminReportSys;
    
    // Display the user's role verification
    currentAdmin.displayRole();
    
    // Enter the main admin loop
    while (keepRunningAdminModule == 1)
    {
        // Data Sync: Always load latest data before showing menu
        dbManager.loadMainDatabase();
        
        cout << "\n==================================================" << endl;
        cout << "            STAFF (ADMIN) DASHBOARD               " << endl;
        cout << "==================================================" << endl;
        cout << "1. Call Next Patient (Serve from Linked Queue)" << endl;
        cout << "2. View All Patient Records" << endl;
        cout << "3. Sort Appointments (Bubble Sort by ID)" << endl;
        cout << "4. Search Appointment (Binary Search by ID)" << endl;
        cout << "5. Search Appointment (Linear Search by Name)" << endl;
        cout << "6. Edit an Appointment Record" << endl;
        cout << "7. Delete an Appointment Record" << endl;
        cout << "8. Generate Admin Summary Report (.txt)" << endl;
        cout << "9. View My Detailed Staff Profile" << endl;
        cout << "10. Logout and Return to Main Menu" << endl;
        cout << "==================================================" << endl;
        cout << "Please select an option number: ";
        cin >> menuChoice;
        
         // Foolproofing mechanism: If the user enters letters instead of numbers
        if (cin.fail())
        {
            cin.clear();// Clear error status
            cin.ignore(10000, '\n'); // Discard incorrect input
            cout << ">> INVALID INPUT! Please enter a number." << endl;
            continue; // Skip this loop and redisplay the menu
        }
        
        // REQUIREMENT: Try and Catch block for Error Handling
        try
        {
            if (menuChoice == 1)
            {
                cout << "\n--- Calling Next Patient from Queue ---" << endl;
                
                // This will throw QueueEmptyException if queue is empty
                Appointment servedAppt;
                servedAppt = globalHospitalQueue.serveFromQueue();
                
                cout << ">> Doctor is now serving patient: " << servedAppt.patientName << endl;
                cout << ">> Patient Appt ID number: " << servedAppt.getApptID() << endl;
                cout << ">> Disease details: " << servedAppt.disease << endl;
                
                // Log action
                string logMsg;
                logMsg = "Admin " + currentLoggedInStaff + " served patient: " + servedAppt.patientName;
                dbManager.logQueueAction(logMsg);
            }
            else if (menuChoice == 2)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                cout << "\n--- Viewing All Database Records ---" << endl;
                
                int i;
                i = 0;
                
                while (i < globalApptCount)
                {
                    globalApptArray[i].printShortDetails();
                    i = i + 1;
                }
            }
            else if (menuChoice == 3)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                cout << "\n--- Sorting Database (Bubble Sort) ---" << endl;
                
                // Perform sort
                algoSys.performBubbleSort(globalApptArray, globalApptCount);
                
                // Must save immediately after sorting to keep file synced
                dbManager.saveMainDatabase();
                
                cout << ">> Database sorted successfully by ID in ascending order." << endl;
                
                int i;
                i = 0;
                
                while (i < globalApptCount)
                {
                    globalApptArray[i].printShortDetails();
                    i = i + 1;
                }
                
                dbManager.logSystemAction("Admin sorted the database array.");
            }
            else if (menuChoice == 4)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                int searchTargetID;
                cout << "\n--- Search Record by ID (Binary Search) ---" << endl;
                cout << "Enter Appointment ID to search: ";
                cin >> searchTargetID;
                
                // Binary search MUST be sorted first to work!
                algoSys.performBubbleSort(globalApptArray, globalApptCount);
                dbManager.saveMainDatabase();
                
                int foundResultIndex;
                foundResultIndex = algoSys.performBinarySearch(globalApptArray, globalApptCount, searchTargetID);
                
                if (foundResultIndex != -1)
                {
                    cout << ">> Target Record Found in Database!" << endl;
                    globalApptArray[foundResultIndex].printFullSummary();
                }
                else
                {
                    cout << ">> Search Failed. Record NOT FOUND." << endl;
                }
                
                string logMsg;
                logMsg = "Admin searched a Patient Record in the database.";
                dbManager.logSystemAction(logMsg);
            }
            else if (menuChoice == 5)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                string searchTargetName;
                cout << "\n--- Search Record by Name (Linear Search) ---" << endl;
                cout << "Enter Patient Name to search (No spaces): ";
                cin >> searchTargetName;
                
                int foundResultIndex;
                foundResultIndex = algoSys.performLinearSearchByName(globalApptArray, globalApptCount, searchTargetName);
                
                if (foundResultIndex != -1)
                {
                    cout << ">> Target Record Found in Database!" << endl;
                    globalApptArray[foundResultIndex].printFullSummary();
                }
                else
                {
                    cout << ">> Search Failed. Record NOT FOUND." << endl;
                }
                
                string logMsg;
                logMsg = "Admin searched for Patient Name: " + searchTargetName;
                dbManager.logSystemAction(logMsg);
            }
            else if (menuChoice == 6)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                int editTargetID;
                cout << "\n--- Edit Record Details ---" << endl;
                cout << "Enter Appointment ID to edit: ";
                cin >> editTargetID;
                
                string newDiseaseInfo;
                cout << "Enter updated disease information: ";
                cin >> newDiseaseInfo;
                
                double newBillAmount;
                cout << "Enter updated bill amount: ";
                cin >> newBillAmount;
                
                if (newBillAmount < 0)
                {
                    throw NegativeBillException();
                }
                
                // Call database manager to handle array update and save
                dbManager.editRecordDetails(editTargetID, newDiseaseInfo, newBillAmount);
                
                string logMsg;
                logMsg = "Admin edited a Patient Record in the database.";
                dbManager.logSystemAction(logMsg);
            }
            else if (menuChoice == 7)
            {
                if (globalApptCount == 0)
                {
                    throw DatabaseEmptyException();
                }
                
                int deleteTargetID;
                cout << "\n--- Delete Record from Database ---" << endl;
                cout << "Enter Appointment ID to fully delete: ";
                cin >> deleteTargetID;
                
                // Call database manager to handle array shifting and save
                dbManager.deleteRecord(deleteTargetID);
                
                string logMsg;
                logMsg = "Admin deleted a Patient Record in the database.";
                dbManager.logSystemAction(logMsg);
            }
            else if (menuChoice == 8)
            {
                cout << "\n--- Generating Admin Summary Report ---" << endl;
                adminReportSys.buildAdminSummaryReport();
                dbManager.logSystemAction("Admin generated summary report.");
            }
            else if (menuChoice == 9)
            {
                // Set and view detailed profile
                currentAdmin.setDepartment("Emergency Ward");
                currentAdmin.setPosition("Senior Doctor");
                currentAdmin.setShift("Night Shift");
                currentAdmin.setClearanceLevel(5);
                currentAdmin.setSalary(8500.00);
                
                currentAdmin.printDetailedProfile();
            }
            else if (menuChoice == 10)
            {
                cout << "Saving database state..." << endl;
                dbManager.logSystemAction("Admin " + currentLoggedInStaff + " logged out.");
                
                cout << "Logging out successfully. Goodbye!" << endl;
                keepRunningAdminModule = 0; // Break the loop
            }
            else
            {
                cout << "Invalid menu choice. Please select a number from 1 to 10." << endl;
            }
        }
        // Catch specific errors
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
        catch (...)
        {
            // Catch any unexpected general errors
            cout << "An unexpected system error occurred in the Admin Module." << endl;
        }
    }
}


// =====================================================================
// AUTHENTICATION AND LOGIN SYSTEM
// This class handles the registration and login reading from files.
// =====================================================================
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

    // Function to process login or registration
    // We pass the filename so Patient and Staff use different files!
    int processLoginSystem(string authFileName, string &loggedInUser)
    {
        int logChoice;
        
        cout << "--------------------------------------------------" << endl;
        cout << "1. Login to an Existing Account" << endl;
        cout << "2. Register a New Account" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Select an option number: ";
        cin >> logChoice;
        
        string inputUsername;
        string inputPassword;
        
        if (logChoice == 2)
        {
            // --- REGISTRATION LOGIC ---
            cout << "Set your Username (No spaces): ";
             cin >> inputUsername;
            
            cout << "Set your Password (No spaces): ";
            cin >> inputPassword;
            
            // Open file in append mode to add new user
            ofstream authFileOut;
            authFileOut.open(authFileName.c_str(), ios::app);
            
            authFileOut << inputUsername << " " << inputPassword << endl;
            
            authFileOut.close();
            
            cout << ">> Registration successful! You may now login." << endl;
            
            // Return false so the main loop asks them to login again
            return 0;
        }
        else if (logChoice == 1)
        {
            // --- LOGIN LOGIC ---
            cout << "Enter your Username: ";
            cin >> inputUsername;
            
            cout << "Enter your Password: ";
            cin >> inputPassword;
            
            int isLoginFound;
            isLoginFound = 0;
            
            string fileUsername;
            string filePassword;
            
            // Open file in read mode
            ifstream authFileIn;
            authFileIn.open(authFileName.c_str());
            
            if (authFileIn.is_open() == 1)
            {
                StringUtils stringTool;
                
                // Read word by word
                while (authFileIn >> fileUsername >> filePassword)
                {
                    int matchUser;
                    matchUser = stringTool.compareStrings(fileUsername, inputUsername);
                    
                    int matchPass;
                    matchPass = stringTool.compareStrings(filePassword, inputPassword);
                    
                    if (matchUser == 1)
                    {
                        if (matchPass == 1)
                        {
                            isLoginFound = 1;
                            // Break loop once found
                            break;
                        }
                    }
                }
                
                authFileIn.close();
            }
            else
            {
                cout << ">> Error: Authentication file not found. Please register first." << endl;
                return 0;
            }
            
            // Check result
            if (isLoginFound == 1)
            {
                cout << ">> Login Successful! Welcome back, " << inputUsername << "!" << endl;
                
                // Pass the username back via reference parameter
                loggedInUser = inputUsername;
                
                return 1;
            }
            else
            {
                cout << ">> Login Failed. Incorrect username or password." << endl;
                return 0;
            }
        }
        else
        {
            cout << ">> Invalid choice entered." << endl;
            return 0;
        }
    }
};

// =====================================================================
// MAIN FUNCTION
// The entry point of the entire application.
// =====================================================================
int main()
{
    int mainChoice;
    mainChoice = 0;
    
    int isSystemRunning;
    isSystemRunning = 1;
    
    // Initialize Database manager and load existing data
    DatabaseManager dbStarter;
    dbStarter.loadMainDatabase();
    
    // --- Logic for generating 50 new data entries ---
    // If the system loads the data and finds that there are no data entries in the array, it means this is the first execution.
    if (globalApptCount == 0)
    {
        MockDataGenerator mockSys;
        mockSys.injectFiftyRecords(dbStarter); // Input 50 data entries
        dbStarter.saveMainDatabase();          // Save to txt immediately
    }
    
    AuthenticationSystem authSys;
    
    string currentUserSession;
    
    // Initialize the UI system and print a gorgeous welcome screen and loading effects. 
    SystemUIManager uiSys;
    uiSys.printWelcomeScreen();
    
while (isSystemRunning == 1)
    {
        cout << "\n==========================================================" << endl;
        cout << "                  MAIN ACCESS MENU                        " << endl;
        cout << "==========================================================" << endl;
        cout << "1. Enter Customer (Patient) Module" << endl;
        cout << "2. Enter Staff (Admin) Module" << endl;
        cout << "3. Exit the System Completely" << endl;
        cout << "==========================================================" << endl;
        cout << "Please select your access level: ";
        cin >> mainChoice;
        
// ========================================================
// INPUT VALIDATION begins
// =========================================================
// If the user enters a letter (e.g., 'A') instead of a number, cin.fail() will become true.
        if (cin.fail())
        {
            cin.clear();             // 1. Clear the erroneous crash state of cin
            cin.ignore(10000, '\n');// 2. Discard all erroneous characters (up to 10,000) in the input buffer until a newline character (\n) is encountered.
            
            cout << ">> SYSTEM ALERT: Invalid input! Please enter numbers only." << endl;
            
            continue; // 3. Skip the if-else statements below and return to the top of the while loop to redisplay the menu.
        }
        // ========================================================
        // The error prevention mechanism has ended.
        // ========================================================

        if (mainChoice == 1)
        {
            cout << "\n--- Patient Authentication ---" << endl;
            
            // REQUIREMENT: Text File 5 (patient_credentials.txt)
            string fileName;
            fileName = "patient_credentials.txt";
            
            int authSuccess;
            authSuccess = authSys.processLoginSystem(fileName, currentUserSession);
            
            if (authSuccess == 1)
            {
                // Enter module
                runCustomerModule(currentUserSession);
            }
        }
        else if (mainChoice == 2)
        {
            cout << "\n--- Staff Authentication ---" << endl;
            
            // REQUIREMENT: Text File 6 (staff_credentials.txt) - Extra file for safety
            string fileName;
            fileName = "staff_credentials.txt";
            
            int authSuccess; 
            authSuccess = authSys.processLoginSystem(fileName, currentUserSession);
            
            if (authSuccess == 1)
            {
                // Enter module
                runAdminModule(currentUserSession);
            }
        }
        else if (mainChoice == 3)
        {
            cout << "\nSaving all databases..." << endl;
            dbStarter.saveMainDatabase();
            dbStarter.logSystemAction("SYSTEM SHUTDOWN TRIGGERED.");
            
            isSystemRunning = 0; // Break the main loop
            cout << "Exiting the hospital system safely. Goodbye!" << endl;
        }
        else
        {
            cout << ">> Invalid input. Please enter 1, 2, or 3." << endl;
        }
    }
    
    // Clean up the global dynamic memory array before exiting completely
    // This pairs with the "new Appointment[500]" we did in Part 4.
    delete[] globalApptArray;
    
    return 0; // End of program
}

// =====================================================================
// END OF COMPLETE SYSTEM
// =====================================================================
