#include <iostream>
using namespace std;

struct Test
{
	virtual bool operator()(string &text) = 0;
	virtual ~Test() {}
};

struct MatchTest : public Test {
	bool operator()(string &text) {
		return text == "lion";
	}
};

void check(string text, Test &test) {
	if (test(text))
		cout << "Match" << endl;
	else
		cout << "Not Match" << endl;

}

int main() {
	MatchTest pred;
	string strVal = "lion";

	cout << pred(strVal) << endl;

	cout << "-----" << endl;

	MatchTest m;
	check("liond", m);

	return 0;
}