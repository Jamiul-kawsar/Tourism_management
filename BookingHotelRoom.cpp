#include <bits/stdc++.h>
using namespace std;
//jamiul Hotel Management
class BookHotel
{
protected:
    int i,j,k,l;
    int days;
    double total_price,price;
private:
    string checkin,checkout,guest,payment;
    int card_number;
public:
    void Recommendation();
    int hotel_type;
    bool ValidChoice=false;
    void CheckIn();
    void CheckOut();
    void NumberOfGuest();
    void Days();
    void Book();
    void Payment();
    void Features();
    void RoomTypes();
};

class BengalBlueberry: public BookHotel
{
protected:

private:

public:
    BengalBlueberry();
    void Features();
    void RoomTypes();
};

class HotelSarinaDhaka: public BookHotel
{
protected:

private:

public:
    HotelSarinaDhaka();
    void Features();
    void RoomTypes();
};
class WhitePalaceHotel: public BookHotel
{
protected:

private:

public:
    WhitePalaceHotel();
    void Features();
    void RoomTypes();
};

class HotelOmniResidency: public BookHotel
{
protected:

private:

public:
    HotelOmniResidency();
    void Features();
    void RoomTypes();
};

void hotel_booking()
{
    ofstream write;
    write.open("Hotel_type.txt",ios::out|ios::app);
    BookHotel book_hotel;
    while (!book_hotel.ValidChoice)
    {
        cout << "Hotel Recommendation..."<< endl;
        book_hotel.Recommendation();
        cout << "1) Bengal Blueberry\nLocation: 90 Road House 1/A, Dhaka City 1212 Bangladesh"<< endl<< endl;
        cout << "2) Hotel Sarina Dhaka\nLocation: 17 Plot #27 Road Banani C/A, Dhaka City 1213 Bangladesh"<< endl<< endl;
        cout << "3) White Palace Hotel\nLocation: House 25, Road 06 Sector 09, Dhaka City 1230 Bangladesh"<<endl<< endl;
        cout << "4) Hotel Omni Residency\nLocation: House 42, Road 15, Block D, Dhaka City 1213 Bangladesh"<< endl<< endl;
        cout << "Which hotel you would like to book? ";
        cin>>book_hotel.hotel_type;
        write<< book_hotel.hotel_type<< endl;
        if(book_hotel.hotel_type==1)
        {
            BengalBlueberry b;
            b.Features();
            b.RoomTypes();
            b.CheckIn();
            b.CheckOut();
            b.NumberOfGuest();
            b.Book();
            b.Payment();
            book_hotel.ValidChoice=true;
        }
        else if(book_hotel. hotel_type==2)
        {
            HotelSarinaDhaka s;
            s.Features();
            s.RoomTypes();
            s.CheckIn();
            s.CheckOut();
            s.NumberOfGuest();
            s.Book();
            s.Payment();
            book_hotel.ValidChoice=true;
        }
        else if(book_hotel. hotel_type==3)
        {
            WhitePalaceHotel p;
            p.Features();
            p.RoomTypes();
            p.CheckIn();
            p.CheckOut();
            p.NumberOfGuest();
            p.Book();
            p.Payment();
            book_hotel.ValidChoice=true;
        }
        else if(book_hotel. hotel_type==4)
        {
            HotelOmniResidency o;
            o.Features();
            o.RoomTypes();
            o.CheckIn();
            o.CheckOut();
            o.NumberOfGuest();
            o.Book();
            o.Payment();
            book_hotel.ValidChoice=true;
        }
        else
        {
            cout << "Invalid choice! Please try again."<< endl<< endl;
            cout << "1) Bengal Blueberry\nLocation: 90 Road House 1/A, Dhaka City 1212 Bangladesh"<< endl<< endl;
            cout << "2) Hotel Sarina Dhaka\nLocation: 17 Plot #27 Road Banani C/A, Dhaka City 1213 Bangladesh"<< endl<< endl;
            cout << "3) White Palace Hotel\nLocation: House 25, Road 06 Sector 09, Dhaka City 1230 Bangladesh"<<endl<< endl;
            cout << "4) HOtel Omni Residency\nLocation: House 42, Road 15, Block D, Dhaka City 1213 Bangladesh"<< endl<< endl;
            cout << "Which hotel you would like to book? ";
            cin>>book_hotel.hotel_type;
            write<< book_hotel.hotel_type<< endl;
        }
    }
}

