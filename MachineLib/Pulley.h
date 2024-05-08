/**
 * @file Pulley.h
 * @author Lance Y.
 *
 * Pulley class of the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H

#include "Component.h"
#include "MotionSource.h"
#include "IMotionSink.h"

/// Maximum amount to rock the belt
const double BeltRockAmount = 0.01;

/// How quickly to rock the belt in radians per second
/// This is divided by the length to get the actual rate
const double BeltRockBaseRate = M_PI * 1000;

/**
 * Pulley class for the machine, derived from both component and IMotionSink.
 */
class Pulley : public Component, public IMotionSink
{
private:
    /// Motion Source for the machine system
    MotionSource mSource;

    /// radius of pulley
    double mRadius = 0.0;

    /// Connected pulley with current pulley
    Pulley* mConnectedPulley = nullptr;

    /// Rock angle, which is the tilt angle of the belts
    double mCurrentRockAngle = 0.0;

    /// Rock rate, the frequency of which belts vibrates
    double mRockRate = 0.0;

    /// Boolean used to detect machine 1 or machine 2
    bool mFlappyBelts = false;

public:

    Pulley(double radius);

    /// Copy constructor (disabled)
    Pulley(const Pulley &) = delete;
    /// Assignment operator (disabled)
    void operator=(const Pulley &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y) override;
    void Rotate(double rotation) override;
    void SetTime(double time) override;

    /**
     * Get sink of the pulley
     * @return this
     */
    IMotionSink* GetSink() { return this; }

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    MotionSource* GetSource() { return &mSource; }

    /**
     * Get radius of the pulley
     * @return mRadius
     */
    double GetRadius() const {return mRadius;}

    void Drive(std::shared_ptr<Pulley> other);

    void SetFlappyBelts();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
