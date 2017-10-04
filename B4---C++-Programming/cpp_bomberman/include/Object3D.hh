#ifndef OBJECT3D_HH_
# define OBJECT3D_HH_

# include "Error.hpp"
# include "GameEngine.hh"
# include <string>


# define IMG_PATH	"ressources/img/"
# define ANIM_PATH	"ressources/animation/"
# define SHADERS_PATH	"lib/gdl/shaders/"

class	Object3D
{
protected:
  std::string		m_path;
  gdl::Texture		m_texture;
  gdl::Geometry		m_geometry;
  glm::vec3		m_position;
  glm::vec3		m_rotation;
  glm::vec3		m_scale;

private:
  Object3D();

public:
  // Constructor
  Object3D(std::string const &, glm::vec3, glm::vec3, glm::vec3);

  // Destructor
  ~Object3D();

  void	initialize(const float = 0.5, const float = 0.5, const float = 0.5);
  void	draw(gdl::BasicShader);

  // Geometric transformation
  void		translate(glm::vec3 const &);
  void		rotate(glm::vec3 const &, float);
  void		scale(glm::vec3 const &);
  glm::mat4	getTransformation();

  // Setter
  void	setPosition(glm::vec3 position) { this->m_position = position; }
  void	setRotation(glm::vec3 rotation) { this->m_rotation = rotation; }
  void	setScale(glm::vec3 scale) { this->m_scale = scale; }

  // Getter
  glm::vec3	getPosition() const { return this->m_position; }
  glm::vec3	getRotation() const { return this->m_rotation; }
};

#endif /* !OBJECT3D_HH_ */
