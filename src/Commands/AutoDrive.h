#ifndef Drive_H
#define Drive_H

#include <Commands/Command.h>

class AutoDrive : public frc::Command {
public:
	AutoDrive(double distress);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double distress;

};



#endif  // Drive_H
