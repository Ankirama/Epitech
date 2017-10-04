#ifndef SCORESTATE_HH_
# define SCORESTATE_HH_

# include "IntroState.hh"
# include "Button.hh"
# include "GenerateText.hh"
# include <map>

class ScoreState : public IGameState {
public:
  void	Init(GameEngine *);
  void	Cleanup();
  void	Pause();
  void	Resume(GameEngine *);

  void	Update(GameEngine *);
  void	Draw(GameEngine *);

  void	QuitState(GameEngine *);
  void	Enter(GameEngine *);
  void	Quit(GameEngine *);

  void	modKey(const int, const int);

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);

  static ScoreState*	Instance() {
    return &m_ScoreState;
  }

protected:
  ScoreState();
  ~ScoreState();

private:
  typedef void		(ScoreState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();

private:
  static ScoreState			m_ScoreState;
  bool					m_released;
  Object2D				*m_background;
  Object2D				*m_backname;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<GenerateText *>		m_top;
  std::vector<Button *>::iterator	m_it;
};

#endif
