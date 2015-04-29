#include <Rcpp.h>
#include <boost/asio.hpp>
using namespace Rcpp;

#ifndef __ASIO_BINDINGS__
#define __ASIO_BINDINGS__

/**
 * A class containing the boost::asio bindings in use in iptools.
 */
class asio_bindings {

private:

  /**
   * A consistent (well, instantiated once per run) io_service
   * instance; used by hostname_to_dns/ip_to_dns functions, and
   * (since it's reusable) we'll hopefully get a speed improvement
   * out of only using one.
   */
  boost::asio::io_service io_service;

  /**
   * A function for taking a hostname ("http://en.wikipedia.org")
   * and converting it to the actual IP addresses it resolves to.
   *
   * @param hostname a hostname.
   *
   * @param resolver_ptr a reference to an asio resolver.
   *
   * @see single_ip_to_dns for the reverse operation, or
   * multi_hostname_to_dns for the vectorised version.
   *
   * @return a vector containing the IP address(es) the hostname
   * resolves to.
   */
  std::vector < std::string > single_hostname_to_dns(std::string hostname, boost::asio::ip::tcp::resolver& resolver_ptr);

  std::vector < std::string > single_ip_to_dns(std::string ip_address, boost::asio::ip::tcp::resolver& resolver_ptr);

  bool single_ip_in_range(std::string ip_address, std::string range);

public:

  std::list < std::vector < std::string > > multi_hostname_to_dns(
      std::vector < std::string > hostnames
  );

  std::list < std::vector < std::string > > multi_ip_to_dns(
      std::vector < std::string > ip_addresses
  );

  std::vector < unsigned int > ip_to_numeric_(std::vector < std::string > ip_addresses);

  std::vector < std::string > numeric_to_ip_ (std::vector < unsigned int > ip_addresses);

  std::vector < std::string > classify_ip_ (std::vector < std::string > ip_addresses);

  std::vector < bool > ip_in_range_(std::vector < std::string > ip_addresses, std::vector < std::string > ranges);
};

#endif