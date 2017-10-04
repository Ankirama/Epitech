/*
** Parts.h for parts in /home/user/rendu/piscine_cpp_d07a/ex01
**
** Made by 
** Login   
**
** Started on  Tue Jan 13 23:01:47 2015 
** Last update Wed Jan 14 09:19:39 2015 
*/

#ifndef PARTS_H_
# define PARTS_H_

# include <string>

class Arms
{
 public :
  Arms(std::string serial, bool functionnal);
  Arms();

  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;

 private:
  std::string _serial;
  bool _functionnal;
};

class Legs
{
 public:
  Legs(std::string serial, bool functionnal);
  Legs();

  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;

 private:
  std::string _serial;
  bool _functionnal;
};

class Head
{
 public:
  Head(std::string serial, bool functionnal);
  Head();

  bool isFunctionnal() const;
  std::string serial() const;
  void informations() const;

 private:
  std::string _serial;
  bool _functionnal;
};

#endif /* !PARTS_H_ */
