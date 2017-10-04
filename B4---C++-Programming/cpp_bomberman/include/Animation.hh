#ifndef ANIMATION_HH_
# define ANIMATION_HH_

# include "Object3D.hh"
# include "Error.hpp"
# include <string>

class	Animation : public Object3D
{
private:
  std::string	m_path;
  gdl::Model	m_model;

  Animation();

public:
  // Constructor
  Animation(glm::vec3, glm::vec3, glm::vec3, std::string const &);

  // Destructor
  ~Animation();

  // Getter
  std::string	const &getTexturePath() const	{ return this->m_path; }

  // Setter
  void	setPath(std::string const &path)	{ this->m_path = path; }
  // Other
  void	initialize();
  void	draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !ANIMATION_HH_ */
