#pragma once
#include <vector>
#include <iostream>
#include <string>



class PerspectiveListener
{
public:
	enum ViewMode
	{
		PERSPECTIVE,
		ORTHOGRAPHIC
	};

	typedef std::string String;
	PerspectiveListener()
	{
		
	}
	~PerspectiveListener()
	{
		
	}

	virtual void updatePerspective(ViewMode mode, float width, float height, float m_near, float m_far) = 0;
};