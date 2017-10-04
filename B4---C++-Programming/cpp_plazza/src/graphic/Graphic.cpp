//
// Graphic.cpp for  in /home/teyssa_r/rendu/cpp_plazza/src
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Apr 15 00:18:33 2015 Raphael Teyssandier
// Last update Sun Apr 26 22:22:55 2015 Raphael Teyssandier
//

#include "Graphic.hh"
#include "Parser.hh"
#include <stdio.h>

static std::string	tab_status_cmd[NB_STATUS_CMD] = {
  "En attente",
  "En cour",
  "Prete"
};

static std::string	tab_status_kit[NB_STATUS_KIT] = {
  "En attente",
  "En travail",
  "Finish"
};

myWindow::myWindow(std::vector<IIngredient *> & ingredient){
  QStringList		header;

  for (std::vector<IIngredient *>::iterator it = ingredient.begin(); it != ingredient.end(); ++it) {
    this->m_ingredient.push_back(new Ingredient((*it)->getName(), (*it)->getQuantity()));
  }
  this->m_nbCommand = 0;
  this->m_menuBar = new QMenuBar(&this->m_window);
  this->m_grid = new QGridLayout(&this->m_window);
  this->m_line = new QLineEdit(&this->m_window);
  connect(this->m_line, SIGNAL(returnPressed()), this, SLOT(parseLineEdit()));
  header << "Command" << "Pizza" << "Quantite" << "OnKitchen" << "Status";
  this->m_tableCommand = this->initTable(this->m_tableCommand, 5, header);
  header.clear();
  header << "CookingTime" << "ReplaceTime" << "NumberCooks" << "Status";
  this->m_tableKitchen = this->initTable(this->m_tableKitchen, 4, header);
  this->m_grid->addWidget(this->m_tableCommand, 1, 0);
  this->m_grid->addWidget(this->m_tableKitchen, 1, 1);
  this->m_grid->addWidget(this->m_line, 2, 0, 2, 2);
  this->m_window.setWindowTitle("Plazza");
  this->m_window.setWindowState(this->m_window.windowState() ^ Qt::WindowMaximized);
  this->menuBar();
  this->m_grid->addWidget(this->m_menuBar, 0, 0);
  this->m_window.show();
}

myWindow::~myWindow(){
  delete this->m_tableCommand;
  delete this->m_tableKitchen;
  delete this->m_grid;
  delete this->m_menuBar;
  delete this->m_newPizza;
  delete this->m_visPizza;
  delete this->m_visIngredient;
  delete this->m_aPropos;
  delete this->m_aCommand;
  delete this->m_line;
}

QTableWidget		*myWindow::initTable(QTableWidget *table, int nb,
					     QStringList header){
  table = new QTableWidget(0, nb, &this->m_window);
  for (int i = 0; i < table->horizontalHeader()->count(); ++i)
    table->horizontalHeader()->setResizeMode(i, QHeaderView::Stretch);
  table->setHorizontalHeaderLabels(header);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->verticalHeader()->hide();
  return (table);
}

QTableWidget	*myWindow::getTableCommand() const{
  return (this->m_tableCommand);
}

QTableWidget	*myWindow::getTableKitchen() const{
  return (this->m_tableKitchen);
}

QGridLayout	*myWindow::getGrid() const{
  return (this->m_grid);
}

std::vector<Command *>	myWindow::getCommand() const{
  return (this->m_command);
}

QTableWidgetItem	*myWindow::insertItem(const std::string &itemString) const{
  QTableWidgetItem	*item = new QTableWidgetItem;

  item->setText(QString::fromStdString(itemString));
  item->setTextAlignment(Qt::AlignCenter);
  return (item);
}


std::string		myWindow::getTall(const int tall) const{
  switch (tall){
  case 1:
    return ("S");
    break;
  case 2:
    return ("M");
    break;
  case 4:
    return ("L");
    break;
  case 8:
    return ("XL");
    break;
  case 16:
    return ("XXL");
    break;
  }
  return ("\0");
}

void			myWindow::refreshCommand(){
  std::vector<Command *>::iterator	it = this->m_command.begin();

  while (this->m_tableCommand->rowCount() > 0)
    this->m_tableCommand->removeRow(0);
  for (it = this->m_command.begin() ; it != this->m_command.end() ; ++it){
    this->m_tableCommand->insertRow(this->m_tableCommand->rowCount());
    this->m_tableCommand->setItem(this->m_tableCommand->rowCount() - 1, 0,
				  this->insertItem(numberToString<int>((*it)
								       ->getNbCommand())));
    this->m_tableCommand->setItem(this->m_tableCommand->rowCount() - 1, 1,
				  this->insertItem((*it)->getPizza()));
    this->m_tableCommand->setItem(this->m_tableCommand->rowCount() - 1, 2,
				  this->insertItem(numberToString<int>((*it)
								       ->getQuantite())));
    this->m_tableCommand->setItem(this->m_tableCommand->rowCount() - 1,
				  3, this->insertItem((*it)->getTall()));
    this->m_tableCommand->setItem(this->m_tableCommand->rowCount() - 1,
				  4, this->insertItem(tab_status_cmd[(*it)->getStatus()]));
  }
}

