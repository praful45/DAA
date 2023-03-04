//wap to print binary strings of 4-bot length without consecutives 0's
#include <iostream>
#include <cstring>

using namespace std;

// Function to print all binary strings of length n without consecutive 0s
void generateBinaryStrings(int n, char str[], int index) {
    if (index == n) {
        cout << str << " ";
        return;
    }
    str[index] = '1';
    generateBinaryStrings(n, str, index + 1);
    if (index == 0 || str[index - 1] != '0') {
        str[index] = '0';
        generateBinaryStrings(n, str, index + 1);
    }
}

int main() {
    int n = 4;
    char str[n + 1];
    memset(str, '\0', sizeof(str));
    generateBinaryStrings(n, str, 0);
    return 0;
}

