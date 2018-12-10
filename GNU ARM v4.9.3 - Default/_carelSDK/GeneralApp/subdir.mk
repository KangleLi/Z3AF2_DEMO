################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_carelSDK/GeneralApp/key_scan.c \
../_carelSDK/GeneralApp/led_blink.c 

OBJS += \
./_carelSDK/GeneralApp/key_scan.o \
./_carelSDK/GeneralApp/led_blink.o 

C_DEPS += \
./_carelSDK/GeneralApp/key_scan.d \
./_carelSDK/GeneralApp/led_blink.d 


# Each subdirectory must supply rules for building sources it contributes
_carelSDK/GeneralApp/key_scan.o: ../_carelSDK/GeneralApp/key_scan.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=gnu99 '-DCONFIGURATION_HEADER="app/framework/util/config.h"' '-DCORTEXM3=1' '-DCORTEXM3_EFM32_MICRO=1' '-DCORTEXM3_EFR32=1' '-DCORTEXM3_EFR32_MICRO=1' '-DAPP_GECKO_INFO_PAGE_BTL=1' '-DATTRIBUTE_STORAGE_CONFIGURATION="app/builder/Z3AF2_DEMO/Z3AF2_DEMO_endpoint_config.h"' '-DCORTEXM3_EFR32MG12P332F1024GL125=1' '-DCORTEXM3_EFR32MG12P332F1024GL125_MICRO=1' '-DGENERATED_TOKEN_HEADER="app/builder/Z3AF2_DEMO/Z3AF2_DEMO_tokens.h"' '-DZA_GENERATED_HEADER="app/builder/Z3AF2_DEMO/Z3AF2_DEMO.h"' '-DPLATFORM_HEADER="platform/base/hal/micro/cortexm3/compiler/gcc.h"' '-DEFR32MG12P=1' '-DEFR32MG12P332F1024GL125=1' '-DEFR32_SERIES1_CONFIG2_MICRO=1' '-DHAL_CONFIG=1' '-DEMBER_AF_USE_HWCONF=1' '-DEMBER_AF_API_EMBER_TYPES="stack/include/ember-types.h"' '-DEMBER_AF_API_DEBUG_PRINT="app/framework/util/print.h"' '-DEMBER_AF_API_AF_HEADER="app/framework/include/af.h"' '-DEMBER_AF_API_AF_SECURITY_HEADER="app/framework/security/af-security.h"' '-DEMBER_STACK_ZIGBEE=1' '-DEMLIB_USER_CONFIG=1' '-DEMBER_PARAMETERIZED_BROADCAST_TABLE=1' '-DAPPLICATION_TOKEN_HEADER="app/builder/Z3AF2_DEMO/afv2-token.h"' '-DAPPLICATION_MFG_TOKEN_HEADER="app/builder/Z3AF2_DEMO/afv2-mfg-token.h"' '-DPHY_RAIL=1' -I"D:\soft\SiliconLabs\SimplicityStudio\v4\developer\sdks\gecko_sdk_suite\v2.4\app\builder\Z3AF2_DEMO\hal-config" -I"D:\soft\SiliconLabs\SimplicityStudio\v4\developer\sdks\gecko_sdk_suite\v2.4\app\builder\Z3AF2_DEMO\external-generated-files" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4/" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//plugin" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//micro/cortexm3/efm32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//micro/cortexm3/efm32/config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//micro/cortexm3/efm32/efr32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../CMSIS/Include" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/common/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/dmadrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/gpiointerrupt/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/rtcdrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/rtcdrv/test" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/sleep/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/spidrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/tempdrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/uartdrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/ustimer/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emlib/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../middleware/glib" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../middleware/glib/glib" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../radio/rail_lib/plugin" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../radio/rail_lib/chip/efr32/rf/common/cortex" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../radio/rail_lib/chip/efr32/rf/rfprotocol/ieee802154/cortex" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/halconfig/inc/hal-config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/module/config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/halconfig" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//app/builder/Z3AF2_DEMO" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//app/builder/Z3AF2_DEMO/hal-config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal/micro/cortexm3/efm32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/bootloader/api" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/app/framework" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/stack" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/app/util" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/app/framework/include" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/bootloader" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/plugin/coexistence/hal/efr32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/plugin/coexistence/common" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/protocol/zwave" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/protocol/ieee802154" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/protocol/ble" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/common" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"_carelSDK/GeneralApp/key_scan.d" -MT"_carelSDK/GeneralApp/key_scan.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

