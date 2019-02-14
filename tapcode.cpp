#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void isPrime(unsigned long long int limit) {
    unsigned long long int c = 1, prime, valid = 0;
    while (valid == 0) {
        c = 1;
        prime = 1;
        while (c < limit) {
            if (limit%c == 0 && c != 1) {
                prime = 0;
                break;
            }
            else
                c++;
        }
        if (prime == 1)
            valid = limit;
        else {
            cout << limit << " is not prime" << endl;
            limit--;
        }
    }
	cout << limit << " is prime" << endl;
}
int main () {
    string alphabet = "abcdefghiklmnopqrstuvwxyz";
    char chart[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            chart[i][j] = alphabet[5*i+j];
            cout << chart[i][j];
        }
        cout << endl;
    }

    string plaintext;
    cout << "plaintext: ";
    getline(cin, plaintext);

    char buffer[256];
    string code = "";
    for (int i = 0; i < plaintext.length(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (chart[j][k] == plaintext[i]) {
                    itoa(j+1, buffer, 10);
                    code += buffer;
                    itoa(k+1, buffer, 10);
                    code += buffer;
                }
            }
        }
    }
    cout << code << endl;
    return 0;
}
