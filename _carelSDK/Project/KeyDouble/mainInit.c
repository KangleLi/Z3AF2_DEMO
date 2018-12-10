/**********************************************************************
 * 文件		：_carelSDK/Project/KeyDouble/mainInit.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../../common.h"



extern EmberEventControl mainInit_EventControl;
void mainInit_Start(void){

	//addList_EP(1,MODE_SCENES,&ks_1);
	addList_EP(1,MODE_SCENES,&ks_2);

	DEBUG(":::端点数量：%d",_getEndpointCount());

	// 启动LED任务
	startApp_LedBlink(1);

	// LED常亮
	_ctlIndicatorAllOnOff(1);

	// 延时1s启动main init
	emberEventControlSetDelayMS(mainInit_EventControl,1000);
}


// 1s启动事件
// 初始化系统
EmberEventControl mainInit_EventControl;
void mainInit_EventFunction(void){


	emberEventControlSetInactive(mainInit_EventControl);

//	DEBUG(":::run->mainInit Event !!");

	// 启动标志
	startup = false;

	// LED熄灭
	_ctlIndicatorAllOnOff(0);


	// 双控&场景 判断更新
	for(uint8_t i = 1;i <= _getEndpointCount();i ++){
		emberAfPluginIdentifyStopFeedbackCallback(i);
	}


	// 启动keyscan任务
	startApp_Keyscan(100);


}




