//
// gamestate.hh for  in /home/teyssa_r/rendu/cpp_bomberman/include
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Fri May  8 01:35:41 2015 Raphael Teyssandier
// Last update Wed Jun  3 14:23:27 2015 Raphael Teyssandier
//

#ifndef IGAMESTATE_HH_
# define IGAMESTATE_HH_

# include "GameEngine.hh"

class	IGameState{
public:
  virtual void		Init(GameEngine *) = 0;
  virtual void		Cleanup() = 0;

  virtual void		Pause() = 0;
  virtual void		Resume(GameEngine *) = 0;

  virtual void		Update(GameEngine *) = 0;
  virtual void		Draw(GameEngine *) = 0;

  virtual void		modKey(const int, const int) = 0;

  void			ChangeState(GameEngine *game, IGameState *state){
    game->ChangeState(state);
  }

protected:
  IGameState() {}
};

#endif /* !GAMESTATE_HH_ */
