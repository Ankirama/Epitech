# include "GameEngine.hh"

class AObject {
public:
  AObject():
    _position(0,0,0),
    _rotation(0,0,0),
    _scale(1,1,1) {
  }

  virtual ~AObject()
  {}

  virtual bool initialize(){
    return (true);
  }

  virtual void update (gdl::Clock const &, gdl::Input &){
  }

  virtual void draw (gdl::AShader &shader, gdl::Clock const &clock) = 0;

  void translate(glm::vec3 const &v) {
    _position += v;
  }

  void rotate(glm::vec3 const &axis, float angle){
    _rotation += axis * angle;
  }

  void scale(glm::vec3 const & scale){
    _scale *= scale;
  }

  glm::mat4 getTransformation(){
    glm::mat4 tranform(1);
    tranform = glm::rotate(tranform, _rotation.y, glm::vec3(0, 1, 0));
    tranform = glm::rotate(tranform, _rotation.z, glm::vec3(0, 0, 1));
    tranform = glm::translate(tranform, _position);
    tranform = glm::scale(tranform, _scale);
    return (tranform);
  }
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
};
