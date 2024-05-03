#include <iostream>
#include <winbase.h>

using namespace std;
class Timer
{
private:
    short int hour, minutes, seconds;

public:
    Timer(int hr, int min, int sec)
    {
        hour = hr;
        minutes = min;
        seconds = sec;
    };
    //~Timer2(int hr, int min, int sec);
    
    void setTimer()
    {
        short int hr;
        short int min;
        short int sec;
        cout << "Informe a hora:" << endl;
        cin >> hr;
        cout << "Informe os minutos:" << endl;
        cin >> min;
        cout << "Informe os segundos:" << endl;
        cin >> sec;
    }

    bool isValidate()
    {
        if (hour < 0 || minutes < 0 || seconds < 0 || minutes > 59 || seconds > 59 || (hour == 0 && minutes == 0 && seconds == 0))
        {
            cout << "Valores invalidos, tente novamente" << endl;
            return true;
        }
        return false;
    }
    void timer()
    {
        short int hr = hour;
        short int min = minutes;
        short int sec = seconds;

        isValidate();
        if (isValidate)
        {
            do
            {
                system("cls");
                // system("clear");
                //  imprimir valores no formato mm:ss
                if (hr < 10)
                {
                    if (min < 10)
                    {
                        if (sec < 10)
                        {
                            cout << "0" << hr << ":0" << min << ":0" << sec << endl;
                        }
                        else
                        {
                            cout << "0" << hr << ":0" << min << ":" << sec << endl;
                        }
                    }
                    else
                    {
                        cout << "0" << hr << ":" << min << ":" << sec << endl;
                    }
                }
                else if (min < 10)
                {
                    if (sec < 10)
                    {
                        cout << hr << ":0" << min << ":0" << sec << endl;
                    }
                    else
                    {
                        cout << hr << ":0" << min << ":" << sec << endl;
                    }
                }
                else if (hr < 10 && sec < 10)
                {
                    cout << "0" << hr << ":" << min << ":0" << sec << endl;
                }
                else if (sec < 10)
                {
                    cout << hr << ":" << min << ":0" << sec << endl;
                }
                else
                {
                    cout << hr << ":" << min << ":" << sec << endl;
                }

                // atualizar a cada segundo
                Sleep(1000);

                if (sec == 0)
                {
                    if (min == 0)
                    {
                        hr--;
                        min = 59;
                        sec = 59;
                    }
                    else
                    {
                        min--;
                        sec = 59;
                    }
                }

                else
                {
                    sec--;
                }

            } while (hr != 0 || min != 0 || sec != 0);
            system("cls");
            // system("clear");
            cout << "0" << hr << ":0" << min << ":0" << sec << endl; // Tempo zerado
            cout << "TEMPO ESGOTADO" << endl;
            for (int i = 0; i < 5; i++)
            {
                Beep(880, 1000);
                Sleep(1000);
            }
        }
    }
};

int main()
{

    timer.setTimer();
    timer.timer();
}
