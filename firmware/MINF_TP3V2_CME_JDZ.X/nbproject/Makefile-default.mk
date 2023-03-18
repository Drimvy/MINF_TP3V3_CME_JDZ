#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/Generateur.c ../src/GesPec12.c ../src/Mc32NVMUtil.c ../src/Mc32SpiUtil.c ../src/Mc32gestSPiDac.c ../src/MenuGen.c ../src/Mc32Debounce.c ../../../../../../bsp/pic32mx_skes/bsp.c ../../../../../../bsp/pic32mx_skes/Mc32Delays.c ../../../../../../bsp/pic32mx_skes/Mc32DriverAdc.c ../../../../../../bsp/pic32mx_skes/Mc32DriverAdcAlt.c ../../../../../../bsp/pic32mx_skes/Mc32DriverLcd.c ../../../../../../bsp/pic32mx_skes/Mc32CoreTimer.c ../../../../../../framework/system/int/src/sys_int_pic32.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/Generateur.o ${OBJECTDIR}/_ext/1360937237/GesPec12.o ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o ${OBJECTDIR}/_ext/1360937237/MenuGen.o ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o ${OBJECTDIR}/_ext/326400065/bsp.o ${OBJECTDIR}/_ext/326400065/Mc32Delays.o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/Generateur.o.d ${OBJECTDIR}/_ext/1360937237/GesPec12.o.d ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o.d ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o.d ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o.d ${OBJECTDIR}/_ext/1360937237/MenuGen.o.d ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o.d ${OBJECTDIR}/_ext/326400065/bsp.o.d ${OBJECTDIR}/_ext/326400065/Mc32Delays.o.d ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o.d ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o.d ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o.d ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o.d ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/Generateur.o ${OBJECTDIR}/_ext/1360937237/GesPec12.o ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o ${OBJECTDIR}/_ext/1360937237/MenuGen.o ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o ${OBJECTDIR}/_ext/326400065/bsp.o ${OBJECTDIR}/_ext/326400065/Mc32Delays.o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o

