
#ifndef CARELSDK_PROJECT_KEYDOUBLE_KEYDOUBLE_H_
#define CARELSDK_PROJECT_KEYDOUBLE_KEYDOUBLE_H_




// Token index
enum{
	INDICATOR_MODE = 0,
	ONOFF_STATE,
};








extern bool _localHandler_KeyDouble(uint8_t ep, uint8_t state);
void _updateIndicatorByMode(void);

extern bool _reportDecode(uint16_t clusterId, uint16_t attrId, uint8_t dataType, void *dataptr);

bool _writeAttrDecode(uint8_t endpoint, uint16_t clusterId, uint16_t attributeId, void *value, uint8_t type);

uint8_t _getToken_KeyDoubleSet(uint8_t index);
void _setToken_KeyDoubleSet(uint8_t index,uint8_t data);



#endif /* CARELSDK_PROJECT_KEYDOUBLE_KEYDOUBLE_H_ */
