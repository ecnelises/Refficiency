#include <immintrin.h>
#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
double mean_upper(NumericMatrix sp)
{
	size_t n = sp.nrow();
	size_t m = sp.ncol();
	__m256d yone0 = {1.0, 1.0, 1.0, 1.0};
	__m256d ysum0 = _mm256_setzero_pd();
	__m256d yload0;
	__m256d ytemp0;
	double t_store[4];
	double sum = 0.0;
	double *q;
	int ic = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < m; ++j) {
			t_store[ic++] = sp(i, j);
			if (ic == 4) {
				yload0 = _mm256_load_pd(t_store);
				ytemp0 = _mm256_div_pd(yone0, yload0);
				ysum0 = _mm256_add_pd(ysum0, ytemp0);
				ic = 0;
			}
		}
	}
	q = (double*)&ysum0;
	sum += q[0] + q[1] + q[2] + q[3];
	for (int i = 0; i < ic; ++i) {
		sum += 1.0 / t_store[i];
	}
	int count = m * (m - 1) / 2;
	return sum / count;
}
