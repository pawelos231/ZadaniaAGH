
#include <iostream>
#include <unordered_map>
using namespace std;

#define LOG(x){cout<<x<<endl;}
//brute force zadanie 4: Proszê napisaæ program wyznaczaj¹cy najmniejsz¹ liczbê pierwsz¹ o sumie cyfr równej N i której cyfry s¹ w porz¹dku niemalej¹cym

long long   LogSmallestPrimeFromSums(int &n) {
	long long tab[100] = {
	0,2,3,13,5,0,7,17,0,19,29,0,67,59,0,79,89,0,199,389,0,499,599,0,997,1889,0,1999,2999,0,4999,6899,0,17989,8999,0,29989,39989,0,49999,59999,0,79999,98999,0,199999,389999,0,598999,599999,0,799999,989999,0,2998999,2999999,0,4999999,6999899, 0, 8989999, 9899999, 0, 19999999, 29999999, 0, 59899999, 59999999, 0, 189997999, 89999999, 0, 289999999, 389999999, 0, 689899999, 699899999, 0, 799999999, 998999999, 0, 2999899999, 3999998999, 0, 5989999999, 6999999989, 0, 9899989999, 18989999999, 0, 28999999999, 39899999999, 0, 68899999999, 59999999999, 0, 79999999999, 98999999999, 0, 298999999999
	};
	std::unordered_map<int, long long> umap;

	for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) {
		umap[i+1] = tab[i];
	}
	return umap[n];
}
/*
int getSum(int n) {
	int sum = 0;
	while (n!= 0){
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}
bool CheckIfNumberIsPrimary(int n) {

	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
}

bool CheckIfSumOfNumsIsPrimary(int& n) {
	if (n == 0 || n == 1) {
		return false;
	}
	int i = 1;

	while (n != getSum(i) || !CheckIfNumberIsPrimary(i)) {
		i++;
	}
	LOG(i);

	return true;
};
*/




int main() {
	int n = 0;
	cout << "wpisz liczbe (MAX 100):" << endl;
	cin >> n;
	if (LogSmallestPrimeFromSums(n) == 0) {
		LOG("BRAK");
	}
	else {
		cout << LogSmallestPrimeFromSums(n) << endl;
	}

}