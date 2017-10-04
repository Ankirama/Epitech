#include "Animation.hh"

Animation::Animation(glm::vec3 position,
		     glm::vec3 rotation,
		     glm::vec3 scale,
		     std::string const &path) : Object3D("", position, rotation, scale), m_path(path)	{
}

Animation::~Animation()	{
}

void	Animation::initialize()	{
  if (this->m_model.load(this->m_path) == false)
    throw ErrorBomberman("Cannot load the model !", "Animation");
  this->m_model.setCurrentAnim(0);
}

void	Animation::draw(gdl::AShader &shader, gdl::Clock const &clock)	{
  this->m_model.draw(shader, getTransformation(), clock.getElapsed());
}
