#include <iostream>
#include <unistd.h> // for usleep() function

using namespace std;

// Definition of LED control class
class LedControl {
private:
    bool state; // LED state: on (true) or off (false)

public:
    // Constructor function
    LedControl() : state(false) {} // LED is initially off

    // Function to turn on the LED
    void turnOn() {
        state = true;
        cout << "LED is on" << endl;
    }

    // Function to turn off the LED
    void turnOff() {
        state = false;
        cout << "LED is off" << endl;
    }

    // Function to check the LED state
    bool checkState() const {
        return state;
    }
};

int main() {
    // Creating LED control object
    LedControl led;

    // Turning off the LED initially
    led.turnOff();

    // Getting input from the user for LED control
    char choice;
    do {
        cout << "Please select an operation (a: turn on LED, k: turn off LED, q: exit): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                led.turnOn();
                break;
            case 'k':
                led.turnOff();
                break;
            case 'q':
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
        }

        // Wait for a moment to respond to the user
        usleep(1000000); // wait for 1 second
    } while (choice != 'q');

    return 0;
}
