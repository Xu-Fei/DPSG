#include "stdafx.h" 
#include "DPSG/ROI_DPSGII.h"
#include "DPSG/CG.h"
#include "math.h"
StepStrucureII g_oDistense64D[65]={
{0,0,0.0},          //����
{1,0,1.0},          //64D-1��λ 
{8,-1,8.062257748}, //64D-2��λ
{4,-1,4.123105626}, //64D-3��λ
{8,-3,8.544003745}, //64D-4��λ 
{2,-1,2.236067977}, //64D-5��λ 
{8,-5,9.433981132}, //64D-6��λ 
{4,-3,5.0},         //64D-7��λ 
{8,-7,10.63014581}, //64D-8��λ 
{1,-1,1.414213562}, //64D-9��λ 
{7,-8,10.63014581}, //64D-10��λ 
{3,-4,5.0},         //64D-11��λ 
{5,-8,9.433981132}, //64D-12��λ 
{1,-2,2.236067977}, //64D-13��λ 
{3,-8,8.544003745}, //64D-14��λ 
{1,-4,4.123105626}, //64D-15��λ 
{1,-8,8.062257748}, //64D-16��λ 
{0,-1,1.0},         //64D-17��λ 
{-1,-8,8.062257748},//64D-18��λ 
{-1,-4,4.123105626},//64D-19��λ 
{-3,-8,8.544003745},//64D-20��λ 
{-1,-2,2.236067977},//64D-21��λ 
{-5,-8,9.433981132},//64D-22��λ 
{-3,-4,5.0},        //64D-23��λ 
{-7,-8,10.63014581},//64D-24��λ 
{-1,-1,1.414213562},//64D-25��λ 
{-8,-7,10.63014581},//64D-26��λ 
{-4,-3,5.0},        //64D-27��λ 
{-8,-5,9.433981132},//64D-28��λ 
{-2,-1,2.236067977},//64D-29��λ 
{-8,-3,8.544003745},//64D-30��λ 
{-4,-1,4.123105626},//64D-31��λ 
{-8,-1,8.062257748},//64D-32��λ 
{-1,0,1.0},         //64D-33��λ 
{-8,1,8.062257748}, //64D-34��λ 
{-4,1,4.123105626}, //64D-35��λ 
{-8,3,8.544003745}, //64D-36��λ 
{-2,1,2.236067977}, //64D-37��λ 
{-8,5,9.433981132}, //64D-38��λ 
{-4,3,5.0},         //64D-39��λ 
{-8,7,10.63014581}, //64D-40��λ 
{-1,1,1.414213562}, //64D-41��λ 
{-7,8,10.63014581}, //64D-42��λ 
{-3,4,5.0},         //64D-43��λ 
{-5,8,9.433981132}, //64D-44��λ 
{-1,2,2.236067977}, //64D-45��λ 
{-3,8,8.544003745}, //64D-46��λ 
{-1,4,4.123105626}, //64D-47��λ 
{-1,8,8.062257748}, //64D-48��λ 
{0,1,1.0},          //64D-49��λ 
{1,8,8.062257748},  //64D-50��λ 
{1,4,4.123105626},  //64D-51��λ 
{3,8,8.544003745},  //64D-52��λ 
{1,2,2.236067977},  //64D-53��λ 
{5,8,9.433981132},  //64D-54��λ 
{3,4,5.0},          //64D-55��λ 
{7,8,10.63014581},  //64D-56��λ 
{1,1,1.414213562},  //64D-57��λ 
{8,7,10.63014581},  //64D-58��λ 
{4,3,5.0},          //64D-59��λ 
{8,5,9.433981132},  //64D-60��λ 
{2,1,2.236067977},  //64D-61��λ 
{8,3,8.544003745},  //64D-62��λ 
{4,1,4.123105626},  //64D-63��λ 
{8,1,8.062257748},  //64D-64��λ 
};
struct StartThrumInfo StartThrum[CURVEMAXNUM]={0};//
struct FeaturePointInfo FeaturePoint[CURVEMAXNUM];// ����������
struct ThrumInfo ThrumGroup[THRUMMAXNUM];
struct CurveInfo CurveGroup[CURVEMAXNUM];
struct StartThrumInfo StartThrumTemp;//
struct ThrumInfo ThrumTemp;
struct LINE LineGroup[LINENUM];
struct LINESEG LineSegGroup[LINENUM];
struct ThrumInfo LineConnect[LINENUM];
struct ThrumInfo LineParallel[LINENUM];
StepStrucureII LinePara[LINENUM]={0};//x��Ӧֱ������������ţ�y��Ӧֱ����ţ�stepdistense��Ӧб��
int StartThrumNum;//��ʼ�߶����
int FeaturePointNum;//���������
int ThrumNum;//�߶����
int CurveNum;//�������
int LineNum;//ֱ�����
int ConLineNum;//�����߶����
int ParallelLineNum;//ƽ��ֱ�����

unsigned short MaxCurveGroup[MAXCURVENUM][2]={0};//���������[][0]���,[][1]����
unsigned short CircleGroup[CIRCLENUM][4]={0};//Բ����[][0]���,[][1]�뾶��[][2]Բ�ĺ����꣬[][3]Բ��������
unsigned char CircleII[192]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63}; 
////////////////////////////////////////////////////////////////////////
//	�� �� ����DPSGII.cc
//	�ļ����ܣ�����Ȥ������ȡ�����ļ��������ڵڶ�����ɢ������ͱ��鷽��,����ֱ�߶μ�����̽��
//	��    �ߣ�������
//	����ʱ�䣺2012��3��27��
//	��Ŀ���ƣ�Ŀ����ʶ���㷨��������ƽ̨
//	����ϵͳ��Windows 7
//	��    ע�� 
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	�������ļ�
//	1	2010��3��27��	������	������  int DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//  2   2010��3��27��	������  ������  unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)   
//  3   2010��3��27��	������  ������  unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)                    
//  4   2010��3��27��	������  ������  unsigned char* DPSGII_SquaYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)                    
//  5   2010��3��27��	������  ������  void DPSGII_YinYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	�� �� ����int DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//	�������ܣ�����ָ����Χ�ڻҶȺ�(����������ҶȾ�ֵ)
//  �������̣�
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ����� 
//	��    �ߣ�������
//	ʱ    �䣺2012��3��27��
//	�� �� ֵ��grayRtotalָ����Χ�ڻҶȺ�
//	��ڲ���˵����
//	1.unsigned char * Img_gray��������ĻҶ�ͼ����
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int StartX��ָ����Χ��ʼ�������
//  5.int StartY��ָ����Χ��ʼ��������
//  6.int EndX��ָ����Χ�����������
//  7.int EndY��ָ����Χ������������
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	����������
//	////////////////////////////////////////////////////////////////////////
int DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
{
	int grayRtotal=0;
	int j=0;
	int i=0;
	if(StartX>EndX||StartY>EndY)
	{return 0;}
	if(StartX>EndX)//����������
	{
		i=StartX;
		StartX=EndX;
		EndX=i;
	}
	if(StartY>EndY)//����������
	{
		j=StartY;
		StartY=EndY;
		EndY=j;
	}
	//����Rin��Ȧ�Ҷ�֮��ƽ��ֵ
	for(j=StartY;j<EndY+1;j++)
		{
			for(i=StartX;i<EndX+1;i++)
			{
				grayRtotal+=((unsigned char*)(Img_gray + nWidth*j))[i];
			}
		}

	return grayRtotal;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	�� �� ����StepStrucureII DPSGII_RectDistri(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//	�������ܣ�ͳ��ָ����Χ�ڲ�������ռ�������
//  �������̣�
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ����� 
//	��    �ߣ�������
//	ʱ    �䣺2012��3��27��
//	�� �� ֵ��StepStrucureII RectDistriָ����Χ�ڲ�������ռ�������
//	��ڲ���˵����
//	1.unsigned char * Img_gray��������ĻҶ�ͼ����
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int StartX��ָ����Χ��ʼ�������
//  5.int StartY��ָ����Χ��ʼ��������
//  6.int EndX��ָ����Χ�����������
//  7.int EndY��ָ����Χ������������
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	����������
//	////////////////////////////////////////////////////////////////////////
StepStrucureII DPSGII_RectDistri(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
{
	StepStrucureII RectDistri={0};
	int j=0;
	int i=0;
	RectDistri.ystep=1;
	if(StartX>EndX)//����������
	{
		i=StartX;
		StartX=EndX;
		EndX=i;
	}
	if(StartY>EndY)//����������
	{
		j=StartY;
		StartY=EndY;
		EndY=j;
	}
	//����Rin��Ȧ�Ҷ�֮��ƽ��ֵ
	for(j=StartY;j<EndY+1;j++)
	{
		for(i=StartX;i<EndX+1;i++)
		{
			RectDistri.xstep+=((unsigned char*)(Img_gray + nWidth*j))[i];//���λҶȺ�
			RectDistri.ystep++;//��ɾ��ε���
		}
	}
	RectDistri.xstep=RectDistri.ystep-RectDistri.xstep/255;//�ڵ����
	RectDistri.stepdistense=(double)RectDistri.xstep/RectDistri.ystep;//�ڵ����
	return RectDistri;
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//	�������ܣ������������������
//  �������̣�ͨ��������ɢ����Χ�ľ������趨����ɢ�������㻹�����㡣
//  ���к�������
//  ���ú�����DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺20102��3��27��
//	�� �� ֵ���������� 255�������㣬0��������
//	��ڲ���˵�� ��
//	1.unsigned char* Img_gray��������ĻҶ�ͼ
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int cenX�������������
//  5.int cenY��������������
//  6.int Rin���ڻ��뾶
//  7.int Rout���⻷�뾶
//  8.int nWeberCoeft��Τ��ϵ��
//  9.int WeberCoefRatio:Τ��ϵ����������,�ò�����һ���Ҷ�ֵ,�ڻ����ȵ��ڴ˻Ҷ�������/��СΤ��ϵ��
//  10.int ABSSign//�Ƿ���þ���ֵ����
//  11.int &YinCounter//�������������
//  12.int &YangCounter//�������������
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	����������
//	////////////////////////////////////////////////////////////////////////
unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	int grayRinTotal=0;
	int grayRoutTotal=0;
	int graySub=0;
	double FloatnWeberCoef=0.0;
	grayRinTotal=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,cenX-Rin,cenY-Rin,cenX+Rin,cenY+Rin)*((Rout<<1)+1)*((Rout<<1)+1);//�ڻ��Ҷ�֮�ͳ������ϵ��
    grayRoutTotal= RoutTotal*(2*Rin+1)*(2*Rin+1);//�⻷�Ҷ�֮�ͳ������ϵ��
	FloatnWeberCoef=(WeberCoefRatio*(2*Rin+1)*(2*Rin+1)*((Rout<<1)+1)*((Rout<<1)+1))/(double)grayRinTotal;
	if(WeberCoefRatio!=0&&FloatnWeberCoef>1.0)
	{
		FloatnWeberCoef=nWeberCoef*FloatnWeberCoef;
	}
	else
	{
		FloatnWeberCoef=(double)nWeberCoef;
	}
	if(ABSSign==0)
	{
		graySub=grayRinTotal-grayRoutTotal;
	}
	else
	{
		graySub=abs(grayRinTotal-grayRoutTotal);

	}
	if((graySub*100)>(FloatnWeberCoef*grayRoutTotal))//���⻷��ֵ֮������⻷��ֵ
	{
		YinCounter++;
		return 255;//Yin
	}
	else 
	{
		YangCounter++;
		return 0;//Yang
	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//	�������ܣ�ʵ�ֻҶ�ͼ������
//  �������̣�
//  ���к�������
//  ���ú�����unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺2012��3��27��
//	�� �� ֵ��unsigned char* YYBin ������ͼ
//	��ڲ���˵����
//	1.unsigned char* Img_gray��������ĻҶ�ͼ
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int Rin���ڻ��뾶
//  5.int Rout���⻷�뾶
//  6.int nWeberCoeft��Τ��ϵ��
//  7.int WeberCoefRatio:Τ��ϵ����������
//  8.int ABSSign
//  9.int &YinCounter
//  10.int &YangCounter
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	����������
//	////////////////////////////////////////////////////////////////////////
unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	unsigned char*	YYBin=new unsigned char[nWidth*nHeight];
	int x=0;
	int y=0;
    int grayTotalTemp=0;//�⻷�ҶȺ�
	int grayPartOne=0;//�Ƴ������ҶȺ�
	int grayPartTwo=0;//���������ҶȺ�
	memset(YYBin,255,nWidth*nHeight*sizeof(char));
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		x=(int)Rout;
		
		grayTotalTemp=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout,y-Rout,x+Rout,y+Rout);
		((unsigned char*)(YYBin + nWidth*(y)))[x]=~(DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter));
		for(x=(int)Rout+Rin;x<nWidth-Rout;x+=Rin)
		{
			grayPartOne=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout-Rin,y-Rout,x-Rout-1,y+Rout);
			grayPartTwo=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x+Rout-Rin+1,y-Rout,x+Rout,y+Rout);
			grayTotalTemp=grayTotalTemp-grayPartOne+grayPartTwo;
			((unsigned char*)(YYBin + nWidth*(y)))[x]=~(DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter));
		}
	}
	return YYBin;
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����unsigned char*DPSGII_SquaYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//	�������ܣ�ʵ�ֻҶ�ͼ������
//  �������̣�
//  ���к�������
//  ���ú�����unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺2012��3��27��
//	�� �� ֵ��unsigned char* YYBin ������ͼ
//	��ڲ���˵����
//	1.unsigned char* Img_gray��������ĻҶ�ͼ
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int Rin���ڻ��뾶
//  5.int Rout���⻷�뾶
//  6.int nWeberCoeft��Τ��ϵ��
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	����������
//	////////////////////////////////////////////////////////////////////////
unsigned char* DPSGII_SquaYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	unsigned char*	YYBin=new unsigned char[nWidth*nHeight];
	int x=0;
	int y=0;
	int grayTotalTemp=0;//�⻷�ҶȺ�
	int grayPartOne=0;//�Ƴ������ҶȺ�
	int grayPartTwo=0;//���������ҶȺ�
	memset(YYBin,255,nWidth*nHeight*sizeof(char));
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		x=(int)Rout;
		
		grayTotalTemp=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout,y-Rout,x+Rout,y+Rout);
		((unsigned char*)(YYBin + nWidth*(y)))[x]=~(DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter));
		for(x=(int)Rout+Rin;x<nWidth-Rout;x+=Rin)
		{
			grayPartOne=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout-Rin,y-Rout,x-Rout-1,y+Rout);
			grayPartTwo=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x+Rout-Rin+1,y-Rout,x+Rout,y+Rout);
			grayTotalTemp=grayTotalTemp-grayPartOne+grayPartTwo;
			((unsigned char*)(YYBin + nWidth*(y)))[x]=DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter);
		}
	}
	return YYBin;
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����void DPSGII_YinYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//	�������ܣ�ʵ�ֻҶ�ͼ����ͬʱ����
//  �������̣�
//  ���к�������
//  ���ú�����unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺2012��3��27��
//	�� �� ֵ��YinMap������ͼ YangMap������ͼ
//	��ڲ���˵����
//	1.unsigned char* Img_gray��������ĻҶ�ͼ
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int Rin���ڻ��뾶
//  5.int Rout���⻷�뾶
//  6.int nWeberCoeft��Τ��ϵ��
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��27��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_YinYangSampleFast(unsigned char* Img_gray, unsigned char* &g_pYinMap,unsigned char* &g_pYangMap,int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	int x=0;
	int y=0;
	int grayTotalTemp=0;//�⻷�ҶȺ�
	int grayPartOne=0;//�Ƴ������ҶȺ�
	int grayPartTwo=0;//���������ҶȺ�
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		x=(int)Rout;
		grayTotalTemp=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout,y-Rout,x+Rout,y+Rout);
		((unsigned char*)(g_pYangMap + nWidth*(y)))[x]=DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter);
		((unsigned char*)(g_pYinMap + nWidth*(y)))[x]=~(((unsigned char*)(g_pYangMap + nWidth*(y)))[x]);
		for(x=(int)Rout+Rin;x<nWidth-Rout;x+=Rin)
		{
			grayPartOne=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout-Rin,y-Rout,x-Rout-1,y+Rout);
			grayPartTwo=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x+Rout-Rin+1,y-Rout,x+Rout,y+Rout);
			grayTotalTemp=grayTotalTemp-grayPartOne+grayPartTwo;
			((unsigned char*)(g_pYangMap + nWidth*(y)))[x]=DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter);
			((unsigned char*)(g_pYinMap + nWidth*(y)))[x]=~(((unsigned char*)(g_pYangMap + nWidth*(y)))[x]);
		}
	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����int DPSGII_DPAdnate8Check(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
//	�������ܣ�����Img_binָ�������ͨ��
//  �������̣�
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �� ��������
//	ʱ    �� ��2012��3��28��
//	�� �� ֵ ����ͨ�� 0-8
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth��������Ķ�ֵͼ������
//  3.int nHeight��������Ķ�ֵͼ����߶�
//	4.int R����ֵͼ�����뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
//	////////////////////////////////////////////////////////////////////////
int DPSGII_DPAdnate8Check(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
{
	if(cenX<R||cenY<R||(cenX+R)>=nWidth||(cenY+R)>=nHeight)
	{return 0x0;}
	//8����ͨ��֮��
	unsigned int AdnateTotal=
		((unsigned char*)(Img_bin + nWidth*(cenY)))[cenX-R]//��
	+   ((unsigned char*)(Img_bin + nWidth*(cenY)))[cenX+R]//��
	+	((unsigned char*)(Img_bin + nWidth*(cenY-R)))[cenX]//��
	+	((unsigned char*)(Img_bin + nWidth*(cenY-R)))[cenX-R]//����
	+	((unsigned char*)(Img_bin + nWidth*(cenY-R)))[cenX+R]//����	
	+	((unsigned char*)(Img_bin + nWidth*(cenY+R)))[cenX]//��
	+	((unsigned char*)(Img_bin + nWidth*(cenY+R)))[cenX-R]//����
	+	((unsigned char*)(Img_bin + nWidth*(cenY+R)))[cenX+R];//����	
	return 8-AdnateTotal/255;//0,1,2,3,4,5,6,7��8
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����bool DPSGII_DPSignCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
//	�������ܣ��ж��������Ƿ��кڵ�
//  �������̣�
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �� ��������
//	ʱ    �� ��2012��9��9��
//	�� �� ֵ ���������кڵ㷵��0,ȫ�׷���1
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth��������Ķ�ֵͼ������
//  3.int nHeight��������Ķ�ֵͼ����߶�
//  4.int cenX�����������ĵ������
//  5.int cenY�����������ĵ�������
//	6.int R����ֵͼ�����뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��9��9��	������	����������
//	////////////////////////////////////////////////////////////////////////
bool DPSGII_DPSignCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
{
	int j=0;
	int i=0;
	bool BlackSing=0; 
	for(j=cenY-R;j<=cenY+R;j++)
	{
		for(i=cenX-R;i<=cenX+R;i++)
		{
				if(((unsigned char*)(Img_bin + nWidth*j))[i]!=255)
				{
					return 0;
				}
		}
	}

	return  1;
	
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����void DPSGII_DPAdnateValueFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int R, int Value)
//	�������ܣ�����ɢ������õ�����������ͼ����ͨ�Խ����˲�
//  �������̣���ͨ�Դ��ڵ���Value�Ĳ��ڵ㣬С��Value��ȥ��
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺2010��4��26��
//	�� �� ֵ����
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth��������Ķ�ֵͼ������
//  3.int nHeight��������Ķ�ֵͼ����߶�
//	4.int R����ֵͼ�����뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
///////////////////////////////////////////////////////////////////////////
int DPSGII_DPAdnateValueFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout,int Value)
{ 
	int y=0;
    int x=0;
	int PointChange=0;
	unsigned char*TempMapNow=new unsigned char[nWidth*nHeight];
	memcpy(TempMapNow,Img_bin,nWidth*nHeight*sizeof(unsigned char));
	//ThrumInfo LineSegTemp;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=Value))//����
			{
				
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=0;
					PointChange++;
					
				
			}
		
			else if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=255)&&(DPSGII_DPAdnate8Check(TempMapNow,nWidth,nHeight,x,y,Rin)<Value))
			{
				{
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=255;
					PointChange--;
				
				}
			}
		}
    }
	delete TempMapNow;
	return PointChange;
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����int DPSGII_DPYinYangFilterR(unsigned char* Img_bin,unsigned char* Img_bin2,int nWidth,int nHeight,int Rin, int Rout,int Value)
//	�������ܣ���������ͼͬʱ�˲�
//  �������̣�
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �� ��������
//	ʱ    �� ��2012��9��9��
//	�� �� ֵ ��PointChange��ɢ��������Ŀ
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ1��
//	2.unsigned char* Img_bin2��������Ķ�ֵͼ2
//  3.int nWidth��������Ķ�ֵͼ������
//  4.int nHeight��������Ķ�ֵͼ����߶�
//  5.int Rin�������뾶
//  6.int Rout���⻷�뾶
//	7.int Value���˲���ֵ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��9��9��	������	����������
//	////////////////////////////////////////////////////////////////////////
int DPSGII_DPYinYangFilterR(unsigned char* Img_bin,unsigned char* Img_bin2,int nWidth,int nHeight,int Rin,  int Rout,int Value)
{ 
	int y=0;
    int x=0;
	int PointChange=0;
	unsigned char*TempMapNow=new unsigned char[nWidth*nHeight];
	memcpy(TempMapNow,Img_bin,nWidth*nHeight*sizeof(unsigned char));
	//ThrumInfo LineSegTemp;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=Value))//����
			{
				
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=0;
					((unsigned char*)(Img_bin2 + nWidth*(y)))[x]=255;
					PointChange++;
					
				
			}
		
			else if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=255)&&(DPSGII_DPAdnate8Check(TempMapNow,nWidth,nHeight,x,y,Rin)<Value))
			{
				{
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=255;
					((unsigned char*)(Img_bin2 + nWidth*(y)))[x]=0;
					PointChange--;
				
				}
			}
		}
    }
	delete TempMapNow;
	return PointChange;
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����int DPSGII_DPAdnateNCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R,int N)
//	�������ܣ������ɢ�����ͼN���뾶��Χ����ͨ��
//  �������̣�
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺2010��4��26��
//	�� �� ֵ����
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth��������Ķ�ֵͼ������
//  3.int nHeight��������Ķ�ֵͼ����߶�
//  4.int cenX�����������ĵ������
//  5.int cenY�����������ĵ�������
//	6.int R����ֵͼ�����뾶
//	7.int N��N���뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
///////////////////////////////////////////////////////////////////////////
int DPSGII_DPAdnateNCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R,int N)
{
	if(cenX<N*R||cenY<N*R||(cenX+N*R)>=nWidth||(cenY+N*R)>=nHeight)
	{return 0x0;}
	unsigned int AdnateTotal=0;
	int n=0;
	for (int i=cenX-N*R;i<=cenX+N*R;i+=R)
	{
		for (int j=cenY-N*R;j<=cenY+N*R;j+=R)
		{
			if (i>=cenX-(N-1)*R && i<=cenX+(N-1)*R && j>=cenY-(N-1)*R && j<=cenY+(N-1)*R)
			{			
			}
			else
			{
				n++;
				AdnateTotal+=((unsigned char*)(Img_bin + nWidth*j))[i];
			}
		}
	}
	return 8*N-AdnateTotal/255;
}
////////////////////////////////////////////////////////////////////////
//	�� �� ����int DPSGII_DPFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout, int N)
//	�������ܣ�����ɢ������õ�����������ͼ�����뾶��Χ��ͨ�Խ����
//  �������̣���ͨ�Դ��ڵ���Value���
//  ���к�������
//  ���ú�������
//  ������������
//  ����ĵ���Object detection based on multi-scale discrete points sampling and grouping.doc 
//	��    �ߣ�������
//	ʱ    �䣺2012��9��9��
//	�� �� ֵ����
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth��������Ķ�ֵͼ������
//  3.int nHeight��������Ķ�ֵͼ����߶�
//  4.int Rin�������뾶
//  5.int Rout���⻷�뾶
//	6.int N��N���뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��9��9��	������	����������
///////////////////////////////////////////////////////////////////////////
int DPSGII_DPFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout, int N)
{ 
	int y=0;
	int x=0;
	int PointChange=0;
	unsigned char * TempMapNow=new unsigned char[nWidth*nHeight];
	memcpy(TempMapNow,Img_bin,nWidth*nHeight);
	bool flag=false;
	int M=N;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			
			if(((unsigned char*)(TempMapNow + nWidth*(y)))[x]==255)
			{
				flag=false;
				M=N;
				for (int i=N;i>=1;i--)
				{
					if (DPSGII_DPAdnateNCheck(TempMapNow,nWidth,nHeight,x,y,Rin,i)==8*i)
					{
						flag=true;
						M=i;
						break;
					}
				}
				
				if (flag)
				{
					//�
					for (int i=x-M*Rin;i<=x+M*Rin;i+=Rin)
					{
						for (int j=y-M*Rin;j<=y+M*Rin;j+=Rin)
						{
							if(((unsigned char*)(Img_bin + nWidth*j))[i]==255)
							{
								PointChange++;
							}
							((unsigned char*)(Img_bin + nWidth*j))[i]=0;
						}
					}
				}
				
			}
		}

	}
	delete []TempMapNow;
	return PointChange;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int SEG_CHAR_YPositionLine(int StartX,int StartY,int EndX, int EndY,int SetX)
