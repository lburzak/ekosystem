#ifndef BODYNOTINSPACEEXCEPTION_H
#define BODYNOTINSPACEEXCEPTION_H

#include <exception>



class BodyNotInSpaceException : public std::exception {
    virtual const char* what() const throw() {
        return "Body is not present in space.";
    }
};

#endif // BODYNOTINSPACEEXCEPTION_H
