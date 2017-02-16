#pragma once

float Approach(float goalL, float currentL, float dt)
{
	float Ldifference = goalL - currentL;
	if (Ldifference > dt)
		return currentL + dt;
	if (Ldifference < -dt)
		return currentL - dt;

	return goalL;
}
