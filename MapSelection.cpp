#include "MapSelection.h"

MapSelection::MapSelection(hudManager& HUD, MapManager mapManager) : HUD(HUD), mapManager(mapManager)
{

}

MapSelection::~MapSelection()
{
}

void MapSelection::Update()
{
	Vector2 position = { 50, 50 };

	for (int i = 0; i < mapTextures.size() -1; i++)
	{
		if (HUD.ShowMaps(position, 20, mapTextures[i], mapNames[i]))
		{
			mapIndex = i;
		}
	}

	if (mapIndex > -1) {

		Image mapImage = LoadImageFromTexture(mapTextures[mapIndex]);

		std::cout << "size : " + mapNames.size() << std::endl;
		mapManager.ChooseMap(mapImage);

		if (delay <= 3.0) {
			delay += GetFrameTime();
		}
		else {
			HUD.DisplayedScreen(2);
			mapIndex = -2;
		}

	}
}

void MapSelection::SelectMap()
{
	if (mapIndex == -2) {
		mapIndex = -1;

		for (const auto& entry : std::filesystem::directory_iterator("resources/maps/"))
		{
			if (entry.path().extension() == ".png")
			{
				Texture2D texture = LoadTexture(entry.path().string().c_str());
				mapTextures.push_back(texture);
				mapNames.push_back(entry.path().stem().string());
			}
		}
	}
}
