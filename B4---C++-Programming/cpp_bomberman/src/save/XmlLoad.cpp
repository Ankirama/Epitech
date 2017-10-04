#include "GameState.hh"
#include "XmlLoad.hh"
#include "Error.hpp"

XmlLoad::XmlLoad(std::string const &filename) {
  if(this->m_xmlDoc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS)
    throw ErrorBomberman("Unable to load save", "XMLLOAD");
}

XmlLoad::~XmlLoad() {
}

void XmlLoad::loadSave() {
  GameState::Instance()->setLoad(true);
  GameState::Instance()->setMaze(this->createMaze(this->m_xmlDoc.FirstChildElement("save")->FirstChildElement("maze")));
  GameState::Instance()->setPlayers(this->loadBombers(this->m_xmlDoc.FirstChildElement("save"), GameState::Instance()->getMaze().getWidth(), GameState::Instance()->getMaze().getHeight()));
  GameState::Instance()->setWidth(GameState::Instance()->getMaze().getWidth());
  GameState::Instance()->setHeight(GameState::Instance()->getMaze().getHeight());
}

std::vector<ACharacter *> XmlLoad::loadBombers(tinyxml2::XMLElement *root, int width, int height) const {
  std::vector<ACharacter *>bombermans;
  tinyxml2::XMLElement *players = root->FirstChildElement("players");
  tinyxml2::XMLElement *AIs = root->FirstChildElement("AIs");

  tinyxml2::XMLElement *pListPlayers = players->FirstChildElement("player");
  while (pListPlayers) {
    bombermans.push_back(this->createPlayer(pListPlayers));
    pListPlayers = pListPlayers->NextSiblingElement("player");
  }
  tinyxml2::XMLElement *pListAIs = AIs->FirstChildElement("AI");
  while (pListAIs) {
    bombermans.push_back(this->createAI(pListAIs, width, height));
    pListAIs = pListAIs->NextSiblingElement("AI");
  }
  return bombermans;
}

int XmlLoad::getIntValue(tinyxml2::XMLElement *root, std::string const &name) const {
  int value;

  root->FirstChildElement(name.c_str())->QueryIntText(&value);
  return value;
}

float XmlLoad::getFloatValue(tinyxml2::XMLElement *root, std::string const &name) const {
  float value;

  root->FirstChildElement(name.c_str())->QueryFloatText(&value);
  return value;
}

unsigned int XmlLoad::getUnIntValue(tinyxml2::XMLElement *root, std::string const &name) const {
  unsigned int value;

  root->FirstChildElement(name.c_str())->QueryUnsignedText(&value);
  return value;
}

bool XmlLoad::getBoolValue(tinyxml2::XMLElement *root, std::string const &name) const {
  bool value;

  root->QueryBoolAttribute(name.c_str(), &value);
  return value;
}

Player *XmlLoad::createPlayer(tinyxml2::XMLElement *player) const {
  Player        *newPlayer;

  newPlayer = new Player(std::string(player->FirstChildElement("name")->GetText()),
			 this->getUnIntValue(player, "position"));
  newPlayer->setMaxBombs(this->getIntValue(player, "maxBombs"));
  newPlayer->setState(this->getBoolValue(player, "state"));
  newPlayer->setDirection(static_cast<eDirection>(this->getIntValue(player, "direction")));
  newPlayer->setSpeed(this->getFloatValue(player, "speed"));
  newPlayer->setRangeBomb(this->getUnIntValue(player, "rangeBomb"));
  newPlayer->setTexturePath(std::string(player->FirstChildElement("texture")->GetText()));
  newPlayer->setScore(this->getUnIntValue(player, "score"));
  newPlayer->setKeyLeft(this->getIntValue(player->FirstChildElement("keys"), "left"));
  newPlayer->setKeyRight(this->getIntValue(player->FirstChildElement("keys"), "right"));
  newPlayer->setKeyUp(this->getIntValue(player->FirstChildElement("keys"), "up"));
  newPlayer->setKeyDown(this->getIntValue(player->FirstChildElement("keys"), "down"));
  newPlayer->setKeyBomb(this->getIntValue(player->FirstChildElement("keys"), "bomb"));
  newPlayer->setBombs(this->createBombs(player->FirstChildElement("bombs")));
  return (newPlayer);
}

IA  *XmlLoad::createAI(tinyxml2::XMLElement *ai, int width, int height) const {
  IA  *newAI;

  newAI = new IA(this->getUnIntValue(ai, "position"),
		 static_cast<eDifficulty>(this->getIntValue(ai, "difficulty")),
		 width, height);
  newAI->setMaxBombs(this->getIntValue(ai, "maxBombs"));
  newAI->setState(this->getBoolValue(ai, "state"));
  newAI->setDirection(static_cast<eDirection>(this->getIntValue(ai, "direction")));
  newAI->setSpeed(this->getFloatValue(ai, "speed"));
  newAI->setRangeBomb(this->getUnIntValue(ai, "rangeBomb"));
  newAI->setTexturePath(std::string(ai->FirstChildElement("texture")->GetText()));
  newAI->setBombs(this->createBombs(ai->FirstChildElement("bombs")));
  return (newAI);
}

std::list <Bomb *>  XmlLoad::createBombs(tinyxml2::XMLElement *bombs) const {
  std::list<Bomb *> newBombs;
  tinyxml2::XMLElement *pListBombs = bombs->FirstChildElement("bomb");
  while (pListBombs) {
    Bomb *newBomb = new Bomb(this->getUnIntValue(pListBombs, "position"));
    newBomb->setDelay(this->getUnIntValue(pListBombs, "time"));
    newBomb->setRange(this->getUnIntValue(pListBombs, "range"));
    newBomb->setTexturePath(std::string(pListBombs->FirstChildElement("texture")->GetText()));
    newBombs.push_back(newBomb);
    pListBombs = pListBombs->NextSiblingElement("bomb");
  }
  return newBombs;
}

Maze *XmlLoad::createMaze(tinyxml2::XMLElement *maze) const {
  Maze *newMaze;
  char *map;

  map = const_cast<char *>(maze->FirstChildElement("maze")->GetText());
  newMaze = new Maze(this->getIntValue(maze->FirstChildElement("size"), "width"),
  this->getIntValue(maze->FirstChildElement("size"), "height"), map);
  return newMaze;
}
