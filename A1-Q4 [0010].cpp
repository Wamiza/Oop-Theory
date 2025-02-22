#include<iostream>
#include<string>
using namespace std;

// 24k-0010 WAMIZA NOMAN

class TransportationCard {
private:
    int cardID;
    bool isActive;
public:
    TransportationCard(int id) : cardID(id), isActive(false) {}
    void activateCard() { isActive = true; }
    void deactivateCard() { isActive = false; }
    bool checkCardStatus() const { 
	return isActive;
	 }
};

class Student{
private:
    string name;
    int studentID;
    bool hasPaidFees;
    string assignedStop;
    TransportationCard* card;
    static int totalStudents;

public:
    Student() : name(""), studentID(0), hasPaidFees(false), assignedStop(""), card(nullptr) {}

    void registerStudent(string n, int id, string stop){
        name = n;
        studentID = id;
        assignedStop = stop;
        card = new TransportationCard(id);
        totalStudents++;
    }

    void payFees(){
        hasPaidFees = true;
        card->activateCard();
        cout << name << " has paid fees. Transportation card activated." << endl ;
    }

    void tapCard(){
        if (card->checkCardStatus())
            cout << name << " attendance recorded." << endl;
        else
            cout << "Card inactive. Pay fees to activate." << endl;
    }

    void displayStudent() const {
        cout << "Student ID: " << studentID << endl << "Name: " << name << endl << "Assigned Stop: " << assignedStop<< endl ;
        cout << "Fees Paid: " << (hasPaidFees ? "Yes" : "No") <<endl;
    }

    static int getTotalStudents(){ 
	return totalStudents;
	 }
    ~Student(){ 
	delete card;
	 }
};

int Student::totalStudents = 0;

class BusRoute{
private:
    int routeID;
    string routeName;
    string* stops;
    int stopCount;
public:
    BusRoute() : routeID(0), routeName(""), stops(nullptr), stopCount(0) {}
    
    void setRoute(int id, string name, string stopList[], int count) {
        routeID = id;
        routeName = name;
        stopCount = count;
        stops = new string[count];
        for(int i = 0; i < count; i++) {
            stops[i] = stopList[i];
        }
    }
    
    void displayRoute() const {
        cout << "Route ID: " << routeID <<endl << "Name: " << routeName << endl << "Stops: ";
        for (int i = 0; i < stopCount; i++) cout << stops[i] << " ";
        cout << endl;
    }
    
    ~BusRoute() { 
	delete[] stops; 
	}
};

class TransportSystem{
private:
    Student* students;
    BusRoute* routes;
    int studentCount, routeCount;
    int maxStudents, maxRoutes;

public:
    TransportSystem(int studentLimit, int routeLimit) : studentCount(0), routeCount(0), maxStudents(studentLimit), maxRoutes(routeLimit) {
        students = new Student[maxStudents];
        routes = new BusRoute[maxRoutes];
    }

    void registerStudent(string name, int id, string stop){
        if (studentCount < maxStudents) {
            students[studentCount].registerStudent(name, id, stop);
            studentCount++;
        } 
		else {
            cout << "Student limit reached!"<<endl;
        }
    }

    void addRoute(int id, string name, string stops[], int stopCount){
        if (routeCount < maxRoutes) {
            routes[routeCount].setRoute(id, name, stops, stopCount);
            routeCount++;
        } 
		else {
            cout << "Route limit reached!"<<endl;
        }
    }

    void displayStudents() const {
        cout << "Registered Students:"<<endl;
        for (int i = 0; i < studentCount; i++) students[i].displayStudent();
    }

    void displayRoutes() const {
        cout << "Available Bus Routes:"<<endl;
        for (int i = 0; i < routeCount; i++) routes[i].displayRoute();
    }

    ~TransportSystem(){
        delete[] students;
        delete[] routes;
    }
};

int main(){
    TransportSystem system(10, 10);
    
    cout<<"WAMIZA NOMAN 24K-0010\n"<<endl;
    
    system.registerStudent("Sarim", 53, "Stop A");
    system.registerStudent("Sara", 132, "Stop B");
    
    string stops1[] = {"Stop A", "Stop B", "Stop C"};
    string stops2[] = {"Stop D", "Stop E", "Stop F"};
    
    system.addRoute(1, "Route 1", stops1, 3);
    system.addRoute(2, "Route 2", stops2, 3);
    
    system.displayStudents();
    system.displayRoutes();
    
    return 0;
}