//	�������� ����ֱ֪��������͵���������꣬��������
//  �������� ����������ֱ�߹�ʽ����
//  ���к��� ��
//  ���ú��� ��
//  �������� ��
//  ����ĵ� ����
//	��    �� ��������
//	ʱ    �� ��2010��6��9��
//	�� �� ֵ ��
//	��ڲ���˵�� ��

////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2010��06��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
int SEG_CHAR_YPositionLine(int StartX,int StartY,int EndX, int EndY,int SetX)
{
	int YPosition=0;
	YPosition=int(((double)EndY-(double)StartY)*((double)SetX-(double)StartX)/((double)EndX-(double)StartX)+StartY+0.5);
	return YPosition;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int SEG_CHAR_YPositionLine(int StartX,int StartY,int EndX, int EndY,int SetX)
//	�������� ����ֱ֪��������͵����������꣬�������
//  �������� ����������ֱ�߹�ʽ����
//  ���к��� ��
//  ���ú��� ��
//  �������� ��
//  ����ĵ� ����
//	��    �� ��������
//	ʱ    �� ��2010��6��9��
//	�� �� ֵ ��
//	��ڲ���˵�� ��

////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2010��06��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
int SEG_CHAR_XPositionLine(int StartX,int StartY,int EndX, int EndY,int SetY)
{
	int XPosition=0;
	XPosition=int(((double)EndX-(double)StartX)*((double)SetY-(double)StartY)/((double)EndY-(double)StartY)+StartX+0.5);
	return XPosition;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int DPSGII_ColumnPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
//	�������� ����ˮƽ������������꣬ͳ�����������صĸ���
//  �������� ����������ֱ�߹�ʽ����ֱ����ÿһ����
//  ���к��� ��
//  ���ú��� ��
//  �������� ��
//  ����ĵ� ����
//	��    �� ��������
//	ʱ    �� ��2010��6��11��
//	�� �� ֵ ��LinePoint������ֵͼ��ֱ���Ϻ����ظ���
//	��ڲ���˵�� ��
//  1.IplImage * Img_bin: �������Ķ�ֵͼ
//  2.int nWidth���������Ķ�ֵͼ������
//  3.int nHeight���������Ķ�ֵͼ����߶�
//  4.int StartPx��������ʼ�������
//  5.int StartPy��������ʼ��������
//  6.int EndPx�����������������
//  7.int EndPy������������������
//  8.int R�������뾶
//  9.int Rout���⻷�뾶

////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2010��06��11��	������	����������
//	////////////////////////////////////////////////////////////////////////
int DPSGII_ColumnPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
{
	int LinePoint=0;
	int tempY=0;
	int tempX=0;
	int i=0;
	if((StartPx<Rout||EndPx<Rout||StartPy<Rout||EndPy<Rout||StartPx>nWidth-Rout||EndPx>nWidth-Rout||StartPy>nHeight-Rout||EndPy>nHeight-Rout))
	{return LinePoint;}
	if( StartPx> EndPx)
	{
		tempX=StartPx;
		StartPx=EndPx;
		EndPx=tempX;
		tempY=StartPy;
		StartPy=EndPy;
		EndPy=tempY;
	}
	for(i=StartPx;i<=EndPx;i+=R)
	{
		tempY=SEG_CHAR_YPositionLine(StartPx,StartPy,EndPx,EndPy,i);
		if(((unsigned char*)(Img_bin + nWidth*(tempY)))[i]==0)
		{
            LinePoint++;
		}
		else if(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,i,tempY,1)>1)
		{
			LinePoint++;
		}

	}
	return LinePoint;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int DPSGII_RowPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
//	�������� ������ֱ�����������꣬ͳ�����������صĸ���
//  �������� ����������ֱ�߹�ʽ����ֱ����ÿһ����
//  ���к��� ��
//  ���ú��� ��
//  �������� ��
//  ����ĵ� ����
//	��    �� ��������
//	ʱ    �� ��2010��6��11��
//	�� �� ֵ ��LinePoint������ֵͼ��ֱ���Ϻ����ظ���
//	��ڲ���˵�� ��
//  1.IplImage * Img_bin: �������Ķ�ֵͼ
//  2.int nWidth���������Ķ�ֵͼ������
//  3.int nHeight���������Ķ�ֵͼ����߶�
//  4.int StartPx��������ʼ�������
//  5.int StartPy��������ʼ��������
//  6.int EndPx�����������������
//  7.int EndPy������������������
//  8.int R�������뾶
//  9.int Rout���⻷�뾶

////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2010��06��11��	������	����������
//	////////////////////////////////////////////////////////////////////////
int DPSGII_RowPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
{
	int LinePoint=0;
	int tempY=0;
	int tempX=0;
	int i=0;
    if((StartPx<Rout||EndPx<Rout||StartPy<Rout||EndPy<Rout||StartPx>nWidth-Rout||EndPx>nWidth-Rout||StartPy>nHeight-Rout||EndPy>nHeight-Rout))
	{return LinePoint;}
	if( StartPy> EndPy)
	{
		tempX=StartPx;
		StartPx=EndPx;
		EndPx=tempX;
		tempY=StartPy;
		StartPy=EndPy;
		EndPy=tempY;
	}
	for(i=StartPy;i<=EndPy;i+=R)
	{
		tempX=SEG_CHAR_XPositionLine(StartPx,StartPy,EndPx,EndPy,i);
		if(((unsigned char*)(Img_bin + nWidth*i))[tempX]==0)
		{
            LinePoint++;
		}
		else if(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,tempX,i,1)>1)
		{
			LinePoint++;
		}
	}
	return LinePoint;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��bool DPSG_AdnoteLinePoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
//	�������� �������������߼�����صĸ����ж�������Ƿ������ӹ�ϵ
//  �������� ����������ֱ�߹�ʽ����ֱ����ÿһ����
//  ���к��� ��
//  ���ú��� ��
//  �������� ��
//  ����ĵ� ����
//	��    �� ��������
//	ʱ    �� ��2010��6��11��
//	�� �� ֵ ��LinePoint������ֵͼ��ֱ���Ϻ����ظ���
//	��ڲ���˵�� ��
//  1.IplImage * Img_bin: �������Ķ�ֵͼ
//  2.int nWidth���������Ķ�ֵͼ������
//  3.int nHeight���������Ķ�ֵͼ����߶�
//  4.int StartPx��������ʼ�������
//  5.int StartPy��������ʼ��������
//  6.int EndPx�����������������
//  7.int EndPy������������������
//  8.int R�������뾶
//  9.int Rout���⻷�뾶

////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2010��06��11��	������	����������
//	////////////////////////////////////////////////////////////////////////
bool DPSG_AdnoteLinePoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
{
	int LinePoint=0;
	int tempY=0;
	int tempX=0;
	int i=0;
	bool AdnoteSign=true;
	 if((StartPx<Rout||EndPx<Rout||StartPy<Rout||EndPy<Rout||StartPx>nWidth-Rout||EndPx>nWidth-Rout||StartPy>nHeight-Rout||EndPy>nHeight-Rout))
	{return false;}
	if(StartPx==EndPx)
	{
		if( StartPy> EndPy)
		{
			tempX=StartPx;
			StartPx=EndPx;
			EndPx=tempX;
			tempY=StartPy;
			StartPy=EndPy;
			EndPy=tempY;
		}
		for(i=StartPy;i<=EndPy;i+=R)
		{
			if(((unsigned char*)(Img_bin + nWidth*i))[StartPx]==0)
			{
				 LinePoint++;
			}
		}
		if(LinePoint<abs((EndPy-StartPy)/R)+1)
		{
			AdnoteSign=false;
		}
	}
	else if(StartPy==EndPy)
	{
		if( StartPx> EndPx)
		{
			tempX=StartPx;
			StartPx=EndPx;
			EndPx=tempX;
			tempY=StartPy;
			StartPy=EndPy;
			EndPy=tempY;
		}
		for(i=StartPx;i<=EndPx;i+=R)
		{
			if(((unsigned char*)(Img_bin + nWidth*(StartPy)))[i]==0)
			{
				LinePoint++;
			}
		}
		if(LinePoint<(abs(EndPx-StartPx)/R)+1)//�����ظ�������
		{
			AdnoteSign=false;
		}
	}
	else if(abs(StartPx-EndPx)>=abs(StartPy-EndPy))
	{
		LinePoint=DPSGII_ColumnPoint(Img_bin,nWidth,nHeight,StartPx,StartPy,EndPx,EndPy,R,Rout);
		if(LinePoint<abs((EndPx-StartPx)/R)+1)
		{
			AdnoteSign=false;//�����ظ�������
		}
	}
	else if(abs(StartPy-EndPy)>abs(StartPx-EndPx))
	{
		LinePoint=DPSGII_RowPoint(Img_bin,nWidth,nHeight,StartPx,StartPy,EndPx,EndPy,R,Rout);
		if(LinePoint<abs((EndPy-StartPy)/R)+1)
		{
			AdnoteSign=false;
		}
	}
   // TRACE("StartPx=%d,EndPx=%d,StartPy=%d,EndPy=%d,LinePoint=%d\n,",StartPx,EndPx,StartPy,EndPy,LinePoint);
	return AdnoteSign;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��StepStrucureII(double) DPSGII_DPTraceR64D(IplImage * Img_bin, int cenX, int cenY, int R, unsigned int Direction)
//	�������� ������Img_binָ����64������֮һ����ͨ����
//	��    �� ��������
//	ʱ    �� ��2012��3��28��
//	�� �� ֵ ��StepStrucureII TraceTemp64������֮һ�߶����
//	��ڲ���˵�� ��
//	1.IplImage * Img_bin��������Ķ�ֵͼ
//	2.int cenX��ָ���������
//	3.int cenY��ָ���������
//	4.int R����ֵͼ�����뾶
//  5.unsigned int Direction:64������֮һ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
//	////////////////////////////////////////////////////////////////////////
StepStrucureII DPSGII_DPTraceR64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout, unsigned int Direction)
{
	StepStrucureII TraceTemp;
	TraceTemp.xstep=cenX;
	TraceTemp.ystep=cenY;
	TraceTemp.stepdistense=0.0;
    int PDCNum=0;
	if(cenY<Rout||cenX<Rout||cenY>nHeight-Rout||cenX>nWidth-Rout||Direction<1||Direction>64)
	{return TraceTemp;}
	int XPosition=cenX+g_oDistense64D[Direction].xstep*R;
	int YPosition=cenY+g_oDistense64D[Direction].ystep*R;
	if((XPosition>nWidth-Rout)||(XPosition<Rout)||(YPosition>nHeight-Rout)||(YPosition<Rout))
	{return TraceTemp;}
	PDCNum++;
	int LastXPosition=cenX;
	int LastYPosition=cenY;
	if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))//��һ���Ͳ�����
	{return TraceTemp;}

	while((XPosition<nWidth-Rout)
		&&(XPosition>Rout)
        &&(YPosition<nHeight-Rout)
		&&(YPosition>Rout)
		&&(((unsigned char*)(Img_bin + nWidth*YPosition))[XPosition]==0))
	{
		if((LastXPosition!=XPosition)&&(YPosition!=LastYPosition))
		{
			if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))
			{break;}
		}
		PDCNum++;
		LastXPosition=XPosition;
		LastYPosition=YPosition;
		XPosition=XPosition+g_oDistense64D[Direction].xstep*R;
		YPosition=YPosition+g_oDistense64D[Direction].ystep*R;
		if((XPosition>nWidth-Rout)||(XPosition<Rout)||(YPosition>nHeight-Rout)||(YPosition<Rout))
		{break;}
		
	}
	PDCNum--;
	TraceTemp.stepdistense=g_oDistense64D[Direction].stepdistense*PDCNum*R;
	TraceTemp.xstep=LastXPosition;
	TraceTemp.ystep=LastYPosition;
	//double tempdist=dist(CGPOINT(cenX,cenY),CGPOINT(LastXPosition,LastYPosition));
	return TraceTemp;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��double DPSGII_DPDisR64D (IplImage * Img_bin, int cenX, int cenY, int R, unsigned int Direction)
