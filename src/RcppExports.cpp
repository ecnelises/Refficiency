// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// mean_upper
double mean_upper(NumericMatrix sp);
RcppExport SEXP Refficiency_mean_upper(SEXP spSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type sp(spSEXP);
    rcpp_result_gen = Rcpp::wrap(mean_upper(sp));
    return rcpp_result_gen;
END_RCPP
}
