#ifndef MY_FONT_HH_
# define MY_FONT_HH_

/**
 * @file Font.hh
 * @brief create text and draw it
 * @author ankirama
 * @version 1.0
 */
# include <SFML/Graphics.hpp>
# include <string>
# include "template_string.hh"
# include "Error.hpp"

/**
 * @class Font
 * @brief create text and draw it
 */
class Font {
public:
  /**
   * @brief constructor
   *
   * create font and text
   *
   * @param fontName	: font used to draw our text
   */
  explicit Font(const std::string &fontName);

  /**
   * @brief destructor
   *
   * It will delete font and text
   */
  ~Font();

  /**
   * @brief set text with specific string, size and position
   *
   * @param str		: text to draw
   * @param size	: size text (in pixels)
   * @param x		: x position
   * @param y		: y position
   */
  void	setText(const std::string &str, int size, float x, float y);

  /**
   * @brief set text with specific string, size and on the middle screen
   *
   * @param str		: text to draw
   * @param size	: size text (in pixels)
   * @param winX	: screen width used to center text
   * @param winY	: screen height used to center text
   */
  void	setTextMiddle(const std::string &str, int size, int winX, int winY);

  /**
   * @brief set text with specific number, size and position
   *
   * @param value	: number to draw
   * @param size	: size text (in pixels)
   * @param x		: x position
   * @param y		: y position
   */
  void	setText(int value, int size, float x, float y);

  /**
   * @brief set text with specific number
   *
   * @param value	:number to draw
   */
  void	setText(int value);

  /**
   * @brief set text with specific string
   *
   * @param str	: string to draw
   */
  void	setText(const std::string &str);

  /**
   * @brief draw our text
   *
   * It will check if text != null then draw our text
   *
   * @param window	:renderWindow used to display our text on the screen
   */
  void	draw(sf::RenderWindow *window);

private:
  sf::Font	*m_font; /**< variable used to set specific font */
  sf::Text	*m_text; /**< used to create our text, set position and size */
};

#endif /* !MY_FONT_HH_ */
