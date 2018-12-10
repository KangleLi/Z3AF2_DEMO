/***
 * 文件		：_carelSDK/Project/KeyDouble/keyDouble.c
 * 描述		：
 * 创建日期	：2018/11/20
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "../../common.h"
#include<stdlib.h>
#include "../../Tokens/keydouble-tokens.h"


//
bool _localHandler_KeyDouble(uint8_t ep, uint8_t state){
	mulbits8_t buf_tk;

	endPoint_t *epPtr = _getEndpointIterm(ep);
	// 空地址检查
	if(epPtr == NULL)
		return false;
	// 双控模式检查
	if(epPtr->mode != MODE_DOUBLE)
		return false;
	//
	epPtr->data.data_keydouble.state = state==0?0:1;
	_updateIndicatorByMode();
	// 更新token
	buf_tk.type_uint8 = _getToken_KeyDoubleSet(ONOFF_STATE);
	_SET_BIT_FROMBITS8(ep, &buf_tk, epPtr->data.data_keydouble.state);
	DEBUG(":::--------state：%d", epPtr->data.data_keydouble.state);
	DEBUG(":::--------写token：%d", buf_tk.type_uint8);
	_setToken_KeyDoubleSet(ONOFF_STATE, buf_tk.type_uint8);
	DEBUG(":::--------写检查token：%d", _getToken_KeyDoubleSet(ONOFF_STATE));
	DEBUG(":::--->local done !!");

	return true;
}




//
void _updateIndicatorByMode(void){
	uint8_t iMode = _getToken_KeyDoubleSet(INDICATOR_MODE);
	//DEBUG(":::-------指示灯模式: %d", iMode);
#if 1
	endPoint_t *epPtr;
	for(uint8_t i=1;i <= _getEndpointCount();i++){
		epPtr = _getEndpointIterm(i);
		if(epPtr->mode == MODE_DOUBLE){
			stopList_Led(epPtr->data.data_keydouble.boardLed, \
					epPtr->data.data_keydouble.state==0? \
					(iMode==0?0:1): \
					(iMode==0?1:0));
		}
	}
#endif
}







// report解码
bool _reportDecode(uint16_t clusterId, uint16_t attrId, uint8_t dataType, void *dataptr){

	uint8_t attrVal_OnOff = 0;

	switch(clusterId){
	case 0x0006:
		if(dataType == 0x10){
			attrVal_OnOff = *(uint8_t *)dataptr;
			DEBUG(":::On Off Report Get attr: %d    Val: %d  ", attrId, attrVal_OnOff);
			if(_localHandler_KeyDouble(emberAfCurrentEndpoint(), attrVal_OnOff))
				return true;
		}
		break;
	default:
		break;
	}

	return false;
}





bool _writeAttrDecode(uint8_t endpoint, uint16_t clusterId, uint16_t attributeId, void *value, uint8_t type){
	endPoint_t *epPtr = _getEndpointIterm(endpoint);
	if(epPtr == NULL)
		return false;

	switch(clusterId){
	case 0xFC56:
		if(epPtr->mode != MODE_DOUBLE)
			return true;
		// 指示灯模式控制
		if(attributeId == 0x0000){
			if(type == 0x20){
				//epPtr->data.data_keydouble.indicatorMode = (*(uint8_t *)value)==0?0:1;
				_setToken_KeyDoubleSet(INDICATOR_MODE,(*(uint8_t *)value)==0?0:1);
				_updateIndicatorByMode();
				//_localHandler_KeyDouble(epPtr->endPoint, epPtr->data.data_keydouble.state);
				//DEBUG(":::____----_____----- 指示灯模式: %d", epPtr->data.data_keydouble.indicatorMode);
				//DEBUG(":::-----------------------val: %d", *(uint8_t *)value);
			}
		}
		// on-off状态
		else if(attributeId == 0x0003){
			if(type == 0x20){
				uint8_t buf_state = (*(uint8_t *)value)==0?0:1;
				//_localHandler_KeyDouble(epPtr->endPoint, epPtr->data.data_keydouble.state);
				extern void key0Pressed_Callback(void);
				if(!(epPtr->data.data_keydouble.state & buf_state))
					key0Pressed_Callback();
			}
		}
		return true;
	default:
		break;
	}
	return false;
}







uint8_t _getToken_KeyDoubleSet(uint8_t index){
	keyDouble_Set_t buf_set;
	halCommonGetToken(&buf_set, TOKEN_KEYDOUBLE_SET);
	return buf_set.keyDouble_Set[index];
}


void _setToken_KeyDoubleSet(uint8_t index,uint8_t data){
	keyDouble_Set_t buf_set;
	halCommonGetToken(&buf_set, TOKEN_KEYDOUBLE_SET);
	buf_set.keyDouble_Set[index] = data;
	halCommonSetToken(TOKEN_KEYDOUBLE_SET, &buf_set);
}





#if 0
void _globalReadCmd_ToBind(uint8_t ep, uint16_t clusterId, uint16_t attrId){
	emberAfSetCommandEndpoints(ep, 0);
	zclGlobalReadCommand();

	emberAfSendCommandUnicastToBindings();


}
#endif
