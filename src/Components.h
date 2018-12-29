//
// Created by mike on 30.12.2018.
//

#ifndef GSDL_COMPONENTS_H
#define GSDL_COMPONENTS_H

#include "EntityComponentSys.h"

class PositionComponent : public Component {
private:
    int xpos;
    int ypos;

public:
    int x() { return xpos; }
    int y() { return ypos; }

    void init() override {
        xpos = 0;
        ypos = 0;
    }

    void update() override {
        xpos++;
        ypos++;
    }

    void setPos(int x, int y) {
        xpos = x;
        ypos = y;
    }


};

#endif //GSDL_COMPONENTS_H
