#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "PerspectiveChanger.h"
#include "PerspectiveChanger.h"
#include "PerspectiveChanger.h"

typedef std::string String;

class PerspectiveChanger;
class PerspectiveListener
{
public:
	enum ViewMode
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

	typedef std::string String;
	PerspectiveListener();
	~PerspectiveListener();

	virtual void updatePerspective(ViewMode mode, float width, float height, float near, float far);
};