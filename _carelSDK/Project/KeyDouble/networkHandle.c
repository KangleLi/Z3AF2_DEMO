/**********************************************************************
 * 文件		：_carelSDK/Project/KeyDouble/networkHandle.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../../common.h"
#include EMBER_AF_API_NETWORK_STEERING
#include EMBER_AF_API_FIND_AND_BIND_TARGET


// commissioning 事件
EmberEventControl commissioning_EventControl;
void commissioning_EventFunction(void){
	emberEventControlSetInactive(commissioning_EventControl);

	DEBUG(":::commissioning !!!");

	if(emberAfNetworkState() == EMBER_JOINED_NETWORK){
		// nothing
	}
	else{
		// 网络指示LED闪烁频率4Hz
		setList_Led(BOARDLED1,5,0xFFFF,0);
		// 启动steering
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

	// 网络指示LED 2Hz闪烁5s后熄灭
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

		// 若是双控开关
		if(getBindingInfoFromEp(endpoint,0x0006) != 0xFF){
			DEBUG(":::双控开关 !!!");

			// 双控模式
			if(ep_ptr->mode != MODE_DOUBLE){
				_removeEndpointIterm(ep_ptr);
				addList_EP(endpoint,MODE_DOUBLE,&kb_2);
				// 重新读取ep地址
				ep_ptr = _getEndpointIterm(endpoint);
				///////////////////////////////////////////////////
				// 读取token on-off属性
				onoff_state.type_uint8 = _getToken_KeyDoubleSet(ONOFF_STATE);
				//DEBUG(":::--------读取token: %d", onoff_state.type_uint8);
				ep_ptr->data.data_keydouble.state = _GET_BIT_FROMBITS8(ep_ptr->endPoint, &onoff_state);
				//DEBUG(":::--------验证：%d", ep_ptr->data.data_keydouble.state);
				// 更新指示灯状态
				_updateIndicatorByMode();
			}
		}
		// 否则视为场景开关
		else{
			DEBUG(":::场景开关 !!!");

			// 场景模式
			if(ep_ptr->mode != MODE_SCENES){
				_removeEndpointIterm(ep_ptr);
				addList_EP(endpoint,MODE_SCENES,&ks_2);
				// 重新读取ep地址
				ep_ptr = _getEndpointIterm(endpoint);
				///////////////////////////////////////////////////
				// LED操作，待扩展(这里关闭)
				stopList_Led(ep_ptr->data.data_keydouble.boardLed,0);
			}
		}
	}
}



// FindingAndBinding 事件
EmberEventControl findingandbinding_EventControl;
void findingandbinding_EventFunction(void){
	emberEventControlSetInactive(findingandbinding_EventControl);
	DEBUG(":::FindingAndBinding !!!");

	// 启动finding&binding
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
		// 启动finding binding
		startFindingAndBinding(1);
	}
	else if(status == EMBER_NETWORK_DOWN){
		DEBUG(":::EMBER_NETWORK_DOWN !! ");
		// 清除binding
		emberClearBindingTable();
		// 清除reporting
		emberAfClearReportTableCallback();
		// 清除groups、scenes
		for(uint8_t epindex = 0;epindex < emberAfEndpointCount();epindex ++){
			uint8_t ep = emberAfEndpointFromIndex(epindex);
			emberAfGroupsClusterClearGroupTableCallback(ep);
			emberAfScenesClusterClearSceneTableCallback(ep);
		}
		// 重建reporting
		/////////////////////////////////////////////////////////////
		// 网络指示LED 2Hz闪烁2后熄灭
		setList_Led(BOARDLED1,10,8,0);

		// 若失去网络，5s后重新Commissioning
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
		// 网络指LED 2Hz闪烁2后熄灭
		setList_Led(BOARDLED1,10,8,0);
	}
	// 首次steering失败重启commissioning事件
	else{
		DEBUG(":::steering failure !!!");
		if(one_time){
			one_time = false;
			startCommissioning(40);
		}
		// 2次steering失败
		else{
			// LED
			stopList_Led(BOARDLED1,0);
		}
	}
}


// 激活Commissioning event
void startCommissioning(uint32_t delay){
	emberEventControlSetDelayMS(commissioning_EventControl,delay);
}


// 激活findingandbinding event
void startFindingAndBinding(uint32_t delay){
	emberEventControlSetDelayMS(findingandbinding_EventControl,delay);
}
