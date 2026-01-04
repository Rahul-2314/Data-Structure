#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    
    for (int i = binary.size() - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * pow(2, power);
        power++;
    }
    
    return decimal;
}

int main() {
    string binaryNumber = "10110";
    int decimalNumber = binaryToDecimal(binaryNumber);
    
    cout << "Decimal Number: " << decimalNumber << endl;
    
    return 0;
}