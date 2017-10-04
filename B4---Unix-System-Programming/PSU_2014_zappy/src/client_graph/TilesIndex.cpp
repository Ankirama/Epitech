#include "TilesIndex.hh"

TilesIndex::TilesIndex() {
  try {
    this->initTextures();
    this->initTiles();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "TileIndex");
  }
}

TilesIndex::~TilesIndex() {}

void	TilesIndex::initTextures() {
  try {
    this->m_texture = new Texture();
    this->m_texture->loadTexture("win", "ressources/win.png");
    this->m_texture->loadTexture("ghost", "ressources/animations/ghost.png");
    this->m_texture->loadTexture("hudVertical", "ressources/animations/hud-vertical.png");
    this->m_texture->loadTexture("hudLeft", "ressources/animations/hud_vertical_left.png");
    this->m_texture->loadTexture("hud", "ressources/animations/HUD.png");
    this->m_texture->loadTexture("loading", "ressources/loading.png");
    this->m_texture->loadTexture("grass", "ressources/tiles/grass.png");
    this->m_texture->loadTexture("egg1", "ressources/tiles/little_egg2.png");
    this->m_texture->loadTexture("egg2", "ressources/tiles/egg2.png");
    this->m_texture->loadTexture("linemate", "ressources/tiles/linemate.png");
    this->m_texture->loadTexture("deraumere", "ressources/tiles/deraumere.png");
    this->m_texture->loadTexture("sibur", "ressources/tiles/sibur.png");
    this->m_texture->loadTexture("mendiane", "ressources/tiles/mendiane.png");
    this->m_texture->loadTexture("phiras", "ressources/tiles/phiras.png");
    this->m_texture->loadTexture("thystame", "ressources/tiles/thystame.png");
    this->m_texture->loadTexture("cLeft", "ressources/animations/left.png");
    this->m_texture->loadTexture("cRight", "ressources/animations/right.png");
    this->m_texture->loadTexture("cUp", "ressources/animations/up.png");
    this->m_texture->loadTexture("cDown", "ressources/animations/down.png");
    this->m_texture->loadTexture("food", "ressources/tiles/burger2.png");
    this->m_texture->loadTexture("levelup", "ressources/tiles/up.png");
    this->m_texture->loadTexture("broadcast", "ressources/tiles/blabla.png");
    this->m_texture->loadTexture("pickfood", "ressources/tiles/food.png");
    this->m_texture->loadTexture("incantation", "ressources/tiles/incante.png");
    this->m_texture->loadTexture("pickstone", "ressources/tiles/stone.png");
    this->m_texture->loadTexture("expulse", "ressources/tiles/kick.png");
    this->m_texture->loadTexture("death", "ressources/tiles/mort.png");
    this->m_texture->loadTexture("egg3", "ressources/tiles/little_egg1.png");
    this->m_texture->loadTexture("egg4", "ressources/tiles/emote_egg.png");
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "TileIndex");
  }
}

void	TilesIndex::initTiles() {
  try {
    this->m_tileIndex["grass"] = new Tile(GRASS, this->m_texture->getTexture("grass"),
					  TILEMAX, 1);
    this->m_tileIndex["egg1"] = new Tile(EGG1, this->m_texture->getTexture("egg1"),
					 TILEMAX, 1);
    this->m_tileIndex["egg2"] = new Tile(EGG2, this->m_texture->getTexture("egg2"),
					 TILEMAX, 1);
    this->m_tileIndex["linemate"] = new Tile(LINEMATE, this->m_texture->getTexture("linemate"),
					     TILEMAX, 1);
    this->m_tileIndex["deraumere"] = new Tile(DERAUMERE, this->m_texture->getTexture("deraumere"),
					      TILEMAX, 1);
    this->m_tileIndex["sibur"] = new Tile(SIBUR, this->m_texture->getTexture("sibur"),
					  TILEMAX, 1);
    this->m_tileIndex["mendiane"] = new Tile(MENDIANE, this->m_texture->getTexture("mendiane"),
					     TILEMAX, 1);
    this->m_tileIndex["phiras"] = new Tile(PHIRAS, this->m_texture->getTexture("phiras"),
					   TILEMAX, 1);
    this->m_tileIndex["thystame"] = new Tile(THYSTAME, this->m_texture->getTexture("thystame"),
					     TILEMAX, 1);
    this->m_tileIndex["cLeft"] = new Tile(CHARACTER, this->m_texture->getTexture("cLeft"),
					      TILEMAX, 1);
    this->m_tileIndex["cRight"] = new Tile(CHARACTER, this->m_texture->getTexture("cRight"),
					      TILEMAX, 1);

    this->m_tileIndex["cUp"] = new Tile(CHARACTER, this->m_texture->getTexture("cUp"),
					      TILEMAX, 1);
    this->m_tileIndex["cDown"] = new Tile(CHARACTER, this->m_texture->getTexture("cDown"),
					      TILEMAX, 1);
    this->m_tileIndex["food"] = new Tile(FOOD, this->m_texture->getTexture("food"),
					 TILEMAX, 1);
    this->m_tileIndex["ghost"] = new Tile(VOID, this->m_texture->getTexture("ghost"), TILEMAX, 1);
    this->m_tileIndex["hudVertical"] = new Tile(VOID, this->m_texture->getTexture("hudVertical"), TILEMAX, 1);
    this->m_tileIndex["hudLeft"] = new Tile(VOID, this->m_texture->getTexture("hudLeft"), TILEMAX, 1);
    this->m_tileIndex["hud"] = new Tile(VOID, this->m_texture->getTexture("hud"), TILEMAX, 1);
    this->m_tileIndex["levelup"] = new Tile(CHARACTER, this->m_texture->getTexture("levelup"), TILEMAX, 1);
    this->m_tileIndex["broadcast"] = new Tile(CHARACTER, this->m_texture->getTexture("broadcast"), TILEMAX, 1);
    this->m_tileIndex["pickfood"] = new Tile(CHARACTER, this->m_texture->getTexture("pickfood"), TILEMAX, 1);
    this->m_tileIndex["incantation"] = new Tile(CHARACTER, this->m_texture->getTexture("incantation"), TILEMAX, 1);
    this->m_tileIndex["pickstone"] = new Tile(CHARACTER, this->m_texture->getTexture("pickstone"), TILEMAX, 1);
    this->m_tileIndex["expulse"] = new Tile(CHARACTER, this->m_texture->getTexture("expulse"), TILEMAX, 1);
    this->m_tileIndex["death"] = new Tile(CHARACTER, this->m_texture->getTexture("death"), TILEMAX, 1);
    this->m_tileIndex["egg3"] = new Tile(CHARACTER, this->m_texture->getTexture("egg3"), TILEMAX, 1);
    this->m_tileIndex["egg4"] = new Tile(CHARACTER, this->m_texture->getTexture("egg4"), TILEMAX, 1);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "TileIndex");
  }
}

Tile	&TilesIndex::getTile(const std::string &name) {
  return *this->m_tileIndex[name];
}

sf::Texture	&TilesIndex::getTexture(const std::string &texture) const {
  return this->m_texture->getTexture(texture);
}
