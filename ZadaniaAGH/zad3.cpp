#include <iostream>
#include <limits.h>

#pragma GCC optimize("Ofast")
using namespace std;

struct Pair {
	bool found;
	int value;
};

Pair findLongestPathUtil(int** arr, int n, int i, int j, bool** visited)
{

	if (i == n - 1 && j ==  n - 1) {
		Pair p;
		p.found = true;
		p.value = 0;
		return p;
	}

	if (i < 0 || i >= n || j < 0 || j >= n || arr[i][j] == 0
		|| visited[i][j]) {
		Pair p;
		p.found = false;
		p.value = INT_MAX;
		return p;
	}

	visited[i][j] = true;

	int res = INT_MIN;

	Pair solutionIndex = findLongestPathUtil(arr, n, i, j + 1, visited);

	if (solutionIndex.found) {
		res = std::max(res, solutionIndex.value);
	}
	solutionIndex = findLongestPathUtil(arr, n, i - 1, j, visited);

	if (solutionIndex.found) {
		res = std::max(res, solutionIndex.value);
	}
	solutionIndex = findLongestPathUtil(arr, n, i + 1, j, visited);

	if (solutionIndex.found) {
		res = std::max(res, solutionIndex.value);
	}

	visited[i][j] = false;

	if (res != INT_MIN) {
		Pair p;
		p.found = true;
		p.value = 1 + res;
		return p;
	}
	else {
		Pair p;
		p.found = false;
		p.value = INT_MAX;
		return p;
	}
}

int main()
{
	int numberOfValues = 0;
	cin >> numberOfValues;

	int** MatrixOfValues = new int* [numberOfValues];
	for (int i = 0; i < numberOfValues; i++) {
		MatrixOfValues[i] = new int[numberOfValues];
		for (int j = 0; j < numberOfValues; j++) {

			char c;
			cin >> c;
			if (c == '#')
				MatrixOfValues[i][j] = 0;

			else MatrixOfValues[i][j] = 1;
		}
	}

	bool** visited = new bool* [numberOfValues];

	for (int i = 0; i < numberOfValues; i++) {
		visited[i] = new bool[numberOfValues];
		for (int j = 0; j < numberOfValues; j++)
			visited[i][j] = false;
	}

	Pair pair = findLongestPathUtil(MatrixOfValues, numberOfValues, 0, 0, visited);

	if (pair.found) {
		cout << pair.value;
	}
	else {
		cout << "BRAK";
	}

	return 0;
}