//	�������� ������Img_binָ����64������֮һ����ͨ����
//	��    �� ��������
//	ʱ    �� ��2012��3��28��
//	�� �� ֵ �� double PDCdist1-64������ͨ����
//	��ڲ���˵�� ��
//	1.IplImage * Img_bin��������Ķ�ֵͼ
//	2.int cenX��ָ���������
//	3.int cenY��ָ���������
//	4.int R����ֵͼ�����뾶
//  5.unsigned int Direction:64������֮һ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
//	////////////////////////////////////////////////////////////////////////
double DPSGII_DPDisR64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout, unsigned int Direction)
{
	double PDCdist=0.0;
	StepStrucureII RectDistriTemp; 
	memset(&RectDistriTemp,0,sizeof(StepStrucureII));
	int PDCNum=0;
	if(cenY<Rout||cenX<Rout||cenY>nHeight-Rout||cenX>nWidth-Rout||Direction<1||Direction>64)
	{return PDCdist;}
	int XPosition=cenX+g_oDistense64D[Direction].xstep*R;
	int YPosition=cenY+g_oDistense64D[Direction].ystep*R;
	int LastXPosition=cenX;
	int LastYPosition=cenY;
	if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))//��һ���Ͳ�����
	{return  PDCdist;}
	while((XPosition<nWidth-Rout)
		&&(XPosition>Rout)
        &&(YPosition<nHeight-Rout)
		&&(YPosition>Rout)
		&&(((unsigned char*)(Img_bin + nWidth*YPosition))[XPosition]==0))
	{
			if((LastXPosition!=XPosition)&&(YPosition!=LastYPosition))
		{
			if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))
			{break;}
		}
		PDCNum++;
		LastXPosition=XPosition;
		LastYPosition=YPosition;
		XPosition=XPosition+g_oDistense64D[Direction].xstep*R;
		YPosition=YPosition+g_oDistense64D[Direction].ystep*R;
		if((XPosition>nWidth-Rout)||(XPosition<Rout)||(YPosition>nHeight-Rout)||(YPosition<Rout))
		{break;}
	}
    PDCNum--;
	PDCdist=g_oDistense64D[Direction].stepdistense*PDCNum*R;
	return PDCdist;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��ThrumInfo DPSGII_LineSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R)
//	�������� ������Img_binָ����32���Է�������γɵ��ֱ��
//	��    �� ��������
//	ʱ    �� ��2010��11��7��
//	�� �� ֵ �� 32��ά�ܱ߷����׶����ֵThrumInfo ThrumNow�ṹ��
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int cenX��ָ���������
//	5.int cenY��ָ���������
//	6.int R����ֵͼ�����뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
//	////////////////////////////////////////////////////////////////////////
ThrumInfo DPSGII_LineSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout)
{
	ThrumInfo ThrumNow;
	int i=0;
	memset(&ThrumNow,0,sizeof(ThrumInfo));
	int MaxDirection=0;//�����
    double MaxPDC=0.0;//������׶�
	double ThrumTest32[33] = {0};
	StepStrucureII ThrumTest64[65] = {0};
	for(i=1;i<33;i++)
	{
		
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>MaxPDC)
		{
			MaxPDC=ThrumTest32[i];
			MaxDirection=i;
		}
	}
	int NormOne=MaxDirection+16;//���߷���1
	    int NormTwo=MaxDirection-16;//���߷���2
		if(NormOne>64)
		{NormOne-=64;}
		if(NormTwo<1)
		{NormTwo+=64;}
		ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+15;//���߷���1
			NormTwo=MaxDirection-17;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+17;//���߷���1
			NormTwo=MaxDirection-15;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+18;//���߷���1
			NormTwo=MaxDirection-14;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+14;//���߷���1
			NormTwo=MaxDirection-18;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
	ThrumNow.ThrumDire=MaxDirection;
	ThrumNow.ThrumDist=MaxPDC;
	ThrumNow.ThrumStart.x=ThrumTest64[MaxDirection].xstep;
	ThrumNow.ThrumStart.y=ThrumTest64[MaxDirection].ystep;
	ThrumNow.ThrumEnd.x=ThrumTest64[MaxDirection+32].xstep;
	ThrumNow.ThrumEnd.y=ThrumTest64[MaxDirection+32].ystep;
   	return ThrumNow;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��unsigned char* DPSGII_YYLineSegPoint(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,int Rout,int SegLength)
//	�������� ����ѡ�ܹ��γ��߶εĵ�
//	��    �� ��������
//	ʱ    �� ��2010��11��7��
//	�� �� ֵ �� 32��ά�ܱ߷����׶����ֵThrumInfo ThrumNow�ṹ��
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int cenX��ָ���������
//	5.int cenY��ָ���������
//	6.int R����ֵͼ�����뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��28��	������	����������
//	////////////////////////////////////////////////////////////////////////
unsigned char* DPSGII_YYLineSegPoint(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,int Rout,int SegLength)
{
	unsigned char*	YYBin=new unsigned char[nWidth*nHeight];
	memset(YYBin,255,nWidth*nHeight*sizeof(unsigned char));
	ThrumInfo LineSegTemp;
	int x=0;
	int y=0;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			if(((unsigned char*)(Img_bin + nWidth*y))[x]==0)
			{
				LineSegTemp=DPSGII_LineSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout);
				if(LineSegTemp.ThrumDist>SegLength)
				{
					((unsigned char*)(YYBin + nWidth*y))[x]=0;
					//(*(P+308))++;
    			}
				
			}
		}
	}
	return YYBin;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R)
//	�������� ������Img_bin��ָ����Ϊ��ͷ32���Է�������γɵ��ֱ�������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��3��30��
//	�� �� ֵ �� 32��ά�ܱ߷����׶����ֵStartThrumInfo StartThrumNow�ṹ��
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int cenX��ָ���������
//	5.int cenY��ָ���������
//	6.int R����ֵͼ�����뾶
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��30��	������	����������
//	////////////////////////////////////////////////////////////////////////
StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout)
{
	StartThrumInfo StartThrumNow;
	int i=0;
	memset(&StartThrumNow,0,sizeof(StartThrumInfo));
	int MaxDirection=0;//�����
    double MaxPDC=0.0;//������׶�
	double ThrumTest32[33] = {0};
	StepStrucureII ThrumTest64[65] = {0};
	int tempStep=0;
	double tempdist=0.0;
	int hisCenX=cenX;
	int HisCenY=cenY;
	for(i=1;i<33;i++)
	{
		
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>MaxPDC)
		{
			MaxPDC=ThrumTest32[i];
			MaxDirection=i;
		}
	}
	tempdist=2*R*g_oDistense64D[MaxDirection].stepdistense;
	if(ThrumTest64[MaxDirection].stepdistense-ThrumTest64[MaxDirection+32].stepdistense>tempdist)
	{
		tempStep=int((ThrumTest64[MaxDirection].stepdistense+0.1)/tempdist);
		cenX=cenX+g_oDistense64D[MaxDirection].xstep*tempStep*R;
		cenY=cenY+g_oDistense64D[MaxDirection].ystep*tempStep*R;

	}
	else if(ThrumTest64[MaxDirection+32].stepdistense-ThrumTest64[MaxDirection].stepdistense>tempdist)
	{
		tempStep=int((ThrumTest64[MaxDirection+32].stepdistense+0.1)/tempdist);
		cenX=cenX+g_oDistense64D[MaxDirection+32].xstep*tempStep*R;
		cenY=cenY+g_oDistense64D[MaxDirection+32].ystep*tempStep*R;
	}
	int NormOne=MaxDirection+16;//���߷���1
	    int NormTwo=MaxDirection-16;//���߷���2
		double NormOneLength=0.0;//���߷���1����
		double NormTwoLength=0.0;//���߷���2����

		if(NormOne>64)
		{NormOne-=64;}
		if(NormTwo<1)
		{NormTwo+=64;}
		NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
		NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+15;//���߷���1
			NormTwo=MaxDirection-17;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+17;//���߷���1
			NormTwo=MaxDirection-15;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+18;//���߷���1
			NormTwo=MaxDirection-14;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+14;//���߷���1
			NormTwo=MaxDirection-18;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
   //������ʼ��λ�ã�ʹ֮���ӽ��ڷ����е�
	if((NormOneLength-NormTwoLength)>R*g_oDistense64D[NormOne].stepdistense)
	{
		StartThrumNow.ThrumSource.x=cenX+g_oDistense64D[NormOne].xstep*R*(NormOneLength-NormTwoLength)/(g_oDistense64D[NormOne].stepdistense*2);
		StartThrumNow.ThrumSource.y=cenY+g_oDistense64D[NormOne].ystep*R*(NormOneLength-NormTwoLength)/(g_oDistense64D[NormOne].stepdistense*2);
	}
	else if((NormTwoLength-NormOneLength)>R*g_oDistense64D[NormTwo].stepdistense)
	{
		StartThrumNow.ThrumSource.x=cenX+g_oDistense64D[NormTwo].xstep*R*(NormTwoLength-NormOneLength)/(g_oDistense64D[NormTwo].stepdistense*2);
		StartThrumNow.ThrumSource.y=cenY+g_oDistense64D[NormTwo].ystep*R*(NormTwoLength-NormOneLength)/(g_oDistense64D[NormTwo].stepdistense*2);;
	}
	else
	{
		StartThrumNow.ThrumSource.x=cenX;
		StartThrumNow.ThrumSource.y=cenY;
	}
	StartThrumNow.ThrumDire=MaxDirection;
	StartThrumNow.ThrumDist=MaxPDC;
	StartThrumNow.ThrumStart.x=ThrumTest64[MaxDirection].xstep;
	StartThrumNow.ThrumStart.y=ThrumTest64[MaxDirection].ystep;
	StartThrumNow.ThrumEnd.x=ThrumTest64[MaxDirection+32].xstep;
	StartThrumNow.ThrumEnd.y=ThrumTest64[MaxDirection+32].ystep;
	
   	return StartThrumNow;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_StartThrumToThrum(StartThrumInfo * StartThrumNow,ThrumInfo *ThrumNow)
