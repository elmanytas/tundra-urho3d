// For conditions of distribution and use, see copyright notice in LICENSE

#include "StableHeaders.h"
#include "Win.h"
#include "ECEditor.h"
#include "Framework.h"
#include "SceneStructureWindow.h"
#include "ECEditorWindow.h"

#include "SceneAPI.h"
#include "Scene.h"

#include "LoggingFunctions.h"

#include <Urho3D/UI/UIElement.h>

namespace Tundra
{
ECEditor::ECEditor(Framework* owner) :
    IModule("LoginScreen", owner)
{
    
}

ECEditor::~ECEditor()
{
    entityEditor_.Reset();
    sceneEditor_.Reset();
}

void ECEditor::Initialize()
{
    entityEditor_ = new ECEditorWindow(GetFramework());
    entityEditor_->Hide();
    sceneEditor_ = new SceneStructureWindow(GetFramework(), this);
    framework->Scene()->SceneCreated.Connect(this, &ECEditor::OnSceneCreated);
}

void ECEditor::OpenSceneEditor()
{
    SceneMap scenes = GetFramework()->Scene()->Scenes();
    if (scenes.Values().Size() > 0)
        sceneEditor_->SetShownScene(scenes.Values()[0]);
}

void ECEditor::OpenSceneEditor(Scene *scene)
{
    sceneEditor_->SetShownScene(scene);
}

void ECEditor::OpenEntityEditor(Entity *entity)
{
    entityEditor_->AddEntity(entity->Id(), true);
    entityEditor_->Widget()->BringToFront();
    entityEditor_->Widget()->SetPosition(IntVector2(300, 0));
    entityEditor_->Show();
}

void ECEditor::OnSceneCreated(Scene *scene, AttributeChange::Type /*type*/)
{
    OpenSceneEditor(scene);
}
}

extern "C"
{

    DLLEXPORT void TundraPluginMain(Tundra::Framework *fw)
    {
        fw->RegisterModule(new Tundra::ECEditor(fw));
    }

}