/**
 * @file Motor.h
 * @author Lance Y.
 *
 * Motor class for the machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTOR_H

#include "Component.h"
#include "MotionSource.h"

/**
 * Class motor from the machine, derived from component.
 */
class Motor : public Component
{
private:
    /// Directory for the image
    wxString mImgDir;

    /// Rotation of the motor
    double mRotation = 0;

    /// mShaft inherited from Polygon
    cse335::Polygon mShaft;

    /// Speed of the motor
    double mSpeed;

    /// Rotation source for this component
    MotionSource mSource;

    /// size of the motor
    const int mSize = 80;


public:
    Motor(wxString imageDir);

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;
    /// Assignment operator (disabled)
    void operator=(const Motor &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
    void SetTime(double time) override;
    void Reset() override;

    void SetSpeed(double speed);

    /**
     * Get size of the motor
     * @return size of the motor
     */
    int GetSize() const {return mSize;}

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    MotionSource *GetSource() { return &mSource; }

    void Rotate(double rotation);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTOR_H