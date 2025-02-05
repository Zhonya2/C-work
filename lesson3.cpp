#include <iostream>
using namespace std;
int main() {
    char sentence[3];

    cout << "Enter sentence: ";
    cin.getline(sentence, 3);

    cout << "Your word:" << sentence << endl;

    return 0;
}