#include <iostream>
#include <vector>
#include <algorithm>

#pragma GCC optimize("Ofast")

using namespace std;

bool CheckIfNumberIsPrimary(int &n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}


bool composite(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return false;

    if (n % 2 == 0 || n % 3 == 0) return true;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return true;

    return false;
}

unsigned int convert(vector<bool>& v) {
    unsigned int result = 0;
    for (int i = 0; i < v.size(); i++) {
        result *= 2;
        result |= v[i];
    }
    return result;
}

int main()
{
    int numberOfZeros = 0;
    int numberOfOnes = 0;

    cin >> numberOfZeros >> numberOfOnes;

    vector<bool> vectorOfPossibleSol;
    for (int i = 0; i < numberOfOnes; i++)
        vectorOfPossibleSol.push_back(1);

    for (int i = 0; i < numberOfZeros; i++)
        vectorOfPossibleSol.push_back(0);


    sort(vectorOfPossibleSol.begin() + 1, vectorOfPossibleSol.end());


    int count = 0;

    while (next_permutation(vectorOfPossibleSol.begin() + 1, vectorOfPossibleSol.end())) {
        int number = convert(vectorOfPossibleSol);
        if (composite(number)) {
            count++;
        }
    
    };
    cout << count;

    return 0;
}