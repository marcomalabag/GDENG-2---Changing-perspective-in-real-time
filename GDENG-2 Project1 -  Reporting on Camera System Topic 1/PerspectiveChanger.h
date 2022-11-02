#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "PerspectiveListener.h"

using namespace std;

typedef std::string String;
typedef std::vector<PerspectiveListener*> Listeners;


class PerspectiveChanger
{
public:

	PerspectiveChanger(float width, float height, float near, float far);
	void addListener(PerspectiveListener* listener);
	void removeListener(PerspectiveListener* listener);
	void CallUpdatePerspective(PerspectiveListener::ViewMode mode, float width, float height, float near, float far);
	void changeMode(PerspectiveListener::ViewMode Mode);
	void changeWidth(float width);
	void changeHeight(float Height);
	void changeNear(float Near);
	void changeFar(float Far);
	string getMode();
	float getWidth();
	float getHeight();
	float getNear();
	float getFar();
	~PerspectiveChanger();

private:
	PerspectiveListener::ViewMode currentMode;
	float width, height, Near, Far;
	Listeners list;
};

