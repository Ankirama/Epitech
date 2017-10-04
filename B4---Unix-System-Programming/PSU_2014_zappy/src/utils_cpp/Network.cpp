//
// Network.cpp for  in /home/teyssa_r/rendu/PSU_2014_zappy
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Jun 17 13:42:58 2015 Raphael Teyssandier
// Last update Sun Jul  5 20:13:14 2015 Raphael Teyssandier
//

#include "Network.hh"
#include "Error.hpp"
#include "template_string.hh"
#include <unistd.h>
#include <algorithm>

Network::Network(std::string const &name, std::string const &port,
		 std::string const &host) : m_name(name + "\n"),
					    m_port(port),
					    m_host(host){
					    }

Network::Network(Network const &e) : m_name(e.m_name),
				     m_port(e.m_port),
				     m_host(e.m_host),
				     m_fd_read(e.m_fd_read),
				     m_fd_write(e.m_fd_write),
				     m_fd(e.m_fd),
				     m_pe(e.m_pe),
				     m_s_in(e.m_s_in),
				     m_h(e.m_h),
				     m_in(e.m_in){
}

Network	&Network::operator=(Network const &e){
  this->m_name = e.m_name;
  this->m_port = e.m_port;
  this->m_host = e.m_host;
  this->m_fd_read = e.m_fd_read;
  this->m_fd_write = e.m_fd_write;
  this->m_fd = e.m_fd;
  this->m_pe = e.m_pe;
  this->m_s_in = e.m_s_in;
  this->m_h = e.m_h;
  this->m_in = e.m_in;
  return (*this);
}

Network::~Network(){
  if (close(this->m_fd) == -1)
    throw ErrorClient(std::string(strerror(errno)), "Network");
}

void	Network::initNetwork(){
  try {
    if (!(this->m_pe = getprotobyname("TCP")))
      throw ErrorClient(std::string(strerror(errno)), "Network");
    if ((this->m_h = gethostbyname(this->m_host.c_str())) == NULL)
      throw ErrorClient(std::string(strerror(errno)), "Network");
    memcpy(&this->m_in, this->m_h->h_addr, sizeof(this->m_in));
    this->m_s_in.sin_family = AF_INET;
    this->m_s_in.sin_port = htons(StringToNumber<int>(this->m_port));
    if ((this->m_fd = socket(PF_INET, SOCK_STREAM, this->m_pe->p_proto)) == -1)
      throw ErrorClient(std::string(strerror(errno)), "Network");
    if (connect(this->m_fd, (struct sockaddr *)&this->m_s_in,
		sizeof(this->m_s_in)) == -1)
      throw ErrorClient(std::string(strerror(errno)), "Network");
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void		Network::sendCmd(std::string const &msg){
  try {
    std::string	tmp;
    unsigned int		i = 0;

    if (msg.length() > BUFF_SIZE){
      while (msg.length() >= i){
	tmp += msg.substr(i, BUFF_SIZE + i);
	i += BUFF_SIZE;
      }
      this->m_writeList.push_back(tmp);
    }
    else if (msg.length() != 0)
      this->m_writeList.push_back(msg);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void		Network::mSend(){
  try {
    char		buf[BUFF_SIZE];

    this->initBuff(buf);
    if (!this->m_writeList.empty() && !this->m_writeList.front().empty()){
      if (write(this->m_fd, this->m_writeList.front().c_str(),
		this->m_writeList.front().length()) == -1)
	throw ErrorClient(std::string(strerror(errno)), "Network");
      this->m_writeList.erase(this->m_writeList.begin());
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

std::string	Network::readCmd(){
  try {
    std::string	tmp = "";

    if (!this->m_readList.empty() &&
	this->m_readList.front().find('\n') != std::string::npos){
      tmp = this->m_readList.front();
      this->m_readList.erase(this->m_readList.begin());
    }
    return (tmp);
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void	Network::mRecv(){
  try {
    char		buf[BUFF_SIZE];
    int			error = 0;
    std::size_t		pos;

    this->initBuff(buf);
    if ((error = recv(this->m_fd, buf, BUFF_SIZE, 0)) == -1)
      throw ErrorClient(std::string(strerror(errno)), "Network");
    else if (error == 0)
      throw ErrorClient("Server shutdown", "Network");
    std::string	tmp(buf);
    while (!tmp.empty()){
      pos = tmp.find('\n');
      if (!this->m_readList.empty() &&
      	  this->m_readList.back().find('\n') == std::string::npos &&
	  pos != std::string::npos){
      	this->m_readList.back() += tmp.substr(0, pos + 1);
      	tmp = tmp.substr(pos + 1, tmp.length());
      } else if (!this->m_readList.empty() &&
		 this->m_readList.back().find('\n') == std::string::npos &&
		 pos == std::string::npos){
	this->m_readList.back() += tmp;
      	tmp = tmp.erase();
      } else if (pos != std::string::npos) {
	this->m_readList.push_back(tmp.substr(0, pos + 1));
	tmp = tmp.substr(pos + 1, tmp.length());
      } else {
	this->m_readList.push_back(tmp);
	tmp.erase();
      }
    }
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void			Network::initFd(){
  try {
    struct timeval	tv;

    tv.tv_sec = 5;
    tv.tv_usec = 0;
    FD_ZERO(&(this->m_fd_read));
    FD_ZERO(&(this->m_fd_write));
    FD_SET(this->m_fd, &(this->m_fd_read));
    FD_SET(this->m_fd, &(this->m_fd_write));
    if (select(this->m_fd + 1, &(this->m_fd_read), &(this->m_fd_write),
	       NULL, &tv) == -1)
      throw ErrorClient(std::string(strerror(errno)), "Network");
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void	Network::initBuff(char *buf){
  try {
    for (int i = 0; i < BUFF_SIZE; ++i)
      buf[i] = 0;
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void	Network::fdIsset(){
  try {
    FD_ZERO(&(this->m_fd_read));
    FD_ZERO(&(this->m_fd_write));
    FD_SET(this->m_fd, &(this->m_fd_read));
    FD_SET(this->m_fd, &(this->m_fd_write));
    if (select(this->m_fd + 1, &(this->m_fd_read), &(this->m_fd_write),
	       NULL, NULL) == -1)
      throw ErrorClient(std::string(strerror(errno)), "Network");
    if (FD_ISSET(this->m_fd, &(this->m_fd_write)))
      this->mSend();
    if (FD_ISSET(this->m_fd, &(this->m_fd_read)))
      this->mRecv();
  } catch (ErrorClient const &e) {
    throw ErrorClient(e.what(), "Network");
  }
}

void	Network::displayTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
  std::cout << "time: " << buf << std::endl;
}
