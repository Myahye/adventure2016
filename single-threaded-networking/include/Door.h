#ifndef Door_h
#define Door_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Door{
public:
    Door();
    Door(const std::string& dir);
    Door(const std::string& dir, const std::vector<std::string>& description, int destinationId);
    Door(const std::string& new_dir, const std::vector<std::string>& new_desc, const std::vector<std::string>& new_keywords, int new_door_id, int new_destinationId);

    std::string getDesc() const;
    std::vector<std::string> getDescV() const;
    std::string getDir() const;
    std::vector<std::string> getKeywords() const;
    int getDoorId() const;
    int getDestinationId() const;

    void setDesc(const std::vector<std::string>& new_desc);
    void setDir(const std::string& new_dir);
    void setKeywords(const std::vector<std::string>& new_keywords);
    void setDoorId(const int new_door_id);


private:
    std::vector<std::string> desc;
    std::string dir;
    std::vector<std::string> keywords;
    unsigned int Door_id;
    unsigned int destinationId;

};
#endif /* Door_h */