/**
 * @file Component.h
 * @author Lance Y.
 *
 * Component class for the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H

#include "Polygon.h"

class Machine;

/**
 * Component class. Including all the parts of the machine, inherited from Polygon class
 */
class Component : public cse335::Polygon
{
private:
    /// Location of the component
    wxPoint mLocation = wxPoint(0,0);

    /// The machine contain all the components
    Machine* mMachine = nullptr;

public:

    void SetMachine(Machine *machine);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y);
    virtual void SetTime(double time);
    virtual void Reset();
    virtual void Advance(double delta);

    /**
     * Getter for position
     * @return mLocation, location of the component
     */
    wxPoint GetPosition() const {return mLocation;}
    /**
     * Setter for the position
     * @param x x-coordinate of the location
     * @param y y-coordinate of the location
     */
    void SetPosition(int x , int y) {mLocation = wxPoint(x,y);}

    /**
     * Get X coordinate of the component
     * @return x-point
     */
    int GetX() const {return mLocation.x;}
    /**
     * Get Y coordinate of the component
     * @return y-point
     */
    int GetY() const {return mLocation.y;}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
