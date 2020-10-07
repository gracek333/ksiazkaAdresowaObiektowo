#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <sstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string wczytajLinie();
    static char wczytajZnak();
    static int wczytajLiczbeCalkowita();
};

#endif
