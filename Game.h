#pragma once

#include <math.h>
#include <vector>
#include <iostream>
#include <graphics.h>
#include <ctime>

#include "Vect2.h"
#include "Vect3.h"
#include "Matrix2.h"
#include "Matrix2.h"
#include "Random.h"

#define	PI 3.1415926535897932384626433f



class Game
{
public:
	Game(int posx, int posy, int width, int height);
	~Game();
	void oc_GameInit();			//游戏初始化
	void oc_GameLoop();			//游戏主循环

	void oc_Update(float dt);	//更新
	void oc_Draw();				//渲染
	void oc_KeyPrco();			//键盘消息处理函数
	void oc_MouseProc();		//鼠标消息处理函数

	void Frame_Begin();			//开始一帧
	void Frame_End();			//结束一帧
	void Lock_FPS(int fps);		//锁定帧数,0表示无限制


	//调试相关
	void Debug_text_output();
	
private:
	HWND oc_hWnd;		//游戏窗口句柄
	int oc_FPS;			//帧数
	clock_t oc_timer;	//计时器
	float dt;			//每帧的时间
	int oc_cxGame;		//游戏窗口宽
	int oc_cyGame;		//游戏窗口高
	int oc_posxGmae;	//游戏窗口位置x
	int oc_posyGame;	//游戏窗口位置y
	bool oc_bPause;		//指示游戏是否暂停
};


class GameEngine
{
	//以后再看
};