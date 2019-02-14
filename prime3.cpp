#include <iostream>
using namespace std;
unsigned long long int input() {
    unsigned long long int limit;
    cout << "Upper bound: ";
	cin >> limit;
	return limit;
}
void isPrime(unsigned long long int limit) {
    unsigned long long int c = 1, prime, valid = 0;
    while (valid == 0) {
        c = 2;
        prime = 1;
        while (c < limit) {
            if (limit%c == 0) {
                prime = 0;
                break;
            }
            else {
                if (c == 2)
                    c++;
                else
                    c+=2;
            }
        }
        if (prime == 1)
            valid = limit;
        else {
            cout << limit << " is not prime; div. by " << c << endl;
            limit--;
        }
    }
	cout << limit << " is prime" << endl;
}
int main () {
	isPrime(input());
	return 0;
}
