#ifndef RES
#define RES
#include "Restaurant.cpp"
#endif // RES

class Kiyoshi : public Restaurant {
    public:
    //shows main menu
    void kiyoshi_menu();
    //selects from main menu
    void select_menu(std::vector<std::string> main_menu, int lines);
    //finds path for selected sub menu
    std::string find_path(std::string selected);
    //shows sub menu
    void show_sub_menu(std::string path);
    //selects from sub menu
    void select_item(std::vector<std::string> sub_menu, std::vector<std::string> items, int cost, int price);
    //shows all selected items
    void show_selected_items(std::vector<std::string> items);
    //text formatting
    void space(std::vector<std::string> str);
    //processes other options if user no longer wants to order
    //such as checking out or going to previous menu
    void process_options(int choice, std::vector<std::string> items, int price);
    //selects from menu again
    void select_menu_again(std::vector<std::string> main_menu, std::vector<std::string> items, int lines, int price);
    //shows sub menu again
    void show_sub_menu_again(std::string path, std::vector<std::string> items, int price);
};

//Shows main menu
void Kiyoshi::kiyoshi_menu()
{
    std::ifstream kiyoshi ("Menus/Kiyoshi/kiyoshi_menu.txt");

    if(kiyoshi.is_open()) {
        int i = 0; //used to keep track of the lines in the file

        std::string line;
        std::vector<std::string> main_menu;

        std::cout << "\n\t ------- Kiyoshi Menu -------- \n\n";

        while( std::getline(kiyoshi, line))
        {
            std::cout << " " << i+1 << "." << line << std::endl;
            main_menu.push_back(line);
            i++;
        }
        select_menu(main_menu, i);
        kiyoshi.close();

    } else {
        std::cout << "\n Unable to open file.\n";
        exit(0);
    }
}

void Kiyoshi::select_menu(std::vector<std::string> main_menu, int lines)
{
    if(lines>0) {
            int choice;
            std::cout << std::endl;
            std::cout << "\n Enter your choice(1-" << lines << "): ";
            std::cin >> choice;

            if(choice<1 || choice>lines) {
                std::cout << "\n Invalid choice. Please try again.\n";
                select_menu(main_menu, lines);
            } else {//concatenates sub menu to path
                std::string selected = main_menu[choice-1];
                std::cout << std::endl;
                std::cout << "\t ------- " << selected << " ------- " << std::endl;
                std::cout << std::endl;
                std::string path = find_path(selected);
                show_sub_menu(path);
            }
    } else {
        std::cout << std::endl << " Nothing found in file." << std::endl;
    }
}

std::string Kiyoshi::find_path(std::string selected)
{
    std::string path = "Menus/Kiyoshi/";
    std::string ext = ".txt";

    for(int i = 0; i < selected.size(); i++)
        path.push_back(selected[i]);

    for(int i = 0; i < ext.size(); i++)
        path.push_back(ext[i]);

    return path;
}


//Shows menu for selected submenu
void Kiyoshi::show_sub_menu(std::string path)
{
        std::ifstream sub_menu_file (path);

        std::string line;
        std::vector<std::string> sub_menu;

        int lines = 0;

        std::cout << std::endl;

        if(sub_menu_file.is_open()) {
            while( getline(sub_menu_file, line)) {
                std::cout << " " << lines+1 << ". " << line << std::endl;
                sub_menu.push_back(line);
                lines++;
            }

            if(lines > 0) {
                std::vector<std::string> items;
                select_item(sub_menu, items, 0, 0);
            } else {
                std::cout << std::endl;
                std::cout << " Sub menu file is empty." << std::endl;
            }

            sub_menu_file.close();
        } else {
           std::cout << std::endl << " Unable to open sub menu file." << std::endl;
        }
}

void Kiyoshi::select_item(std::vector<std::string> sub_menu, std::vector<std::string> items, int cost, int price)
{
            int choice;
            std::cout << "\n Enter your choice(1-" << sub_menu.size() << "): ";
            std::cin >> choice;

            if(choice > 0 && choice <= sub_menu.size()) {
                std::string chosen = sub_menu[choice-1];

                std::cout << std::endl;

                std::cout << std:: endl;

                items.push_back(chosen);

                int cost = find_int_from_str(chosen);

                price += cost;

                space(items);

                std::cout << std::endl;
                std::cout << " Subtotal : " << price << std::endl;
                std::cout << std::endl;

                if(Restaurant::check_again()) {
                    select_item(sub_menu, items, cost, price);
                }   else {
                    int choice = other_options();
                    process_options(choice, items, price);
                }
        } else {
            std::cout << "\n Invalid choice. Please try again.\n";
            select_item(sub_menu, items, cost, price);
        }
}

