#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

using namespace std;




int main(int argc, char **argv)
{
/*
    LZespolona A1={6,1};
    LZespolona A2={4,2};

      Wyswietl(A1%A2);
        cout << endl;
      Wyswietl(A1%A2);
        cout << endl;
      Wyswietl(A1%A2);
        cout << endl;
      Wyswietl(A1%A2);
*/

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  BazaT.wskTabTestu=nullptr;
  BazaT.IloscPytan=0;
  BazaT.IndeksPytania=0;


  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

WyrazenieZesp   WyrZ_PytanieTestowe;
Statystyka Staty{0,0};
LZespolona Odp;
    cout << "Na kazde pytanie dostepne 3 bledy skladni. Bladna odpowiedz konczy proby" << endl;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
  {
    cout << " Podaj wynik: " << WyrZ_PytanieTestowe;

        for(int i=0; i<4; i++)
        {
            cout << "\n Twoja Odpowiedz:";
            cin >> Odp;
            if (!cin.fail())
            {
                break;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Zly zapis" << endl;

        }
        if(cin.fail())
        {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Zly zapis" << endl;
        }
        else if(Odp == oblicz(WyrZ_PytanieTestowe))
        {
        Staty.poprawne++;
        cout << "Poprawna odpowiedz \n \n";
        }
        else
        {
        Odp=oblicz(WyrZ_PytanieTestowe);
        Staty.bledne++;
        cout << "Bledna odpowiedz. Poprawna odpowiedz:" << Odp << endl;
        }

    cout << endl;
  }


  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
    cout << "Poprawne odpowiedzi:" << Staty.poprawne << endl;
    cout << "Bledne odpowiedzi:" << Staty.bledne << endl;  Staty.procent=(Staty.poprawne*100/(Staty.bledne+Staty.poprawne));
    cout << "Procent poprawnych odpowiedzi:" << Staty.procent << "%" << endl;


}


