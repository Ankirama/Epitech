//
// Button.hh for  in /home/teyssa_r/rendu/cpp_bomberman
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Tue May 12 21:41:47 2015 Raphael Teyssandier
// Last update Thu May 21 17:53:59 2015 Raphael Teyssandier
//

#ifndef BUTTON_H_
# define BUTTON_H_

# define PATH_MAC(img)	(std::string(IMG_PATH) + std::string(img))
# define PATH_BUT(img)	(std::string(IMG_PATH) + std::string("button/") + std::string(img))

# define BACK_IMG	{std::string(IMG_PATH) + std::string("background/Background.tga")}
# define BUT_PLAY_1	PATH_BUT("play.tga")
# define BUT_PLAY_2	PATH_BUT("play2.tga")
# define BUT_MULT_1	PATH_BUT("multi.tga")
# define BUT_MULT_2	PATH_BUT("multi2.tga")
# define BUT_OPTN_1	PATH_BUT("options.tga")
# define BUT_OPTN_2	PATH_BUT("options2.tga")
# define BUT_EXIT_1	PATH_BUT("exit.tga")
# define BUT_EXIT_2	PATH_BUT("exit2.tga")
# define BUT_SOLO_1	PATH_BUT("solo.tga")
# define BUT_SOLO_2	PATH_BUT("solo2.tga")
# define BUT_SAVE_1	PATH_BUT("save.tga")
# define BUT_SAVE_2	PATH_BUT("save2.tga")
# define BUT_ARRI_1	PATH_BUT("fleche_droit.tga")
# define BUT_ARRI_2	PATH_BUT("fleche_droite_orange.tga")
# define BUT_ARLE_1	PATH_BUT("fleche_gauche.tga")
# define BUT_ARLE_2	PATH_BUT("fleche_gauche_orange.tga")
# define BUT_RSLT_1	PATH_BUT("resolution.tga")
# define BUT_RSLT_2	PATH_BUT("resolution2.tga")
# define BUT_KEYB_1	PATH_BUT("keyboard.tga")
# define BUT_KEYB_2	PATH_BUT("keyboard2.tga")
# define BUT_TP10_1	PATH_BUT("top10.tga")
# define BUT_TP10_2	PATH_BUT("top10_orange.tga")
# define BUT_LOAD_1	PATH_BUT("load.tga")
# define BUT_LOAD_2	PATH_BUT("load2.tga")
# define BUT_BACK_1	PATH_BUT("back.tga")
# define BUT_BACK_2	PATH_BUT("back2.tga")

# include "Object2D.hh"
# include "IGameState.hh"

class	Button {
public:
  Button(const std::string &, const std::string &, const int, const int, void (*func)(GameEngine *));
  ~Button();

  void	Init(const float, const float, const float);
  void	Draw(gdl::BasicShader shader, const e_Etat, GameEngine *);
  int	getY() const;
  void	setY(const int, const int);

private:
  std::vector<Object2D *>		m_container;
  void				(*m_func)(GameEngine *);
};

#endif /* !BUTTON_H_ */
