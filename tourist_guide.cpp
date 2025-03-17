#include <iostream>
using namespace std;
class Tourist
{
public:

    void choice();
    void sonargaon();
    void taj();
    void dhaka();
    void olddhaka();
    void shylet();
    void cox();
    void hill();

};

void tourist_guide()
{
    Tourist obj;
    obj.choice();
}

void Tourist :: choice()
{
    cout<< "Welcome.Customers are our first priority.Hope you will have an amazing and pleasurable experience.Thank you."<<endl<<endl<<"Places For tour:" << endl<< "1.Sonargaon" << endl<< "2.Banglar Taj Mahal & Pyramid" << endl<< "3.Dhaka City" << endl << "4.Half-day Old Dhaka" << endl << "5.Teagarden and Rainforest of Sreemangal" << endl<< "6.Cox's Bazar" << endl<< "7.Bandarban & Sajec Valley" << endl;
    int choice ;
    cout<< "Enter Your Choice." << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
        Tourist obj1;
        obj1.sonargaon();
        break;

    case 2:
        Tourist obj2;
        obj2.taj();
        break;

    case 3:
        Tourist obj3;
        obj3.dhaka();
        break;

    case 4:
        Tourist obj4;
        obj4.olddhaka();
        break;

    case 5:
        Tourist obj5;
        obj5.shylet();
        break;

    case 6:
        Tourist obj6;
        obj6.cox();
        break;

    case 7:
        Tourist obj7;
        obj7.hill();
        break;

    }

}
void Tourist :: sonargaon ()
{
    cout<< "********************************Sonargaon Day-Tour from Dhaka City**********************************" << endl <<"This is a day tour will take experience the history, culture and heritage of old" ;
    cout<< " Bengali nation fromthe history of Mugal Empire to British transformation. You will learn about the past and current position of Bangladesh and experience the golden era of Bangali history." << endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.our service stars from 50$ per adult (price varies by group size.)We will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 1-90" <<endl<<"*Duration: 8h" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:" << endl<< "*Per adult: 50$" << endl<< "*Group of 4:120$" << endl<< "*Group of 8:150$" << endl<< "*If you have a group more than 8 members and if you have any requirment please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:" << endl<< "*Air-conditioned vehicle" << endl<< "*Snacks" << endl<< "*Lunch" << endl<< "*WiFi on board" << endl<< "*Bottled water" << endl<< "*Entry/Admission - Sonargaon Folk Art and Craft Museum" << endl<< "*Entry/Admission - Panam Nagar" << endl<<endl<< "Not included:" <<endl<<"*Entry Fee of Baro Sardar Bari (Emperor House)" << endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" << endl << endl<< endl<< endl;
}

