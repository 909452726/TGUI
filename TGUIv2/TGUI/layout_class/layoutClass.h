#ifndef _LAYOUTCLASS_H_
#define _LAYOUTCLASS_H_

#include "winClass.h"

#ifdef __cplusplus
extern "C"  {
#endif

#include "interface_conf/tgui_conf.h"
#include "includes_all.h"
	
#ifdef __cplusplus
}
#endif

//���ִ����� -- ����ؼ�����
class layoutWin
{
public:
	layoutWin(
		rootWin* backWin,	//Ҫ�����ֵĶ���
		uint16_t X,			//��Ҫ���ֵķ�Χ
		uint16_t Y,
		uint16_t Width,
		uint16_t High
	);
	virtual ~layoutWin();

	rootWin* getBackWin(){return backWin;}
	uint16_t getLayoutX(){return layoutX;}
	uint16_t getLayoutY(){return layoutY;}
	uint16_t getLayoutWidth(){return layoutWidth;}
	uint16_t getLayoutHigh(){return layoutHigh;}
	
	uint16_t getHorizGap(){return horizGap;}
	uint16_t getVertGap(){return vertGap;}
	void setHorizGap(uint16_t horizGap){this->horizGap = horizGap;}
	void setVertGap(uint16_t vertGap){this->vertGap = vertGap;}
	virtual void addWin(rootWin* rw) = 0;
private:
	rootWin* backWin;//Ҫ�����ֵĶ���
	uint16_t layoutX;//��Ҫ���ֵķ�Χ
	uint16_t layoutY;
	uint16_t layoutWidth;
	uint16_t layoutHigh;

	uint16_t horizGap; //horizontal��϶
	uint16_t vertGap; //vertical��϶
};

//��ʽ����
class flowLayoutWin:public layoutWin
{
public:
	flowLayoutWin(
		rootWin* backWin,	//Ҫ�����ֵĶ���
		uint16_t X,			//��Ҫ���ֵķ�Χ
		uint16_t Y,
		uint16_t Width,
		uint16_t High,
		uint16_t Hgap,
		uint16_t Vgap
	);
	virtual ~flowLayoutWin();

	virtual void addWin(rootWin* rw);
private:
	uint16_t residualW;//ʣ����
	uint16_t residualH;//ʣ��߶�
	uint16_t maxH; //һ������ĸ�

};

//�߽粼��
class borderLayoutWin:public layoutWin
{
public:
	borderLayoutWin(
		rootWin* backWin,	//Ҫ�����ֵĶ���
		uint16_t X,			//��Ҫ���ֵķ�Χ
		uint16_t Y,
		uint16_t Width,
		uint16_t High
	);
	virtual ~borderLayoutWin();
	virtual void addWin(rootWin* rw);
	void addWin(rootWin* rw,uint16_t seat);
	void setBorderSize(uint16_t northH,uint16_t southH,uint16_t westW,uint16_t eastW);
private:	
	uint16_t northH;
	uint16_t southH;
	uint16_t westW;
	uint16_t eastW;
	uint8_t layoutStat;//����״̬ �Ǽ����Ѿ�������

};

//���񲼾�
class gridLayoutWin:public layoutWin
{
public:
	gridLayoutWin(
		rootWin* backWin,	//Ҫ�����ֵĶ���
		uint16_t X,			//��Ҫ���ֵķ�Χ���λ��
		uint16_t Y,
		uint16_t Width,
		uint16_t High,
		uint8_t  row,
		uint8_t  column
	);
	virtual ~gridLayoutWin();
	virtual void addWin(rootWin* rw);
	void generateGridWH(uint16_t horizGap,uint16_t vertGap);
private:
	uint8_t row; //��
	uint8_t column; //��
	uint8_t currSeat;
	uint16_t gridW;
	uint16_t gridH;
};





#endif //_LAYOUTCLASS_H_

