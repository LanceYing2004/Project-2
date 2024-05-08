/**
 * @file Pulley.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include <cmath>
#include "Pulley.h"

/**
 * Pulley constructor
 * @param radius radius for the pulley
 */
Pulley::Pulley(double radius) : mRadius(radius)
{
    mRadius = radius;
    Circle(mRadius);
}

/**
 * Set new time for pulley
 * @param time
 */
void Pulley::SetTime(double time) {
    if (mConnectedPulley) {
        // calculate length, setup rock-rate (the vibration of the belts), and update rock angle
        double length = wxPoint2DDouble(GetPosition() - mConnectedPulley->GetPosition()).GetVectorLength();
        mRockRate = BeltRockBaseRate / length;
        mCurrentRockAngle += time * mRockRate;
        mCurrentRockAngle = fmod(mCurrentRockAngle, 2 * M_PI);
    }
}

/**
 * Function that draw pulley on the screen
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if (mConnectedPulley)
    {
        wxPoint pos1 = GetPosition();
        wxPoint pos2 = mConnectedPulley->GetPosition();

        double radius1 = mRadius - 3;
        double radius2 = mConnectedPulley->GetRadius() - 3;

        double theta = atan2((pos1.y - pos2.y), (pos1.x - pos2.x));
        double phi = (radius1 - radius2) /
            (sqrt(pow(pos1.x - pos2.x, 2) + pow (pos1.y - pos2.y, 2)));
        double beta1 = theta + phi + M_PI / 2;
        double beta2 = theta - phi - M_PI / 2;

        if (mFlappyBelts)
        {
            wxGraphicsPath path = graphics->CreatePath();
            double flap = BeltRockAmount * sin(mCurrentRockAngle);

            wxPoint endPoint11(pos1.x + radius1 * cos(beta1), pos1.y + radius1 * sin(beta1) + flap * 250);
            wxPoint endPoint12(pos2.x + radius2 * cos(beta1), pos2.y + radius2 * sin(beta1) - flap * 250);
            wxPoint endPoint21(pos1.x + radius1 * cos(beta2), pos1.y + radius1 * sin(beta2) + flap * 250);
            wxPoint endPoint22(pos2.x + radius2 * cos(beta2), pos2.y + radius2 * sin(beta2) - flap * 250);

            path.MoveToPoint(endPoint11.x, endPoint11.y);
            path.AddCurveToPoint(endPoint11, endPoint12, endPoint12);
            path.MoveToPoint(endPoint21.x, endPoint21.y);
            path.AddCurveToPoint(endPoint21, endPoint22, endPoint22);

            wxPen pen(wxColour(0, 0, 0), 2);  // Black pen of width 2
            graphics->SetPen(pen);
            graphics->StrokePath(path);
        }

        wxPoint endPoint11(pos1.x + radius1 * cos(beta1), pos1.y + radius1 * sin(beta1));
        wxPoint endPoint12(pos2.x + radius2 * cos(beta1), pos2.y + radius2 * sin(beta1));
        wxPoint endPoint21(pos1.x + radius1 * cos(beta2), pos1.y + radius1 * sin(beta2));
        wxPoint endPoint22(pos2.x + radius2 * cos(beta2), pos2.y + radius2 * sin(beta2));

        wxPen penLine(*wxBLACK, 2);

        graphics->SetPen(penLine);
        graphics->StrokeLine(endPoint11.x, endPoint11.y, endPoint12.x, endPoint12.y);
        graphics->StrokeLine(endPoint21.x, endPoint21.y, endPoint22.x, endPoint22.y);
    }

    DrawPolygon(graphics, GetPosition().x, GetPosition().y);
}

/**
 * Rotate the pulley
 * @param rotation rotation value of the pulley
 */
void Pulley::Rotate(double rotation)
{
    // Upcall to ensure the polygon rotation gets set
    SetRotation(rotation);

    mSource.Rotate(rotation);

    // Set the rotation for any pulley we are connected to by a belt.
    if (mConnectedPulley != nullptr)
    {
        auto speed = mRadius / mConnectedPulley -> mRadius;
        mConnectedPulley->SetRotation(rotation * speed);
    }
}

/**
 * Pulley acted as motion source to drive other pulleys
 * @param other shared pointer of pulley
 */
void Pulley::Drive(std::shared_ptr<Pulley> other)
{
    mConnectedPulley = other.get();
    mSource.AddSink(other->GetSink());
}

/**
 * Boolean used to differentiate Machine 1 and Machine 2
 */
void Pulley::SetFlappyBelts()
{
    mFlappyBelts = true;
}



