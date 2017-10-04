#include "Font.hh"

Font::Font(const std::string &fontName) {
  this->m_font = new sf::Font();
  if (!this->m_font->loadFromFile(fontName))
    throw ErrorClient("Unable to load font", "Font");
  this->m_text = new sf::Text();
}

Font::~Font() {
  delete this->m_font;
  delete this->m_text;
}

void	Font::setText(const std::string &str, int size, float x, float y) {
  this->m_text->setFont(*this->m_font);
  this->m_text->setString(str);
  this->m_text->setCharacterSize(size);
  this->m_text->setColor(sf::Color(237, 127, 16));
  this->m_text->setStyle(sf::Text::Bold);
  this->m_text->setPosition(x, y);
}

void	Font::setText(int value, int size, float x, float y) {
  try {
    std::string str = NumberToString<int>(value);

    this->m_text->setFont(*this->m_font);
    this->m_text->setString(str);
    this->m_text->setCharacterSize(size);
    this->m_text->setColor(sf::Color(237, 127, 16));
    this->m_text->setStyle(sf::Text::Bold);
    this->m_text->setPosition(x, y);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Font");
  }
}

void	Font::setText(const std::string &str) {
  this->m_text->setString(str);
}

void	Font::setText(int value) {
  try {
    std::string str = NumberToString<int>(value);

    this->m_text->setString(str);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Font");
  }
}

void	Font::setTextMiddle(const std::string &str, int size, int winX, int winY) {
  this->m_text->setFont(*this->m_font);
  this->m_text->setString(str);
  this->m_text->setCharacterSize(size);
  this->m_text->setColor(sf::Color(237, 127, 16));
  this->m_text->setStyle(sf::Text::Bold);
  this->m_text->setPosition(winX / 2 - this->m_text->getLocalBounds().width / 2,
			    winY / 6 - this->m_text->getLocalBounds().height / 2);
}

void	Font::draw(sf::RenderWindow *window) {
  window->draw(*this->m_text);
}
