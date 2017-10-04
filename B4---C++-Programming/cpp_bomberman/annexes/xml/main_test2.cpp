#include <iostream>
#include <vector>
#include "tinyxml2.h"

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { std::cerr << "Error: " << a_eResult << std::endl; return a_eResult; }
#endif

typedef struct  s_color {
  int r;
  int g;
  int b;
}               t_color;

typedef struct	s_bomb {
	int a;
}								t_bomb;

std::vector<t_bomb *> bombs() {
	std::vector<t_bomb *> bombs;

	bombs.push_back(new t_bomb);
	bombs.push_back(new t_bomb);
	bombs.push_back(new t_bomb);
	return bombs;
}

void          player(tinyxml2::XMLElement *player) {
  const char  *name;
  int         position;
  int         direction;
  int         speed;
  t_color     color;
  const char  *filepath;
  int         score;
  int         left;
  int         right;
  int         up;
  int         down;
  int         bomb;
	bool					alive = false;

  name = player->FirstChildElement("name")->GetText();
	player->QueryBoolAttribute("state", &alive);
	std::cout << "ALIVE: " << alive << std::endl;
  player->FirstChildElement("position")->QueryIntText(&position);
  player->FirstChildElement("direction")->QueryIntText(&direction);
  player->FirstChildElement("speed")->QueryIntText(&speed);
  player->FirstChildElement("texture")->FirstChildElement("color")->FirstChildElement("r")->QueryIntText(&color.r);
  player->FirstChildElement("texture")->FirstChildElement("color")->FirstChildElement("g")->QueryIntText(&color.g);
  player->FirstChildElement("texture")->FirstChildElement("color")->FirstChildElement("b")->QueryIntText(&color.b);
  filepath = player->FirstChildElement("texture")->FirstChildElement("path")->GetText();
  player->FirstChildElement("score")->QueryIntText(&score);
  player->FirstChildElement("keys")->FirstChildElement("left")->QueryIntText(&left);
  player->FirstChildElement("keys")->FirstChildElement("right")->QueryIntText(&right);
  player->FirstChildElement("keys")->FirstChildElement("up")->QueryIntText(&up);
  player->FirstChildElement("keys")->FirstChildElement("down")->QueryIntText(&down);
  player->FirstChildElement("keys")->FirstChildElement("bomb")->QueryIntText(&bomb);
  std::cout << name << std::endl << position << std::endl << direction << std::endl << speed << std::endl << color.r
  << std::endl << color.g << std::endl << color.b << std::endl << filepath << std::endl << score << std::endl << left
  << std::endl << right
  << std::endl << up
  << std::endl << down
  << std::endl << bomb << std::endl;
}

int main() {
	std::vector<t_bomb *> test;
  tinyxml2::XMLDocument xmlDoc;
  tinyxml2::XMLError eResult = xmlDoc.LoadFile("test.xml");
  XMLCheckResult(eResult);
  tinyxml2::XMLNode *pRoot = xmlDoc.FirstChild();
  if (pRoot == 0)
    return tinyxml2::XML_ERROR_FILE_READ_ERROR;
  tinyxml2::XMLElement *pElement = xmlDoc.FirstChildElement("save")->FirstChildElement("players");
  if (pElement == 0) {std::cout << "error" << std::endl; return tinyxml2::XML_ERROR_PARSING_ELEMENT;}
  player(pElement->FirstChildElement("player"));
	test= bombs();
  return (0);
}
