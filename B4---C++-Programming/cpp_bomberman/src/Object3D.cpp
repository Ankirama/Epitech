#include "Object3D.hh"

// Constructor
Object3D::Object3D(std::string const &path, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : m_path(path), m_position(position), m_rotation(rotation), m_scale(scale) {
}

Object3D::~Object3D()	{
}

void	Object3D::initialize(float x, float y, float z)	{
  if (this->m_texture.load(this->m_path.c_str()) == false)	{
    throw ErrorBomberman("Cannot load the texture");
  }
  // 1ère face
  this->m_geometry.setColor(glm::vec4(1, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(x, -y, z));
  this->m_geometry.pushVertex(glm::vec3(x, y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // 2ème face
  this->m_geometry.setColor(glm::vec4(1, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(x, -y, -z));
  this->m_geometry.pushVertex(glm::vec3(x, y, -z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, -z));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, -z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // 3ème face
  this->m_geometry.setColor(glm::vec4(1, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(x, -y, -z));
  this->m_geometry.pushVertex(glm::vec3(x, y, -z));
  this->m_geometry.pushVertex(glm::vec3(x, y, z));
  this->m_geometry.pushVertex(glm::vec3(x, -y, z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // 4ème face
  this->m_geometry.setColor(glm::vec4(1, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, -z));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, -z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));


  // 5ème face
  this->m_geometry.setColor(glm::vec4(1, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(x, y, z));
  this->m_geometry.pushVertex(glm::vec3(x, y, -z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, -z));
  this->m_geometry.pushVertex(glm::vec3(-x, y, z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  // 6ème face
  this->m_geometry.setColor(glm::vec4(1, 1, 1, 1));
  this->m_geometry.pushVertex(glm::vec3(x, -y, -z));
  this->m_geometry.pushVertex(glm::vec3(x, -y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, z));
  this->m_geometry.pushVertex(glm::vec3(-x, -y, -z));

  this->m_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  this->m_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  this->m_geometry.pushUv(glm::vec2(0.0f, 1.0f));

  this->m_geometry.build();
}


void	Object3D::draw(gdl::BasicShader shader)	{
  this->m_texture.bind();
  this->m_geometry.draw(shader, this->getTransformation(), GL_QUADS);
}

// Geometric transformation
void	Object3D::translate(glm::vec3 const &v)	{
  this->m_position += v;
}

void	Object3D::rotate(glm::vec3 const &axis, float angle)	{
  this->m_rotation += axis * angle;
}

void	Object3D::scale(glm::vec3 const &scale)	{
  this->m_scale *= scale;
}

glm::mat4	Object3D::getTransformation()	{
  glm::mat4	transform(1);

  transform = glm::translate(transform, this->m_position);
  transform = glm::rotate(transform, this->m_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->m_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->m_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->m_scale);
  return (transform);
}
