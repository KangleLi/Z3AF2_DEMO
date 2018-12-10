/***
 * 文件		：_carelSDK/Z3_Extend/mainCallback.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../common.h"
#include<stdlib.h>


// LED结构链表
LIST(blink_leds);



// LED显示处理任务主体
EmberEventControl gAppLedBlink_EventControl;
void gAppLedBlink_EventFunction(void){
	struct blink_led_t *ledItem;
	emberEventControlSetInactive(gAppLedBlink_EventControl);

	if(*blink_leds != NULL){
		for(ledItem = *blink_leds;;ledItem = ledItem->next){
			if((ledItem->led_onoff > 0) && (ledItem->led_period > 0)){
				if(ledItem->led_ccnt == 0)
					ledItem->led_ccnt = 1;
				if(--(ledItem->led_ccnt) == 0){
					ledItem->led_ccnt = ledItem->led_period;
					if(ledItem->led_state == 0){
						ledItem->led_state = 1;
						halSetLed(ledItem->led_num);
					}
					else{
						ledItem->led_state = 0;
						halClearLed(ledItem->led_num);
					}
					if(ledItem->led_delayoff != 0xFFFF){
						if(ledItem->led_delayoff <= 1)
							stopList_Led(ledItem->led_num,ledItem->led_delayoffstate);
						else
							ledItem->led_delayoff --;
					}
				}
			}

			if(ledItem->next == NULL){
				break;
			}
		}
	}
	else{
		//emberAfCorePrintln("NULL");
	}

	emberEventControlSetDelayMS(gAppLedBlink_EventControl,PERIOD_LED_BLINK);
}





// 初始化LED链表
// 添加LED元素并配置初始值
// 延时启动LED任务
void startApp_LedBlink(uint32_t delay){
	// 初始化led链表
	list_init(blink_leds);
/*
	*********************************************************
	* 						添加led元素						*
	*********************************************************
 */
	//addList_Led(BOARDLED0,0);
	addList_Led(BOARDLED1,0);


	emberEventControlSetDelayMS(gAppLedBlink_EventControl,delay);
}



// 停止LED任务
void stopApp_LedBlink(void){
	emberEventControlSetInactive(gAppLedBlink_EventControl);
}



// led列表添加元素
void addList_Led(uint8_t num,uint8_t state){
	struct blink_led_t *itermLed = malloc(sizeof(struct blink_led_t));

	itermLed->led_num = num;
	itermLed->led_period = 0;
	itermLed->led_ccnt = 0;
	itermLed->led_onoff = 0;
	if(state){
		halSetLed(num);
		itermLed->led_state = 1;
	}
	else{
		halClearLed(num);
		itermLed->led_state = 0;
	}

	list_add(blink_leds,itermLed);
}



// led列表启动元素
void setList_Led(uint8_t num,uint32_t period,uint16_t delay,uint16_t state){
	struct blink_led_t *ledItem;
	if(*blink_leds == NULL){
		return;
	}
	for(ledItem = *blink_leds;;ledItem = ledItem->next){
		if(ledItem->led_num == num){
			ledItem->led_onoff = 1;
			ledItem->led_period = period;
			ledItem->led_ccnt = period;
			ledItem->led_delayoff = delay;
			ledItem->led_delayoffstate = state;
			ledItem->led_state = 1;
			LED_ENABLE(num);
			break;
		}
		if(ledItem->next == NULL)
			break;
	}
}



// led列表停止元素
void stopList_Led(uint8_t num,uint8_t state){
	DEBUG(":::ts: -------stop Led!");
	struct blink_led_t *ledItem;
	if(*blink_leds == NULL){
		return;
	}
	for(ledItem = *blink_leds;;ledItem = ledItem->next){
		if(ledItem->led_num == num){
			ledItem->led_onoff = 0;
			ledItem->led_period = 0;
			ledItem->led_ccnt = 0;
			if(state)
				halSetLed(ledItem->led_num);
			else
				halClearLed(ledItem->led_num);
			break;
		}
		if(ledItem->next == NULL)
			break;
	}
}
