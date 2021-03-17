#pragma once
#include <string>
#include <vector>

#include <QJsonArray>
#include <QJsonObject>


class Aircraft
{
protected:
    std::string m_id;
    std::string m_model;
    std::string image_path;

public:
    virtual std::vector<std::string> isSuitableFor() const = 0;
    virtual double maxAltitude() const = 0;
    virtual std::string toString() const = 0;
    virtual std::string get_image_path();
    virtual void set_image_path(std::string new_image_path);

    // function to convert a base Aircraft to a json document
    // we are making this function virtual as we'll override in the derived classes!
    virtual QJsonObject toJsonObject(){
        QJsonObject obj; // we are creating a QJsonObject which will store the current Aircraft in json format
        obj["id"] = m_id.c_str(); // we are adding the id of the to this json object . one whay to achive this is using the syntax is obj[key] = value;
        // we need to convert our class member from std::string to char* (m_id.c_str() and m_model.c_str())
        // because there is no viable overload between a std::string and a QString
        obj.insert("model", m_model.c_str()); // we are adding the model of the to this json object . another whay to achive this is using the syntax is obj.insert(key, value);

        // the format of this json object is something like this:
        // {
        //      "id": "myid",
        //      "model": "modelxyz"
        //  }
        return obj;
    }

public:
    Aircraft(const std::string& id, const std::string model) : m_id{ id }, m_model{ model } {}
    virtual ~Aircraft() {}
};

class Helicopter : public Aircraft
{
private:
    bool m_isPrivate;

public:
    Helicopter(const std::string& id, const std::string model, bool isPrivate) : Aircraft{ id, model }, m_isPrivate{ isPrivate } {}

    virtual QJsonObject toJsonObject(){
        QJsonObject obj = Aircraft::toJsonObject(); // we are calling the toJsonObject method from the parent class, delegation of duty
        // the obj now contains the id and the model of the aircraft
        //  we must add the additional data that an helicopter can store: if it is private
        obj["isPrivate"] = m_isPrivate ? "true" : "false";
        obj["type"] = "helicopter"; // we are also adding a type element to the json file to be able to determine the type of the aircraft
        QJsonArray suitableForJsonArray; // we are creating a json array to store the activities that this object is suitable for
        std::vector<std::string> suitableFor = isSuitableFor(); // calling the method isSuitableFor() to get the suitable actvities of the current object
        for(auto act: suitableFor){ // we are traversing through these activities using the range based for
            suitableForJsonArray.push_back(act.c_str()); // we are adding the activity on the json array
        }
        obj["suitableFor"] = suitableForJsonArray; // finally, we are adding suitableForJsonArray to the QJsonObject obj

        // the format of this json object is something like this:
//        {
//            "id": "1",
//            "isPrivate": "true",
//            "model": "model1",
//            "suitableFor": [
//                "military",
//                "medical emergencies",
//                "public transportation",
//                "leisure time"
//            ],
//            "type": "helicopter"
//        }
        return obj;
    }
    std::vector<std::string> isSuitableFor() const override;
    double maxAltitude() const override;
    std::string toString() const override;
};

class Plane : public Aircraft
{
private:
    bool m_isPrivate;
    std::string m_main_wings;

public:
    Plane(const std::string& id, const std::string model, bool isPrivate, std::string main_wings) :
        Aircraft{ id, model }, m_isPrivate{ isPrivate }, m_main_wings{ main_wings } {};

    virtual QJsonObject toJsonObject(){
        QJsonObject obj = Aircraft::toJsonObject(); // we are calling the toJsonObject method from the parent class, delegation of duty
        // the obj now contains the id and the model of the aircraft
        //  we must add the additional data that an helicopter can store: if it is private
        obj["isPrivate"] = m_isPrivate ? "true" : "false";
        obj["type"] = "plane"; // we are also adding a type element to the json file to be able to determine the type of the aircraft
        obj["mainWings"] = m_main_wings.c_str();

        QJsonArray suitableForJsonArray; // we are creating a json array to store the activities that this object is suitable for
        std::vector<std::string> suitableFor = isSuitableFor(); // calling the method isSuitableFor() to get the suitable actvities of the current object
        for(auto act: suitableFor){ // we are traversing through these activities using the range based for
            suitableForJsonArray.push_back(act.c_str()); // we are adding the activity on the json array
        }
        obj["suitableFor"] = suitableForJsonArray; // finally, we are adding suitableForJsonArray to the QJsonObject obj
        obj["type"] = "plane";
        return obj;
    }
    std::vector<std::string> isSuitableFor() const override;
    double maxAltitude() const override;
    std::string toString() const override;
};

class HotAirBalloon : public Aircraft
{
private:
    double m_weightLimit;

public:
    HotAirBalloon(const std::string& id, const std::string model, double weightLimit) : Aircraft{ id, model }, m_weightLimit{ weightLimit } {}

    virtual QJsonObject toJsonObject(){
        QJsonObject obj = Aircraft::toJsonObject(); // we are calling the toJsonObject method from the parent class, delegation of duty
        // the obj now contains the id and the model of the aircraft
        //  we must add the additional data that an helicopter can store: if it is private

        obj["type"] = "plane"; // we are also adding a type element to the json file to be able to determine the type of the aircraft
        obj["weightLimit"] = m_weightLimit;

        QJsonArray suitableForJsonArray; // we are creating a json array to store the activities that this object is suitable for
        std::vector<std::string> suitableFor = isSuitableFor(); // calling the method isSuitableFor() to get the suitable actvities of the current object
        for(auto act: suitableFor){ // we are traversing through these activities using the range based for
            suitableForJsonArray.push_back(act.c_str()); // we are adding the activity on the json array
        }
        obj["suitableFor"] = suitableForJsonArray; // finally, we are adding suitableForJsonArray to the QJsonObject obj
        obj["type"] = "hot air ballon";
        return obj;
    }
    std::vector<std::string> isSuitableFor() const override;
    double maxAltitude() const override;
    std::string toString() const override;
};
