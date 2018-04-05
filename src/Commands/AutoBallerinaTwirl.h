#ifndef AutoBallerinaTwirl_H
#define AutoBallerinaTwirl_H

#include <Commands/Command.h>

class AutoBallerinaTwirl : public frc::Command {
public:
	AutoBallerinaTwirl(double angle);
    AutoBallerinaTwirl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool isClockwise;
	double EndingAngle;
	double Twirl;

};

#endif  // AutoBallerinaTwirl_H
