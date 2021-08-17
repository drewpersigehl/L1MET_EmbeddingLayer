#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include "embed.h"

#define NTEST 1

void embed(
	int data,
	float res[n_out],
	float weights[n_in*n_out]);

int main() {

	int data;
	float res[n_out];
	float weights[n_in*n_out];

	for (int test = 1; test <= NTEST; ++test) {

		// CAN CHANGE THIS
		data = 3;  // which row to check weights of for testing

		// initialize the result vector as zeros
		for (int i = 0; i < n_out; i++) {
			res[i] = 0;
		}

		// initialize the weights vector arbitrarily
		for (int i = 0; i < n_in; i++) {
			for (int j = 0; j < n_out; j++) {
				weights[i*n_out + j] = i;  // such that row x should look like {x, x, ...}
			}
		}

		embed(data, res, weights);

		for (int i = 0; i < n_out; i++) {
			printf("%f ", res[i]);
		}

		// write result to text file

		using namespace std;
		ofstream myfile ("cppValidationOutput.txt");
		if (myfile.is_open()) {
			myfile << "The output of the c++ embedding layer with input 3 is:\n";
			myfile << "\n";
			for (int i = 0; i < n_out; i++) {
				myfile << res[i];
				myfile << " ";
			}
		}
		else cout << "Unable to open file";

	}

	return 0;

}
