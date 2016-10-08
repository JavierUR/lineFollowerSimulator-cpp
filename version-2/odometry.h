class Pose
{
public:
	Pose();
	void odometryUpdate(int leftPower, int rightPower, int timestep);
	void writeOut( void );
	// Measured in cm, with positive being forward of the starting position
	double distAlong;
	// Measured in degrees, with positive being nose left.
	double angleFrom;
};

Pose::Pose() {
	distAlong = 0;
	angleFrom = 0;
}

void Pose::writeOut( void ) {
	Serial.print("(d, theta) = (");
	Serial.print(distAlong);
	Serial.print(", ");
	Serial.print(angleFrom);
	Serial.print(")");
}

const double MAX_FORWARD_SPEED = 100;
const double MAX_TURN_SPEED = 500;

// Update the estimated pose of the robot based on wheel (estimated) odometry.
void Pose::odometryUpdate( int leftPower, int rightPower, int timestep) {
	double forwardSpeed = (leftPower + rightPower) / 2 * MAX_FORWARD_SPEED / 255.0;
	double turnSpeed = (rightPower - leftPower) / 2 * MAX_TURN_SPEED / 255.0;

	distAlong += forwardSpeed * timestep / 1000.0;
	angleFrom += turnSpeed * timestep / 1000.0;
}