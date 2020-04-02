#ifndef BODY_H
#define BODY_H


class Body {
    friend class BodyRegistry;
    friend class VicinityProvider;

public:
    bool operator< (const Body &right) const {
        return id < right.id;
    }

    unsigned getId();

private:
    unsigned id;

    /**
     * @brief Makes class polymorphic (allows for dynamic casting)
     */
    virtual void _() {};
};

#endif // BODY_H
