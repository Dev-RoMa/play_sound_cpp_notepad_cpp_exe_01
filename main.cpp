#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
    int baseFreq = 400;
    int step = 40;

    ifstream inputFile("notes.txt");
    if (!inputFile) {
        cerr << "Error opening notes.txt\n";
        return 1;
    }

    while (1) {
        int note;
        inputFile >> note;

        if (inputFile.eof()) {
            cout << "End of file reached. Exiting the program.\n";
            break;
        }

        if (note >= 0 && note <= 9) {
            char key = '0' + note;
            cout << "Playing " << note << " sound\n";
            Beep(baseFreq + (note - 1) * step, 1000);
        } else {
            cout << "Invalid note: " << note << "\n";
        }

        Sleep(10);
    }

    inputFile.close();
    return 0;
}