#pragma once
class GAME
{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//シーン
public:
	enum SCENE_ID {
		TITLE_ID,
		SELECT_ID,
		STAGE01_ID,
		STAGE02_ID,
		RESULT_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);
private:
	class BACK* Back;
	class PLAYER* Player;
public:
	void draw();
	class BACK* back() { return Back; }
	class PLAYER* player() { return Player; }

public:
	GAME();
	~GAME();
	void run();
};