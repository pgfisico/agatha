#ifndef Forklift_H
#define Forklift_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <DigitalInput.h>

class Forklift : public frc::Subsystem
{
    private:
        // It's desirable that everything possible under private except
        // for methods that implement subsystem capabilities
        frc::Spark WinchMotor;
        //The limit switches are plugged in to the NC2 and COM if you are confused asked Judy @ 587 429 2424
        frc::DigitalInput LimitSwitches;


    public:
        Forklift();
        void InitDefaultCommand();
        void ForkliftUp();
        void ForkliftUp(double WinchSpeed);
        void ForkliftDown();
        void ForkliftDown(double WinchSpeed);
};

#endif  // Forklift_H
