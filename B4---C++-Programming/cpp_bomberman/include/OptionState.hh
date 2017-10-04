#ifndef OPTIONSTATE_HH_
# define OPTIONSTATE_HH_

# include "IntroState.hh"
# include "Button.hh"
# include <map>

class OptionState: public IGameState {
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
  void	setBackground(std::string const &);

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);

  static OptionState*	Instance() {
    return &m_OptionState;
  }

  enum  e_State {
    RES,
    SCORE,
    OPTION,
    CREDIT
  };

protected:
  OptionState();
  ~OptionState();

private:
  typedef void		(OptionState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();

private:
  static OptionState			m_OptionState;
  bool					m_released;
  Object2D				*m_background;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
};

#endif
