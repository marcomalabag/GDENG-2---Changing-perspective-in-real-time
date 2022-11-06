#include "PerspectiveChangerScreen.h"
#include "IMGUI\imgui.h"
#include "IMGUI\imgui_impl_dx11.h"
#include "IMGUI\imgui_impl_win32.h"

PerspectiveChangerScreen::PerspectiveChangerScreen(PerspectiveChanger* changer): AUIScreen("Perspective Changer")
{
	this->changerPerspective = changer;
	this->height = new float(changerPerspective->getHeight());
	this->width = new float(changerPerspective->getWidth());
	this->m_far = new float(changerPerspective->getFar());
	this->m_near = new float(changerPerspective->getNear());
}

void PerspectiveChangerScreen::drawUI()
{
	static const char* views[] = { "Perspective", "Orthographic"};
	static int currView = 0;

	ImGui::Begin("View Changer Window");
	//ImGui::SetWindowPos(ImVec2(UIManager::WINDOW_WIDTH - 575, 25));
	//ImGui::SetWindowSize(ImVec2(275, 225));

	/*
	ImGui::Text("Mode %s", changerPerspective->getMode().c_str());
	ImGui::Text("Height %f", changerPerspective->getHeight());
	ImGui::Text("Width %f", changerPerspective->getWidth());
	ImGui::Text("Near %f", changerPerspective->getNear());
	ImGui::Text("Far %f", changerPerspective->getFar());
	*/

	ImGui::Combo("View Mode", &currView, views, IM_ARRAYSIZE(views));
	if (currView == 0)
	{
		changerPerspective->changeMode(PerspectiveListener::ViewMode::PERSPECTIVE);
	}
	if (currView == 1)
	{
		changerPerspective->changeMode(PerspectiveListener::ViewMode::ORTHOGRAPHIC);
	}
	ImGui::Text("Width");
	ImGui::PushButtonRepeat(true);
	if (ImGui::Button("-"))
	{
		changerPerspective->changeWidth((* this->width)--);
	}
	ImGui::SameLine();
	if (ImGui::InputFloat("", this->width))
	{
		changerPerspective->changeWidth(*this->width);
	}
	ImGui::SameLine();
	if (ImGui::Button("+"))
	{
		changerPerspective->changeWidth((*this->width)++);
	}
	ImGui::Text("Height");
	if (ImGui::Button("-"))
	{
		changerPerspective->changeHeight((*this->height)--);
	}
	ImGui::SameLine();
	if(ImGui::InputFloat("", this->height))
	{
		
		changerPerspective->changeHeight(*this->height); 
	}
	ImGui::SameLine();
	if (ImGui::Button("+"))
	{
		changerPerspective->changeHeight((*this->height)++);
	}
	ImGui::Text("Near");
	if (ImGui::Button("-"))
	{
		changerPerspective->changeNear((*this->m_near)--);
	}
	ImGui::SameLine();
	if (ImGui::InputFloat("", this->m_near))
	{
		changerPerspective->changeNear(*this->m_near);
	}
	ImGui::SameLine();
	if (ImGui::Button("+"))
	{
		changerPerspective->changeNear((*this->m_near)++);
	}
	ImGui::Text("Far");
	if (ImGui::Button("+"))
	{
		changerPerspective->changeFar((*this->m_far)--);
	}
	ImGui::SameLine();
	if (ImGui::InputFloat("", this->m_far))
	{

		changerPerspective->changeFar(*this->m_far);
	}
	ImGui::SameLine();
	if (ImGui::Button("+"))
	{
		changerPerspective->changeFar((*this->m_far)++);
	}
	ImGui::PopButtonRepeat();
	ImGui::End();
}

PerspectiveChangerScreen::~PerspectiveChangerScreen()
{
}


