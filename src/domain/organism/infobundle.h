#ifndef INFOBUNDLE_H
#define INFOBUNDLE_H

#include <string>
#include <map>
#include <set>

using namespace std;


class InfoBundle {
public:
    void set(string key, string value);
    string get(string key);
    string toString();
    std::set<string> keys();

private:
    map<string, string> data;
};

#endif // INFOBUNDLE_H
