
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
    {
        public:
            NasaError(std::string const &message,
                      std::string const &component = "Unknown") : m_component(component), _message(message) {}
        virtual ~NasaError() throw() {}
        std::string const &getComponent() const {return this->m_component;}
        const char* what() const throw() {return _message.c_str();}
        protected:
        std::string     m_component;
        private:
            std::string _message;
    };

class MissionCriticalError : public NasaError
    {
        public:
            MissionCriticalError(std::string const &message,
                                 std::string const &component = "Unknown") : NasaError(message, component) {}
        virtual ~MissionCriticalError() throw() {}
    };

class LifeCriticalError : public NasaError
    {
        public:
            LifeCriticalError(std::string const &message,
                              std::string const &component = "Unknown") : NasaError(message, component){}
        virtual ~LifeCriticalError() throw() {}
    };

class UserError : public NasaError
    {
        public:
            UserError(std::string const &message,
                      std::string const &component = "Unknown") : NasaError(message, component) {}
        virtual ~UserError() throw() {}
    };

    class CommunicationError : public NasaError
    {
        public:
        CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice") {}
        virtual ~CommunicationError() throw() {}
    };
#endif
