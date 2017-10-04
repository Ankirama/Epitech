# include "Camera.hh"
//glm::vec3(0.0f, 0.0f, 8.0f)
Camera::Camera(glm::vec3 pos)	{
  this->m_position = pos;
  this->m_look = glm::vec3(0.0f, 0.0f, 0.0f);
  this->m_projection = glm::perspective(60.0f, 16.0f / 9.0f, 0.1f, 100.0f);
  this->m_transformation = glm::lookAt(m_position,
				       m_look,
				       glm::vec3(0.0f, 0.01f, 0.0f));
};



Camera::~Camera()	{
};

glm::mat4	Camera::getProjection() const	{
  return (this->m_projection);
};

glm::mat4	Camera::getTransformation() const	{
  return (this->m_transformation);
};

void	Camera::defaultCamera() {
  this->m_transformation = glm::lookAt(glm::vec3(0, 0, 30), glm::vec3(0, 0, 0),
						 glm::vec3(0, 0.1, 0));
}

void	Camera::setCamera(float x, float y)	{
   m_position = m_position + glm::vec3(x, y, 0.0f);
   m_look = m_look + glm::vec3(x, y, 0.0f);
  this->m_transformation = glm::lookAt(m_position, m_look, glm::vec3(0.0f, 1.0f, 0.0f));
};

void	Camera::changeCamera(GameEngine *game) {
  game->getShader().setUniform("view", this->getTransformation());
  game->getShader().setUniform("projection", this->getProjection());
}
