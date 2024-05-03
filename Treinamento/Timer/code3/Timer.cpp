#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

int main() {
    int hours, minutes, seconds;
    std::cout << "Enter the hours: ";
    std::cin >> hours;
    std::cout << "Enter the minutes: ";
    std::cin >> minutes;
    std::cout << "Enter the seconds: ";
    std::cin >> seconds;

    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    while (total_seconds > 0) {
        hours = total_seconds / 3600;
        minutes = (total_seconds % 3600) / 60;
        seconds = total_seconds % 60;

        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
        total_seconds--;
    }

    std::cout << "Time's up!\n";

    return 0;
}
