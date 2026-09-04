#include<iostream>
#include<string>
using namespace std;

int money = 0;
int bankCash = 25000;

struct hotel {
    string name;
    float rating;
    string bFood;
    string location;
};

struct ride {
    string name;
    int id;
    float price;
};

struct veg {
    string name;
    float price;
};

void bankVisit(int bankChoice) {
    int choice;
    float cash;
    int changeChoice;
    
    if (bankChoice == 1) {
        cout << "ATM: How much money do you want to withdraw?" << endl;
        do {
            cin >> cash;
            if (cash < bankCash) {
            	money = money + cash;
                bankCash = bankCash - cash;
                break;
            } else {
                cout << "ATM: Try again! You are exceeding the maximum limit" << endl;
            }
        } while (true);
    } else {
	        cout << "Current Cash in Hand: " << money << endl;
        if (money > 1000) {
        	cout<<"Should I keep some change for myself?"<<endl;
        	cin>>changeChoice;
        	if(changeChoice==1){
        	int keptAmount = money * 0.10;
            int depositAmount = money - keptAmount;
            bankCash = bankCash + depositAmount;
            money = keptAmount;
            cout << "Deposited Amount: " << depositAmount << endl;
			} else {
            bankCash = bankCash + money;
            money = 0;
            cout << "Deposited all cash to the bank." << endl;
        }
        } else {
            bankCash = bankCash + money;
            money = 0;
            cout << "Deposited all cash to the bank." << endl;
        }
        cout << "New Bank Balance: " << bankCash << endl;
}
}

void vegShop(veg vegMenu[5]) {
    int choice;
    int amount;
    int count = 0;
    veg bill[100];
    int qty[100];
    int totBill = 0;

    cout << "Item\t\tPrice" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << vegMenu[i].name << "\t" << vegMenu[i].price << endl;
    }
    cout << "Shopkeeper: Choose item (0 to exit)" << endl;

     do {
        cin >> choice;
        if (choice > 0 && choice <= 5) {

            int i = choice - 1;
            cout << "Shopkeeper: How much do you want to buy sir?" << endl;
            cin >> amount;
            
            if (money >= vegMenu[i].price * amount) {
                bill[count] = vegMenu[i];
                qty[count] = amount;
                totBill = totBill + (vegMenu[i].price * amount);
                count++;
                cout<<"Shopkeeper: Want anything else sir?"<<endl;
            } else {
                cout << "Me: I dont have enough balance. Lets go to the bank again" << endl;
                bankVisit(1);
                cout << "Me: Lets try shopping again" << endl;
            }
        } else if (choice == 0) {
            if (count == 0) {
                cout << "Me: I need to buy at least 1 item" << endl;
            } else {
                break;
            }
        } else {
            cout << "Shopkeeper: Sorry sir! We don't have it available at the moment" << endl;
        }
    } while (choice != 0);

    cout << "Item\t\tPrice\t\tQuantity" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << bill[i].name << "\t" << bill[i].price << "\t\t" << qty[i] << endl;
    }
    cout << "Total Bill: " << totBill << endl;
    money = money - totBill;
    cout << "Shopkeeper: Thanks for shopping here sir." << endl;
}

void park(bool isFriend) {
    int rideChoice;
    ride bill[10];
    int totalBill = 0;
    int count = 0;
    cout << "Ticket Machine: Welcome to Fatima Jinnah Park! Please Enter the Ride ID you want to choose (Press 0 to Exit) "<<endl;

    ride rides[4] = {
        {"Slide  ", 1, 20},
        {"See-Saw", 2, 40},
        {"Ping   ", 3, 60},
        {"Cars   ", 4, 100},
    };

    cout << "ID\tName\t\tPrice" << endl;
    for (int i = 0; i < 4; i++) {
        cout << rides[i].id << "\t" << rides[i].name << "\t\t" << rides[i].price << endl;
    }

    do {
        cin >> rideChoice;

        if (rideChoice == 0) {
            break;
        }

        if (rideChoice > 0 && rideChoice <= 4) {
            int i = rideChoice - 1;
            int actualPrice = rides[i].price;

            if (isFriend == true) {
                actualPrice = actualPrice * 2;
                cout << "Ticket Machine: For 2 people, The price of tickets would be: " << actualPrice << endl;
            }

            if (money >= actualPrice) {
                money = money - actualPrice;
                bill[count] = rides[i];
                bill[count].price = actualPrice;
                totalBill = totalBill + actualPrice;
                count = count + 1;
            } else {
                cout << "Me: I dont have enough balance. Lets go to the bank again" << endl;
                bankVisit(1);
                cout << "Me: Lets try buying the ticket again" << endl;
            }
        } else {
            cout << "Ticket Machine: Invalid Ride ID." << endl;
        }

    } while (count < 4);

    cout << "Item\t\tPrice" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << bill[i].name << "\t" << bill[i].price << endl;
    }
    cout << "Ticket Machine: Your Total Bill is: " << totalBill << endl;
    cout << "Ticket Machine: Thanks for visiting here sir." << endl;
}

