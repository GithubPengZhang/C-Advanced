#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test) {
	return test.size() == 3;
}

int countString(vector<string> &texts, bool(*pFun)(string test)) {
	int itotal = 0;
	for (int i = 0; i<texts.size(); i++) {
		if (pFun(texts[i])) {
			++itotal;
		}
	}
	return itotal;
}

int main() {
	vector<string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("five");
	texts.push_back("six");
	texts.push_back("seven");
	texts.push_back("eight");

	cout << match("one") << endl;

	cout << count_if(texts.begin(), texts.end(), match) << endl;

	cout << countString(texts, match) << endl;

	return 0;
}
#endif