#include <iostream>
#include <string>
#include <vector>
#include<math.h>
#include <fstream>
using namespace std; 

class File;
class Display{
public: 
virtual void show()=0;
};

class Allcars : public Display {
public:
    string make;
    string model;
    int year;
    string colour;
    double price;
    Allcars(){}

    Allcars(string make, string model, int year,string colour,double price) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->colour=colour;
        set_price(price); // because price may fluctuate or increase due to market value
    }
    ~Allcars(){}

    void display() {
    	// to count car number
    	static int count=0;
        cout<<"Car number "<<count << " \nMake: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "colour " << colour << endl;
        
        cout << "Price: Rs." << price << endl;
         count++;
    }

    void show() {
    	static int count2;
        cout << " Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "colour " << colour << endl;
        cout << "Price: Rs." << price << endl;
    }
void set_price(double pRice){
        this->price=pRice;
    }
   inline float get_price(){ return price;}
   inline string get_make  (){ return make;}
   inline string get_model(){ return model;}
   inline int get_year(){ return year;}
   inline string get_color(){ return colour;}

};

class CarInventory : public Allcars{
private:
    vector<Allcars> foreachcar;

public:
    CarInventory(){}
    void addCar(Allcars car) {
        foreachcar.push_back(car);//to add a new element to the end of the array of vector
    }
~CarInventory(){}

    void displayCars() {
    /*for (variable_type variable_name : array_name) {
    // Code to be executed for each element of the array
}*/
        for (Allcars car : foreachcar) {
            car.display();
            cout << endl;
        }
    }

    vector<Allcars> searchByPrice(double minPrice,double maxPrice) {
        vector<Allcars> matchingCars;
        for (const Allcars car : foreachcar) {
            if (car.price >= minPrice && car.price <= maxPrice) {
                matchingCars.push_back(car);//send to matching cars array
            }
        }
        return matchingCars;
    }

    vector<Allcars> searchByBudget(double budget) {
        vector<Allcars> matchingCars;
        for (const Allcars car : foreachcar) {
            if (car.price <= budget) {
                matchingCars.push_back(car);
                budget -= car.price;
            }
        }
        return matchingCars;
    }
    
      CarInventory(string make, string model,int  year, string colour,double price) : Allcars(make,model,year,colour,price){}
      
    void addCarByAdmin() {

    string Make, Model,Colour;
        int Year;
        double Price;
        cout << "Enter the car's make: ";
        fflush(stdin);fflush(stdin);cin >> Make;
        cout << "Enter the car's model: ";
        fflush(stdin);cin >> Model;
        cout << "Enter the car's year: ";
        fflush(stdin);cin >> Year;
        cout << "Enter the car's colour: ";
        fflush(stdin);cin >> Colour;
        cout << "Enter the car's price: ";
        fflush(stdin);cin >> Price; 
  
  CarInventory car(Make, Model, Year, Colour,Price);
        addCar(car);

        cout << "Allcars added successfully!" << endl;
    }
    
};

class User {
public:
    string name;
    double budget;
    double opload;
User(){}
   User(string name, double budget) {
        this->name = name;
        this->budget = budget;
    }
~User() {}  
    	
	 friend class Admin;
	 User operator +(double finalPrice)// operator overloading
	 {
	 	
	User u;
	u.opload=this->budget - finalPrice;
	return u;
	 	
	 }
};


class File{
    public:
    fstream out;
    ifstream in;
    Allcars m;
    string ww;
    void display_Orders(User& t){
        Allcars m;

out.open("data_of_orders.txt",ios::app);
out << t.name << ": Rs." << t.budget << endl;
out.close();
}
void invoice(int totalPrice,int totaltax,int finalprice,double budget,string name){
out.open("invoice.txt");
out<<"==========================================================================================================\n";
out<<"  Seller Name "<<": MRU Company"<<endl;
out<<"  Customer Name :"<<name <<endl;
out<< "\tTAX= ("<<totaltax<<")"<<endl;
	 
		  out << "Market price= Rs " << finalprice<<endl;
	 	 
	out << "Remaining budget= Rs " << budget - finalprice << endl<<"\t\tThanks for shopping!!!"<<endl;
		
	out<<"==========================================================================================================\n";
out<<"\n\n\n\n\n\n\n";
}

};

class Admin {
private:
   const string password = "me";

public:
	Admin(){}
    bool authenticate(string inputPassword) {
        return inputPassword == password;
    }

    
    void display_Orders(User& t){
    	  cout << "Orders: " << endl;
    
            cout << t.name << ": Rs." << t.budget << endl;
            File file;
            file.display_Orders(t);

	}

    void addCarToInventory(CarInventory& inventory) {
        inventory.addCarByAdmin();
    }
};



