#include "Headers.h"

class Restaurant {
    public:
    void process_sub_menu(int choice);
    int find_int_from_str(std::string str);
    bool check_again();
    int other_options();
    void checkout(std::vector<std::string> items, int price);
    void space(std::vector<std::string> str);
    void select_option(std::vector<std::string> pay, std::vector<std::string> items, int price);
    void cash_memo(std::vector<std::string> items, int price);
    bool confirm_order();
    std::string int_to_str(std::string str, int price);
    bool bill(std::vector<std::string> items);
    std::vector<std::string> add_whitespace(std::vector<std::string> str, std::string max_string);
    void iterate(std::vector<std::string> vec, std::string max_string);
    void iterate(std::vector<std::string> str);
};
