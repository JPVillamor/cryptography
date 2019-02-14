#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
int main () {
	vector<char>pw; int plength; int hun[100]; int num[10]; int caps[26]; int lower[26];
	cout << "password length: ";
	cin >> plength;
	srand(time(NULL));
	for (int b = 0; b < plength; b++) {
		//set 0-99
		for (int a = 0; a < 100; a++) {
			hun[a] = a;
		}
		//shuffle 0-99
		for (int i = 0; i < 100; i++) {
			int index = rand() % 100;
			int temp = hun[i];
			hun[i] = hun[index];
			hun[index] = temp;
		}
		if (hun[1] <= 49) {
			char integer; 
			for (int q = 0; q < 10; q++) {
			num[q] = q + 48;
			}
			for (int c = 0; c < 10; c++){
				int windex = rand() % 10;
				int temp1 = num[c];
				num[c] = num[windex];
				num[windex] = temp1;
			}
			integer = num[1];
			pw.push_back(integer); //char will be a number 
		}
		else {
			char letter;
			if (hun[10] <= 49) {
				for (int w = 0; w < 26; w++) {
				caps[w] = w + 65;
				}
				for (int d = 0; d < 26; d++) {
					int index2 = rand() % 26;
					int temp2 = caps[d];
					caps[d] = caps[index2];
					caps[index2] = temp2;
				}
				letter = caps[1]; //char will be a capital letter
			}
			else {
				for (int f = 0; f < 26; f++) {
				lower[f] = f + 97;
				}
				for (int e = 0; e < 26; e++) {
					int index3 = rand() % 26;
					int temp3 = lower[e];
					lower[e] = lower[index3];
					lower[index3] = temp3;
				}
				letter = lower[1]; //char will be a lowercase letter
			}
			pw.push_back(letter);
		}
	}
	for (int z = 0; z < plength; z++) {
		cout << pw[z];
	}
	return 0;
}
