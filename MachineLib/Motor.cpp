/**
 * @file Motor.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "Motor.h"

/**
 * Motor constructor
 * @param imageDir directory containing all the image files
 */
Motor::Motor(wxString imageDir) : mImgDir(imageDir)
{
    mShaft.CenteredSquare(20);
    mShaft.SetImage(mImgDir + L"/shaft.png");
}

/**
 * The function that allows you draw motor on the screen
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, GetPosition().x, GetPosition().y);
    mShaft.DrawPolygon(graphics, GetPosition().x, GetPosition().y);
}

/**
 * Set speed for the motor
 * @param speed speed for the motor, double
 */
void Motor::SetSpeed(double speed) {
    mSpeed = speed;
}

/**
 * Set time for the motor
 * @param time time for the motor, double
 */
void Motor::SetTime(double time)
{
    mRotation = time * mSpeed;
    mShaft.SetRotation(mRotation);
    Rotate(mRotation);
}

/**
 * Reset the motor, set mRotation to 0.
 */
void Motor::Reset()
{
    mRotation = 0;
}

/**
 * Rotation function that connected to the MotionSource
 * @param rotation
 */
void Motor::Rotate(double rotation)
{
    mSource.Rotate(rotation);
}