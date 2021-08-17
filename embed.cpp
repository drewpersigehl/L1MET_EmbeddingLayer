#include "embed.h"

void embed(
	int data,
	float res[n_out],
	float weights[n_in*n_out])
{
	// copy over the corresponding row in the weights lookup table
	for (int i = 0; i < n_out; i++) {
		res[i] = weights[data * n_out + i];
	}
}
