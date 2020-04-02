#include <iostream>
#include <set>
#include <map>
#include <space/vicinity.h>
#include <space/vicinityprovider.h>
#include "body/body.h"
#include "body/bodyregistry.h"
#include "space/space.h"

using namespace std;

class Human : public Body {
public:
    void eat() { cout << "eating!" << endl; };
};

class Virus : public Body {
public:
    void onTick(Vicinity vicinity) {
        set<Body*> bodies = vicinity.getBodies();
        for (auto it = bodies.begin(); it != bodies.end(); it++) {
            if (Human* human = dynamic_cast<Human*>(*it)) {
                attack(human);
                human->eat();
            }
        }
    }
private:
    void attack(Human* human) {
        victim = human;
    }
    Human* victim = nullptr;
};

int main() {
    BodyRegistry bodyRegistry;
    Space space(bodyRegistry);
    VicinityProvider vicinityProvider(space);

    Human human;
    Virus virus;

    bodyRegistry.registerBody(virus);
    bodyRegistry.registerBody(human);
    space.putAt(virus, 1, 1);
    space.putAt(human, 1, 1);
    Vicinity* virusVicinity = vicinityProvider.provideFor(virus);
    virus.onTick(*virusVicinity);

    cout << "Hello World!" << endl;
    return 0;
}
