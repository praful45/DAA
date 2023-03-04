//4.3 WAP to generate a list of strings representing binary numbers from 0 to 15.

#include <iostream>
#include <string>
#include<bitset>

using namespace std;

int main() {
    for (int i = 0; i <=15; i++) {
        string binary = bitset<4>(i).to_string();
        cout<<binary<<endl;
    }
    return 0;
}

