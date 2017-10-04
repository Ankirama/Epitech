#ifndef OBJECT2D_HH_
# define OBJECT2D_HH_

# include "Error.hpp"
# include "GameEngine.hh"

# define IMG_PATH		"ressources/img/"
# define RESSOURCES_PATH	"ressources/"
# define SHADERS_PATH		"lib/gdl/shaders/"

class	Object2D {
private:
  std::string		m_path;
  gdl::BasicShader	m_shader;
  gdl::Texture		m_texture;
  gdl::Geometry		m_geometry;
  glm::vec3		m_position;
  glm::vec3		m_rotation;
  glm::vec3		m_scale;
  float			m_y;

public:
  Object2D(const std::string &, int, int, int);
  ~Object2D();

  void			Init(const float, const float, const float, const float);
  void			Draw(gdl::BasicShader);

  void			Translate(glm::vec3 const &);
  void			Rotate(glm::vec3 const &, float);
  void			Scale(glm::vec3 const &);

  int			getY() const;
  void			setY(const int, const int);

  glm::mat4		getTransformation();
};

#endif /* !OBJECT_HH_ */
