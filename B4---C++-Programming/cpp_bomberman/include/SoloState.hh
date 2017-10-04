#ifndef SOLOSTATE_HH_
# define SOLOSTATE_HH_

# include "IntroState.hh"
# include "Button.hh"
# include <map>

class SoloState : public IGameState {
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


  // Getter
  std::string	getName(void) const {return this->m_name; }

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);
  void			removeLetter(GameEngine *);

  static SoloState*	Instance() {
    return &m_SoloState;
  }

  enum  e_State {
    PLAY,
    EXIT
  };

protected:
  SoloState();
  ~SoloState();

private:
  typedef void		(SoloState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();
  void			writeName(int const, GameEngine *);

private:
  static SoloState			m_SoloState;
  bool					m_released;
  Object2D				*m_background;
  Object2D				*m_backname;
  std::string				m_name;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
  GenerateText				*m_text;
};

#endif
