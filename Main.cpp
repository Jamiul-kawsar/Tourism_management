#include "Hakka_Dhaka.cpp"
#include "Kiyoshi.cpp"
#include "Thai_Emerald.cpp"
#include "Takeout_Tejgaon.cpp"
#include "BookingHotelRoom.cpp"
#include "final project with login.cpp"
#include "tourist_guide.cpp"

void select_restaurant();
void show_menu(int choice);
void menu();
void select(int choice);

int main()
{
    //int choice=0;
    ///while(!choice)
    //{
        menu();
    //}
    return 0;
}

void menu()
{
    std::cout << "\n\n ::::::: Tourism Management System ::::::: \n\n";
    std::cout << " 1. Book Hotel Room\n";
    std::cout << " 2. Hire Vehicle\n";
    std::cout << " 3. Hire Tourist Guide\n";
    std::cout << " 4. Order From Restaurant\n";

    select(0);
}

void select(int choice)
{
    std::cout << "\n Enter your choice(1-4): ";
    std::cin >> choice;

    switch(choice)
    {
    case 1:
    {
        std::cout << std::endl;
        hotel_booking();
    }
    break;
    case 2:
    {
        std::cout << std::endl;
        vehicle_rental();
    }
    break;
    case 3:
    {
        std::cout << std::endl;
        tourist_guide();
    }
    break;
    case 4:
        select_restaurant();
        break;
    default:
    {
        std::cout << "\n Invalid choice. Please try again.\n";
        select(choice);
    }
    break;
    }
}

void select_restaurant()
{
    std::vector<std::string> restaurants;

    std::string res;

    std::ifstream res_file ("Restaurants.txt", std::ios::in);

    if(res_file.is_open())
    {
        while( std::getline( res_file, res))
        {
            restaurants.push_back(res);
        }
        int i = 0;

        std::cout << "\n\t ----- Restaurants ------ \n\n";

        std::vector<std::string>::iterator it;

        for(it = restaurants.begin(); it != restaurants.end(); it++, i++)
        {
            std::cout << " " << i+1 << ". "  << *(it) << std::endl;
        }

        if(i>0)
        {
            int choice;
            std::cout << "\n Enter your choice(1-" << i << "): ";
            std::cin >> choice;

            if(choice<1 || choice>i)
            {
                std::cout << "\n Invalid choice. Please try again.\n";
                select_restaurant();
            }
            else
            {
                show_menu(choice);
            }
        }
        res_file.close();
    }
    else
    {
        std::cout << "\n Unable to read file.\n";
        exit(0);
    }
}

void show_menu(int choice)
{
    switch(choice)
    {
    case 1:
    {
        Thai_Emerald te;
        te.thai_em_menu();
    }
    break;
    case 2:
    {
        Hakka_Dhaka hd;
        hd.hakka_dhaka_menu();
    }
    break;
    case 3:
    {
        Kiyoshi k;
        k.kiyoshi_menu();
    }
    break;
    case 4:
    {
        Takeout_Tejgaon tj;
        tj.takeout_tejgaon_menu();
    }
    break;
    }
}
