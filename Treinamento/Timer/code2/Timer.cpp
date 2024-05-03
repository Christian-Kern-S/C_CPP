#include <iostream>
#include <chrono>
#include <thread> // For sleep
#include <unistd.h>

class CountdownTimer
{
public:
    CountdownTimer(int minutes, int seconds)
    {
        totalSeconds = minutes * 60 + seconds;
    }

    void Start()
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        while (totalSeconds > 0)
        {
            auto currentTime = std::chrono::high_resolution_clock::now();
            auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
            int remainingSeconds = totalSeconds - elapsedSeconds;

            if (remainingSeconds <= 0)
                break;

            std::cout << "Time remaining: " << remainingSeconds / 60 << " minutes " << remainingSeconds % 60 << " seconds\r";
            std::cout.flush();

            // Sleep for 1 second
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
        }

        std::cout << "\nTime's up!\n";
    }

private:
    int totalSeconds;
};

int main()
{
    int minutes = 1;
    int seconds = 10;

    CountdownTimer timer(minutes, seconds);
    timer.Start();

    return 0;
}
