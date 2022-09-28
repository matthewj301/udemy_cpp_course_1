// Section 11
// Recursion - Penny Multiplier

#include <iostream>

using namespace std;

double a_penny_doubled_everyday(int, double = 0.01);

int main() {
    double total_amount = a_penny_doubled_everyday(1);
    cout << "Total amount: " << total_amount << endl;
    return 0;
}

double a_penny_doubled_everyday(int number_of_days, double amount) {
    if (number_of_days <= 1) {
        return amount;
    }
    // Pretty interesting how number_of_days is handled here
    return a_penny_doubled_everyday(--number_of_days, amount*2);

}
