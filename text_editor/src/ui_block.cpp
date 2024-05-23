#include "ui_block.h"
#include "ui_face.h"
#include <fox_math.h>

bool ui_block::click_check(float x, float y)
{
	if (check_aabb_overlap(vec2(x, y), corners[0], corners[3]))
	{

	}
	return false;
}
