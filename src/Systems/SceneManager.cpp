#include "SceneManager.hpp"

void SceneManager::PushSceneData(SceneData *data)
{
    SceneDataContainer.push_back(data);
}

void SceneManager::LoadScene(uint8_t sceneID)
{
    SceneData* data = FindSceneWithID(sceneID);

    if(data != nullptr)
    {
        m_CurrentSceneData = data;
    }else
    {
        //Throw error
        Serial.print("ERROR : INVALID SCENE ID :(");
        m_CurrentSceneData = nullptr;
    }
}

void SceneManager::RenderCurrentScene(Renderer* renderer)
{
    if(m_CurrentSceneData != nullptr)
    {
        if(m_CurrentSceneData->Text != nullptr)
        {
            for(int i = 0;i < m_CurrentSceneData->TextLineCount;i++)
            {
                renderer->PushText(m_CurrentSceneData->Text[i]);
            }
        }

        if(m_CurrentSceneData->Sprites != nullptr)
        {
            for(int i = 0;i < m_CurrentSceneData->SpriteCount;i++)
            {
                renderer->PushSprite((m_CurrentSceneData->Sprites + i));
            }
        }

        renderer -> Render();
    }else
    {
        //Throw error
        Serial.print("ERROR : INVALID SCENE ID :(");
    }

}

SceneData *SceneManager::FindSceneWithID(uint8_t id)
{
    for(auto d : SceneDataContainer)
    {
        if(d->ID == id)
            return d;
    }

    return nullptr;
}
