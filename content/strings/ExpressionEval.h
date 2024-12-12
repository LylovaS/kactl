/**
 * Author: Sofia Lylova
 * Date: 2024-12-10
 * License: CC0
 * Source: folklor
 * Description: Evaluates expression with brackets and operations 
 * with different priorities.
 * Time: $O(N)$.
 * Status: not testes
 */
#pragma once

double merge(double a, double b, char c) {
    switch (c) {
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
    } assert(false);
}
map<char, int> prior = {{'*', 1},
                        {'/', 1},
                        {'+', 0},
                        {'-', 0}};
double eval(string s) {
    string ops;
    vector<double> vals;
    bool past_number;
    for (char c: s) {
        if (c == '(') {
            past_number = false;
            ops.push_back(c);
            continue;
        }
        if (c == ')') {
            past_number = false;
            while (ops.back() != '(') {
                double b = vals.back(); vals.pop_back();
                double a = vals.back(); vals.pop_back();
                vals.push_back(merge(a, b, ops.back()));
                ops.pop_back();
            }
            ops.pop_back();
            continue;
        }
        if (c >= '0' && c <= '9') {
            if (!past_number) {
                vals.push_back(c - '0');
            } else {
                vals.back() = vals.back() * 10 + c - '0';
            }
            past_number = true;
            continue;
        }
        past_number = false;
        while (!ops.empty() && ops.back() != '(' && prior[c] <= prior[ops.back()]) {
            double b = vals.back(); vals.pop_back();
            double a = vals.back(); vals.pop_back();
            vals.push_back(merge(a, b, ops.back()));
            ops.pop_back();
        }
        ops.push_back(c);
    }
    while (!ops.empty()) {
        double b = vals.back(); vals.pop_back();
        double a = vals.back(); vals.pop_back();
        vals.push_back(merge(a, b, ops.back()));
        ops.pop_back();
    }
    return vals[0];
}