void			myWindow::addCommand(){
  if (edit_command->text().isEmpty() || this->spin_command->value() <= 0){
    QMessageBox	messageBox;

    messageBox.critical(0, "Error", "An error has occured !");
    messageBox.setFixedSize(500, 200);
  }
  else {
    this->win_command->close();
    this->m_command.push_back(new Command(edit_command->text().toStdString(),
					  this->spin_command->value(),
					  this->getTall(this->box_command->itemData
							(this->box_command->currentIndex())
							.toInt()), WAIT_CMD, ++this->m_nbCommand));
    this->refreshCommand();
  }
}

void			myWindow::addCommand(std::string const &type,
					     std::string const &size,
					     const int quantite){
  this->m_command.push_back(new Command(type,
					quantite,
				        size,
					WAIT_CMD,
					++this->m_nbCommand));
  this->refreshCommand();
}

void			myWindow::addKitchen(const int cookingTime,
					     const long replaceTime,
					     const int nbCooks,
					     const t_status_kit status){
  this->m_tableKitchen->insertRow(this->m_tableKitchen->rowCount());
  this->m_tableKitchen->setItem(this->m_tableKitchen->rowCount() - 1, 0,
				this->insertItem(numberToString<int>(cookingTime)));
  this->m_tableKitchen->setItem(this->m_tableKitchen->rowCount() - 1, 1,
				this->insertItem(numberToString<long>(replaceTime)));
  this->m_tableKitchen->setItem(this->m_tableKitchen->rowCount() - 1, 2,
				this->insertItem(numberToString<int>(nbCooks)));
  this->m_tableKitchen->setItem(this->m_tableKitchen->rowCount() - 1, 3,
				this->insertItem(tab_status_kit[status]));
}

void			myWindow::menuBar() {
  QMenu			*menu = new QMenu("New");

  this->createActions();
  menu->addAction(this->m_newPizza);
  menu->addAction(this->m_aCommand);
  this->m_menuBar->addMenu(menu);
  menu = new QMenu("Edition");
  menu->addAction(this->m_visPizza);
  menu->addAction(this->m_visIngredient);
  this->m_menuBar->addMenu(menu);
  menu = new QMenu("A propos");
  menu->addAction(this->m_aPropos);
  this->m_menuBar->addMenu(menu);
}

void			myWindow::createActions() {
  this->m_newPizza = new QAction(QString::fromStdString("New Pizza"),
				 &this->m_window);
  connect(this->m_newPizza, SIGNAL(triggered()),
  	  this, SLOT(newPizza()));
  this->m_visPizza = new QAction(QString::fromStdString("Pizza"),
  				 &this->m_window);
  connect(this->m_visPizza, SIGNAL(triggered()),
	  this, SLOT(visPizza()));
  this->m_visIngredient = new QAction(QString::fromStdString("Ingredient"),
  				      &this->m_window);
  connect(this->m_visIngredient, SIGNAL(triggered()),
	  this, SLOT(visIngredient()));
  this->m_aPropos = new QAction(QString::fromStdString("Credit"),
				&this->m_window);
  connect(this->m_aPropos, SIGNAL(triggered()),
	  this, SLOT(credit()));
  this->m_aCommand = new QAction(QString::fromStdString("New Command"),
				&this->m_window);
  connect(this->m_aCommand, SIGNAL(triggered()),
	  this, SLOT(newCommand()));
}

void			myWindow::addPizza(){
  if (edit_command->text().isEmpty() || this->spin_command->value() <= 0){
    QMessageBox	messageBox;

    messageBox.critical(0, "Error", "An error has occured !");
    messageBox.setFixedSize(500, 200);
  } else {
    this->win_command->close();
    Pizzas::getInstance().addPizza(edit_command->text().toStdString(),
				   this->spin_command->value(), this->m_ingredient);
  }
}

void			myWindow::newPizza() {
  this->win_command = this->newWindow("Visualisation Pizza");
  this->grid_command = new QGridLayout(win_command);
  this->edit_command = new QLineEdit(win_command);
  this->but_command = new QPushButton("Valider", win_command);
  this->spin_command = new QSpinBox(win_command);
  grid_command->addWidget(edit_command, 0, 0);
  grid_command->addWidget(spin_command, 1, 0);
  grid_command->addWidget(but_command, 2, 0);
  win_command->show();
  connect(but_command, SIGNAL(clicked()), this, SLOT(addPizza()));

}

