#include <iostream>
#include <string>

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

// Interfejs budowniczego
class UserBuilder {
public:
    virtual void setUserInfo(const string& inputName, int inputAge) = 0;
    virtual void setWeight(double weight) = 0;
    virtual void setHeight(double height) = 0;
    virtual User build() const = 0;
};

// Konkretny budowniczy dla User
class ConcreteUserBuilder : public UserBuilder {
private:
    User user;

public:
    void setUserInfo(const string& inputName, int inputAge) override {
        user.setUserInfo(inputName, inputAge);
    }

    void setWeight(double weight) override {
        user.setWeight(weight);
    }

    void setHeight(double height) override {
        user.setHeight(height);
    }

    User build() const override {
        return user;
    }
};

// Interfejs budowniczego dla Aktywnosc
class ActivityBuilder {
public:
    virtual void setTrainingActivity(const string& activity) = 0;
    virtual void setWorkMode(const string& workMode) = 0;
    virtual void setDayActivity(const string& dayActivity) = 0;
    virtual Aktywnosc build() const = 0;
};

// Konkretny budowniczy dla Aktywnosc
class ConcreteActivityBuilder : public ActivityBuilder {
private:
    Aktywnosc activity;

public:
    void setTrainingActivity(const string& activity) override {
        this->activity.setTrainingActivity(activity);
    }

    void setWorkMode(const string& workMode) override {
        this->activity.setWorkMode(workMode);
    }

    void setDayActivity(const string& dayActivity) override {
        this->activity.setDayActivity(dayActivity);
    }

    Aktywnosc build() const override {
        return activity;
    }
};

// Interfejs budowniczego dla Cel
class GoalBuilder {
public:
    virtual void setWeightGoal(double weightGoal) = 0;
    virtual Cel build() const = 0;
};

// Konkretny budowniczy dla Cel
class ConcreteGoalBuilder : public GoalBuilder {
private:
    Cel goal;

public:
    void setWeightGoal(double weightGoal) override {
        goal.waga_docelowa = weightGoal;
    }

    Cel build() const override {
        return goal;
    }
};

// Dyrektor - kontroluje proces budowy obiektow
class Director {
public:
    User buildUser(UserBuilder& builder, const string& inputName, int inputAge, double weight, double height) {
        builder.setUserInfo(inputName, inputAge);
        builder.setWeight(weight);
        builder.setHeight(height);
        return builder.build();
    }

    Aktywnosc buildActivity(ActivityBuilder& builder, const string& training, const string& workMode, const string& dayActivity) {
        builder.setTrainingActivity(training);
        builder.setWorkMode(workMode);
        builder.setDayActivity(dayActivity);
        return builder.build();
    }

    Cel buildGoal(GoalBuilder& builder, double weightGoal) {
        builder.setWeightGoal(weightGoal);
        return builder.build();
    }
};

int main() {
    Logowanie logowanie("bozena_nowak", "Mleko231");

    string wprowadzoneHaslo;
    cout << "Podaj haslo: ";
    cin >> wprowadzoneHaslo;

    if (logowanie.wymaganiaHasla(wprowadzoneHaslo)) {
        cout << "Haslo poprawne!" << endl;

        Director director;

        ConcreteUserBuilder userBuilder;
        User uzytkownik = director.buildUser(userBuilder, "Bożena", 30, 65.5, 170.0);

        ConcreteActivityBuilder activityBuilder;
        Aktywnosc aktywnosc = director.buildActivity(activityBuilder, "srednia", "aktywny", "srednia");

        ConcreteGoalBuilder goalBuilder;
        Cel cel = director.buildGoal(goalBuilder, 60.0);


    } else {
        cout << "Haslo nie spelnia wymagan." << endl;
    }

    return 0;
}
