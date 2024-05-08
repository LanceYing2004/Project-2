/**
 * @file Snow.h
 * @author Lance Y.
 *
 * Snow class of the machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOW_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOW_H

#include <random>

class SnowBlowerBody;

/**
 * Snow class for the machine.
 */
class Snow
{
private:
    /// Position of the snow
    wxPoint2DDouble mP;

    /// Velocity of the snow
    wxPoint2DDouble mV;

    /// The machine contain all the components
    SnowBlowerBody* mSnowBlowerBody = nullptr;

    /// Radius of the snow
    double mRadius;

    /// Boolean to check if Yellow Snow is enabled
    bool mYellowSnow = false;

    /// Boolean to check if Yellow Snow probability function is enabled
    bool mYellowSnowProb = false;

public:
    Snow();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    void Advance(double delta);

    void setMp(const wxPoint2DDouble &MP);
    void setMv(const wxPoint2DDouble &MV);

    const wxPoint2DDouble &getMp() const;
    const wxPoint2DDouble &getMv() const;

    void IncreaseSize();
    void SetYellowSnow();
    void DetermineColor();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOW_H
