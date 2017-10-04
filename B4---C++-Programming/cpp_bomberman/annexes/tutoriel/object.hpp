#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

class AObject
{
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

public:
  AObject():  _position(0, 0, 0), _rotation(0, 90, 0), _scale(0.01, 0.01, 0.01)	{
  }

  virtual ~AObject()	{
  }

  virtual bool	initialize()	{
    return (true);
  }

  virtual void	update(gdl::Clock const &, gdl::Input &)	{
  }

  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;

  void	translate(glm::vec3 const &v)	{
    _position += v;
  }

  void	rotate(glm::vec3 const & axis, float angle)	{
    _rotation += axis * angle;
  }

  void	scale(glm::vec3 const & scale)	{
    _scale *= scale;
  }

  glm::mat4	getTransformation()	{
    glm::mat4	transform(1);

    transform = glm::translate(transform, _position);
    transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
    transform = glm::scale(transform, _scale);
    return (transform);
  }
};

class Animation : public AObject
{
private:
  gdl::Model	_model;
  float		_speed;

public:
  Animation()	{}
  virtual	~Animation()	{}

  virtual bool	initialize()	{
    _speed = 10.0f;
    if (_model.load("annexes/tutoriel/fire.fbx") == false)	{
      std::cerr << "Cannot load lol" << std::endl;
    }
    std::cout << _model.getAnimationFrameNumber(0) << std::endl;
    if (_model.createSubAnim(0, "Run", 0, 30) == false || _model.createSubAnim(0, "Stand", 0, 10) == false)
      std::cerr << "LOL" << std::endl;
    _model.setCurrentAnim(0);
    return (true);
  }

  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock)	{
    _model.draw(shader, getTransformation(), clock.getElapsed());
  }
};

class Cube : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;

public:
  Cube()	{}
  virtual	~Cube()	{}

  virtual bool	initialize()	{
    _speed = 10.0f;
    if (_texture.load("ressources/img/Carmen.tga") == false)	{
      std::cerr << "Cannot load Lol" << std::endl;
      return (false);
    }
    _geometry.setColor(glm::vec4(1, 1, 1, 1));

    // 1ere face
    _geometry.pushVertex(glm::vec3(5, -5, 5));
    _geometry.pushVertex(glm::vec3(5, 5, 5));
    _geometry.pushVertex(glm::vec3(-5, 5, 5));
    _geometry.pushVertex(glm::vec3(-5, -5, 5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(1, 1, 1, 1));

    // 2eme face
    _geometry.pushVertex(glm::vec3(5, -5, -5));
    _geometry.pushVertex(glm::vec3(5, 5, -5));
    _geometry.pushVertex(glm::vec3(-5, 5, -5));
    _geometry.pushVertex(glm::vec3(-5, -5, -5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(1, 1, 1, 1));

    // 3eme face
    _geometry.pushVertex(glm::vec3(5, -5, -5));
    _geometry.pushVertex(glm::vec3(5, 5, -5));
    _geometry.pushVertex(glm::vec3(5, 5, 5));
    _geometry.pushVertex(glm::vec3(5, -5, 5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(1, 1, 1, 1));

    // 4eme face
    _geometry.pushVertex(glm::vec3(-5, -5, 5));
    _geometry.pushVertex(glm::vec3(-5, 5, 5));
    _geometry.pushVertex(glm::vec3(-5, 5, -5));
    _geometry.pushVertex(glm::vec3(-5, -5, -5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(1, 1, 1, 1));

    // 5eme face
    _geometry.pushVertex(glm::vec3(5, 5, 5));
    _geometry.pushVertex(glm::vec3(5, 5, -5));
    _geometry.pushVertex(glm::vec3(-5, 5, -5));
    _geometry.pushVertex(glm::vec3(-5, 5, 5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.setColor(glm::vec4(1, 1, 1, 1));

    // 6eme face
    _geometry.pushVertex(glm::vec3(5, -5, 5));
    _geometry.pushVertex(glm::vec3(5, -5, 5));
    _geometry.pushVertex(glm::vec3(-5, -5, 5));
    _geometry.pushVertex(glm::vec3(-5, -5, -5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();
    return (true);
  }

  virtual void	draw(gdl::AShader &shader, gdl::Clock const &)	{
    this->_texture.bind();
    this->_geometry.draw(shader, this->getTransformation(), GL_QUADS);
  }

  virtual void	update(gdl::Clock const &clock, gdl::Input &input)	{
    if (input.getKey(SDLK_UP))
      {
	if (_rotation != glm::vec3(0, 0, 0))
	  _rotation = glm::vec3(0, 0, 0);
	else
	  translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    if (input.getKey(SDLK_DOWN))
      {
	if (_rotation != glm::vec3(0, 180, 0))
	  _rotation = glm::vec3(0, 180, 0);
	else
	  translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    if (input.getKey(SDLK_LEFT))
      {
	if (_rotation != glm::vec3(0, 90, 0))
	  _rotation = glm::vec3(0, 90, 0);
	else
	  translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
      }
    if (input.getKey(SDLK_RIGHT))
      {
	if (_rotation != glm::vec3(0, -90, 0))
	  _rotation = glm::vec3(0, -90, 0);
	else
	  translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
      }
  }
};
