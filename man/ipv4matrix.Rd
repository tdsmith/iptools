% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{ipv4matrix}
\alias{ipv4matrix}
\title{IPv4 Hilbert Curve Matrix}
\usage{
ipv4matrix(ip)
}
\arguments{
\item{ip}{input character (dotted-deciman IPv4s) vector}
}
\value{
4096x4096 matrix, with non-0 entries being the count of IP addresses
        in that netblock
}
\description{
Returns a 4096x4096 Hilbert curve matrix for an input vector of IP
addresses. Generally not called directly (most of the time you'll want to
use \code{ipv4heatmap}), but avilable in the event another method of
visualization is necessary/desired.
}

