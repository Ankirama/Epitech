//
// Graphic.hh for  in /home/teyssa_r/rendu/cpp_plazza/includes
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Apr 15 00:16:59 2015 Raphael Teyssandier
// Last update Sun Apr 26 18:07:38 2015 Raphael Teyssandier
//

#ifndef GRAPHIC_HH_
# define GRAPHIC_HH_

# define NB_STATUS_CMD	3
# define NB_STATUS_KIT	3
# define PNG_ZERO	"./src/graphic/zen1.png"

# include <QConstString>
# include <QApplication>
# include <QPushButton>
# include <QTableWidget>
# include <QHeaderView>
# include <QGridLayout>
# include <QMenuBar>
# include <QMessageBox>
# include <QWidget>
# include <QLabel>
# include <QLineEdit>
# include <QComboBox>
# include <QVariant>
# include <QSpinBox>
# include <iostream>
# include <sstream>
# include "IIngredient.hh"
# include "IPizza.hh"
# include "Command.hh"

typedef enum	e_status_kit {
  WAIT_KIT,
  ONWORK,
  FINISH_KIT
}		t_status_kit;

class		myWindow : public QWidget {
  Q_OBJECT

public:
  myWindow(std::vector<IIngredient *> &);
  ~myWindow();

  QTableWidget			*getTableCommand() const;
  QTableWidget			*getTableKitchen() const;
  QGridLayout			*getGrid() const;
  std::vector<Command *>	getCommand() const;
  void				menuBar();
  void				addKitchen(const int,
					   const long,
					   const int,
					   const t_status_kit);
  QTableWidgetItem		*insertItem(const std::string &) const;
  std::string			getTall(const int) const;
  void				createActions();
  QWidget			*newWindow(const std::string &) const;
  void				refreshCommand();
  QTableWidget 			*initTable(QTableWidget *, int, QStringList);

public slots:
  void			newPizza();
  void			newCommand();
  void			visPizza();
  void			visIngredient();
  void			credit();
  void			addCommand();
  void			addCommand(std::string const &, std::string const &, const int);
  void			addPizza();
  void			parseLineEdit();

private:
  QWidget			m_window;
  QTableWidget			*m_tableCommand;
  QTableWidget			*m_tableKitchen;
  QGridLayout			*m_grid;
  QMenuBar			*m_menuBar;
  int				m_nbCommand;
  QAction			*m_newPizza;
  QAction			*m_visPizza;
  QAction			*m_visIngredient;
  QAction			*m_aPropos;
  QAction			*m_aCommand;
  QLineEdit			*m_line;
  QWidget			*win_command;
  QGridLayout			*grid_command;
  QLineEdit			*edit_command;
  QPushButton			*but_command;
  QComboBox			*box_command;
  QSpinBox			*spin_command;
  std::vector<Command *>	m_command;
  std::vector<IIngredient *>	m_ingredient;
  std::vector<IPizza *>		m_pizza;
};

template <typename T>
std::string		numberToString(T number)
{
  std::stringstream	ss;

  ss << number;
  return (ss.str());
}

#endif /* !GRAPHIC_HH_ */