int main() {
	float totaltax;
 CarInventory inventory;
//SAMPLE CARS
    inventory.addCar(Allcars("Toyota", "Corolla", 2015,"white", 12000));
    inventory.addCar(Allcars("Honda", "Civic", 2019,"red", 22000));
    inventory.addCar(Allcars("Tesla", "Model S", 2021,"silver", 80000));
    
loginpage: //goto
    string userType;
    jum2:
    
  Admin *admin=new Admin[5]; //dynamic initialization 

jum333:
cout << "Are you an admin or user? ";
    fflush(stdin);cin >> userType;
    if (userType == "admin") {
        string password;
     
        cout << "Enter password: ";
        fflush(stdin);cin >> password;

        if (admin->authenticate(password)) {
            cout << "Authentication successful!" << endl;
           fflush(stdin);
        
            string addCarOption;
            cout << "Would you like to add more car to the inventiory(yes/no)or display  list and logout(write display)"<<endl;
            jump:
			cin>>addCarOption;
            if (addCarOption == "yes") {
admin->addCarToInventory(inventory);
string addCarOption2;

 cout << "Would you like to add more car to the inventiory(yes/no)or display  list and logout(write display)"<<endl;
      cin>>addCarOption2;
	    if (addCarOption2 == "yes") {
		    goto jump;}//to add more cars
		     
else if (addCarOption2 == "no")
 {goto jum2;//to go to end
}
else if (addCarOption2 == "display") {
                // call displayOrders function for admin
inventory.displayCars();
            }
}
else if (addCarOption == "display") {
                // call displayOrders function for admin
inventory.displayCars();
            }
            
} else {
cout << "Authentication failed. Goodbye!" << endl;
}
int login_choice;
cout <<"thank you....successfully logout"<<endl<<endl;
cout <<"would you like go again to login page or exit 1/0"<<endl;
cin>>login_choice;
if (login_choice==1){
	goto jum333;
}
else{
	return 0;
} 

}  if (userType == "user") {
string name;
double budget;
    cout << "Enter your name: ";
    fflush(stdin);cin >> name;
    cout << "Enter your budget: ";
    fflush(stdin);cin >> budget;

    User user(name, budget);
    admin->display_Orders(user);

    cout << endl << "\t\t***CAR LIST*** " << endl;
    inventory.displayCars();
// trying
vector<Allcars>matchingCars;
int choice2;
    cout << "Search cars by:\n";
    cout << "1. Price range\n";
    cout << "2. Budget\n";
    cout << "Enter choice: ";
    cin >> choice2;

    // Search for cars based on user choice
    
    switch (choice2) {
        case 1: {
           double maxPrice,minPrice;
           cout << "Enter minimum price: ";
            cin >> minPrice;
    cout << "Enter the maximum price you are willing to pay: ";
   fflush(stdin);cin >> maxPrice;
 
             matchingCars = inventory.searchByPrice(minPrice,maxPrice);
            goto check;
        }
        case 2: {
            
            
            
              matchingCars = inventory.searchByBudget( budget);
            goto check;//to display matching cars

        }
        default:
            cout << "Invalid choice!\n";
            return 1;
    }

check:
    if (matchingCars.size() == 0) {
        cout << "No cars match your price range. Goodbye!" << endl;
        return 0;
    }

    cout << endl << "Matching cars: " << endl;
    for (Allcars car : matchingCars) {
        car.show();
        cout << endl;
    }

    double totalPrice = 0;
    vector<Allcars> selectedCars;
law://for going toward end if 2nd car is out of budget
	if (totalPrice > user.budget) {
		  cout << endl << "Matching cars: " << endl;
    for (Allcars car : matchingCars) {
        car.show();
        cout << endl; 
    }
		
		
		cout <<"not in your budget"<<endl;
       cout << "Total price: Rs." << totalPrice << endl;
   
	cout << "Remaining budget: " <<  user.	budget- totalPrice<< endl<<"\t\tThanks for shopping!!!";
    
    return 0;
	}
    else{
	
    while (totalPrice <= user.budget) {
    	
        string addAnotherCar;
        
       

        int carIndex;
        cout << "Enter the car number(given in car list) you would like to add: ";
        fflush(stdin);cin >> carIndex;

        Allcars selectedCar = matchingCars[carIndex];
        selectedCars.push_back(selectedCar);
        totalPrice += selectedCar.price;
         cout << "Would you like to add another car? ";
        fflush(stdin);cin >> addAnotherCar;

        if (addAnotherCar == "no") {
            
    for (Allcars car : selectedCars) {
        car.show();
        cout << endl;goto label;//going toward billing
        }
        
    }
    else if(addAnotherCar == "yes")
    {
    	goto law ;//for adding more cars to bill
	}

    else if (selectedCars.size() == 0) {
        cout << "No cars selected. Goodbye!" << endl;
        return 0;
    }

    cout << endl << "Selected cars: " << endl;
    for (Allcars car : selectedCars) {
        car.show();
        cout << endl;
    }
label:
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"==========================================================================================================\n";
 cout << "New Owner = " << name << endl;
   	
    cout << "Price without tax = Rs." << totalPrice << endl;
   int tax;
	 int finalprice;
	double ff=0;
    if (totalPrice>=20000)
    {
	
	  float tax=0.2;
	 int finalprice;
	 finalprice=totalPrice+(totalPrice*tax);
	 int totaltax=tax*totalPrice;
	 ff=ff+finalprice;
	 
	 	 cout<< "\tTAX= ("<<totaltax<<")"<<endl;
	} else if (totalPrice<20000)
	 {
	 	float tax=0.4;
	 	 totaltax=tax*totalPrice;
	 	
 finalprice=totalPrice+totaltax;
	 	 	 ff=ff+finalprice;
	 	cout<< "\tTAX= ("<<totaltax<<")"<<endl;
	 }
		  cout << "Market price= Rs " << ff<<endl;
	 	  User u3;
    u3=user+(ff);
	cout << "Remaining budget= Rs " << u3.opload<< endl<<"\t\tThanks for shopping!!!"<<endl;
		
	cout<<"==========================================================================================================\n";
cout<<"\n\n\n\n\n\n\n";

string last;
cout<<"would you want to go to login page enter yes to proceed and no to print  invoice and exit"<<endl;
    cin>>last;
     if(last== "yes")
    {
    	goto loginpage ;//for adding more cars to bill
	}

    else if (last== "no")
    
	
    {
	File a;
    a.invoice(totalPrice,totaltax,finalprice,budget,name ) ;
    cout <<"thank you .........."<<endl;
    return 0;}
}}} else {
cout << "Invalid user type. Goodbye!" << endl;
}

return 0;
}