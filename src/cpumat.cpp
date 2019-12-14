#include "extptr.h"
#include "fml/src/cpu/cpumat.hh"
#include "fml/src/cpu/linalg.hh"


// -----------------------------------------------------------------------------
// cpumat class methods
// -----------------------------------------------------------------------------

extern "C" SEXP R_cpumat_init(SEXP m_, SEXP n_)
{
  SEXP ret;
  
  int m = INTEGER(m_)[0];
  int n = INTEGER(n_)[0];
  
  cpumat<double> *x = new cpumat<double>();
  if (m > 0 && n > 0)
    x->resize(m, n);
  
  newRptr(x, ret, fml_object_finalizer<cpumat<double>>);
  UNPROTECT(1);
  return ret;
}



extern "C" SEXP R_cpumat_dim(SEXP x_robj)
{
  SEXP ret;
  PROTECT(ret = allocVector(INTSXP, 2));
  
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  INTEGER(ret)[0] = x->nrows();
  INTEGER(ret)[1] = x->ncols();
  UNPROTECT(1);
  return ret;
}



extern "C" SEXP R_cpumat_inherit(SEXP x_robj, SEXP data)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->inherit(REAL(data), nrows(data), ncols(data), false);
  return R_NilValue;
}



extern "C" SEXP R_cpumat_resize(SEXP x_robj, SEXP m, SEXP n)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->resize(INTEGER(m)[0], INTEGER(n)[0]);
  return R_NilValue;
}



extern "C" SEXP R_cpumat_print(SEXP x_robj, SEXP ndigits)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->print(INTEGER(ndigits)[0]);
  return R_NilValue;
}



extern "C" SEXP R_cpumat_info(SEXP x_robj)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->info();
  return R_NilValue;
}



extern "C" SEXP R_cpumat_fill_zero(SEXP x_robj)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->fill_zero();
  return R_NilValue;
}



extern "C" SEXP R_cpumat_fill_val(SEXP x_robj, SEXP v)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->fill_val(REAL(v)[0]);
  return R_NilValue;
}



extern "C" SEXP R_cpumat_fill_linspace(SEXP x_robj, SEXP start, SEXP stop)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->fill_linspace(REAL(start)[0], REAL(stop)[0]);
  return R_NilValue;
}



extern "C" SEXP R_cpumat_fill_eye(SEXP x_robj)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->fill_eye();
  return R_NilValue;
}



extern "C" SEXP R_cpumat_fill_runif(SEXP x_robj, SEXP seed, SEXP min, SEXP max)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  if (INTEGER(seed)[0] == -1)
    x->fill_runif(REAL(min)[0], REAL(max)[0]);
  else
    x->fill_runif(INTEGER(seed)[0], REAL(min)[0], REAL(max)[0]);
  
  return R_NilValue;
}



extern "C" SEXP R_cpumat_fill_rnorm(SEXP x_robj, SEXP seed, SEXP min, SEXP max)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  if (INTEGER(seed)[0] == -1)
    x->fill_rnorm(REAL(min)[0], REAL(max)[0]);
  else
    x->fill_rnorm(INTEGER(seed)[0], REAL(min)[0], REAL(max)[0]);
  
  return R_NilValue;
}



extern "C" SEXP R_cpumat_scale(SEXP x_robj, SEXP s)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->scale(REAL(s)[0]);
  return R_NilValue;
}



extern "C" SEXP R_cpumat_rev_rows(SEXP x_robj)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->rev_rows();
  return R_NilValue;
}



extern "C" SEXP R_cpumat_rev_cols(SEXP x_robj)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  x->rev_cols();
  return R_NilValue;
}



extern "C" SEXP R_cpumat_to_robj(SEXP x_robj)
{
  SEXP ret;
  
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  
  len_t m = x->nrows();
  len_t n = x->ncols();
  auto *x_d = x->data_ptr();
  
  PROTECT(ret = allocMatrix(REALSXP, m, n));
  double *ret_d = REAL(ret);
  
  for (len_t j=0; j<n; j++)
  {
    for (len_t i=0; i<m; i++)
      ret_d[i + m*j] = (double) x_d[i + m*j];
  }
  
  UNPROTECT(1);
  return ret;
}



extern "C" SEXP R_cpumat_from_robj(SEXP x_robj, SEXP robj)
{
  int m = nrows(robj);
  int n = ncols(robj);
  double *r_d = REAL(robj);
  
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  len_t m_x = x->nrows();
  len_t n_x = x->ncols();
  
  if (m_x != m || n_x != n)
    x->resize(m, n);
  
  auto *x_d = x->data_ptr();
  for (len_t j=0; j<n; j++)
  {
    for (len_t i=0; i<m; i++)
      x_d[i + m*j] = (double) r_d[i + m*j];
  }
  
  return R_NilValue;
}



// -----------------------------------------------------------------------------
// linalg namespace
// -----------------------------------------------------------------------------

extern "C" SEXP R_cpumat_linalg_crossprod(SEXP xpose, SEXP alpha, SEXP x_robj, SEXP ret_robj)
{
  cpumat<double> *x = (cpumat<double>*) getRptr(x_robj);
  cpumat<double> *ret = (cpumat<double>*) getRptr(ret_robj);
  
  if (LOGICAL(xpose)[0])
    linalg::tcrossprod(REAL(alpha)[0], *x, *ret);
  else
    linalg::crossprod(REAL(alpha)[0], *x, *ret);
  
  return R_NilValue;
}