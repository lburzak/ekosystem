#ifndef BODYREGISTRY_H
#define BODYREGISTRY_H

#include <map>
#include "body.h"



class BodyRegistry {
public:
    Body* fetch(unsigned id) {
        auto it = idToBody.find(id);

        if (it != idToBody.end()) {
            return it->second;
        } else exit(70);
    }

    void registerBody(Body& body) {
        body.id = lastId++;
        idToBody.insert(std::make_pair(body.getId(), &body));
    }

private:
    unsigned lastId = 0;
    std::map<unsigned, Body*> idToBody;
};

#endif // BODYREGISTRY_H