void BookHotel:: Recommendation()
{
    string recommend;
    i=j=k=l=0;
    ifstream read;
    read.open("Hotel_type.txt");
    while(getline(read,recommend))
    {
        if("1"==recommend)
            i++;
        else if("2"==recommend)
            j++;
        else if("3"==recommend)
            k++;
        else if("4"==recommend)
            l++;
    }
    if(i>=j&&j>=k&&k>=l)
        cout << "1) Bengal Blueberry, 2) Hotel Sarina Dhaka, 3) White Palace Hotel, 4) Hotel Omni Residency\n"<< endl;
    else if(i>=j&&j>=l&&l>=k)
        cout << "1) Bengal Blueberry, 2) Hotel Sarina Dhaka, 4) Hotel Omni Residency, 3) White Palace Hotel\n"<< endl;

    else if(i>=k&&k>=j&&j>=l)
        cout << "1) Bengal Blueberry, 3) White Palace Hotel, 2) Hotel Sarina Dhaka, 4) Hotel Omni Residency\n"<< endl;
    else if(i>=k&&k>=l&&l>=j)
        cout << "1) Bengal Blueberry, 3) White Palace Hotel, 4) Hotel Omni Residency, 2) Hotel Sarina Dhaka\n"<< endl;

    else if(i>=l&&l>=k&&k>=j)
        cout << "1) Bengal Blueberry, 4) Hotel Omni Residency, 3) White Palace Hotel, 2) Hotel Sarina Dhaka\n"<< endl;
    else if(i>=l&&l>=j&&j>=k)
        cout << "1) Bengal Blueberry, 4) Hotel Omni Residency, 2) Hotel Sarina Dhaka, 3) White Palace Hotel\n"<< endl;

    else if(j>=i&&i>=k&&k>=l)
        cout << "2) Hotel Sarina Dhaka, 1) Bengal Blueberry, 3) White Palace Hotel, 4) Hotel Omni Residency\n"<< endl;
    else if(j>=i&&i>=l&&l>=k)
        cout << "2) Hotel Sarina Dhaka, 1) Bengal Blueberry, 3) White Palace Hotel, 4) Hotel Omni Residency\n"<< endl;

    else if(j>=k&&k>=i&&i>=l)
        cout << "2) Hotel Sarina Dhaka, 3) White Palace Hotel, 1) Bengal Blueberry, 4) Hotel Omni Residency\n"<< endl;
    else if(j>=k&&k>=l&&l>=i)
        cout << "2) Hotel Sarina Dhaka, 3) White Palace Hotel, 4) Hotel Omni Residency, 1) Bengal Blueberry\n"<< endl;

    else if(j>=l&&l>=k&&k>=i)
        cout << "2) Hotel Sarina Dhaka, 4) Hotel Omni Residency, 3) White Palace Hotel, 1) Bengal Blueberry\n"<< endl;
    else if(j>=l&&l>=i&&i>=k)
        cout << "2) Hotel Sarina Dhaka, 4) Hotel Omni Residency, 1) Bengal Blueberry, 3) White Palace Hotel\n"<< endl;

    else if(k>=j&&j>=i&&i>=l)
        cout << "3) White Palace Hotel, 2) Hotel Sarina Dhaka, 1) Bengal Blueberry, 4) Hotel Omni Residency\n"<< endl;
    else if(k>=j&&j>=l&&l>=i)
        cout << "3) White Palace Hotel, 2) Hotel Sarina Dhaka, 4) Hotel Omni Residency, 1) Bengal Blueberry\n"<< endl;

    else if(k>=i&&i>=j&&j>=l)
        cout << "3) White Palace Hotel, 1) Bengal Blueberry, 2) Hotel Sarina Dhaka, 4) Hotel Omni Residency\n"<< endl;
    else if(k>=i&&i>=l&&l>=j)
        cout << "3) White Palace Hotel, 1) Bengal Blueberry, 4) Hotel Omni Residency, 2) Hotel Sarina Dhaka\n"<< endl;

    else if(k>=l&&l>=i&&i>=j)
        cout << "3) White Palace Hotel, 4) Hotel Omni Residency, 1) Bengal Blueberry, 2) Hotel Sarina Dhaka\n"<< endl;
    else if(k>=l&&l>=j&&j>=i)
        cout << "3) White Palace Hotel, 4) Hotel Omni Residency, 2) Hotel Sarina Dhaka, 1) Bengal Blueberry\n"<< endl;

    else if(l>=j&&j>=k&&k>=i)
        cout << "4) Hotel Omni Residency, 2) Hotel Sarina Dhaka, 3) White Palace Hotel, 1) Bengal Blueberry\n"<< endl;
    else if(l>=j&&j>=i&&i>=k)
        cout << "4) Hotel Omni Residency, 2) Hotel Sarina Dhaka, 1) Bengal Blueberry, 3) White Palace Hotel\n"<< endl;

    else if(l>=k&&k>=i&&i>=j)
        cout << "4) Hotel Omni Residency, 3) White Palace Hotel, 1) Bengal Blueberry, 2) Hotel Sarina Dhaka\n"<< endl;
    else if(l>=k&&k>=j&&j>=i)
        cout << "4) Hotel Omni Residency, 3) White Palace Hotel, 2) Hotel Sarina Dhaka, 1) Bengal Blueberry\n"<< endl;

    else if(l>=i&&i>=j&&j>=k)
        cout << "4) Hotel Omni Residency, 1) Bengal Blueberry, 2) Hotel Sarina Dhaka, 3) White Palace Hotel\n"<< endl;
    else if(l>=i&&i>=k&&k>=j)
        cout << "4) Hotel Omni Residency, 1) Bengal Blueberry, 3) White Palace Hotel, 2) Hotel Sarina Dhaka\n"<< endl;
    else
        cout << "1) Bengal Blueberry, 2) Hotel Sarina Dhaka, 3) White Palace Hotel, 4) Hotel Omni Residency\n"<< endl;
}

