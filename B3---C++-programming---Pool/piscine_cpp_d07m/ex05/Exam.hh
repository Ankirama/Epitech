//
// Exam.hh for aahahahaijwdiojqwiodioqwjdioqwjdjqwdjqwjdpoqwkdo[qwkdo[qwkdkqw[dkqw[kd[qwk[dkq[dkw[qdpqwkd[qwpkd[qpk in /home/user/rendu/piscine_cpp_d07m/ex05
//
// Made by 
// Login   
//
// Started on  Tue Jan 13 17:50:39 2015 
// Last update Tue Jan 13 20:40:37 2015 
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
