
#include <iostream>
#include <unordered_map>
using namespace std;

#define LOG(x){cout<<x<<endl;}

#pragma GCC optimize("Ofast")

int getSum(int n) {
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





int main() {
	int n = 0;
	cin >> n;
	if (!CheckIfSumOfNumsIsPrimary(n)) {
		LOG("BRAK");
	}
}