void hotels(bool isFriend) {
    int hotChoice;
    int fChoice;
    veg bill[10];
    int count = 0;
    int totBill = 0;

    hotel H[4] = {
        {"Sialvi Madni Restaraunt        ", 4.5, "Chicken Karahi ", "Lalamusa"},
        {"Bismillah Burgers & Shawarma   ", 4.3, "Shaami Burger  ", "Lalamusa"},
        {"Karachi Student Chicken Biryani", 4.6, "Chicken Biryani", "Gujrat"},
        {"Kentucky Fried Chicken (KFC)   ", 4.7, "Chicken Wings  ", "Kharian"}
    };

    veg hotelMenus[4][4] = {
        { {"Chicken Karahi ", 900}, {"Mutton Karahi  ", 2500}, {"Chicken Fried Rice", 700}, {"Naan/Roti Basket   ", 200} },
        { {"Shaami Burger  ", 160}, {"Zinger Burger  ", 350}, {"Chicken Shawarma(L)", 250}, {"Chicken Shawarma(S)", 190} },
        { {"Chicken Biryani", 160}, {"Simple Biryani ", 110}, {"Shami Tikki & Salad", 50}, {"Soft Drink (250ML)  ", 70} },
        { {"Chicken Wings  ", 500}, {"Chicken & Chips", 400}, {"Zingeratha         ", 390}, {"Krunch Burger      ", 310} }
    };

    cout << "\t\t\t\tSELECT A HOTEL" << endl;
    cout << "\tName" << "\t\t\t\t" << "\tRatings"<< "\t\t" << "Best Food"<< "\t" << "Location"<< endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << H[i].name << "\t\t" << H[i].rating<< "\t\t" << H[i].bFood<< "\t\t" << H[i].location << endl;
    }
    cin >> hotChoice;

    if (hotChoice >= 1 && hotChoice <= 4) {
        int hIndex = hotChoice - 1;
        cout << "Waiter: Welcome to " << H[hIndex].name << "! sir, please take a look at our menu" << endl;
        cout << "\t\t\tMENU" << endl;
        cout << "\tItem" << "\t\t\t\tPrice" <<endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << hotelMenus[hIndex][i].name
                 << "\t\t\t" << hotelMenus[hIndex][i].price << endl;
        }
        do {
            cout << "(Enter Item Number to Order (0 to exit)): ";
            cin >> fChoice;

            if (fChoice > 0 && fChoice <= 4) {
                int itemIndex = fChoice - 1;
                veg selectedItem = hotelMenus[hIndex][itemIndex];

                int actualPrice = selectedItem.price;

                if (isFriend == true) {
                    actualPrice = actualPrice * 2;
                    cout << "Waiter: Ok sir! That would be for 2 people right? " << actualPrice << endl;
                    cout<<"Me: Yes"<<endl;
                }

                if (money >= actualPrice) {
                    money = money - actualPrice;
                    selectedItem.price = actualPrice;
                    bill[count] = selectedItem;
                    totBill = totBill + actualPrice;
                    count++;
                } else {
                    cout << "Me: Not enough cash! Going to bank..." << endl;
                    bankVisit(1);
                    cout << "Me: Alright I am Back with money!" << endl;
                }
            } else if (fChoice != 0) {
                cout << "Waiter: Sorry Sir, We don't have what you are asking for available at the moment'" << endl;
            }

        } while (fChoice != 0 && count < 10);

        cout << " Cashier: Sir your Total Bill would be: " << totBill << endl;
    } else {
        cout << "Me: I don't think I know this hotel" << endl;
    }
}

