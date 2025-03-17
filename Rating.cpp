//This code doesn't work

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>

bool check_sub(std::string str, std::string str2);
int find_int_from_str(std::string str);
std::string num_to_str(int number);
void iterate(std::vector<std::string> ranked_res);
std::vector<std::string> sort_file(std::vector<std::string> ranked_list);
void bubble_sort(int* arr, int arr_size);

int main()
{
    std::ifstream res_file ("Restaurants.txt", std::ios::in);

	if(res_file.is_open()) {
        std::string res;
        std::cout << "\n\t ----- Restaurants ------ \n\n";
        int i = 0;//counts number of restaurants in file
        std::vector<std::string> restaurants;
        while( std::getline( res_file, res))
        {
            i++;
            std::cout << res << std::endl;
            restaurants.push_back(res);
        }

        int choice = 0;

        std::cout << "\n Enter your choice: ";
        std::cin >> choice;


        if(choice > 0 && choice <= i) {
            std::string chosen = restaurants[choice-1];

            std::fstream rating ("Rating.txt", std::ios::out | std::ios::in);

            std::string line;
            std::vector<std::string> ranked_res;
            if(rating.is_open()) {
                while( getline(rating, line))
                {
                    std::cout << line << std::endl;
                    ranked_res.push_back(line);
                }

                std::vector<std::string>::iterator it;

                for(it = ranked_res.begin(); it != ranked_res.end(); it++)
                {
                    //check substring
                    std::string str = *(it);
                    bool sub = check_sub(str, chosen);
                    if(sub) {
                        int num = find_int_from_str(str);

                        std::string num_string_before = std::to_string(num);

                        std::cout << "\n Number before: " << num << std::endl;

                        num += 1;
                        std::cout << "\n Number after: " << num << std::endl;

                        std::string num_string_after = std::to_string(num);

                        std::cout << " Before " << num_string_before << std::endl;
                        std::cout << " After " << num_string_after << std::endl;

                        int j = 0;

                        for(int i = 0; i < str.size(); i++)
                        {
                            if(str[i] >= '0' && str[i] <= '9') {
                                str[i] = num_string_after[j];
                                j++;

                            }
                        }

                        while(j < num_string_after.size())
                        {
                            str.push_back(num_string_after[j]);
                            j++;
                        }

                        //std::cout << str << std::endl;
                        *(it) = str;
                        break;
                    }
                }
                iterate(ranked_res);
                rating.close();
            } else {
                std::cout << "\n Unable to open rating file.\n";
            }
        }
    }


    return 0;
}

std::vector<std::string> sort_file(std::vector<std::string> ranked_list)
{
    std::vector<std::string>::iterator it;

    int number = 0;

    int* arr = new int[ranked_list.size()];

    int i = 0;

    for(it = ranked_list.begin(); it != ranked_list.end(); it++)
    {
        std::string str = (*(it));
        int number = find_int_from_str(str);
        arr[i] = number;
        i++;
    }

    std::vector<std::string> result;

    i = 0;

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, arr_size);

    for(it = ranked_list.begin(); it != ranked_list.end(); it++)
    {
        std::string str = *(it);
        int number = find_int_from_str(*(it));
        if(number == arr[i]) {
            result.push_back(*(it));
            i++;
            std::vector<std::string>::iterator it2 = ranked_list.erase(it);
            it = ranked_list.begin();
        }
    }


    delete []arr;

    return result;
}

void iterate(std::vector<std::string> ranked_res)
{
    std::vector<std::string>::iterator it;

    std::fstream rated_file ("Rating.txt", std::ios::out);

    if(rated_file.is_open()) {
        std::vector<std::string> new_ranked_res = sort_file(ranked_res);

        for(it = new_ranked_res.begin(); it != new_ranked_res.end(); it++)
        {
            std::cout << *(it) << std::endl;
            rated_file << *(it) << std::endl;
        }
        rated_file.close();
    } else {
        std::cout << "\n Unable to open rating file.\n";
    }

}

bool check_sub(std::string str, std::string str2)
{
    for(int i = 0; i <= str.size() - str2.size(); i++)
    {
        int j;
        for( j = 0; j < str2.size(); j++)
        {
            if(str[i+j] != str2[j])
                break;
        }
        if(j == str2.size()) {
            return true;
        }
    }
    return false;
}

int find_int_from_str(std::string str)
{
    std::string nums;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i]>='0' && str[i]<='9') {
            nums.push_back(str[i]);
        }
    }
    //std::cout << nums << std::endl;
    int result = std::stoi(nums);
    //std::cout << result << std::endl;
    return result;
}

void bubble_sort(int* arr, int arr_size)
{
    for(int i = 1; i <= arr_size; i++)
    {
        for(int j = 0; j < arr_size - i; j++)
        {
            if(arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
}









