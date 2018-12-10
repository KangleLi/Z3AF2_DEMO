/**********************************************************************
 * �ļ�		��_carelSDK/Project/KeyDouble/keyHandle.c
 * ����		��
 * ��������	��2018/11/15
 * �����		��Carel.Li
 * �޸�����	��
 * �޸�����	��
 * �汾		��v1.0
 */
#include "../../common.h"
#include "plugin/scenes/scenes.h"




// key0����
void key0Pressed_Callback(void){
	static bool check_mode = false;

	endPoint_t *ep_ptr = _getEndpointIterm(1);
	if(ep_ptr == NULL)
		return;

	if(getBindingInfoFromEp(ep_ptr->endPoint,0x0006) != 0xFF){
		if(check_mode == false){
			check_mode = true;
			extern void emberAfPluginIdentifyStopFeedbackCallback(uint8_t endpoint);
			emberAfPluginIdentifyStopFeedbackCallback(ep_ptr->endPoint);
			ep_ptr = _getEndpointIterm(ep_ptr->endPoint);
		}
	}
	else{
		if(check_mode == true){
			check_mode = false;
			extern void emberAfPluginIdentifyStopFeedbackCallback(uint8_t endpoint);
			emberAfPluginIdentifyStopFeedbackCallback(ep_ptr->endPoint);
			ep_ptr = _getEndpointIterm(ep_ptr->endPoint);
		}
	}



	// ˫�ع���
	if(ep_ptr->mode == MODE_DOUBLE){
		DEBUG("::: ˫�� ���ͣ�");
		// binding ����
		emberAfSetCommandEndpoints(ep_ptr->endPoint, 0);

		//_localHandler_KeyDouble(ep_ptr->endPoint, ep_ptr->data.data_keydouble.state==0?1:0);

		if(ep_ptr->data.data_keydouble.state != 0){
			emberAfFillCommandOnOffClusterOff();
		}
		else{
			emberAfFillCommandOnOffClusterOn();
		}

		emberAfSendCommandUnicastToBindings();
	}
#if 1
	// ��������
	else if(ep_ptr->mode == MODE_SCENES){
		DEBUG("::: ���� ���ͣ�");
		EmberAfSceneTableEntry entry;
		uint8_t i = 0;
		// ����ƥ�䳡����
		for (i = 0; i < EMBER_AF_PLUGIN_SCENES_TABLE_SIZE; i++) {
			emberAfPluginScenesServerRetrieveSceneEntry(entry, i);
			if(entry.endpoint == ep_ptr->endPoint){
				break;
			}
		}

		// �޶�Ӧ����,LED��Ч��˸(2Hz, 2s)
		if(i == EMBER_AF_PLUGIN_SCENES_TABLE_SIZE){
			setList_Led(ep_ptr->data.data_keydouble.boardLed,10,8,0);
			return;
		}

		// ��������ָʾ:����LED2s
		setList_Led(ep_ptr->data.data_keydouble.boardLed,80,1,0);

		// ������������:recall
		emberAfSetCommandEndpoints(ep_ptr->endPoint, 0);
		emberAfFillCommandScenesClusterRecallScene(entry.groupId, entry.sceneId);
		emberAfSendCommandMulticast(entry.groupId);
	}
#endif
}

// key0һ������
// ����ǰ�����磬������commissioning
void key0LongPressed1_Callback(void){
	startCommissioning(1);
}

// key0��������
// �뿪����
void key0LongPressed2_Callback(void){
	emberLeaveNetwork();
}
// key1����
void key1Pressed_Callback(void){
	endPoint_t *ep_ptr = _getEndpointIterm(2);
	if(ep_ptr == NULL)
		return;

	// ˫�ع���
	if(ep_ptr->mode == MODE_DOUBLE){
		DEBUG("::: ˫�� ���ͣ�");
		// binding ����
		emberAfSetCommandEndpoints(ep_ptr->endPoint, 0);
		if(ep_ptr->data.data_keydouble.state){
			ep_ptr->data.data_keydouble.state = 0;
			//stopList_Led(ep_ptr->data.data_keydouble.boardLed, \
			//		ep_ptr->data.data_keydouble.indicatorMode==0?0:1);
			emberAfFillCommandOnOffClusterOff();
		}else{
			ep_ptr->data.data_keydouble.state = 1;
			//stopList_Led(ep_ptr->data.data_keydouble.boardLed, \
			//					ep_ptr->data.data_keydouble.indicatorMode==0?1:0);
			emberAfFillCommandOnOffClusterOn();
		}
		_updateIndicatorByMode();
		emberAfSendCommandUnicastToBindings();
	}
	// ��������
	else if(ep_ptr->mode == MODE_SCENES){
		DEBUG("::: ���� ���ͣ�");
		EmberAfSceneTableEntry entry;
		uint8_t i = 0;
		// ����ƥ�䳡����
		for (i = 0; i < EMBER_AF_PLUGIN_SCENES_TABLE_SIZE; i++) {
			emberAfPluginScenesServerRetrieveSceneEntry(entry, i);
			if(entry.endpoint == ep_ptr->endPoint){
				break;
			}
		}

		// �޶�Ӧ����,LED��Ч��˸(2Hz, 2s)
		if(i == EMBER_AF_PLUGIN_SCENES_TABLE_SIZE){
			setList_Led(ep_ptr->data.data_keydouble.boardLed,10,8,0);
			return;
		}

		// ��������ָʾ:����LED2s
		setList_Led(ep_ptr->data.data_keydouble.boardLed,80,1,0);

		// ������������:recall
		emberAfSetCommandEndpoints(ep_ptr->endPoint, 0);
		emberAfFillCommandScenesClusterRecallScene(entry.groupId, entry.sceneId);
		emberAfSendCommandMulticast(entry.groupId);
	}
}
