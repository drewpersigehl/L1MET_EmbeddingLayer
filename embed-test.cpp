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
	float weights[n_in*n_out] = {0.69405118, 0.85314349, 0.44348042, 0.98682741, 0.07212228, 0.44294918,
			  0.50451567, 0.89471736,
			 0.5172397,  0.73553228, 0.32378551, 0.08363885, 0.90106569, 0.34001472,
			  0.95520333, 0.09582401,
			 0.37217257, 0.33020137, 0.58489308, 0.59285919, 0.99916981, 0.28807132,
			  0.47801168, 0.94389581,
			 0.81038834, 0.34495702, 0.87173576, 0.36079162, 0.8432279,  0.74681984,
			  0.96527759, 0.83150219,
			 0.85617576, 0.117599, 0.63892696, 0.12100261, 0.83511491, 0.0326155,
			  0.18490572, 0.55708856};

	for (int test = 1; test <= NTEST; ++test) {

		// CAN CHANGE THIS
		data = 3;  // which row to check weights of for testing

		// initialize the result vector as zeros
		for (int i = 0; i < n_out; i++) {
			res[i] = 0;
		}

		embed(data, res, weights);

		for (int i = 0; i < n_out; i++) {
			printf("%f ", res[i]);
		}

		// THIS SECTION SHOULD BE REMOVED FOR HLS SYNTHESIS

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
