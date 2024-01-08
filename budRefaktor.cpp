#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Logowanie {
private:
    string login;
    string haslo;

public:
    Logowanie(const string& username, const string& password): login(username), haslo(username) {}

    bool sprawdz(const string& inputUsername, const string& inputPassword) {
        return (login == inputUsername && haslo == inputPassword);
    }

    bool wymaganiaHasla(const string& password) {
        if (password.length() < 8) {
            cout << "Haslo musi miec co najmniej 8 znakow." << endl;
            return false;
        }

        bool maDuzaLitere = false;
        bool maCyfre = false;
        for (char znak : password) {
            if (isupper(znak)) {
                maDuzaLitere = true;
            }
            if (isdigit(znak)) {
                maCyfre = true;
            }
        }

        if (!maDuzaLitere || !maCyfre) {
            cout << "Haslo musi zawierac przynajmniej 1 dużą litere i 1 cyfre." << endl;
            return false;
        }
        return true;
    }

    string poprawneHaslo(const string& password){
        return password;
    }
};

class User {
private:
    string imie;
    int wiek;
    double waga;
    double wzrost;

public:
    void setUserInfo(const string& inputName, int inputAge) {
        imie = inputName;
        wiek = inputAge;
    }

    void setWeight(double weight) {
        waga = weight;
    }

    void setHeight(double height) {
        wzrost = height;
    }

    string getImie() const {
        return imie;
    }

    int getWiek() const {
        return wiek;
    }

    double getWaga() const {
        return waga;
    }

    double getWzrost() const {
        return wzrost;
    }
};

class Aktywnosc {
public:
    string aktywnosc_trening;
    string tryb_pracy;
    string aktywnosc_dzien;

    string getAktywnoscTrening() const {
        return aktywnosc_trening;
    }

    string getTrybPracy() const {
        return tryb_pracy;
    }

    string getAktywnoscDzien() const {
        return aktywnosc_dzien;
    }

    void setTrainingActivity(const string& activity) {
        aktywnosc_trening = activity;
    }

    void setWorkMode(const string& workMode) {
        tryb_pracy = workMode;
    }

    void setDayActivity(const string& dayActivity) {
        aktywnosc_dzien = dayActivity;
    }
};

class Cel {
public:
    double waga_docelowa;

    double getWagaDocelowa() const {
        return waga_docelowa;
    }
};

int main() {
    Logowanie logowanie("bozena_nowak", "Mleko231");

    string wprowadzoneHaslo;
    cout << "Podaj haslo: ";
    cin >> wprowadzoneHaslo;

    if (logowanie.wymaganiaHasla(wprowadzoneHaslo)) {
        cout << "Haslo poprawne!" << endl;

        User uzytkownik;
        string imie;
        int wiek;
        double waga;
        double wzrost;

        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj wiek: ";
        cin >> wiek;
        cout << "Podaj wage: ";
        cin >> waga;
        cout << "Podaj wzrost: ";
        cin >> wzrost;

        uzytkownik.setUserInfo(imie, wiek);
        uzytkownik.setWeight(waga);
        uzytkownik.setHeight(wzrost);

        cout << "Imie: " << uzytkownik.getImie() << endl;
        cout << "Wiek: " << uzytkownik.getWiek() << " lat" << endl;
        cout << "Waga: " << uzytkownik.getWaga() << " kg" << endl;
        cout << "Wzrost: " << uzytkownik.getWzrost() << " cm" << endl;

        Aktywnosc aktywnosc;
        string trening;
        string trybPracy;
        string aktywnoscDzien;

        cout << "Podaj aktywnosc treningowa (niska, srednia, wysoka): ";
        cin >> trening;
        aktywnosc.setTrainingActivity(trening);

        cout << "Podaj tryb pracy (aktywny, siedzacy): ";
        cin >> trybPracy;
        aktywnosc.setWorkMode(trybPracy);

        cout << "Podaj aktywnosc w ciagu dnia (niska, srednia, wysoka): ";
        cin >> aktywnoscDzien;
        aktywnosc.setDayActivity(aktywnoscDzien);

        cout << "Aktywnosc treningowa: " << aktywnosc.getAktywnoscTrening() << endl;
        cout << "Tryb pracy: " << aktywnosc.getTrybPracy() << endl;
        cout << "Aktywnosc w ciagu dnia: " << aktywnosc.getAktywnoscDzien() << endl;

        Cel cel;
        double wagaDocelowa;
        cout << "Podaj wage docelowa: ";
        cin >> wagaDocelowa;
        cel.waga_docelowa = wagaDocelowa;

        cout << "Waga docelowa: " << cel.getWagaDocelowa() << " kg" << endl;
    } else {
        cout << "Haslo nie spelnia wymagan." << endl;
    }

    return 0;
}

