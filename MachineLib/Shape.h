/**
 * @file Shape.h
 * @author Lance Y.
 *
 * Shape class of the machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
#define CANADIANEXPERIENCE_MACHINELIB_SHAPE_H

#include "Component.h"
#include "IMotionSink.h"

/**
 * Shape class for the machine, derived from both component and IMotionSink.
 */
class Shape : public Component, public IMotionSink
{
private:

public:
    Shape();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y) override;
    void Rotate(double rotation) override;

    /**
     * Get the motion sink of the class
     * @return this
     */
    IMotionSink* GetSink() { return this; }

};

#endif //CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
