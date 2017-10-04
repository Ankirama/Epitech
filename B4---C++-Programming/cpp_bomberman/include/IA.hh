#ifndef CPP_IA_HH
# define CPP_IA_HH


/**
 * @file IA.hh
 * @brief IA class in the game
 * @author ankirama
 * @version 0.43
 */

# include "ACharacter.hh"
# include "Lua.hh"

/**
 * @enum eDifficulty
 * @brief AI's difficulty
 */
typedef enum	eDifficulty
  {
    DUMMY = 1,
    EASY,
    NORMAL
  }           eDifficulty;


# define IA_NONE	5

/**
 * @class IA
 * @brief NPC class
 *
 * It will manage movement/update from an AI.
 * It will call Lua class to execute our lua's script
 */
class IA : public ACharacter
{
public:

  /**
   * @brief IA's constructor
   *
   * @param position Set the AI's position
   * @param eDifficulty Chose the AI's difficulty
   */
  IA(unsigned int position, eDifficulty, int width, int height);

  /**
   * @brief IA's destructor
   */
  ~IA();

  // getter
  eDifficulty	getDifficulty() const;

  // setter
  void	setDifficulty(eDifficulty);
  virtual void	update(GameEngine *, Maze &);

private:
  IA();
  IA(IA const &);
  IA	&operator=(IA const &);

private:
  eDifficulty	m_difficulty;
  Lua		*m_lua;
  int		m_width;
  int		m_height;
  int		m_time;
  typedef void	(IA::*m_tabFun)(Maze &, gdl::Clock &);
  m_tabFun	m_func[5] = {&IA::MoveUp, &IA::MoveRight, &IA::MoveDown,
			     &IA::MoveLeft, &IA::Plant};

private:
  void	MoveRight(Maze &, gdl::Clock &);
  void	MoveLeft(Maze &, gdl::Clock &);
  void	MoveUp(Maze &, gdl::Clock &);
  void	MoveDown(Maze &, gdl::Clock &);
  void	Plant(Maze &, gdl::Clock &);
};

#endif /* !CPP_IA_HH */
