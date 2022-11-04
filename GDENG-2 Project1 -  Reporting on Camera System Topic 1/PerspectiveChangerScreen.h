#pragma once
#include "AUIScreen.h"
#include "PerspectiveChanger.h"
#include "UIManager.h"
#include <string>

using namespace std;
typedef std::string String;

class PerspectiveChangerScreen: public AUIScreen
{
public:
	PerspectiveChangerScreen(PerspectiveChanger* changer);
	void drawUI() override;
	~PerspectiveChangerScreen();

private:
	PerspectiveChanger* changerPerspective;
	float* height;
	float* width;
	float* m_near;
	float* m_far;


};

