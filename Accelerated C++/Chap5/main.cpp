#include <iostream>
#include "main.h"
#include <string>

using namespace std;

int main() {

    string s;

    getline(cin, s);
        //cout << s;

    vector<string> string_split = split(s);

    for (vector<string>::const_iterator i = string_split.begin(); i != string_split.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;

}