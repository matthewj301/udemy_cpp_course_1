
// Section 6
// Challenge

/* 
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>

const int small_room_price {25};
const int large_room_price {35};
const double tax_rate {0.06};
const int estimate_expiry_in_days {30}; // days

using namespace std;

int main() {
    int requested_small_rooms {0};
    int requested_large_rooms {0};
    int total_small_rooms_price {0};
    int total_large_rooms_price {0};
    int total_pretax_price {0};
    int total_posttax_price {0};

    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "How many small rooms would you like cleaned? ";
    cin >> requested_small_rooms;
    cout << "How many large rooms would you like cleaned? ";
    cin >> requested_large_rooms;

    total_small_rooms_price = requested_small_rooms * small_room_price;
    total_large_rooms_price = requested_large_rooms * large_room_price;
    total_pretax_price = total_small_rooms_price + total_large_rooms_price;
    total_posttax_price = total_pretax_price + (total_pretax_price * tax_rate);

    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << requested_small_rooms << endl;
    cout << "Number of large rooms: " << requested_large_rooms << endl;
    cout << "Price per small room: $" << small_room_price << endl;
    cout << "Price per large room: $" << large_room_price << endl;
    cout << "Cost: $" << total_pretax_price << endl;
    cout << "Tax: $" << (total_pretax_price * tax_rate) << endl;
    cout << "======================" << endl;
    cout << "Total estimate: $" << total_posttax_price << endl;
    cout << "This estimate is valid for " << estimate_expiry_in_days << " days" << endl;

    return 0;
}

