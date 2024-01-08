#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class User {
private:
    string login;
    string haslo;
    string imie;
    int wiek;
    double waga;
    double wzrost;
    string aktywnosc_trening;
    string tryb_pracy;
    string aktywnosc_dzien;
    double waga_docelowa;

public:
    User(const string& username, const string& password) : login(username), haslo(password) {
        wiek = 0;
        waga = 0.0;
        wzrost = 0.0;
        aktywnosc_trening = "";
        tryb_pracy = "";
        aktywnosc_dzien = "";
        waga_docelowa = 0.0;
    }

    // Gettery
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

    string getAktywnoscTrening() const {
        return aktywnosc_trening;
    }

    string getTrybPracy() const {
        return tryb_pracy;
    }

    string getAktywnoscDzien() const {
        return aktywnosc_dzien;
    }

    double getWagaDocelowa() const {
        return waga_docelowa;
    }
//Weryfikacja loginu i hasla----------------------------------------------------------
    bool sprawdz(const string& inputUsername, const string& inputPassword) {
        return (login == inputUsername && haslo == inputPassword);
    }
//Dlugosc hasla i wymagania--------------------------------------------------------
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
//Jesli nie spelnia wymagan-> szansa na poprawe -------------------------------------------------
        if (!maDuzaLitere || !maCyfre) {
            cout << "Haslo musi zawierac przynajmniej 1 dużą litere i 1 cyfre." << endl;
            return false;
        }
        return true;
    }

string poprawneHaslo(const string& password){
        return password;
    }
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

    void setTrainingActivity(const string& activity) {
        aktywnosc_trening = activity;
    }

    void setWorkMode(const string& workMode) {
        tryb_pracy = workMode;
    }

    void setDayActivity(const string& dayActivity) {
        aktywnosc_dzien = dayActivity;
    }

    void setTargetWeight(double targetWeight) {
        waga_docelowa = targetWeight;
    }
//Sprawdzenie poprawnosci wpisanych danych ------------------------------------------
    double calculateBMI() const {
        if (wzrost == 0) {
            cout << "Wprowadź wzrost przed obliczeniem BMI." << endl;
            return 0.0;
        }

        return waga / ((wzrost / 100.0) * (wzrost / 100.0));
    }

    bool isHealthyBMI(double bmi) const {
        if (bmi < 18.5) {
            cout << "Twoje BMI jest zbyt niskie! Sugeruje konsultacje z lekarzem :( ." << endl;
            return false;
        } else if (bmi < 24.9) {
            cout << "Twoje BMI jest prawidlowe! Tak trzymaj! :)" << endl;
            return true;
        } else {
            cout << "Twoje BMI jest zbyt wysokie. Sugeruje konsultacje z lekarzem :( ." << endl;
            return false;
        }
    }
};
//Logowanie-----------------------------------------------------------------------------
void login(User& user) {
    string username, password;
    double targetWeight;
    cout << "Cześć użytkowniku! Witamy na stronie logowania!" << endl;
    cout << "Podaj login: ";
    cin >> username;

    do {
        cout << "Podaj hasło: ";
        cin >> password;
    } while (!user.wymaganiaHasla(password));
//wprowadzanie danych ------------------------------------------------------------------------
    if (user.sprawdz(username, password)) {
        string name;
        int age;

        cout << "Wprowadź imię: ";
        cin >> name;
        cout << "Wprowadź wiek: ";
        cin >> age;

        user.setUserInfo(name, age);

        double weight, height;
        string trainingActivity, workMode, dayActivity;

        cout << "Wprowadź wagę (kg): ";
        cin >> weight;
        user.setWeight(weight);

        cout << "Wprowadź wzrost (cm): ";
        cin >> height;
        user.setHeight(height);

        cout << "Wybierz aktywność treningową (niska, średnia, wysoka): ";
        cin >> trainingActivity;
        user.setTrainingActivity(trainingActivity);

        cout << "Wybierz tryb pracy (aktywny, siedzący): ";
        cin >> workMode;
        user.setWorkMode(workMode);

        cout << "Wybierz aktywność w ciągu dnia (niska, średnia, wysoka): ";
        cin >> dayActivity;
        user.setDayActivity(dayActivity);

        cout << "Wprowadź wagę docelową (kg): ";
        cin >> targetWeight;
        user.setTargetWeight(targetWeight);

    } else {
        cout << "Logowanie nie powiodło się. Sprawdź login i hasło." << endl;
    }
}
//Pokazuje co wpisal uzytkownik----------------------------------------------------------------------
void displayUserInfo(const User& user) {
    cout << "Oto wprowadzone przez Ciebie, " << user.getImie() << " dane! :)" << endl;
    cout << "Imię: " << user.getImie() << endl;
    cout << "Wiek: " << user.getWiek() << " lat" << endl;
    cout << "Waga: " << user.getWaga() << " kg" << endl;
    cout << "Wzrost: " << user.getWzrost() << " cm" << endl;
    cout << "Aktywność treningowa: " << user.getAktywnoscTrening() << endl;
    cout << "Tryb pracy: " << user.getTrybPracy() << endl;
    cout << "Aktywność w ciągu dnia: " << user.getAktywnoscDzien() << endl;


    double bmi = user.calculateBMI();
    cout << "Twoje BMI wynosi: " << bmi << endl;
    user.isHealthyBMI(bmi);

    if (user.getWagaDocelowa() > 0) {
        double bmiTarget = user.calculateBMI();
        cout << "Twoje BMI na podstawie wagi docelowej wynosi: " << bmiTarget << endl;
        user.isHealthyBMI(bmiTarget);
    }
}

//Zapisuje wpisane informacje uzytkownika:
void zapiszDane(const User& user){

    cout<<endl;
    cout<<endl;
    cout << "Zapisane dane uzytkownika:  " << user.getImie() <<endl;
    cout << "Imię: " << user.getImie() << endl;
    cout << "Wiek: " << user.getWiek() << " lat" << endl;
    cout << "Waga: " << user.getWaga() << " kg" << endl;
    cout << "Wzrost: " << user.getWzrost() << " cm" << endl;
    cout << "Aktywność treningowa: " << user.getAktywnoscTrening() << endl;
    cout << "Tryb pracy: " << user.getTrybPracy() << endl;
    cout << "Aktywność w ciągu dnia: " << user.getAktywnoscDzien() << endl;


    double bmi = user.calculateBMI();
    cout << "Twoje BMI wynosi: " << bmi << endl;
    user.isHealthyBMI(bmi);

    if (user.getWagaDocelowa() > 0) {
        double bmiTarget = user.calculateBMI();
        cout << "Twoje BMI na podstawie wagi docelowej wynosi: " << bmiTarget << endl;
        user.isHealthyBMI(bmiTarget);
    }
}

//void zapiszDane();

int main() {
    User user("Markind2", "Mleko1234");
    login(user);
    displayUserInfo(user);
    zapiszDane(user);


    return 0;
}