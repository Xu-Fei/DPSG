#pragma once
#include "DPSG/CG.h"
#include "ED/EdgeMap.h"
static const unsigned int THRUMMAXNUM=30000;
static const unsigned int CURVEMAXNUM=5000;
static const unsigned int MAXCURVENUM=3;
static const unsigned int CIRCLENUM=10;
static const unsigned int LINENUM=100;
static const unsigned int CHARMAXNUM=60;//���ڶ�λ�ĵ��ͽṹ�������
static const unsigned int POINTMAXNUM=4000;//�����������ͽṹ�ĵ���������
typedef struct//��������ṹ��
{
	int xstep;//�Ჽ����λ
	int ystep;//�ݲ�����λ
	double stepdistense;//��������
} StepStrucureII;
extern StepStrucureII g_oDistense64D[];

//////////////////////////////////////////////////////////////////////////////////////////////
struct StartThrumInfo{
		POINT ThrumStart; //��ͷ��ʼ������
		POINT ThrumEnd;	  //��ͷ����������
		POINT ThrumSource;//��ͷԴͷ
		int ThrumDire;	//��ͷ����(1-64)
		int StartFrom;  //��ͷ����λ
		double ThrumDist; //��ͷ����
		double ThrumNormdis;//���߷��򳤶�
};//��ͷ�ṹ��
struct FeaturePointInfo{
	    POINT ThrumStart; //��ͷ��ʼ������
		POINT ThrumEnd;	  //��ͷ����������
	    POINT FeaturePointPos;//����������
		POINT PointNormOne;//�����㷨�߽߱�1
        POINT PointNormTwo;//�����㷨�߽߱�2
		unsigned char ThrumDire;	//��ͷ����(1-32)
		double ThrumDist; //��ͷ����
		double ThrumNormdis;//���߷��򳤶�
		unsigned char LongDir;//������
		double LoneDis;//�����򳤶�
		unsigned char ShortDir;//�̷���
		double ShortDis;//�̷��򳤶�
		unsigned char NormOne;//���߷���1
		double NormOneDis;//���߷���1����
		unsigned char NormTwo;//���߷���2
		double NormTwoDis;//���߷���1����
		//int DirOne; //����1
		//double DirOneDis;//����1����
		//int DirTwo; //����2
		//double DirTwoDis;//����2����
		//int DirThree; //����3
		//double DirThreeDis;//����3����
		//int DirFour; //����4
		//double DirFourDis;//����4����
		int FeaturePointType;//���������� 0����ͨ�㣻1���˵㣻2���յ㣻3��������� 4���Ľ����
};//������ṹ��
struct ThrumInfo{
		POINT ThrumStart; //�߶���ʼ������
		POINT ThrumEnd;	  //�߶ν���������
		int ThrumDire;	//�߶η���(1-64)
		int ThrumCurveSeq;//�߶������������
		double ThrumDist;        //�߶γ���
		double ThrumNormdis;//���߷��򳤶�
		double ThrumHisDire;//�߶���ʷ����
		double ThrumWeight;//�߶�Ȩ��
		//POINT PointNormOne;//�����㷨�߽߱�1
  //      POINT PointNormTwo;//�����㷨�߽߱�2
		//int NormOne;//���߷���1
		//double NormOneDis;//���߷���1����
		//int NormTwo;//���߷���2
		//double NormTwoDis;//���߷���1����

};//�߶νṹ��

