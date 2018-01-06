#include "stdafx.h"
#include "mainGame.h"

void mainGame::setImages()
{

	

	//------------------------------------------------------
	//**************플레이어 이미지*********************
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
	//**************아이템 이미지*********************
	//------------------------------------------------------

	//인벤 이미지들.
	IMAGEMANAGER->addImage("cursor", "./image/inventory/invencursor.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("invenOpen", "./image/inventory/inven.bmp", 0,0,5380, 693, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inventory", "./image/inventory/inventory.bmp", 0, 0, 2152, 693, 2, 1, true, RGB(255, 0, 255));

	//아이템 이미지
	IMAGEMANAGER->addImage("firelod", "./image/inventory/firelod.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shovel", "./image/inventory/shovel.bmp", 133, 133, true, RGB(0, 0, 0));
	//마을, NPC 이미지ㅛ    
	IMAGEMANAGER->addImage("town", "./image/town/townimage.bmp", 8137, 900, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tangtangball", "./image/inventory/tangtangball.bmp", 133, 133, true, RGB(0, 0, 0));
	//------------------------------------------------------
	//------------------------------------------------------

	//------------------------------------------------------
	//**************옵션창 사용되는 이미지*********************
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
	//**************아이템 이미지*********************
	//------------------------------------------------------

	//인벤 이미지들.
	IMAGEMANAGER->addImage("cursor", "./image/inventory/invencursor.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("invenOpen", "./image/inventory/inven.bmp", 0,0,5380, 693, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inventory", "./image/inventory/inventory.bmp", 0, 0, 2152, 693, 2, 1, true, RGB(255, 0, 255));

	//아이템 이미지
	IMAGEMANAGER->addImage("firelod", "./image/inventory/firelod.bmp", 133, 133, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shovel", "./image/inventory/shovel.bmp", 133, 133, true, RGB(0, 0, 0));
	//마을, NPC 이미지    
	IMAGEMANAGER->addImage("town", "./image/town/townimage.bmp", 8137, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("townPix", "./image/town/townPiximage.bmp", 8137, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backsideimg", "./image/town/backsidetown.bmp", 8137, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("conversationRect", "./image/town/conversationRect.bmp", 1600, 194, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점", "./image/town/상점UI.bmp", 1600, 384, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택박스", "./image/town/SelectRect.bmp", 121, 120, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("watergirl", "./image/town/waterGalMove.bmp", 0, 0, 426, 360, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bardnomal", "./image/town/바드노말.bmp", 0, 0, 4480, 180, 26, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bardfirst", "./image/town/바드first.bmp", 0, 0, 2890, 185, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bardfun", "./image/town/바드흥겨운음악.bmp", 0, 0, 3497, 185, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("genericKnight", "./image/town/genericKnightNoMove.bmp", 0, 0, 66, 39, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("몰리", "./image/town/몰리.bmp", 0, 0, 307, 372, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("짐든 남자", "./image/town/bagFellaMove.bmp", 0, 0, 427, 360, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("염소", "./image/town/goatician_test.bmp", 6016, 180, 32, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마법사", "./image/town/마법사아가씨믹스.bmp", 7668, 225, 46, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("요리사", "./image/town/음식점주인기쁨.bmp", 797, 300, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("조리중", "./image/town/음식점주인재료손질.bmp", 1030, 225, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("조리중1", "./image/town/음식점주인조리중1.bmp", 4945, 225, 23, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("조리중2-1", "./image/town/음식점주인조리중2-1.bmp", 806, 225, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("조리중2-2", "./image/town/음식점주인조리중2-2.bmp", 1087, 225, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("서빙", "./image/town/음식점주인음식만듬.bmp", 892, 280, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("hedgeFarmer", "./image/town/hedgeFarmer1-1.bmp", 436, 180, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("guard", "./image/town/guard.bmp", 308, 200, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("광대", "./image/town/Merchant.bmp", 339, 150, 2, 1, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("선택안된YES", "./image/town/NotSelectYes.bmp", 107, 43, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("선택안된NO", "./image/town/NotSelectNO.bmp", 75, 36, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("선택BOX", "./image/town/SelectBox.bmp", 130, 61, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("안삼", "./image/town/Done.bmp", 79, 24, true, RGB(0, 0, 0));

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
	//**************UI 이미지*********************
	//------------------------------------------------------
	IMAGEMANAGER->addImage("UI_basic", "./image./UI/ui/main_ui.bmp", 1600, 71, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_worldMap", "./image./UI./ui./worldMap_ui.bmp", 1600, 192, false, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ui_playerHP", "./image/UI/ui/hp_icon.bmp", 102, 34, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("number", "./image/UI/ui/number.bmp", 300, 29, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("number_blue", "./image/UI/ui/number_blue.bmp", 300, 29, 10, 1, true, RGB(255, 0, 255));

	//------------------------------------------------------
	//------------------------------------------------------

	//------------------------------------------------------
	//**************백그라운드 이미지*********************
	//------------------------------------------------------
	
	
	//배경
	IMAGEMANAGER->addImage("back1", "./image./stage./background_1.bmp", 6219, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back2", "./image./stage./background_2.bmp",1600,900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back3","./image./stage./background_3.bmp",1600,900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back4","./image./stage./background_4.bmp",1600,900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back5","./image./stage./background_5.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back6","./image./stage./background_6.bmp",1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back7","./image./stage./background_7.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back8","./image./stage./background_8.bmp", 1600, 1589, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back8_left","./image./stage./background_8_left.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back9","./image./stage./background_9.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back10","./image./stage./background_10.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back11","./image./stage./background_11.bmp", 1600, 3390, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back11_right","./image./stage./background_11_right.bmp", 2303, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back12","./image./stage./background_12.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back13","./image./stage./background_13.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back14","./image./stage./background_14.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back15","./image./stage./background_15.bmp", 1601, 2561, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back15_left","./image./stage./background_15_left.bmp", 1983, 899, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("back16","./image./stage./background_16.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backBoss","./image./stage./background_boss.bmp", 1600, 900, false, RGB(255, 0, 255));

	//pixel collision background
	IMAGEMANAGER->addImage("colBack1", "./image./stage./colbackground_1.bmp", 6219, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack2", "./image./stage./colbackground_2.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack3", "./image./stage./colbackground_3.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack4", "./image./stage./colbackground_4.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack5", "./image./stage./colbackground_5.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack6", "./image./stage./colbackground_6.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack7", "./image./stage./colbackground_7.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack8", "./image./stage./colbackground_8.bmp", 1600, 1589, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack8_left", "./image./stage./colbackground_8_left.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack9", "./image./stage./colbackground_9.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack10", "./image./stage./colbackground_10.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack11", "./image./stage./colbackground_11.bmp", 1600, 3390, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack11_right", "./image./stage./colbackground_11_right.bmp", 2303, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack12", "./image./stage./colbackground_12.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack13", "./image./stage./colbackground_13.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack14", "./image./stage./colbackground_14.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack15", "./image./stage./colbackground_15.bmp", 1601, 2561, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack15_left", "./image./stage./colbackground_15_left.bmp", 1983, 899, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBack16", "./image./stage./colbackground_16.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("colBackBoss", "./image./stage./colbackground_boss.bmp", 1600, 900, false, RGB(255, 0, 255));



	//------------------------------------------------------
	//------------------------------------------------------

	//------------------------------------------------------
	//**************오브젝트 이미지*********************
	//------------------------------------------------------
	IMAGEMANAGER->addFrameImage("파볼", "./image/object/fireball.bmp", 120, 40, 3, 1, true, RGB(255, 0, 255));


	//------------------------------------------------------
	//------------------------------------------------------


	//오브젝트 젬
	IMAGEMANAGER->addImage("bluedia", "./image/object/bigdia.bmp", 60, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("reddia", "./image/object/smalldia.bmp", 48, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bluegem", "./image/object/bluegem.bmp", 32, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greengem", "./image/object/greengem.bmp", 26, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("smalljew", "./image/object/sjewel.bmp", 17, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowgem", "./image/object/yellowgem.bmp", 37, 28, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("skull", "./image/object/skull.bmp", 48, 44, true, RGB(255, 0, 255));
	//픽업 이펙트
	IMAGEMANAGER->addFrameImage("sparkle", "./image/object/pickupSparkle.bmp", 42, 14, 3, 1, true, RGB(255, 0, 255));

	//음식
	IMAGEMANAGER->addImage("chicken", "./image/object/chicken.bmp", 120, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("food", "./image/object/foods.bmp", 120, 75, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("platter", "./image/object/platter.bmp", 138, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("halfedplatter", "./image/object/halfedplatter.bmp", 125, 125, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("halfedplatter2", "./image/object/halfedplatter2.bmp", 90, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bubbles", "./image/object/bubbles.bmp",400 ,100,4, 1, true, RGB(255, 0, 255));
	//광맥
	IMAGEMANAGER->addFrameImage("dirtpile", "./image/object/dirtpile.bmp", 660, 60, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("digclod1", "./image/object/digclod1.bmp", 40, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("digclod2", "./image/object/digclod2.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bubbleeffect", "./image/object/bubbleeffect.bmp", 200, 100, 2, 1, true, RGB(255, 0, 255));
	//블록
	IMAGEMANAGER->addImage("dirtblock", "./image/object/dirtblock.bmp", 128, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("dirtblocksmall", "./image/object/dirtblock_small.bmp", 58, 58, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dirtblockeffect", "./image/object/dirtblock_effect.bmp", 540, 148, 3,1,true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("dirtblockeffect2", "./image/object/dirtblock_small_effect.bmp", 320, 72, 3,1,true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("movingrock", "./image/object/moving_block.bmp", 192, 64, true, RGB(255, 0, 255));
	//부서지는 지형
	IMAGEMANAGER->addImage("leftfakehead", "./image/object/fakehead_left.bmp",66, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("rightfakehead", "./image/object/fakehead_right.bmp", 66, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("leftfakeline", "./image/object/fakeline_left.bmp", 64, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("rightfakeline", "./image/object/fakeline_right.bmp", 64, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("leftfaketail", "./image/object/faketail_left.bmp", 64, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("rightfaketail", "./image/object/faketail_right.bmp", 64, 192, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ladder", "./image/object/ladder.bmp", 72, 461, true, RGB(255, 0, 255));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////에너미 이미지

	IMAGEMANAGER->addFrameImage("슬라임", "슬라임.bmp",
		200, 272,
		4, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("레드비틀", "레드비틀.bmp",
		260, 160,
		4, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("노란용", "노란드래곤2.bmp",
		5790, 990,
		12, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("초록용", "초록색용.bmp",
		277, 639,
		3, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("해골", "스켈레톤완성.bmp",
		580, 3060,
		4, 24, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("버블", "비눗방울완성.bmp",
		925, 438,
		4, 2, true, RGB(255, 0, 255));

	//IMAGEMANAGER->addFrameImage("해골", "스켈레톤.bmp",
	//	580, 3060,
	//	4, 24, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스", "검은삽기사.bmp",
		1500, 11125,
		6, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("임시배경", "임시배경입니다.bmp", 1280, 720, true, RGB(255, 0, 255));




	////////////////////////////////////////////////////////////////////////////////////////////////////////////


}
	