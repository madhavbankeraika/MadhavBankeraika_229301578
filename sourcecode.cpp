#include <bits/stdc++.h>
using namespace std;

// Function to convert a string number from any base to decimal (BigInteger as string)
long long convertToDecimal(const string &value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = tolower(c) - 'a' + 10;
        else digit = 0;
        result = result * base + digit;
    }
    return result;
}

int main() {
    // Sample JSON-like input (you can later replace it with file reading & JSON parsing)
    int n = 4, k = 3;
    vector<pair<int,string>> inputs = {
        {10, "4"}, {2, "111"}, {10, "12"}, {4, "213"}
    };

    // Step 1: Take first k roots and convert
    vector<long long> roots;
    for (int i = 0; i < k; i++) {
        roots.push_back(convertToDecimal(inputs[i].second, inputs[i].first));
    }

    // Step 2: Polynomial expansion
    // Represent polynomial as vector of coefficients
    vector<long long> coeffs = {1}; // Start with P(x) = 1

    for (long long r : roots) {
        vector<long long> newCoeffs(coeffs.size() + 1, 0);

        // Multiply (x - r)
        for (size_t i = 0; i < coeffs.size(); i++) {
            newCoeffs[i] -= coeffs[i] * r;     // -r * coeff
            newCoeffs[i + 1] += coeffs[i];     // shift for x * coeff
        }
        coeffs = newCoeffs;
    }

    // Step 3: Output coefficients
    cout << "Polynomial Coefficients:" << endl;
    cout << "[ ";
    for (size_t i = 0; i < coeffs.size(); i++) {
        cout << coeffs[i];
        if (i != coeffs.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}