struct CurveInfo{
	POINT CurveStart; //������ʼ������
	POINT CurveEnd;	  //���߽���������
	unsigned int CurveFrom;	//������ʼ��λ
	double CurveDire;	//���ߴ��巽��(0-360)
	unsigned int CurveStartThrum;//������ʼ�߶����
	unsigned int CurveEndThrum;//���߽����߶����
	unsigned int CurveMidThrum;//�����в��߶����
	unsigned char Curvetype;//���߱�־��1����ֱ�� 2���� 8������� 6Բ�� 
	unsigned char CurveChange;//���߷���仯����
	double CurveDist[65];//���߳���0:�����ܳ��Ⱥ� 1-64:������ʮ�ķ�����Գ��Ⱥ�
	double  CurveNormdis;//���߷���ƽ�����
	double Curvature;//���߷���仯
	unsigned short CrossCruve[5][6];//����������Ϣ�� ����Է��߶κš���������0:�޽��� 1һ���� 2������������������ꡢ������,�����ҷ��߶κ�;���������������
	
	
	
	};//���߽ṹ��

extern struct StartThrumInfo StartThrum[CURVEMAXNUM];//
extern struct FeaturePointInfo FeaturePoint[CURVEMAXNUM];// ����������
extern struct ThrumInfo ThrumGroup[THRUMMAXNUM];
extern struct CurveInfo CurveGroup[CURVEMAXNUM];
extern struct StartThrumInfo StartThrumTemp;//
extern struct ThrumInfo ThrumTemp;
extern struct LINE LineGroup[LINENUM];
extern struct LINESEG LineSegGroup[LINENUM];
extern StepStrucureII LinePara[LINENUM];
extern int StartThrumNum;//��ʼ�߶����
extern int FeaturePointNum;//���������
extern int ThrumNum;//�߶����
extern int CurveNum;//�������
extern int LineNum;//ֱ�����

extern unsigned short MaxCurveGroup[MAXCURVENUM][2];//���������[][0]���,[][1]����
extern unsigned short CircleGroup[CIRCLENUM][4];//Բ����[][0]���,[][1]�뾶��[][2]Բ�ĺ����꣬[][3]Բ��������
extern unsigned char CircleII[192];

