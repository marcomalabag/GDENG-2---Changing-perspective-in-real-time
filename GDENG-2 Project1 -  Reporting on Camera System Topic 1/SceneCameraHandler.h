#pragma once
#include "Camera.h"
#include "PerspectiveChanger.h"



class SceneCameraHandler
{
public:
	static SceneCameraHandler* getInstance();
	static void initialize();
	static void destroy();

	void update();
	void updateCameraPerspective();

	void addCameraPerspectiveListener(PerspectiveChanger* perspective_changer);

	Matrix4x4 getSceneCameraViewMatrix();
	Matrix4x4 getSceneCameraPerspectiveMatrix();

private:
	SceneCameraHandler();
	~SceneCameraHandler();
	SceneCameraHandler(SceneCameraHandler const&) {};
	SceneCameraHandler& operator=(SceneCameraHandler const&) {};
	static SceneCameraHandler* sharedInstance;

	Camera* sceneCamera;
};

