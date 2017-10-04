#include "XmlSave.hh"
#include "GameState.hh"

XmlSave::XmlSave(std::string const &filename, int nbPlayers, int nbAIs): m_ofs(filename.c_str()),
m_xmlWrite(this->m_ofs) {
  this->m_nbPlayers = nbPlayers;
  this->m_nbAIs = nbAIs;
  this->m_playersDone = false;
  this->m_AIDone = false;
  this->m_playersStarted = false;
  this->m_AIsStarted = false;
  this->m_idPlayer = 1;
  this->m_idAI = 1;
  this->m_xmlWrite << tag("save");
}

XmlSave::~XmlSave() {}

void XmlSave::saveGame() {
  std::vector<ACharacter *> players = GameState::Instance()->getPlayers();
  Maze &maze = GameState::Instance()->getMaze();

  for (unsigned int i = 0; i < players.size(); ++i) {
    if (players[i]->getType().compare("Player") == 0)
      this->savePlayer(*(static_cast<Player *>(players[i])));
    else
      this->saveAI(*(static_cast<IA *>(players[i])));
  }
  this->saveMaze(maze.getMaze(), maze.getWidth(), maze.getHeight());
}

bool XmlSave::savePlayer(Player &bomber) {
  if (this->m_playersDone)
    return false;
  if (!this->m_playersStarted) {
    this->m_playersStarted = true;
    this->m_xmlWrite
      << tag("players")
      << attribute("number") << this->m_nbPlayers;
  }
  this->m_xmlWrite
    << tag("player")
    << attribute("id") << this->m_idPlayer++
    << attribute("state") << bomber.getState()
    << tag("name")
    << data() << bomber.getName()
    << endtag()
    << tag("maxBombs")
    << data() << bomber.getMaxBombs()
    << endtag()
    << tag("position")
    << data() << bomber.getPosition()
    << endtag()
    << tag("direction")
    << data() << bomber.getDirection()
    << endtag()
    << tag("speed")
    << data() << bomber.getSpeed()
    << endtag()
    << tag("rangeBomb")
    << data() << bomber.getRangeBomb()
    << endtag();
  this->writeTexture(bomber.getTexturePath());
  this->m_xmlWrite
    << tag("score")
    << data() << bomber.getScore()
    << endtag();
  this->writeKeys(bomber.getKeyLeft(), bomber.getKeyRight(), bomber.getKeyUp(),
		  bomber.getKeyDown(), bomber.getKeyBomb());
  this->writeBombs(bomber.getBombs());
  this->m_xmlWrite
    << endtag("player");
  --this->m_nbPlayers;
  if ((this->m_playersDone = this->m_nbPlayers == 0 ? true: false)) {
    this->m_xmlWrite
      << endtag("players");
  }
  return true;
}

bool XmlSave::saveAI(IA &bomber) {
  if (!this->m_playersDone || this->m_AIDone)
    return false;
  if (!this->m_AIsStarted) {
    this->m_AIsStarted = true;
    this->m_xmlWrite
      << tag("AIs")
      << attribute("number") << this->m_nbAIs;
  }
  this->m_xmlWrite
    << tag("AI")
    << attribute("id") << this->m_idAI++
    << attribute("state") << bomber.getState()
    << tag("difficulty")
    << data() << static_cast<int>(bomber.getDifficulty())
    << endtag()
    << tag("maxBombs")
    << data() << bomber.getMaxBombs()
    << endtag()
    << tag("position")
    << data() << bomber.getPosition()
    << endtag()
    << tag("direction")
    << data() << bomber.getDirection()
    << endtag()
    << tag("speed")
    << data() << bomber.getSpeed()
    << endtag()
    << tag("rangeBomb")
    << data() << bomber.getRangeBomb()
    << endtag();
  this->writeTexture(bomber.getTexturePath());
  this->writeBombs(bomber.getBombs());
  this->m_xmlWrite
    << endtag("AI");
  --this->m_nbAIs;
  if ((this->m_AIDone = this->m_nbAIs == 0 ? true: false)) {
    this->m_xmlWrite
      << endtag("AIs");
  }
  return true;
}

bool XmlSave::saveMaze(char const *map, int width, int height) {
  if (!this->m_playersDone || !this->m_AIDone)
    return false;
  this->m_xmlWrite
    << tag("maze")
    << tag("size")
    << tag("width")
    << data() << width
    << endtag()
    << tag("height")
    << data() << height
    << endtag("size")
    << tag("maze")
    << data() << map
    << endtag("maze");
  return false;
}

void XmlSave::writeTexture(std::string const& filepath) {
  this->m_xmlWrite
    << tag("texture")
    << data() << filepath
    << endtag();
}

void XmlSave::writeKeys(int left, int right, int up, int down, int bomb) {
  this->m_xmlWrite
    << tag("keys")
    << tag("left")
    << data() << left
    << endtag()
    << tag("right")
    << data() << right
    << endtag()
    << tag("up")
    << data() << up
    << endtag()
    << tag("down")
    << data() << down
    << endtag()
    << tag("bomb")
    << data() << bomb
    << endtag("keys");
}

void XmlSave::writeBombs(std::list<Bomb *> const &bombs) {
  int	i = 0;
  this->m_xmlWrite
    << tag("bombs")
    << attribute("number") << bombs.size();
  for (std::list<Bomb *>::const_iterator it = bombs.begin(); it != bombs.end(); ++it) {
    this->m_xmlWrite
      << tag("bomb")
      << attribute("id") << ++i;
    this->writeTexture((*it)->getTexturePath());
    this->m_xmlWrite
      << tag("time")
      << data() << (*it)->getDelay()
      << endtag()
      << tag("range")
      << data() << (*it)->getRange()
      << endtag()
      << tag("position")
      << data() << (*it)->getPosition()
      << endtag("bomb");
      }
  this->m_xmlWrite << endtag("bombs");
}
