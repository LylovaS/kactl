#include "../utilities/template.h"
#include "../../content/strings/ExpressionEval.h"

const double eps = 1e-9;

void test(const string& s, double expected_res) {
    double res = eval(s);
    if (abs(res - expected_res) > eps) {
            cerr << setprecision(20) << fixed;
			cerr << "failed!" << endl;
			cerr << s << endl;
			cerr << "expected_res: " << expected_res << endl;
			cerr << "got: " << res << endl;
			abort();
		}
}


int main() {
	test("1+2", 3);
	test("((((2+3)*4)-5)/3+1)*2", 12);
	test("2*3/4*5/6+7-8", 0.25);
	test("(1/2*3/4)+(5/6-7/8)*9/10", 0.3375);
	test("((3*4+5)/6)/7-8+9*(10-11/12)", 74.1547619047619);
}