
#ifndef CARELSDK_GENERALAPP_LED_BLINK_H_
#define CARELSDK_GENERALAPP_LED_BLINK_H_

// Led_Blink任务周期
#define PERIOD_LED_BLINK			((uint32_t)(25))

// led链表元素结构体
struct blink_led_t{
	struct blink_led_t *next;
	uint8_t led_num;			// 编号
	uint8_t led_onoff;			// 控制
	uint8_t led_state;			// 状态
	uint8_t led_period;			// 周期
	uint8_t led_ccnt;			// 当前计数
	uint16_t led_delayoff;		// 延时关闭计数（0xFFFF为不延时）
	uint8_t led_delayoffstate;	// 延时关闭状态
};


// Led_Blink任务句柄
extern EmberEventControl gApp_EventControl;


// 启动Led_Blink任务
// delay:延时启动时间
void startApp_LedBlink(uint32_t delay);


// 停止Led_Blink任务
void stopApp_LedBlink(void);

// led列表添加项
// num:led宏编号
// state:led初始状态
void addList_Led(uint8_t num,uint8_t state);

// led列表启动元素
// period:led闪烁半周期（次/25ms）
void setList_Led(uint8_t num,uint32_t period,uint16_t delay,uint16_t state);

// led列表停止元素
void stopList_Led(uint8_t num,uint8_t state);


#endif /* CARELSDK_GENERALAPP_LED_BLINK_H_ */


