//
// Created by ankirama on 5/22/15.
//

#include "GenerateText.hh"

GenerateText::GenerateText(const std::string& test, float x, float y) : m_str(test){
    this->m_posX = x;
    this->m_posY = y;
    for (unsigned int i = 0; i < test.size(); ++i) {
        Object2D *letter;
        if (test[i] != ' ') {
          letter = this->getLetterObj(test[i], x + i * 2.0, y);
          if (letter == 0) {
	          std::cerr << "error: [" << test[i] << "]: unable to load this letter in generateMaze" << std::endl;
	          return ;
          }
        }
      this->m_text.push_back(letter);
    }
}

GenerateText::~GenerateText() {
    for (unsigned int i = 0; i < this->m_text.size(); ++i) {
        delete this->m_text[i];
    }
    this->m_text.clear();
}

void GenerateText::Init() {
    for (unsigned int i = 0; i < this->m_text.size(); ++i) {
        this->m_text[i]->Init(1.5, 1.0, 1.0, 1.0);
    }
}

Object2D    *GenerateText::getLetterObj(char letter, float x, float y) {
    char up;
    std::string    upper;
    std::stringstream ss;

    up = (letter >= 'a' && letter <= 'z' ? letter - 32 : letter);
    ss << up;
    ss >> upper;
    if (!((upper[0] >= 'A' && upper[0] <= 'Z') || (upper[0] >= '0' && upper[0] <= '9')))
        return 0;
    return (new Object2D(PATH_TXT_NORMAL(upper), y, x, 0.0));
}

void    GenerateText::Draw(gdl::BasicShader shader) {
    for (std::vector<Object2D *>::const_iterator it = this->m_text.begin(); it != this->m_text.end(); ++it) {
        (*it)->Draw(shader);
    }
}

int	GenerateText::getY() const{
  return (this->m_text.front()->getY());
}

std::string const & GenerateText::getStr() const {
  return (this->m_str);
}
