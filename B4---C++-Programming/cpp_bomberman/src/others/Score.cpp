//
// Created by ankirama on 5/11/15.
//

#include "Score.hh"

Score   Score::m_instance = Score();

Score::Score() {
    std::string     line;
    std::string     token;
    unsigned int  score;
    this->m_rFile.open("./scores", std::ios::in);
    if (this->m_rFile.is_open()) {
        while (getline(this->m_rFile, line)) {
            score = line.find(" ");
            token = line.substr(0, score);
            score = StringToNumber<unsigned int>(line.substr(score + 1));
            this->m_score[token] = score;
        }
    }
}

Score::~Score() {
  if (this->m_rFile.is_open()) {
    this->m_rFile.close();
  }
  this->m_wFile.open("./scores", std::ios::out | std::ios::trunc);
  if (this->m_wFile.is_open()) {
    std::map<unsigned int, std::string const> splitted = flip_map<std::string const, unsigned int>(this->m_score);
    for (std::map<unsigned int, std::string const>::reverse_iterator iter = splitted.rbegin();
	 iter != splitted.rend(); ++iter) {
      this->m_wFile << iter->second << " " << iter->first << std::endl;
    }
    splitted.clear();
    this->m_wFile.close();
  }
}

void    Score::addScore(std::string const &player, unsigned int score) {
    std::string tmp = player;
    for (unsigned int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            tmp[i] = tmp[i] + 32;
    }
    if (this->m_score.find(tmp) == this->m_score.end())
        this->m_score[tmp] = score;
    else
        this->m_score[tmp] += score;
}



void    Score::showScore() const{
  std::map<unsigned int, std::string const> splitted = flip_map<std::string const, unsigned int>(this->m_score);
  for (std::map<unsigned int, std::string const>::reverse_iterator iter = splitted.rbegin();
       iter != splitted.rend(); ++iter) {
    std::cout << iter->second << ": " << iter->first << std::endl;
  }
  splitted.clear();
}

unsigned int Score::getPlayerScore(std::string const &player) {
  if (this->m_score.find(player) == this->m_score.end())
    return 0;
  return this->m_score[player];
}

std::vector < std::pair<std::string, unsigned int > > Score::getTopN(int n) {
  std::vector <std::pair<std::string, unsigned int > > topN;
  std::map<unsigned int, std::string const> splitted = flip_map<std::string const, unsigned int>(this->m_score);

  for (std::map<unsigned int, std::string const>::reverse_iterator iter = splitted.rbegin();
       iter != splitted.rend() && n > 0; ++iter) {
    unsigned int tmp_int = iter->first;
    std::string tmp_str = iter->second;
    topN.push_back(std::make_pair(tmp_str, tmp_int));
    --n;
  }
  return topN;
}

Score&  Score::getInstance() {
    return m_instance;
}
