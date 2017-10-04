/*
** KreogCom.h for coucou in /home/mar_b/rendu/piscine_cpp_d07a/ex02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan 14 01:14:36 2015 Fabien Martinez
** Last update Wed Jan 14 09:20:22 2015 Fabien Martinez
*/

#ifndef KREOGCOM_H_
#define KREOGCOM_H_

class	KreogCom
{
 public:
  KreogCom(int x, int y, int serial);
  ~KreogCom();

 public:
  void addCom(int x, int y, int serial);
  KreogCom *getCom();
  void removeCom();

 public:
  void ping() const;
  void locateSquad() const;

 private:
  KreogCom *_next;
  int X;
  int Y;
  const int m_serial;
};


#endif /* !KREOGCOM_H_ */
