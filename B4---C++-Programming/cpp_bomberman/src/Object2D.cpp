#include "Object2D.hh"

Object2D::Object2D(const std::string &name, int x, int y, int z) : m_path(name),
							       m_position(x, y, z),
							       m_rotation(0, 0, 0),
							       m_scale(1, 1, 1){
  this->m_y = x;
}

Object2D::~Object2D(){
}

void	Object2D::Init(const float x, const float y, const float z, const float trans){
  if (this->m_texture.load(this->m_path.c_str()) == false){
    throw ErrorBomberman(std::string("[") + this->m_path + std::string("]: Cannot load the texture"), "Object2D");
  }
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  this->m_geometry.setColor(glm::vec4(1, 0, 0, 1));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // Background (800 / 600) : 38.5 / 51.0
  this->m_geometry.setColor(glm::vec4(1, 1, 1, trans));
  this->m_geometry.pushVertex(glm::vec3(x, -y, z));
  this->m_geometry.pushVertex(glm::vec3(x, y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->m_geometry.setColor(glm::vec4(0, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->m_geometry.setColor(glm::vec4(1, 0, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->m_geometry.setColor(glm::vec4(0, 1, 0, 1));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->m_geometry.setColor(glm::vec4(0, 0, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));
  this->m_geometry.pushVertex(glm::vec3(0.0, 0.0, 0.0));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->m_geometry.build();
}

void	Object2D::Draw(gdl::BasicShader shader){
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // shader.bind();
  this->m_texture.bind();
  this->m_geometry.draw(shader, this->getTransformation(), GL_QUADS);
}

void	Object2D::Translate(glm::vec3 const &v) {
  this->m_position += v;
}

void	Object2D::Rotate(glm::vec3 const &axis, float angle){
  this->m_rotation += axis * angle;
}

void	Object2D::Scale(glm::vec3 const & scale){
  this->m_scale *= scale;
}

int	Object2D::getY() const{
  return (this->m_y);
}

void	Object2D::setY(const int y, const int x){
  this->m_position = glm::vec3(y, x, 0);
}

glm::mat4	Object2D::getTransformation(){
  glm::mat4	tranform(1);
  tranform = glm::rotate(tranform, this->m_rotation.y, glm::vec3(0, 1, 0));
  tranform = glm::rotate(tranform, this->m_rotation.z, glm::vec3(0, 0, 1));
  tranform = glm::translate(tranform, this->m_position);
  tranform = glm::scale(tranform, this->m_scale);
  return (tranform);
}
