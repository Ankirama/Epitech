#ifndef CPP_MAZE_HH
# define CPP_MAZE_HH

# include <vector>
# include <string>

# include "Object2D.hh"
# include "Object3D.hh"
# include "GenerateMaze.hh"

# define DEFAULT_GROUND	"ressources/img/texture/sol.tga"
# define DEFAULT_WALL	"ressources/img/texture/mur.tga"
# define DEFAULT_CAISSE	"ressources/img/texture/caisse.tga"

class Maze
{
private:
  int				m_width;
  int				m_height;
  char				*m_maze;
  std::string			m_texture_ground;
  std::string			m_texture_wall;
  std::string			m_texture_caisse;
  Object2D			*m_ground;
  Object3D			*m_wall;
  Object3D			*m_box;
  bool				m_todraw;

private:
  Maze();
  Maze(const Maze &);
  Maze	&operator=(const Maze &);

public:
  Maze(int, int, char *);

  ~Maze();

  // Getter
  char	*	getMaze() const { return this->m_maze; }
  int		getWidth() const { return this->m_width; }
  int		getHeight() const { return this->m_height; }
  std::string	getTextureGround() const { return this->m_texture_ground; }
  std::string	getTextureWall() const { return this->m_texture_wall; }
  std::string	getTextureCaisse() const { return this->m_texture_caisse; }
  bool		getDraw() const { return this->m_todraw; }

  // Setter
  void	setMaze(char *map) { this->m_maze = map; }
  void	setCase(unsigned int position, int ID) { this->m_maze[position] = ID; }
  void	setWidth(int width) { this->m_width = width; }
  void	setHeight(int height) { this->m_height = height; }
  void	setTextureGround(std::string const &texture_ground) { this->m_texture_ground = texture_ground; }
  void	setTextureWall(std::string const &texture_wall) { this->m_texture_ground = texture_wall; }
  void	setTextureCaisse(std::string const &texture_caisse) { this->m_texture_ground = texture_caisse; }
  void	setDraw(bool todraw) { this->m_todraw = todraw; }

  void	initialize();
  void	draw(gdl::BasicShader, gdl::Clock const &);
};

#endif /* !CPP_MAP_HH */
