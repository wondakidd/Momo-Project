#include <iostream>
using namespace std;

int default_pin = 0000;
int default_balance = 1000;
int auth_attempts = 0;

bool authenticate(int entered_pin) {
    if (entered_pin == default_pin) {
        return true;
    } else {
        auth_attempts++;
        if (auth_attempts >= 3) {
            exit(0);
        }
        return false;
    }
}

void reset_pin() {
    int old_pin, new_pin;
    cout << "Enter old pin: ";
    cin >> old_pin;
    if (old_pin == default_pin) {
        cout << "Enter new pin: ";
        cin >> new_pin;
        default_pin = new_pin;
    } else {
        cout << "Old pin was incorrect" << endl;
    }
}

void check_balance() {
    cout << "Your balance is: " << default_balance << endl;
}

void send_money() {
    int recipient_phone_number, amount;
    cout << "Enter recipient phone number: ";
    cin >> recipient_phone_number;
    cout << "Enter amount to send: ";
    cin >> amount;
    if (amount <= default_balance) {
        default_balance -= amount;
        cout << "Sent " << amount << " to " << recipient_phone_number << endl;
    } else {
        cout << "Insufficient balance" << endl;
    }
}

int main() {
    int choice, pin;
    while (true) {
        cout << "Enter pin: ";
        cin >> pin;
        if (authenticate(pin)) {
            cout << "1. Reset Pin" << endl;
            cout << "2. Check Balance" << endl;
            cout << "3. Send Money" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    reset_pin();
                    break;
                case 2:
                    check_balance();
                    break;
                case 3:
                    send_money();
                    break;
                case 4:
                    exit(0);
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }
    return 0;
}
