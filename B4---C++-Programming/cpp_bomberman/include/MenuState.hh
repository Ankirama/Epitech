#ifndef MENUSTATE_H
# define MENUSTATE_H

# include "MenuState.hh"
# include "Button.hh"
# include <map>

class MenuState : public IGameState {
public:
  void	Init(GameEngine *);
  void	Cleanup();
  void	Pause();
  void	Resume(GameEngine *);

  void	Update(GameEngine *);
  void	Draw(GameEngine *);

  void	Up(GameEngine *);
  void	Down(GameEngine *);
  void	Right(GameEngine *);
  void	Left(GameEngine *);
  void	Enter(GameEngine *);
  void	QuitState(GameEngine *);
  void	Quit(GameEngine *);

  void	modKey(const int, const int);

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);

  static MenuState*	Instance() {
    return &m_MenuState;
  }

  enum  e_State {
    RES,
    SAVE,
    OPTION,
    CREDIT
  };

protected:
  MenuState();
  ~MenuState();

private:
  typedef void		(MenuState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();

private:
  static MenuState			m_MenuState;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
  Object2D				*m_background;
  bool                                  m_released;
};

#endif
