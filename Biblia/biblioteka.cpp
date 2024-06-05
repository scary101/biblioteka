#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

typedef bool (*ContainsAllCharactersFunc)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "RUS");

    string inputString, searchChars;
    cout << "Введите строку: ";
    std::getline(cin, inputString);
    cout << "Введите символы для поиска: ";
    std::getline(cin, searchChars);
    HINSTANCE load = LoadLibrary(TEXT("DinBiblia.dll"));

    ContainsAllCharactersFunc containsAllCharacters = (ContainsAllCharactersFunc)GetProcAddress(load, "containsAllCharacters");

    bool result = containsAllCharacters(inputString.c_str(), searchChars.c_str());

    if (result) {
        cout << "В строке найден символ" << endl;
    }
    else {
        cout << "В строке не найдено" << endl;
    }

    FreeLibrary(load);

    return 0;
}