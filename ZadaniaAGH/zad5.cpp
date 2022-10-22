#include <iostream>
#include <vector>

#pragma GCC optimize("Ofast")
using namespace std;

struct LandMpair {
    int licznik;
    int mianownik;
};

bool isNumbersEqual(LandMpair other, LandMpair main) {
    int a = main.licznik;
    int b = main.mianownik;
    int c = other.licznik;
    int d = other.mianownik;

    return (a * d - b * c) == 0;
}


LandMpair divideNumbers(LandMpair other, LandMpair main) {
    return LandMpair{
        main.licznik* other.mianownik, 
        main.mianownik* other.licznik
    };
}

int main()
{
    int numberOfNumbers = 0;
    cin >> numberOfNumbers;

    vector<LandMpair> vectorOfSeq;

    for (int i = 0; i < numberOfNumbers; i++) {
        int licznik = 0;
        int mianownik = 0;
        cin >> licznik >> mianownik;
        vectorOfSeq.push_back(LandMpair{licznik,mianownik});
    }

    short curr = 0;
    int maxLength = 0;

    int lengthOfCurrSeq = 0;

    LandMpair q;
    LandMpair first;
    LandMpair second;
    LandMpair third;

    while (curr != vectorOfSeq.size() && curr + lengthOfCurrSeq + 2 < vectorOfSeq.size()) {
        first = vectorOfSeq[curr + lengthOfCurrSeq];
        second = vectorOfSeq[curr + lengthOfCurrSeq + 1];
        third = vectorOfSeq[curr + lengthOfCurrSeq + 2];
        q = divideNumbers(first, second);
        LandMpair nextValue = divideNumbers(second, third);
        if (isNumbersEqual(nextValue, q)) {
            lengthOfCurrSeq++;
        }
        else {
            curr++;
            lengthOfCurrSeq = 0;
        }
        if (lengthOfCurrSeq > maxLength)
            maxLength = lengthOfCurrSeq;
    }

    maxLength += 2;
    if (maxLength < 3) {
        cout << "BRAK";
    }
    else {
        cout << maxLength;
    }

    return 0;
}
