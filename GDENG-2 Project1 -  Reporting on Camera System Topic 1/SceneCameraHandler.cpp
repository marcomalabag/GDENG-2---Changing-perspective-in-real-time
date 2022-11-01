#include "SceneCameraHandler.h"
#include "EngineTime.h"

SceneCameraHandler* SceneCameraHandler::sharedInstance = NULL;

SceneCameraHandler::SceneCameraHandler()
{
	this->sceneCamera = new Camera("SceneCamera");
}

SceneCameraHandler* SceneCameraHandler::getInstance()
{
	return sharedInstance;
}

void SceneCameraHandler::initialize()
{
	sharedInstance = new SceneCameraHandler();
	
}

void SceneCameraHandler::destroy()
{
	delete sharedInstance;
}

void SceneCameraHandler::update()
{
	this->sceneCamera->update(EngineTime::getDeltaTime());
}

void SceneCameraHandler::updateCameraPerspective()
{
	this->sceneCamera->updatePerspective(PerspectiveListener::PERSPECTIVE,
		1000.0f, 500.0f, 0.1, 1000.0f);
}

void SceneCameraHandler::addCameraPerspectiveListener(PerspectiveChanger* perspective_changer)
{
	perspective_changer->addListener(this->sceneCamera);
}



Matrix4x4 SceneCameraHandler::getSceneCameraViewMatrix()
{
	return this->sceneCamera->getViewMatrix();
}

Matrix4x4 SceneCameraHandler::getSceneCameraPerspectiveMatrix()
{
	return this->sceneCamera->getPerspectiveMatrix();
}

SceneCameraHandler::~SceneCameraHandler()
{
	delete this->sceneCamera;
}
