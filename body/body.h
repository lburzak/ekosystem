#ifndef BODY_H
#define BODY_H


class Body {
    friend class BodyRegistry;
    friend class VicinityProvider;

public:
    Body(unsigned mass) : mass(mass) {}

    bool operator< (const Body &right) const {
        return id < right.id;
    }

    unsigned getId();

private:
    unsigned id;
    unsigned mass;

    /**
     * @brief Makes class polymorphic (allows for dynamic casting)
     */
    virtual void _() {};
};

#endif // BODY_H
