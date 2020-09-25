#include "UzytkownikMenedzer.h"
void UzytkownikMenedzer :: wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenedzer :: rejestracjaUzytkownika()
{
    system("cls");
    cout << endl << "Rejestracja uzytkownika: " << endl << endl;

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer :: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer :: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer :: czyIstniejeLogin(string login)
{
    for (int i = 0; i< uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer :: wypiszWszystkichUzytkownikow()
{
    system("cls");
    cout << endl << "Wszyscy uzytkownicy: " << endl << endl;
    for (int i = 0; i< uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl << endl;
    }
    system("pause");
}

void UzytkownikMenedzer :: logowanieUzytkownika()
{
    system("cls");
    cout << endl << "Logowanie uzytkownika: " << endl << endl;
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    ustawIdZalogowanegoUzytkownika(uzytkownicy[i].pobierzId());
                    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzIdZalogowanegoUzytkownika(), idOstatniegoAdresata);
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl << endl;
            system("pause");
            ustawIdZalogowanegoUzytkownika(0);
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    ustawIdZalogowanegoUzytkownika(0);
}

void UzytkownikMenedzer :: ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
    if (noweIdZalogowanegoUzytkownika >= 0)
        idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

void UzytkownikMenedzer :: zmianaHaslaZalogowanegoUzytkownika()
{
    system("cls");
    cout << endl << "Zmiana hasla: " << endl << endl;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == pobierzIdZalogowanegoUzytkownika())
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenedzer :: pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer :: wyloguj()
{
    system("cls");
    ustawIdZalogowanegoUzytkownika(0);
    cout << endl << "Wylogowano!" << endl << endl;
    system("pause");
}

void UzytkownikMenedzer :: wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void UzytkownikMenedzer :: dodajAdresata()
{
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}
