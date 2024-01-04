#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <random>

using namespace std;


// funkcja wyswietla wiadomosc i przyjmuje wartosc in
string read_input_str(string message) {
    string in = "";
    cout << message << endl;
    cin >> in;

    return in;
}


// funkcja sprawdza czy str jest liczba calkowita
bool is_int(string str) {
    try {
        stoi(str);
    }

    catch (exception e) {
        return false;
    }

    return true;
}

// sprawdza czy argument jest liczba zmiennoprzecinkowa
bool is_flt(string str) {
    try {
        stof(str);
    }

    catch (exception e) {
        return false;
    }

    return true;
}

// funkcja sprawdza czy argument int jest ujemny
bool is_negative_int(int arg) {
    if (arg >= 0) return false;
    else return true;
}


// funkcja sprawdza czy argument float jest ujemny
bool is_negative_flt(float arg) {
    if (arg >= 0) return false;

    else return true;
}


// program wczytuje nieujemna liczbe calkowita.
int read_int_positive(string message) {
    string n;

    while (true) {
        string n = read_input_str(message);

        if (is_int(n)) {
            int n_int = stoi(n);

            if (!is_negative_int(n_int)) return n_int;
            else printf("Liczba %i jest ujemna.\n", n_int);
        }

        else cout << ("Wprowadzona wartosc nie jest prawidlowa.\n");
    }

    return -1;
}


// odczytuje i zwraca zmienna typu float
float read_flt(string message) {
    string n;
    bool truth = false;

    cout << message;

    do {
        cin >> n;

        if (!is_flt(n)) cout << "Wprowadzona wartosc nie jest prawidlowa.\n";
        else truth = true;

    } while(!truth);

    return stof(n);
}

// odczytuje i zwraca dodatnia zmienna typu float
float read_flt_positive(string message) {
    string n;
    bool truth = false;

    cout << message;

    do {
        cin >> n;

        if (!is_flt(n)) cout << "Wprowadzona wartosc nie jest prawidlowa.\n";
        else truth = true;

    } while(!truth);

    if (is_negative_flt(stof(n))) {
        cout << "Wartosci ujemne beda zamienione na dodatnie.\n";
        return abs(stof(n));
    }

    return stof(n);
}

// oblicza i zwracaja pole powierzchni trapezu:
float zadanie1(float a, float b, float h) {
    cout << "Program oblicza i zwraca pole powierzchni trapezu.\n";
    float y = (a + b) / 2 * h;
    printf("Pole trapezu wynosi %0.2f.\n\n", y);
    return y;
}

void zadanie2(float x) {
    cout << "Program oblicza wartość funkcji y(x) w punkcie x.\n";
    double y = 0;
    if (x < 0) y = (0.5 * (x * x) + 1.0/3 * x);
    else if (x <= 6) y = (sin(x) + 1.0);
    else y = (x + 3.0);

    printf("Wartosc funkcji f(x) w punkcie %0.2f wynosi %0.2f.\n\n", x, y);
}

array<int, 2> coinToss(int x) {
    cout << "Program symuluje rzut monetą n podanych razy.";

    int o = 0;
    int r = 0;
    // https://learn.microsoft.com/pl-pl/cpp/standard-library/random?view=msvc-170
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 2);
    for (int i = 0; i < x; i++) {
        if (dist(gen) != 1) {
            r++;
            cout << "Reszka\n";
        }

        else {
            o++;
            cout << "Orzel\n";
        }
    }

    return {r, o};
}

bool triangable(float a, float b, float c) {
    if ((a + b > c) and (b + c > a) and (a + c > b)) return true;

    return false;
}

double area_of_triangle(float a, float b, float c) {
    return (sqrt((0.5 * (a + b + c)) * ((0.5 * (a + b + c) - a)) * ((0.5 * (a + b + c) - b)) * ((0.5 * (a + b + c) - c))));
}

int main() {
    while (true) {
        cout << "Opcje:\n";
        cout << "1. Zadanie 1.4.1. - pole trapezu\n";
        cout << "2. Zadanie 1.4.2. - wartosc funkcji w punkcie\n";
        cout << "3. Zadanie 1.4.3. - rzut moneta\n";
        cout << "4. Zadanie 1.4.4. - pole trojkata z odcinkow\n";
        cout << "5. Wyjscie.\n\n";

        int opt = read_int_positive("Wprowadz numer opcji [od 0 - 5].\n");

        switch (opt) {
            case 1:
                zadanie1(read_flt_positive("Wprowadz dlugosc podstawy a [dodatnia liczba rzeczywista].\n"), read_flt_positive("Wprowadz dlugosc podstawy b [dodatnia liczba rzeczywista].\n"), read_flt_positive("Wprowadz wysokosc trapezu [dodatnia liczba rzeczywista].\n"));
                break;

            case 2:
                zadanie2(read_flt("Wprowadz liczbe rzeczywista.\n"));
                break;

            case 3: {
                array<int, 2> res = {0, 0};
                res = coinToss(read_int_positive("Ile ma byc rzutow moneta? Podaj dodatnia liczbe calkowita.\n"));
                printf("Reszka wypadla %d razy, orzel wypadl %d razy.\n", res[0], res[1]);

//                if (res[0] > res[1]) cout << "Reszka wygrala.\n";
//                else if (res[0] == res[1]) cout << "Remis.\n";
//                else cout << "Orzel wygral.\n";
//
//                cout << endl;
                break;
            }
            
            case 4: {
                float a = read_flt_positive("Podaj dlugosc odcinka a [dodatnia liczba calkowita].\n");
                float b = read_flt_positive("Podaj dlugosc odcinka b [dodatnia liczba calkowita].\n");
                float c = read_flt_positive("Podaj dlugosc odcinka c [dodatnia liczba calkowita].\n");

                if (triangable(a, b, c)) printf("Pole trojkata wynosi: %0.2f cm.\n\n", area_of_triangle(a, b, c));
                else cout << "Z podanych odcinkow nie mozna stworzyc trojkata.\n\n";
                break;
            }

            case 5:
                exit(1);

            default:
                cout << "Brak wybranej opcji.\n";
                break;
        }
    }

    return 0;
}
