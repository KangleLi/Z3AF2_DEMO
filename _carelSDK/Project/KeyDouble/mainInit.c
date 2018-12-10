/**********************************************************************
 * �ļ�		��_carelSDK/Project/KeyDouble/mainInit.c
 * ����		��
 * ��������	��2018/11/15
 * �����		��Carel.Li
 * �޸�����	��
 * �޸�����	��
 * �汾		��v1.0
 */
#include "../../common.h"



extern EmberEventControl mainInit_EventControl;
void mainInit_Start(void){

	//addList_EP(1,MODE_SCENES,&ks_1);
	addList_EP(1,MODE_SCENES,&ks_2);

	DEBUG(":::�˵�������%d",_getEndpointCount());

	// ����LED����
	startApp_LedBlink(1);

	// LED����
	_ctlIndicatorAllOnOff(1);

	// ��ʱ1s����main init
	emberEventControlSetDelayMS(mainInit_EventControl,1000);
}


// 1s�����¼�
// ��ʼ��ϵͳ
EmberEventControl mainInit_EventControl;
void mainInit_EventFunction(void){


	emberEventControlSetInactive(mainInit_EventControl);

//	DEBUG(":::run->mainInit Event !!");

	// ������־
	startup = false;

	// LEDϨ��
	_ctlIndicatorAllOnOff(0);


	// ˫��&���� �жϸ���
	for(uint8_t i = 1;i <= _getEndpointCount();i ++){
		emberAfPluginIdentifyStopFeedbackCallback(i);
	}


	// ����keyscan����
	startApp_Keyscan(100);


}




