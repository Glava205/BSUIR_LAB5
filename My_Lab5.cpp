
#include <iostream>
#include <cstdlib>

using namespace std;




int main()
{
    int width;

    //vvod znacheniya
    cout << "VVedite razmer massiva\n";
    while (!(cin >> width) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << endl;
    }

    //dlina massiva
    const int wid = width;
    int* mas=new int[wid];

    //vybor zapolneniya
    cout << "Kak zapolnyt massiv? 1-s klaviatury, 2-random\n";
    int vyb;
    cin >> vyb;
    while (vyb<1 || vyb>2)
    {
        cout << "VVedite 1-s klaviatury, 2-random\n";
        cin >> vyb;
    }

    //opredelenie massiva
    if (vyb == 1)
    {
        for (int i = 0; i < wid; i++)
        {
            cout << "[ " << i+1 << " ] :";
            cin >> mas[i];
        }
        cout << "Massiv opredelen\n";
    }
    else
    {
        for (int i = 0; i < wid; i++)
        {
            cout << "[ " << i << " ] :";
            mas[i]=rand();
            cout << mas[i]<<"\n";
        }
        cout << "Massiv opredelen\n";
    }

    //proizvedenie
    int counter=0;
    for (int i = 0; i < wid; i++)
    {
        //pervyi 0
        if (mas[i] == 0)
        {
            i++;
            for (int k = i; k < wid; k++)
            {
                //vtoroy 0
                if (mas[k] == 0)
                {
                    goto Vyvod;
                }
                counter = counter * mas[k];
            }
        }
        counter = 0;
    }
Vyvod:
    cout << "Proizvedenie elementov= " << counter;

}

