#include <iostream>
#include <string>

#include "DiceRoller.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    // main() will eventually parse input and
    // manipulate Die class as needed

    bool again = true;
    string rollInput = "";
    vector<string> splitInput;

    do {
        cout << "Dice rolls in format of \"# d# [# d#...]\"\n"
             << "Press ENTER without typing anything to quit." << endl;
        cin >> rollInput;

        splitInput = ParseRollInput(rollInput);

    } while (again);

    system("pause");
}

vector<string> ParseRollInput(string Input)
{
    vector<string> splitInput;
    string currToken = "";
    bool encounteredFirst = false;

    // TODO:
    // -- Validate while parsing

    for (int i = 0; i < Input.size(); i++) {
        if (Input[i] == ' ') {
            if (encounteredFirst) {
                splitInput.push_back(currToken);
            }
        } else {
            if (!encounteredFirst) encounteredFirst = true;
            currToken += Input[i];
        }
    }

    return splitInput;
}