void BookHotel:: CheckIn()
{
    ofstream write;
    write.open("CheckIn.txt",ios::out|ios::app);
    cout << "Enter check-in date: ";
    cin>>checkin;
    write<< "Check In Date: "<< checkin<< endl;
}

void BookHotel:: CheckOut()
{
    ofstream write;
    write.open("CheckOut.txt",ios::out|ios::app);
    cout << "Enter check-out date: ";
    cin>>checkout;
    write<< "Check Out Date: "<< checkout<< endl;
}

void BookHotel:: NumberOfGuest()
{
    ofstream write;
    write.open("Guest.txt",ios::out|ios::app);
    cout << "How many guests stay here: ";
    cin>> guest;
    write<< "Number of guest: "<< guest<< endl;
}

void BookHotel:: Days()
{
    ofstream write;
    write.open("day.txt",ios::out|ios::app);
    cout << "how many days you want to stays: ";
    cin>>days;
    write<< "Days: "<<days<< endl;
}

void BookHotel:: Book()
{
    ofstream write;
    write.open("Payment.txt",ios::out|ios::app);
    while(!ValidChoice)
    {
        if(hotel_type==1)
        {
            price=8000;
            ValidChoice=true;
        }
        else if(hotel_type==2)
        {
            price=18000;
            ValidChoice=true;
        }
        else if(hotel_type==3)
        {
            price=10000;
            ValidChoice=true;
        }
        else if(hotel_type==4)
        {
            price=7000;
            ValidChoice=true;
        }
        else
        {
            cout << "Which hotel you would like to book? ";
            cin>>hotel_type;
        }
    }
    Days();

    total_price= price*days;
    cout << "The total price for booking hotel for "<< days << " days is "<< total_price<< " Taka."<< endl<< endl;
    write<< "Bill: "<< total_price<< endl;
}

