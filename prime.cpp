#include <iostream>
using namespace std;
int main () {
	long counter1 = 2, counter2 = 1, prime, valid, limit = 10000;
	while (counter1 < limit) {
		counter2 = 1;
		prime = 1;
		while (counter2 < counter1) {
			if (counter1%counter2 == 0 && counter2 != 1) {
				counter2 = counter1;
				prime = 0;
			}
			else {
				counter2++;
			}
		}
		if (prime == 1) {
			cout << (double)counter1/limit * 100 << '%';
			valid = counter1;
		}
		counter1++;
	}
	cout << endl << valid << endl;
	return 0;
}
