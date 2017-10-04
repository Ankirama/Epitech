#include "ParseClient.hh"

std::vector<std::vector<std::vector<int> > >	ParseClient::getSee(std::string &tmp,
								    std::map<std::string,
								    int> &map){
  try {
    std::string				str;
    std::size_t				pos;
    std::size_t				posTmp;
    std::vector<std::vector<int> >     	myCase;
    unsigned int			floor = 1;
    std::vector<std::vector<std::vector<int> > >	myFloor;

    this->initSeeOrInv(tmp, pos);
    if (tmp[0] == ' ')
      tmp = tmp.substr(1, tmp.length());
    while (!tmp.empty()){
      str = this->getStrOrNumber(tmp, ',', pos, false);
      std::vector<int>			myTab;
      for (int i = 0;i < NBOBJECT;++i)
        myTab.push_back(0);
      myCase.push_back(myTab);
      while (!str.empty())
        myCase.back()[map[this->getStrOrNumber(str, ' ', posTmp, true)]]++;
      (pos != std::string::npos) ? tmp = tmp.substr(pos + 1, tmp.length()) : tmp.erase();
      if (myCase.size() == floor){
        myFloor.push_back(myCase);
        floor += 2;
        while (!myCase.empty())
          myCase.erase(myCase.begin());
      }
    }
    return (myFloor);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ParseClient");
  }
}

void			ParseClient::getInv(std::string &tmp,
					    std::map<std::string, int> &map, int *tab){
  try {
    std::string		str;
    std::size_t		pos;
    std::size_t		posTmp;

    for (int i = 0;i < NBOBJECT;++i)
      tab[i] = 0;
    this->initSeeOrInv(tmp, pos);
    while (!tmp.empty()){
      str = this->getStrOrNumber(tmp, ',', pos, false);
      while (!str.empty())
        tab[map[this->getStrOrNumber(str, ' ', posTmp, true)]] =
	  StringToNumber<int>(this->getStrOrNumber(str, ' ', posTmp, true));
      (pos != std::string::npos) ? tmp = tmp.substr(pos + 2, tmp.length()) : tmp.erase();
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ParseClient");
  }
}

void	ParseClient::initSeeOrInv(std::string &tmp, std::size_t &pos){
  pos = tmp.find('{');
  if (pos != std::string::npos)
    tmp = tmp.substr(pos + 1, tmp.length());
  pos = tmp.find('}');
  if (pos != std::string::npos)
    tmp = tmp.substr(0, pos);
}

std::string		ParseClient::getStrOrNumber(std::string &str, char const c,
						    std::size_t &pos, bool erase){
  try {
    std::string		nb;

    pos = str.find(c);
    if (pos != std::string::npos){
      nb = str.substr(0, pos);
      if (erase)
	str = str.substr(pos + 1, str.length());
    } else {
      nb = str;
      if (erase)
	str.erase();
    }
    return (nb);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ParseClient");
  }
}
