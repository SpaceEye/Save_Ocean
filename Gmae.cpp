#include "Game.h"

Game::Game(int posx, int posy, int width, int height)
{
	oc_cxGame = width;
	oc_cyGame = height;
	oc_posxGmae = posx;
	oc_posyGame = posy;
}

Game::~Game()
{

}

//��Ϸ��ʼ��
void Game::oc_GameInit()
{		
	initgraph(oc_cxGame, oc_cyGame, SHOWCONSOLE);
	oc_hWnd = GetHWnd();
	SetWindowPos(oc_hWnd, HWND_TOP, oc_posxGmae, oc_posyGame, oc_cxGame, oc_cyGame, SWP_SHOWWINDOW);
	oc_FPS = 0;
	oc_timer = 0;
	dt = 0;
	oc_bPause = false;
}		
void Game::oc_GameLoop()
{
	//��ѭ��
	while (1)
	{
		Frame_Begin();		//��ʼ��ǰ֡
		

		oc_Update(dt);		//���ݸ���
		BeginBatchDraw();	//��ʼ������ͼ
		oc_Draw();			//��Ⱦ
		FlushBatchDraw();	//��ʾ��ǰ֡
		Lock_FPS(120);		//֡������


		Frame_End();		//������ǰ֡
	}
	
}	 
	

void Game::oc_Update(float dt)
{

}

void Game::oc_Draw()
{
	cleardevice();				//����
	Debug_text_output();		//�����������

	circle(200, 500, 100);

}


void Game::oc_KeyPrco()
{

}

void Game::oc_MouseProc()
{

}


clock_t timer_temp;	//֡��������ʱ��ʱ��

void Game::Frame_Begin()	//��ʼһ֡
{
	timer_temp = clock();
}

void Game::Frame_End()		//����һ֡
{
	static int fps_i = 0;	//������̬�����������֡��
	static int fps_t = 0;
	
	dt = clock() - timer_temp;	//����֡���ʱ��dt
	fps_i++;
	oc_timer += dt;
	fps_t += dt;
	if (fps_i == 50)		//�ۻ�10֡�ٽ��м��㣬����ʱ����ܺܶ�
	{
		oc_FPS = 50000.0f / fps_t;
		fps_i = 0;
		fps_t = 0;
	}
}

void Game::Lock_FPS(int fps)
{
	if (fps <= 0)return;
	int t = (1000.0f / fps) - clock() + timer_temp;
	if (t < 0)return;
	Sleep(t);
}


void Game::Debug_text_output()		//�����������
{
	wchar_t output_text[50];
	swprintf(output_text, 50, L"FPS:%d Time:%f", oc_FPS, oc_timer/1000.0f);
	outtextxy(5, 5, output_text);
}