//	�������� ������ͷ�ṹ����Ϣ��ֵ���߶νṹ��
//	��    �� ��������
//	ʱ    �� ��2012��3��30��
//	�� �� ֵ �� ��
//	��ڲ���˵�� ��
//	1.StartThrumInfo * StartThrumNow����ֵ����ͷ�ṹ��
//  2.ThrumInfo *ThrumNowҪ��ֵ���߶νṹ��
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��30��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_StartThrumToThrum(StartThrumInfo * StartThrumNow,ThrumInfo *ThrumNow)
{
	ThrumNow->ThrumDire=StartThrumNow->ThrumDire;
	ThrumNow->ThrumDist=StartThrumNow->ThrumDist;
	ThrumNow->ThrumStart=StartThrumNow->ThrumStart;
	ThrumNow->ThrumEnd=StartThrumNow->ThrumEnd;
	ThrumNow->ThrumNormdis=StartThrumNow->ThrumNormdis;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void ChangeSeqII(int SeqA,int SeqB)
//	�������� �����߶�A���߶�B�����ߣ��߶μ��ϣ��е�λ�ý���������ת�䷽��
//	��    �� ��������
//	ʱ    �� ��2012��3��30��
//	�� �� ֵ �� ��
//	��ڲ���˵�� ��
//	1.int SeqA�߶�A���
//	1.int SeqB�߶�B���
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��30��	������	����������
//	////////////////////////////////////////////////////////////////////////
void ChangeSeqII(int SeqA,int SeqB)
{
	if(SeqA!= SeqB)
	{
	ThrumTemp.ThrumStart=ThrumGroup[SeqB].ThrumStart;
    ThrumGroup[SeqB].ThrumStart=ThrumGroup[SeqB].ThrumEnd;
	ThrumGroup[SeqB].ThrumEnd=ThrumTemp.ThrumStart;
	if(ThrumGroup[SeqB].ThrumDire<=32)
	{ThrumGroup[SeqB].ThrumDire+=32;}
	else
	{ThrumGroup[SeqB].ThrumDire-=32;}

	ThrumTemp.ThrumStart=ThrumGroup[SeqA].ThrumStart;
    ThrumGroup[SeqA].ThrumStart=ThrumGroup[SeqA].ThrumEnd;
	ThrumGroup[SeqA].ThrumEnd=ThrumTemp.ThrumStart;
	if(ThrumGroup[SeqA].ThrumDire<=32)
	{ThrumGroup[SeqA].ThrumDire+=32;}
	else
	{ThrumGroup[SeqA].ThrumDire-=32;}
	memcpy(&ThrumTemp,&ThrumGroup[SeqB],sizeof(ThrumInfo));
	memcpy(&ThrumGroup[SeqB],&ThrumGroup[SeqA],sizeof(ThrumInfo));
	memcpy(&ThrumGroup[SeqA],&ThrumTemp,sizeof(ThrumInfo));
	}
	else
	{
		ThrumTemp.ThrumStart=ThrumGroup[SeqB].ThrumStart;
		ThrumGroup[SeqB].ThrumStart=ThrumGroup[SeqB].ThrumEnd;
		ThrumGroup[SeqB].ThrumEnd=ThrumTemp.ThrumStart;
		if(ThrumGroup[SeqB].ThrumDire<=32)
		{ThrumGroup[SeqB].ThrumDire+=32;}
		else
		{ThrumGroup[SeqB].ThrumDire-=32;}
	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��bool DPSG_ThrumCheck64D_NP(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int LastDire)
//	�������� ���ж�ָ�����������߶η���2N+1�����Ƿ�����߶�
//	��    �� ��������
//	ʱ    �� ��2012��03��30��
//	�� �� ֵ �� true�����ڣ�false:������
//	��ڲ���˵�� ��
//	1.IplImage * Img_bin��������Ķ�ֵͼ
//  2.int nWidth��������Ķ�ֵͼ������
//  3.int nHeight��������Ķ�ֵͼ����߶�
//  4.int cenX��ָ���������
//  5.int cenY��ָ����������
//	6.int R:�����뾶
//  7.int LastDire�������߶η���

////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��03��30��	������	����������
//	////////////////////////////////////////////////////////////////////////
bool DPSGII_ThrumCheck64D_NP(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int LastDire,int DirectionN)
{
	//ThrumTemp.ThrumDire=0;
	//ThrumTemp.ThrumDist=0.0;
	//ThrumTemp.ThrumStart.x=0;
	//ThrumTemp.ThrumStart.y=0;
	//ThrumTemp.ThrumEnd.x=0;
	//ThrumTemp.ThrumEnd.y=0;
	//memset(&ThrumTemp,0,sizeof(ThrumInfo));
	int i=0;
	int j=0;
	int MaxDirection=0;//�����
	int NormalDirection=0;//���߷���
	double MaxPDC=0.1;//������׶�
	double ThrumTest64[65] = {0.0};
	int NormOne=0;//���߷���1
	int NormTwo=0;//���߷���2
	double NormOneDis=0.0;
	double NormTwoDis=0.0;
	bool DirReigon=0;//����Χ��־
 	for(i=0;i<2*DirectionN+1;i++)
	{
		 
			ThrumTest64[CircleII[64+LastDire-DirectionN+i]]=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,CircleII[64+LastDire-DirectionN+i]);
			if((ThrumTest64[CircleII[64+LastDire-DirectionN+i]]>MaxPDC))//&&(DPSG_DPAdnate8Check(Img_bin,nWidth,nHeight,cenX+g_oDistense64D[i].xstep*R,cenY+g_oDistense64D[i].ystep*R,R)==8))
			{
				MaxPDC=ThrumTest64[CircleII[64+LastDire-DirectionN+i]];
				MaxDirection=CircleII[64+LastDire-DirectionN+i];
			}
	//		Counterstr.Format("LastDire=%d: i=%d,",LastDire,i);
	//        InfoText->ReplaceSel(Counterstr);
	}
	//  InfoText->ReplaceSel("\n");//����);

	if(MaxDirection!=0&&MaxPDC>(g_oDistense64D[MaxDirection].stepdistense*R-0.1))
	{
		//���ԭ���򻹿�����һ����������·���ĳ���С��ԭ���򳤶ȣ���ԭ��������
		

		if(MaxDirection-LastDire)//�������Ҫ�ı�
		{
			DirReigon=1;
			for(i=0;i<5;i++)
			{
				if(MaxDirection==CircleII[64+LastDire-2+i])//����·�������ԭ���Ҷ�����
				{	
					DirReigon=0;
					break;
				}
			}
			//int Ratio=int(ThrumTemp.ThrumNormdis/ThrumTest64[IICircle[64+LastDire]]+0.499999);
			double  Ratio=ThrumTest64[CircleII[64+LastDire]]/MaxPDC;//�����߱ȽϿ�ʱ����ϣ�����׵ĸı�ԭ���ķ���
			if((DirReigon==1)&&(ThrumTest64[CircleII[64+LastDire]]>(g_oDistense64D[LastDire].stepdistense*R-0.1))&&(MaxPDC<1.5*ThrumTemp.ThrumNormdis))
			{
				MaxPDC=ThrumTest64[CircleII[64+LastDire]];
				MaxDirection=LastDire;
			}
			if(Ratio>0.75)
			{
				MaxPDC=ThrumTest64[CircleII[64+LastDire]];
				MaxDirection=LastDire;
			}
			
		}
		ThrumTemp.ThrumDire=MaxDirection;
		ThrumTemp.ThrumDist=g_oDistense64D[MaxDirection].stepdistense*R;
		ThrumTemp.ThrumStart.x=cenX;
		ThrumTemp.ThrumStart.y=cenY;
		ThrumTemp.ThrumEnd.x=cenX+g_oDistense64D[MaxDirection].xstep*R;
		ThrumTemp.ThrumEnd.y=cenY+g_oDistense64D[MaxDirection].ystep*R;
		NormOne=MaxDirection+16;//���߷���1
	    NormTwo=MaxDirection-16;//���߷���2
		if(NormOne>64)
		{NormOne-=64;}
		if(NormTwo<1)
		{NormTwo+=64;}
		NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
		ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+15;//���߷���1
			NormTwo=MaxDirection-17;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+17;//���߷���1
			NormTwo=MaxDirection-15;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+18;//���߷���1
			NormTwo=MaxDirection-14;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+14;//���߷���1
			NormTwo=MaxDirection-18;//���߷���2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		////������ʼ��λ�ã�ʹ֮���ӽ��ڷ����е�
		/*if((NormOneDis-NormTwoDis)>2*g_oDistense64D[NormOne].stepdistense)
		{
			ThrumTemp.ThrumEnd.x=ThrumTemp.ThrumEnd.x+g_oDistense64D[NormOne].xstep;
			ThrumTemp.ThrumEnd.y=ThrumTemp.ThrumEnd.y+g_oDistense64D[NormOne].ystep;
		}
		else if((NormTwoDis-NormOneDis)>2*g_oDistense64D[NormTwo].stepdistense)
		{
			ThrumTemp.ThrumEnd.x=ThrumTemp.ThrumEnd.x+g_oDistense64D[NormTwo].xstep;
			ThrumTemp.ThrumEnd.y=ThrumTemp.ThrumEnd.y+g_oDistense64D[NormTwo].ystep;
		}*/
		/*if(ThrumTemp.ThrumDire==LastDire)
		{
			ThrumTemp.ThrumCurveSeq=ThrumNum-1;
		}
		else
		{
			ThrumTemp.ThrumCurveSeq=ThrumNum;
    	}*/
		//TRACE("TRUE_ThrumNum=%d:ThrumCurveSeq=%d,ThrumDist=%f��ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDist,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
		return true;
    }
	else
	{
		//TRACE("FALSE_ThrumNum=%d:ThrumCurveSeq=%d,ThrumDist=%f��ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDist,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
		return false;
	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_CopyImgArray(unsigned char* Img_dst,unsigned char* Img_src,int nWidth,int nHeight,int LeftSide, int RightSide, int UpSide,int DownSide,int DirectionN)
//	�������� ����Img_srcָ�������򿽱���Img_dst��
//	��    �� ��������
//	ʱ    �� ��2012��3��30��
//	�� �� ֵ ����
//	��ڲ���˵�� ��
//  1.IplImage * Img_dst: ������Ŀ��ͼ
//  2.IplImage * Img_src: ������ԭʼͼ
//  3.int nWidth��������ĻҶ�ͼ������
//  4.int nHeight��������ĻҶ�ͼ����߶�
//  5.int LeftSide��������߽�
//  6.int RightSide�������ұ߽�
//  7.int UpSide�������ϱ߽�
//  8.int DownSide�������±߽�
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��3��30��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CopyImgArray(unsigned char* Img_dst,unsigned char* Img_src,unsigned short* Img_his,int nWidth,int nHeight,int LeftSide, int RightSide, int UpSide,int DownSide,int DirectionN, int HistoryLine)
{
	int x=0;
	int y=0;
	if(LeftSide>RightSide||DownSide<UpSide||LeftSide<0||UpSide<0||RightSide>(nWidth-1)||DownSide>(nHeight-1))
	{return;}
	for(y=UpSide;y<DownSide+1;y++)
	{
	   	for(x=LeftSide;x<RightSide+1;x++)
	   {
			((unsigned char *)(Img_dst+ nWidth*y))[x]=DirectionN;
			((unsigned short *)(Img_his+ nWidth*y))[x]=HistoryLine;

	   }
	}

}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_CopyLineSegRegion(unsigned char* Img_dst,unsigned char* Img_src,int nWidth,int nHeight,int R,ThrumInfo* ThrumNow)
//	�������� ����Img_src��̽�⵽���߶������Ƶ�Img_dst��
//	��    �� ��������
//	ʱ    �� ��2012��03��30��
//	�� �� ֵ �� ���޸��˵�Img_dst
//	��ڲ���˵�� ��
//  1.IplImage * Img_dst: ������Ŀ��ͼ
//  2.IplImage * Img_src: ������ԭʼͼ
//  3.int nWidth��������ĻҶ�ͼ������
//  4.int nHeight��������ĻҶ�ͼ����߶�
//  5.ThrumInfo* ThrumNow��ָ��Ҫ���Ƶ��߶�
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��03��30��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CopyLineSegRegion(unsigned char* Img_dst,unsigned char* Img_src,unsigned short* Img_his,int nWidth,int nHeight,int R,ThrumInfo* ThrumNow)
{
	int LeftSide=0;
	int RightSide=0;
	int UpSide=0;
	int DownSide=0;
	if(ThrumNow->ThrumStart.x>ThrumNow->ThrumEnd.x)
	{
		LeftSide=ThrumNow->ThrumEnd.x;
		RightSide=ThrumNow->ThrumStart.x+(R<<1);
		//RightSide=ThrumNow->ThrumStart.x+ThrumNow->ThrumNormdis;
	}
	else if(ThrumNow->ThrumStart.x<ThrumNow->ThrumEnd.x)
	{
		LeftSide=ThrumNow->ThrumStart.x-(R<<1);
        //LeftSide=ThrumNow->ThrumStart.x-ThrumNow->ThrumNormdis;
		RightSide=ThrumNow->ThrumEnd.x;
	}
	if(ThrumNow->ThrumStart.y>ThrumNow->ThrumEnd.y)
	{
		UpSide=ThrumNow->ThrumEnd.y;
		DownSide=ThrumNow->ThrumStart.y+(R<<1);
		//DownSide=ThrumNow->ThrumStart.y+ThrumNow->ThrumNormdis;
	}
	else if(ThrumNow->ThrumStart.y<ThrumNow->ThrumEnd.y)
	{
		UpSide=ThrumNow->ThrumStart.y-(R<<1);
		//UpSide=ThrumNow->ThrumStart.y-ThrumNow->ThrumNormdis;
		DownSide=ThrumNow->ThrumEnd.y;
	}
	if(ThrumNow->ThrumStart.x==ThrumNow->ThrumEnd.x)
	{
		LeftSide=ThrumNow->ThrumStart.x-(R<<1);
		RightSide=ThrumNow->ThrumStart.x+(R<<1);
		//LeftSide=ThrumNow->ThrumStart.x-ThrumNow->ThrumNormdis;
		//RightSide=ThrumNow->ThrumStart.x+ThrumNow->ThrumNormdis;
	}
	else if(ThrumNow->ThrumStart.y==ThrumNow->ThrumEnd.y)
	{
		UpSide=ThrumNow->ThrumStart.y-(R<<1);
		DownSide=ThrumNow->ThrumStart.y+(R<<1);
		//UpSide=ThrumNow->ThrumStart.y-ThrumNow->ThrumNormdis;
		//DownSide=ThrumNow->ThrumStart.y+ThrumNow->ThrumNormdis;
    }
	DPSGII_CopyImgArray(Img_dst,Img_src,Img_his,nWidth,nHeight,LeftSide,RightSide,UpSide,DownSide,ThrumNow->ThrumDire,ThrumNum-1);
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_SetRegionValue(unsigned char* Img_dst,int nWidth,int nHeight,int StartX,int StartY, int EndX, int EndY,int Value)
//	�������� ����ָ����Χ�ڵ�����ֵ��ΪValue
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ���޸��˵�Img_dst
//	��ڲ���˵�� ��
//  1.IplImage * Img_dst: ���޸�Ŀ��ͼ
//  2.int nWidth��������ĻҶ�ͼ������
//  3.int nHeight��������ĻҶ�ͼ����߶�
//  4.int StartX��ָ����Χ��ʼ������
//  5.int StartY��ָ����Χ��ʼ������
//  6.int EndX��ָ����Χ����������
//  7.int EndY��ָ����Χ����������
//  8.int Value����ָ����Χ�ڵ�����ֵ��ΪValue
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_SetRegionValue(unsigned char* Img_dst,int nWidth,int nHeight,int StartX,int StartY, int EndX, int EndY,int Value)
{
	int LeftSide=0;
	int RightSide=0;
	int UpSide=0;
	int DownSide=0;
	
	if(StartX<=EndX)
	{
		LeftSide=StartX;
		RightSide=EndX;
	}
	else 
	{
		LeftSide=EndX;        
		RightSide=StartX;
	}
	if(StartY<=EndY)
	{
		UpSide=StartY;
		DownSide=EndY;
	}
	else 
	{
		UpSide=EndY;
		DownSide=StartY;
	}
	int x=0;
	int y=0;
	for(y=UpSide;y<DownSide+1;y++)
	{
	/*	if(((unsigned char*)(Img_dst + nWidth*y))[x]==Value)
		{break;}*/
	   	for(x=LeftSide;x<RightSide+1;x++)
	   {
		   /*	if(((unsigned char*)(Img_dst + nWidth*y))[x]==Value)
			{break;}
			else*/
			{((unsigned char *)(Img_dst+ nWidth*y))[x]=Value;}
       }
	}

	
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_CurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight, StartThrumInfo * StartThrumNow,int R,int DirectionN,int NormThre,int CrossAngle)
//	�������� ����ָ����ͷ̽��������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��03��31��
//	�� �� ֵ ���߶μ����߼���
//	��ڲ���˵�� ��
//  1.IplImage * Img_bin: ��̽��ͼ
//  2.IplImage * Img_sign: ��̽��������ͼ
//  3.int nWidth��������ĻҶ�ͼ������
//  4.int nHeight��������ĻҶ�ͼ����߶�
//  5.StartThrumInfo * StartThrumNow��ָ����ͷ�ṹ��
//  6.int R�������뾶
//  7.int DirectionN��ֱ��̽�ⷶΧ
//  8.int NormThre��������ֵ
//  9.int CrossAngle�������߽������С�Ƕ�
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��03��31��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_his,int nWidth,int nHeight, FeaturePointInfo * StartThrumNow,int R,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinCruve)
{
	int tempThrumStart=0;
	int tempThrumEnd=0;
	int j=0;
	int i=0;
	unsigned char HistorySign=0;
	unsigned short HistoryLine=0;
	

	int DirReigon=0;
	int LastDirOne=0;
	int LastDirTwo=0;
	int NextDirOne=0;
	int NextDirTwo=0;
	memset(&CurveGroup[CurveNum],0,sizeof(CurveInfo));
	tempThrumStart=ThrumNum;
	ThrumGroup[ThrumNum].ThrumDire=StartThrumNow->ThrumDire;//�߶η���
	ThrumGroup[ThrumNum].ThrumStart=StartThrumNow->FeaturePointPos;//�߶���ʼ
	ThrumGroup[ThrumNum].ThrumEnd=StartThrumNow->FeaturePointPos;//�߶ν���
	ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;//�߶��������ߺ�
    ThrumGroup[ThrumNum].ThrumHisDire=0.0;//�߶���ʷ����
	ThrumGroup[ThrumNum].ThrumDist=0.0;//�߶γ���
	ThrumGroup[ThrumNum].ThrumNormdis=StartThrumNow->ThrumNormdis;//�߶η��߿��
    ThrumTemp.ThrumNormdis=StartThrumNow->ThrumNormdis;//��ʱ���߿��
	CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum].ThrumStart;//������ʼ
	CurveGroup[CurveNum].CurveStartThrum=ThrumNum;//��CurveNum��������ʼ�߶����
	CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;//���߿���ۼ�
	ThrumNum+=1;
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
		//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if(HistorySign==0)
		{break;}
        else if(HistorySign>=1&&HistorySign<=64)
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////�����߽������С�Ƕ�*(P+312)*5.625,С������Ƕ����ܽ���
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
			/*if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				i=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]!=0)
				{
					i++;
					if(i>4)
					{
						i=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
			
		
		
/////////////////////////////////////////////////////////////////////
		
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)//�Ⱥ�����������ͬ
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			if(ThrumTemp.ThrumDire<=32)
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire+32]+=ThrumTemp.ThrumDist;}
			else
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire-32]+=ThrumTemp.ThrumDist;}
			
		}
		else//�Ⱥ�����������ͬ
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumGroup[ThrumNum].ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumGroup[ThrumNum].ThrumDist;
			if(ThrumTemp.ThrumNormdis<NormThre)//��ǰ���߿��С���趨��ֵ
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;

	     }
		if((ThrumTemp.ThrumStart.x!=StartThrumNow->FeaturePointPos.x)||(ThrumTemp.ThrumStart.y!=StartThrumNow->FeaturePointPos.y))//��ʼ�㲻���,���ⷴ��ʱ����Ϊ�����ѱ������
		{
			//TRACE("ThrumNum=%d:ThrumCurveSeq=%d,ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
			DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);
		}

	
		
	}
	CurveGroup[CurveNum].CurveStartThrum=tempThrumStart;
    CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum-1].ThrumEnd;
	tempThrumEnd=ThrumNum-1;
	if(tempThrumEnd==tempThrumStart)
	{
		ThrumTemp.ThrumStart=ThrumGroup[tempThrumStart].ThrumStart;
		ThrumGroup[tempThrumStart].ThrumStart=ThrumGroup[tempThrumStart].ThrumEnd;
		ThrumGroup[tempThrumStart].ThrumEnd=ThrumTemp.ThrumStart;
		if(ThrumGroup[tempThrumStart].ThrumDire<=32)
		{ThrumGroup[tempThrumStart].ThrumDire+=32;}
		else
		{ThrumGroup[tempThrumStart].ThrumDire-=32;}
	}
	else
	{
		for(j=0;j<=((tempThrumEnd-tempThrumStart)>>1);j++)
		{
		   ChangeSeqII(tempThrumStart+j,tempThrumEnd-j);
		}
	}
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
	//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if(HistorySign==0)
		{break;}
        else if((HistorySign>=1&&HistorySign<=64)&&(ThrumNum>tempThrumEnd+1))
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////�����߽������С�Ƕ�*(P+312)*5.625,С������Ƕ����ܽ���
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
	/*		if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				j=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]!=0)
				{
					j++;
					if(j>4)
					{
						j=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
/////////////////////////////////////////////////////////////////////
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
		}
	    else
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
		   	CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			if(ThrumTemp.ThrumNormdis<NormThre)
			{CurveGroup[CurveNum].CurveNormdis+=ThrumTemp.ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;
		}
		DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);

		
	 }
	  CurveGroup[CurveNum].CurveEndThrum=ThrumNum-1;
	  CurveGroup[CurveNum].CurveEnd=ThrumGroup[ThrumNum-1].ThrumEnd;
	  if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
	  { 
      /*���������ж�*/
		  CurveGroup[CurveNum].CurveChange=0;
		  CurveGroup[CurveNum].Curvetype=0;
		  CGPOINT Cstart;//������ʼ��
		  CGPOINT Cend;//���߽�����
		  CGPOINT CTemp;//��ʱ��
		  CGPOINT CBack;//��ʱ��
		  CGPOINT CMAX;
		  CGPOINT *CCurve;
		  int CPointNum=CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+2;
		  double StoELength=0.0;
		  double Maxdis=0.0;
		  double Tempdis=0.0;
		  double Circlerate=0.0;
		  int HalfSeq=0;
		  LINESEG StoE;
		  double PolygonArea=0.0;
		  CCurve =new CGPOINT[CPointNum];//ȡ�ö����
		  double MaxCirclerate=0.0;
			CGPOINT BestCenter;
			double BestR=0.0;
			CGPOINT BestPartCenter;
			double BestPartR=0.0;
			int PointInCircle=0;
			int MaxPointInCircle=0;
		  if(CPointNum==2)
		  {
			  CurveGroup[CurveNum].Curvetype=1;//ֱ��
			  ThrumGroup[CurveGroup[CurveNum].CurveStartThrum].ThrumWeight=1.0;
			  goto END;
		  }
			
			CCurve[0].x=CurveGroup[CurveNum].CurveStart.x;
			CCurve[0].y=CurveGroup[CurveNum].CurveStart.y;
			CCurve[CPointNum-1].x=CurveGroup[CurveNum].CurveEnd.x;
			CCurve[CPointNum-1].y=CurveGroup[CurveNum].CurveEnd.y;
			StoE.e=CCurve[0];
			StoE.s= CCurve[CPointNum-1];
			Maxdis=0.0;
			for(i=1;i<CPointNum-1;i++)
			{
				CCurve[i].x=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.x;
				CCurve[i].y=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.y;
				ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
				Tempdis=ptolinesegdist(CCurve[i],StoE,CBack);
				if(Tempdis>Maxdis)
				{
					Maxdis=Tempdis;
					CMAX=CTemp;
					}
			}
			ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
			if(Maxdis*30<CurveGroup[CurveNum].CurveDist[0])//���н�atan(0.2)=11.3��
			{
				CurveGroup[CurveNum].Curvetype=1;//ֱ��
					goto END;
			}
			if(dist(CCurve[0],CCurve[CPointNum-1])*10<CurveGroup[CurveNum].CurveDist[0])
			{
					CurveGroup[CurveNum].Curvetype=8;//����������
					goto END;
				}
			for(i=0;i<5;i++)
			{
				if(ThrumGroup[CurveGroup[CurveNum].CrossCruve[i][0]].ThrumCurveSeq==CurveNum&&CurveGroup[CurveNum].CrossCruve[i][1]!=0)
				{
					CurveGroup[CurveNum].Curvetype=9;//�ֲ��������
					goto END;
				}
			}
			double MacLineSeg[3][2]={0};
			for(i=1;i<65;i++)
			{
				CurveGroup[CurveNum].CurveDist[i]=CurveGroup[CurveNum].CurveDist[i]/CurveGroup[CurveNum].CurveDist[0];
				if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[0][1])
				{
						MacLineSeg[2][1]=MacLineSeg[1][1];
						MacLineSeg[2][0]=MacLineSeg[1][0];
						MacLineSeg[1][1]=MacLineSeg[0][1];
						MacLineSeg[1][0]=MacLineSeg[0][0];
						MacLineSeg[0][1]=CurveGroup[CurveNum].CurveDist[i];
						MacLineSeg[0][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[1][1])
				{
					MacLineSeg[2][1]=MacLineSeg[1][1];
					MacLineSeg[2][0]=MacLineSeg[1][0];
					MacLineSeg[1][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[1][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[2][1])
				{
					MacLineSeg[2][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[2][0]=i;
				}
     		}
			//TRACE("����%d��һ����%f,����%f���ڶ�����%f,����%f,��������%f,����%f,",CurveNum,MacLineSeg[0][0],MacLineSeg[0][1],MacLineSeg[1][0],MacLineSeg[1][1],MacLineSeg[2][0],MacLineSeg[2][1]);
			
			if(MacLineSeg[0][1]+MacLineSeg[1][1]+MacLineSeg[2][1]>0.75)
			{
				if(CurveGroup[CurveNum].CurveDist[0]<COLINEDIS)
				{
					CurveGroup[CurveNum].Curvetype=1;//ֱ��
					goto END;
				}
				else if(MacLineSeg[2][1]>0.1)//||MacLineSeg[2][1]*CurveGroup[CurveNum].CurveDist[0]>20)//����С���Ǿ��Գ��ȴ���20
				{
					CurveGroup[CurveNum].Curvetype=3;//3����
					goto END;
				}
				else if(MacLineSeg[1][1]>0.2)
				{
					CurveGroup[CurveNum].Curvetype=2;//2����
					goto END;
				}
				else
				{
					CurveGroup[CurveNum].Curvetype=1;//ֱ��
					goto END;

				}
			}
			for(i=1;i<33;i++)
			{
				CurveGroup[CurveNum].CurveDire=i*(CurveGroup[CurveNum].CurveDist[i]+CurveGroup[CurveNum].CurveDist[i+32]);
			}
			if(CPointNum>10)//������Բ
			{
				//�Ƚ�������Բ���ж�
				for(i=3;i<CPointNum-3;i++)
				{
					cocircle(CCurve[i-2],CCurve[i],CCurve[i+2],CBack,Tempdis);
					if(CBack.x-Tempdis>0&&CBack.x+Tempdis<nWidth&&CBack.y-Tempdis>0&&CBack.y+Tempdis<nHeight)//��ͼ��Բ��
					{
						Circlerate=CGpolygon_on_circle(CBack,Tempdis,CPointNum,CCurve,&PointInCircle);
						if(Circlerate>MaxCirclerate)
						{
							MaxCirclerate=Circlerate;
							BestCenter=CBack;
			                BestR=Tempdis;
						}
						if(PointInCircle>MaxPointInCircle)
						{
							MaxPointInCircle=PointInCircle;
							BestPartCenter=CBack;
			                BestPartR=Tempdis;

						}
					}
				}
				//TRACE("����%d�����Բ��%f,���������Բ�ϵĵ����%d\n",CurveNum,MaxCirclerate,MaxPointInCircle);
				if(MaxCirclerate>EPCIRCLE)
				{
					CurveGroup[CurveNum].Curvetype=6;//Բ��
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
				if(MaxPointInCircle>PARTCIRCLE )
				{
					CurveGroup[CurveNum].Curvetype=7;//�ֲ�Բ��
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
			}
				


		  
		  
END:	  delete CCurve;
		  
          CurveGroup[CurveNum].CurveNormdis=CurveGroup[CurveNum].CurveNormdis/(CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+1);
		  for(i=0;i<MAXCURVENUM;i++)//ǰʮ������߼�¼
		  {
			  if(CurveGroup[CurveNum].CurveDist[0]>MaxCurveGroup[i][1])
			  {
			
				  MaxCurveGroup[i][1]=CurveGroup[CurveNum].CurveDist[0];
				  MaxCurveGroup[i][0]=CurveNum;
				  break;
			  }
		  }
	 }
	  
}
void DPSGII_CurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_his,int nWidth,int nHeight, StartThrumInfo * StartThrumNow,int R,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinCruve)
{
	int tempThrumStart=0;
	int tempThrumEnd=0;
	int j=0;
	int i=0;
	unsigned char HistorySign=0;
	unsigned short HistoryLine=0;
	

	int DirReigon=0;
	int LastDirOne=0;
	int LastDirTwo=0;
	int NextDirOne=0;
	int NextDirTwo=0;
	memset(&CurveGroup[CurveNum],0,sizeof(CurveInfo));
	tempThrumStart=ThrumNum;
	ThrumGroup[ThrumNum].ThrumDire=StartThrumNow->ThrumDire;//�߶η���
	ThrumGroup[ThrumNum].ThrumStart=StartThrumNow->ThrumSource;//�߶���ʼ
	ThrumGroup[ThrumNum].ThrumEnd=StartThrumNow->ThrumSource;//�߶ν���
	ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;//�߶��������ߺ�
    ThrumGroup[ThrumNum].ThrumHisDire=0.0;//�߶���ʷ����
	ThrumGroup[ThrumNum].ThrumDist=0.0;//�߶γ���
	ThrumGroup[ThrumNum].ThrumNormdis=StartThrumNow->ThrumNormdis;//�߶η��߿��
    ThrumTemp.ThrumNormdis=StartThrumNow->ThrumNormdis;//��ʱ���߿��
	CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum].ThrumStart;//������ʼ
	CurveGroup[CurveNum].CurveStartThrum=ThrumNum;//��CurveNum��������ʼ�߶����
	CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;//���߿���ۼ�
	ThrumNum+=1;
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
		//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if(HistorySign!=255)
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////�����߽������С�Ƕ�*(P+312)*5.625,С������Ƕ����ܽ���
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
			/*if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				i=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]!=0)
				{
					i++;
					if(i>4)
					{
						i=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
			
		
		
/////////////////////////////////////////////////////////////////////
		
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)//�Ⱥ�����������ͬ
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			if(ThrumTemp.ThrumDire<=32)
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire+32]+=ThrumTemp.ThrumDist;}
			else
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire-32]+=ThrumTemp.ThrumDist;}
			
		}
		else//�Ⱥ�����������ͬ
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumGroup[ThrumNum].ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumGroup[ThrumNum].ThrumDist;
			if(ThrumTemp.ThrumNormdis<NormThre)//��ǰ���߿��С���趨��ֵ
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;

	     }
		if((ThrumTemp.ThrumStart.x!=StartThrumNow->ThrumSource.x)||(ThrumTemp.ThrumStart.y!=StartThrumNow->ThrumSource.y))//��ʼ�㲻���,���ⷴ��ʱ����Ϊ�����ѱ������
		{
			//TRACE("ThrumNum=%d:ThrumCurveSeq=%d,ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
			DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);
		}

	
		
	}
	CurveGroup[CurveNum].CurveStartThrum=tempThrumStart;
    CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum-1].ThrumEnd;
	tempThrumEnd=ThrumNum-1;
	if(tempThrumEnd==tempThrumStart)
	{
		ThrumTemp.ThrumStart=ThrumGroup[tempThrumStart].ThrumStart;
		ThrumGroup[tempThrumStart].ThrumStart=ThrumGroup[tempThrumStart].ThrumEnd;
		ThrumGroup[tempThrumStart].ThrumEnd=ThrumTemp.ThrumStart;
		if(ThrumGroup[tempThrumStart].ThrumDire<=32)
		{ThrumGroup[tempThrumStart].ThrumDire+=32;}
		else
		{ThrumGroup[tempThrumStart].ThrumDire-=32;}
	}
	else
	{
		for(j=0;j<=((tempThrumEnd-tempThrumStart)>>1);j++)
		{
		   ChangeSeqII(tempThrumStart+j,tempThrumEnd-j);
		}
	}
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
	//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if((HistorySign!=255)&&(ThrumNum>tempThrumEnd+1))
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////�����߽������С�Ƕ�*(P+312)*5.625,С������Ƕ����ܽ���
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
	/*		if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				j=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]!=0)
				{
					j++;
					if(j>4)
					{
						j=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
/////////////////////////////////////////////////////////////////////
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
		}
	    else
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
		   	CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			if(ThrumTemp.ThrumNormdis<NormThre)
			{CurveGroup[CurveNum].CurveNormdis+=ThrumTemp.ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;
		}
		DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);

		
	 }
	  CurveGroup[CurveNum].CurveEndThrum=ThrumNum-1;
	  CurveGroup[CurveNum].CurveEnd=ThrumGroup[ThrumNum-1].ThrumEnd;
	  if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
	  { 
      /*���������ж�*/
		  CurveGroup[CurveNum].CurveChange=0;
		  CurveGroup[CurveNum].Curvetype=0;
		  CGPOINT Cstart;//������ʼ��
		  CGPOINT Cend;//���߽�����
		  CGPOINT CTemp;//��ʱ��
		  CGPOINT CBack;//��ʱ��
		  CGPOINT CMAX;
		  CGPOINT *CCurve;
		  int CPointNum=CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+2;
		  double StoELength=0.0;
		  double Maxdis=0.0;
		  double Tempdis=0.0;
		  double Circlerate=0.0;
		  int HalfSeq=0;
		  LINESEG StoE;
		  double PolygonArea=0.0;
		  CCurve =new CGPOINT[CPointNum];//ȡ�ö����
		  double MaxCirclerate=0.0;
			CGPOINT BestCenter;
			double BestR=0.0;
			CGPOINT BestPartCenter;
			double BestPartR=0.0;
			int PointInCircle=0;
			int MaxPointInCircle=0;
		  if(CPointNum==2)
		  {
			  CurveGroup[CurveNum].Curvetype=1;//ֱ��
			  ThrumGroup[CurveGroup[CurveNum].CurveStartThrum].ThrumWeight=1.0;
			  goto END;
		  }
			
			CCurve[0].x=CurveGroup[CurveNum].CurveStart.x;
			CCurve[0].y=CurveGroup[CurveNum].CurveStart.y;
			CCurve[CPointNum-1].x=CurveGroup[CurveNum].CurveEnd.x;
			CCurve[CPointNum-1].y=CurveGroup[CurveNum].CurveEnd.y;
			StoE.e=CCurve[0];
			StoE.s= CCurve[CPointNum-1];
			Maxdis=0.0;
			for(i=1;i<CPointNum-1;i++)
			{
				CCurve[i].x=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.x;
				CCurve[i].y=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.y;
				ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
				Tempdis=ptolinesegdist(CCurve[i],StoE,CBack);
				if(Tempdis>Maxdis)
				{
					Maxdis=Tempdis;
					CMAX=CTemp;
					}
			}
			ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
			if(Maxdis*30<CurveGroup[CurveNum].CurveDist[0])//���н�atan(0.2)=11.3��
			{
				CurveGroup[CurveNum].Curvetype=1;//ֱ��
					goto END;
			}
			if(dist(CCurve[0],CCurve[CPointNum-1])*10<CurveGroup[CurveNum].CurveDist[0])
			{
					CurveGroup[CurveNum].Curvetype=8;//����������
					goto END;
				}
			for(i=0;i<5;i++)
			{
				if(ThrumGroup[CurveGroup[CurveNum].CrossCruve[i][0]].ThrumCurveSeq==CurveNum&&CurveGroup[CurveNum].CrossCruve[i][1]!=0)
				{
					CurveGroup[CurveNum].Curvetype=9;//�ֲ��������
					goto END;
				}
			}
			double MacLineSeg[3][2]={0};
			for(i=1;i<65;i++)
			{
				CurveGroup[CurveNum].CurveDist[i]=CurveGroup[CurveNum].CurveDist[i]/CurveGroup[CurveNum].CurveDist[0];
				if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[0][1])
				{
						MacLineSeg[2][1]=MacLineSeg[1][1];
						MacLineSeg[2][0]=MacLineSeg[1][0];
						MacLineSeg[1][1]=MacLineSeg[0][1];
						MacLineSeg[1][0]=MacLineSeg[0][0];
						MacLineSeg[0][1]=CurveGroup[CurveNum].CurveDist[i];
						MacLineSeg[0][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[1][1])
				{
					MacLineSeg[2][1]=MacLineSeg[1][1];
					MacLineSeg[2][0]=MacLineSeg[1][0];
					MacLineSeg[1][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[1][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[2][1])
				{
					MacLineSeg[2][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[2][0]=i;
				}
     		}
			//TRACE("����%d��һ����%f,����%f���ڶ�����%f,����%f,��������%f,����%f,",CurveNum,MacLineSeg[0][0],MacLineSeg[0][1],MacLineSeg[1][0],MacLineSeg[1][1],MacLineSeg[2][0],MacLineSeg[2][1]);
			
			if(MacLineSeg[0][1]+MacLineSeg[1][1]+MacLineSeg[2][1]>0.75)
			{
				if(CurveGroup[CurveNum].CurveDist[0]<COLINEDIS)
				{
					CurveGroup[CurveNum].Curvetype=1;//ֱ��
					goto END;
				}
				else if(MacLineSeg[2][1]>0.1)//||MacLineSeg[2][1]*CurveGroup[CurveNum].CurveDist[0]>20)//����С���Ǿ��Գ��ȴ���20
				{
					CurveGroup[CurveNum].Curvetype=3;//3����
					goto END;
				}
				else if(MacLineSeg[1][1]>0.2)
				{
					CurveGroup[CurveNum].Curvetype=2;//2����
					goto END;
				}
				else
				{
					CurveGroup[CurveNum].Curvetype=1;//ֱ��
					goto END;

				}
			}
			for(i=1;i<33;i++)
			{
				CurveGroup[CurveNum].CurveDire=i*(CurveGroup[CurveNum].CurveDist[i]+CurveGroup[CurveNum].CurveDist[i+32]);
			}
			if(CPointNum>10)//������Բ
			{
				//�Ƚ�������Բ���ж�
				for(i=3;i<CPointNum-3;i++)
				{
					cocircle(CCurve[i-2],CCurve[i],CCurve[i+2],CBack,Tempdis);
					if(CBack.x-Tempdis>0&&CBack.x+Tempdis<nWidth&&CBack.y-Tempdis>0&&CBack.y+Tempdis<nHeight)//��ͼ��Բ��
					{
						Circlerate=CGpolygon_on_circle(CBack,Tempdis,CPointNum,CCurve,&PointInCircle);
						if(Circlerate>MaxCirclerate)
						{
							MaxCirclerate=Circlerate;
							BestCenter=CBack;
			                BestR=Tempdis;
						}
						if(PointInCircle>MaxPointInCircle)
						{
							MaxPointInCircle=PointInCircle;
							BestPartCenter=CBack;
			                BestPartR=Tempdis;

						}
					}
				}
				//TRACE("����%d�����Բ��%f,���������Բ�ϵĵ����%d\n",CurveNum,MaxCirclerate,MaxPointInCircle);
				if(MaxCirclerate>EPCIRCLE)
				{
					CurveGroup[CurveNum].Curvetype=6;//Բ��
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
				if(MaxPointInCircle>PARTCIRCLE )
				{
					CurveGroup[CurveNum].Curvetype=7;//�ֲ�Բ��
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
			}
				
END:	  delete CCurve;
		  
          CurveGroup[CurveNum].CurveNormdis=CurveGroup[CurveNum].CurveNormdis/(CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+1);
		  for(i=0;i<MAXCURVENUM;i++)//ǰʮ������߼�¼
		  {
			  if(CurveGroup[CurveNum].CurveDist[0]>MaxCurveGroup[i][1])
			  {
				/*  for(j=MAXCURVENUM-1;j>i;j++)
				  {
					  MaxCurveGroup[j][1]=MaxCurveGroup[j-1][1];
					  MaxCurveGroup[j][0]=MaxCurveGroup[j-1][0];
				  }*/
				  MaxCurveGroup[i][1]=CurveGroup[CurveNum].CurveDist[0];
				  MaxCurveGroup[i][0]=CurveNum;
				  break;
			  }
		  }
	 }
	  
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_CrossConclusion()
//	�������� �����ཻ������Ϣ��ʵ���ƣ���������ֻҪ��Ӿ��ܼ�����
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ���޸��˵�CurveGroup
//	��ڲ���˵�� ����
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CrossConclusion()
{
	int i=0;
	int j=0;
	int SelfLineSeq=0;//�ཻ�Լ��߶κ�
	int OtherLineSeq=0;//�ཻ�����߶κ�
	int CurveSeq=0;//���ߺ�
	int CrossType=0;//�ཻ����
	int x=0;
	int y=0;
	int k=0;
	for(i=0;i<CurveNum;i++)
	{
		j=0;
		while(CurveGroup[i].CrossCruve[j][0]!=0&&CurveGroup[i].CrossCruve[j][5]==0)
		{
			OtherLineSeq=CurveGroup[i].CrossCruve[j][0];
			CrossType=CurveGroup[i].CrossCruve[j][1];
            SelfLineSeq=CurveGroup[i].CrossCruve[j][4];
			x=CurveGroup[i].CrossCruve[j][2];
		    y=CurveGroup[i].CrossCruve[j][3];
			CurveSeq=ThrumGroup[OtherLineSeq].ThrumCurveSeq;
			if(CurveSeq!=0xffff)
			{
				k=0;
				while(CurveGroup[CurveSeq].CrossCruve[k][0]!=0)
				{
					k++;
					if(k>4)
					{
						k=0;
						break;
					}
				}
				CurveGroup[CurveSeq].CrossCruve[k][0]=SelfLineSeq;
				CurveGroup[CurveSeq].CrossCruve[k][1]=CrossType;
				CurveGroup[CurveSeq].CrossCruve[k][2]=x;
				CurveGroup[CurveSeq].CrossCruve[k][3]=y;
				CurveGroup[CurveSeq].CrossCruve[k][4]=OtherLineSeq;
				CurveGroup[CurveSeq].CrossCruve[k][5]=0xff;
			}
        j++;
		if(j==5)
		{break;}
		}

	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight, StartThrumInfo * StartThrumNow,int R,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve)
//	�������� ����Img_bin���Զ�̽��������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��4��1��
//	�� �� ֵ ���߶μ����߼���
//	��ڲ���˵�� ��
//  1.IplImage * Img_bin: ��̽��ͼ
//  2.IplImage * Img_sign: ��̽��������ͼ
//  3.int nWidth��������ĻҶ�ͼ������
//  4.int nHeight��������ĻҶ�ͼ����߶�
//  5.int R�������뾶
//  6.int DirectionN��ֱ��̽�ⷶΧ
//  7.int NormThre��������ֵ
//  8.int CrossAngle�������߽������С�Ƕ�
//  9.int MinLine����С��ʼ������ֱ�߳���
//  10.int MinCruve����С̽�����߳���
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��03��31��	������	����������
//	////////////////////////////////////////////////////////////////////////

void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve)
{
	int x=0;
	int y=0;
	int i=0;
	bool FeaturePointSign=false;
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			if(CurveNum>=CURVEMAXNUM||StartThrumNum>=CURVEMAXNUM||ThrumNum>THRUMMAXNUM)
			{break;}
			//̽��ͼ�����������ͨ�ĺڵ㣬���ͼ���������޺ڵ�İ׵�,����Ϊ�ǿ��ܵ���ʼ��
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			{
				//����ʼ��ͷ
				memset(&FeaturePoint[FeaturePointNum],0,sizeof(FeaturePointInfo));
				FeaturePoint[FeaturePointNum]=DPSGII_FeaturePointSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout,NormThre);
				FeaturePointSign=DPSGII_FeaturePointBlockArea(Img_sign,nWidth,nHeight,Rin,&FeaturePoint[FeaturePointNum]);
	            FeaturePointNum+=FeaturePointSign;	
		
				//��ʼ��ͷ���ڳ���Ҫ����MinLine
				if(FeaturePointSign&&FeaturePoint[FeaturePointNum-1].ThrumDist>MinLine&&FeaturePoint[FeaturePointNum-1].ThrumNormdis<NormThre)
				{
					DPSGII_CurveSearch64D(Img_bin,Img_sign,Img_history,nWidth,nHeight,&FeaturePoint[FeaturePointNum-1],Rin,Rout,DirectionN,NormThre,CrossAngle,MinCruve);
					//TRACE("CurveNum=%d:CurveDist[0]=%f,CurveStartThrum=%d,CurveEndThrum=%d\n",CurveNum,CurveGroup[CurveNum].CurveDist[0],CurveGroup[CurveNum].CurveStartThrum,CurveGroup[CurveNum].CurveEndThrum);
					if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
					{
						CurveNum++;
					}
					else
					{
						
						for(i=CurveGroup[CurveNum].CurveStartThrum;i<=CurveGroup[CurveNum].CurveEndThrum;i++)
						{
							ThrumGroup[i].ThrumCurveSeq=0xffff;
						}
					}
				}
			}
		}
	}
	if(CurveNum>2)
	{DPSGII_CrossConclusion();}

}
void DPSGII_AutoCurveSearch64DII(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve)
{
	int x=0;
	int y=0;
	int i=0;
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			if(CurveNum>=CURVEMAXNUM||StartThrumNum>=CURVEMAXNUM||ThrumNum>THRUMMAXNUM)
			{break;}
			//̽��ͼ�����������ͨ�ĺڵ㣬���ͼ���������޺ڵ�İ׵�,����Ϊ�ǿ��ܵ���ʼ��
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			{
				//����ʼ��ͷ
				memset(&StartThrum[StartThrumNum],0,sizeof(StartThrumInfo));
				StartThrum[StartThrumNum]=DPSGII_StartThrumSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout);
				//StartThrum[StartThrumNum]=ROI_DPSGII_StartThrumSearch64D(Img_bin,nWidth,nHeight,x,y,Rin);
				//TRACE("StartThrumNum=%d:x=%d,y=%d,ThrumSource.x=%d,ThrumSource.y=%d,ThrumDire=%d,ThrumDist=%f,ThrumNormdis=%f\n",StartThrumNum,x,y,StartThrum[StartThrumNum].ThrumSource.x,StartThrum[StartThrumNum].ThrumSource.y,StartThrum[StartThrumNum].ThrumDire,StartThrum[StartThrumNum].ThrumDist,StartThrum[StartThrumNum].ThrumNormdis);
				//��ʼ��ͷ���ڳ���Ҫ����MinLine
				if(StartThrum[StartThrumNum].ThrumDist>MinLine&&StartThrum[StartThrumNum].ThrumNormdis<NormThre)
					//&&StartThrum[StartThrumNum].ThrumDist>(StartThrum[StartThrumNum].ThrumNormdis*4))
				{
					DPSGII_CurveSearch64D(Img_bin,Img_sign,Img_history,nWidth,nHeight,&StartThrum[StartThrumNum],Rin,Rout,DirectionN,NormThre,CrossAngle,MinCruve);
					//TRACE("CurveNum=%d:CurveDist[0]=%f,CurveStartThrum=%d,CurveEndThrum=%d\n",CurveNum,CurveGroup[CurveNum].CurveDist[0],CurveGroup[CurveNum].CurveStartThrum,CurveGroup[CurveNum].CurveEndThrum);
					if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
					{
						StartThrumNum++;
						CurveNum++;
					}
					else
					{
						
						for(i=CurveGroup[CurveNum].CurveStartThrum;i<=CurveGroup[CurveNum].CurveEndThrum;i++)
						{
							ThrumGroup[i].ThrumCurveSeq=0xffff;
						}
					}
				}
			}
		}
	}
	if(CurveNum>2)
	{DPSGII_CrossConclusion();}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////��ͼ
//  2.IplImage * Img_sign: ��̽��������ͼ
//  3.int nWidth��������ĻҶ�ͼ������
//  4.int nHeight��������ĻҶ�ͼ����߶�
//  5.int R�������뾶
//  6.int DirectionN��ֱ��̽�ⷶΧ
//  7.int NormThre��������ֵ
//  8.int CrossAngle�������߽������С�Ƕ�
//  9.int MinLine����С��ʼ������ֱ�߳���
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��03��31��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_AutoLineSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine)
{
	int x=0;
	int y=0;
	int i=0;
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			//̽��ͼ�����������ͨ�ĺڵ㣬���ͼ���������޺ڵ�İ׵�,����Ϊ�ǿ��ܵ���ʼ��
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=4)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<3))))
			{
				//����ʼ��ͷ
				StartThrum[StartThrumNum]=DPSGII_StartThrumSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout);
				//��ʼ��ͷ���ڳ���Ҫ����MinLine
				if(StartThrum[StartThrumNum].ThrumDist>MinLine)
				{
					DPSGII_StartThrumToThrum(&StartThrum[StartThrumNum],&ThrumTemp);
					DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_history,nWidth,nHeight,Rin,&ThrumTemp);
				    StartThrumNum++;
     			}

			}
		}
	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_Clear()
