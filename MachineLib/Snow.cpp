/**
 * @file Snow.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "Snow.h"
#include "SnowBlowerBody.h"

/// Gravity in pixels per second per second
const float Gravity = 15;

/// Probability of a snow particle being a yellow snow
const double YellowSnowProbability = 0.1;

/**
 * Snow constructor, set default radius to 2
 */
Snow::Snow() : mP(0,0), mV(0,0), mRadius(2)
{
    DetermineColor();
}

/**
 * Draw snow on the screen
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Snow::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) {
    if(mYellowSnow)
    {
        wxColour color = mYellowSnowProb ? *wxYELLOW : *wxWHITE;
        wxBrush brush(color);
        graphics->SetBrush(brush);
        graphics->SetPen(wxPen(color));
    }
    else
    {
        wxColour color = *wxWHITE;
        wxBrush brush(color);
        graphics->SetBrush(brush);
        graphics->SetPen(wxPen(color));
    }
    graphics->DrawEllipse((int)mP.m_x + x - mRadius, (int)mP.m_y + y - mRadius, mRadius, mRadius);
}

/**
 * Advance function for the snow, allowing snow to progress forward
 * @param delta time difference
 */
void Snow::Advance(double delta) {
    // Gravity affects the y-component of velocity
    mV = wxPoint2DDouble(mV.m_x, mV.m_y + Gravity * delta);
    mP = wxPoint2DDouble(mP.m_x + mV.m_x * delta, mP.m_y + mV.m_y * delta);
}

/**
 * Increase size of the snow
 */
void Snow::IncreaseSize()
{
    mRadius++;
}

/**
 * Set the yellow snow status to true
 */
void Snow::SetYellowSnow()
{
    mYellowSnow = true;
}

/**
 * Set position for the snow particles
 * @param MP position
 */
void Snow::setMp(const wxPoint2DDouble &MP)
{
    mP = MP;
}

/**
 * Set velocity for the snow particles
 * @param MV velocity
 */
void Snow::setMv(const wxPoint2DDouble &MV)
{
    mV = MV;
}

/**
 * Get position for the snow particles
 * @return position
 */
const wxPoint2DDouble &Snow::getMp() const
{
    return mP;
}

/**
 * Set velocity for the snow particles
 * @return velocity
 */
const wxPoint2DDouble &Snow::getMv() const
{
    return mV;
}

/**
 * Determine the color of the snow
 */
void Snow::DetermineColor()
{
    // Generate a number between 0 and 1
    double prob = ((double) rand() / (RAND_MAX));
    mYellowSnowProb = prob < YellowSnowProbability;
}