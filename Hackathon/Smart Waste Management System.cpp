// SMART WASTE MANAGEMENT SYSTEM FOR SMART CITIES
// Demonstrates:
// Classes & Objects
// Constructors & Destructors
// Function Overloading
// Operator Overloading
// Inheritance
// Runtime Polymorphism
// Abstract Classes
// Dynamic Memory Allocation
// Exception Handling
// File Handling

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

// ================= ABSTRACT CLASS =================

class WasteEntity
{
public:
    virtual void displayStatus() = 0;
    virtual ~WasteEntity() {}
};

// ================= SMART BIN =================

class SmartBin : public WasteEntity
{
private:
    int binID;
    string location;
    int fillLevel;

public:
    SmartBin()
    {
        binID = 0;
        location = "Unknown";
        fillLevel = 0;
    }

    SmartBin(int id, string loc, int level)
    {
        if(level < 0 || level > 100)
            throw invalid_argument("Fill level must be between 0 and 100");

        binID = id;
        location = loc;
        fillLevel = level;
    }

    int getBinID()
    {
        return binID;
    }

    string getLocation()
    {
        return location;
    }

    int getFillLevel()
    {
        return fillLevel;
    }

    void updateFillLevel(int level)
    {
        if(level < 0 || level > 100)
            throw invalid_argument("Invalid fill level");

        fillLevel = level;
    }

    bool operator>(SmartBin &other)
    {
        return fillLevel > other.fillLevel;
    }

    void displayStatus()
    {
        cout << "\nBin ID       : " << binID;
        cout << "\nLocation     : " << location;
        cout << "\nFill Level   : " << fillLevel << "%\n";
    }

    ~SmartBin()
    {
        cout << "\nBin " << binID << " deleted.";
    }
};

// ================= COMPARISON FUNCTION =================

bool compareBins(SmartBin* a, SmartBin* b)
{
    return a->getFillLevel() > b->getFillLevel();
}

// ================= VEHICLE =================

class Vehicle : public WasteEntity
{
protected:
    string vehicleNo;

public:
    Vehicle(string no)
    {
        vehicleNo = no;
    }
};

// ================= TRUCK =================

class CollectionTruck : public Vehicle
{
private:
    int capacity;

public:
    CollectionTruck(string no, int cap)
        : Vehicle(no)
    {
        capacity = cap;
    }

    void displayStatus()
    {
        cout << "\nTruck Number : " << vehicleNo;
        cout << "\nCapacity     : " << capacity << " kg\n";
    }
};

// ================= CITIZEN =================

class Citizen : public WasteEntity
{
private:
    string name;
    int rewardPoints;

public:
    Citizen(string n)
    {
        name = n;
        rewardPoints = 0;
    }

    void addReward(int points)
    {
        rewardPoints += points;
    }

    int getPoints()
    {
        return rewardPoints;
    }

    string getName()
    {
        return name;
    }

    void displayStatus()
    {
        cout << "\nCitizen Name : " << name;
        cout << "\nReward Points: " << rewardPoints << "\n";
    }
};

// ================= REWARD SYSTEM =================

class RewardSystem
{
public:

    void recyclePlastic(Citizen &c)
    {
        c.addReward(10);
    }

    void recyclePaper(Citizen &c)
    {
        c.addReward(5);
    }

    void recycleMetal(Citizen &c)
    {
        c.addReward(15);
    }
};

// ================= COMPLAINT MANAGER =================

class ComplaintManager
{
public:

    void addComplaint(string complaint)
    {
        ofstream file("complaints.txt", ios::app);

        file << complaint << endl;

        file.close();
    }

    void addComplaint(string citizen,
                      string complaint)
    {
        ofstream file("complaints.txt", ios::app);

        file << citizen
             << " : "
             << complaint
             << endl;

        file.close();
    }

