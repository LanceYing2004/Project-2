/**
 * @file SnowBlowerBody.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "SnowBlowerBody.h"
#include "Snow.h"

/// Average amount of snow created per rotation
const double SnowPerRotation = 1000;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.25;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 100;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 90;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 110;

///////////////////////////////////////

/// Probability of a snow particle expanding
const double SnowExpansionProbability = 0.05;

/// Constant epsilon
const double epsilon = 0.0001;

/**
 * Constructor for snow blower body
 * @param imageDir image directory used to story all the files
 */
SnowBlowerBody::SnowBlowerBody(wxString imageDir) : mImgDir(imageDir)
{
    std::random_device rd;	// Generates a random seed
    mRandom.seed(rd());		// Seed the random number generator
}

/**
 * Function that draw snow blower body on the screen
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void SnowBlowerBody::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

//    graphics->PushState();
    for (auto snow : mSnow) {

        if (mYellowSnow)
        {
            snow.SetYellowSnow();
        }
        snow.Draw(graphics, x, y);
    }
//    graphics->PopState();

    Component::Draw(graphics, x, y);
}

/**
 * Rotate the snow blower body to a certain angle, and use the value of rotation
 * to determine amount of snow that should be generated.
 * @param rotation rotation value of the snow blower body
 */
void SnowBlowerBody::Rotate(double rotation)
{
    double diff = rotation - mRotation;
    mRotation = rotation;
    CalcRotate(diff);

    if (mOscillate) {Oscillate(diff);}

}

/**
 * Calculate the amount of snow generated per second.
 * @param rotation rotation difference of the previous function
 */
void SnowBlowerBody::CalcRotate(double rotation)
{
    // Compute how much snow to generate for this amount of rotation.
    auto num = (int)(rotation * (SnowPerRotation + Random(-SnowVariancePerSecond, SnowVariancePerSecond)));

    // Reduce the amount of snow
    num /= 3;

    for (int i = 0; i < num; i++)
    {   // GetRotation gets the rotation of the snow machine.
        // This code computes a vector to the emitting end of the
        // snow machine. The random value means that position is over
        // the entire end of the machine, not just a single point.
        auto angle = GetRotation() * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
        auto dx = sin(angle);
        auto dy = -cos(angle);

        auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
        auto dx1 = sin(angle1);
        auto dy1 = -cos(angle1);

        double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
        double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);

        wxPoint2DDouble snowPosition((float)(GetX()+dx * offset), (float)(GetY()+dy * offset));
        wxPoint2DDouble snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));

        auto snowflake = Snow();
        snowflake.setMp(snowPosition);
        snowflake.setMv(snowVelocity);

        mSnow.push_back(snowflake);
    }
}

/**
 * Advance function to drive the snow moving forward
 * @param delta time difference
 */
void SnowBlowerBody::Advance(double delta)
{
    for (auto snow= mSnow.begin(); snow != mSnow.end(); snow++)
    {
        if (mIncrementSnow)
        {
            double prob = Random(0, 1);
            if (prob < SnowExpansionProbability)
            {
                snow->IncreaseSize();
            }
        }
        if (snow->getMp().m_y > 600)
        {

        }
        snow->Advance(delta);
    }
}

/**
 * Generate a uniform distribution random number from fmValue to toValue
 * \param fmValue Minimum value to generate
 * \param toValue Maximum value to generate
 * \return Random number
 */
double SnowBlowerBody::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}

/**
 * Set the yellow snow status to true
 */
void SnowBlowerBody::SetYellowSnow()
{
    mYellowSnow = true;
}

/**
 * Set the increment snow status to true
 */
void SnowBlowerBody::SetIncrementSnow()
{
    mIncrementSnow = true;
}

/**
 * Set the oscillate status to true
 */
void SnowBlowerBody::SetOscillate()
{
    mOscillate = true;
}

/**
 * Oscillate the snow blower body
 * @param diff rotation value been passed down to the function
 */
void SnowBlowerBody::Oscillate(double diff)
{
    if (mIsOsc)
    {
        SetRotation(GetRotation() + 0.05 * diff);
    }
    if (!mIsOsc){
        SetRotation(GetRotation() - 0.05 * diff);
    }

    if (GetRotation() < 0.05)
    {
        mIsOsc = true;
    }
    if (GetRotation() > 0.25)
    {
        mIsOsc = false;
    }
}


