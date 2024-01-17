#include "road.h"

/*************************Ò»°ãµÀÂ·************************/
RoadNormal::RoadNormal(const double& r_width)
{
	Rwidth = r_width;
	left_boundary = SCREEN_WIDTH / 2.0 - Rwidth;
	right_boundary = SCREEN_WIDTH / 2.0 + Rwidth;
}

void RoadNormal::showRoad()
{
	setlinestyle(PS_SOLID, 4);
	setlinecolor(BLACK);
	line(left_boundary, 0.0, left_boundary, SCREEN_HEIGHT);
	line(right_boundary, 0.0, right_boundary, SCREEN_HEIGHT);
}