void					myWindow::visPizza() {
  QWidget				*win_pizza = this->newWindow("Visualisation Pizza");
  QGridLayout				*grid_pizza = new QGridLayout(win_pizza);
  QTableWidget				*table_pizza =
    new QTableWidget(0, 1, &this->m_window);
  std::vector<IPizza *>			pizza = Pizzas::getInstance().getAllPizza();
  std::vector<IPizza *>::iterator	it = pizza.begin();
  QStringList				header;

  header << "Pizza";
  table_pizza->setSelectionBehavior(QAbstractItemView::SelectRows);
  table_pizza->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table_pizza->setHorizontalHeaderLabels(header);
  table_pizza->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
  grid_pizza->addWidget(table_pizza, 0, 0);
  while (it != pizza.end()){
    table_pizza->insertRow(table_pizza->rowCount());
    table_pizza->setItem(table_pizza->rowCount() - 1, 0,
			 this->insertItem((*it)->getName()));
    ++it;
  }
  win_pizza->show();
}

void			myWindow::visIngredient() {
  QWidget		*win_ingredient = this->newWindow("Visualisation Ingredient");
  QGridLayout		*grid_ingredient = new QGridLayout(win_ingredient);
  QTableWidget		*table_ingredient = new QTableWidget(0, 1, win_ingredient);
  QStringList		header;

  header << "Ingredient";
  table_ingredient->setSelectionBehavior(QAbstractItemView::SelectRows);
  table_ingredient->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table_ingredient->setHorizontalHeaderLabels(header);
  table_ingredient->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
  for (std::vector<IIngredient *>::iterator it = this->m_ingredient.begin()
	 ; it != this->m_ingredient.end() ; ++it) {
    table_ingredient->insertRow(table_ingredient->rowCount());
    table_ingredient->setItem(table_ingredient->rowCount() - 1, 0,
			 this->insertItem((*it)->getName()));
  }
  grid_ingredient->addWidget(table_ingredient, 0, 0);
  win_ingredient->show();
}

QWidget			*myWindow::newWindow(const std::string &name) const {
  QWidget		*new_win = new QWidget();

  new_win->setWindowTitle(QString::fromStdString(name));
  new_win->setFixedSize(300, 250);
  return (new_win);
}

void			myWindow::newCommand(){
  this->win_command = this->newWindow("Visualisation Command");
  this->grid_command = new QGridLayout(win_command);
  this->edit_command = new QLineEdit(win_command);
  this->but_command = new QPushButton("Valider", win_command);
  this->box_command = new QComboBox(win_command);
  this->spin_command = new QSpinBox(win_command);
  box_command->addItem("S", QVariant(1));
  box_command->addItem("M", QVariant(2));
  box_command->addItem("L", QVariant(4));
  box_command->addItem("XL", QVariant(8));
  box_command->addItem("XXL", QVariant(16));
  grid_command->addWidget(edit_command, 0, 0);
  grid_command->addWidget(box_command, 1, 0);
  grid_command->addWidget(spin_command, 2, 0);
  grid_command->addWidget(but_command, 3, 0);
  win_command->show();
  connect(but_command, SIGNAL(clicked()), this, SLOT(addCommand()));
}

void			myWindow::credit() {
  QWidget		*win_credit = this->newWindow("Credit");
  QGridLayout		*grid_credit = new QGridLayout(win_credit);
  QLabel		*lab_credit = new QLabel(win_credit);
  QLabel		*img_credit = new QLabel(win_credit);
  QPixmap		*img = new QPixmap();

  img->load(PNG_ZERO);
  img_credit->setPixmap(img->scaled(150, 200, Qt::KeepAspectRatio));
  img_credit->setAlignment(Qt::AlignCenter);
  lab_credit->setText("Credit\nFabien MARTINEZ\nRaphael TEYSSANDIER\nAlexandre CHENEVIER");
  lab_credit->setAlignment(Qt::AlignCenter);
  grid_credit->addWidget(lab_credit, 1, 0);
  grid_credit->addWidget(img_credit, 0, 0);
  win_credit->show();
}

void			myWindow::parseLineEdit() {
  Parser		*parser = new Parser();

  if (parser->parse(this->m_line->text().toStdString())){
    this->addCommand(parser->getType().back(),
		     parser->getSize().back(),
		     parser->getNumber().back());
  }
  else if (!this->m_line->text().isEmpty()){
    QMessageBox	messageBox;

    messageBox.critical(0, "Error", "An error has occured !");
    messageBox.setFixedSize(500, 200);
  }
  this->m_line->clear();
}
