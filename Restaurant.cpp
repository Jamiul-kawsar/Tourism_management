#pragma once

#ifndef RES_H
#define RES_H
#include "Restaurant.h"
#endif // RES_H

int Restaurant::find_int_from_str(std::string str)
{
    std::string nums;

    int i = 0;
    int space_count = 0;

    for( i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ') {
            space_count++;
            if(space_count > 1) {
                break;
            }
        } else {
            space_count = 0;
        }
    }

    int j = i;

    for(j = i; j < str.size(); j++)
    {
        if(str[j]>='0' && str[j]<='9') {
            nums.push_back(str[j]);
        }
    }

    int result = std::stoi(nums);

    return result;
}

bool Restaurant::check_again()
{
    char check;
    std::cout << " Do you want to select another item from this list(Y/n)? ";
    std::cin >> check;

    if(check=='Y' || check=='y')
        return true;
    return false;
}

int Restaurant::other_options()
{
    std::cout << std::endl;

    std::cout << " 1. Checkout" << std::endl;
    std::cout << " 2. Return to Previous Menu" << std::endl;

    int choice;

    std::cout << "\n Enter your choice(1-2): ";
    std::cin >> choice;

    if(choice <= 0 || choice > 2) {
        std::cout << "\n Invalid choice. Please try again.\n";
        return other_options();
    }
    return choice;
}

void Restaurant::checkout(std::vector<std::string> items, int price)
{
    std::cout << std::endl;

    std::fstream payment ("Payment.txt", std::ios::in);

    if(payment.is_open()) {
        std::string line;
        std::vector<std::string> pay;
        int i = 1;
        while(getline(payment, line))
        {
            std::cout << " " << i << ". " << line << std::endl;
            pay.push_back(line);
            i++;
        }
        select_option(pay, items, price);
    } else {
        std::cout << "\n Unable to open \'Payment.txt\'.\n";
    }
}

void Restaurant::select_option(std::vector<std::string> pay, std::vector<std::string> items, int price)
{
    if(pay.size() > 0) {
        int choice;
        std::cout << "\n Enter your choice(1-" << pay.size() << "): ";
        std::cin >> choice;

        if(choice < 0 || choice > pay.size()) {
            std::cout << "\n Invalid choice. Please try again.\n";
            select_option(pay, items, price);
        } else {
            std::string selected = pay[choice-1];

            if(selected == "Cash") {
                cash_memo(items, price);
            } else {
                std::string ext = ".txt";

                for(int i = 0; i < ext.size(); i++)
                {
                    selected.push_back(ext[i]);
                }

                std::fstream opt(selected, std::ios::in);

                if(opt.is_open()) {

                    std::string line;
                    std::vector<std::string> acc;

                    while(getline(opt, line))
                    {
                        acc.push_back(line);
                    }

                    std::string account_num;
                    std::cout << "\n Enter your account no. : ";
                    std::cin >> account_num;

                    while(account_num != acc[0])
                    {
                        std::cout << "\n Invalid account. Please try again.\n";
                        std::cout << "\n Enter your account no. : ";
                        std::cin >> account_num;
                    }

                    std::string pin;

                    std::cout << "\n Enter your PIN: ";
                    std::cin >> pin;

                    while(pin != acc[1])
                    {
                        std::cout << "\n Invalid PIN. Please try again.\n";
                        std::cout << "\n Enter your PIN: ";
                        std::cin >> pin;
                    }

                    cash_memo(items, price);

                    opt.close();
                } else {
                    std::cout << "\n Unable to open credit information file.\n";
                    exit(0);
                }
            }


        }
    } else {
        std::cout << "\n File is empty.\n";
    }
}

void Restaurant::space(std::vector<std::string> str)
{
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

    std::string max_string = str[index];

    std::vector<std::string>::iterator it;

    int i = 1;

    std::vector<std::string> new_vec = add_whitespace(str, max_string);

    for(it = new_vec.begin(); it != new_vec.end(); it++)
    {
        std::cout << " " << i << ". " << *(it) << std::endl;
        i++;
    }
}

void Restaurant::cash_memo(std::vector<std::string> items, int price)
{
    std::cout << "\n\n :::::: CASH MEMO :::::: \n\n";

    space(items);

    std::cout << std::endl;

    int vat = (price*15)/100;
    int delivery_fee = 50;
    int total = price + vat + delivery_fee;

    std::string sub_str = " Subtotal    : TK ";
    std::string vat_str = " VAT         : TK ";
    std::string delivery_str = " Delivery fee: TK ";
    std::string total_str = " Total: TK ";

    std::cout << sub_str << price << std::endl;
    std::cout <<  vat_str <<  vat << std::endl;
    std::cout <<  delivery_str << delivery_fee << std::endl;
    std::cout << std::endl <<  total_str << total << std::endl;

    sub_str = int_to_str(sub_str, price);
    vat_str = int_to_str(vat_str, price);
    delivery_str = int_to_str(delivery_str, price);
    total_str = int_to_str(total_str, price);

    items.push_back(sub_str);
    items.push_back(vat_str);
    items.push_back(delivery_str);
    items.push_back(total_str);

    if(confirm_order()) {
        std::cout << "\n Your order has been placed.";
        std::cout << " Thank you for using our service.\n";
        if(bill(items)) {
            std::cout << "\n This information has been appended to \'Bill.txt\' file.\n";
        }
        exit(0);
    } else {
        std::cout << "\n Your order has been cancelled.\n";
        exit(0);
    }

}

bool Restaurant::confirm_order()
{
    char choice;

    std::cout << std::endl;

    std::cout << " Confirm order(Y/n)? ";

    std::cin >> choice;

    if(choice == 'Y' || choice == 'y') {
        return true;
    }
    return false;
}

std::string Restaurant::int_to_str(std::string str, int price)
{
    std::string price_string = std::to_string(price);
    for(int i = 0; i < price_string.size(); i++)
    {
        str.push_back(price_string[i]);
    }
    return str;
}

bool Restaurant::bill(std::vector<std::string> items)
{
    std::fstream bill ("Bill.txt", std::ios::app);

    if(bill.is_open()) {
        for(int i = 0; i < items.size(); i++)
        {
            bill << items[i] << std::endl;
        }
    } else {
        return false;
    }
    return true;
}

std::vector<std::string> Restaurant::add_whitespace(std::vector<std::string> str, std::string max_string)
{
    std::vector<std::string> new_vec;

    for(int i = 0; i < str.size(); i++)
    {
        std::string str2 = str[i];

        int dif = max_string.size() - str2.size();

        if(str2.size() == max_string.size()) {
            new_vec.push_back(str2);
            continue;
        }

        if(str2.size() < max_string.size()) {

            for(int i = 0; i < str2.size() - max_string.size(); i++)
            {
                str2.push_back(' ');
            }

            int space_count = 0;

            int i = 0;

            for(i = 0; i < str2.size(); i++)
            {
                if(str2[i] == ' ') {
                    space_count++;
                    if(space_count == 2)
                        break;
                } else {
                    space_count = 0; //this caused a lot of problems
                }
            }

            while(str2[i] == ' ')
                i++;

            i = 0;

            if(dif < str2.size())
                for( i = str2.size()- 1; i >= str2.size() - dif || str2[i-dif] != 'T'; i--)
                {
                    std::swap(str2[i-dif], str2[i]);
                    if(str2[i] == 'T')
                        break;
                }

            if(str2[i-dif] == 'T') {
                std::swap(str2[i-dif], str2[i]);
            }

            new_vec.push_back(str2);
        }
    }
    return new_vec;
}


