#include <string>
#include <iostream>

using namespace std;

int charToInt(char digit) {
    return (int)(digit - 48);
}

char intToChar(int digit) {
    return (char)(digit + 48);
}

string sum(string num1, string num2) {
    int n1Length = num1.length();
    int n2Length = num2.length();
    int length = (n1Length > n2Length ? n1Length : n2Length) + 1;

    int inum1[length];
    int inum2[length];
    int iresult[length];

    bool isTen = false;

    for(int i = 0; i < (length - n1Length); i++) {
        inum1[i] = 0;
    }
    for(int i = 0; i < n1Length; i++) {
        inum1[i + (length - n1Length)] = charToInt(num1[i]);
    }

    for(int i = 0; i < (length - n2Length); i++) {
        inum2[i] = 0;
    }
    for(int i = 0; i < n2Length; i++) {
        inum2[i + (length - n2Length)] = charToInt(num2[i]);
    }

    for(int i = length-1; i >= 0; i--) {
        if(isTen) {
            iresult[i] = inum1[i] + inum2[i] + 1;
        } else {
            iresult[i] = inum1[i] + inum2[i];
        }
        isTen = false;

        if(iresult[i] >= 10) {
            iresult[i] -= 10;
            isTen = true;
        }
    } 

    string result = "";

    for(int i = iresult[0] == 1 ? 0 : 1; i < length; i++) {
        result.append(1, intToChar(iresult[i]));
    }

    return result;
}

// if num1 >= num2, return true
bool compare(string num1, string num2) {
    int n1Length = num1.length();
    int n2Length = num2.length();

    if(n1Length > n2Length) {
        return true;
    } else if(n1Length < n2Length) {
        return false;
    }

    for(int i = 0; i < n1Length; i++) {
        if(num1[i] < num2[i]) {
            return false;
        }
    }

    return true;
}

string sub(string num1, string num2) {
    int n1Length = num1.length();
    int n2Length = num2.length();
    int length = n1Length > n2Length ? n1Length : n2Length;

    int inum1[length];
    int inum2[length];
    int iresult[length]; 

    bool isMinus = !compare(num1, num2);
    bool needTen = false;

    if(isMinus) {
        for(int i = 0; i < (length - n2Length); i++) {
            inum1[i] = 0;
        }
        for(int i = 0; i < n2Length; i++) {
            inum1[i + (length - n2Length)] = charToInt(num2[i]);
        }

        for(int i = 0; i < (length - n1Length); i++) {
            inum2[i] = 0;
        }
        for(int i = 0; i < n1Length; i++) {
            inum2[i + (length - n1Length)] = charToInt(num1[i]);
        }
    } else {
        for(int i = 0; i < (length - n1Length); i++) {
            inum1[i] = 0;
        }
        for(int i = 0; i < n1Length; i++) {
            inum1[i + (length - n1Length)] = charToInt(num1[i]);
        }

        for(int i = 0; i < (length - n2Length); i++) {
            inum2[i] = 0;
        }
        for(int i = 0; i < n2Length; i++) {
            inum2[i + (length - n2Length)] = charToInt(num2[i]);
        }
    }

    for(int i = length-1; i >= 0; i--) {
        if(needTen) {
            inum1[i]--;
            needTen = false;
        }
        if(inum1[i] < inum2[i]) {
            needTen = true;
            inum1[i] += 10;
        }
        iresult[i] = inum1[i] - inum2[i];
    }

    string result = isMinus ? "-" : "";
    bool isZero = true;

    for(int i = 0; i < length; i++) {
        if(isZero) {
            if(iresult[i] == 0) {
                continue;
            } else {
                isZero = false;
            }
        }
        result.append(1, intToChar(iresult[i]));
    }

    return isZero ? "0" : result;
}
