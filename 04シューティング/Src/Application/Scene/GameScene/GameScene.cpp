﻿#include "GameScene.h"

#include"../SceneManager.h"
#include "../../main.h"
#include "../../GameObject/Camera/FPSCamera/FPSCamera.h"
#include "../../GameObject/Terrains/Terrain/Terrain.h"
#include "../../GameObject/Character/Player/Player.h"
#include "../../GameObject/Terrains/WoodenBox/WoodenBox.h"

void GameScene::Event()
{
}

void GameScene::Init()
{
	ShowCursor(false);

	std::shared_ptr<Player> player = std::make_shared<Player>();
	player->Init();
	AddObject(player);

	std::shared_ptr<Terrain> terrain = std::make_shared<Terrain>();
	terrain->SetScale(3);
	terrain->Init();
	AddObject(terrain);

	std::shared_ptr<WoddenBox> box;
	for (int i = 0; i < 5; i++)
	{
		box = std::make_shared<WoddenBox>();
		box->SetPos({-60.0f + i * 30.0f, 0.0f, 50.0f});
		box->SetScale(10);
		box->Init();
		AddObject(box);
	}

	std::shared_ptr<FPSCamera> camera = std::make_shared<FPSCamera>();
	camera->Init();
	AddObject(camera);

	//player->SetCamera(camera);
	camera->SetTarget(player);
}
