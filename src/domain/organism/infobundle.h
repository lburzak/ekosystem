#ifndef INFOBUNDLE_H
#define INFOBUNDLE_H

#include <string>
#include <map>

using namespace std;


class InfoBundle {
public:
    void set(string key, string value);
    string get(string key);
    string toString();

private:
    map<string, string> data;
};

#endif // INFOBUNDLE_H