//	�������� ����̽�����߽ṹ����ʼ�㡢ֱ�߶Ρ����ߡ�������ȫ������
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ���޸��˵�StartThrum��ThrumGroup��urveGroup��FeaturePoint��MaxCurveGroup��CircleGroup
//	��ڲ���˵�� ����
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_Clear()
{
	StartThrumNum=0;//��ʼ�߶����
	memset(StartThrum,0,CURVEMAXNUM*sizeof(StartThrumInfo));//���CurveGroup[CURVEMAXNUM]
	memset(&StartThrumTemp,0,sizeof(StartThrumInfo));
	ThrumNum=0;
	memset(ThrumGroup,0,THRUMMAXNUM*sizeof(ThrumInfo));//���ThrumGroup[THRUMMAXNUM]
	memset(&ThrumTemp,0,sizeof(ThrumInfo));//���ThrumTemp
	CurveNum=0;
	memset(CurveGroup,0,CURVEMAXNUM*sizeof(CurveInfo));//���CurveGroup[CURVEMAXNUM]
	FeaturePointNum=0;
	memset(FeaturePoint,0,CURVEMAXNUM*sizeof(FeaturePointInfo));
	memset(MaxCurveGroup,0,MAXCURVENUM*sizeof(unsigned short)<<1);//ǰʮ�����߼�¼��
	memset(CircleGroup,0,CIRCLENUM*sizeof(unsigned short)<<2);//Բ��¼��
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_Result(int& StartThrumNumOut,int& ThrumNumOut, int&CurveNumOut)
//	�������� ����̽�����߽ṹ����ʼ�㡢ֱ�߶Ρ����ߵ���������
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ ��̽�⵽�����߽ṹ����ʼ�㡢ֱ�߶Ρ����ߵ�����
//	��ڲ���˵�� ��
//  1.int& StartThrumNumOut: ��ʼ����������ֵ
//  2.int& ThrumNumOut: ֱ�߶���������ֵ
//  3.int& CurveNumOut: ������������ֵ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_Result(int& StartThrumNumOut,int& ThrumNumOut, int&CurveNumOut)
{
	StartThrumNumOut=StartThrumNum;
	ThrumNumOut=ThrumNum;
	CurveNumOut=CurveNum;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��StartThrumInfo * DPSGII_StartThrum(int StartThrumNumNow)
//	�������� ����ָ����ʼ����Ϣ����
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ��StartThrumNumNow����ʼ����Ϣ
//	��ڲ���˵�� ��
//  1.int StartThrumNumOut: ָ�����ص���ʼ�����
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
StartThrumInfo * DPSGII_StartThrum(int StartThrumNumNow)
{
	return &StartThrum[StartThrumNumNow];
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��CurveInfo * DPSGII_Curve(int CurveNumNow)
//	�������� ����ָ��������Ϣ����
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ��CurveNumNow��������Ϣ
//	��ڲ���˵�� ��
//  1.int CurveNumNow: ָ�����ص��������
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
CurveInfo * DPSGII_Curve(int CurveNumNow)
{
	return &CurveGroup[CurveNumNow];
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��unsigned short * DPSGII_MaxCurve(int MaxSeq)
//	�������� ����ָ�������˳��ŷ���
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ��MaxSeq��������Ϣ
//	��ڲ���˵�� ��
//  1.int MaxSeq: ָ�����ص���������
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
unsigned short  DPSGII_MaxCurve(int MaxSeq)
{
	return MaxCurveGroup[MaxSeq][0];
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��ThrumInfo * DPSGII_Thrum(int ThrumNumNow)
//	�������� ����ָ��ֱ�߶���Ϣ����
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ��ThrumNumNow��ֱ�߶���Ϣ
//	��ڲ���˵�� ��
//  1.int ThrumNumNow: ָ�����ص�ֱ�߶����
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
ThrumInfo * DPSGII_Thrum(int ThrumNumNow)
{
	return &ThrumGroup[ThrumNumNow];
}
ThrumInfo * DPSGII_ConLine(int ConLineNumNow)
{
	return &LineConnect[ConLineNumNow];
}
ThrumInfo * DPSGII_ParallelLine(int ConLineNumNow)
{
	return &LineParallel[ConLineNumNow];
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��FeaturePointInfo * DPSGII_FeaturePoint(int FeaturePointNow)
//	�������� ����ָ����������Ϣ����
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ��FeaturePointNow����������Ϣ
//	��ڲ���˵�� ��
//  1.int FeaturePointNow: ָ�����ص����������
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
FeaturePointInfo * DPSGII_FeaturePoint(int FeaturePointNow)
{
	return &FeaturePoint[FeaturePointNow];
}


////////////////////////////////////////////////////////////////////////
//	�� �� �� ��bool RegionBetweenAngle(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
//	�������� �����һ����������������������������н����Ƿ��м��
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ ��0���޼�� 1���м��
//	��ڲ���˵�� ��
//	1.StepStrucureII *ThrumRegion��������Ķ�ֵͼ
//  2.unsigned char AngleOne: �Ƕ�1
//  3.unsigned char AngleTwo: �Ƕ�2
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////	
bool RegionBetweenAngle(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
{
	int i=0;
	bool RegionSign =false;
	char AngleSubOne=0;
	char AngleSubTwo=0;
	if(AngleOne==AngleTwo)
	{return RegionSign;}
	if(AngleTwo-AngleOne==32)
	{
		for(i=AngleOne+1;i<AngleTwo;i++)
		{
			if((ThrumRegion+i)->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}
		}
	}
	else if(AngleOne-AngleTwo==32)
	{
		for(i=1;i<32;i++)
		{
			if((ThrumRegion+ CircleII[64+AngleOne+i])->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}

		}
	}
	else if(AngleTwo<AngleOne)
	{
		AngleSubOne=AngleOne;
		AngleOne=AngleTwo;
		AngleTwo=AngleSubOne;
	}
	AngleSubOne=AngleTwo-AngleOne;
	AngleSubTwo=AngleOne-AngleTwo+64;
	if(AngleSubOne<AngleSubTwo)
	{
		for(i=AngleOne+1;i<AngleTwo;i++)
		{
			if((ThrumRegion+i)->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}
		}
	}
	else
	{
		for(i=1;i<AngleSubTwo;i++)
		{
			if((ThrumRegion+ CircleII[64+AngleTwo+i])->stepdistense<0.1)
			{
				RegionSign=true;
				break;
			}
		}
	}
	return RegionSign;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��bool RegionBetweenAngleII(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
//	�������� �����һ����������������������������н����Ƿ��м��
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ ��0���޼�� 1���м��
//	��ڲ���˵�� ��
//	1.StepStrucureII *ThrumRegion��������Ķ�ֵͼ
//  2.unsigned char AngleOne: �Ƕ�1
//  3.unsigned char AngleTwo: �Ƕ�2
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////	
bool RegionBetweenAngleII(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
{
	int i=0;
	bool RegionSign =false;
	char AngleSub;
	if(AngleOne==AngleTwo)
	{return RegionSign;}
	else if(AngleOne<AngleTwo)
	{
		for(i=AngleOne+1;i<AngleTwo;i++)
		{
			if((ThrumRegion+i)->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}
		}

	}
	else
	{
		AngleSub=AngleOne-AngleTwo;
		for(i=1;i<AngleSub;i++)
		{
			if((ThrumRegion+ CircleII[64+AngleTwo+i])->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}

		}


	}
	return RegionSign;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��FeaturePointInfo DPSGII_FeaturePointSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
//	�������� ������Img_binָ�����������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ָ�����������ϢStartThrumInfo StartThrumNow�ṹ��
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int cenX��ָ���������
//	5.int cenY��ָ���������
//	6.int R����ֵͼ�����뾶
//  7.int Rout���⻷�뾶
//  8.int NormThre��������ֵ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
FeaturePointInfo DPSGII_FeaturePointSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
{
	FeaturePointInfo FeaturePointNow;
	int i=0;
	memset(&FeaturePointNow,0,sizeof(FeaturePointInfo));
	unsigned char Max32Direction=0;//���32����
    double Max32PDC=0.0;//������׶�
	double TotalPDC=0.0;//���Ⱥ�
	double ThrumTest32[33] = {0};
	unsigned char Min64Direction=0;//��С����
	double Min64PDC=1000.0;//��С64�����׶�
	unsigned char Min32Direction=0;//��С����
	double Min32PDC=1000.0;//��С32�����׶�
	StepStrucureII ThrumTest64[65] = {0};
	for(i=1;i<33;i++)
	{
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>Max32PDC)
		{
			Max32PDC=ThrumTest32[i];
			Max32Direction=i;
		}
		if(ThrumTest32[i]<Min32PDC)
		{
			Min32PDC=ThrumTest32[i];
			Min32Direction=i;
		}
		if(ThrumTest64[i].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i].stepdistense;
			Min64Direction=i;
		}
		if(ThrumTest64[i+32].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i+32].stepdistense;
			Min64Direction=i+32;
		}
		TotalPDC+=ThrumTest64[i].stepdistense;
	}
	/*����ԭ�㣬���ֱ�߷������ֱ�߳���*/
	FeaturePointNow.FeaturePointPos.x=cenX;
	FeaturePointNow.FeaturePointPos.y=cenY;
	FeaturePointNow.ThrumDist=Max32PDC;
	FeaturePointNow.ThrumDire=Max32Direction;
	/*�������᷽�򡢶��᷽�򣬶��᷽���Ӧ��㣬���᷽���Ӧ�յ�*/
	if(ThrumTest64[Max32Direction].stepdistense>ThrumTest64[Max32Direction+32].stepdistense)
	{
		FeaturePointNow.LongDir=Max32Direction;
		FeaturePointNow.LoneDis=ThrumTest64[Max32Direction].stepdistense;
		FeaturePointNow.ShortDir=Max32Direction+32;
		FeaturePointNow.ShortDis=ThrumTest64[Max32Direction+32].stepdistense;
		FeaturePointNow.ThrumStart.x=ThrumTest64[Max32Direction+32].xstep;
		FeaturePointNow.ThrumStart.y=ThrumTest64[Max32Direction+32].ystep;
		FeaturePointNow.ThrumEnd.x=ThrumTest64[Max32Direction].xstep;
		FeaturePointNow.ThrumEnd.y=ThrumTest64[Max32Direction].ystep;
	}
	else
	{
		FeaturePointNow.LongDir=Max32Direction+32;
		FeaturePointNow.LoneDis=ThrumTest64[Max32Direction+32].stepdistense;
		FeaturePointNow.ShortDir=Max32Direction;
		FeaturePointNow.ShortDis=ThrumTest64[Max32Direction].stepdistense;
		FeaturePointNow.ThrumStart.x=ThrumTest64[Max32Direction].xstep;
		FeaturePointNow.ThrumStart.y=ThrumTest64[Max32Direction].ystep;
		FeaturePointNow.ThrumEnd.x=ThrumTest64[Max32Direction+32].xstep;
		FeaturePointNow.ThrumEnd.y=ThrumTest64[Max32Direction+32].ystep;
	}
	/*ÿ�������е�,˵��λ�ڽϿ������÷��߽߱�����С̽����������ȥ*/
	if(Min64PDC>0.0)
	{
		FeaturePointNow.PointNormOne.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormOne.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormOne=Min64Direction;
		FeaturePointNow.NormOneDis=ThrumTest64[Min64Direction].stepdistense;
		if(Min64Direction>32)
		{Min64Direction-=32;}
		else
		{Min64Direction+=32;}
		FeaturePointNow.PointNormTwo.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormTwo.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormTwo=Min64Direction;
		FeaturePointNow.NormTwoDis=ThrumTest64[Min64Direction].stepdistense;
		FeaturePointNow.FeaturePointType=0xff;
		return FeaturePointNow;
	}
	else if(Min32PDC>0.1)
	{
		if(ThrumTest64[Min32Direction].stepdistense>ThrumTest64[Min32Direction+32].stepdistense)
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormOne=Min32Direction;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormTwo=Min32Direction+32;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction+32].stepdistense;
		}
		else
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormOne=Min32Direction+32;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction+32].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormTwo=Min32Direction;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction].stepdistense;

		}
		FeaturePointNow.FeaturePointType=0xf0;
		return FeaturePointNow;

	}
	/*�������߷���ͷ��߽߱�*/
	int NormOne=CircleII[64+Max32Direction+16];//���߷���1
	int NormTwo=CircleII[64+Max32Direction-16];//���߷���2
	FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+15];//���߷���1
		NormTwo=CircleII[64+Max32Direction-17];//���߷���2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+17];//���߷���1
		NormTwo=CircleII[64+Max32Direction-15];//���߷���2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+18];//���߷���1
		NormTwo=CircleII[64+Max32Direction-14];//���߷���2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+14];//���߷���1
		NormTwo=CircleII[64+Max32Direction-18];//���߷���2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}

	FeaturePointNow.NormOne=NormOne;
	FeaturePointNow.NormOneDis=ThrumTest64[NormOne].stepdistense;
	FeaturePointNow.PointNormOne.x=ThrumTest64[NormOne].xstep;
	FeaturePointNow.PointNormOne.y=ThrumTest64[NormOne].ystep;
	FeaturePointNow.NormTwo=NormTwo;
	FeaturePointNow.NormTwoDis=ThrumTest64[NormTwo].stepdistense;
	FeaturePointNow.PointNormTwo.x=ThrumTest64[NormTwo].xstep;
	FeaturePointNow.PointNormTwo.y=ThrumTest64[NormTwo].ystep;
	if(FeaturePointNow.ThrumDist*2<TotalPDC)
	{
		FeaturePointNow.FeaturePointType=0xf;
		return FeaturePointNow;
    }
	bool RegionSign[5]={0};
	RegionSign[1]=RegionBetweenAngleII(&ThrumTest64[0],Max32Direction,NormOne);
	RegionSign[2]=RegionBetweenAngleII(&ThrumTest64[0],NormOne,Max32Direction+32);
	RegionSign[3]=RegionBetweenAngleII(&ThrumTest64[0],Max32Direction+32,NormTwo);
	RegionSign[4]=RegionBetweenAngleII(&ThrumTest64[0],NormTwo,Max32Direction);
	RegionSign[0]=RegionSign[1]*RegionSign[2]*RegionSign[3]*RegionSign[4];
	if(FeaturePointNow.ThrumNormdis<NormThre)
	{
		FeaturePointNow.FeaturePointType=2;
		if(FeaturePointNow.ShortDis<(4*R)&&FeaturePointNow.ThrumNormdis<(FeaturePointNow.ThrumDist*0.25))//�̷���ͷ�����߿��С����ͷ�����ķ�֮һ
		{
			if((fabs(FeaturePointNow.NormOneDis-FeaturePointNow.NormTwoDis)<(R*2))&&(min(FeaturePointNow.NormOneDis,FeaturePointNow.NormTwoDis)>0.1))//ȡ�������м�
			{FeaturePointNow.FeaturePointType=1;}
		}
		return FeaturePointNow;
	}
	
	if(min(FeaturePointNow.NormOneDis,FeaturePointNow.NormTwoDis)>min(FeaturePointNow.ThrumDist*0.25,NormThre*0.5))//���߿�ȱȽϿ�
	{
		if(RegionSign[0])
		{FeaturePointNow.FeaturePointType=4;}
	}
   	return FeaturePointNow;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��FeaturePointInfo DPSGII_FeaturePointShield(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
//	�������� ������Img_binָ�����������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ָ�����������ϢStartThrumInfo StartThrumNow�ṹ�壬ֻ���������Ͱ�������е�������
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int cenX��ָ���������
//	5.int cenY��ָ���������
//	6.int R����ֵͼ�����뾶
//  7.int Rout���⻷�뾶
//  8.int NormThre��������ֵ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
FeaturePointInfo DPSGII_FeaturePointShield(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
{
	FeaturePointInfo FeaturePointNow;
	int i=0;
	memset(&FeaturePointNow,0,sizeof(FeaturePointInfo));
	unsigned char Max32Direction=0;//���32����
    double Max32PDC=0.0;//������׶�
	double TotalPDC=0.0;//���Ⱥ�
	double ThrumTest32[33] = {0};
	unsigned char Min64Direction=0;//��С����
	double Min64PDC=1000.0;//��С64�����׶�
	unsigned char Min32Direction=0;//��С����
	double Min32PDC=1000.0;//��С32�����׶�
	StepStrucureII ThrumTest64[65] = {0};
	for(i=1;i<33;i++)
	{
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>Max32PDC)
		{
			Max32PDC=ThrumTest32[i];
			Max32Direction=i;
		}
		if(ThrumTest32[i]<Min32PDC)
		{
			Min32PDC=ThrumTest32[i];
			Min32Direction=i;
		}
		if(ThrumTest64[i].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i].stepdistense;
			Min64Direction=i;
		}
		if(ThrumTest64[i+32].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i+32].stepdistense;
			Min64Direction=i+32;
		}
		TotalPDC+=ThrumTest64[i].stepdistense;
	}
	///*����ԭ�㣬���ֱ�߷������ֱ�߳���*/
	FeaturePointNow.FeaturePointPos.x=cenX;
	FeaturePointNow.FeaturePointPos.y=cenY;
	FeaturePointNow.ThrumDist=Max32PDC;
	FeaturePointNow.ThrumDire=Max32Direction;
	/*ÿ�������е�,˵��λ�ڽϿ������÷��߽߱�����С̽����������ȥ*/
	if(Min64PDC>0.0)
	{
		FeaturePointNow.PointNormOne.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormOne.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormOne=Min64Direction;
		FeaturePointNow.NormOneDis=ThrumTest64[Min64Direction].stepdistense;
		if(Min64Direction>32)
		{Min64Direction-=32;}
		else
		{Min64Direction+=32;}
		FeaturePointNow.PointNormTwo.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormTwo.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormTwo=Min64Direction;
		FeaturePointNow.NormTwoDis=ThrumTest64[Min64Direction].stepdistense;
		FeaturePointNow.FeaturePointType=0xff;
		return FeaturePointNow;
	}
	else if(Min32PDC>0.1)
	{
		if(ThrumTest64[Min32Direction].stepdistense>ThrumTest64[Min32Direction+32].stepdistense)
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormOne=Min32Direction;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormTwo=Min32Direction+32;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction+32].stepdistense;
		}
		else
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormOne=Min32Direction+32;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction+32].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormTwo=Min32Direction;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction].stepdistense;

		}
		FeaturePointNow.FeaturePointType=0xf0;
		return FeaturePointNow;

	}
   	return FeaturePointNow;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��bool DPSGII_FeaturePointSetSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
