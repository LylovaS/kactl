/**
 * Author: Sophya Lylova
 * Date: Somewhen
 * License: CC0
 * Description: Evaluates expression with brackets and operations with different priorities.
 * Time: $O(N)$.
 * Status: 
 */
#pragma once

double merge(double a, double b, char c) {
	switch (c) {
		case '*': return a * b; case '/': return a / b;
		case '+': return a + b;	case '-': return a - b;
	} assert(false);
}
map<char, int> prior = {{'*', 1},{'/', 1},{'+', 0},{'-', 0}};
double eval(string s) {
	string ops;
	vector<double> vals;
	bool past_number=false;
	for (char c: s) {
		if (c >= '0' && c <= '9') {
			if (!past_number) vals.push_back(0);
			vals.back() = vals.back() * 10 + c - '0';
			past_number = true;	continue;
		}
		past_number = false;
		if (c == '(') {
			ops.push_back(c); continue;
		}
		if (c == ')') {
			while (ops.back() != '(') {
				double b = vals.back(); vals.pop_back();
				double a = vals.back(); vals.pop_back();
				vals.push_back(merge(a, b, ops.back()));
				ops.pop_back();
			}
			ops.pop_back();	continue;
		}
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