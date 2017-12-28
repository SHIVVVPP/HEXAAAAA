#include "stdafx.h"
#include "mainGame.h"

void mainGame::setImages()
{

	//------------------------------------------------------
	//**************옵션창 사용되는 이미지*********************
	//------------------------------------------------------

	//1. OPTION_MAIN
	IMAGEMANAGER->addImage("option_main_background", "/image/UI/OPTION/option_main.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("back", "/image/UI/OPTION/main_back.bmp", 408, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_audio", "/image/UI/OPTION/main_audio.bmp", 486, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_controls", "/image/UI/OPTION/main_controls.bmp", 717, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_game", "/image/UI/OPTION/main_game.bmp", 408, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_video", "/image/UI/OPTION/main_video.bmp", 486, 55, 3, 1, true, RGB(255, 0, 255));
	
	//2. OPTION_CONTROLS
	IMAGEMANAGER->addImage("option_controls_background", "/image/UI/OPTION/option_controls.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_editController", "/image/UI/OPTION/controls_editcontroller.bmp", 1246, 56,3,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_editKeyBoard", "/image/UI/OPTION/controls_editkeyboard.bmp", 1101, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_relicInputType", "/image/UI/OPTION/controls_relicinputtype.bmp", 1332, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_relicInputType_options", "/image/UI/OPTION/controls_relicinputtype_select.bmp", 460, 55, 2, 1, true, RGB(255, 0, 255));

	//3. OPTION_GAME
	IMAGEMANAGER->addImage("option_game_background", "/image/UI/OPTION/option_game.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("game_pauseOnLostFocus", "/image/UI/OPTION/game_pauseonlostfocus.bmp", 1563, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("game_showFeats", "/image/UI/OPTION/game_showfeats.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enable_option", "/image/UI/OPTION/select_enable.bmp", 406, 24, 2, 1, true, RGB(255, 0, 255));

	//4. OPTION_AUDIO
	IMAGEMANAGER->addImage("option_audio_background", "/image/UI/OPTION/option_audio.bmp", 822, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_musicVolume", "/image/UI/OPTION/audio_musicvolume.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_soundVolume", "/image/UI/OPTION/audio_soundvolume.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_setToDefault", "/image/UI/OPTION/audio_settodefault.bmp", 1176, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("audio_progressBar", "/image/UI/OPTION/audio_progressBar.bmp", 155, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("audio_progressValue", "/image/UI/OPTION/audio_progressBar_value.bmp", 9, 21, true, RGB(255, 0, 255));

	//5. OPTION_VIDEO
	IMAGEMANAGER->addImage("option_video_background", "/image/UI/OPTION/option_video.bmp", 823, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_brightness", "/image/UI/OPTION/video_brightness.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_fullScreen", "/image/UI/OPTION/video_fullscreen.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_resulution", "/image/UI/OPTION/video_resulution.bmp", 870, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_screenScale", "/image/UI/OPTION/video_screenscale.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("OnOff", "/image/UI/OPTION/on_off.bmp", 148, 56, 2, 1, true, RGB(255, 0, 255));


	//6. Player
	IMAGEMANAGER->addFrameImage("playerIdle", "character//playerIdle.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerAttack", "character//playerAtk.bmp", 1000, 500, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerDownAttack", "character//playerDownAtk.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerWalk", "character//playerWalk.bmp", 1500, 500, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerHitted", "character//playerHitted.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerClimb", "character//playerLadder.bmp", 250, 750, 1, 3, true, RGB(255, 0, 255));

	//------------------------------------------------------
	//------------------------------------------------------
}