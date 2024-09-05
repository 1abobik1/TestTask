#include "switch.h"

#include <iostream>

std::string Switch::getFullName() const
{
    return manufacturer + ":" + name;
}

int Switch::getNumPort() const
{
    return number_of_ports;
}

void Switch::initialize() const {
    std::cout << getFullName() << ": Up " << getNumPort() << " ports\n";
}

void CiscoSwitch::initialize() const {
    std::cout << getFullName() << ": Up " << getNumPort() << " ports\n";
}

void HuaweiSwitch::initialize() const {
    std::cout << getFullName() << ": Up " << getNumPort() << " ports\n";
}

void JuniperSwitch::initialize() const {
    std::cout << getFullName() << ": Up " << getNumPort() << " ports\n";
}
