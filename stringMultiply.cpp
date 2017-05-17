#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define  ASCII_MIN 48
#define  ASCII_MAX 57
using namespace std;

vector <char> mult (vector<char> a, vector<char> b) {
    
    vector <char> result;
    
    for (int i = 0; i < a.size() + b.size(); i++) {
        result.push_back('0');
    }
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int digit1 = a[a.size()-1-i] - ASCII_MIN;
            int digit2 = b[b.size()-1-j] - ASCII_MIN;
            int x = digit1 * digit2;
            int tens = (x / 10);
            int ones = (x % 10);
            result [result.size()-1-i-j] += ones;
            if (result [result.size()-1-i-j] > ASCII_MAX) {
                result [result.size()-1-i-j] -= 10;
                result [result.size()-2-i-j] += 1;
            }
            result [result.size()-2-i-j] += tens;
            if (result [result.size()-2-i-j] > ASCII_MAX) {
                result [result.size()-2-i-j] -= 10;
                result [result.size()-3-i-j] += 1;
            }
        }
    }
    
    while (result[0] == '0') {
        result.erase(result.begin());
    }
    
    return result;
    
}

vector <char> convert (int x) {
    vector <char> result;
    while (x > 0) {
        char toInsert = x % 10 + ASCII_MIN;
        result.insert (result.begin(), toInsert);
        x = x / 10;
    }
    return result;
}

void printVector (vector<char> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }
    cout << '\n';
}

int main(){
    int n;
    cin >> n;
    
    vector<char> fact;
    fact.push_back ('1');
    
    while (n > 1) {
        vector <char> nVect;
        nVect = convert(n);
        fact = mult (fact, nVect);
        n--;
    }
        
    printVector (fact);
    return 0;
}