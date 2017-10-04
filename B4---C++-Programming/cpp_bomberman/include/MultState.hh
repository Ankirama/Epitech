#ifndef MULTSTATE_HH_
# define MULTSTATE_HH_

# include "IntroState.hh"
# include "Button.hh"
# include <map>

class MultState : public IGameState {
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
  void					removeLetter(GameEngine *);

  // Getter
  std::string	getName1(void) const { return this->m_name1; }
  std::string	getName2(void) const { return this->m_name2; }


  static MultState*	Instance() {
    return &m_MultState;
  }

  enum  e_State {
    PLAY,
    EXIT
  };

protected:
  MultState();
  ~MultState();

private:
  typedef void		(MultState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();
  void			writeName(int const, GameEngine *);

private:
  static MultState			m_MultState;
  int					m_iterator;
  bool					m_released;
  Object2D				*m_background;
  Object2D				*m_backname1;
  Object2D				*m_backname2;
  Object2D				*m_head;
  std::string				m_name1;
  std::string				m_name2;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
  std::vector<GenerateText *>		m_player;
};

#endif