void BookHotel:: Payment()
{
    cout << "How would you like to pay? (c for credit card, a for cash): ";
    cin>>payment;
    while(payment!="a"&&payment!="c")
    {
        cout << "Invalid choice. Please enter c for credit card or a for cash: ";
        cin >> payment;
    }
    if(payment=="c")
    {
        cout << "Please enter your credit card number: ";
        cin >> card_number;
        cout << "Thank you for your payment. Your booking has been confirmed.\n"<< endl;
    }
    else
        cout << "You have to visit our hotel. Thank you.\n"<< endl;

}
//constractor
BengalBlueberry:: BengalBlueberry()
{
    cout << "Hotel Bengal BlueBerry is a newly established Four Stars Luxury Hotel in the most VIPdiplomatic zone in Dhaka city. With all the modern amenities. Hotel Bengal BlueBerry is aperfect place for you and your valuable guest where you may have comfort and Luxury whilestaying. Yet for all the wonder this stunning structure provides when you finally see it in person,it is the service within that really makes the Bengal Blue Berry Hotel so extraordinary."<< endl;
}

HotelSarinaDhaka:: HotelSarinaDhaka()
{
    cout << "Hotel Sarina Dhaka is located at Banani adjacent to diplomatic enclave and the fast growing commercial area of Gulshan, Baridhara and Banani. Its 15 minutes drive from the Hazrat Shahjalal International Airport. Hotel Sarina Dhaka offers everything that a Business Traveler needs with an exclusive touch of personalized service."<<endl;
}

WhitePalaceHotel::WhitePalaceHotel()
{
    cout << "White Palace Hotel is a premier luxury hotel in Uttara that offers brand new, stunning accommodations. The hotel is easily accessible from the airport and is surrounded by many amenities, including supermarkets, shopping centers, restaurants, buying houses, banks, and multinational companies. It is ideal for both business and leisure travelers seeking top-notch hospitality and amenities, such as 54 spacious rooms, a modern banquet hall, multi-cuisine restaurant, live BBQ station, coffee shop and much more. The hotel also features state-of-the-art safety and security equipment, including fire and smoke detectors, electronic door locks, and CCTV surveillance. The hotel staff looks forward to welcoming guests soon."<< endl;
}

HotelOmniResidency:: HotelOmniResidency()
{
    cout << "Hotel Omni Residency is one of the leading luxury Hotels, Located in the Banani area. It’s a brand-new stunning hotel. The hotel is within easy access to the airport. This is the most secure area in Dhaka. It is a symbol of modern Dhaka. Hotel Omni Residency, aims to provide Customers with an excellent and truly memorable experience. Hotel Omni Residency is the perfect gateway for both business and leisure travelers, who will enjoy all that an international hotel can offer – from first to surrounding to world – class hospitality."<< endl;
}
//method of features

void BengalBlueberry:: Features()
{
    cout<< "1. Air conditioning \n2. Room service\n3. safe\n4. Minibar\n5. Refrigerator\n6. Flatscreen TV."<< endl;
}

void HotelSarinaDhaka:: Features()
{
    cout << "1. Air conditioning\n2. bathrobes\n3. housekeeping\n4. Desk\n5. Minibar\n6. Flatscreen TV"<<endl;
}

void WhitePalaceHotel:: Features()
{
    cout << "1. Air conditioning\n2. Desk\n3. Cable/Satellite TV\n4. Bath/Shower\n5. Coffee/Tea maker\n6. Extra long beds"<<endl;
}

void HotelOmniResidency :: Features()
{
    cout << "1. Allergy-free room\n2. blackout curtains\n3. Air conditioning\n4. Coffee/tea maker\n5. Cable/Satellite TV\n6. walk-in shower"<<endl;
}

//method of room-types
void BengalBlueberry:: RoomTypes()
{
    cout << "1. Non-smoking rooms\n2. Suites\n3. Family rooms\n4. Smoking rooms available."<< endl;
}

void HotelSarinaDhaka:: RoomTypes()
{
    cout << "1. City view\n2. Non-smoking rooms\n3. Suites\n4. Family rooms\n5. Smoking rooms available."<<endl;
}

void WhitePalaceHotel:: RoomTypes()
{
    cout << "1. City view\n2. Landmark view\n3. Pool view\n4. Non-smoking rooms\n5. Suites\n6. Family rooms."<< endl;
}

void HotelOmniResidency:: RoomTypes()
{
    cout << ". City view\n2. Landmark view\n3. Non-smoking rooms\n4. Family rooms\n5. Smoking rooms available."<< endl;
}