//	�������� ����ָ����FeaturePointNow��Ϣ���Img_signͼ
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� �������Ƿ��������������㣬1���ڣ�0������
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int R����ֵͼ�����뾶
//  5.FeaturePointInfo* FeaturePointNow��ָ����FeaturePointNow
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
bool DPSGII_FeaturePointSetSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
{
	int x=0;
	int y=0;
	bool FeaturePointSign=false;
	int cenX=FeaturePointNow->FeaturePointPos.x;
	int cenY=FeaturePointNow->FeaturePointPos.y;
	int NormRadii=0;
	int startX=FeaturePointNow->ThrumStart.x;
	int startY=FeaturePointNow->ThrumStart.y;
	int startDir=FeaturePointNow->ShortDir;
	int endX=FeaturePointNow->ThrumEnd.x;
	int endY=FeaturePointNow->ThrumEnd.y;
	int endDir=FeaturePointNow->LongDir;
	int normOneDir=FeaturePointNow->NormOne;
	int normOneX=FeaturePointNow->PointNormOne.x;
	int normOneY=FeaturePointNow->PointNormOne.y;
	int normTwoDir=FeaturePointNow->NormTwo;
	int normTwoX=FeaturePointNow->PointNormTwo.x;
	int normTwoY=FeaturePointNow->PointNormTwo.y;
	switch(FeaturePointNow->FeaturePointType)
	{
	case 0xff:
		FeaturePointSign=false;
		NormRadii=int(FeaturePointNow->NormOneDis+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
			{break;}*/
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
				{break;}
				else*/
				{((unsigned char*)(Img_sign + nWidth*y))[x]=0;}
			}
		}
		break;
	case 0xf0:
		FeaturePointSign=false;
		DPSGII_SetRegionValue(Img_sign,nWidth, nHeight,cenX,cenY,normOneX,normOneY,0);
		break;
	case 0xf:
		FeaturePointSign=false;
		 while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;

		 }
		break;
	case 0x1:
		 while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;
		}
		FeaturePointSign=true;
		break;
	case 0x2:
		//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
	/*	 while(cenX!=endX||cenY!=endY)
		{*/
			//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			//((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			//((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
		/*	cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;*/
		//}
		FeaturePointSign=true;
		break;
	case 0x3:
		//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
		FeaturePointSign=true;
		break;
	case 0x4:
		NormRadii=int(min(min(FeaturePointNow->NormOneDis,FeaturePointNow->NormTwoDis),FeaturePointNow->ShortDis)+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				((unsigned char*)(Img_sign + nWidth*y))[x]=0;
			}
		}

		FeaturePointSign=true;
		break;
	default:
		break;
	}

	
	return  FeaturePointSign;
}
bool DPSGII_FeaturePointBlockArea(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
{
	int x=0;
	int y=0;
	bool FeaturePointSign=false;
	int cenX=FeaturePointNow->FeaturePointPos.x;
	int cenY=FeaturePointNow->FeaturePointPos.y;
	int NormRadii=0;
	int startX=FeaturePointNow->ThrumStart.x;
	int startY=FeaturePointNow->ThrumStart.y;
	int startDir=FeaturePointNow->ShortDir;
	int endX=FeaturePointNow->ThrumEnd.x;
	int endY=FeaturePointNow->ThrumEnd.y;
	int endDir=FeaturePointNow->LongDir;
	int normOneDir=FeaturePointNow->NormOne;
	int normOneX=FeaturePointNow->PointNormOne.x;
	int normOneY=FeaturePointNow->PointNormOne.y;
	int normTwoDir=FeaturePointNow->NormTwo;
	int normTwoX=FeaturePointNow->PointNormTwo.x;
	int normTwoY=FeaturePointNow->PointNormTwo.y;
	switch(FeaturePointNow->FeaturePointType)
	{
	case 0xff:
		FeaturePointSign=false;
		NormRadii=int(FeaturePointNow->NormOneDis+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
			{break;}*/
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
				{break;}
				else*/
				{((unsigned char*)(Img_sign + nWidth*y))[x]=0;}
			}
		}
		break;
	case 0xf0:
		FeaturePointSign=false;
		DPSGII_SetRegionValue(Img_sign,nWidth, nHeight,cenX,cenY,normOneX,normOneY,0);
		break;
	case 0xf:
		FeaturePointSign=false;
		/* while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;

		 }*/
		break;
	case 0x1:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
	/*	 while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;
		}*/
		FeaturePointSign=false;
		break;
	case 0x2:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
	/*	 while(cenX!=endX||cenY!=endY)
		{*/
			//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			//((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			//((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
		/*	cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;*/
		//}
		FeaturePointSign=true;
		break;
	case 0x3:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
		FeaturePointSign=false;
		break;
	case 0x4:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
	/*	NormRadii=int(min(min(FeaturePointNow->NormOneDis,FeaturePointNow->NormTwoDis),FeaturePointNow->ShortDis)+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				((unsigned char*)(Img_sign + nWidth*y))[x]=0;
			}
		}*/

		FeaturePointSign=false;
		break;
	default:
		break;
	}

	/*if(FeaturePointNow->FeaturePointType==2)
	{
		return true;
	}
	else 
	{
		return false;
	}*/
	return  FeaturePointSign;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��bool DPSGII_FeaturePointShieldSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
//	�������� ����ָ����FeaturePointNow��Ϣ���Img_signͼ
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� �������Ƿ��������������㣬1���ڣ�0������
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//  2.int nWidth: ��ֵͼ���
//  3.int nHeight: ��ֵͼ�߶�
//	4.int R����ֵͼ�����뾶
//  5.FeaturePointInfo* FeaturePointNow��ָ����FeaturePointNow
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
bool DPSGII_FeaturePointShieldSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
{
	int x=0;
	int y=0;
	bool FeaturePointSign=false;
	int cenX=FeaturePointNow->FeaturePointPos.x;
	int cenY=FeaturePointNow->FeaturePointPos.y;
	int NormRadii=0;
	int startX=FeaturePointNow->ThrumStart.x;
	int startY=FeaturePointNow->ThrumStart.y;
	int startDir=FeaturePointNow->ShortDir;
	int endX=FeaturePointNow->ThrumEnd.x;
	int endY=FeaturePointNow->ThrumEnd.y;
	int endDir=FeaturePointNow->LongDir;
	int normOneDir=FeaturePointNow->NormOne;
	int normOneX=FeaturePointNow->PointNormOne.x;
	int normOneY=FeaturePointNow->PointNormOne.y;
	int normTwoDir=FeaturePointNow->NormTwo;
	int normTwoX=FeaturePointNow->PointNormTwo.x;
	int normTwoY=FeaturePointNow->PointNormTwo.y;
	switch(FeaturePointNow->FeaturePointType)
	{
	case 0xff:
		FeaturePointSign=false;
		NormRadii=int(FeaturePointNow->NormOneDis+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				{((unsigned char*)(Img_sign + nWidth*y))[x]=0;}
			}
		}
		break;
	case 0xf0:
		FeaturePointSign=false;
		DPSGII_SetRegionValue(Img_sign,nWidth, nHeight,cenX,cenY,normOneX,normOneY,0);
		break;
	
	default:
		break;
	}
	return  FeaturePointSign;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int DPSGII_FeaturePointSearch(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
//	�������� ������Img_binָ�������������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ����������ĸ���
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//	2.unsigned char* Img_sign��������Ķ�ֵͼ
//  3.int nWidth: ��ֵͼ���
//  4.int nHeight: ��ֵͼ�߶�
//	5.int Rin����ֵͼ�����뾶
//  6.int Rout���⻷�뾶
//  7.int NormThre��������ֵ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
int DPSGII_FeaturePointSearch(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
{
	 int y=0;
     int x=0;
	 int i=0;
	 FeaturePointNum=0;
	 bool FeaturePointSign=false;
	 int AdnateNum=0;
	// StepStrucureII RectDistriTemp; 
	 memset(FeaturePoint,0,CURVEMAXNUM*sizeof(FeaturePointInfo));//���CurveGroup[CURVEMAXNUM]
	 for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			if(FeaturePointNum==CURVEMAXNUM)
			{break;}
			FeaturePointSign=false;
			//DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin);//counter point in background
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			 {
				  FeaturePoint[FeaturePointNum]=DPSGII_FeaturePointSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout,NormThre);
				  FeaturePointSign=DPSGII_FeaturePointSetSign(Img_sign,nWidth,nHeight,Rin,&FeaturePoint[FeaturePointNum]);
	              FeaturePointNum+=FeaturePointSign;	
			}
		}
	 }
	 return  FeaturePointNum;
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_FeaturePointSearchShield(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
//	�������� ��������㡢����������ε�
//	��    �� ��������
//	ʱ    �� ��2012��09��09��
//	�� �� ֵ �� ������㡢����������ε���Img_signͼ
//	��ڲ���˵�� ��
//	1.unsigned char* Img_bin��������Ķ�ֵͼ
//	2.unsigned char* Img_sign��������Ķ�ֵͼ
//  3.int nWidth: ��ֵͼ���
//  4.int nHeight: ��ֵͼ�߶�
//	5.int Rin����ֵͼ�����뾶
//  6.int Rout���⻷�뾶
//  7.int NormThre��������ֵ
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��09��	������	����������
//	////////////////////////////////////////////////////////////////////////
void DPSGII_FeaturePointSearchShield(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
{
	 int y=0;
     int x=0;
	 int i=0;
	 FeaturePointNum=0;
	 bool FeaturePointSign=false;
	 int AdnateNum=0;
	// StepStrucureII RectDistriTemp; 
	 memset(FeaturePoint,0,CURVEMAXNUM*sizeof(FeaturePointInfo));//���CurveGroup[CURVEMAXNUM]
	 for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			FeaturePointSign=false;
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			 {
				  FeaturePoint[FeaturePointNum]=DPSGII_FeaturePointShield(Img_bin,nWidth,nHeight,x,y,Rin,Rout,NormThre);
				  FeaturePointSign=DPSGII_FeaturePointShieldSign(Img_sign,nWidth,nHeight,Rin,&FeaturePoint[FeaturePointNum]);
	              //FeaturePointNum+=FeaturePointSign;	
			}
		}
	 }
}
void StepStrucureQuickSort(StepStrucureII * Level,int Left,int Right, int Index,int Usednum)
{
	int i,j;
	
	double pivot;//�ָ�ָ��
	int pivotads=0;//�ָ�λ��v
	i=Left;	j=Right+1;//����i,j�ֱ�Ϊ���������ָ��
	StepStrucureII TempDistance;
	pivot=Level[Left].stepdistense;
	if(i<j)
	{ do
		{
			/*���������ұ�pivot���ֵ*/
			do
			{i++;
			}while(Level[i].stepdistense<pivot&&i<=Right);
            /*���������ұ�pivotС��ֵ*/
			do
			{j--;
			}while(Level[j].stepdistense>pivot&&j>Left);
			if(i<j)
			{
				    TempDistance.stepdistense=Level[i].stepdistense;
					Level[i].stepdistense=Level[j].stepdistense;
					Level[j].stepdistense=TempDistance.stepdistense;
					TempDistance.xstep=Level[i].xstep;
					Level[i].xstep=Level[j].xstep;
					Level[j].xstep=TempDistance.xstep;
					TempDistance.ystep=Level[i].ystep;
					Level[i].ystep=Level[j].ystep;
					Level[j].ystep=TempDistance.ystep;
			}
		}while(i<j);
		 TempDistance.stepdistense=Level[Left].stepdistense;
		 Level[Left].stepdistense=Level[j].stepdistense;
		 Level[j].stepdistense=TempDistance.stepdistense;
		 TempDistance.xstep=Level[Left].xstep;
		 Level[Left].xstep=Level[j].xstep;
		 Level[j].xstep=TempDistance.xstep;
		 TempDistance.ystep=Level[Left].ystep;
		 Level[Left].ystep=Level[j].ystep;
		 Level[j].ystep=TempDistance.ystep;
		 if(j+1-Left>Usednum)
		 {
	//		 QuickSort(Level,Left,j-1,j,Usednum);
			StepStrucureQuickSort(Level,Left,j-1,Index,Usednum);
		 }//��������
		 else if(j+1-Left==Usednum)
	//	 {QuickSort(Level,Left,j-1,j,Usednum-1);}
	     {StepStrucureQuickSort(Level,Left,j-1,Index,Usednum-1);}
		 else 
		 {
           //  QuickSort(Level,Left,j-1,j,j);//��������
			  StepStrucureQuickSort(Level,Left,j-1,Index,j);
			 StepStrucureQuickSort(Level,j+1,Right,Index,Usednum-(j+1-Left));//�����Ұ��
		 }
		 
//		  QuickSort(Level,Left,j-1,Index,Usednum);
//		   QuickSort(Level,j+1,Right,Index,Usednum);
		
        
	}
}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int CopyLineFromCurve()
//	�������� ������ֱ���ж�
//	��    �� ��������
//	ʱ    �� ��2012��09��19��
//	�� �� ֵ �� ����ֱ������
//	��ڲ���˵�� ��
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��19��	������	����������
//	////////////////////////////////////////////////////////////////////////
//int CopyLineFromCurve()
//{
//	LineNum=0;
//	int i=0;
//	int j=0;
//	CGPOINT PStart ;
//	CGPOINT PEnd ;
//	CGPOINT PStartII;
//	CGPOINT PEndII;
//	double LineDis;
//	double MinDis=10000.0;
//	int DisType=0;
//	LINE CoLine;
//	
//	double CoLineAngle=0.0;
//	ConLineNum=0;
//	if(CurveNum>0&&CurveNum<CURVEMAXNUM)
//	{
//		for(i=0;i<CurveNum;i++)
//		{
//			if(CurveGroup[i].Curvetype==1)
//			{
//				PStart.x=CurveGroup[i].CurveStart.x;
//				PStart.y=CurveGroup[i].CurveStart.y;
//				PEnd.x=CurveGroup[i].CurveEnd.x;
//				PEnd.y=CurveGroup[i].CurveEnd.y;
//				LineGroup[i]=makeline(PStart,PEnd);
//				LinePara[LineNum].xstep=i;
//				LinePara[LineNum].ystep=LineNum;
//				LinePara[LineNum].stepdistense=180-alpha(LineGroup[i])*180/PI;
//				//TRACE(_T("NO.%dCurve is LineSeg%d,Start[%d,%d],End[%d,%d],ALPHA%f,CurveDire%f\n"),LinePara[LineNum].xstep,LinePara[LineNum].ystep,CurveGroup[i].CurveStart.x,CurveGroup[i].CurveStart.y,CurveGroup[i].CurveEnd.x,CurveGroup[i].CurveEnd.y,LinePara[LineNum].stepdistense);
//				LineNum++;
//				if(LineNum==LINENUM)
//				{break;}
//
//			}
//
//		}
//		StepStrucureQuickSort(LinePara,0,LineNum-1,LineNum,LineNum);
//	
//		for(i=0;i<LineNum;i++)
//		{
//			
//			//TRACE(_T("NO.%dCurve is LineSeg%d,ALPHA%f\n"),LinePara[i].xstep,LinePara[i].ystep,LinePara[i].stepdistense);
//			j=i+1;
//			while(abs(LinePara[j].stepdistense-LinePara[i].stepdistense)<COLINEANGLE)
//			{
//				MinDis=10000.0;
//				PStart.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
//				PStart.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
//				PEnd.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
//				PEnd.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
//				PStartII.x=CurveGroup[LinePara[j].xstep].CurveStart.x;
//				PStartII.y=CurveGroup[LinePara[j].xstep].CurveStart.y;
//				PEndII.x=CurveGroup[LinePara[j].xstep].CurveEnd.x;
//				PEndII.y=CurveGroup[LinePara[j].xstep].CurveEnd.y;
//				LineDis=dist(PStart,PStartII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=1;
//				}
//				LineDis=dist(PStart,PEndII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=2;
//				}
//				LineDis=dist(PEnd,PStartII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=3;
//				}
//				LineDis=dist(PEnd,PEndII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=4;
//				}
//	            switch(DisType)
//				{
//				case 1://��ͷ��ͷ����ͷ���䣬��β���ͷ
//				PEndII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
//				PEndII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
//				break;
//				case 2://��ͷ��β����β���䣬��ͷ���ͷ
//				PStartII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
//				PStartII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
//				break;
//				case 3://��β��ͷ����ͷ���䣬��β���β
//				PEndII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
//				PEndII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
//				break;
//				case 4://��β��β����β���䣬��ͷ���β
//				PStartII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
//				PStartII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
//				break;
//
//				}
//	            CoLine=makeline(PStartII,PEndII);
//				CoLineAngle=180-alpha(CoLine)*180/PI;
//				if(MinDis<COLINEDIS&&abs(LinePara[i].stepdistense-CoLineAngle)<COLINEANGLE&&abs(CoLineAngle-LinePara[j].stepdistense)<COLINEANGLE)
//				{
//					
//					LineConnect[ConLineNum].ThrumStart.x=PStartII.x+0.5;
//					LineConnect[ConLineNum].ThrumStart.y=PStartII.y+0.5;
//					LineConnect[ConLineNum].ThrumEnd.x=PEndII.x+0.5;
//					LineConnect[ConLineNum].ThrumEnd.y=PEndII.y+0.5;
//					LineConnect[ConLineNum].ThrumDire=LinePara[i].xstep;
//					LineConnect[ConLineNum].ThrumCurveSeq=LinePara[j].xstep;
//					LineConnect[ConLineNum].ThrumDist=dist(PStartII,PEndII);
//					TRACE(_T("NO.%dCurve and NO.%dCurve should be connected with Dist%f!\n"),LinePara[i].xstep,LinePara[j].xstep,LineConnect[ConLineNum].ThrumDist);
//					ConLineNum++;
//					if(ConLineNum>1)
//					{
//						if((LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumStart.y)
//							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumEnd.y)
//							||(LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumEnd.y)
//							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumStart.y))
//						{
//							if(LineConnect[ConLineNum-1].ThrumDist<LineConnect[ConLineNum-2].ThrumDist)
//							{
//								LineConnect[ConLineNum-2].ThrumStart.x=LineConnect[ConLineNum-1].ThrumStart.x;
//								LineConnect[ConLineNum-2].ThrumStart.y=LineConnect[ConLineNum-1].ThrumStart.y;
//								LineConnect[ConLineNum-2].ThrumEnd.x=LineConnect[ConLineNum-1].ThrumEnd.x;
//								LineConnect[ConLineNum-2].ThrumEnd.y=LineConnect[ConLineNum-1].ThrumEnd.y;
//								LineConnect[ConLineNum-2].ThrumDire=LineConnect[ConLineNum-1].ThrumDire;
//								LineConnect[ConLineNum-2].ThrumCurveSeq=LineConnect[ConLineNum-1].ThrumCurveSeq;
//								LineConnect[ConLineNum-2].ThrumDist=LineConnect[ConLineNum-1].ThrumDist;
//							}
//							ConLineNum--;
//						}
//					}
//				}
//
//				j++;
//			}
//			//i=j;
//		
//				
//
//		}
//
//
//	}
//	return ConLineNum;
//
//}
int CopyLineFromCurve()
{
	LineNum=0;
	int i=0;
	int j=0;
	CGPOINT PStart ;
	CGPOINT PEnd ;
	CGPOINT PStartII;
	CGPOINT PEndII;
	double LineDis;
	double MinDis=10000.0;
	int DisType=0;
	LINE CoLine;
	
	double CoLineAngle=0.0;
	ConLineNum=0;
	if(CurveNum>0&&CurveNum<CURVEMAXNUM)
	{
		for(i=0;i<CurveNum;i++)
		{
			if(CurveGroup[i].Curvetype==1)
			{
				PStart.x=CurveGroup[i].CurveStart.x;
				PStart.y=CurveGroup[i].CurveStart.y;
				PEnd.x=CurveGroup[i].CurveEnd.x;
				PEnd.y=CurveGroup[i].CurveEnd.y;
				LineGroup[i]=makeline(PStart,PEnd);
				LinePara[LineNum].xstep=i;
				LinePara[LineNum].ystep=LineNum;
				LinePara[LineNum].stepdistense=180-alpha(LineGroup[i])*180/PI;
				//TRACE(_T("NO.%dCurve is LineSeg%d,Start[%d,%d],End[%d,%d],ALPHA%f,CurveDire%f\n"),LinePara[LineNum].xstep,LinePara[LineNum].ystep,CurveGroup[i].CurveStart.x,CurveGroup[i].CurveStart.y,CurveGroup[i].CurveEnd.x,CurveGroup[i].CurveEnd.y,LinePara[LineNum].stepdistense);
				LineNum++;
				if(LineNum==LINENUM)
				{break;}

			}

		}
		StepStrucureQuickSort(LinePara,0,LineNum-1,LineNum,LineNum);
	
		for(i=0;i<LineNum;i++)
		{
			
			//TRACE(_T("NO.%dCurve is LineSeg%d,ALPHA%f\n"),LinePara[i].xstep,LinePara[i].ystep,LinePara[i].stepdistense);
			j=i+1;
			while(abs(LinePara[j].stepdistense-LinePara[i].stepdistense)<COLINEANGLE)
			{
				MinDis=10000.0;
				PStart.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStart.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				PEnd.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEnd.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				PStartII.x=CurveGroup[LinePara[j].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[j].xstep].CurveStart.y;
				PEndII.x=CurveGroup[LinePara[j].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[j].xstep].CurveEnd.y;
				LineDis=dist(PStart,PStartII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=1;
				}
				LineDis=dist(PStart,PEndII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=2;
				}
				LineDis=dist(PEnd,PStartII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=3;
				}
				LineDis=dist(PEnd,PEndII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=4;
				}
	            switch(DisType)//PStart-PEnd:Զ��;PStartII-PEndII:����
				{
				case 1://��ͷ��ͷ����ͷ���䣬��β���ͷ
				PStart.x=PEndII.x;
				PStart.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 2://��ͷ��β����β���䣬��ͷ���ͷ
                PStart.x=PStartII.x;
				PStart.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 3://��β��ͷ����ͷ���䣬��β���β
				PEnd.x=PEndII.x;
				PEnd.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;
				case 4://��β��β����β���䣬��ͷ���β
                PEnd.x=PStartII.x;
				PEnd.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;

				}
				TRACE(_T("i=%d,j=%d,PStart[%d,%d],PEnd[%d,%d],PStart[%d,%d],PEnd[%d,%d]\n"),i,j,(int)PStart.x,(int)PStart.y,(int)PEnd.x,(int)PEnd.y,(int)PStartII.x,(int)PStartII.y,(int)PEndII.x,(int)PEndII.y);
				//CoLine=makeline(PStartII,PEndII);
	           //CoLine=makeline(PStart,PEnd);
				CoLineAngle=180-alpha(CoLine)*180/PI;
				if(MinDis<COLINEDIS&&abs(LinePara[i].stepdistense-CoLineAngle)<COLINEANGLE&&abs(CoLineAngle-LinePara[j].stepdistense)<COLINEANGLE)
				{
					
					LineConnect[ConLineNum].ThrumStart.x=PStartII.x+0.5;
					LineConnect[ConLineNum].ThrumStart.y=PStartII.y+0.5;
					LineConnect[ConLineNum].ThrumEnd.x=PEndII.x+0.5;
					LineConnect[ConLineNum].ThrumEnd.y=PEndII.y+0.5;
					LineConnect[ConLineNum].ThrumDire=LinePara[i].xstep;
					LineConnect[ConLineNum].ThrumCurveSeq=LinePara[j].xstep;
					LineConnect[ConLineNum].ThrumDist=dist(PStartII,PEndII);
					TRACE(_T("NO.%dCurve and NO.%dCurve should be connected with Dist%f!\n"),LinePara[i].xstep,LinePara[j].xstep,LineConnect[ConLineNum].ThrumDist);
					ConLineNum++;
					if(ConLineNum>1)
					{
						if((LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumStart.y)
							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumEnd.y)
							||(LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumEnd.y)
							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumStart.y))
						{
							if(LineConnect[ConLineNum-1].ThrumDist<LineConnect[ConLineNum-2].ThrumDist)
							{
								LineConnect[ConLineNum-2].ThrumStart.x=LineConnect[ConLineNum-1].ThrumStart.x;
								LineConnect[ConLineNum-2].ThrumStart.y=LineConnect[ConLineNum-1].ThrumStart.y;
								LineConnect[ConLineNum-2].ThrumEnd.x=LineConnect[ConLineNum-1].ThrumEnd.x;
								LineConnect[ConLineNum-2].ThrumEnd.y=LineConnect[ConLineNum-1].ThrumEnd.y;
								LineConnect[ConLineNum-2].ThrumDire=LineConnect[ConLineNum-1].ThrumDire;
								LineConnect[ConLineNum-2].ThrumCurveSeq=LineConnect[ConLineNum-1].ThrumCurveSeq;
								LineConnect[ConLineNum-2].ThrumDist=LineConnect[ConLineNum-1].ThrumDist;
							}
							ConLineNum--;
						}
					}
				}

				j++;
			}
			//i=j;
		
				

		}


	}
	return ConLineNum;

}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int CopyLineFromCurve()
//	�������� �����ߡ�ƽ��ֱ���ж�
//	��    �� ��������
//	ʱ    �� ��2012��09��19��
//	�� �� ֵ �� ����ֱ������
//	��ڲ���˵�� ��
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��19��	������	����������
//	////////////////////////////////////////////////////////////////////////
int StraightLineInfo()
{
	LineNum=0;
	int i=0;
	int j=0;
	CGPOINT PStart ;
	CGPOINT PEnd ;
	CGPOINT PStartII;
	CGPOINT PEndII;
	double LineDis;
	double LineStartDis;
	double LineEndDis;
	double MinDis=10000.0;
	double FarDis=0.0;//Զ�����
	double NearDis=0.0;//�������
	int DisType=0;
	LINE CoLine;
	LINE CoLineII;
	
	double CoLineAngle=0.0;
	double CoLineAngleII=0.0;
	ConLineNum=0;
	ParallelLineNum=0;
	if(CurveNum>0&&CurveNum<CURVEMAXNUM)
	{
		for(i=0;i<CurveNum;i++)
		{
			if(CurveGroup[i].Curvetype==1)
			{
				PStart.x=CurveGroup[i].CurveStart.x;
				PStart.y=CurveGroup[i].CurveStart.y;
				PEnd.x=CurveGroup[i].CurveEnd.x;
				PEnd.y=CurveGroup[i].CurveEnd.y;
				LineGroup[LineNum]=makeline(PStart,PEnd);
				LineSegGroup[LineNum]=LINESEG(PStart,PEnd);
				LinePara[LineNum].xstep=i;//���ߺ�
				LinePara[LineNum].ystep=LineNum;
				LinePara[LineNum].stepdistense=180-alpha(LineGroup[LineNum])*180/PI;
				//TRACE(_T("NO.%dCurve is LineSeg%d,Start[%d,%d],End[%d,%d],ALPHA%f,CurveDire%f\n"),LinePara[LineNum].xstep,LinePara[LineNum].ystep,CurveGroup[i].CurveStart.x,CurveGroup[i].CurveStart.y,CurveGroup[i].CurveEnd.x,CurveGroup[i].CurveEnd.y,LinePara[LineNum].stepdistense);
				LineNum++;
				if(LineNum==LINENUM)
				{break;}

			}

		}
		StepStrucureQuickSort(LinePara,0,LineNum-1,LineNum,LineNum);
	
		for(i=0;i<LineNum;i++)
		{
			
			//TRACE(_T("NO.%dCurve is LineSeg%d,ALPHA%f\n"),LinePara[i].xstep,LinePara[i].ystep,LinePara[i].stepdistense);
			j=i+1;
			while(abs(LinePara[j].stepdistense-LinePara[i].stepdistense)<COLINEANGLE)
			{
				MinDis=10000.0;
				PStart.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStart.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				PEnd.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEnd.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				PStartII.x=CurveGroup[LinePara[j].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[j].xstep].CurveStart.y;
				PEndII.x=CurveGroup[LinePara[j].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[j].xstep].CurveEnd.y;
				LineStartDis=ptoldist(PStartII,LineSegGroup[LinePara[i].ystep]);
				LineEndDis=ptoldist(PEndII,LineSegGroup[LinePara[i].ystep]);
				FarDis=max(LineStartDis,LineEndDis);
				NearDis=min(LineStartDis,LineEndDis);
				if(FarDis<PARALLELDIS)
				{
					
				
					LineDis=dist(PStart,PStartII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=1;
					}
					LineDis=dist(PStart,PEndII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=2;
					}
					LineDis=dist(PEnd,PStartII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=3;
					}
					LineDis=dist(PEnd,PEndII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=4;
					}
				 switch(DisType)//PStart-PEnd:Զ��;PStartII-PEndII:����
				{
				case 1://��ͷ��ͷ����ͷ���䣬��β���ͷ
				PStart.x=PEndII.x;
				PStart.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 2://��ͷ��β����β���䣬��ͷ���ͷ
                PStart.x=PStartII.x;
				PStart.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 3://��β��ͷ����ͷ���䣬��β���β
				PEnd.x=PEndII.x;
				PEnd.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;
				case 4://��β��β����β���䣬��ͷ���β
                PEnd.x=PStartII.x;
				PEnd.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;

				}
				
				CoLine=makeline(PStart,PEnd);
				CoLineII=makeline(PStartII,PEndII);
				CoLineAngle=180-alpha(CoLine)*180/PI;
				CoLineAngleII=180-alpha(CoLineII)*180/PI;
				
				//TRACE(_T("Curve I=%d,Angle=%f,CurveII=%d,AngleII=%f,CoLineAngle=%f,CoLineAngleII=%f\n"),LinePara[j].xstep,LinePara[j].stepdistense,LinePara[i].xstep,LinePara[i].stepdistense,CoLineAngle,CoLineAngleII);
				TRACE(_T("%d,%d,%f,%f,%f,%f\n"),LinePara[j].xstep,LinePara[i].xstep,LinePara[j].stepdistense,LinePara[i].stepdistense,CoLineAngle,CoLineAngleII);
				//TRACE(_T("PStart[%d,%d],PEnd[%d,%d],PStartII[%d,%d],PEndII[%d,%d]\n"),(int)PStart.x,(int)PStart.y,(int)PEnd.x,(int)PEnd.y,(int)PStartII.x,(int)PStartII.y,(int)PEndII.x,(int)PEndII.y);

					//CoLineAngle=180-alpha(CoLine)*180/PI;
					if(MinDis<0.1)
					{
						TRACE(_T("NO.%dCurve's StartPoint[%d,%d] near NO.%dCurve with dist=%f\n"),LinePara[j].xstep,(int)PStartII.x,(int)PStartII.y,LinePara[i].xstep,LineStartDis);
						TRACE(_T("NO.%dCurve's EndPoint[%d,%d] near NO.%dCurve with dist=%f\n"),LinePara[j].xstep,(int)PEndII.x,(int)PEndII.y,LinePara[i].xstep,LineEndDis);

					}
					if(MinDis>0.1&&MinDis<COLINEDIS&&abs(LinePara[i].stepdistense-CoLineAngle)<COLINEANGLE&&abs(CoLineAngle-LinePara[j].stepdistense)<COLINEANGLE&&abs(LinePara[i].stepdistense-CoLineAngleII)<COLINEANGLE&&abs(CoLineAngleII-LinePara[j].stepdistense)<COLINEANGLE)
					//if(MinDis>0.1&&MinDis<COLINEDIS&&CoLineAngle<COLINEANGLE)
					{
					
						LineConnect[ConLineNum].ThrumStart.x=PStartII.x+0.5;
						LineConnect[ConLineNum].ThrumStart.y=PStartII.y+0.5;
						LineConnect[ConLineNum].ThrumEnd.x=PEndII.x+0.5;
						LineConnect[ConLineNum].ThrumEnd.y=PEndII.y+0.5;
						LineConnect[ConLineNum].ThrumDire=LinePara[i].xstep;
						LineConnect[ConLineNum].ThrumCurveSeq=LinePara[j].xstep;
						LineConnect[ConLineNum].ThrumDist=dist(PStartII,PEndII);
						LineConnect[ConLineNum].ThrumNormdis=0.0;
						LineConnect[ConLineNum].ThrumHisDire=DisType;
						//TRACE(_T("NO.%dCurve and NO.%dCurve should be connected with Dist%f!\n"),LinePara[i].xstep,LinePara[j].xstep,LineConnect[ConLineNum].ThrumDist);
						ConLineNum++;

						if(ConLineNum>1)
						{
							if((LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumStart.y)
								||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumEnd.y)
								||(LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumEnd.y)
								||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumStart.y))
							{
								if(LineConnect[ConLineNum-1].ThrumDist<LineConnect[ConLineNum-2].ThrumDist)
								{
									LineConnect[ConLineNum-2].ThrumStart.x=LineConnect[ConLineNum-1].ThrumStart.x;
									LineConnect[ConLineNum-2].ThrumStart.y=LineConnect[ConLineNum-1].ThrumStart.y;
									LineConnect[ConLineNum-2].ThrumEnd.x=LineConnect[ConLineNum-1].ThrumEnd.x;
									LineConnect[ConLineNum-2].ThrumEnd.y=LineConnect[ConLineNum-1].ThrumEnd.y;
									LineConnect[ConLineNum-2].ThrumDire=LineConnect[ConLineNum-1].ThrumDire;
									LineConnect[ConLineNum-2].ThrumCurveSeq=LineConnect[ConLineNum-1].ThrumCurveSeq;
									LineConnect[ConLineNum-2].ThrumDist=LineConnect[ConLineNum-1].ThrumDist;
									LineConnect[ConLineNum-2].ThrumNormdis=LineConnect[ConLineNum-1].ThrumNormdis;
									LineConnect[ConLineNum-2].ThrumHisDire=LineConnect[ConLineNum-1].ThrumHisDire;
								}
								ConLineNum--;
							}
						}
					}
				else if(NearDis>PARALLELSUB&&FarDis-NearDis<PARALLELSUB)
				{
						LineParallel[ParallelLineNum].ThrumStart.x=PStartII.x+0.5;
						LineParallel[ParallelLineNum].ThrumStart.y=PStartII.y+0.5;
						LineParallel[ParallelLineNum].ThrumEnd.x=PEndII.x+0.5;
						LineParallel[ParallelLineNum].ThrumEnd.y=PEndII.y+0.5;
						LineParallel[ParallelLineNum].ThrumDire=LinePara[i].xstep;
						LineParallel[ParallelLineNum].ThrumCurveSeq=LinePara[j].xstep;
						LineParallel[ParallelLineNum].ThrumNormdis=(FarDis+NearDis)/2;
					
						//TRACE(_T("NO.%dCurve may be paralleled with NO.%dCurve with dist=%f\n"),LineParallel[ParallelLineNum].ThrumDire,LineParallel[ParallelLineNum].ThrumCurveSeq,LineParallel[ParallelLineNum].ThrumNormdis);
						ParallelLineNum++;

				}
				}
				j++;
				if(j==LineNum)
				{break;}
			}
			//i=j;
		
				

		}


	}
	return ConLineNum;

}
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��int Parallel_Result()
//	�������� ������ƽ���߸���
//	��    �� ��������
//	ʱ    �� ��2012��09��19��
//	�� �� ֵ �� ƽ���߸���
//	��ڲ���˵�� ��
////////////////////////////////////////////////////////////////////////
//	��ʷ��¼��
//	���     ����    	����    ��ע
//	0	2012��09��19��	������	����������
//	////////////////////////////////////////////////////////////////////////
int Parallel_Result()
{return ParallelLineNum;
}