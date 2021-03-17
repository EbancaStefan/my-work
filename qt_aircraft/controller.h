#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "aircraft.h"
#include <vector>
#include <iostream>
class Controller
{
public:
    Controller();
    ~Controller();

    void add(std::shared_ptr<Aircraft> aircraft);
    std::vector<std::shared_ptr<Aircraft>> filterByActivity(const std::string& activity);
    void displayAll();
    bool saveToJsonFile(std::string jsonPath);
    void loadRepo(std::string document);
private:
    std::vector<std::shared_ptr<Aircraft>> m_repo;
    std::vector<std::string> tokenize_cs_line(std::string line);
};

#endif // CONTROLLER_H
