#include "stdafx.h"
#include "mainGame.h"

void mainGame::setImages()
{

	//------------------------------------------------------
	//**************옵션창 사용되는 이미지*********************
	//------------------------------------------------------

	//1. OPTION_MAIN
	IMAGEMANAGER->addImage("option_main_background", "//image//ui//option//option_main.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("back", "//image//ui//option//main_back.bmp", 408, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_audio", "//image//ui//option//main_audio.bmp", 486, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_controls", "//image//ui//option//main_controls.bmp", 717, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_game", "//image//ui//option//main_game.bmp", 408, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_video", "//image//ui//option//main_video.bmp", 486, 55, 3, 1, true, RGB(255, 0, 255));
	
	//2. OPTION_CONTROLS
	IMAGEMANAGER->addImage("option_controls_background", "//image//ui//option//option_controls.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_editController", "//image//ui//option//controls_editcontroller.bmp", 1246, 56,3,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_editKeyBoard", "//image//ui//option//controls_editkeyboard.bmp", 1101, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_relicInputType", "//image//ui//option//controls_relicinputtype.bmp", 1332, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_relicInputType_options", "//image//ui//option//controls_relicinputtype_select.bmp", 460, 55, 2, 1, true, RGB(255, 0, 255));

	//3. OPTION_GAME
	IMAGEMANAGER->addImage("option_game_background", "//image//ui//option//option_game.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("game_pauseOnLostFocus", "//image/ui//option//game_pauseonlostfocus.bmp", 1563, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("game_showFeats", "//image//ui//option//game_showfeats.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enable_option", "//image//ui//option//select_enable.bmp", 406, 24, 2, 1, true, RGB(255, 0, 255));

	//4. OPTION_AUDIO
	IMAGEMANAGER->addImage("option_audio_background", "//image//ui//option//option_audio.bmp", 822, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_musicVolume", "//image//ui//option//audio_musicvolume.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_soundVolume", "//image//ui//option//audio_soundvolume.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_setToDefault", "//image//ui//option//audio_settodefault.bmp", 1176, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("audio_progressBar", "//image//ui//option//audio_progressBar.bmp", 155, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("audio_progressValue", "//image//ui//option//audio_progressBar_value.bmp", 9, 21, true, RGB(255, 0, 255));

	//5. OPTION_VIDEO
	IMAGEMANAGER->addImage("option_video_background", "//image//ui//option//option_video.bmp", 823, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_brightness", "//image//ui//option//video_brightness.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_fullScreen", "//image//ui//option//video_fullscreen.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_resulution", "//image//ui//option//video_resulution.bmp", 870, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_screenScale", "//image//ui//option//video_screenscale.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("OnOff", "//image//ui//option//on_off.bmp", 148, 56, 2, 1, true, RGB(255, 0, 255));

	//------------------------------------------------------
	//------------------------------------------------------
}