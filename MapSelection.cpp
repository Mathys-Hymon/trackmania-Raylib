#include "MapSelection.h"


Vector2 position = { 500, 500 };

MapSelection::MapSelection(hudManager& HUD, MapManager& mapManager) : HUD(HUD), mapManager(mapManager)
{

}

MapSelection::~MapSelection()
{
}

void MapSelection::Draw()
{
	std::string len = std::to_string(mapTextures.size());
	std::string index = std::to_string(displayIndex + 1) + "/" + len;
	DrawText(index.c_str(), 500 - MeasureText(index.c_str(), 25) / 2, 750, 25, BLACK);


	for (int i = -1; i <= 1; i++)
	{
		if (displayIndex + i < 0) {
			HUD.ShowMaps({ position.x + i * 250, position.y }, 20, mapTextures[mapTextures.size() - 1], mapNames[mapTextures.size() - 1]);
		}
		else if (displayIndex + i >= mapTextures.size()) {
			HUD.ShowMaps({ position.x + i * 250, position.y }, 20, mapTextures[0], mapNames[0]);
		}
		else {
			HUD.ShowMaps({ position.x + i * 250, position.y }, 20, mapTextures[displayIndex + i], mapNames[displayIndex + i]);
		}

	}
}

void MapSelection::Update()
{
	Draw();

	if (HUD.buttonClicked({ 430, 750 }, "<", { 20,30 })) {
		if (displayIndex - 1 < 0) {
			displayIndex = mapTextures.size() - 1;
		}
		else {
			displayIndex -= 1;
		}
	}
	if (HUD.buttonClicked({ 540, 750 }, ">", { 20,30 })) {
		if (displayIndex + 1 >= mapTextures.size()) {
			displayIndex = 0;
		}
		else {
			displayIndex += 1;
		}
	}

	if (IsKeyDown(KEY_ENTER) && mapIndex < 0) {
		mapIndex = displayIndex;
		std::string filePath = "resources/maps/" + mapNames[mapIndex] + ".png";
		Image mapImage = LoadImage(filePath.c_str());

		mapManager.ChooseMap(mapImage);
		UnloadImage(mapImage);
	}
	if (mapIndex >= 0 && delay < 0.5f) {
		delay += GetFrameTime();
	}
	else if (delay > 0.5f) {
		mapIndex = -2;
		HUD.DisplayedScreen(2);
	}
}

void MapSelection::SelectMap()
{
	if (mapIndex == -2) {
		mapIndex = -1;

		for (int i = 0; i < mapTextures.size(); i++) {
			UnloadTexture(mapTextures[i]);
		}

		for (const auto& entry : std::filesystem::directory_iterator("resources/maps/"))
		{
			if (entry.path().extension() == ".png")
			{
				Texture texture = LoadTexture(entry.path().string().c_str());
				mapTextures.push_back(texture);
				mapNames.push_back(entry.path().stem().string());
			}
		}
	}
}

void MapSelection::Unload()
{
	for (int i = 0; i < mapTextures.size(); i++) {
		UnloadTexture(mapTextures[i]);
	}
}
