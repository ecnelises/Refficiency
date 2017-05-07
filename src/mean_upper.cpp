#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
double mean_upper(NumericMatrix sp)
{
	size_t n = sp.nrow();
	size_t m = sp.ncol();
	double sum = 0.0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < m; ++j) {
            sum += 1.0 / sp(i, j);
		}
	}
	int count = m * (m - 1) / 2;
	return sum / count;
}
