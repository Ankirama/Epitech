# include "BoxBonus.hh"

BoxBonus::BoxBonus(unsigned int position): m_position(position) {
  int	i;
  std::string	path = "./annexes/tutoriel/";

  i = 0;
  std::srand(std::time(0));
  i = std::rand() % 6;
  switch (i)
    {
    case 0:
      this->m_bonus = "upBomb";
      break;
    case 1:
      this->m_bonus = "upRange";
      break;
    case 2:
      this->m_bonus = "upSpeed";
      break;
    case 3:
      this->m_bonus = "downBomb";
      break;
    case 4:
      this->m_bonus = "downRange";
      break;
    default:
      this->m_bonus = "downSpeed";
      break;
    }
  path = path + this->m_bonus +".tga";
  this->m_animation = new Animation(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.1, 0.1, 0.1), std::string(path));
}

BoxBonus::~BoxBonus()	{
}

Animation	*BoxBonus::getAnimation() const	{
  return (this->m_animation);
}

unsigned int	BoxBonus::getPosition() {
  return (this->m_position);
}

void		BoxBonus::setPosition(unsigned int position) {
  this->m_position = position;
}

std::string	BoxBonus::getBonus() {
  return (this->m_bonus);
}
