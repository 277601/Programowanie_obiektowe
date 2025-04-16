#ifndef KALKULATOR_H
#define KALKULATOR_H

class Kalkulator {
private:
    double akumulator;
    double pamiec;

public:
    Kalkulator();  
    double dodawanie(double a, double b);
    double odejmowanie(double a, double b);
    double mnozenie(double a, double b);
    double dzielenie(double a, double b);
    double reszta(double a, double b);
    
    void M_plus();
    void M_minus();
    void M_clear();
    
    double getPamiec() const;
    void setPamiec(double wartosc);
    double getAkumulator() const { return akumulator; }
    void setAkumulator(double wartosc);
};

#endif
