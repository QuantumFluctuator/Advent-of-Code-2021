#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int x, y, z, count(0), sum(INT_MAX);
	string s;
	ifstream file;

	file.open("input.txt");

	if (file.is_open()) {
		getline(file, s);
		x = stoi(s);
		getline(file, s);
		y = stoi(s);

		while (getline(file, s)) {
			z = stoi(s);

			if (x + y + z > sum) {
				count++;
			}
			sum = x + y + z;
			x = y;
			y = z;
		}
	}

	cout << count;

	cin.get();
	file.close();

	return 0;
}