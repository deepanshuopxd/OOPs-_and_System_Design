#include <iostream>
using namespace std;

// ================= BASE CLASS =================
class Employee {
protected:
    string name;
    int *employeeId;

public:
    Employee(string name, int id) {
        cout << "Employee Constructor\n";
        this->name = name;
        employeeId = new int(id);
    }

    virtual ~Employee() {
        cout << "Employee Destructor for " << name << endl;
        delete employeeId;
    }

    void display() {
        cout << "Name: " << name << ", ID: " << *employeeId << endl;
    }
};

// ================= HIERARCHICAL =================
class SalesManager : public Employee {
public:
    SalesManager(string name, int id) : Employee(name, id) {
        cout << "SalesManager Constructor\n";
    }

    ~SalesManager() {
        cout << "SalesManager Destructor\n";
    }

    void boostSales() {
        cout << name << " boosting sales\n";
    }
};

class MarketingManager : public Employee {
public:
    MarketingManager(string name, int id) : Employee(name, id) {
        cout << "MarketingManager Constructor\n";
    }

    ~MarketingManager() {
        cout << "MarketingManager Destructor\n";
    }

    void createMarketingStrategy() {
        cout << name << " creating marketing strategy\n";
    }
};

// ================= MULTIPLE (Sales + Marketing) =================
class BusinessDevelopmentManager : public SalesManager, public MarketingManager {
public:
    BusinessDevelopmentManager(string name, int id)
        : SalesManager(name, id), MarketingManager(name, id) {
        cout << "BusinessDevelopmentManager Constructor\n";
    }

    ~BusinessDevelopmentManager() {
        cout << "BusinessDevelopmentManager Destructor\n";
    }

    void coordinateBusinessDev() {
        cout << "Coordinating business development\n";
    }
};

// ================= MULTILEVEL =================
class Executive : public Employee {
public:
    Executive(string name, int id) : Employee(name, id) {
        cout << "Executive Constructor\n";
    }

    ~Executive() {
        cout << "Executive Destructor\n";
    }

    void makeDecision() {
        cout << name << " making decision\n";
    }
};

class CEO : public Executive {
public:
    CEO(string name, int id) : Executive(name, id) {
        cout << "CEO Constructor\n";
    }

    ~CEO() {
        cout << "CEO Destructor\n";
    }

    void leadCompany() {
        cout << name << " leading company\n";
    }
};

// ================= DEVELOPER =================
class Developer : public Employee {
    string *language;

public:
    Developer(string name, int id, string lang)
        : Employee(name, id) {
        cout << "Developer Constructor\n";
        language = new string(lang);
    }

    ~Developer() {
        cout << "Developer Destructor\n";
        delete language;
    }

    void show() {
        cout << name << " codes in " << *language << endl;
    }
};

// ================= HR =================
class HRManager : public Employee {
public:
    HRManager(string name, int id) : Employee(name, id) {
        cout << "HRManager Constructor\n";
    }

    ~HRManager() {
        cout << "HRManager Destructor\n";
    }

    void handleHRDuties() {
        cout << name << " handling HR duties\n";
    }
};

class HRDirector : public HRManager {
public:
    HRDirector(string name, int id) : HRManager(name, id) {
        cout << "HRDirector Constructor\n";
    }

    ~HRDirector() {
        cout << "HRDirector Destructor\n";
    }

    void manageHRDept() {
        cout << name << " managing HR department\n";
    }
};

// ================= MULTIPLE INHERITANCE (RIGHT SIDE) =================
class ProjectManager {
protected:
    string *projectManaged;

public:
    ProjectManager(string p) {
        cout << "ProjectManager Constructor\n";
        projectManaged = new string(p);
    }

    ~ProjectManager() {
        cout << "ProjectManager Destructor\n";
        delete projectManaged;
    }

    void manageProject() {
        cout << "Managing project: " << *projectManaged << endl;
    }
};

class TeamLead {
protected:
    int *teamSize;

public:
    TeamLead(int size) {
        cout << "TeamLead Constructor\n";
        teamSize = new int(size);
    }

    ~TeamLead() {
        cout << "TeamLead Destructor\n";
        delete teamSize;
    }

    void leadTeam() {
        cout << "Leading team of size " << *teamSize << endl;
    }
};

// 🔥 MAIN IMPORTANT CLASS (3 INHERITANCE)
class TechLead : public Employee, public ProjectManager, public TeamLead {
public:
    TechLead(string name, int id, string project, int size)
        : Employee(name, id),
          ProjectManager(project),
          TeamLead(size) {
        cout << "TechLead Constructor\n";
    }

    ~TechLead() {
        cout << "TechLead Destructor\n";
    }

    void displayInfo() {
        cout << name << " is Tech Lead\n";
    }
};

// ================= MAIN =================
int main() {

    cout << "\n--- BusinessDevelopmentManager ---\n";
    BusinessDevelopmentManager bdm("Deepanshu", 101);
    bdm.coordinateBusinessDev();

    cout << "\n--- CEO ---\n";
    CEO ceo("Boss", 1);
    ceo.leadCompany();

    cout << "\n--- Developer ---\n";
    Developer dev("Coder", 200, "C++");
    dev.show();

    cout << "\n--- HRDirector ---\n";
    HRDirector hr("HR Head", 300);
    hr.manageHRDept();

    cout << "\n--- TechLead (Multiple 3 Parents) ---\n";
    TechLead t("TechGuy", 500, "AI System", 5);
    t.displayInfo();
    t.manageProject();
    t.leadTeam();

    cout << "\n--- Dynamic Allocation ---\n";
    Employee *e = new Employee("DynamicEmp", 999);
    e->display();
    delete e;

    cout << "\n--- End ---\n";
}