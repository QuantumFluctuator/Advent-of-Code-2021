#include <iostream>
#include <fstream>
#include <string>

#define DATASIZE 12

using namespace std;

int main() {
	int* gamma((int*)malloc(DATASIZE * sizeof(int))), * epsilon((int*)malloc(DATASIZE * sizeof(int))), * count((int*)calloc(DATASIZE, sizeof(int))), counttotal(0), eps(0), gam(0);
	string s;
	ifstream file;

	file.open("input.txt");

	if (file.is_open()) {
		while (getline(file, s)) {
			counttotal++;
			for (int i(0); i < DATASIZE; i++) {
				if (s[i] == '1') {
					count[i]++;
				}
			}
		}
	}

	for (int i(0); i < DATASIZE; i++) {
		epsilon[i] = (count[i] < (counttotal / 2)) ? 1 : 0;
		gamma[i] = (count[i] < (counttotal / 2)) ? 0 : 1;
	}

	for (int i(0); i < DATASIZE; i++) {
		eps += (epsilon[i] == 1) ? (int)pow(2, DATASIZE - (i + 1)) : 0;
		gam += (gamma[i] == 1) ? (int)pow(2, DATASIZE - (i + 1)) : 0;
	}

	cout << "gamma is:\t" << gam << endl;
	cout << "epsilon is:\t" << eps << endl;
	cout << "Final result is:\t" << (eps * gam) << endl;

	cin.get();

	file.close();

	free(gamma);
	free(epsilon);
	free(count);
}