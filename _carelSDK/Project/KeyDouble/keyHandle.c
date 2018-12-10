/**********************************************************************
 * 文件		：_carelSDK/Project/KeyDouble/keyHandle.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../../common.h"
#include "plugin/scenes/scenes.h"




// key0按下
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



	// 双控功能
	if(ep_ptr->mode == MODE_DOUBLE){
		DEBUG("::: 双控 发送！");
		// binding 单播
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
	// 场景功能
	else if(ep_ptr->mode == MODE_SCENES){
		DEBUG("::: 场景 发送！");
		EmberAfSceneTableEntry entry;
		uint8_t i = 0;
		// 检索匹配场景项
		for (i = 0; i < EMBER_AF_PLUGIN_SCENES_TABLE_SIZE; i++) {
			emberAfPluginScenesServerRetrieveSceneEntry(entry, i);
			if(entry.endpoint == ep_ptr->endPoint){
				break;
			}
		}

		// 无对应场景,LED无效闪烁(2Hz, 2s)
		if(i == EMBER_AF_PLUGIN_SCENES_TABLE_SIZE){
			setList_Led(ep_ptr->data.data_keydouble.boardLed,10,8,0);
			return;
		}

		// 场景控制指示:亮起LED2s
		setList_Led(ep_ptr->data.data_keydouble.boardLed,80,1,0);

		// 场景控制命令:recall
		emberAfSetCommandEndpoints(ep_ptr->endPoint, 0);
		emberAfFillCommandScenesClusterRecallScene(entry.groupId, entry.sceneId);
		emberAfSendCommandMulticast(entry.groupId);
	}
#endif
}

// key0一级长按
// 若当前无网络，则启动commissioning
void key0LongPressed1_Callback(void){
	startCommissioning(1);
}

// key0二级长按
// 离开网络
void key0LongPressed2_Callback(void){
	emberLeaveNetwork();
}
// key1按下
void key1Pressed_Callback(void){
	endPoint_t *ep_ptr = _getEndpointIterm(2);
	if(ep_ptr == NULL)
		return;

	// 双控功能
	if(ep_ptr->mode == MODE_DOUBLE){
		DEBUG("::: 双控 发送！");
		// binding 单播
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
	// 场景功能
	else if(ep_ptr->mode == MODE_SCENES){
		DEBUG("::: 场景 发送！");
		EmberAfSceneTableEntry entry;
		uint8_t i = 0;
		// 检索匹配场景项
		for (i = 0; i < EMBER_AF_PLUGIN_SCENES_TABLE_SIZE; i++) {
			emberAfPluginScenesServerRetrieveSceneEntry(entry, i);
			if(entry.endpoint == ep_ptr->endPoint){
				break;
			}
		}

		// 无对应场景,LED无效闪烁(2Hz, 2s)
		if(i == EMBER_AF_PLUGIN_SCENES_TABLE_SIZE){
			setList_Led(ep_ptr->data.data_keydouble.boardLed,10,8,0);
			return;
		}

		// 场景控制指示:亮起LED2s
		setList_Led(ep_ptr->data.data_keydouble.boardLed,80,1,0);

		// 场景控制命令:recall
		emberAfSetCommandEndpoints(ep_ptr->endPoint, 0);
		emberAfFillCommandScenesClusterRecallScene(entry.groupId, entry.sceneId);
		emberAfSendCommandMulticast(entry.groupId);
	}
}
