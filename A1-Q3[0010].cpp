#include <iostream>
using namespace std;

// 24K-0010 WAMIZA NOMAN

class Users{
    string licenseType, name;
    int contactNo, userID, age;

public:
    void setDetails(){
        cout << "Enter the user name: ";
        getline(cin, name);
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter License Type (Learner, Intermediate, Full): ";
        getline(cin, licenseType);
        cout << "Enter Contact No:(5 digits) ";
        cin >> contactNo;
        cin.ignore();
    }

    void setUpdates(){
        cin.ignore();
        cout << "Enter the user name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter License Type (Learner, Intermediate, Full): ";
        getline(cin, licenseType);
        cout << "Enter Contact No:(5 digits)";
        cin >> contactNo;
        cin.ignore();
    }

    string getLicenseType() { 
	    return licenseType;
		}
};

class Vehicles{
    string Model;
    float RentperDay;
    string Eligibility;

public:
    Vehicles(string Model, float RentperDay, string Eligibility) {
        this->Model = Model;
        this->RentperDay = RentperDay;
        this->Eligibility = Eligibility;
    }

    void display() {
        cout << "Model: " << Model
             << "  Price per day: " << RentperDay
             << "  Eligibility: " << Eligibility << endl;
    }

    string getEligibility() { 
	    return Eligibility; 
		}
};

class RentalSystem {
    Vehicles* vehicleCollection[10];
    int vehicleCount = 0;

public:
    void addVehicle(string Model, float RentperDay, string Eligibility) {
        if (vehicleCount < 10) {
            vehicleCollection[vehicleCount++] = new Vehicles(Model, RentperDay, Eligibility);
            cout << "Vehicle added successfully!"<<endl;
        } 
		else {
            cout << "Vehicle limit reached (10 vehicles max)!\n";
        }
    }
    int getVehicleCount() {
    return vehicleCount;
}

    void displayVehicles() {
        if (vehicleCount == 0) {
            cout << "No vehicles available."<<endl;
            return;
        }
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicleCollection[i] != nullptr) {
                cout << i << ". ";
                vehicleCollection[i]->display();
            }
        }
    }

    void rentVehicle(Users user) {
        if (vehicleCount == 0) {
            cout << "No vehicles available for rent."<<endl;
            return;
        }

        cout << "Available vehicles:"<<endl;
        displayVehicles();

        int choice;
        cout << "Enter the number of the vehicle you want to rent: "<<endl;
        cin >> choice;

        if (choice < 0 || choice >= vehicleCount || vehicleCollection[choice] == nullptr) {
            cout << "Invalid choice."<<endl;
            return;
        }

        Vehicles* selectedVehicle = vehicleCollection[choice];

        if (user.getLicenseType() == selectedVehicle->getEligibility()) {
            cout << "You have successfully rented: "<<endl;
            selectedVehicle->display();
        } 
		else {
            cout << "You are not eligible to rent this vehicle."<<endl;
        }
    }

    void deleteVehicle(int index) {
        if (index >= 0 && index < vehicleCount && vehicleCollection[index] != nullptr) {
            delete vehicleCollection[index];
            vehicleCollection[index] = nullptr;
            cout << "Vehicle deleted successfully!"<<endl;
        } 
		else {
            cout << "Invalid index!"<<endl;
        }
    }

    ~RentalSystem() {
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicleCollection[i];
        }
    }
};

int main() {
    cout << "WAMIZA NOMAN 24K-0010" << endl;
    int option;
    RentalSystem myRentalSystem;
    Users* user1 = new Users();
    user1->setDetails();

    myRentalSystem.addVehicle("Honda Civic", 60, "Full");
    myRentalSystem.addVehicle("Toyota Corolla", 50, "Intermediate");
    myRentalSystem.addVehicle("Suzuki Alto", 30, "Learner");
    myRentalSystem.addVehicle("Lamborghini Espada", 50, "Full");
    myRentalSystem.addVehicle("Kia Sportage", 60, "Intermediate");
    myRentalSystem.addVehicle("BMW", 80, "Full");
    myRentalSystem.addVehicle("Honda City", 40, "Learner");
    myRentalSystem.addVehicle("Volkswagon", 60, "Intermediate");
    myRentalSystem.addVehicle("Suzuki palto", 40, "Learner");
    while (true) {
        cout << "\nChoose from this menu:"<<endl<< "1. Update user details"<<endl<< "2. Display vehicles"<<endl<< "3. Delete a vehicle"<<endl<< "4. Rent a vehicle"<<endl<< "5. Exit"<<endl<< "6. Add a new vehicle"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> option;

        switch (option) {
            case 1:
                user1->setUpdates();
                break;

            case 2:
                myRentalSystem.displayVehicles();
                break;

            case 3: {
                int index;
                cout << "Enter vehicle index to delete (0-" << myRentalSystem.getVehicleCount() - 1 << "): ";
                cin >> index;
                myRentalSystem.deleteVehicle(index);
                break;
            }

            case 4:
                myRentalSystem.rentVehicle(*user1);
                break;

            case 5:
                cout << "Exiting program..."<<endl;
                delete user1;
                return 0;

            case 6: {
                string model, eligibility;
                float rent;
                cin.ignore();
                cout << "Enter vehicle model: "<<endl;
                getline(cin, model);
                cout << "Enter rent per day: "<<endl;
                cin >> rent;
                cin.ignore();
                cout << "Enter eligibility (Learner, Intermediate, Full): "<<endl;
                getline(cin, eligibility);
                myRentalSystem.addVehicle(model, rent, eligibility);
                break;
            }

            default:
                cout << "Invalid choice, please try again."<<endl;
        }
    }
    return 0;
}
