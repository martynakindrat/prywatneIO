#include <iostream>

using namespace std;

class Nawodnienie {
public:
    string poziomNawodnienia;
    float litry;

    Nawodnienie() : poziomNawodnienia("Brak danych"), litry(0) {} // Initialize variables in the constructor

    float obliczPoziom(float masa) {
        cout << "### OBLICZANIE DZIENNEGO ZAPOTRZEBOWANIA NA WODĘ ###" << endl;
        // Zakładam, że średnie dzienne zapotrzebowanie wynosi 30 ml na 1 kg masy ciała
        float wynik = masa * 0.03;
        cout << "Dzienne zapotrzebowanie na wodę: " << wynik << " litrów" << endl;
        return wynik;
    }

    void wypijWode(float iloscSzklanek) {
        litry += iloscSzklanek * 0.25; // Zakładam, że jedna szklanka to 0.25 litra
        updatePoziomNawodnienia();
        cout << "Wypito " << iloscSzklanek << " szklanek wody." << endl;
    }

    void updatePoziomNawodnienia() {
        // Adjust these thresholds as needed
        if (litry >= 2.5) {
            poziomNawodnienia = "Bardzo dobry! :D";
        } else if (litry >= 2.0) {
            poziomNawodnienia = "Dobry! :)";
        } else if (litry >= 1.5) {
            poziomNawodnienia = "Przeciętny! :| ";
        } else {
            poziomNawodnienia = "Niedostateczny! :(";
        }
    }

    void displayInfo(float masa) {
        cout << "Informacje o nawodnieniu:" << endl;
        cout << "Masa ciała: " << masa << " kg" << endl;
        cout << "Poziom nawodnienia: " << poziomNawodnienia << endl;
        cout << "Ilość wypitej wody: " << litry << " litrów" << endl;
    }
};

int main() {
    float masa;
    cout << "Podaj masę ciała: ";
    cin >> masa;
    cout << " kg ";

    Nawodnienie poziom1;

    poziom1.obliczPoziom(masa);

    int iloscSzklanek;
    cout << "Podaj ilość wypitych szklanek wody dziś: ";
    cin >> iloscSzklanek;

    poziom1.wypijWode(iloscSzklanek);
    poziom1.displayInfo(masa);

    return 0;
}
