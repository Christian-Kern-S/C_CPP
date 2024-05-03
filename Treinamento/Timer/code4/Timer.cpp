#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Timer {
private:
    int total_seconds;
    std::vector<Observer*> observers;

    Timer() : total_seconds(0) {}

public:
    static Timer& getInstance() {
        static Timer instance;
        return instance;
    }

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void set(int hours, int minutes, int seconds) {
        total_seconds = hours * 3600 + minutes * 60 + seconds;
    }

    void start() {
        while (total_seconds > 0) {
            int hours = total_seconds / 3600;
            int minutes = (total_seconds % 3600) / 60;
            int seconds = total_seconds % 60;

            std::string time = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
            notify("Time remaining: " + time);

            std::this_thread::sleep_for(std::chrono::seconds(1));
            total_seconds--;
        }

        notify("Time's up!");
    }

    void notify(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

class ConsoleObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << message << "\n";
    }
};

int main() {
    Timer& timer = Timer::getInstance();
    ConsoleObserver consoleObserver;
    timer.addObserver(&consoleObserver);

    int hours, minutes, seconds;
    std::cout << "Enter the hours: ";
    std::cin >> hours;
    std::cout << "Enter the minutes: ";
    std::cin >> minutes;
    std::cout << "Enter the seconds: ";
    std::cin >> seconds;

    timer.set(hours, minutes, seconds);
    timer.start();

    return 0;
}
