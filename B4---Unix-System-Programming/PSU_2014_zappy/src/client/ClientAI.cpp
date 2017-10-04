//
// ClientAI.cpp for  in /home/teyssa_r/rendu/PSU_2014_zappy/src/client
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Thu Jun 18 22:15:21 2015 Raphael Teyssandier
// Last update Sun Jul  5 22:15:22 2015 Raphael Teyssandier
//

#include "ClientAI.hh"
#include "Parser.hh"

static int	level[7][NBOBJECT] = {
  {1, 0, 1, 0, 0, 0, 0, 0},
  {2, 0, 1, 1, 1, 0, 0, 0},
  {2, 0, 2, 0, 1, 0, 2, 0},
  {4, 0, 1, 1, 2, 0, 1, 0},
  {4, 0, 1, 2, 1, 3, 0, 0},
  {6, 0, 1, 2, 3, 0, 1, 0},
  {6, 0, 2, 2, 2, 2, 2, 1}
};

ClientAI::ClientAI(int ac, char **av) : m_currentLevel(1),
					m_goHelp(false),
					m_idHelp(0),
					m_parsing(new ParseClient()),
					m_posX(0),
					m_posY(0),
					m_canIncant(false),
					m_alive(true){
  Parser	*parser = new Parser(ac, av, USAGE, true);

  if (parser->getPort().empty() || parser->getName().empty())
    throw ErrorClient(USAGE, "ClientAI");
  this->m_network = new Network(parser->getName(), parser->getPort(),
				parser->getHostName());
  this->m_map["joueur"] = ClientAI::ID_PLAYER;
  this->m_map["nourriture"] = ClientAI::ID_FOOD;
  this->m_map["linemate"] = ClientAI::ID_LINEMATE;
  this->m_map["deraumere"] = ClientAI::ID_DERAUMETE;
  this->m_map["sibur"] = ClientAI::ID_SIBUR;
  this->m_map["mendiane"] = ClientAI::ID_MENDIANE;
  this->m_map["phiras"] = ClientAI::ID_PHIRAS;
  this->m_map["thystame"] = ClientAI::ID_THYSTAME;
  this->m_tab[ClientAI::ID_FOOD] = 10;
}

ClientAI::ClientAI(ClientAI const &e) : m_network(e.m_network){
}

ClientAI	&ClientAI::operator=(ClientAI const &e){
  this->m_network = e.m_network;
  return (*this);
}

ClientAI::~ClientAI(){
  delete this->m_network;
  delete this->m_parsing;
}

void	ClientAI::init(){
  this->m_network->initNetwork();
  this->m_network->initFd();
}

void	ClientAI::recvMessage(){
  try {
    while ((this->m_receive = this->m_network->readCmd()).empty())
      this->m_network->fdIsset();
    if (this->m_receive == "mort\n"){
      this->m_alive = false;
      this->m_receive.erase();
      throw ErrorClient("MORT", "ClientAI");
    }
    else
      this->recvInfoIncant();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }

}