_carelSDK/GeneralApp/led_blink.o: ../_carelSDK/GeneralApp/led_blink.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=gnu99 '-DCONFIGURATION_HEADER="app/framework/util/config.h"' '-DCORTEXM3=1' '-DCORTEXM3_EFM32_MICRO=1' '-DCORTEXM3_EFR32=1' '-DCORTEXM3_EFR32_MICRO=1' '-DAPP_GECKO_INFO_PAGE_BTL=1' '-DATTRIBUTE_STORAGE_CONFIGURATION="app/builder/Z3AF2_DEMO/Z3AF2_DEMO_endpoint_config.h"' '-DCORTEXM3_EFR32MG12P332F1024GL125=1' '-DCORTEXM3_EFR32MG12P332F1024GL125_MICRO=1' '-DGENERATED_TOKEN_HEADER="app/builder/Z3AF2_DEMO/Z3AF2_DEMO_tokens.h"' '-DZA_GENERATED_HEADER="app/builder/Z3AF2_DEMO/Z3AF2_DEMO.h"' '-DPLATFORM_HEADER="platform/base/hal/micro/cortexm3/compiler/gcc.h"' '-DEFR32MG12P=1' '-DEFR32MG12P332F1024GL125=1' '-DEFR32_SERIES1_CONFIG2_MICRO=1' '-DHAL_CONFIG=1' '-DEMBER_AF_USE_HWCONF=1' '-DEMBER_AF_API_EMBER_TYPES="stack/include/ember-types.h"' '-DEMBER_AF_API_DEBUG_PRINT="app/framework/util/print.h"' '-DEMBER_AF_API_AF_HEADER="app/framework/include/af.h"' '-DEMBER_AF_API_AF_SECURITY_HEADER="app/framework/security/af-security.h"' '-DEMBER_STACK_ZIGBEE=1' '-DEMLIB_USER_CONFIG=1' '-DEMBER_PARAMETERIZED_BROADCAST_TABLE=1' '-DAPPLICATION_TOKEN_HEADER="app/builder/Z3AF2_DEMO/afv2-token.h"' '-DAPPLICATION_MFG_TOKEN_HEADER="app/builder/Z3AF2_DEMO/afv2-mfg-token.h"' '-DPHY_RAIL=1' -I"D:\soft\SiliconLabs\SimplicityStudio\v4\developer\sdks\gecko_sdk_suite\v2.4\app\builder\Z3AF2_DEMO\hal-config" -I"D:\soft\SiliconLabs\SimplicityStudio\v4\developer\sdks\gecko_sdk_suite\v2.4\app\builder\Z3AF2_DEMO\external-generated-files" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4/" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//plugin" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//micro/cortexm3/efm32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//micro/cortexm3/efm32/config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal//micro/cortexm3/efm32/efr32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../CMSIS/Include" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/common/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/dmadrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/gpiointerrupt/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/rtcdrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/rtcdrv/test" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/sleep/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/spidrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/tempdrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/uartdrv/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emdrv/ustimer/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../emlib/inc" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../middleware/glib" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../middleware/glib/glib" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../radio/rail_lib/plugin" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../radio/rail_lib/chip/efr32/rf/common/cortex" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base//../radio/rail_lib/chip/efr32/rf/rfprotocol/ieee802154/cortex" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/halconfig/inc/hal-config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/module/config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/halconfig" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//hardware/kit/common/bsp" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//app/builder/Z3AF2_DEMO" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//app/builder/Z3AF2_DEMO/hal-config" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/base/hal/micro/cortexm3/efm32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/bootloader/api" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/app/framework" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/stack" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/app/util" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//protocol/zigbee/app/framework/include" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/Device/SiliconLabs/EFR32MG12P/Include" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/bootloader" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/plugin/coexistence/hal/efr32" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/plugin/coexistence/common" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/protocol/zwave" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/protocol/ieee802154" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/protocol/ble" -I"D:/soft/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.4//platform/radio/rail_lib/common" -Os -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"_carelSDK/GeneralApp/led_blink.d" -MT"_carelSDK/GeneralApp/led_blink.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


