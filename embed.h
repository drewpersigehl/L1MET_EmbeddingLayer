#define n_in 5  // number of categories (i.e. vocab size)
#define n_out 8  // vector with length of encoded embedding

void embed(
	int data,
	float res[n_out],
	float weights[n_in*n_out]);
