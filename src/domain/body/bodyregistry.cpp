#include "bodyregistry.h"


Body* BodyRegistry::fetch(unsigned id) {
    auto it = idToBody.find(id);

    if (it != idToBody.end()) {
        return it->second;
    } else exit(70);
}

void BodyRegistry::registerBody(Body& body) {
    body.id = lastId++;
    idToBody.insert(std::make_pair(body.getId(), &body));
}