    void viewComplaints()
    {
        ifstream file("complaints.txt");

        string line;

        cout << "\n===== COMPLAINTS =====\n";

        while(getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
};

// ================= ROUTE OPTIMIZER =================

class RouteOptimizer
{
public:

    static void findPriorityBins(vector<SmartBin*> bins)
    {
        sort(bins.begin(),
             bins.end(),
             compareBins);

        cout << "\n===== PRIORITY BINS =====\n";

        for(int i = 0; i < bins.size(); i++)
        {
            if(bins[i]->getFillLevel() >= 80)
            {
                cout << "Bin "
                     << bins[i]->getBinID()
                     << " -> "
                     << bins[i]->getFillLevel()
                     << "% Full\n";
            }
        }
    }
};

// ================= FILE MANAGER =================

class FileManager
{
public:

    static void saveBin(SmartBin* bin)
    {
        ofstream file("bins.txt", ios::app);

        file << bin->getBinID()
             << " "
             << bin->getLocation()
             << " "
             << bin->getFillLevel()
             << endl;

        file.close();
    }

    static void viewBinFile()
    {
        ifstream file("bins.txt");

        string line;

        cout << "\n===== BIN RECORDS =====\n";

        while(getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
};

// ================= MAIN =================

int main()
{
    vector<SmartBin*> bins;
    vector<Citizen> citizens;

    ComplaintManager complaintManager;
    RewardSystem rewardSystem;

    int choice;

    do
    {
        cout << "\n\n================================";
        cout << "\n SMART WASTE MANAGEMENT SYSTEM";
        cout << "\n================================";
        cout << "\n1. Add Smart Bin";
        cout << "\n2. View Smart Bins";
        cout << "\n3. Add Citizen";
        cout << "\n4. View Citizens";
        cout << "\n5. Raise Complaint";
        cout << "\n6. View Complaints";
        cout << "\n7. Award Recycling Points";
        cout << "\n8. Route Optimization";
        cout << "\n9. Add Collection Truck";
        cout << "\n10. View Bin Records";
        cout << "\n0. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        try
        {
            switch(choice)
            {
            case 1:
            {
                int id, level;
                string location;

                cout << "Enter Bin ID: ";
                cin >> id;

                cout << "Enter Location: ";
                cin >> location;

                cout << "Enter Fill Level (0-100): ";
                cin >> level;

                SmartBin *bin =
                    new SmartBin(id,
                                 location,
                                 level);

                bins.push_back(bin);

                FileManager::saveBin(bin);

                cout << "\nBin Added Successfully.";

                break;
            }

            case 2:
            {
                for(int i=0;i<bins.size();i++)
                {
                    bins[i]->displayStatus();
                }

                break;
            }

            case 3:
            {
                string name;

                cout << "Enter Citizen Name: ";
                cin >> name;

                citizens.push_back(Citizen(name));

                cout << "\nCitizen Added.";

                break;
            }

            case 4:
            {
                for(int i=0;i<citizens.size();i++)
                {
                    citizens[i].displayStatus();
                }

                break;
            }

            case 5:
            {
                string citizenName;
                string complaint;

                cout << "Citizen Name: ";
                cin >> citizenName;

                cin.ignore();

                cout << "Enter Complaint: ";
                getline(cin, complaint);

                complaintManager.addComplaint(
                    citizenName,
                    complaint);

                cout << "\nComplaint Registered.";

                break;
            }

            case 6:
            {
                complaintManager.viewComplaints();
                break;
            }

            case 7:
            {
                if(citizens.size() == 0)
                {
                    cout << "\nNo Citizens Found.";
                    break;
                }

                int index;

                cout << "\nCitizen Index (0 to "
                     << citizens.size()-1
                     << "): ";

                cin >> index;

                int type;

                cout << "\n1. Plastic";
                cout << "\n2. Paper";
                cout << "\n3. Metal";
                cout << "\nSelect Type: ";
                cin >> type;

                if(type == 1)
                    rewardSystem.recyclePlastic(citizens[index]);
                else if(type == 2)
                    rewardSystem.recyclePaper(citizens[index]);
                else if(type == 3)
                    rewardSystem.recycleMetal(citizens[index]);

                cout << "\nReward Added.";

                break;
            }

            case 8:
            {
                RouteOptimizer::findPriorityBins(bins);
                break;
            }

            case 9:
            {
                string number;
                int capacity;

                cout << "Enter Truck Number: ";
                cin >> number;

                cout << "Enter Capacity: ";
                cin >> capacity;

                CollectionTruck truck(number,
                                      capacity);

                truck.displayStatus();

                break;
            }

            case 10:
            {
                FileManager::viewBinFile();
                break;
            }

            case 0:
            {
                cout << "\nExiting Program...";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!";
            }
            }
        }

        catch(exception &e)
        {
            cout << "\nError: "
                 << e.what();
        }

    } while(choice != 0);

    for(int i=0;i<bins.size();i++)
    {
        delete bins[i];
    }

    return 0;
}
