#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int hpos(0), depth(0), val;
	string s, direction;
	ifstream file;

	file.open("input.txt");

	if (file.is_open()) {
		while (getline(file, s)) {
			direction = s.substr(0, s.find(" "));
			val = stoi(s.substr(s.find(" ")));

			switch (direction[0]) {
			case 'f':
				hpos += val;
				break;
			case 'u':
				depth -= val;
				break;
			case 'd':
				depth += val;
				break;
			}
		}
	}

	cout << "Horizontal position is:\t" << hpos << endl;
	cout << "Depth is:\t" << depth << endl;

	cout << "Final result is:\t" << (hpos * depth) << endl;

	cin.get();
	file.close();

	return 0;
}