void	ClientAI::cycle(){
  try {
    while ((this->m_receive = this->m_network->readCmd()) != "BIENVENUE\n")
      this->m_network->fdIsset();
    this->sendInfo(this->m_network->getName());
    if (this->m_receive != "ko\n"){
      this->recvMessage();
      if (this->m_receive != "ko\n")
	this->loop();
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::recvInfoIncant(){
    std::size_t	pos;
    std::string	tmp;

    if (this->m_parsing->getStrOrNumber(this->m_receive, ' ', pos, false) == "message"
	   && !this->m_canIncant && this->m_alive){
      this->m_goHelp = true;
      this->m_canIncant = false;
      this->m_messageHelp = this->m_receive;
      this->m_receive.erase();
      this->recvMessage();
    }
    if (this->m_parsing->getStrOrNumber(this->m_receive, ' ', pos, false) == "message"
	&& this->m_alive){
      this->m_receive.erase();
      this->recvMessage();
    }
    if (this->m_parsing->getStrOrNumber(this->m_receive, ' ', pos, false) == "niveau"
	&& this->m_alive){
      this->m_currentLevel++;
      this->m_goHelp = false;
      this->m_canIncant = false;
      this->m_messageHelp.erase();
      this->m_idHelp = 0;
      this->m_receive.erase();
      this->recvMessage();
      this->log("Incantation:", "Done " + NumberToString<int>(this->m_currentLevel),
		  "\e[0;34m");
    }
}

void		ClientAI::log(std::string const what, std::string const message,
			      std::string const color){
  std::cout << color << what << "\e[0;0m\t" << message << std::endl;
}

bool		ClientAI::sendInfo(std::string _message) {
  try {
    this->m_receive.erase();
    this->m_network->sendCmd(_message);
    this->recvMessage();
    if (this->m_alive){
      _message.erase(_message.find('\n'));
      this->log("Message:", _message, "\e[0;33m");
      this->log("The reponse:", this->m_receive, "\e[0;32m");
      if (_message == "voir" && this->m_receive[0] == '{' && this->m_receive[1] == ' ')
	this->m_floor = this->m_parsing->getSee(this->m_receive, this->m_map);
      else if (_message == "inventaire" && this->m_receive[0] == '{' &&
	       this->m_receive[1] != ' ' )
	this->m_parsing->getInv(this->m_receive, this->m_map, this->m_tab);
    }
    return ((this->m_receive == "ko\n") ? false : true);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

bool		ClientAI::checkSee(int whatIWant, int whoMuch) {
  try {
    int             x = 0;
    int             y = 0;

    for (std::vector<std::vector<std::vector<int> > >::iterator itFloor =
	   this->m_floor.begin();
	 itFloor != this->m_floor.end(); ++itFloor){
      x = 0;
      for (std::vector<std::vector<int> >::iterator it = (*itFloor).begin();
	   it != (*itFloor).end();++it){
	if ((*it)[whatIWant] >= whoMuch){
	  this->m_posX = x;
	  this->m_posY = y;
	  return (true);
	}
	x++;
      }
      y++;
    }
    return (false);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void	ClientAI::loop(){
  try {
    int	inCantation = 0;

    sendInfo(VOIR);
    while (this->m_alive && this->m_network->getFd() > 0){
      sendInfo(INVENTAIRE);
      if (!this->m_goHelp && this->m_tab[ClientAI::ID_FOOD] > 5){
	inCantation = 0;
	for (int i = 2; i < NBOBJECT; ++i)
	  if (this->m_tab[i] < level[this->m_currentLevel - 1][i])
	    this->seekElem(i, level[this->m_currentLevel - 1][i]);
	  else
	    inCantation++;
	if (inCantation == 6)
	  this->findElevation();
      } else if (this->m_goHelp && this->m_tab[ClientAI::ID_FOOD] >= 5)
	goForHelp();
      else
	seekElem(ClientAI::ID_FOOD, 10);
    }
    return;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

std::string	ClientAI::seekInMap(int elem) const {
  try {
    for (std::map<std::string, int>::const_iterator it = this->m_map.begin();
	 it != this->m_map.end(); ++it)
      if ((*it).second == elem)
	return ((*it).first);
    return ("");
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void	ClientAI::seekElem(int elem, int whoMuch){
  try {
    int	i;
    int	miam = 5;

    i = 0;
    sendInfo(VOIR);
    if (elem == ClientAI::ID_FOOD && this->m_canIncant){
      this->m_canIncant = false;
      sendInfo(AVANCE);
      sendInfo("broadcast ko\n");
    }
    if (elem == ClientAI::ID_FOOD)
      miam = 1;
    if (checkSee(elem, 1)){
      do {
	sendInfo(VOIR);
	this->advance(i);
	this->leftOrRight(i);
	sendInfo(PRENDRE(this->seekInMap(elem)));
	sendInfo(INVENTAIRE);
      }  while (this->m_tab[elem] < whoMuch && this->m_tab[ClientAI::ID_FOOD] > miam &&
		checkSee(elem, 1));
      if (this->m_tab[ClientAI::ID_FOOD] <= 5)
	seekElem(ClientAI::ID_FOOD, 10);
    } else {
      this->m_posY = 0;
      this->advance();
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::leftOrRight(int &i){
  try {
    int		x = 0;

    if (this->m_posX < i) {
      x = this->m_posX;
      sendInfo(GAUCHE);
      while (x < i) {
	this->advance();
	x++;
      }
    } else if (this->m_posX > i) {
      x = this->m_posX;
      sendInfo(DROITE);
      while (x > i) {
	this->advance();
	x--;
      }
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::advance(int &i){
  try {
    while (this->m_posY > 0) {
      this->advance();
      i++;
      this->m_posY--;
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::advance(){
  try {
    sendInfo(VOIR);
    this->takeFood();
    sendInfo(AVANCE);
    sendInfo(VOIR);
    this->takeFood();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::takeFood(){
  try {
    while (!this->m_floor.empty() &&
	   !this->m_floor[0].empty() &&
	   !this->m_floor[0][0].empty() &&
	   this->m_floor[0][0][ClientAI::ID_FOOD] > 0){
      sendInfo(PRENDRE(this->seekInMap(ClientAI::ID_FOOD)));
      sendInfo(VOIR);
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::helpDirection(int k){
  try {
    switch (k){
    case 1:
    case 2:
    case 8:
      this->advance();
      break;
    case 7:
    case 6:
      sendInfo(DROITE);
      break;
    case 3:
    case 4:
      sendInfo(GAUCHE);
      break;
    case 5:
      sendInfo(DROITE);
      break;
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::goForHelp() {
  try {
    int		levelHelp;
    int		idTmp;
    int		k;
    std::string	str;
    std::size_t	pos;

    str = this->m_parsing->getStrOrNumber(this->m_messageHelp, ',', pos, true);
    if (this->m_parsing->getStrOrNumber(str, ' ', pos, true) == "message"){
      k = StringToNumber<int>(this->m_parsing->getStrOrNumber(str, ' ', pos, true));
      str = this->m_parsing->getStrOrNumber(this->m_messageHelp, ',', pos, true);
      if (this->m_parsing->getStrOrNumber(str, ' ', pos, false) != "ko\n") {
	this->m_goHelp = true;
	levelHelp = StringToNumber<int>(this->m_parsing->getStrOrNumber(str, ' ', pos, true));
	if (this->m_currentLevel == levelHelp &&
	    (this->m_idHelp ||
	     (idTmp = StringToNumber<int>(this->m_parsing->getStrOrNumber(str, ' ',
									  pos, true)))))
	  this->helpDirection(k);
	else if (levelHelp != this->m_currentLevel){
	  this->m_goHelp = false;
	  this->m_messageHelp.erase();
	  this->m_idHelp = 0;
	}
      } else
	this->m_goHelp = false;
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::takeOrPose(){
  try {
    for (int i = 1;i < NBOBJECT;++i)
      for (int j = 0;this->m_floor[0][0][i] > 0;++j){
	sendInfo(PRENDRE(this->seekInMap(i)));
	sendInfo(VOIR);
      }
    sendInfo(INVENTAIRE);
    for (int i = 2;i < NBOBJECT;++i)
      for (int j = 0;this->m_floor[0][0][i] < level[this->m_currentLevel - 1][i] &&
	     this->m_tab[i] > 0;j++){
	sendInfo(POSER(this->seekInMap(i)));
	sendInfo(VOIR);
      }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void		ClientAI::findElevation() {
  try {
    bool		ko;
    std::size_t	pos;
    std::string	tmp = "";

    sendInfo(VOIR);
    if (this->m_floor[0][0][ClientAI::ID_PLAYER] <
	level[this->m_currentLevel - 1][ClientAI::ID_PLAYER]){
      sendInfo("broadcast " + NumberToString<int>(this->m_currentLevel) + " " +
	       NumberToString<int>(this->m_network->getFd()) + "\n");
      this->m_canIncant = true;
    } else if (!this->m_floor.empty() &&
	       !this->m_floor[0].empty()){
      sendInfo(VOIR);
      this->m_canIncant = false;
      this->takeOrPose();
      ko = sendInfo(INCANTATION);
      this->log("Incantation", "Level " + NumberToString<int>(this->m_currentLevel),
		"\e[0;34m");
      while ((tmp = this->m_parsing->getStrOrNumber((tmp = this->m_network->
      						     readCmd()), ' ', pos, true)).empty()
      	     && ko && this->m_alive)
      	this->m_network->fdIsset();
      if (!tmp.empty() && tmp == "mort\n")
	throw ErrorClient("MORT", "ClientAI");
      if (this->m_alive && ko && !tmp.empty() && tmp == "niveau"){
	this->m_currentLevel++;
	this->log("Incantation:", "Done " + NumberToString<int>(this->m_currentLevel),
		  "\e[0;34m");
	this->doFork();
      }
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "ClientAI");
  }
}

void	ClientAI::doFork() {
  sendInfo(INVENTAIRE);
  if (this->m_tab[ClientAI::ID_FOOD] > 4){
    seekElem(ClientAI::ID_FOOD, 5);
    sendInfo(INVENTAIRE);
    if (this->m_tab[ClientAI::ID_FOOD] >= 5)
      sendInfo(FORK);
  }
}
