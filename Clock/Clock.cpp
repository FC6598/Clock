#include <iostream>
#include <string>
using namespace std;

void Get12HourFormat(int hour, int minute, int second) {

    string ampm = "AM";

    // If hour is greater than or equal to 13, subtract 12 and set to PM
    if (hour >= 13) {
        hour -= 12;
        ampm = "PM";
    }
    else if (hour == 0) {
        hour = 12;
        ampm = "AM";
    }
    else if (hour == 12) { //Special case for noon
        ampm = "PM"; // Set to PM because noon is 12 PM
    }

    string hourString = to_string(hour);
    string minuteString = to_string(minute);
    string secondString = to_string(second);

    //These if statements check if a zero needs to be inserted
    if (hour < 10) {
        hourString.insert(0, "0");
    }
    if (minute < 10) {
        minuteString.insert(0, "0");
    }
    if (second < 10) {
        secondString.insert(0, "0");
    }

    // 12-hour format is output
    cout << "12-Hour Clock\n";
    cout << hourString << ':' << minuteString << ':' << secondString << ampm << endl;

}

void Get24HourFormat(int hour, int minute, int second) {

    string hourString = to_string(hour);
    string minuteString = to_string(minute);
    string secondString = to_string(second);
    // Ensure zero padding for single-digit time units
    if (hour < 10) {
        hourString.insert(0, "0");
    }
    if (minute < 10) {
        minuteString.insert(0, "0");
    }
    if (second < 10) {
        secondString.insert(0, "0");
    }


    // Display 24-hour format
    cout << "24-Hour Clock\n";
    cout << hourString << ':' << minuteString << ':' << secondString << endl;


}

int main() {

    int hour;
    int minute;
    int second;
    int menuChoice;

    cout << "Enter current hour";
    cin >> hour;
    cout << "Enter current minute";
    cin >> minute;
    cout << "Enter current second";
    cin >> second;

    Get12HourFormat(hour, minute, second);
    Get24HourFormat(hour, minute, second);

    cout << "1 - Add one hour" << endl;
    cout << "2 - Add one minute" << endl;
    cout << "3 - Add one second" << endl;
    cout << "4 - Exit program" << endl;

    cin >> menuChoice;

    while (menuChoice != 4) {
        if (menuChoice == 1) {
            hour += 1;
            if (hour > 23) {
                hour = 0;
            }
            Get12HourFormat(hour, minute, second);
            Get24HourFormat(hour, minute, second);
        }
        else if (menuChoice == 2) {
            minute += 1;
            if (minute > 59) {
                minute = 0;
                hour += 1;
            }
            Get12HourFormat(hour, minute, second);
            Get24HourFormat(hour, minute, second);
        }
        else if (menuChoice == 3) {
            second += 1;
            if (second > 59) {
                second = 0;
                minute += 1;
                if (minute > 59) {
                    minute = 0;
                    hour += 1;
                }
            }
                
                Get12HourFormat(hour, minute, second);
                Get24HourFormat(hour, minute, second);
            }
            cin >> menuChoice;
        }
    return 0;
    }
