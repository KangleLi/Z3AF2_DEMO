/**********************************************************************
 * �ļ�		��_carelSDK/Project/KeyDouble/networkHandle.c
 * ����		��
 * ��������	��2018/11/15
 * �����		��Carel.Li
 * �޸�����	��
 * �޸�����	��
 * �汾		��v1.0
 */
#include "../../common.h"
#include EMBER_AF_API_NETWORK_STEERING
#include EMBER_AF_API_FIND_AND_BIND_TARGET


// commissioning �¼�
EmberEventControl commissioning_EventControl;
void commissioning_EventFunction(void){
	emberEventControlSetInactive(commissioning_EventControl);

	DEBUG(":::commissioning !!!");

	if(emberAfNetworkState() == EMBER_JOINED_NETWORK){
		// nothing
	}
	else{
		// ����ָʾLED��˸Ƶ��4Hz
		setList_Led(BOARDLED1,5,0xFFFF,0);
		// ����steering
		emberAfPluginNetworkSteeringStart();
	}
}



// callback
// Identify Start
void emberAfPluginIdentifyStartFeedbackCallback(uint8_t endpoint,
                                                uint16_t identifyTime){
	DEBUG(":::Identify Start !!!ep:%d  time:%d",endpoint,identifyTime);
	if(startup)
		return;

	// ����ָʾLED 2Hz��˸5s��Ϩ��
	setList_Led(BOARDLED1,10,20,0);
}



// callback
// Identify Stop
void emberAfPluginIdentifyStopFeedbackCallback(uint8_t endpoint){
	mulbits8_t onoff_state;

	DEBUG(":::Identify Stop !!!");
	if(startup)
		return;

	for(uint8_t i = 1;i <= _getEndpointCount();i ++){
		endPoint_t *ep_ptr = _getEndpointIterm(i);
		if(ep_ptr == NULL)
			continue;

		// ����˫�ؿ���
		if(getBindingInfoFromEp(endpoint,0x0006) != 0xFF){
			DEBUG(":::˫�ؿ��� !!!");

			// ˫��ģʽ
			if(ep_ptr->mode != MODE_DOUBLE){
				_removeEndpointIterm(ep_ptr);
				addList_EP(endpoint,MODE_DOUBLE,&kb_2);
				// ���¶�ȡep��ַ
				ep_ptr = _getEndpointIterm(endpoint);
				///////////////////////////////////////////////////
				// ��ȡtoken on-off����
				onoff_state.type_uint8 = _getToken_KeyDoubleSet(ONOFF_STATE);
				//DEBUG(":::--------��ȡtoken: %d", onoff_state.type_uint8);
				ep_ptr->data.data_keydouble.state = _GET_BIT_FROMBITS8(ep_ptr->endPoint, &onoff_state);
				//DEBUG(":::--------��֤��%d", ep_ptr->data.data_keydouble.state);
				// ����ָʾ��״̬
				_updateIndicatorByMode();
			}
		}
		// ������Ϊ��������
		else{
			DEBUG(":::�������� !!!");

			// ����ģʽ
			if(ep_ptr->mode != MODE_SCENES){
				_removeEndpointIterm(ep_ptr);
				addList_EP(endpoint,MODE_SCENES,&ks_2);
				// ���¶�ȡep��ַ
				ep_ptr = _getEndpointIterm(endpoint);
				///////////////////////////////////////////////////
				// LED����������չ(����ر�)
				stopList_Led(ep_ptr->data.data_keydouble.boardLed,0);
			}
		}
	}
}



// FindingAndBinding �¼�
EmberEventControl findingandbinding_EventControl;
void findingandbinding_EventFunction(void){
	emberEventControlSetInactive(findingandbinding_EventControl);
	DEBUG(":::FindingAndBinding !!!");

	// ����finding&binding
	if(emberAfNetworkState() == EMBER_JOINED_NETWORK){
		emberAfPluginFindAndBindTargetStart(1);
	}
}


// callback
// stack status
bool emberAfStackStatusCallback(EmberStatus status)
{
	if(status == EMBER_NETWORK_UP){
		DEBUG(":::EMBER_NETWORK_UP !! ");
		// ����finding binding
		startFindingAndBinding(1);
	}
	else if(status == EMBER_NETWORK_DOWN){
		DEBUG(":::EMBER_NETWORK_DOWN !! ");
		// ���binding
		emberClearBindingTable();
		// ���reporting
		emberAfClearReportTableCallback();
		// ���groups��scenes
		for(uint8_t epindex = 0;epindex < emberAfEndpointCount();epindex ++){
			uint8_t ep = emberAfEndpointFromIndex(epindex);
			emberAfGroupsClusterClearGroupTableCallback(ep);
			emberAfScenesClusterClearSceneTableCallback(ep);
		}
		// �ؽ�reporting
		/////////////////////////////////////////////////////////////
		// ����ָʾLED 2Hz��˸2��Ϩ��
		setList_Led(BOARDLED1,10,8,0);

		// ��ʧȥ���磬5s������Commissioning
		if(emberAfNetworkState() == EMBER_NO_NETWORK){
			startCommissioning(5000);
		}

	}
	return false;
}


// callback
// Network Steering Complete
void emberAfPluginNetworkSteeringCompleteCallback(EmberStatus status,
                                                  uint8_t totalBeacons,
                                                  uint8_t joinAttempts,
                                                  uint8_t finalState){
	static bool one_time = true;
	if(status == EMBER_SUCCESS){
		DEBUG(":::steering success !!!");
		// ����ָLED 2Hz��˸2��Ϩ��
		setList_Led(BOARDLED1,10,8,0);
	}
	// �״�steeringʧ������commissioning�¼�
	else{
		DEBUG(":::steering failure !!!");
		if(one_time){
			one_time = false;
			startCommissioning(40);
		}
		// 2��steeringʧ��
		else{
			// LED
			stopList_Led(BOARDLED1,0);
		}
	}
}


// ����Commissioning event
void startCommissioning(uint32_t delay){
	emberEventControlSetDelayMS(commissioning_EventControl,delay);
}


// ����findingandbinding event
void startFindingAndBinding(uint32_t delay){
	emberEventControlSetDelayMS(findingandbinding_EventControl,delay);
}
