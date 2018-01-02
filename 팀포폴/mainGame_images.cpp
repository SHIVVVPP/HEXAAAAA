#include "stdafx.h"
#include "mainGame.h"

void mainGame::setImages()
{

	

	//------------------------------------------------------
	//**************�÷��̾� �̹���*********************
	//------------------------------------------------------
	//6. Player
	IMAGEMANAGER->addFrameImage("playerWalk", "./image/character/playerWalk.bmp", 1500, 500, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerClimb", "./image/character/playerLadder.bmp", 250, 750, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerIdle", "./image/character/playerIdle.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerHitted", "./image/character/playerHitted.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerDownAtk", "./image/character/playerDownAtk.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerAtk", "./image/character/playerAtk.bmp", 1000, 500, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerJump", "./image/character/playerJump.bmp", 500, 500, 2, 2, true, RGB(255, 0, 255));

	//------------------------------------------------------
	//**************������ �̹���*********************
	//------------------------------------------------------

	//�κ� �̹�����.
	IMAGEMANAGER->addImage("cursor", "./image/inventory/invencursor.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("invenOpen", "./image/inventory/inven.bmp", 0,0,5380, 693, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inventory", "./image/inventory/inventory.bmp", 0, 0, 2152, 693, 2, 1, true, RGB(255, 0, 255));

	//������ �̹���
	IMAGEMANAGER->addImage("firelod", "./image/inventory/firelod.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shovel", "./image/inventory/shovel.bmp", 133, 133, true, RGB(0, 0, 0));
	//����, NPC �̹�����    
	IMAGEMANAGER->addImage("town", "./image/town/townimage.bmp", 8137, 900, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tangtangball", "./image/inventory/tangtangball.bmp", 133, 133, true, RGB(0, 0, 0));
	//------------------------------------------------------
	//------------------------------------------------------

	//------------------------------------------------------
	//**************�ɼ�â ���Ǵ� �̹���*********************
	//------------------------------------------------------

	//1. OPTION_MAIN
	IMAGEMANAGER->addImage("option_main_background", "./image/UI/OPTION/option_main.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("back", "./image/UI/OPTION/main_back.bmp", 408, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_audio", "./image/UI/OPTION/main_audio.bmp", 486, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_controls", "./image/UI/OPTION/main_controls.bmp", 717, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_game", "./image/UI/OPTION/main_game.bmp", 408, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("main_video", "./image/UI/OPTION/main_video.bmp", 486, 55, 3, 1, true, RGB(255, 0, 255));

	//2. OPTION_CONTROLS
	IMAGEMANAGER->addImage("option_controls_background", "./image/UI/OPTION/option_controls.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_editController", "./image/UI/OPTION/controls_editcontroller.bmp", 1246, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_editKeyBoard", "./image/UI/OPTION/controls_editkeyboard.bmp", 1101, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_relicInputType", "./image/UI/OPTION/controls_relicinputtype.bmp", 1332, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("controls_relicInputType_options", "./image/UI/OPTION/controls_relicinputtype_select.bmp", 460, 55, 2, 1, true, RGB(255, 0, 255));

	//3. OPTION_GAME
	IMAGEMANAGER->addImage("option_game_background", "./image/UI/OPTION/option_game.bmp", 821, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("game_pauseOnLostFocus", "./image/UI/OPTION/game_pauseonlostfocus.bmp", 1563, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("game_showFeats", "./image/UI/OPTION/game_showfeats.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enable_option", "./image/UI/OPTION/select_enable.bmp", 406, 24, 2, 1, true, RGB(255, 0, 255));

	//4. OPTION_AUDIO
	IMAGEMANAGER->addImage("option_audio_background", "./image/UI/OPTION/option_audio.bmp", 822, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_musicVolume", "./image/UI/OPTION/audio_musicvolume.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_soundVolume", "./image/UI/OPTION/audio_soundvolume.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("audio_setToDefault", "./image/UI/OPTION/audio_settodefault.bmp", 1176, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("audio_progressBar", "./image/UI/OPTION/audio_progressBar.bmp", 155, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("audio_progressValue", "./image/UI/OPTION/audio_progressBar_value.bmp", 9, 21, true, RGB(255, 0, 255));

	//5. OPTION_VIDEO
	IMAGEMANAGER->addImage("option_video_background", "./image/UI/OPTION/option_video.bmp", 823, 514, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_brightness", "./image/UI/OPTION/video_brightness.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_fullScreen", "./image/UI/OPTION/video_fullscreen.bmp", 870, 56, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_resulution", "./image/UI/OPTION/video_resulution.bmp", 870, 55, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("video_screenScale", "./image/UI/OPTION/video_screenscale.bmp", 1023, 56, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("OnOff", "./image/UI/OPTION/on_off.bmp", 148, 56, 2, 1, true, RGB(255, 0, 255));

	

	//------------------------------------------------------
	//**************������ �̹���*********************
	//------------------------------------------------------

	//�κ� �̹�����.
	IMAGEMANAGER->addImage("cursor", "./image/inventory/invencursor.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("invenOpen", "./image/inventory/inven.bmp", 0,0,5380, 693, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inventory", "./image/inventory/inventory.bmp", 0, 0, 2152, 693, 2, 1, true, RGB(255, 0, 255));

	//������ �̹���
	IMAGEMANAGER->addImage("firelod", "./image/inventory/firelod.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shovel", "./image/inventory/shovel.bmp", 133, 133, true, RGB(0, 0, 0));
	//����, NPC �̹�����    
	IMAGEMANAGER->addImage("town", "./image/town/townimage.bmp", 8137, 900, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tangtangball", "./image/inventory/tangtangball.bmp", 133, 133, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("fishingrod", "./image/inventory/fishingrod.bmp", 133, 133, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("healthcap", "./image/inventory/healthcap.bmp", 133, 133, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("invenMusicSheet", "./image/inventory/invenmusicsheet.bmp", 133, 133, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("invenMealTickets", "./image/inventory/mealtickets.bmp", 133, 133, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("armor", "./image/inventory/shovelarmor.bmp", 133, 133, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("potion", "./image/inventory/potion.bmp", 38, 46, true, RGB(255, 0, 255));
	//------------------------------------------------------
	//------------------------------------------------------

	//------------------------------------------------------
	//**************UI �̹���*********************
	//------------------------------------------------------
	IMAGEMANAGER->addImage("UI_basic", "./image./UI/ui/main_ui.bmp", 1600, 71, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_worldMap", "./image./UI./ui./worldMap_ui.bmp", 1600, 192, false, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ui_playerHP", "./image/UI/ui/hp_icon.bmp", 102, 34, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("number", "./image/UI/ui/number.bmp", 300, 29, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("number_blue", "./image/UI/ui/number_blue.bmp", 300, 29, 10, 1, true, RGB(255, 0, 255));

	//------------------------------------------------------
	//------------------------------------------------------


}
	