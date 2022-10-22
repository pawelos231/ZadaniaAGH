
#include <iostream>
#include <unordered_map>
using namespace std;

#define LOG(x){cout<<x<<endl;}

#pragma GCC optimize("Ofast")

//Zgodnie z oswiadczeniem jednej z osob odpowiedzialnych za zadania, mozemy posiadac preprocesowana wczesniej tablice zawierajaca owczesnie wygenerowane liczby pierwsze

long long   LogSmallestPrimeFromSums(int& n) {
    long long tab[100] = {
        0, 2, 3,13, 5,0, 7,17,0,19,29,0,67,59,0,79,89,0,199,389,0,499,599,0,1699,1889,0,1999,2999,0,4999,6899,0,25999,8999,0,48889,56999,0,49999,59999,0,79999,179999,0,199999,389999,0,679999,599999,0,799999,1799999,0,4789999,2999999,0,4999999,7799999,0,16999999,18899999,0,19999999,29999999,0,77899999,59999999,0,268999999,89999999,0,289999999,389999999,0,778999999,779999999,0,799999999,2888999999,0,12889999999,4799999999,0,17888899999,25889999999,0,16999999999,37889999999,0,28999999999,146999999999,0,68899999999,59999999999,
        0,79999999999,269999999999,0,488899999999
    };
	std::unordered_map<int, long long> umap;

	for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) {
		umap[i + 1] = tab[i];
	}
	return umap[n];
}
/*
int getSum(int &n) {
	int sum = 0;
	while (n!= 0){
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}
bool valid(unsigned long long n) {
	unsigned long long temp = n % 10;
	while (n / 10 > 0)
	{
		n /= 10;
		if (temp < n % 10)
			return false;
		temp = n % 10;
	}
	return true;
}
bool CheckIfNumberIsPrimary(int n)
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

bool CheckIfSumOfNumsIsPrimary(int& n) {
	if (n == 0 || n == 1) {
		return false;
	}
	int i = 1;
	if (n % 3 == 0 && n != 3) {
		return false;
	}
	while (!valid(i) || n != getSum(i) || !CheckIfNumberIsPrimary(i)) {
		i++;
	}
	LOG(i);
	return true;
};
*/





int main() {
	int n = 0;
	cin >> n;

	if (!LogSmallestPrimeFromSums(n)) {
		cout << "BRAK";
	}
	else {
		cout << LogSmallestPrimeFromSums(n) << endl;
	}

	return 0;
}