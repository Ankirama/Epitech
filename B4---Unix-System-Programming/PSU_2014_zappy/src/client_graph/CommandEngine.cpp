#include "CommandEngine.hh"

CommandEngine::CommandEngine() {
  try {
    this->m_function["msz"] = &CommandEngine::msz;
    this->m_function["bct"] = &CommandEngine::bct;
    this->m_function["tna"] = &CommandEngine::tna;
    this->m_function["pnw"] = &CommandEngine::pnw;
    this->m_function["ppo"] = &CommandEngine::ppo;
    this->m_function["plv"] = &CommandEngine::plv;
    this->m_function["pin"] = &CommandEngine::pin;
    this->m_function["pex"] = &CommandEngine::pex;
    this->m_function["pbc"] = &CommandEngine::pbc;
    this->m_function["pic"] = &CommandEngine::pic;
    this->m_function["pie"] = &CommandEngine::pie;
    this->m_function["pfk"] = &CommandEngine::pfk;
    this->m_function["pdr"] = &CommandEngine::pdr;
    this->m_function["pgt"] = &CommandEngine::pgt;
    this->m_function["pdi"] = &CommandEngine::pdi;
    this->m_function["enw"] = &CommandEngine::enw;
    this->m_function["eht"] = &CommandEngine::eht;
    this->m_function["ebo"] = &CommandEngine::ebo;
    this->m_function["edi"] = &CommandEngine::edi;
    this->m_function["sgt"] = &CommandEngine::sgt;
    this->m_function["seg"] = &CommandEngine::seg;
    this->m_function["smg"] = &CommandEngine::smg;
    this->m_function["suc"] = &CommandEngine::suc;
    this->m_function["sbp"] = &CommandEngine::sbp;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

CommandEngine::~CommandEngine() {
  while (!this->m_function.empty())
    this->m_function.erase(this->m_function.begin());
}

std::string		CommandEngine::getCmd(std::string &tmp) const {
  try {
    std::size_t		pos;
    std::string		cmd;

    pos = tmp.find(' ');
    if (pos != std::string::npos){
      cmd = tmp.substr(0, pos);
      tmp = tmp.substr(pos + 1, tmp.length());
      return (cmd);
    }
    return (tmp);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::whichCmd(Network &network, GameEngine &game){
  try {
    std::string		tmp;
    std::string		cmd;

    if (!(tmp = network.readCmd()).empty()){
      if (this->m_function.find((cmd = this->getCmd(tmp))) != this->m_function.end()){
	tabFun		tmpFun = this->m_function[cmd];
	(this->*tmpFun)(tmp, game);
      }
    }
    network.fdIsset();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

std::vector<std::string>       	CommandEngine::getArg(std::string &tmp){
  try {
    std::size_t			pos;
    std::vector<std::string>	vecArg;

    while (!tmp.empty()){
      if ((pos = tmp.find(' ')) != std::string::npos){
	vecArg.push_back(tmp.substr(0, pos));
	tmp = tmp.substr(pos + 1, tmp.length());
      } else {
	vecArg.push_back(tmp.substr(0, tmp.length()));
	tmp.erase();
      }
    }
    return (vecArg);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::msz(std::string &tmp, GameEngine &game) {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 2)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.createMap(StringToNumber<int>(myArg[0]), StringToNumber<int>(myArg[1]));
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void				CommandEngine::bct(std::string &tmp, GameEngine &game) {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);
    int			x = StringToNumber<int>(myArg[0]);
    int			y = StringToNumber<int>(myArg[1]);
    static int		count = 0;

    if (myArg.size() != 9)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getMap().setItem(x, y, ID_MEAT, StringToNumber<unsigned int>(myArg[2]));
    for (unsigned i = 0; i < NB_OBJ; ++i)
      game.getMap().setItem(x, y, i, StringToNumber<unsigned int>(myArg[3 + i]));
    if (!game.isLoaded()) {
      ++count;
      if (count + 1 == game.getWidth() * game.getHeight())
	game.setLoaded(true);
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::tna(std::string &tmp, GameEngine &game) {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.addTeam(myArg[0]);
    game.getHudLeft().addTeam();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pnw(std::string &tmp, GameEngine &game) {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 6)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.addPlayer(StringToNumber<int>(myArg[0]),
		   StringToNumber<int>(myArg[1]),
		   StringToNumber<int>(myArg[2]),
		   StringToNumber<int>(myArg[3]),
		   StringToNumber<int>(myArg[4]),
		   myArg[5]);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::ppo(std::string &tmp, GameEngine &game) {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 4)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    Character &player = game.getPlayer(StringToNumber<int>(myArg[0]));
    game.getMap().getCell(player.getX(), player.getY()).removePlayer(player.getId());
    player.setPosition(StringToNumber<int>(myArg[1]),
		       StringToNumber<int>(myArg[2]),
		       StringToNumber<int>(myArg[3]));
    game.getMap().getCell(player.getX(), player.getY()).addPlayer(player.getId());
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::plv(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 2)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[0])).setLevel(StringToNumber<int>(myArg[1]));
    game.getPlayer(StringToNumber<int>(myArg[0])).setLevelUp(true);
    game.getPlayer(StringToNumber<int>(myArg[0])).setTimer(50);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pin(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 10)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    Character &player = game.getPlayer(StringToNumber<int>(myArg[0]));
    player.setIncantation(false);
    player.setPosition(StringToNumber<int>(myArg[1]), StringToNumber<int>(myArg[2]));
    player.setItem(ID_MEAT, StringToNumber<int>(myArg[3]));
    for (int i = 0; i < NB_OBJ; ++i) {
      player.setItem(i, StringToNumber<int>(myArg[4 + i]));
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pex(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[0])).setExpulse(true);
    game.getPlayer(StringToNumber<int>(myArg[0])).setTimer(100);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pbc(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[0])).setBroadcast(true);
    game.getPlayer(StringToNumber<int>(myArg[0])).setTimer(100);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pic(std::string &tmp, GameEngine &game)  {
  try {
     std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() < 4)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[3])).setIncantation(true);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pie(std::string &tmp, GameEngine &game)  {
  try {
     std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() < 3)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    std::vector<int>	playersID = game.getMap().getCell(StringToNumber<int>(myArg[0]),
				     StringToNumber<int>(myArg[1])).getPlayers();
    if (StringToNumber<int>(myArg[2]) == 1) {
      for (unsigned int i = 0; i < playersID.size(); ++i) {
	game.getPlayer(playersID[i]).setIncantation(false);
	game.getPlayer(playersID[i]).levelUp();
      }
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pfk(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[0])).setEgge(true);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pdr(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 2)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[0])).setPickFood(true);
    game.getPlayer(StringToNumber<int>(myArg[0])).setTimer(100);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pgt(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 2)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    if (StringToNumber<int>(myArg[1]) == ID_MEAT)
      game.getPlayer(StringToNumber<int>(myArg[0])).setPickFood(true);
    else
      game.getPlayer(StringToNumber<int>(myArg[0])).setPickStone(true);
    game.getPlayer(StringToNumber<int>(myArg[0])).setTimer(100);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::pdi(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() < 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getPlayer(StringToNumber<int>(myArg[0])).setDie(true);
    game.removePlayer(StringToNumber<int>(myArg[0]));
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::enw(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() < 4)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getMap().addEgg(StringToNumber<int>(myArg[2]), StringToNumber<int>(myArg[3]), StringToNumber<int>(myArg[0]));
    game.getHudLeft().addEgg();
    game.getPlayer(StringToNumber<int>(myArg[1])).setEgg(false);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::eht(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getMap().removeEgg(StringToNumber<int>(myArg[0]));
    game.getHudLeft().removeEgg();
    game.getHudLeft().addGhost();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::ebo(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.getMap().removeGhost(StringToNumber<int>(myArg[0]));
    game.getHudLeft().removeGhost();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::edi(std::string &, GameEngine &)  {
  try {
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::sgt(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.setTime(StringToNumber<int>(myArg[0]));
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::seg(std::string &tmp, GameEngine &game)  {
  try {
    std::vector<std::string>	myArg = this->getArg(tmp);

    if (myArg.size() != 1)
      throw ErrorClient("Wrong Argument", "CommandEngine");
    game.setWinner(myArg[0]);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::smg(std::string &, GameEngine &)  {
  try {

  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::suc(std::string &, GameEngine &)  {
  try {

  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}

void			CommandEngine::sbp(std::string &, GameEngine &)  {
  try {

  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "CommmandEngine");
  }
}
