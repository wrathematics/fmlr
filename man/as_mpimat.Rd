% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/mpimat.r
\name{as_mpimat}
\alias{as_mpimat}
\title{as_mpimat}
\usage{
as_mpimat(grid, x, bf_rows = 16, bf_cols = 16)
}
\arguments{
\item{grid}{An MPI grid object; the return of \code{grid()}. See \code{?grid}.}

\item{x}{R matrix.}

\item{bf_rows, bf_cols}{The blocking factor.}
}
\value{
An mpimat object.
}
\description{
Convert an R matrix to an mpimat object.
}
