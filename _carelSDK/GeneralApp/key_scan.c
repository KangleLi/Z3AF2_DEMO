/**********************************************************************
 * 文件		：_carelSDK/GeneralApp/keyscan.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../common.h"

#define KEY_0				BUTTON0
#define KEY_1				BUTTON1
#define PRESSED				BUTTON_PRESSED
#define RELEASED			BUTTON_RELEASED
#define TIM_KEY0PRESSED1	((uint32_t)(20 * 3))		// 3s
#define TIM_KEY0PRESSED2	((uint32_t)(20 * 8))		// 8s


// key0按下
extern void key0Pressed_Callback(void);
// key0一级长按
extern void key0LongPressed1_Callback(void);
// key0二级长按
extern void key0LongPressed2_Callback(void);
// key1按下
extern void key1Pressed_Callback(void);


EmberEventControl gAppKeyScan_EventControl;
void gAppKeyScan_EventFunction(void){
	static uint8_t SEQ_keyscan0 = 0;
	static uint8_t SEQ_keyscan1 = 0;
	static uint32_t CNT_key0Pressed = 0;
	emberEventControlSetInactive(gAppKeyScan_EventControl);

	// 读取按键状态
	uint8_t st_key0 = halButtonPinState(KEY_0);
	uint8_t st_key1 = halButtonPinState(KEY_1);


	/* ---------------key0---------------- */
	switch(SEQ_keyscan0){
	// 判断状态
	case 0:
		if(st_key0 == RELEASED)
			SEQ_keyscan0 = 1;
		else if(st_key0 == PRESSED)
			SEQ_keyscan0 = 2;

		break;

	// 松开状态
	case 1:
		// 发生：按键按下
		if(st_key0 == PRESSED){
			SEQ_keyscan0 = 2;
			CNT_key0Pressed = 0;
			key0Pressed_Callback();
			break;
		}
		break;

	// 按下状态
	case 2:
		// 发生：到达一级长按时间
		if(++CNT_key0Pressed == TIM_KEY0PRESSED1){
			key0LongPressed1_Callback();
		}

		// 发生：到达二级长按时间
		if(CNT_key0Pressed == TIM_KEY0PRESSED2){
			key0LongPressed2_Callback();
		}

		// 发生：松开按键
		if(st_key0 == RELEASED){
			CNT_key0Pressed = 0;
			SEQ_keyscan0 = 1;
			break;
		}
		break;

	default:
		SEQ_keyscan0 = 0;
		CNT_key0Pressed = 0;
		break;
	}


	/* ---------------key1---------------- */
	switch(SEQ_keyscan1){
	// 判断状态
	case 0:
		if(st_key1 == RELEASED)
			SEQ_keyscan1 = 1;
		else if(st_key1 == PRESSED)
			SEQ_keyscan1 = 2;

		break;

	// 松开状态
	case 1:
		// 发生：按键按下
		if(st_key1 == PRESSED){
			SEQ_keyscan1 = 2;
			key1Pressed_Callback();
			break;
		}
		break;

	// 按下状态
	case 2:
		// 发生：松开按键
		if(st_key1 == RELEASED){
			SEQ_keyscan1 = 1;
			break;
		}
		break;

	default:
		SEQ_keyscan1 = 0;
		break;
	}


	emberEventControlSetDelayMS(gAppKeyScan_EventControl,PERIOD_KEY_SCAN);
}


void startApp_Keyscan(uint32_t delay){
	emberEventControlSetDelayMS(gAppKeyScan_EventControl,delay);
}

void stopApp_Keyscan(void){
	emberEventControlSetInactive(gAppKeyScan_EventControl);
}

