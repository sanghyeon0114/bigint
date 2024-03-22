#include <iostream>
#include <string>

using namespace std;

int charToInt(char digit);
char intToChar(int digit);
string sum(string num1, string num2);
string sub(string num1, string num2);

int main() {
    string num1;
    string num2;
    
    cout << "First number\t>> ";
    cin >> num1;
    cout << "Second number\t>> ";
    cin >> num2;

    // Sum Function
    cout << "Sum\t\t>> " << sum(num1, num2) << endl;
    // Sub Function
    cout << "Sub\t\t>> " << sub(num1, num2) << endl;
    return 0;
}