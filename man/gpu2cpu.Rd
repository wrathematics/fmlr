% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/helpers.r
\name{gpu2cpu}
\alias{gpu2cpu}
\title{gpu2cpu}
\usage{
gpu2cpu(gpu_in, cpu_out)
}
\arguments{
\item{gpu_in}{Input.}

\item{cpu_out}{Ouput.}
}
\value{
Returns \code{NULL}.
}
\description{
Copy the data in a GPU object to a CPU object. The objects must be of the
core class (e.g. gpuvec/cpuvec and gpumat/cpumat), but they can be of
different fundamental types (e.g. float/double).
}
