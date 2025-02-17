/*
 * main.h
 *
 *  Created on: Aug 24, 2024
 *      Author: DELL
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS   5
//some stack memory calculation
#define SIZE_TASK_STACK 1024U

#define SRAM_START      0X20000000U
#define SIZE_SRAM       ((96)*(1024))
#define SRAM_END        ((SRAM_START)+(SIZE_SRAM))

#define T1_stack_START   SRAM_END
#define T2_stack_START     ((SRAM_END)-(1*SIZE_TASK_STACK))
#define T3_stack_START     ((SRAM_END)-(2*SIZE_TASK_STACK))
#define T4_stack_START     ((SRAM_END)-(3*SIZE_TASK_STACK))
#define IDLE_STACK_START  ((SRAM_END)-(4*SIZE_TASK_STACK))
#define SCHED_stack_START  ((SRAM_END)-(5*SIZE_TASK_STACK))

#define TICK_HZ 1000U

#define HSI_CLOCK        16000000U
#define SYSTICK_TIM_CLK    HSI_CLOCK

#define DUMMY_XPSR 0x01000000U

#define TASK_READY_STATE 0X00
#define TASK_BLOCKED_STATE 0xFF

#define INTERRUPT_DISABLE() do{__asm volatile("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)
#define INTERRUPT_ENABLE() do{__asm volatile("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)

#endif /* MAIN_H_ */
