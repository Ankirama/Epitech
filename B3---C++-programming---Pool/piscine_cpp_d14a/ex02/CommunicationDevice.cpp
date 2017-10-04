
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
try : _api(input, output)
{
    
}
catch (const std::exception &e){
    std::string tmp = "Error: ";
    int i = -1;
    while (e.what()[++i])
        tmp += e.what()[i];
    throw CommunicationError(tmp);
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    }
    catch (const std::logic_error& e) {
        std::string tmp = "LogicError: ";
        int i = -1;
        while (e.what()[++i])
            tmp += e.what()[i];
        throw std::logic_error(tmp);
    }
    catch (const std::runtime_error& e) {
        std::string tmp = "RuntimeError: ";
        int i = -1;
        while (e.what()[++i])
            tmp += e.what()[i];
        throw std::runtime_error(tmp);
    }
    catch (const std::exception& e) {
        std::string tmp = "Error: ";
        int i = -1;
        while (e.what()[++i])
            tmp += e.what()[i];
        throw CommunicationError(tmp);
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
    _api.sendMessage(user, message);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
        message = "INVALID MESSAGE";
    }
}
