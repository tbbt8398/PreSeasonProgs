#pragma config(Sensor, S3,     ultra,          sensorSONAR)
#pragma config(Motor,  motorA,          A,             tmotorNXT, PIDControl, encoder)

task main()
{
	int angle = 0;
	bool rotSwitch = true;
	float radius;
	float xPoints[100];
	float yPoints[100];

	eraseDisplay();
	nxtDrawCircle(0,63,62);
	nMotorEncoder[motorA] = 0;
	while(true)
	{
		radius = SensorValue[ultra]/ (float)255;
		radius *= (float)30;
		angle = nMotorEncoder[motorA];

		float Xposition = 31 + radius * cosDegrees(nMotorEncoder[motorA] + (float)90);
		float Yposition = 31 +  radius * sinDegrees(nMotorEncoder[motorA] + (float)90);
		for (int c = 99; c>0; c--)
		{
			xPoints[c] = xPoints[c-1];
			yPoints[c] = yPoints[c-1];
		}
			xPoints[0] = Xposition;
			yPoints[0] = Yposition;

		if (angle >= 90 && rotSwitch == true)
		{
			rotSwitch = false;
		}
		else if (angle <= -90 && rotSwitch == false)
		{
			rotSwitch = true;
			eraseDisplay();
			for (int c = 0; c <= 99; c++)
			{
				nxtSetPixel(xPoints[c],yPoints[c]);
			}
			nxtFillRect(30,30,32,32);
			nxtDrawCircle(0,63,62);
			memset(xPoints, 0, 100);
			memset(yPoints, 0, 100);
		}

		if (rotSwitch == true)
		{
			motor[motorA] = 17;
			//nMotorEncoderTarget[motorA] += 5;
		}
		else
		{
			motor[motorA] = -17;
			//nMotorEncoderTarget[motorA] -= 5;
		}
		//while(nMotorRunState[motorA] != runStateIdle)
		//{

		//}
	}
}
