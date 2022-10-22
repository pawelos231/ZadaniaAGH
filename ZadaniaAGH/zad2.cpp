#include <iostream>
#include <vector>
#include <algorithm>

#pragma GCC optimize("Ofast")

using namespace std;

bool checkIfNumberIsComposite(unsigned int &n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return false;

    if (n % 2 == 0 || n % 3 == 0) return true;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return true;

    return false;
}

int main()
{
    int numberOfZeros = 0;
    int numberOfOnes = 0;

    cin >> numberOfZeros >> numberOfOnes;

    vector<bool> vectorOfBinaries;
    for (int i = 0; i < numberOfOnes; i++)
        vectorOfBinaries.push_back(1);

    for (int i = 0; i < numberOfZeros; i++)
        vectorOfBinaries.push_back(0);

    

    auto beginValue = vectorOfBinaries.begin() + 1;
    auto endValue = vectorOfBinaries.end();
    auto VecSize = vectorOfBinaries.size();

    //sortujemy poniewaz tylko taki vector przyjmuje next_permutation ze standardowej bibliotece
    sort(beginValue, endValue);
    int count = 0;

    do {
        unsigned int number = 0;
        for (int i = 0; i < VecSize; i++) {
            number *= 2;
            number |= vectorOfBinaries[i];
        }
        if (checkIfNumberIsComposite(number)) {
            count++;
        }
    } while (next_permutation(beginValue, endValue));
    
    cout << count;

    return 0;
}