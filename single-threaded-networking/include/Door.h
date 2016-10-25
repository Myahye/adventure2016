#ifndef Door_h
#define Door_h

#include <iostream>
#include <vector>
#include <string>

class Door{
public:
    Door();
    Door(std::string dir);
    Door(std::string dir, std::string description, int destinationId);
    Door(std::string& new_desc, std::string& new_dir, std::string& new_keywords, int& new_door_id, int& new_destinationId);

    std::string getDesc() const;
    std::string getDir() const;
    std::string getKeywords() const;
    int getDoorId() const;
    int getDestinationId() const;

    void setDesc(const std::string& new_desc);
    void setDir(const std::string& new_dir);
    void setKeywords(const std::string& new_keywords);
    void setDoorId(const int new_door_id);


private:
    std::string desc;
    std::string dir;
    std::string keywords;
    unsigned int Door_id;
    unsigned int destinationId;

};
#endif /* Door_h */
