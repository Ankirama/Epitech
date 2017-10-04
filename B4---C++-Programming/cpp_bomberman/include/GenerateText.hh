//
// Created by ankirama on 5/22/15.
//

#ifndef CPP_BOMBERMAN_GENERATETEXT_HH
#define CPP_BOMBERMAN_GENERATETEXT_HH

/**
 * @file GenerateText.hh
 * @brief display text GUI
 * @author ankirama
 * @version 1.0
 */

# define PATH_TXT_NORMAL(c)    (std::string(IMG_PATH) + std::string("alphanumeric/") + std::string(c) + std::string(".tga"))
# define PATH_TXT_ORANGE(c)    (std::string(IMG_PATH) + std::string("alphanumeric_orange/") + std::string(c) + std::string(".tga"))

# include <vector>
# include <string>
# include <sstream>
# include "Object2D.hh"

/**
 * @class GenerateText
 * @brief Display text on screen
 *
 * Function to display some text on the screen.
 */

class GenerateText {
public:
    /**
     * @brief GenerateText's constructor
     *
     * It will create our object's vector with every letter needed and set it
     *
     * @param text Text we want to display on the screen
     * @param x x's position where we want to display it
     * @param y y's position where we want to display it
     */
    GenerateText(const std::string& text, float x, float y);

    /**
     * @brief GenerateText's destructor
     *
     * It will clean / delete every letter in our vector then destroy the class
     */
    ~GenerateText();

  /**
   * @brief init vector
   *
   * Every letter are Object2D so they have to be initialized.
   * This is the goal of this function
   */
  void		Init();

  /**
   * @brief Display letters' vector
   *
   * It will display our letters' vector.
   * This function will be called in the draw's loop in a state (like in GameState)
   *
   * @param shader Object2D need a shader so we need it
   */
  void		Draw(gdl::BasicShader shader);

  /**
   * @brief get Y position
   *
   * @return return Y position
   */
  int		getY() const;

  /**
   * @brief get text draw
   *
   * @return text stored in the instance
   */
   std::string const& getStr() const;
private:
   /**
    * @brief create new letter
    *
    * Create a new object2d from a char
    *
    * @param letter Letter which well be converted
    * @param x x's position
    * @param y y's position
    * @result Object2D created from letter
    */
    std::string const         m_str; /**< string used to display text */
    Object2D                *getLetterObj(char letter, float x, float y);
    std::vector<Object2D *>   m_text; /**< Letters' vector created to display on the screen*/
    float                     m_posX; /**< X initial position (for the first letter)*/
    float                     m_posY; /**< Y initial position (for the first letter)*/
};

#endif //CPP_BOMBERMAN_GENERATETEXT_HH
