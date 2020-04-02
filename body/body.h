#ifndef BODY_H
#define BODY_H


class Body {
public:
    bool operator< (const Body &right) const {
        return id < right.id;
    }

    unsigned getId() {
        return id;
    }

    virtual void _() {};
private:
    unsigned id;

    friend class BodyRegistry;
    friend class VicinityProvider;
};

#endif // BODY_H
