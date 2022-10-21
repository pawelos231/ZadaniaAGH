#include <iostream>
#include <unordered_map>
#include <string>
#define LOG(x){cout<<x<<endl;}

using namespace std;

 
int chuj() {
	int mianownik = 0, licznik = 0;
	cin >> licznik >> mianownik;

	string res = "";
	res += to_string(licznik / mianownik);
	int remaiding = licznik % mianownik;

	if (remaiding == 0) {
		cout << res;
		return 0;
	}

	res += '.';
	unordered_map<int, int> mapOfDecimalExp;
	while (remaiding > 0) {
		if (mapOfDecimalExp.find(remaiding) != mapOfDecimalExp.end()) {
			res += ")";
			res.insert(mapOfDecimalExp[remaiding], "(");
			break;
		}
		else {
			mapOfDecimalExp[remaiding] = res.size();
		}
		remaiding *= 10;
		res += to_string(remaiding / mianownik);
		remaiding = remaiding % mianownik;
	}
	cout << res;
	return 0;
}