#include "kalkulator.h"
#include <iostream>

using namespace std;

Kalkulator::Kalkulator() : akumulator(0.0), pamiec(0.0) {}

double Kalkulator::dodawanie(double a, double b) {
    akumulator = a + b;
    return akumulator;
}

double Kalkulator::odejmowanie(double a, double b) {
    akumulator = a - b;
    return akumulator;
}

double Kalkulator::mnozenie(double a, double b) {
    akumulator = a * b;
    return akumulator;
}

double Kalkulator::dzielenie(double a, double b) {
    if (b == 0) {
        cout << "Nie mozna dzielic przez 0!" << endl;
        return 0;
    }
    akumulator = a / b;
    return akumulator;
}

double Kalkulator::reszta(double a, double b) {
    return a - (int)(a / b) * b;
}

void Kalkulator::M_plus() {
    pamiec += akumulator;
    cout << "Wartosc dodano do pamieci, aktualna pamiec: " << pamiec << endl; // Dodana instrukcja cout


}

void Kalkulator::M_minus() {
    pamiec -= akumulator;
    cout << "Wartosc odjeto od pamieci" << endl;
}

void Kalkulator::M_clear() {
    pamiec = 0.0;
    cout << "Pamiec wyczyszczona" << endl;
}

double Kalkulator::getPamiec() const {
    return pamiec;
}

void Kalkulator::setPamiec(double wartosc) {
    pamiec = wartosc;
}
void Kalkulator::setAkumulator(double wartosc) {
    akumulator = wartosc;
}
