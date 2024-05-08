/**
 * @file MotionSource.h
 * @author Lance Y.
 *
 * The collection of motion source class
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H

class IMotionSink;

/**
 * The source of motion, used to drive other motion sinks.
 */
class MotionSource
{
private:
    /// Smart pointer connected to Sink
    std::vector<IMotionSink*> mSinks;

public:
    MotionSource() {}

    /// Copy constructor (disabled)
    MotionSource(const MotionSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const MotionSource &) = delete;

    void AddSink(IMotionSink* sink);
    void Rotate(double rotation);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H
