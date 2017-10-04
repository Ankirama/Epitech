#ifndef CPP_BOMBERMAN_CAMERA_HH
# define CPP_BOMBERMAN_CAMERA_HH

# include "GameEngine.hh"

class Camera
{
public:
  Camera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 8.0f));
  ~Camera();

  //Getter
  glm::mat4	getProjection() const;
  glm::mat4	getTransformation() const;

  void	setCamera(float, float);
  void	defaultCamera();
  void	changeCamera(GameEngine *);

private:
  Camera	&operator=(Camera const &);
  Camera(Camera const &);

private:
  glm::vec3	m_position;
  glm::vec3	m_look;
  glm::mat4	m_projection;
  glm::mat4	m_transformation;
};

#endif /* !CPP_BOMBERMAN_CAMERA_HH */
