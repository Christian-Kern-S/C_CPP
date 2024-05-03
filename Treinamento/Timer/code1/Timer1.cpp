#include <iostream>
#include <winbase.h>


using namespace std;
int main(void)
{

    int min, seg;
    cout << "Informe os minutos e segundos" << endl;
    cin >> min >> seg;

    if (min < 0 || seg < 0 || min > 59 || seg > 59 || (min == 0 && seg == 0))
    {
        cout << "Valores invalidos, tente novamente" << endl;
    }
    else
    {
        do
        {
            system("cls");
            // imprimir valores no formato mm:ss
            if (min < 10)
            {
                if (seg < 10)
                {
                    cout << "0" << min << ":0" << seg << endl;
                }
                else
                {
                    cout << "0" << min << ":" << seg << endl;
                }
            }
            else if (seg<10)
            {
                cout << min << ":0" << seg << endl;
            }
            else{
                cout << min << ":" << seg << endl;
            }
            

            // atualizar a cada segundo
            Sleep(1000);
            if (seg == 0)
            {
                min--;
                seg = 59;
            }
            else
            {
                seg--;
            }

        } while (min != 0 || seg != 0);
        system("cls");
        cout << "0" << min << ":0" << seg << endl; // Tempo zerado
        cout << "TEMPO ESGOTADO" << endl;
        for (int i = 0; i < 5; i++)
        {
            Beep(880, 1000);
            Sleep(1000);
        }
    }
}
