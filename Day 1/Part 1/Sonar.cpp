#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int previous(INT_MAX), x, count(0);
	string s;
	ifstream file;

	file.open("input.txt");

	if (file.is_open()) {
		while (getline(file, s)) {
			x = stoi(s);
			if (x > previous) {
				count++;
			}
			previous = x;
		}
	}

	cout << count;

	cin.get();
	file.close();

	return 0;
}