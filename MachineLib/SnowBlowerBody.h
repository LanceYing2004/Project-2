/**
 * @file SnowBlowerBody.h
 * @author Lance Y.
 *
 * SnowBlowerBody class for the machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWERBODY_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWERBODY_H

#include "Component.h"
#include "IMotionSink.h"
#include <random>

class Snow;

/**
 * SnowBlowerBody class for the machine, derived from both Component and IMotionSink.
 */
class SnowBlowerBody : public Component, public IMotionSink
{
private:

    /// image directory
    wxString mImgDir;

    /// Snowblower for the machine
    std::vector<Snow> mSnow;

    /// random variable used to generate random numbers
    std::mt19937 mRandom;

    /// rotation for the snowblower
    double mRotation = 0.0;

    /// Boolean to check if Increment Snow function is enabled
    bool mIncrementSnow = false;

    /// Boolean to check if Oscillation function is enabled
    bool mOscillate = false;

    /// Boolean to check if Yellow Snow function is enabled
    bool mYellowSnow = false;

    /// Oscillation direction of the machine
    bool mIsOsc;

public:
    SnowBlowerBody(wxString imageDir);

    /// Copy constructor (disabled)
    SnowBlowerBody(const SnowBlowerBody &) = delete;
    /// Assignment operator (disabled)
    void operator=(const SnowBlowerBody &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y) override;
    void Rotate(double rotation) override;
    void Advance(double delta) override;

    void CalcRotate(double rotation);

    double Random(double fmValue, double toValue);

    void SetIncrementSnow();
    void SetOscillate();
    void SetYellowSnow();

    void Oscillate(double diff);

    /**
     * Get sink of the snow blower body
     * @return this
     */
    IMotionSink* GetSink() { return this; }
};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWERBODY_H
