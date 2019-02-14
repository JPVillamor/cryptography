#include <iostream>
#include <string>
using namespace std;
void makeChart (char ary[][5], string word) {
    string alphabet = "abcdefghiklmnopqrstuvwxyz", newKey = "";
    for (int i = 0; i < word.length(); i++){
        if (newKey.find(word[i]) == -1) {
            newKey += word[i];
        }
    }
    for (int i = 0; i < alphabet.length(); i++) {
        if (newKey.find(alphabet[i]) == -1) {
            newKey += alphabet[i];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ary[i][j] = newKey[5*i+j];
        }
    }
}
string encrypt (char ary[][5], string plain) {
    string code = "";
    for (int i = 0; i < plain.length(); i+=2) {
        int r1, r2, r3, r4, c1, c2, c3, c4;
        char temp1 = plain[i], temp2 = plain[i+1];
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (ary[r][c] == temp1) {
                    r1 = r;
                    c1 = c;
                }
                if (ary[r][c] == temp2) {
                    r2 = r;
                    c2 = c;
                }
            }
        }
        if (r1 == r2) {
            c3 = c1+1;
            c4 = c2+1;
            if (c3 == 5)
                c3 = 0;
            if (c4 == 5)
                c4 = 0;
            code += ary[r1][c3];
            code += ary[r1][c4];
        }
        else if (c1 == c2) {
            r3 = r1+1;
            r4 = r2+1;
            if (r3 == 5)
                r3 = 0;
            if (r4 == 5)
                r4 = 0;
            code += ary[r3][c1];
            code += ary[r4][c1];
        }
        else {
            code += ary[r1][c2];
            code += ary[r2][c1];
        }
    }
    return code;
}
string decrypt (char ary[][5], string code) {
    string plain = "";
    for (int i = 0; i < code.length(); i+=2) {
        int r1, r2, r3, r4, c1, c2, c3, c4;
        char temp1 = code[i], temp2 = code[i+1];
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (ary[r][c] == temp1) {
                    r1 = r;
                    c1 = c;
                }
                if (ary[r][c] == temp2) {
                    r2 = r;
                    c2 = c;
                }
            }
        }
        if (r1 == r2) {
            c3 = c1-1;
            c4 = c2-1;
            if (c3 == -1)
                c3 = 4;
            if (c4 == -1)
                c4 = 4;
            plain += ary[r1][c3];
            plain += ary[r1][c4];
        }
        else if (c1 == c2) {
            r3 = r1-1;
            r4 = r2-1;
            if (r3 == -1)
                r3 = 4;
            if (r4 == -1)
                r4 = 4;
            plain += ary[r3][c1];
            plain += ary[r4][c1];
        }
        else {
            plain += ary[r1][c2];
            plain += ary[r2][c1];
        }
    }
    return plain;
}
int main () {
    char chart[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            chart[i][j] = '$';
        }
    }
    string keyword = "NULL";
    int option = 0;
    while (option != 4) {
        cout << "[1] new keyword" << endl;
        cout << "[2] encrypt" << endl;
        cout << "[3] decrypt" << endl;
        cout << "[4] exit" << endl;
        cout << " I: ";
        cin >> option;
        if (option == 1) {
            cout << "keyword: ";
            cin.ignore();
            getline(cin, keyword);
            for (int i = 0; i < keyword.length(); i++) {
                if (keyword[i] == 'j') {
                    keyword[i] == 'i';
                }
            }
            makeChart(chart, keyword);
        }
        else if (option == 2) {
            string input = " ";
            cin.ignore();
            do {
                cout << "message: ";
                getline(cin, input);
            }
            while (input.length()%2 != 0);
            if (keyword != "NULL") {
                for (int i = 0; i < input.length(); i++) {
                    if (input[i] == 'j') {
                        input[i] == 'i';
                    }
                }
                cout << encrypt(chart, input) << endl;
            }
            else {
                cout << "need a keyword" << endl;
            }
        }
        else if (option == 3) {
            string input = " ";
            cin.ignore();
            do {
                cout << "message: ";
                getline(cin, input);
            }
            while (input.length()%2 != 0);
            if (keyword != "NULL") {
                for (int i = 0; i < input.length(); i++) {
                    if (input[i] == 'j') {
                        input[i] == 'i';
                    }
                }
                cout << decrypt(chart, input) << endl;
            }
            else {
                cout << "need a keyword" << endl;
            }
        }
    }
    return 0;
}
