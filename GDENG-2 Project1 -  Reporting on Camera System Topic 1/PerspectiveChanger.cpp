#include "PerspectiveChanger.h"

PerspectiveChanger::PerspectiveChanger(float width, float height, float near, float far)
{
	this->currentMode = PerspectiveListener::PERSPECTIVE;
	this->width = width;
	this->height = height;
	this->Near = near;
	this->Far = far;
}

void PerspectiveChanger::addListener(PerspectiveListener* listener)
{
	this->list.push_back(listener);
}

void PerspectiveChanger::removeListener(PerspectiveListener* listener)
{
	int index = -1;
	for(int i = 0; i < this->list.size(); i++)
	{
		if(this->list[i] == listener)
		{
			index = i;
			this->list.erase(this->list.begin() + index);
			break;
		}
	}
}

void PerspectiveChanger::CallUpdatePerspective(PerspectiveListener::ViewMode mode, float width, float height, float near, float far)
{
	for(int i = 0; i < list.size(); i++)
	{
		list[i]->updatePerspective(mode, width, height, near, far);
	}
}

void PerspectiveChanger::changeMode(PerspectiveListener::ViewMode mode)
{
	this->currentMode = mode;
	this->CallUpdatePerspective(mode, width, height, Near, Far);

}

void PerspectiveChanger::changeWidth(float width)
{
	this->width = width;
	this->CallUpdatePerspective(currentMode, this->width, height, Near, Far);
}

void PerspectiveChanger::changeHeight(float Height)
{
	this->height = Height;
	this->CallUpdatePerspective(currentMode, width, height, Near, Far);
}

void PerspectiveChanger::changeNear(float Near)
{
	this->Near = Near;
	this->CallUpdatePerspective(currentMode, width, height, this->Near, Far);
}

void PerspectiveChanger::changeFar(float Far)
{
	this->Far = Far;
	this->CallUpdatePerspective(currentMode, width, height, this->Near, Far);
}

PerspectiveChanger::~PerspectiveChanger()
{
}
