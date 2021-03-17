#include "Aircraft.h"

using namespace std;

std::vector<std::string> Helicopter::isSuitableFor() const
{
    vector<string> activities{"military", "medical emergencies", "public transportation"};
    if (this->m_isPrivate)
        activities.push_back("leisure time");

    return activities;
}

double Helicopter::maxAltitude() const
{
    return 12;
}

std::string Helicopter::toString() const
{
    string res{this->m_id};
    res += ", " + this->m_model;
    string pr = (this->m_isPrivate ? "private" : "public");
    res += ", " + pr;
    return res;
}

std::vector<std::string> HotAirBalloon::isSuitableFor() const
{
    vector<string> activities{ "leisure time" };
    return activities;
}

double HotAirBalloon::maxAltitude() const
{
    return m_weightLimit;
}

std::string HotAirBalloon::toString() const
{
    string res{ this->m_id };
    res += ", " + this->m_model;
    res += ", " + std::to_string(this->m_weightLimit);
    return res;
}

std::vector<std::string> Plane::isSuitableFor() const
{
    vector<string> activities{ "military", "medical emergencies", "public transportation" };
    if (this->m_main_wings == "biplane")
        activities.push_back("leisure time");
    return activities;
}

double Plane::maxAltitude() const
{
    return 26;
}

std::string Plane::toString() const
{
    string res{ this->m_id };
    res += ", " + this->m_model;
    string pr = (this->m_isPrivate ? "private" : "public");
    res += ", " + pr;
    res += ", " + this->m_main_wings;
    return res;
}

std::string Aircraft::get_image_path()
{
    return image_path;
}

void Aircraft::set_image_path(std::string new_image_path)
{
    image_path = new_image_path;
}
