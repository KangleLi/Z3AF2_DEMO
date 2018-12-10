
#ifndef CARELSDK_COMMON_H_
#define CARELSDK_COMMON_H_

#include "./CLib/List/list.h"
#include "app/framework/include/af.h"

#include "./Z3_Extend/Ext_Bind.h"
#include "./Z3_Extend/Ext_GroupScene.h"


#include "./GeneralApp/led_blink.h"
#include "./GeneralApp/key_scan.h"
#include "./Project/keyDouble/networkHandle.h"
#include "./Project/keyDouble/keyDouble.h"

#define DEBUG			emberAfCorePrintln


enum {
	MODE_DOUBLE = 0,		// 双控
	MODE_SCENES,			// 场景
	MODE_KEY,				// 开关
	MODE_CURTAIN,			// 窗帘
};


typedef struct{
	uint8_t bit_0:1;
	uint8_t bit_1:1;
	uint8_t bit_2:1;
	uint8_t bit_3:1;
	uint8_t bit_4:1;
	uint8_t bit_5:1;
	uint8_t bit_6:1;
	uint8_t bit_7:1;
}bits8_t;

typedef union{
	uint8_t type_uint8;
	bits8_t type_bits8;
}mulbits8_t;



// 位域结构体 位取值
uint8_t _GET_BIT_FROMBITS8(uint8_t index, mulbits8_t *data);

// 位域结构体 位赋值
void _SET_BIT_FROMBITS8(uint8_t index, mulbits8_t *data, uint8_t bit);


// 数据结构定义:双控
typedef struct KEYDOUBLE{
	uint8_t boardBtn;			// 按键
	uint8_t boardLed;			// 指示灯
	uint8_t state;				// 状态
	//uint8_t indicatorMode;		// 模式
}keydouble_t;

// 数据结构定义:场景
typedef struct{
	uint8_t boardBtn;
	uint8_t boardLed;
}scenes_t;

// 数据结构定义:开关
typedef struct{
	uint8_t boardBtn;
	uint8_t boardLed;
}normalkey_t;

// 数据结构定义:窗帘
typedef struct{
	uint8_t boardBtn;
	uint8_t boardLed_up;
	uint8_t boardLed_down;
}curtain_t;

typedef struct ENDPOINT {
	struct ENDPOINT *next;
	uint8_t endPoint;
	uint8_t mode;
	union {
		keydouble_t data_keydouble;
		scenes_t data_sccenes;
		normalkey_t data_key;
		curtain_t data_curtain;
	}data;
} endPoint_t;





extern bool startup;

/**
 * 双控端点定义
 */
extern keydouble_t kb_1;
extern keydouble_t kb_2;

/**
 * 场景端点定义
 */
extern scenes_t ks_1;
extern scenes_t ks_2;



// LED控制
#define PIN_TO_LED				0
#if PIN_TO_LED
#define LED_DISABLE(a)			halSetLed(a)
#define LED_ENABLE(a)			halClearLed(a)
#else
#define LED_DISABLE(a)			halClearLed(a)
#define LED_ENABLE(a)			halSetLed(a)
#endif

// 添加endPoint元素
// ep.端点
// mode.端点模式
// data.端点配置
void addList_EP(uint8_t ep,uint8_t mode,void *data);


// 得到ep对应元素指针
endPoint_t *_getEndpointIterm(uint8_t ep);

// 得到端点数量
//
uint8_t _getEndpointCount(void);


// 删除元素
//
void _removeEndpointIterm(endPoint_t *iterm);

// 开关所有端点对应的LED
// mask.[1]开启 [0]关闭
void _ctlIndicatorAllOnOff(uint8_t mask);

// 开所有LED指定时间
// 时间：time * 25ms
void _ctlIndicatorAllOnDelay(uint16_t time);

#endif /* CARELSDK_COMMON_H_ */
