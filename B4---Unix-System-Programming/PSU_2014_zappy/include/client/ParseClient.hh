#ifndef PARSECLIENT_HH_
# define PARSECLIENT_HH_

/**
 * @file ParseClient.hh
 * @brief For parsing command from the client
 * @author doT
 * @version 1.0
 */
# define NBOBJECT	8

# include <map>
# include <vector>
# include <iostream>
# include "Error.hpp"
# include "template_string.hh"

/**
 * @class ParseClient
 * @brief This class parse the command receive by the client from the server
 */
class	ParseClient {
public:
  /**
   * @brief Parse the command 'voir'
   */
  std::vector<std::vector<std::vector<int> > >	getSee(std::string &,
						       std::map<std::string, int>&);
  /**
   * @brief Parse the command 'inventaire'
   */
  void		getInv(std::string &, std::map<std::string, int>&, int *);
  /**
   * @brief Get name or the number of the string between comma
   */
  std::string	getStrOrNumber(std::string &, char const, std::size_t &, bool);
  /**
   * @brief Remove '{' and '}'
   */
  void		initSeeOrInv(std::string &, std::size_t &);
};

#endif /* !PARSECLIENT_HH_ */