void Tourist :: taj()
{
    cout<< "*******************************Banglar Taj Mahal & Pyramid Day-Tour from Dhaka City**********************************" << endl <<endl ;
    cout<< " Taj Mahal Bangladesh is an architectural imitation of Taj Mahal, a Mughal mausoleum in Agra, India.The Pyramid is standing beside it. These structures were built by Ahsanullah Moni, a Bangladeshi film-maker, as a tourist spot." << endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.our service stars from 50$ per adult (price varies by group size)We.will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 1-90" <<endl<<"*Duration: 8h" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:" << endl<< "*Per adult: 50$" << endl<< "*Group of 4:120$" << endl<< "*Group of 8:150$" << endl<< "*If you have a group more than 8 members and if you have any requirment please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:" << endl<< "*Air-conditioned vehicle" << endl<< "*Snacks" << endl<< "*Lunch" << endl<< "*WiFi on board" << endl<< "*Bottled water" << endl<< "*Entry/Admission - Taj Mahal & Pyramid" << endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" <<  endl<<  endl<<  endl<<  endl;

}
void Tourist :: dhaka()
{
    cout<< "*******************************Dhaka Full-Day City Sightseeing Tour**********************************" << endl <<endl;
    cout<< " Get a comprehensive tour of Dhaka combined with personalized attention on this private excursion. You and your party will be able to move at your own pace through the old town in Dhaka, listening to commentary on the city's history and culture. A local lunch, a rickshaw ride, and a traditional wooden boat ride are included.Hope you will have an amazing experience." << endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.our service stars from 50$ per adult (price varies by group size).We will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 10-90" <<endl<<"*Duration: 8h" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:" << endl<< "*Per adult: 80$" << endl<< "*Group of 4:170$" << endl<< "*Group of 8:220$" << endl<< "*If you have a group more than 8 members and if you have any requirement please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:" << endl<< "*Hotel pickup & Hotel drop-off" << endl <<"*Professional Art & Historian guide" << endl<< "*Private Transfer,Traditional Pulling Rickshaw Ride,Traditional Wooden Rowboat Ride" << endl<< "*Walking tour through small narrow streets around the old town" << endl<< "*Bottled water" << endl<< "*Traditional Menu Lunch" <<endl<<endl << "Not included:" <<endl<<"*Drinks both Soft and Hard"<< endl<<"*Any Expenses which is not mentioned"<< endl<<"*Entry/Admission - Lalbag Fort"<< endl<<"*Entry/Admission - Ahsan Manzil"<< endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" <<  endl<<  endl<<  endl<<  endl;
}
void Tourist :: olddhaka()
{
    cout<< "*******************************Half-day Old Dhaka History & Heritage Private Tour**********************************" << endl <<endl;
    cout<< "Dhaka is the capital city of Bangladesh, in southern Asia. Set beside the Buriganga River, it’s at the center of national government, trade and culture. The 17th-century old city was the Mughal capital of Bengal, and many palaces and mosques remain. American architect Louis Khan’s National Parliament House complex typifies the huge, fast-growing modern metropolis." << endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.our service stars from 45$ per adult (price varies by group size).We will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 10-90" <<endl<<"*Duration: 8h" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:" << endl<< "*Per adult: 45$" << endl<< "*Group of 4:110$" << endl<< "*Group of 8:160$" << endl<< "*If you have a group more than 8 members and if you have any requirement please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:"<< endl <<"*Professional Art & Historian guide" << endl<< "*Private Transportation(AC)"<< endl  <<"*Walking tour through small narrow streets around the old town" << endl<< "*Bottled water"  <<endl<<endl << "Not included:"<<endl<< "*Traditional Menu Lunch"  <<endl<<"*Drinks both Soft and Hard"<< endl<<"*Any Expenses which is not mentioned"<< endl<<"*Entry/Admission - Lalbag Fort"<< endl<<"*Entry/Admission - Ahsan Manzil"<< endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" <<  endl<<  endl<<  endl<<  endl;
}
void Tourist :: shylet()
{
    cout<< "*******************************3 Days Teagarden and Rainforest Tour in Sreemangal**********************************" << endl <<endl ;
    cout<< " Sreemangal is a town located in the northeastern part of Bangladesh, in the Moulvibazar district of Sylhet division. It is known as the tea capital of Bangladesh, as it is the center of the country's largest tea producing region. The town is surrounded by lush green tea gardens, hills, and forests, which make it a popular tourist destination in Bangladesh. The area is also home to many indigenous communities, including the Khasi, Monipuri, and Tripura tribes, who have their own unique cultures and traditions. One of the most popular attractions in Sreemangal is Lawachara National Park, which is home to a diverse range of flora and fauna, including several rare species of birds, monkeys, and reptiles. Another popular destination is the Madhabpur Lake, which is known for its serene beauty and picturesque views." << endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.This service is for group tour (max:8)and it starts from 120$ (3 members).We will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 1-90" <<endl<<"*Duration: 3 days" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:"  << endl<< "*group of  minimum 5 members:250$"<< endl<< "*group of  maximum 8 members:300$"<< endl<< "*If you have any requirment please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:"<< endl <<"*Professional guide" << endl<< "*Private Transportation(AC)"<< endl  <<"*Breakfast" << endl<< "*Lunch"   <<endl << "*Water"<<endl<<endl<< "*Not included:" <<endl << "*Local Transportation."  <<endl<<"*Drinks both Soft and Hard"<< endl<<"*Any Expenses which is not mentioned" << endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" <<  endl<<  endl<<  endl<<  endl;

}
void Tourist :: cox()
{
    cout<< "*******************************3 Days Cox's Bazar Tour**********************************" << endl <<endl ;
    cout<< " Cox's Bazar beach is the longest sea beaches in the world. Itfs a sandy beach. The sea beach is the main attraction of the Cox's Bazar town. There are large number of hotels, resorts, guest houses, motels and restaurants have been established in the city. Many international standard 3 to 5 star hotels and resorts are available, which provide exclusive beachside area with accessories for the tourist. Itfs a stunning and beautiful place to enjoy swimming, walking, and to observe sunrise and sunset. Itfs a wonderful beach to visit for the family, friends and tourists and to enjoy the amazing nature" << endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.This service is for group tour (min 4)and it starts from 200$ .We will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 1-90" <<endl<<"*Duration: 3 days" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:"  << endl<< "*group of  minimum 4 members:200$"<< endl<< "*group of  maximum 8 members:370$"<< endl<< "*If you have any requirment please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:"<< endl <<"*Professional guide" << endl<< "*Private Transportation(AC)"<< endl  <<"*Breakfast" << endl<< "*Lunch"   <<endl << "*Water"<<endl<<endl<< "*Not included:" <<endl << "*Local Transportation."  <<endl<<"*Drinks both Soft and Hard"<< endl<<"*Any Expenses which is not mentioned" << endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" <<  endl<<  endl<<  endl<<  endl;

}
void Tourist :: hill()
{
    cout<< "*******************************Tour of Bandarban & Sajec Valley**********************************" << endl <<endl<<endl ;
    cout<< "********Bandarban**********" <<endl<< "Among the eye-catching places, the most remote and least populated Bandarban is a popular destination for its adventurous, distinctive and scenic landscape. The beauty of its forests, numerous waterfalls, tallest peaks and lifestyles of 15 different ethnic groups attract tourists from both home and abroad."<< endl<< endl;
    cout<< "********Sajec Valley*******" << "Sajek is located in the verdant hills of Kasalong range of mountains amidst the serene and exotic beauty of nature. Lofty mountains, dense forest, sprawling grasslands and miles of hilly tracks feature the valley. The simple and basic indigenous lifestyle of local people is just fabulous for visitors to spend a day."<< endl<< endl;
    cout<< "Reserve Now & Pay Later" << endl<<"We guarantee the lowest price.This service is for group tour (max:8) and our service starts from 150$ (min 3 members)We will reserve your spot today, and you can cancel up to two days before your experience without making a payment. Secure your spot with ease, stay flexible, and never miss out.Have a great time."<<endl<<endl;
    cout<< "Conditions:" << endl<<"*Ages: 1-90" <<endl<<"*Duration: 3 days" <<endl<<"*Start time: Check availability" <<endl<<"*Mobile ticket"<< endl<<"*Language:English" <<endl<<endl<< "Cost:"  << endl<< "*group of  minimum 3 members:150$"<< endl<< "*group of  maximum 8 members:300$"<< endl<< "*If you have any requirment please contact with us and ensure your price." << endl<< endl ;
    cout<< "What are included:"<< endl <<"*Professional guide" << endl<< "*Private Transportation(AC)"<< endl  <<"*Breakfast" << endl<< "*Lunch"   <<endl << "*Water"<<endl<<endl<< "*Not included:" <<endl << "*Local Transportation."  <<endl<<"*Drinks both Soft and Hard"<< endl<<"*Any Expenses which is not mentioned" << endl<< endl;
    cout<<endl<< "Contact:" << endl<< "*014767678" << endl<< "*Email:tahossain45@gmail.com" <<  endl<<  endl<<  endl;

}