////////////////////////////////////////////////////////////////////////////////////
struct InkDataType 
{
	short x;//���������������0-255
	short y;//����������������0-255
	unsigned short z;//ѹ��
	unsigned short type;//�������
};
extern struct InkDataType InkData[CHARMAXNUM][POINTMAXNUM];//
struct YYMatchingType 
{
	unsigned int PointNum;// �������������ݵ���;
	unsigned int PointSize;// ��ģ���������ݵ���;
	unsigned short Code;//�������� *(P+272)
	unsigned short Width;//ģ���
	unsigned short Height;//ģ���
	CGPOINT StartPoint;//ģ����ʼ��λ��
	CGPOINT CenterPoint;//ģ�����ĵ�λ��
	CGPOINT FirstPoint;//ģ�����ĵ�λ��
	unsigned int UnitSeq;//�������
	double scale;//ģ��߶�
	double angle;//ģ��Ƕ�
	double perimeter;//ģ���ܳ�
	double YinCYinMRatio; //��������������ͼ�е�ƥ����
	double YinLineYinMRatio; //��������������ͼ�е��߶�ƥ����
	double YinCYangMRatio;//��������������ͼ�е�ƥ����
	double YangTYinMRatio;//��ģ����������ͼ�е�ƥ����
	double YangTYangMRatio;//��ģ����������ͼ�е�ƥ����
};
extern struct YYMatchingType YYMatchingResult[CHARMAXNUM];
extern struct YYMatchingType YYMatchingTemp;
////////////////////////////////////////////////////////////////////////////////////
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
ThrumInfo DPSGII_LineSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout);
double DPSGII_DPDisR64D(unsigned char* Img_bin, int nWidth, int nHeight, int cenX, int cenY, int R, int Rout, unsigned int Direction);
unsigned char* DPSGII_DistanceTrans(unsigned char* Img_bin, int nWidth, int nHeight, int Rin, int Rout);
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
unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter);
////////////////////////////////////////////////////////////////////////
//	�� �� ����void DPSGII_YinYangSampleFast(unsigned char* Img_gray, unsigned char* &g_pYinMap,unsigned char* &g_pYangMap,int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter);
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
void DPSGII_YinYangSampleFast(unsigned char* Img_gray, unsigned char* &g_pYinMap,unsigned char* &g_pYangMap,int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter);
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
int DPSGII_DPYinYangFilterR(unsigned char* Img_bin,unsigned char* Img_bin2,int nWidth,int nHeight,int Rin,  int Rout,int Value);
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
bool DPSG_AdnoteLinePoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout);
StepStrucureII DPSG_LinePointCounter(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout);
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve);
//	�������� ����Img_bin���Զ�̽��������Ϣ
//	��    �� ��������
//	ʱ    �� ��2012��4��1��
//	�� �� ֵ ���߶μ����߼���
//	��ڲ���˵�� ��
//  1.IplImage * Img_bin: ��̽��ͼ
//  2.IplImage * Img_sign: ��̽��������ͼ
//      unsigned short* Img_history
//  3.int nWidth��������ĻҶ�ͼ������
//  4.int nHeight��������ĻҶ�ͼ����߶�
//  5.int Rin�������뾶 2
//    int Rout 15
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
void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve);
void DPSGII_AutoCurveSearch64DII(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve);
void DPSGII_AutoLineSearch64D(unsigned char* Img_bin, unsigned char* Img_sign, unsigned short* Img_history, int nWidth, int nHeight, int Rin, int Rout, int DirectionN, int NormThre, int CrossAngle, int MinLine);
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
void DPSGII_Clear();
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
void DPSGII_Result(int& StartThrumNumOut,int& ThrumNumOut, int&CurveNumOut);
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
StartThrumInfo * DPSGII_StartThrum(int StartThrumNum);
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
CurveInfo * DPSGII_Curve(int CurveNumNow);
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
unsigned short  DPSGII_MaxCurve(int MaxSeq);
unsigned short*  DPSGII_CircleCurve(int CircleSeq);
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
ThrumInfo * DPSGII_Thrum(int ThrumNumNow);
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
FeaturePointInfo * DPSGII_FeaturePoint(int FeaturePointNow);
ThrumInfo * DPSGII_ConLine(int ConLineNumNow);
ThrumInfo * DPSGII_ParallelLine(int ConLineNumNow);
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
FeaturePointInfo DPSGII_FeaturePointSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre);
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
int DPSGII_FeaturePointSearch(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre);
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
void DPSGII_FeaturePointSearchShield(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre);
int CopyLineFromCurve();
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
int StraightLineInfo();
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
int Parallel_Result();
////////////////////////////////////////////////////////////////////////
//	�� �� �� ��StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout)
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
StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R);
bool DPSGII_FeaturePointBlockArea(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow);
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
int DPSGII_DPAdnateValueFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout,int Value);
double DPSGII_YinMatching(unsigned char* Img_bin,int nWidth,int nHeight,CGPOINT* Yincontours,int Lengths,int SetX,int SetY);
double DPSGII_YinMatchingLine(unsigned char* Img_bin,int nWidth,int nHeight,CGPOINT* Yincontours,int Lengths,int SetX,int SetY,int Rin,int Rout);
double DPSGII_YangMatching(unsigned char* Img_bin,int nWidth,int nHeight,unsigned char* Yangtemplate,int nWidthII,int nHeightII,int Size,int SetX,int SetY);
YYMatchingType DPSGII_YinYangSetPointMatching(unsigned char* Img_yin,unsigned char * Img_yang,int nWidth,int nHeight,CGPOINT* Yincontours,unsigned char* Yangtemplate,YYMatchingType InputTemplate);
YYMatchingType DPSGII_YinYangMatching(unsigned char* Img_yin,unsigned char * Img_yang,int nWidth,int nHeight,CGPOINT* Yincontours,unsigned char* Yangtemplate,YYMatchingType InputTemplate,int Rin,int Rout,int NormThre);
void DPSGII_EdpfInfo(EdgeMap *EdpfMap);