//"shuvo", "123"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

//shuvo car rental
// User class
class User
{
private:
    string username;
    string password;
public:
    User(string username, string password) : username(username), password(password) {}

    bool checkCredentials(string username, string password)
    {
        return (this->username == username && this->password == password);
    }
};

// Abstract Class for Vehicle
class Vehicle
{
protected:
    int days;
    float totalPrice;
public:
    virtual void hire() = 0;
    virtual void payment() = 0;
};

// Car class derived from Vehicle
class Car: public Vehicle
{
private:
    string carType;
    char paymentMethod;
    string cardNumber;
public:
    void Recommendation();
    void hire()
    {
        ofstream write;
        write.open("RecommendationCar.txt",ios::out|ios::app);
        bool validChoice = false;
        cout <<endl << endl<< "Car Recommendation..."<< endl;
        Recommendation();
        cout << "What type of car would you like to hire?\n\n 1)Economy (4,000 Taka per day)\n 2)Standard (7,500 Taka per day)\n 3)Luxury (10,000 Taka per day)\n Choose 1-3:\n";
        cin >> carType;

        while (!validChoice)
        {
            if (carType == "1")
            {
                totalPrice = 4000.0;
                validChoice = true;
            }
            else if (carType == "2")
            {
                totalPrice = 7500.0;
                validChoice = true;
            }
            else if (carType == "3")
            {
                totalPrice = 10000.0;
                validChoice = true;
            }
            else
            {
                cout << "Invalid choice. Please enter 1)Economy, 2)Standard or 3)Luxury: ";
                cin >> carType;
            }
        }

        cout << "How many days would you like to hire the car for? ";
        cin >> days;

        totalPrice *= days;
        cout << "The total price for hiring a " << carType << " car for " << days << " days is " << totalPrice << " Taka" << endl;
    }

    void payment()
    {
        cout << "How would you like to pay? (c for credit card, a for cash): ";
        cin >> paymentMethod;

        while (paymentMethod != 'c' && paymentMethod != 'a')
        {
            cout << "Invalid choice. Please enter c for credit card or a for cash: ";
            cin >> paymentMethod;
        }

        if (paymentMethod == 'c')
        {
            cout << "Please enter your credit card number: ";
            cin >> cardNumber;

            cout << "Thank you for your payment. Your booking has been confirmed.\n";
        }
        else
        {
            cout << "Thank you for your payment. Your booking has been confirmed.\n";
        }
    }
};

// Motorbike class derived from Vehicle
class Motorbike: public Vehicle
{
private:
    char paymentMethod;
    string cardNumber;
public:
    void hire()
    {
        cout << "Motor Bike rent 2,000 Taka per day" << endl;
        cout << "How many days would you like to hire the motorbike for? ";
        cin >> days;
        totalPrice = 2000.0 * days;
        cout << "The total price for hiring a motorbike for " << days << " days is " << totalPrice << " Taka" << endl;
    }

    void payment()
    {
        cout << "How would you like to pay?\n Credit card \nor\n Cash\n(c for credit card, a for cash): ";
        cin >> paymentMethod;
        while (paymentMethod != 'c' && paymentMethod != 'a')
        {
            cout << "Invalid choice. Please enter c for credit card or a for cash: ";
            cin >> paymentMethod;
        }

        if (paymentMethod == 'c')
        {
            cout << "Please enter your credit card number: ";
            cin >> cardNumber;

            cout << "Thank you for your payment. Your booking has been confirmed.\n";
        }
        else
        {
            cout << "Thank you for your payment. Your booking has been confirmed.\n";
        }
    }
};

void vehicle_rental()
{
    string username, password;
    cout << "Welcome to the vehicle rental system!" << endl;
// Login
    while (true)
    {
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;

        User user(username, password);

        if (user.checkCredentials("shuvo", "123"))
        {
            cout << "Login successful!" << endl;
            break;
        }
        else
        {
            cout << "Invalid username or password. Please try again." << endl;
        }
    }

// Vehicle selection
    Vehicle *vehicle;
    bool validChoice = false;

    while (!validChoice)
    {
        int vehicleType;
        cout << "\nWhat type of vehicle would you like to hire?\n\n 1)Car\n 2)Motorbike\n Choose 1-2: ";
        cin >> vehicleType;

        if (vehicleType == 1)
        {
            vehicle = new Car();
            validChoice = true;
        }
        else if (vehicleType == 2)
        {
            vehicle = new Motorbike();
            validChoice = true;
        }
        else
        {
            cout << "Invalid choice. Please enter 1 for car or 2 for motorbike." << endl;

        }
    }

// Vehicle hire and payment
    vehicle->hire();
    vehicle->payment();

}

void Car:: Recommendation()
{
    string recommend;
    ifstream read;
    int i,j,k;
    i=j=k=0;
    read.open("RecommendationCar.txt");
    while(getline(read,recommend))
    {
        if("1"==recommend)
            i++;
        else if("2"==recommend)
            j++;
        else if("3"==recommend)
            k++;
    }

    if(i>=j&&j>=k)
        cout << "1)Economy,  2)Standard, 3)Luxury."<<endl<< endl;
    else if(i>=k&&k>=j)
        cout << "1)Economy, 3)Luxury,  2)Standard."<<endl<< endl;
    else if(j>i&&i>=k)
        cout << "2)Standard, 1)Economy,  3)Luxury."<<endl<< endl;
    else if(j>=k&&k>=i)
        cout << "2)Standard,  3)Luxury, 1)Economy."<<endl<< endl;

    else if(k>=j&&j>=i)
        cout << "3)Luxury, 2)Standard,  1)Economy."<<endl<< endl;
    else if(k>=i&&i>=j)
        cout << "3)Luxury,  1)Economy, 2)Standard."<<endl<< endl;
    else
        cout << "1)Economy,  2)Standard, 3)Luxury."<<endl<< endl;
}

