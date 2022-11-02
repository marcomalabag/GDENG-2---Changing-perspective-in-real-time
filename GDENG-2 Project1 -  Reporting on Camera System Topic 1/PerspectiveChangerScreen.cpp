#include "PerspectiveChangerScreen.h"
#include "IMGUI\imgui.h"
#include "IMGUI\imgui_impl_dx11.h"
#include "IMGUI\imgui_impl_win32.h"

PerspectiveChangerScreen::PerspectiveChangerScreen(PerspectiveChanger* changer): AUIScreen("Perspective Changer")
{
	this->changerPerspective = changer;
}

void PerspectiveChangerScreen::drawUI()
{
	//float height[3] = { changerPerspective->getHeight(), changerPerspective->getHeight(), changerPerspective->getHeight() };
	ImGui::Begin("Perspective Changer Window");
	ImGui::SetWindowPos(ImVec2(UIManager::WINDOW_WIDTH - 575, 25));
	ImGui::SetWindowSize(ImVec2(250, UIManager::WINDOW_HEIGHT));
	ImGui::Text("Mode %s", changerPerspective->getMode().c_str());
	ImGui::Text("Height %f", changerPerspective->getHeight());
	ImGui::Text("Width %f", changerPerspective->getWidth());
	ImGui::Text("Near %f", changerPerspective->getNear());
	ImGui::Text("Far %f", changerPerspective->getFar());
	ImGui::End();
}

PerspectiveChangerScreen::~PerspectiveChangerScreen()
{
}


