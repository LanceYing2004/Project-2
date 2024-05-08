/**
 * @file MotionSource.cpp
 * @author Lance Y.
 */

#include "pch.h"
#include "MotionSource.h"
#include "IMotionSink.h"

/**
 * Add sink to the motion source
 * @param sink component in motion sink
 */
void MotionSource::AddSink(IMotionSink* sink){
    mSinks.push_back(sink);
    sink->SetSource(this);
}

/**
 * Function that drives the other motion sink component to rotate
 * @param rotation rotation of component, double
 */
void MotionSource::Rotate(double rotation) {
    for (auto sink : mSinks)
    {
        sink->Rotate(rotation);
    }
}

