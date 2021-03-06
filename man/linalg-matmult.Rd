% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/linalg.r
\name{matmult}
\alias{matmult}
\alias{linalg_matmult}
\title{matmult}
\usage{
linalg_matmult(transx = FALSE, transy = FALSE, alpha = 1, x, y, ret = NULL)
}
\arguments{
\item{transx, transy}{Should x/y be transposed?}

\item{alpha}{Scalar.}

\item{x, y}{Input data.}

\item{ret}{Either \code{NULL} or an already allocated fml matrix of the same
class and type as \code{x}.}
}
\value{
Returns the matrix product.
}
\description{
Multiply two matrices: \code{ret = alpha*x*y}.
}
