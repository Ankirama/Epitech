#ifndef CONFSTATE_HH_
# define CONFSTATE_HH_

# include "IntroState.hh"
# include "Button.hh"
# include <map>

class ConfState : public IGameState {
public:
  void	Init(GameEngine *);
  void	Cleanup();
  void	Pause();
  void	Resume(GameEngine *);

  void	Update(GameEngine *);
  void	Draw(GameEngine *);

  void	Up(GameEngine *);
  void	Down(GameEngine *);
  void	Enter(GameEngine *);
  void	QuitState(GameEngine *);
  void	Quit(GameEngine *);

  void	modKey(const int, const int);

  bool	rightNumber();

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);

  static ConfState*	Instance() {
    return &m_ConfState;
  }

  enum  e_State {
    PLAY,
    EXIT
  };

protected:
  ConfState();
  ~ConfState();

private:
  typedef void		(ConfState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();
  void			writeName(int, GameEngine *);
  void			writeText(GameEngine *, std::string &, int const);
  void			removeLetter(GameEngine *);
  void			removeOneLetter(GameEngine *, std::string &);

private:
  static ConfState			m_ConfState;
  int					m_iterator;
  bool					m_released;
  Object2D				*m_background;
  Object2D				*m_backx;
  Object2D				*m_backy;
  Object2D				*m_backnbAI;
  Object2D				*m_backDifficulty;
  Object2D				*m_head;
  std::string				m_x;
  std::string				m_nbAI;
  std::string				m_difficulty;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
  std::vector<GenerateText *>		m_player;
};

#endif
