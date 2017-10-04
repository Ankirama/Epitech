#include "Maze.hh"

Maze::Maze(int width, int height, char *maze) : m_width(width + 2), m_height(height + 2), m_maze(maze),
						m_texture_ground(DEFAULT_GROUND),
						m_texture_wall(DEFAULT_WALL),
						m_texture_caisse(DEFAULT_CAISSE),
						m_todraw(true)
{
  if (this->m_width < 12 || this->m_height < 12)
    throw ErrorBomberman("The map must be superior to 10x10 !");
  try {
    this->m_ground = new Object2D(this->m_texture_ground, 0, 0.0, 1);
    this->m_box = new Object3D(this->m_texture_caisse, glm::vec3(0, 0, CASE + CASE / 2.0),
			  glm::vec3(0, 0, 0), glm::vec3(CASE, CASE, CASE));
    this->m_wall = new Object3D(this->m_texture_wall, glm::vec3(0, 0, CASE + CASE / 2.0),
			 glm::vec3(0, 0, 0), glm::vec3(CASE, CASE, CASE));
  } catch (ErrorBomberman const &e) {
    throw ErrorBomberman(e.what(), "Maze");
  }
}

Maze::~Maze()	{
  try {
    if (m_ground)
      delete(m_ground);
    if (m_wall)
      delete m_wall;
    if (m_box)
      delete m_box;
  } catch (ErrorBomberman const &e) {
      throw ErrorBomberman(e.what(), "Maze");
    }
}

void	Maze::initialize()	{
  this->m_ground->Init(this->m_width / 2.0, this->m_height / 2.0, 1.0, 1.0);
  this->m_wall->initialize(CASE / 2.0, CASE / 2.0, CASE + CASE / 2.0);
  this->m_box->initialize(CASE / 2.0, CASE / 2.0, CASE + CASE / 2.0);
}

void	Maze::draw(gdl::BasicShader shader, gdl::Clock const &)	{
  this->m_ground->Draw(shader);

  float	x = this->m_width / 2.0 - CASE / 2.0;
  float	y = this->m_height / 2.0 - CASE / 2.0;

  int	size_map = this->m_width * this->m_height;
  for (int i = 0; i < size_map; i++) {
    if (this->m_maze[i] == ID_BLOCK) {
      this->m_box->setPosition(glm::vec3(x, y, CASE + CASE / 2.0));
      this->m_box->draw(shader);
    }
    else if (this->m_maze[i] == ID_WALL) {
      this->m_wall->setPosition(glm::vec3(x, y, CASE + CASE / 2.0));
      this->m_wall->draw(shader);
    }
    x = x - CASE;
    if (i % this->m_width == this->m_width - 1) {
      x = this->m_width / 2.0 - CASE / 2;
      y = y - CASE;
    }
  }
  this->m_todraw = false;
}
