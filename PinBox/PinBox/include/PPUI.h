#pragma once
#ifndef _PP_UI_H_
#define _PP_UI_H_
#include <3ds.h>
#include <string>
#include <citro3d.h>
#include "PPGraphics.h"
#include "PPSessionManager.h"
#include "easing.h"
#include "Color.h"

//#define UI_DEBUG 1



typedef std::function<int()> PopupCallback;
typedef std::function<void(void* arg1, void* arg2)> ResultCallback;

typedef struct DialogBoxOverride {
	bool isActivate = false;
	Color TitleBgColor;
	Color TitleTextColor;
};

class PPUI
{

public:
	static u32 getKeyDown();
	static u32 getKeyHold();
	static u32 getKeyUp();
	static circlePosition getLeftCircle();
	static circlePosition getRightCircle();

	static u32 getSleepModeState();

	static void UpdateInput();
	static bool TouchDownOnArea(float x, float y, float w, float h);
	static bool TouchUpOnArea(float x, float y, float w, float h);
	static bool TouchDown();
	static bool TouchMove();
	static bool TouchUp();

	// SCREEN
	static int DrawIdleTopScreen(PPSessionManager *sessionManager);


	static int DrawBtmServerSelectScreen(PPSessionManager *sessionManager);
	static int DrawBtmAddNewServerProfileScreen(PPSessionManager *sessionManager, ResultCallback cancel, ResultCallback ok);

	static int DrawStreamConfigUI(PPSessionManager *sessionManager, ResultCallback cancel, ResultCallback ok);
	static int DrawIdleBottomScreen(PPSessionManager *sessionManager);
	static int DrawBottomScreenUI(PPSessionManager *sessionManager);

	static void InfoBox(PPSessionManager *sessionManager);


	// DIALOG
	static void OverrideDialogTypeWarning();
	static void OverrideDialogTypeInfo();
	static void OverrideDialogTypeSuccess();
	static void OverrideDialogTypeCritical();

	static int DrawDialogKeyboard( ResultCallback cancelCallback, ResultCallback okCallback);
	static int DrawDialogNumberInput( ResultCallback cancelCallback, ResultCallback okCallback);
	static int DrawDialogLoading(const char* title, const char* body, PopupCallback callback);
	static int DrawDialogMessage(PPSessionManager *sessionManager, const char* title, const char* body);
	static int DrawDialogMessage(PPSessionManager *sessionManager, const char* title, const char* body, ResultCallback closeCallback);
	static int DrawDialogMessage(PPSessionManager *sessionManager, const char* title, const char* body, ResultCallback cancelCallback, ResultCallback okCallback);

	static void DrawDialogBox(PPSessionManager *sessionManager);




	// SLIDE
	static float Slide(float x, float y, float w, float h, float val, float min, float max, float step, const char* label);
	
	// CHECKBOX
	static bool ToggleBox(float x, float y, float w, float h, bool value, const char* label);

	// BUTTON
	static bool FlatButton(float x, float y, float w, float h, const char* label);
	static bool FlatDarkButton(float x, float y, float w, float h, const char* label);
	static bool FlatColorButton(float x, float y, float w, float h, const char* label, Color colNormal, Color colActive, Color txtCol);

	static bool RepeatButton(float x, float y, float w, float h, const char* label, Color colNormal, Color colActive, Color txtCol);

	// TEXT
	static int LabelBox(float x, float y, float w, float h, const char* label, Color bgColor, Color txtColor, float scale = 0.5f);
	static int LabelBoxAutoWrap(float x, float y, float w, float h, const char* label, Color bgColor, Color txtColor, float scale = 0.5f);
	static int LabelBoxLeft(float x, float y, float w, float h, const char* label, Color bgColor, Color txtColor, float scale = 0.5f);

	// POPUP
	static bool HasPopup();
	static PopupCallback GetPopup();
	static void ClosePopup();
	static void AddPopup(PopupCallback callback);

};

#endif