# Source Files
SOURCEFILES=../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/app.c ../src/main.c ../src/Generateur.c ../src/GesPec12.c ../src/Mc32NVMUtil.c ../src/Mc32SpiUtil.c ../src/Mc32gestSPiDac.c ../src/MenuGen.c ../src/Mc32Debounce.c ../../../../../../bsp/pic32mx_skes/bsp.c ../../../../../../bsp/pic32mx_skes/Mc32Delays.c ../../../../../../bsp/pic32mx_skes/Mc32DriverAdc.c ../../../../../../bsp/pic32mx_skes/Mc32DriverAdcAlt.c ../../../../../../bsp/pic32mx_skes/Mc32DriverLcd.c ../../../../../../bsp/pic32mx_skes/Mc32CoreTimer.c ../../../../../../framework/system/int/src/sys_int_pic32.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  .generated_files/ff6fd0dbf0a0fa15119e92fe28b4e8b672f29925.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  .generated_files/528be2c9bc1df87820830922c4bc656e52dda184.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  .generated_files/515a8244f73e74687f73dc105cfab95f73399ce9.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/b32bfab2809aec4cb1572f646629825a0c84dbfb.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  .generated_files/a42cc94e66392bc27805968d648418d82678ca3f.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/f8be2d1b904b6ea9df8fde27d9f981b5bf05cf29.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/a164030317cd1a83f93f6d177562976451b8304d.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/aad2c059977ae7243d12d0a9bc3bac109ba70d75.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/fb711c2d8bb21453376293a5257b3a9a62c378ed.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/cad820e5e7b98be71a36ee100de9aeff4a0778c8.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/b2f28312a882526541245c1d5316640ecc52a06c.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/b172a1f984f223140877c24a4e6228509c887f08.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Generateur.o: ../src/Generateur.c  .generated_files/7334aa1b4441a61b4581e8d37661e3f45a35146f.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Generateur.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Generateur.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Generateur.o.d" -o ${OBJECTDIR}/_ext/1360937237/Generateur.o ../src/Generateur.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/GesPec12.o: ../src/GesPec12.c  .generated_files/fc8494c1d19bf0c5cd6be5f37dda4e4345fbc1f7.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesPec12.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesPec12.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GesPec12.o.d" -o ${OBJECTDIR}/_ext/1360937237/GesPec12.o ../src/GesPec12.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o: ../src/Mc32NVMUtil.c  .generated_files/af926b8244f6b2dd6fd0fc2f59bd58ce3e7f8f13.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o ../src/Mc32NVMUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o: ../src/Mc32SpiUtil.c  .generated_files/babd188562ea54464260ae2d2345dd117fd1ccdc.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o ../src/Mc32SpiUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o: ../src/Mc32gestSPiDac.c  .generated_files/dcff086bca782156e7676e0db039a5770ab917f2.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o ../src/Mc32gestSPiDac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/MenuGen.o: ../src/MenuGen.c  .generated_files/310d1b8ad53ba8e463169427d4f18d7265f90d38.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MenuGen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MenuGen.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/MenuGen.o.d" -o ${OBJECTDIR}/_ext/1360937237/MenuGen.o ../src/MenuGen.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o: ../src/Mc32Debounce.c  .generated_files/6eb68389cacba323c9c99c92f690e7e9de4247c1.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o ../src/Mc32Debounce.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/bsp.o: ../../../../../../bsp/pic32mx_skes/bsp.c  .generated_files/7cf9a4ea28e8d274d5ab9727a31e4fe98658a54c.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/bsp.o.d" -o ${OBJECTDIR}/_ext/326400065/bsp.o ../../../../../../bsp/pic32mx_skes/bsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32Delays.o: ../../../../../../bsp/pic32mx_skes/Mc32Delays.c  .generated_files/f30557605254a9f31a8ea3554fe46df1d8717769.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32Delays.o ../../../../../../bsp/pic32mx_skes/Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o: ../../../../../../bsp/pic32mx_skes/Mc32DriverAdc.c  .generated_files/a0c1901ae8a9856bf0a9a6679397ac58467b95b9.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o ../../../../../../bsp/pic32mx_skes/Mc32DriverAdc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o: ../../../../../../bsp/pic32mx_skes/Mc32DriverAdcAlt.c  .generated_files/5edbe293a2b9afb3573b4c4264a6f2c5a2d9ca2.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o ../../../../../../bsp/pic32mx_skes/Mc32DriverAdcAlt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o: ../../../../../../bsp/pic32mx_skes/Mc32DriverLcd.c  .generated_files/8959dc2cce11db00cdfe3d915b4b9a2548293263.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o ../../../../../../bsp/pic32mx_skes/Mc32DriverLcd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o: ../../../../../../bsp/pic32mx_skes/Mc32CoreTimer.c  .generated_files/48f0df2250fdd0de7c089c0dcb1f56db386e20b1.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o ../../../../../../bsp/pic32mx_skes/Mc32CoreTimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/711155467/sys_int_pic32.o: ../../../../../../framework/system/int/src/sys_int_pic32.c  .generated_files/fa2a6a54c937dd92431f80ab466afd9233ca1a26.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/711155467" 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ../../../../../../framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  .generated_files/9dec73b1241792fe95a5e1a3c4bcfc80f8a616ca.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  .generated_files/ea9b82cb7630c92d3673da1de06654c28ba9e82d.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  .generated_files/a804c0dd0152a0ba0df8f349e0a4bd383b657865.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/734f13f3534940ce0b3199adeab97898e7eb1a7e.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  .generated_files/40376e9f14f8e6e6a0d5cb644ce0f330f07c5d1c.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/af98ebfcd37b8e11f4d3da088b67b14b1295c6a.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/40aa720e934d18a9d4771894999545fe58fedaaf.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/d585aea7942f6e689c4dd8d5278fcae7de632858.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/1103d07ebe346320cf213cfd61b7df1492c0d8be.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/36ec702e3a0130ebd073ce9744429237b4411aa5.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/d7672f07a8d2033f7a242d6f070c356147266c7e.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/94ab3c5a4efa7881f95e79e6df3a5242d8280de4.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Generateur.o: ../src/Generateur.c  .generated_files/8969c3c9bcd31a4c757baae4e132e043223b49fb.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Generateur.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Generateur.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Generateur.o.d" -o ${OBJECTDIR}/_ext/1360937237/Generateur.o ../src/Generateur.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/GesPec12.o: ../src/GesPec12.c  .generated_files/d025cdde931cee91b5bd238120f939a99199f56d.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesPec12.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GesPec12.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GesPec12.o.d" -o ${OBJECTDIR}/_ext/1360937237/GesPec12.o ../src/GesPec12.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o: ../src/Mc32NVMUtil.c  .generated_files/51842de7802c4f418c3eb914962ec0279190883d.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32NVMUtil.o ../src/Mc32NVMUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o: ../src/Mc32SpiUtil.c  .generated_files/edf3e2a21b41a9bd325c5c0affe9d28baab857ed.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32SpiUtil.o ../src/Mc32SpiUtil.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o: ../src/Mc32gestSPiDac.c  .generated_files/c9322160868b81f155bb32f4da84302667b88c2.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32gestSPiDac.o ../src/Mc32gestSPiDac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/MenuGen.o: ../src/MenuGen.c  .generated_files/bccbae1022dc2d997e17658587623825c3a4a87b.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MenuGen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MenuGen.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/MenuGen.o.d" -o ${OBJECTDIR}/_ext/1360937237/MenuGen.o ../src/MenuGen.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o: ../src/Mc32Debounce.c  .generated_files/5ce34faa3ea23e303676dba09f6c9f776b4b59be.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o.d" -o ${OBJECTDIR}/_ext/1360937237/Mc32Debounce.o ../src/Mc32Debounce.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/bsp.o: ../../../../../../bsp/pic32mx_skes/bsp.c  .generated_files/522bc16fe19594fb108054ba34fdf84bbc3e01de.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/bsp.o.d" -o ${OBJECTDIR}/_ext/326400065/bsp.o ../../../../../../bsp/pic32mx_skes/bsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32Delays.o: ../../../../../../bsp/pic32mx_skes/Mc32Delays.c  .generated_files/f8a06dfc9e61cd7cbec0fde54fcb77815198644d.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32Delays.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32Delays.o ../../../../../../bsp/pic32mx_skes/Mc32Delays.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o: ../../../../../../bsp/pic32mx_skes/Mc32DriverAdc.c  .generated_files/3a48c5dbfa5d6293ec725fac1eaf7d0f21735a74.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdc.o ../../../../../../bsp/pic32mx_skes/Mc32DriverAdc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o: ../../../../../../bsp/pic32mx_skes/Mc32DriverAdcAlt.c  .generated_files/20eab82d93f9588cfb39fa2d4f08e016fb283b90.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32DriverAdcAlt.o ../../../../../../bsp/pic32mx_skes/Mc32DriverAdcAlt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o: ../../../../../../bsp/pic32mx_skes/Mc32DriverLcd.c  .generated_files/ea80201dec74a7aeed8b1865a0a0266bd039d11c.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32DriverLcd.o ../../../../../../bsp/pic32mx_skes/Mc32DriverLcd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o: ../../../../../../bsp/pic32mx_skes/Mc32CoreTimer.c  .generated_files/a68d1ecc09589b97ea497493ce935e10cb4e2db1.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/326400065" 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o.d" -o ${OBJECTDIR}/_ext/326400065/Mc32CoreTimer.o ../../../../../../bsp/pic32mx_skes/Mc32CoreTimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/711155467/sys_int_pic32.o: ../../../../../../framework/system/int/src/sys_int_pic32.c  .generated_files/e9e8a255dcd181d6cf088a5a07bf13f827858548.flag .generated_files/9c38dd73fa47c8727ca672a3ac38932765b77050.flag
	@${MKDIR} "${OBJECTDIR}/_ext/711155467" 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../framework" -I"../src/system_config/default/framework" -I"../../../../../../bsp/pic32mx_skes" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ../../../../../../framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../bin/framework/peripheral/PIC32MX795F512L_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\bin\framework\peripheral\PIC32MX795F512L_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../bin/framework/peripheral/PIC32MX795F512L_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\bin\framework\peripheral\PIC32MX795F512L_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MINF_TP3V2_CME_JDZ.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
