#ifndef SAVESTATE_HH_
# define SAVESTATE_HH_

# include "IntroState.hh"
# include "GenerateText.hh"
# include "Button.hh"
# include <map>

class SaveState : public IGameState{
public:
  void	Init(GameEngine *);
  void	Cleanup();
  void	Pause();
  void	Resume(GameEngine *);

  void	Update(GameEngine *);
  void	Draw(GameEngine *);

  void	QuitState(GameEngine *);
  void	Up(GameEngine *);
  void	Down(GameEngine *);
  void	Enter(GameEngine *);
  void	Quit(GameEngine *);

  void	modKey(const int, const int);

  std::vector<Button *>::iterator	&getIterator();
  std::vector<Button *>			&getVector();
  void					setReleased(bool);

  static SaveState*	Instance() {
    return &m_SaveState;
  }

protected:
  SaveState();
  ~SaveState();

private:
  typedef void		(SaveState::*m_tabFun)(GameEngine *);
  void			addKey(const int, m_tabFun);
  void			delKey(const int);
  void			delAllKey();

private:
  static SaveState			m_SaveState;
  bool					m_released;
  bool					m_load;
  Object2D                              *m_background;
  Object2D                              *m_bomb;
  std::map<int, m_tabFun>		m_map;
  std::vector<Button *>			m_button;
  std::vector<Button *>::iterator	m_it;
  std::vector<GenerateText *>		m_file;
  std::vector<GenerateText *>::iterator	m_itFile;
};

#endif
