#include <iostream>
#include "kalkulator.h"

using namespace std;

int main() {
    Kalkulator kalk;
    int wybor;
    double a, b;
    
    while (true) {
        cout << "\nWybierz dzialanie:\n";
        cout << "1. Dodawanie\n";
        cout << "2. Odejmowanie\n";
        cout << "3. Mnozenie\n";
        cout << "4. Dzielenie\n";
        cout << "5. Reszta z dzielenia\n";
        cout << "6. M+\n";
        cout << "7. M-\n";
        cout << "8. Czysc pamiec\n";
        cout << "9. Wyswietl pamiec\n";
        cout << "10. Wyjdz\n";
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == 10) {
            cout << "Chińskie dziecko wyłączone\n";
            break;
        }

        if (wybor >= 1 && wybor <= 5) {
            cout << "Podaj dwie liczby: ";
            cin >> a >> b;
        }

        switch (wybor) {
            case 1:
                cout << "Wynik dodawania: " << kalk.dodawanie(a, b) << endl;
                break;
            case 2:
                cout << "Wynik odejmowania: " << kalk.odejmowanie(a, b) << endl;
                break;
            case 3:
                cout << "Wynik mnozenia: " << kalk.mnozenie(a, b) << endl;
                break;
            case 4:
                cout << "Wynik dzielenia: " << kalk.dzielenie(a, b) << endl;
                break;
            case 5:
                cout << "Reszta z dzielenia: " << kalk.reszta(a, b) << endl;
                break;
            case 6:
                kalk.M_plus();
                break;
            case 7:
                kalk.M_minus();
                break;
            case 8:
                kalk.M_clear();
                break;
            case 9:
                cout << "Pamiec: " << kalk.getPamiec() << endl;
                break;
            default:
                cout << "Niepoprawny wybor!" << endl;
        }
    }

    return 0;
}
