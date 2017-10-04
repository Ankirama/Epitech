#include "GameEngine.hh"

GameEngine::GameEngine(int argc, char **argv){
  try {
    Parser	*parser = new Parser(argc, argv, USAGE, false);

    if (parser->getPort().empty())
      throw ErrorClient(USAGE, "Display");
    this->m_network = new Network("GRAPHIC", parser->getPort(),
				  parser->getHostName());
    this->m_tiles = new TilesIndex();
    this->m_cmdEngine = new CommandEngine();
    this->m_window = 0;
    this->m_clock = 0;
    this->m_loading = new sf::Sprite;
    this->m_loading->setTexture(this->m_tiles->getTexture("loading"));
    this->m_winBack = new sf::Sprite;
    this->m_winBack->setTexture(this->m_tiles->getTexture("win"));
    this->m_font = new Font("ressources/fonts/Achafsex.ttf");
    this->m_textLoaded = false;
    this->m_map = 0;
    this->m_width = 0;
    this->m_mousePressed = false;
    this->m_positionMouse = sf::Vector2i(0, 0);
    this->m_height = 0;
    this->m_loaded = false;
    this->m_win = false;
    this->m_hudVertical = 0;
    this->m_hud = 0;
    this->m_hudLeft = 0;
    this->m_time = 0;
    this->m_modeMove = CELL_MODE;
    this->m_playerSet = false;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

GameEngine::~GameEngine() {
  try {
    delete this->m_network;
    if (this->m_map)
      delete this->m_map;
    delete this->m_tiles;
    delete this->m_loading;
    if (this->m_hudVertical)
      delete this->m_hudVertical;
    if (this->m_hud)
      delete this->m_hud;
    if (this->m_hudLeft)
      delete this->m_hudLeft;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

void	GameEngine::init(int windowX, int windowY) {
  try {
    this->m_windowX = windowX;
    this->m_windowY = windowY;
    this->m_network->initNetwork();
    this->m_network->initFd();
    while (this->m_network->readCmd() != "BIENVENUE\n")
      this->m_network->fdIsset();
    this->m_network->sendCmd(this->m_network->getName());
    this->m_window = new sf::RenderWindow(sf::VideoMode(windowX, windowY),
					  "zappy_graphic", sf::Style::Resize);
    this->m_window->setFramerateLimit(60);
    this->m_window->setPosition(sf::Vector2i(0, 0));
    sf::Vector2f pos = sf::Vector2f(windowX - this->m_tiles->getTile("hudVertical").getWidth(),
				    windowY - this->m_tiles->getTile("hud").getHeight());
    this->m_view.setSize(pos);
    pos *= 0.5f;
    this->m_zoom = 1.0f;
    this->m_view.setCenter(pos);
    pos = sf::Vector2f(this->m_windowX, this->m_windowY);
    this->m_hudView.setSize(pos);
    pos *= 0.5f;
    this->m_hudView.setCenter(pos);
    this->m_hud = new HUD(windowX, windowY, new Tile(this->m_tiles->getTile("hud")));
    this->m_hudLeft = new HUDLeft(windowX, windowY,
				  new Tile(this->m_tiles->getTile("hudLeft")));
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

void	GameEngine::createMap(int width, int height) {
  try {
    if (width > 0 && height > 0){
      this->m_width = width;
      this->m_height = height;
      this->m_map = new Map(this->m_width, this->m_height, this->m_tiles,
			    this->m_windowX, this->m_windowY);
      this->m_hudVertical = new HUDVertical(this->m_windowX, this->m_windowY, new Tile (this->m_tiles->getTile("hudVertical")), this->m_map->getCurrentCell());
      this->m_hudLeft->setCells(this->m_width * this->m_height);
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

void	GameEngine::addPlayer(int id, int x, int y,
			      int orientation, int level,
			      const std::string &team) {
  try {
    this->m_players[id] = new Character(id, team, x, y, orientation,
					this->m_tiles->getTexture("grass").getSize(), level);
    this->m_players[id]->setWindowSize(this->m_windowX, this->m_windowY);
    this->m_players[id]->setMapSize(this->m_width, this->m_height);
    this->m_players[id]->setTile(new Tile(this->m_tiles->getTile("cUp")));
    this->m_players[id]->setTile(new Tile(this->m_tiles->getTile("cRight")));
    this->m_players[id]->setTile(new Tile(this->m_tiles->getTile("cDown")));
    this->m_players[id]->setTile(new Tile(this->m_tiles->getTile("cLeft")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("broadcast")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("pickfood")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("pickstone")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("incantation")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("levelup")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("expulse")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("death")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("egg3")));
    this->m_players[id]->setAction(new Tile(this->m_tiles->getTile("egg4")));
    this->m_hudLeft->addPlayer();
    if (this->m_playerSet == false) {
      this->m_playerSet = true;
      this->m_modeMove = CHARACTER_MODE;
      this->m_currentPlayer = this->m_players.find(id);
      this->m_hud->setPlayer((*this->m_currentPlayer).second);
    }
    this->m_map->getCell(x, y).addPlayer(id);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

void	GameEngine::removePlayer(int id) {
  if (this->m_players.find(id) != this->m_players.end()) {
    this->m_hudLeft->removePlayer();
    delete this->m_players[id];
    this->m_players.erase(id);
    this->m_currentPlayer = this->m_players.begin();
    this->m_hud->removePlayer();
  }
  if (this->m_players.size() == 0) {
    this->m_playerSet = false;
    this->m_modeMove = CELL_MODE;
    this->m_hud->setMode(CELL_MODE);
  }
}

void		GameEngine::setWin(bool value) {
  this->m_win = value;
}

void		GameEngine::setWinner(const std::string &name) {
  this->m_win = true;
  this->m_winner = name;
}

Character	&GameEngine::getPlayer(int id) {
  if (this->m_players.find(id) == this->m_players.end()) {
    throw ErrorClient("Unable to find id player", "GameEngine");
  }
  return *this->m_players[id];
}

void	GameEngine::addTeam(const std::string &name) {
  this->m_teams.push_back(name);
}

bool	GameEngine::isLoaded() {
  try {
    return this->m_loaded;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

Map	&GameEngine::getMap() const {
  try {
    return *this->m_map;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

int	GameEngine::getWidth() const {
  try {
    return this->m_width;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

int	GameEngine::getHeight() const {
  try {
    return this->m_height;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

HUDLeft	&GameEngine::getHudLeft() const {
  return *this->m_hudLeft;
}

void	GameEngine::setLoaded(bool value) {
  try {
    this->m_loaded = value;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

bool	GameEngine::inputMouse(sf::Event event) {
  if (!this->m_loaded || this->m_win)
    return false;
  switch (event.type) {
  case sf::Event::MouseWheelMoved :
    if (this->m_loaded) {
      if (event.mouseWheel.delta < 0) {
	  this->m_view.zoom(2.0f);
	  this->m_zoom *= 2.0f;
	}
      else {
	  this->m_view.zoom(.5f);
	  this->m_zoom *= .5f;
	}
    }
    break;
  case sf::Event::MouseButtonPressed :
    if (event.mouseButton.button == sf::Mouse::Left) {
      this->m_mousePressed = true;
      this->m_positionMouse = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
    }
    break;
  case sf::Event::MouseButtonReleased :
    if (event.mouseButton.button == sf::Mouse::Left) {
      this->m_mousePressed = false;
    }
  case sf::Event::MouseMoved :
    if (this->m_mousePressed && this->m_loaded && !this->m_win) {
      this->m_view.move(this->m_positionMouse.x - event.mouseMove.x,
			this->m_positionMouse.y - event.mouseMove.y);
      this->m_positionMouse = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
    }
    break;
  default:
    return false;
    break;
  }
  return true;
}

void	GameEngine::inputKeys(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
    case sf::Keyboard::Escape:
      this->m_window->close();
      break;
    case sf::Keyboard::Space:
      this->m_win = true;
      this->m_winner = "Meow";
      break;
    case sf::Keyboard::Return:
      if (!this->m_win && this->m_loaded) {
	if (this->m_modeMove == CELL_MODE && this->m_players.size() > 0)
	  this->m_modeMove = CHARACTER_MODE;
	else
	  this->m_modeMove = CELL_MODE;
	this->m_hud->setMode(this->m_modeMove);
      }
      break;
    case sf::Keyboard::Up:
      if (!this->m_win && this->m_loaded && this->m_modeMove == CELL_MODE) {
	this->m_map->setNextCell(this->m_width * -1);
      }
      break;
    case sf::Keyboard::Left:
      if (!this->m_win && this->m_loaded) {
	if (this->m_modeMove == CELL_MODE)
	  this->m_map->setNextCell(-1);
	else {
	  if (this->m_currentPlayer == this->m_players.begin())
	    this->m_currentPlayer = this->m_players.end();
	  --this->m_currentPlayer;
	  this->m_hud->setPlayer((*this->m_currentPlayer).second);
	}
      }
      break;
    case sf::Keyboard::Right:
      if (!this->m_win && this->m_loaded) {
	if (this->m_modeMove == CELL_MODE)
	  this->m_map->setNextCell(1);
	else {
	  ++this->m_currentPlayer;
	  if (this->m_currentPlayer == this->m_players.end())
	    this->m_currentPlayer = this->m_players.begin();
	  this->m_hud->setPlayer((*this->m_currentPlayer).second);
	}
      }
      break;
    case sf::Keyboard::Down:
      if (!this->m_win && this->m_loaded && this->m_modeMove == CELL_MODE) {
	this->m_map->setNextCell(this->m_width);
      }
      break;
    default:
      break;
    }
  }
}

void	GameEngine::inputKey() {
  try {
    sf::Event	event;

    while (this->m_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	this->m_window->close();
      else if (this->inputMouse(event) == false) {
	this->inputKeys(event);
      }
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

void	GameEngine::update() {
  try {
    this->inputKey();
    if (!this->m_win)
      this->m_cmdEngine->whichCmd(*this->m_network, *this);
    else if (this->m_win && !this->m_textLoaded) {
      this->m_font->setTextMiddle(std::string("WINNER: ") + this->m_winner, 42,
				  this->m_windowX, this->m_windowY);
      this->m_textLoaded = true;
    }
    if (this->m_loaded && !this->m_win) {
      if (this->m_modeMove == CHARACTER_MODE) {
	this->m_map->setCurrentCell((*this->m_currentPlayer).second->getX() + (*this->m_currentPlayer).second->getY() * this->m_width);
      }
      this->m_hudVertical->setCell(this->m_map->getCurrentCell());
      this->m_hudVertical->update();
      this->m_hud->update();
      this->m_hudLeft->update();
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "GameEngine");
  }
}

  void	GameEngine::draw() {
    try {
      this->m_window->clear();
      this->m_window->setView(this->m_view);
      if (!this->m_loaded) {
	this->m_window->draw(*this->m_loading);
      }
      else if (this->m_loaded && !this->m_win) {
	this->m_map->draw(this->m_window);
	for (std::map<int, Character *>::const_iterator it = this->m_players.begin();
	     it != this->m_players.end(); ++it) {
	  it->second->draw(this->m_window);
	}
	this->m_window->setView(this->m_hudView);
	this->m_hudVertical->draw(this->m_window);
	this->m_hud->draw(this->m_window);
	this->m_hudLeft->draw(this->m_window);
      }
      else {
	this->m_window->draw(*this->m_winBack);
	this->m_font->draw(this->m_window);
      }
      this->m_window->display();
    } catch (ErrorClient const &e) {
      throw ErrorClient(e.what(), "GameEngine");
    }
  }

  void	GameEngine::game() {
    try {
      this->m_clock = new sf::Clock;
      this->m_window->clear();
      while (this->m_window->isOpen()) {
	this->update();
	this->draw();
      }
    } catch (ErrorClient const &e) {
      throw ErrorClient(e.what(), "GameEngine");
    }
  }
