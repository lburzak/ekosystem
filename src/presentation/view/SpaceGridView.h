//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_SPACEGRIDVIEW_H
#define EKOSYSTEM_SPACEGRIDVIEW_H

class SpaceGridView {
public:
    virtual void onTileSelectedChange(int index) = 0;
    virtual void onOrganismsCountChange(int index) = 0;
    virtual void onDataChange() = 0;
};

#endif //EKOSYSTEM_SPACEGRIDVIEW_H
