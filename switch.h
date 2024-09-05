#include <string>

class Switch
{
private:
    std::string name;
    std::string manufacturer;
    int number_of_ports;
public:
    Switch(const std::string& name, const std::string& manufacturer, int number_of_ports)
        : name(name), manufacturer(manufacturer), number_of_ports(number_of_ports) {}

    std::string getFullName() const;
    int getNumPort() const;
    void initialize() const;
};

class CiscoSwitch : public Switch {
public:
    CiscoSwitch(const std::string& name, int number_of_ports)
        : Switch(name, "Cisco", number_of_ports) {}
};

class HuaweiSwitch : public Switch {
public:
    HuaweiSwitch(const std::string& name, int number_of_ports)
        : Switch(name, "Huawei", number_of_ports) {}
};

class JuniperSwitch : public Switch {
public:
    JuniperSwitch(const std::string& name, int number_of_ports)
        : Switch(name, "Juniper", number_of_ports) {}
};