
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
	MODE_DOUBLE = 0,		// ˫��
	MODE_SCENES,			// ����
	MODE_KEY,				// ����
	MODE_CURTAIN,			// ����
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



// λ��ṹ�� λȡֵ
uint8_t _GET_BIT_FROMBITS8(uint8_t index, mulbits8_t *data);

// λ��ṹ�� λ��ֵ
void _SET_BIT_FROMBITS8(uint8_t index, mulbits8_t *data, uint8_t bit);


// ���ݽṹ����:˫��
typedef struct KEYDOUBLE{
	uint8_t boardBtn;			// ����
	uint8_t boardLed;			// ָʾ��
	uint8_t state;				// ״̬
	//uint8_t indicatorMode;		// ģʽ
}keydouble_t;

// ���ݽṹ����:����
typedef struct{
	uint8_t boardBtn;
	uint8_t boardLed;
}scenes_t;

// ���ݽṹ����:����
typedef struct{
	uint8_t boardBtn;
	uint8_t boardLed;
}normalkey_t;

// ���ݽṹ����:����
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
 * ˫�ض˵㶨��
 */
extern keydouble_t kb_1;
extern keydouble_t kb_2;

/**
 * �����˵㶨��
 */
extern scenes_t ks_1;
extern scenes_t ks_2;



// LED����
#define PIN_TO_LED				0
#if PIN_TO_LED
#define LED_DISABLE(a)			halSetLed(a)
#define LED_ENABLE(a)			halClearLed(a)
#else
#define LED_DISABLE(a)			halClearLed(a)
#define LED_ENABLE(a)			halSetLed(a)
#endif

// ���endPointԪ��
// ep.�˵�
// mode.�˵�ģʽ
// data.�˵�����
void addList_EP(uint8_t ep,uint8_t mode,void *data);


// �õ�ep��ӦԪ��ָ��
endPoint_t *_getEndpointIterm(uint8_t ep);

// �õ��˵�����
//
uint8_t _getEndpointCount(void);


// ɾ��Ԫ��
//
void _removeEndpointIterm(endPoint_t *iterm);

// �������ж˵��Ӧ��LED
// mask.[1]���� [0]�ر�
void _ctlIndicatorAllOnOff(uint8_t mask);

// ������LEDָ��ʱ��
// ʱ�䣺time * 25ms
void _ctlIndicatorAllOnDelay(uint16_t time);

#endif /* CARELSDK_COMMON_H_ */
