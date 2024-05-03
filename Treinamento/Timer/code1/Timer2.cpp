#include <iostream>
#include <winbase.h>

using namespace std;
class Timer2
{
private:
    short int hour, minutes, seconds;

public:
    Timer2(){};
    //~Timer2();
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
        hour = hr;
        minutes = min;
        seconds = sec;
    }
    void timer()
    {
        short int hr = hour;
        short int min = minutes;
        short int sec = seconds;

        if (hr < 0 || min < 0 || sec < 0 || min > 59 || sec > 59 || (hr == 0 && min == 0 && sec == 0))
        {
            cout << "Valores invalidos, tente novamente" << endl;
        }
        else
        {
            do
            {
                system("cls");
                //system("clear");
                // imprimir valores no formato mm:ss
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
                    else{
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
            //system("clear");
            cout << "0" << hr << ":0" << min << ":0" << sec << endl; // Tempo zerado
            cout << "TEMPO ESGOTADO" << endl;

        }
    }
};

int main()
{
    Timer2 timer;
    timer.setTimer();
    timer.timer();
}