void Kiyoshi::space(std::vector<std::string> str)
{
    //checking if all strings are of the same length

    int len = str[0].size(), len_in = 0;
    bool flag = true;
    std::string max_string;

    for(int i = 1; i < str.size(); i++)
    {
        int current_length = str[i].size();
        if(current_length == len) {
            continue;
        }

        if(current_length > len) {
            len = current_length;
            len_in = i;
        }
        flag = false;

    }

    if(flag == true) {

        int length = 0, index = 0;

        //length of all strings here are same
        //we have to differentiate by finding the maximum number
        //of characters before finding two spaces
        for(int i = 0; i < str.size(); i++)
        {
            std::string current = str[i];

            int current_length = 0;
            int space_count = 0;

            for(int j = 0; j < current.size(); j++)
            {
                if(current[j] == ' ') {
                    space_count++;
                    if(space_count == 2) {
                        if(current_length > length) {
                            index = i;
                            length = current_length;
                        }
                            break;
                    }
                    current_length++;
                } else {
                    space_count = 0;
                    current_length++;
                }
            }
        }

        max_string = str[index];

        std::string selected = "Items Selected";

        int counter = 0, current_counter=0;

        for(int i = 0; i < max_string.size(); i++)
        {
            if(max_string[i] == ' ') {
                current_counter++;
                if(current_counter > counter)
                    counter = current_counter;
            } else {
                current_counter = 0;
            }
        }

        int spaces = 0;

        if(str.size() < 10) {
            spaces = length - selected.size() + counter + 2;
        } else {
            spaces = length - selected.size() + counter + 3;
        }

        for(int i = 0; i < spaces; i++)
        {
            selected.push_back(' ');
        }

        std::cout << " " << selected << "Price\n\n";

        std::vector<std::string>::iterator it;

        int i = 1;

        for(it = str.begin(); it != str.end(); it++)
        {
            if(i < 10) {
                std::cout << " " << i << ". " << *(it) << std::endl;
            } else {
                std::cout << i << ". " << *(it) << std::endl;
            }

            i++;
        }
    }   else    {

        max_string = str[len_in];

        std::string selected = "Items Selected";

        int spaces = 0;

        if(str.size() < 10) {
            spaces = len - selected.size() - 3;
        } else {
            spaces = len - selected.size() - 2;
        }

        for(int i = 0; i < spaces; i++)
        {
            selected.push_back(' ');
        }

        std::cout << " " << selected << "Price\n\n";

        std::vector<std::string>::iterator it;

        int i = 1;

        std::vector<std::string> new_vec = add_whitespace(str, max_string);

        for(it = new_vec.begin(); it != new_vec.end(); it++)
        {
            if(i < 10) {
                std::cout << " " << i << ". " << *(it) << std::endl;
            } else {
                std::cout << i << ". " << *(it) << std::endl;
            }
            i++;
        }

    }
}


void Kiyoshi::process_options(int choice, std::vector<std::string> items, int price)
{
    if(choice == 1) {
        checkout(items, price);
    } else {
        std::ifstream kiyoshi ("Menus/Kiyoshi/kiyoshi_menu.txt");

        if(kiyoshi.is_open()) {
            int i = 0; //used to keep track of the lines in the file

            std::string line;
            std::vector<std::string> main_menu;

            std::cout << "\n\t ------- Kiyoshi Menu -------- \n\n";

            while( std::getline(kiyoshi, line))
            {
                std::cout << " " << i+1 << "." << line << std::endl;
                main_menu.push_back(line);
                i++;
            }
            select_menu_again(main_menu, items, i, price);
            kiyoshi.close();

        } else {
            std::cout << "\n Unable to open file.\n";
            exit(0);
        }
    }
}

void Kiyoshi::select_menu_again(std::vector<std::string> main_menu, std::vector<std::string> items, int lines, int price)
{
    if(lines>0) {
            int choice;
            std::cout << std::endl;
            std::cout << "\n Enter your choice(1-" << lines << "): ";
            std::cin >> choice;

            if(choice<1 || choice>lines) {
                std::cout << "\n Invalid choice. Please try again.\n";
                select_menu_again(main_menu, items, lines, price);
            } else {//concatenates sub menu to path
                std::string selected = main_menu[choice-1];
                std::cout << std::endl;
                std::cout << "\t ------- " << selected << " ------- " << std::endl;
                std::cout << std::endl;
                std::string path = find_path(selected);
                show_sub_menu_again(path, items, price);
            }
    } else {
        std::cout << std::endl << " Nothing found in file." << std::endl;
    }
}

void Kiyoshi::show_sub_menu_again(std::string path, std::vector<std::string> items, int price)
{
        std::ifstream sub_menu_file (path);

        std::string line;
        std::vector<std::string> sub_menu;

        int lines = 0;

        if(sub_menu_file.is_open()) {
            while( getline(sub_menu_file, line)) {
                std::cout << " " << lines+1 << ". " << line << std::endl;
                sub_menu.push_back(line);
                lines++;
            }

            if(lines > 0) {
                select_item(sub_menu, items, 0, price);
            } else {
                std::cout << std::endl;
                std::cout << " Sub menu file is empty." << std::endl;
            }

            sub_menu_file.close();
        } else {
           std::cout << std::endl << " Unable to open sub menu file." << std::endl;
        }
}
