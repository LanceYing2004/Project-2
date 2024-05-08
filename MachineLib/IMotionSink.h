/**
 * @file IMotionSink.h
 * @author Lance Y.
 *
 * Interface class for the motion sink of the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_IMOTIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_IMOTIONSINK_H

class MotionSource;

/**
 * Class used to converge all the motion source into sink, where it
 * use to drive other motion sinks.
 */
class IMotionSink
{

private:
    /// Pointer to MotionSource
    MotionSource* mSource;

public:
    virtual ~IMotionSink() = default;

    /**
     * Set the rotation for the machine
     * @param rotation rotation of the machine
     */
    virtual void Rotate(double rotation) = 0;

    /**
     * Get motion source
     * @return MotionSource pointer
     */
    MotionSource* GetSource() const {return mSource;}

    /**
     * Set motion source
     * @param source Motion source pointer
     */
    void SetSource(MotionSource* source) {mSource = source;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_IMOTIONSINK_H
