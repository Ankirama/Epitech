
//
// gameengine.hh for  in /home/teyssa_r/rendu/cpp_bomberman/include
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Fri May  8 01:41:24 2015 Raphael Teyssandier
// Last update Sun Jun 14 17:40:36 2015 Raphael Teyssandier
//

#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

# define WIDTH	800
# define HEIGHT	600
# define SOUND_PATH	{std::string("./ressources/sound/")}
# define START_MUSIC	{std::string(SOUND_PATH) + std::string("Bomberman_Theme.ogg")}
# define GOD_LIKE	"./ressources/sound/godlike.wav"
# define BB_TRIPLE	"./ressources/sound/triple.wav"
# define WICKED		"./ressources/sound/wickedsick.wav"
# define UNSTOPPPABLE  	"./ressources/sound/unstoppable.wav"
# define HEADSHOT      	"./ressources/sound/headshot.wav"
# define HOLYSHIT      	"./ressources/sound/holyshit.wav"
# define HUEHUE		"./ressources/sound/huehue.wav"
# define BUTTON_30	"./ressources/sound/button-30.wav"
# define BUTTON_21	"./ressources/sound/button-21.wav"
# define DING		"./ressources/sound/ding.wav"

# include <vector>
# include <iostream>
# include <Game.hh>
# include <SdlContext.hh>
# include <Clock.hh>
# include <Input.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <AShader.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <SFML/Audio.hpp>

enum	e_Etat {
  SURVOLE,
  ENFONCE,
  PAS_SURVOLE
};

class	IGameState;

class	GameEngine : gdl::Game{
public:
  GameEngine();
  ~GameEngine();

  bool			initialize();
  void			Cleanup();
  gdl::SdlContext	getContext() const;
  gdl::Clock		getClock() const;

  void	ChangeState(IGameState *);
  void	PushState(IGameState *);
  void	PopState();

  void	HandleEvents();
  bool	update();
  void	draw();

  bool	Running() { return (m_running); }
  void	Quit() { m_running = false; }
  void	resizeWindow(int, int);

  sf::Music	&getMusic()	{ return m_music; }
  bool	getLock() const;
  void	setLock(const bool);
  gdl::BasicShader	&getShader();
  gdl::Input		&getInput();
  gdl::Clock		&getClock();

  pthread_t		&getPthread()	{ return m_sound;	}
  pthread_attr_t	&getAttr()	{ return m_attr;	}

private:
  gdl::SdlContext		m_context;
  gdl::Clock			m_clock;
  gdl::Input			m_input;
  gdl::BasicShader		m_shader;
  std::vector<IGameState*>	m_states;
  sf::Music			m_music;
  bool				m_running;;
  bool				m_lock;
  pthread_attr_t		m_attr;
  pthread_t			m_sound;
};

void	*pthreadSound(void *);

#endif /* !GAMEENGINE_HH_ */
