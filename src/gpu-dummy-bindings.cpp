#include <Rinternals.h>

#define WARNMSG "fmlr built without GPU support; this does nothing"
#define WARN_AND_RETURN warning(WARNMSG);return R_NilValue;

namespace
{
  static inline void unused(){}
  
  template <typename T>
  static inline void unused(T *x)
  {
    (void)x;
  }
  
  template <typename T, typename... VAT>
  static inline void unused(T *x, VAT... vax)
  {
    unused(x);
    unused(vax ...);
  }
}



// -----------------------------------------------------------------------------
// card bindings
// -----------------------------------------------------------------------------

extern "C" SEXP R_card_init(SEXP id_)
{
  unused(id_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_card_info(SEXP x_robj)
{
  unused(x_robj);
  WARN_AND_RETURN;
}

extern "C" SEXP R_card_get_id(SEXP x_robj)
{
  unused(x_robj);
  WARN_AND_RETURN;
}

extern "C" SEXP R_card_valid_card(SEXP x_robj)
{
  unused(x_robj);
  WARN_AND_RETURN;
}



// -----------------------------------------------------------------------------
// gpuvec bindings
// -----------------------------------------------------------------------------

extern "C" SEXP R_gpuvec_init(SEXP c_robj, SEXP size_)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_size(SEXP x_robj)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_set(SEXP x_robj, SEXP data)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_resize(SEXP x_robj, SEXP size)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_print(SEXP x_robj, SEXP ndigits)
{
  unused(x_robj, ndigits);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_info(SEXP x_robj)
{
  unused(x_robj);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_fill_zero(SEXP x_robj)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_fill_one(SEXP x_robj)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_fill_val(SEXP x_robj, SEXP v)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_fill_linspace(SEXP x_robj, SEXP start, SEXP stop)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_scale(SEXP x_robj, SEXP s)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}

extern "C" SEXP R_gpuvec_rev(SEXP x_robj)
{
  unused(c_robj, size_);
  WARN_AND_RETURN;
}