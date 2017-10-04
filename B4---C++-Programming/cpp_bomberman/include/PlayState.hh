#ifndef PLAYSTATE_HH_
# define PLAYSTATE_HH_

# include "IntroState.hh"
# include "Button.hh"
# include <map>

class PlayState : public IGameState {
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

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);

  static PlayState*	Instance() {
    return &m_PlayState;
  }

  enum  e_State {
    SOLO,
    MULT,
    EXIT
  };

protected:
  PlayState();
  ~PlayState();

private:
  typedef void		(PlayState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();

private:
  static PlayState			m_PlayState;
  bool					m_released;
  Object2D				*m_background;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
};

#endif
