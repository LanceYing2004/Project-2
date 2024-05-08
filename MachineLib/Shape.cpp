/**
 * @file Shape.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "Shape.h"

Shape::Shape()
{

}

/**
 * Draw the shape to the program
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, GetPosition().x, GetPosition().y);
}

/**
 * Set the rotation value of the shape
 * @param rotation rotation value
 */
void Shape::Rotate(double rotation)
{
    SetRotation(rotation);
}