void hospital() {
	cout << "Me: I am feeling extremley nauseous, doctor. I went to a hotel and after that I went to a park." << endl;
    cout << "Doctor: No need to worry, A few meds and you will be ok" << endl;
    cout << "Me: I am feeling much better now" << endl;
    cout << "Doctor: Take care next time" << endl;
    cout<<"Reception: Sir your bill would be 2000"<<endl;
    cout<<"Me: Alright here you go"<<endl;
    money = money - 2000;
}

int main() {
    cout << "Me: I need to go out today. But first, I need some cash from the bank." << endl;
    bankVisit(1);

    cout << "Me: Alright Now, Lets proceed to shop for some vegetables" << endl;
    cout << "Shopkeeper: Welcome to Our Shop sir. Please, take a look at our menu" << endl;
    veg vegMenu[5] = {
        {"Potato", 120},
        {"Tomato", 300},
        {"Onion", 500},
        {"Garlic", 700},
        {"Ginger", 800}
    };

    vegShop(vegMenu);

    veg frtMenu[5] = {
        {"Apple", 120},
        {"Mango", 300},
        {"Grapes", 500},
        {"Orange", 700},
        {"Banana", 800}
    };
    cout << "Me: Alright Now, Lets proceed to shop for some fruits" << endl;
    vegShop(frtMenu);

    int frnChoice;
    int parkHotChoice;
    int extChoice;
    bool isFriend;

    cout << "Mateen: Hey Where you going?" << endl;
    cout << "Me: Hey there!" << endl;
    cout << "(Press 1 to say Park and 2 to say Hotel and anything else to shrug him off)" << endl;
    cin >> frnChoice;

    if (frnChoice == 1) {
        cout << "Me: I am going to the park. Lets go together." << endl;
        parkHotChoice = 1;
        isFriend = true;
    } else if (frnChoice == 2) {
        cout << "Me: I am going to a hotel. lets go together" << endl;
        parkHotChoice = 2;
        isFriend = true;
    } else {
        cout << "Me: Nowhere bro! I am just headed home" << endl;
        cout << "(Finally, I can go alone. But where should I go first)" << endl;
        isFriend = false;
        do {
            cout << "1 for Park and 2 for hotel" << endl;
            cin >> parkHotChoice;
            if (parkHotChoice < 1 || parkHotChoice > 2) {
                cout << "Me: I dont know where that place really is" << endl;
            }
        } while (parkHotChoice < 1 || parkHotChoice > 2);
    }

    if (parkHotChoice == 1) {
        park(isFriend);
        cout << "Should I go to the hotel? (1 for Yes 2 for No)" << endl;
        do
        {
            cin>> extChoice;
        if(extChoice == 1) {
            hotels(isFriend);
            
        } else if (extChoice == 2) {
            cout << "Nah! lets go home" << endl;
            bankVisit(2);
            cout << "I am back Home!!" << endl;
        } else {
            cout << "What does that even mean?" << endl;
        }
        } while (extChoice < 1 || extChoice > 2);
        
    } else if (parkHotChoice == 2) {
        hotels(isFriend);
        cout << "Should I go to the park? (1 for Yes 2 to say No)" << endl;
        do {
            cin >> extChoice;
            if (extChoice == 1) {
                park(isFriend);
                cout << "(I am feeling very nauseous. I have to visit the hospital.)" << endl;
                hospital();
                bankVisit(2);
                cout << "I am back Home!!" << endl;
            } else if (extChoice == 2) {
                cout << "Nah! lets go home" << endl;
                bankVisit(2);
                cout << "I am back Home!!" << endl;
            } else {
                cout << "What does that even mean?" << endl;
            }
        } while (extChoice < 1 || extChoice > 2);
    }
    cout<<"Me: It's been a long day! Now, I am going to sleep. Good Night!!!"<<endl;
    return 0;
}
