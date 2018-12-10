/**********************************************************************
 * 文件		：_carelSDK/Z3_Extend/mainCallback.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../common.h"

/*[Calback]
 * 函数：emberAfMainInitCallback
 * 描述：
 * 输入：void
 * 输出：void
 */
extern void mainInit_Start(void);
void emberAfMainInitCallback(void){
	//DEBUG(":::run -> main init");

	//mainInit_Start();
}

/*[Calback]
 * 函数：emberAfMainTickCallback
 * 描述：
 * 输入：void
 * 输出：void
 */
static bool F1_Tick = true;
void emberAfMainTickCallback(void){
	if(F1_Tick){
		F1_Tick = false;
		DEBUG(":::run -> main Tick");
		mainInit_Start();
	}
}

EmberAfAttributeWritePermission emberAfAllowNetworkWriteAttributeCallback(int8u endpoint,
                                                                          EmberAfClusterId clusterId,
                                                                          EmberAfAttributeId attributeId,
                                                                          int8u mask,
                                                                          int16u manufacturerCode,
                                                                          int8u* value,
                                                                          int8u type){
	if(_writeAttrDecode(endpoint, clusterId, attributeId, value, type))
		return EMBER_ZCL_ATTRIBUTE_WRITE_PERMISSION_DENY_WRITE;
	else
		return EMBER_ZCL_ATTRIBUTE_WRITE_PERMISSION_ALLOW_WRITE_NORMAL;
}

boolean emberAfReportAttributesCallback(EmberAfClusterId clusterId,
                                     int8u *buffer,
                                     int16u bufLen){
	DEBUG(":::RX Reporting！ clusterId:%d  attrId:%d  attrType:0x%X",clusterId,*(uint16_t *)buffer,*(uint8_t *)(buffer+2));
	if(bufLen < 4)
		return false;

	_reportDecode(clusterId,*(uint16_t *)buffer,*(uint8_t *)(buffer+2),buffer+3);

	return true;
}

void emberAfHalButtonIsrCallback(uint8_t button,
                                 uint8_t state)
{
}
