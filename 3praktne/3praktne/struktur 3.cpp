1#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// -----------------------------------------
// Bilietų pardavimų apdorojimas
// -----------------------------------------
void calculateTicketSales() {
    ifstream fin("tickets.txt");
    ofstream fout("ticketResults.txt");

    if (!fin) {
        cout << "Nepavyko atidaryti tickets.txt failo!\n";
        return;
    }

    double price;
    int sold;
    long long totalTickets = 0;
    double totalRevenue = 0.0;

    while (fin >> price >> sold) {
        totalTickets += sold;
        totalRevenue += price * sold;
    }

    cout << fixed << setprecision(2);
    fout << fixed << setprecision(2);

    cout << "\n--- Bilietu pardavimo rezultatai ---\n";
    cout << "Parduota bilietu: " << totalTickets << endl;
    cout << "Bendra pardavimu suma: " << totalRevenue << " EUR\n";

    fout << "Parduota bilietu: " << totalTickets << "\n";
    fout << "Bendra pardavimu suma: " << totalRevenue << " EUR\n";

    cout << "\nRezultatai issaugoti failuose ticketResults.txt\n";
}

// -----------------------------------------
// Atlyginimų skaičiavimas
// -----------------------------------------
void updateSalaries() {
    ifstream fin("salary.txt");
    ofstream fout("newSalary.txt");

    if (!fin) {
        cout << "Nepavyko atidaryti salary.txt failo!\n";
        return;
    }

    string lastName, firstName;
    double currentSalary, increasePercent;

    cout << "\n--- Nauji atlyginimai ---\n";
    fout << fixed << setprecision(2);

    while (fin >> lastName >> firstName >> currentSalary >> increasePercent) {
        double newSalary = currentSalary * (1 + increasePercent / 100.0);

        cout << fixed << setprecision(2);
        cout << lastName << " " << firstName << " " << newSalary << endl;

        fout << lastName << " " << firstName << " " << newSalary << endl;
    }

    cout << "\nRezultatai issaugoti faile newSalary.txt\n";
}

// -----------------------------------------
// Meniu
// -----------------------------------------
int main() {
    int choice;

    do {
        cout << "\n===== MENIU =====\n";
        cout << "1. Skaiciuoti bilietu pardavimus\n";
        cout << "2. Atnaujinti darbuotoju atlyginimus\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkite: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculateTicketSales();
                break;
            case 2:
                updateSalaries();
                break;
            case 0:
                cout << "Programa baigta.\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas!\n";
        }

    } while (choice != 0);

    return 0;
}
