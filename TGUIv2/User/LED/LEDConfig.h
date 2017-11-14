#ifndef _LEDCONFIG_H_
#define _LEDCONFIG_H_

//#include "stm32f4xx.h"
#include "includes_all.h"

//��
#define LED_RED  \
					LED_RED_ON();\
					LED_GREEN_OFF();\
					LED_BLUE_OFF()

//��
#define LED_GREEN		\
					LED_RED_OFF();\
					LED_GREEN_ON();\
					LED_BLUE_OFF()

//��
#define LED_BLUE	\
					LED_RED_OFF();\
					LED_GREEN_OFF();\
					LED_BLUE_ON()

					
//��(��+��)					
#define LED_YELLOW	\
					LED_RED_ON();\
					LED_GREEN_ON();\
					LED_BLUE_OFF()
//��(��+��)
#define LED_PURPLE	\
					LED_RED_ON();\
					LED_GREEN_OFF();\
					LED_BLUE_ON()

//��(��+��)
#define LED_CYAN \
					LED_RED_OFF();\
					LED_GREEN_ON();\
					LED_BLUE_ON()
					
//��(��+��+��)
#define LED_WHITE	\
					LED_RED_ON();\
					LED_GREEN_ON();\
					LED_BLUE_ON()
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					LED_RED_OFF();\
					LED_GREEN_OFF();\
					LED_BLUE_OFF()
					
					

extern void LED_RED_Config(void);
extern void LED_GREEN_Config(void);
extern void LED_BLUE_Config(void);

extern void LED_RED_ON(void);
extern void LED_RED_OFF(void);
extern void LED_RED_Toggle(void);
	
extern void LED_GREEN_ON(void);
extern void LED_GREEN_OFF(void);
extern void LED_GREEN_Toggle(void);

extern void LED_BLUE_ON(void);
extern void LED_BLUE_OFF(void);
extern void LED_BLUE_Toggle(void);




#endif // !_LEDCONFIG_H_

