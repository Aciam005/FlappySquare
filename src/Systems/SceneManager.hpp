#pragma once

#include <vector>

#include "Renderer.hpp"
#include "Components/SceneData.hpp"

class SceneManager
{
    public:
    /*
        Makes the Scene Manager aware of the scene data
    */
    void PushSceneData(SceneData* data);

    /*
        Loads the scene data so that it will be displayed the next time that "RenderCurrentScene()" is called
    */
    void LoadScene(uint8_t sceneID);

    /*
        Renders current scenes
    */
    void RenderCurrentScene(Renderer* renderer);

    private:
    SceneData* FindSceneWithID(uint8_t id);

    public:

    private:
    std::vector<SceneData*> SceneDataContainer;
    SceneData* m_CurrentSceneData = nullptr;
};

