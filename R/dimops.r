#' @useDynLib fmlr R_dimops_matsums
matsums = function(row, mean, x, s)
{
  if (is.null(s))
    s = setret(x, vec=TRUE)
  
  .Call(R_dimops_matsums, get_backend(x), x$get_type(), row, mean, x$data_ptr(), s$data_ptr())
  s
}



#' matsums
#' 
#' Compute the sums/means of the rows/columns of a matrix.
#' 
#' @param x Input matrix.
#' @param s Either \code{NULL} or an already allocated fml matrix of the same
#' class and type as \code{x}.
#' @return Returns the matrix sum.
#' 
#' @rdname dimops
#' @name dimops
NULL



#' @name dimops
#' @export
dimops_rowsums = function(x, s=NULL)
{
  check_is_mat(x)
  invisiret = check_inputs(s, x)
  
  s = matsums(TRUE, FALSE, x, s)
  
  if (invisiret)
    invisible(s)
  else
    s
}

#' @name dimops
#' @export
dimops_rowmeans = function(x, s=NULL)
{
  check_is_mat(x)
  invisiret = check_inputs(s, x)
  
  s = matsums(TRUE, TRUE, x, s)
  
  if (invisiret)
    invisible(s)
  else
    s
}

#' @name dimops
#' @export
dimops_colsums = function(x, s=NULL)
{
  check_is_mat(x)
  invisiret = check_inputs(s, x)
  
  s = matsums(FALSE, FALSE, x, s)
  
  if (invisiret)
    invisible(s)
  else
    s
}

#' @name dimops
#' @export
dimops_colmeans = function(x, s=NULL)
{
  check_is_mat(x)
  invisiret = check_inputs(s, x)
  
  s = matsums(FALSE, TRUE, x, s)
  
  if (invisiret)
    invisible(s)
  else
    s
}



#' scale
#' 
#' Remove the mean and/or sd of the columns of a matrix. The operations occur
#' in-place.
#' 
#' @param rm_mean,rm_sd Should the data be centered/scaled first?
#' @param x Input matrix. The input data is overwritten by the centered/scaled
#' data.
#' 
#' @rdname scale
#' @name scale
#' 
#' @useDynLib fmlr R_dimops_scale
#' 
#' @export
dimops_scale = function(rm_mean=TRUE, rm_sd=FALSE, x)
{
  check_is_mat(x)
  
  rm_mean = as.logical(rm_mean)
  rm_sd = as.logical(rm_sd)
  
  .Call(R_dimops_scale, get_backend(x), x$get_type(), rm_mean, rm_sd, x$data_ptr())
  invisible(NULL)
}
