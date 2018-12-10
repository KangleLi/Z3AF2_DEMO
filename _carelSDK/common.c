/***
 * 文件		：_carelSDK/common.c
 * 描述		：
 * 创建日期	：2018/11/15
 * 设计者		：Carel.Li
 * 修改日期	：
 * 修改内容	：
 * 版本		：v1.0
 */
#include "common.h"
#include <stdlib.h>

// 启动标志
bool startup = true;


// 端点表
LIST(EP_LIST);



// 位域结构体 位取值
uint8_t _GET_BIT_FROMBITS8(uint8_t index, mulbits8_t *data){
	switch(index){
	case 1:
		return (uint8_t)((*data).type_bits8.bit_0);
	case 2:
		return (uint8_t)((*data).type_bits8.bit_1);
	case 3:
		return (uint8_t)((*data).type_bits8.bit_2);
	case 4:
		return (uint8_t)((*data).type_bits8.bit_3);
	case 5:
		return (uint8_t)((*data).type_bits8.bit_4);
	case 6:
		return (uint8_t)((*data).type_bits8.bit_5);
	case 7:
		return (uint8_t)((*data).type_bits8.bit_6);
	case 8:
		return (uint8_t)((*data).type_bits8.bit_7);
	default:
		return 0xFF;
	}
}

// 位域结构体 位赋值
void _SET_BIT_FROMBITS8(uint8_t index, mulbits8_t *data, uint8_t bit){
	switch(index){
	case 1:
		(*data).type_bits8.bit_0 = bit==0?0:1;
		break;
	case 2:
		(*data).type_bits8.bit_1 = bit==0?0:1;
		break;
	case 3:
		(*data).type_bits8.bit_2 = bit==0?0:1;
		break;
	case 4:
		(*data).type_bits8.bit_3 = bit==0?0:1;
		break;
	case 5:
		(*data).type_bits8.bit_4 = bit==0?0:1;
		break;
	case 6:
		(*data).type_bits8.bit_5 = bit==0?0:1;
		break;
	case 7:
		(*data).type_bits8.bit_6 = bit==0?0:1;
		break;
	case 8:
		(*data).type_bits8.bit_7 = bit==0?0:1;
		break;
	default:
		break;
	}
}




/**
 * 双控端点定义
 */
keydouble_t kb_1 = {
	BUTTON0,			// 按键
	BOARDLED0,			// 指示灯
	0,					// state
//	0					// 模式
};
keydouble_t kb_2 = {
	BUTTON1,			// 按键
	BOARDLED1,			// 指示灯
	0,					// state
//	0					// 模式
};

/**
 * 场景端点定义
 */
scenes_t ks_1 = {
	BUTTON0,			// 按键
	BOARDLED0,			// 指示灯
};
scenes_t ks_2 = {
	BUTTON1,			// 按键
	BOARDLED1,			// 指示灯
};

// 得到端点数量
//
uint8_t _getEndpointCount(void){
	return list_length(EP_LIST);
}

// 删除元素
//
void _removeEndpointIterm(endPoint_t *iterm){
	list_remove(EP_LIST,iterm);
}


// 得到ep对应元素指针
endPoint_t *_getEndpointIterm(uint8_t ep){
	if(*EP_LIST == NULL)
		return NULL;
	for(endPoint_t *buf_ep = *EP_LIST;buf_ep != NULL;buf_ep = buf_ep->next){
		if(buf_ep->endPoint == ep){
			return buf_ep;
		}
	}

	return NULL;
}


void addList_EP(uint8_t ep,uint8_t mode,void *data){

	endPoint_t *bufEp = malloc(sizeof(endPoint_t));

	if(data == NULL)
		return;

	bufEp->endPoint = ep;
	bufEp->mode = mode;

	switch(mode){
	case MODE_DOUBLE:
		bufEp->data.data_keydouble.boardBtn = ((keydouble_t *)data)->boardBtn;
		bufEp->data.data_keydouble.boardLed = ((keydouble_t *)data)->boardLed;
		//bufEp->data.data_keydouble.indicatorMode = ((keydouble_t *)data)->indicatorMode;
		bufEp->data.data_keydouble.state = ((keydouble_t *)data)->state;
		break;
	case MODE_SCENES:
		bufEp->data.data_sccenes.boardBtn = ((scenes_t *)data)->boardBtn;
		bufEp->data.data_sccenes.boardLed = ((scenes_t *)data)->boardLed;
		break;
	case MODE_KEY:
		break;
	case MODE_CURTAIN:
		break;
	default:
		break;
	}

	list_add(EP_LIST,bufEp);
}

// 开所有LED指定时间 delay * 25ms
void _ctlIndicatorAllOnDelay(uint16_t time){
	if(*EP_LIST == NULL)
		return;
	for(endPoint_t *ep = *EP_LIST;ep != NULL;ep = ep->next){

		switch(ep->mode){
		case MODE_DOUBLE:
			setList_Led(ep->data.data_keydouble.boardLed,time,1,0);
			DEBUG(":::on off ep: %d  led:%d",ep->endPoint,ep->data.data_keydouble.boardLed);
			break;
		case MODE_SCENES:
			setList_Led(ep->data.data_sccenes.boardLed,time,1,0);
			break;
		case MODE_KEY:
			setList_Led(ep->data.data_key.boardLed,time,1,0);
			break;
		case MODE_CURTAIN:
			setList_Led(ep->data.data_curtain.boardLed_down,time,1,0);
			setList_Led(ep->data.data_curtain.boardLed_up,time,1,0);
			break;
		default:
			break;
		}

	}
}


// 开关所有LED
void _ctlIndicatorAllOnOff(uint8_t mask){
	if(*EP_LIST == NULL)
		return;
	for(endPoint_t *ep = *EP_LIST;ep != NULL;ep = ep->next){

		switch(ep->mode){
		case MODE_DOUBLE:
			stopList_Led(ep->data.data_keydouble.boardLed,mask==0?0:1);
			DEBUG(":::on off ep: %d  led:%d",ep->endPoint,ep->data.data_keydouble.boardLed);
			break;
		case MODE_SCENES:
			stopList_Led(ep->data.data_sccenes.boardLed,mask==0?0:1);
			break;
		case MODE_KEY:
			stopList_Led(ep->data.data_key.boardLed,mask==0?0:1);
			break;
		case MODE_CURTAIN:
			stopList_Led(ep->data.data_curtain.boardLed_down,mask==0?0:1);
			stopList_Led(ep->data.data_curtain.boardLed_up,mask==0?0:1);
			break;
		default:
			break;
		}

	}
}




