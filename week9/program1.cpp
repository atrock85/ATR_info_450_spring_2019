#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vehicle {
    
private:
    int wheels;
    int passengers;
    int cargo;
    string type;
    string whatType;
    Vehicle *next;
    
public:
    Vehicle (string whatType, int wheels, int passengers, int cargo, string type);
    void insert(string whatType, int wheels, int passengers, int cargo, string type);
    void printList();
};

Vehicle::Vehicle(string whatType, int Wheels, int Passengers, int Cargo, string Type){
    whatType = whatType;
    wheels = Wheels;
    passengers = Passengers;
    cargo = Cargo;
    type = Type;
    next = NULL;
}

void Vehicle::insert(string whatType, int wheels, int passengers, int cargo, string type){
    if (next != NULL){
        next->insert(whatType, wheels, passengers, cargo, type);
    }
    else{
        next = new Vehicle(whatType, wheels, passengers, cargo, type);
    }
}

void Vehicle::printList(){
    ofstream output;
    output.open("output.txt");
    
    if (output.is_open()){
        Vehicle *temp = next;
        
        while (temp != NULL){
            cout << "Vehicle : " << temp->whatType << "\n";
            output << temp->whatType << "\n";
            
            cout << "Wheels : " << temp->wheels << "\n";
            output << temp->wheels << "\n";
            
            cout << "Passengers : " << temp->passengers << "\n";
            output << temp->passengers << "\n";
            
            if (temp->whatType == "automobile"){
                cout << "Type : " << temp->type << "\n";
                output << temp->type << "\n";
            }
            else{
                cout << "Cargo : " << temp->cargo << "\n";
                output << temp->cargo << "\n";
            }
            
            temp = temp->next;
        }
        output.close();
    }
    else{
        cout << "File did not open. Try again. " << "\n";
    }
}

int main(){
    using namespace std;
    char add[] = "yes";
    Vehicle *head = new Vehicle(" ", 0, 0, 0, " ");
    
    while ( !strcmp(add, "yes")){
        char Vehicle[100];
        cout << "Is this an automobile or a truck? Enter 'automobile' or 'truck'?: ";
        cin >> Vehicle;
        int wheels;
        cout << "How many wheels does this vehicle have?: ";
        cin >> wheels;
        int passengers;
        cout << "How many passengers can this vehicle hold?: ";
        cin >> passengers;
        if (Vehicle[0] == 't' && Vehicle[1] == 'r' && Vehicle[2] == 'u' && Vehicle[3] == 'c' && Vehicle[4] == 'k'){
            int cargo;
            cout << "How much cargo (in pounds) can this vehicle hold?: ";
            cin >> cargo;
            
            head->insert(Vehicle, wheels, passengers, cargo, " ");
        }
        else{
            char type[100];
            cout << "What type of automobile is this? Enter van, car, or wagon: ";
            cin >> type;
            head->insert(Vehicle, wheels, passengers, 0, type);
        }
        
        cout << "Would you like to enter another vehicle? yes or no: ";
        cin >> add;
    }
    
    head->printList();
}
