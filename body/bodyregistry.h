#ifndef BODYREGISTRY_H
#define BODYREGISTRY_H

#include <map>
#include "body.h"



class BodyRegistry {
public:
    Body* fetch(unsigned id);
    void registerBody(Body& body);

private:
    unsigned lastId = 0;
    std::map<unsigned, Body*> idToBody;
};

#endif // BODYREGISTRY_H
