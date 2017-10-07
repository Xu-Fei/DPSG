#pragma once
#ifndef _CG_H
#define _CG_H
/* ���õĳ������� */ 
const double INF = 1E200; 
const double EP = 1E-10; 
const double EPDPSG = 0.04; //��ɢ����������ľ�������ƫ�����ƽ����
const double EPCIRCLE = 0.80;//Բ���������ƫ�� 
const double PARTCIRCLE = 10;//Բ���������ƫ�� 
const double COLINEANGLE = 11.25;//������������ƫ�� 
const double COLINEDIS = 100.00;//������������˵�ƫ�� 
const double PARALLELDIS = 30.00;//ƽ���������maxƫ�� 
const double PARALLELSUB = 4.00;//ƽ���������minƫ�� 
const int MAXV = 300; 
const double PI = 3.14159265; 
const int MAXWIDTH = 1400;
const int MAXHEIGHT = 1024;
/* ���õı��ʽ���� */ 
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
/* �������νṹ */ 
struct CGPOINT 
{ 
double x; 
double y; CGPOINT(double a=0, double b=0) { x=a; y=b;} //constructor 
}; 
struct LINESEG 
{ 
CGPOINT s; 
CGPOINT e; LINESEG(CGPOINT a, CGPOINT b) { s=a; e=b;} 
LINESEG() { } 
}; 
struct LINE // ֱ�ߵĽ������� a*x+b*y+c=0 Ϊͳһ��ʾ��Լ�� a >= 0 
{ 
double a; 
double b; 
double c; LINE(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;} 
}; 
/******************** 
*                    * 
*   ��Ļ�������     * 
*                    * 
********************/ 
double dist(CGPOINT p1,CGPOINT p2) ;//��������֮��ŷ�Ͼ��� 
bool equal_CGPOINT(CGPOINT p1,CGPOINT p2);//�ж��������Ƿ��غ�
double multiply(CGPOINT sp,CGPOINT ep,CGPOINT op);//�жϵ�ep��ʸ��opsp����ʱ�뷽��˳ʱ�뷽�����㹲��
double dotmultiply(CGPOINT p1,CGPOINT p2,CGPOINT p0);//�ж���ʸ���н�Ϊ���ֱ�Ƕ۽�
CGPOINT rotate(CGPOINT o,double alpha,CGPOINT p); // ���ص�p�Ե�oΪԲ����ʱ����תalpha(��λ������)�����ڵ�λ�� 
double angle(CGPOINT o,CGPOINT s,CGPOINT e); //���ض�����o�㣬��ʼ��Ϊos����ֹ��Ϊoe�ļн�(��λ������) 
/***************************** 
*                             * 
*      �߶μ�ֱ�ߵĻ�������   * 
*                             * 
*****************************/ 
bool online(LINESEG l,CGPOINT p); //�жϵ�p�Ƿ����߶�l�� 
double relation(CGPOINT p,LINESEG l); //�жϵ����߶εĹ�ϵ
CGPOINT perpendicular(CGPOINT p,LINESEG l); //���C���߶�AB����ֱ�ߵĴ��� P 
double ptolinesegdist(CGPOINT p,LINESEG l,CGPOINT &np); //���p���߶�l����̾���,�������߶��Ͼ�õ�����ĵ�np ע�⣺np���߶�l�ϵ���p����ĵ㣬��һ���Ǵ���
double ptoldist(CGPOINT p,LINESEG l); // ���p���߶�l����ֱ�ߵľ���,��ע�Ȿ�������ϸ�����������  
double ptoCGPOINTset(int vcount,CGPOINT CGPOINTset[],CGPOINT p,CGPOINT &q); //����㵽���߼����������,�����������. 
bool CircleInsidePolygon(int vcount,CGPOINT center,double radius,CGPOINT polygon[]); // �ж�Բ�Ƿ��ڶ������
double cosine(LINESEG l1,LINESEG l2); //��������ʸ��l1��l2�ļнǵ�����
double lsangle(LINESEG l1,LINESEG l2); // �����߶�l1��l2֮��ļн� ��λ������ ��Χ(-pi��pi) 
bool intersect(LINESEG u,LINESEG v); //����߶�u��v�ཻ(�����ཻ�ڶ˵㴦)ʱ������true 
bool intersect_A(LINESEG u,LINESEG v); //(�߶�u��v�ཻ)&&(���㲻��˫���Ķ˵�) ʱ����true   
bool intersect_l(LINESEG u,LINESEG v); // �߶�v����ֱ�����߶�u�ཻʱ����true���������ж��߶�u�Ƿ�����߶�v  
LINE makeline(CGPOINT p1,CGPOINT p2); // ������֪�������꣬����������ֱ�߽������̣� a*x+b*y+c = 0  (a >= 0)  
double slope(LINE l); // ����ֱ�߽������̷���ֱ�ߵ�б��k,ˮƽ�߷��� 0,��ֱ�߷��� 1e200 
double alpha(LINE l); // ����ֱ�ߵ���б��alpha ( 0 - pi) 
CGPOINT symmetry(LINE l,CGPOINT p); // ���p����ֱ��l�ĶԳƵ�  
bool lineintersect(LINE l1,LINE l2,CGPOINT &p); // �������ֱ�� l1(a1*x+b1*y+c1 = 0), l2(a2*x+b2*y+c2 = 0)�ཻ������true���ҷ��ؽ���p  
bool intersection(LINESEG l1,LINESEG l2,CGPOINT &inter); // ����߶�l1��l2�ཻ������true�ҽ�����(inter)���أ����򷵻�false 
/****************************** 
* * 
* ����γ����㷨ģ�� * 
* * 
******************************/ 
// ������ر�˵�����������ζ���Ҫ����ʱ������ 
bool issimple(int vcount,CGPOINT polygon[]); //����Ķ�����Ǽ򵥶���Σ�����true 
void checkconvex(int vcount,CGPOINT polygon[],bool bc[]); // ����ֵ��������˳�򷵻ض���ζ����͹�����жϣ�bc[i]=1,iff:��i��������͹���� 
bool isconvex(int vcount,CGPOINT polygon[]); // ����ֵ�������polygon��͹�����ʱ������true  
double area_of_polygon(int vcount,CGPOINT polygon[]); // ���ض�������(signed)�����붥�㰴��ʱ������ʱ��������ֵ�����򷵻ظ�ֵ 
double perimeter_of_polygon(int vcount,CGPOINT polygon[],bool closesign);//���ض�����ܳ� 
bool isconterclock(int vcount,CGPOINT polygon[]); // ������붥�㰴��ʱ�����У�����true 
bool isccwize(int vcount,CGPOINT polygon[]); // ��һ���ж϶���ζ������з���ķ���  
bool PointInsidePolygon(int vcount,CGPOINT center,CGPOINT polygon[]); //�жϵ��Ƿ��ڶ������.
int insidepolygon(int vcount,CGPOINT Polygon[],CGPOINT q); //���߷��жϵ�q������polygon��λ�ù�ϵ��Ҫ��polygonΪ�򵥶���Σ�������ʱ������
bool InsideConvexPolygon(int vcount,CGPOINT polygon[],CGPOINT q);// ��q��͹�����polygon��ʱ������true��ע�⣺�����polygonһ��Ҫ��͹�����  
void Graham_scan(CGPOINT CGPOINTSet[],CGPOINT ch[],int n,int &len);// Ѱ��͹����graham ɨ�跨
void ConvexClosure(CGPOINT CGPOINTSet[],CGPOINT ch[],int n,int &len);// ���������㼯͹�ǣ�����˵��ͬgraham�㷨 
bool LinesegInsidePolygon(int vcount,CGPOINT polygon[],LINESEG l); //�ж������Ƿ��ڼ򵥶������,�жϼ򵥶�����Ƿ�����һ���򵥶������
void AddPosPart(double x, double y, double w, double &xtr, double &ytr, double &wtr); //�����ұ���������
void AddNegPart(double x, double y, double w, double &xtl, double &ytl, double &wtl); //��������������� 
void AddRegion ( double x1, double y1, double x2, double y2, double &xtr, double &ytr,double &wtr, double &xtl, double &ytl, double &wtl ); //����������� 
CGPOINT cg_simple(int vcount,CGPOINT polygon[]); //������򵥶����polygon������
CGPOINT gravitycenter(int vcount,CGPOINT polygon[]); // ��͹����ε�����,Ҫ���������ΰ���ʱ������ 
CGPOINT a_CGPOINT_insidepoly(int vcount,CGPOINT polygon[]);//����һ�򵥶���Σ��ҳ�һ���϶��ڸö�����ڵĵ� 
void CGPOINTtangentpoly(int vcount,CGPOINT polygon[],CGPOINT p,CGPOINT &rp,CGPOINT &lp); //��Ӷ������һ��p������һ���򵥶���ε�����,������ڷ����е�,����rp�������е�,lp�����е� 
bool core_exist(int vcount,CGPOINT polygon[],CGPOINT &p); // ��������polygon�ĺ˴��ڣ�����true�����غ��ϵ�һ��p.���㰴��ʱ�뷽������  
/************************* 
* * 
* Բ�Ļ������� * 
* * 
*************************/ 
bool CGPOINT_in_circle(CGPOINT o,double r,CGPOINT p); //��p��Բ��(�����߽�)ʱ������true 
double CGpolygon_on_circle(CGPOINT o,double r,int vcount,CGPOINT polygon[],int *PartCircle); //����λ�����Բ��ʱ��������Բ�Ժ�������Բ�ϵ�ĸ���
bool cocircle(CGPOINT p1,CGPOINT p2,CGPOINT p3,CGPOINT &q,double &r); //�󲻹��ߵ�����ȷ��һ��Բ 
bool line_circle(LINE l,CGPOINT o,double r,CGPOINT &p1,CGPOINT &p2); //δʵ�֣���ֱ�ߺ�Բ�Ľ���
/************************** 
* * 
* ���εĻ������� * 
* * 
**************************/ 
CGPOINT rect4th(CGPOINT a,CGPOINT b,CGPOINT c); //��֪���ε���������(a,b,c)��������ĸ�����d������. ע�⣺��֪�������������������� 
/************************* 
* * 
* �����㷨������ * 
* * 
*************************/ 
/* ��δʵ�ֵ��㷨�� 
1. ������㼯����СԲ 
2. �����εĽ� 
3. �򵥶���ε������ʷ� 
4. Ѱ�Ұ����㼯����С���� 
5. ���ߵĻ��� 
6. �жϾ����Ƿ��ھ����� 
7. �жϾ����ܷ���ھ����� 
8. ���β���������ܳ� 
9. ���β������� 
10.���β��ıհ� 
11.���εĽ� 
12.�㼯�е������� 
13.����εĲ� 
14.Բ�Ľ��벢 
15.ֱ����Բ�Ĺ�ϵ 
16.�߶���Բ�Ĺ�ϵ 
17.�����εĺ˼�������� 
18.��㼯�в��ཻ��� railwai 
*/ 
/******************** 
* * 
* ���� * 
* * 
********************/ 
int CircleRelation(CGPOINT p1, double r1, CGPOINT p2, double r2); //���룺1�����У�2���ཻ��3�����У�4���ں���5��
bool CircleRecRelation(CGPOINT pc, double r, CGPOINT pr1, CGPOINT pr2, CGPOINT pr3, CGPOINT pr4); //�ж�Բ�Ƿ��ھ�����
double P2planeDist(double x, double y, double z, double a, double b, double c, double d);// �㵽ƽ��ľ���,ƽ����һ��ʽ��ʾax+by+cz+d=0 
bool SameSide(CGPOINT p1, CGPOINT p2, LINE line); // �������Ƿ���ֱ��ͬ�࣬���򷵻�true 
void reflect(double a1,double b1,double c1,double a2,double b2,double c2,double &a,double &b,double &c);//��֪�����ߡ����棬�����ߡ� 
bool r2inr1(double A,double B,double C,double D); // ����2��C��D���Ƿ���1��A��B���� 
void  c2CGPOINT(CGPOINT p1,double r1,CGPOINT p2,double r2,CGPOINT &rp1,CGPOINT &rp2); //��Բ���㣺��Բ�Ѿ��ཻ�����У� 
double c2area(CGPOINT p1,double r1,CGPOINT p2,double r2);//��Բ������������뱣֤�ཻ  
int clCGPOINT(CGPOINT p,double r,double a,double b,double c,CGPOINT &rp1,CGPOINT &rp2); //Բ��ֱ�߹�ϵ��0----���� 1----���� 2----�ཻ  
void incircle(CGPOINT p1,CGPOINT p2,CGPOINT p3,CGPOINT &rp,double &r);//����Բ��
void cutCGPOINT(CGPOINT p,double r,CGPOINT sp,CGPOINT &rp1,CGPOINT &rp2); //���е㣺  p---Բ�����꣬ r---Բ�뾶�� sp---Բ��һ�㣬 rp1,rp2---�е����� 
int rotat(LINESEG l1,LINESEG l2); //�߶ε��������� 0�� �غϣ� 1�� �������C1�� ������

#endif /*_CG_H*/