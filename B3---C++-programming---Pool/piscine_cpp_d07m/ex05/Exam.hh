//
// Exam.hh for aahahahaijwdiojqwiodioqwjdioqwjdjqwdjqwjdpoqwkdo[qwkdo[qwkdkqw[dkqw[kd[qwk[dkq[dkw[qdpqwkd[qwpkd[qpk in /home/mar_b/rendu/piscine_cpp_d07m/ex05
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Tue Jan 13 17:50:39 2015 Fabien Martinez
// Last update Tue Jan 13 20:40:37 2015 Fabien Martinez
//

#ifndef EXAM_HH_
# define EXAM_HH_

class Exam
{
public:
  static bool cheat;
  Exam(bool *);
  ~Exam();
  bool isCheating();
  void (Exam::*kobayashiMaru)(int);
  void start(int);
};

#endif /* !EXAM_HH_ */
