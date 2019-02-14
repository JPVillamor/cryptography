#include <iostream>
using namespace std;
int main () {
	long c1 = 2, c2 = 1, limit, prime, valid = 0;
	cout << "Upper bound: ";
	cin >> limit;
    while (valid == 0) {
        c2 = 1;
        prime = 1;
        while (c2 < limit) {
            if (limit%c2 == 0 && c2 != 1) {
                c2 = limit;
                prime = 0;
            }
            else
                c2++;
        }
        if (prime == 1)
            valid = limit;
        else {
            cout << limit << " is not prime" << endl;
            limit--;
        }
    }
	cout << limit << " is prime" << endl;
	return 0;
}
