#include "infobundle.h"

void InfoBundle::set(string key, string value) {
    data.insert(make_pair(key, value));
}

string InfoBundle::get(string key) {
    auto it = data.find(key);

    if (it != data.end()) {
        return (*it).second;
    } else {
        return "N/D";
    }
}

string InfoBundle::toString() {
    string buf = "{";

    for (auto it = data.begin(); it != data.end(); it++) {
        buf += (*it).first + "=" + (*it).second + ", ";
    }

    buf.pop_back();
    buf.pop_back();

    buf += "}";

    return buf;
}

std::set<string> InfoBundle::keys() {
    std::set<string> k;

    for (const auto& entry : data) {
        k.insert(entry.first);
    }

    return k;
}
