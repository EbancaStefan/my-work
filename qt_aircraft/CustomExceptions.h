#pragma once
#include <exception>
#include <string>

using namespace std;

class BaseRepoException :public exception
{
public:
    const char* what() const override;
};

class FileException :public BaseRepoException
{
private:
    string path_name;
    std::string m_exceptionMessage;
public:
    FileException(string path_name) :path_name(path_name) {
        m_exceptionMessage = "The file "+path_name+" does not exist\n";
    }
    const char* what() const {
        //        string msg{std::string("Input file ") + path_name + " not found"};
        //        return msg.c_str();  -> the problem was that msg goes out of scope at the ent of the method
        return m_exceptionMessage.c_str(); // so we created a new member function m_exceptionMessage, which holds the string that the exception will return in the what() method
        // however the what() method is marked with const and we cannot change any member variable inside this method, so we initialize the m_exceptionMessage variable in the constructor
    }
};

class OutofBoundException :public BaseRepoException
{
public:
    const char* what() const { return "Out of bound"; };
};
