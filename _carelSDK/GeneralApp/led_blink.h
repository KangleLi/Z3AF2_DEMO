
#ifndef CARELSDK_GENERALAPP_LED_BLINK_H_
#define CARELSDK_GENERALAPP_LED_BLINK_H_

// Led_Blink��������
#define PERIOD_LED_BLINK			((uint32_t)(25))

// led����Ԫ�ؽṹ��
struct blink_led_t{
	struct blink_led_t *next;
	uint8_t led_num;			// ���
	uint8_t led_onoff;			// ����
	uint8_t led_state;			// ״̬
	uint8_t led_period;			// ����
	uint8_t led_ccnt;			// ��ǰ����
	uint16_t led_delayoff;		// ��ʱ�رռ�����0xFFFFΪ����ʱ��
	uint8_t led_delayoffstate;	// ��ʱ�ر�״̬
};


// Led_Blink������
extern EmberEventControl gApp_EventControl;


// ����Led_Blink����
// delay:��ʱ����ʱ��
void startApp_LedBlink(uint32_t delay);


// ֹͣLed_Blink����
void stopApp_LedBlink(void);

// led�б������
// num:led����
// state:led��ʼ״̬
void addList_Led(uint8_t num,uint8_t state);

// led�б�����Ԫ��
// period:led��˸�����ڣ���/25ms��
void setList_Led(uint8_t num,uint32_t period,uint16_t delay,uint16_t state);

// led�б�ֹͣԪ��
void stopList_Led(uint8_t num,uint8_t state);


#endif /* CARELSDK_GENERALAPP_LED_BLINK_H_ */


