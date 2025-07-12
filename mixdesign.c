#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//step1
int grade;
double targetstrength,x,s,valueofx(),valueofs();
//step2
int sizeofaggregate;
double amountofair;
//step3
double wc;
int exposure,type;
//step4
int n;
double slump,watercontent,fwatercontent;
//step5
double cementcontent;
//step6
double y_6,CAratio,FAratio,k1,k2;
int num6,pump6;
//for pumping and nonpumping concrete;
//step 70double spgrcement;
double spgrsp,spgrcement,volcement,volwater,volsp,volaggr,massCA,massFA,spgrCA,spgrFA;
//stepwise functions
int step1();
void step2();
int step3();
int step3a();
int step4();
int step5();
int step6();
int step7();
int step8();
int step9();
//
void main()
{
printf("\n\n**********     WELCOME TO CONCRETE MIX DESIGN      ***\n\n");
step1();
step2();
step3();
step3a();
printf("\nwater cement ratio:%.3lf\n",wc);
step4();
step5();
step6();
step7();
step8();
step9();
}
int step1()
{
// f`ck=fck+1.65(s);     //f`ck=fck+x;
double f_ck1;
double f_ck2;
double fck;
printf("\n\nSTEP-1:ESTIMATION OF ULTIMATE TARGET STRENGTH*******\n\n");
printf("\nEnter grade of the cement:M");
scanf("%d",&grade);
// inserting self value of x using if else lader.
valueofx();
// inserting self value of s using if else lader.
valueofs();
f_ck1=grade + (1.65*s);
f_ck2=grade + x;
if(f_ck1>f_ck2)
{
targetstrength=f_ck1;
}
else
{
targetstrength=f_ck2;
}
return 0;
}
double valueofx()
{
if(grade==10||grade==15)
x=5.0;
else if(grade==20||grade==25)
x=5.5;
else if(grade==30 || grade==35 || grade==40 || grade==45 || grade==50 || grade== 55 || grade==60)
x=6.5;
else
x=8.0;
return x;
}
double valueofs()
{
if(grade==10||grade==15)
s=3.5;
else if(grade==20||grade==25)
s=4.0;
else if(grade==30 || grade==35 || grade==40 || grade==45 || grade==50 || grade== 55 || grade==60)
s=5.0;
else if(grade==65 || grade==70 || grade==75 || grade==80)
s=6.0;
return s;
}
void step2()
{
printf("\n\n***STEP 2:ESTIMATION OF AIR CONTENT***\n\n");
printf("Enter the Nominal maximum size of Aggregate (10 or 20 or 40):");
scanf("%d",&sizeofaggregate);
if(sizeofaggregate==10)
{
amountofair = .015;
}
else if(sizeofaggregate==20)
{
amountofair = 0.01;
}
else if(sizeofaggregate==40)
{
amountofair=0.008;
}
else
{
    printf("Invalid INPUT\\n");
    exit(0);
}
}
int step3()
{
int choice;
printf("\n\n***STEP-3:WATER CEMENT (W/C) RATIO***\n\n");      //OPC 33               - CURVE:1
//OPC 43 AND PPC/PSC   - CURVE:2
//OPC 53               - CURVE:3
printf("Enter the type of cement:\n");
printf("->Enter the following numbers according to your choice:\n");
printf("1. OPC 33 2. OPC 43 & PPC/PSC 3. OPC 53:");
scanf("%d",&choice);
if(choice != 1 && choice != 2 && choice != 3)
{
printf("Invalid INPUT");
exit(0);
}
if(choice==1)
{
// logic; for M5,7.5,10,15,20,25,30,35,40,45,50,55,60,70
if(targetstrength==26.60)
wc=0.56;
else if(targetstrength==20.77)
wc=0.56;
else if(targetstrength==15.77)
wc=0.53;
else if(targetstrength==31.60)
wc=0.434;
else if(targetstrength==38.25)
wc=0.384;
else if(targetstrength==43.25)
wc=0.35;
else if(targetstrength==48.25)
wc=0.318;
else if(targetstrength==53.25)
wc=0.279;
else if(targetstrength==58.25)
wc=0.26;
else if(targetstrength==63.25||targetstrength==68.25||targetstrength==74.90||targetstrength==79.90||targetstrength==84.90||targetstrength==89.90)
printf("NA:Not available from graph");
else
printf("ERROR-Doesn't exist");
}
else if(choice==2)
{
if(targetstrength==20.77)
wc=0.62;
else if(targetstrength==26.60)
wc=0.55;
else if(targetstrength==31.60)
wc=0.485;
else if(targetstrength==38.25)
wc=0.43;
else if(targetstrength==43.25)
wc=0.385;
else if(targetstrength==48.25)
wc=0.36;
else if(targetstrength==53.25)
wc=0.32;
else if(targetstrength==58.25)
wc=0.289;
else if(targetstrength==63.25)
wc=0.26;
else if(targetstrength==15.77||targetstrength==68.25||targetstrength==74.90||targetstrength==79.90||targetstrength==84.90||targetstrength==89.90)
printf("NA:Not available from graph");
else
printf("ERROR-Doesn't exist");
}
else if(choice==3)
{
if(targetstrength==31.60)
wc=0.56;
else if(targetstrength==26.60)
wc=0.628;//0.628](notion://0.0.2.116/)
else if(targetstrength==38.25)
wc=0.5;
else if(targetstrength==43.25)
wc=0.45;
else if(targetstrength==48.25)
wc=0.41;
else if(targetstrength==53.25)
wc=0.374;
else if(targetstrength==58.25)
wc=0.34;
else if(targetstrength==63.25)
wc=0.31;
else if(targetstrength==68.25)
wc=0.28;
else if(targetstrength==74.90)
wc=0.25;
else if(targetstrength==15.77||targetstrength==20.77||targetstrength==79.90||targetstrength==84.90||targetstrength==89.90)
printf("NA:Not available from graph");
else
printf("ERROR-Doesn't exist");
}
else
{
printf("OUT OF BOUND");
exit(0);
}
}
int step3a()
{
printf("->Enter 1 for reinforced Concrete else Enter 2 for plain concrete:");
scanf("%d",&type);
if(type!= 1 && type!=2)
{
printf("Invalid INPUT");
exit(0);
}
printf("->Enter exposure:\n");
printf("1:Mild 2:Moderate 3:Severe 4:Very Severe 5:Extreme:");
scanf("%d",&exposure);
if(exposure != 1 && exposure != 2 && exposure != 3 && exposure != 4 && exposure != 5)
{
printf("Invalid INPUT");
exit(0);
}
if(type==1)
{
if(exposure==1)
{
if(wc>0.55)
wc=0.55;
}
else if(exposure==2)
{
if(wc>0.5)
wc=0.5;
}
else if(exposure==3||exposure==4)
{
if(wc>0.45)
wc=0.45;
}
else if(exposure==5)
{
if(wc>0.40)
wc=0.40;
}
else
{
printf("NA");
}}
else
{
if(exposure==1||exposure==2)
{
if(wc>0.60)
wc=0.60;
}
else if(exposure==3)
{
if(wc>0.50)
wc=0.50;
}
else if(exposure==4)
{
if(wc>0.45)
wc=0.45;
}
else if(exposure==5)
{
if(wc>0.40)
wc=0.40;
}
else
{
printf("NA");
}
}
return wc;
}
int step4()
{
double k;
double initialcontent;
printf("\n\n***STEP-4:ESTIMATION OF WATERCONTENT***\n\n");
if(sizeofaggregate==10)
initialcontent=208;
else if(sizeofaggregate==20)
initialcontent=186;
else if(sizeofaggregate==40)
initialcontent=165;
else{
printf("NA"); }
printf("Enter slump:");
scanf("%lf",&slump);
k=21*(slump-50)/175;
watercontent=initialcontent+((k*initialcontent)/100);
printf("->If super plasticizer used Enter 1 else Enter 2:");
scanf("%d",&n);
if(n!=1 && n!=2)
{
printf("Invalid INPUT");
exit(0);
}
if(n==1)
{
fwatercontent=watercontent-((23*watercontent)/100);
}
else
{
fwatercontent=watercontent;
}
return 0;
}
int step5()
{
printf("\n\nSTEP-5:***ESTIMATION OF CEMENT CONTENT***\n\n");
cementcontent=fwatercontent/wc;
if(type==1) //reinforced concrete
{
if(exposure==1||exposure==2)  //mild,Moderate
{
if(cementcontent<300)
cementcontent=300;
}
else if(exposure==3)
{
if(cementcontent<320)
cementcontent=320;
}
else if(exposure==4)
{
if(cementcontent<340)
cementcontent=340;
}
else if(exposure==5)
{
if(cementcontent<360)
cementcontent=360;
}
else
printf("NA");
}
else if(type==2)
{
if(exposure==1)  //mild
{
if(cementcontent<220)
cementcontent=220;
}
else if(exposure==2)
{
if(cementcontent<240)
cementcontent=240;
}
else if(exposure==3)
{
if(cementcontent<250)
cementcontent=250;
}
else if(exposure==4)
{
if(cementcontent<260)
cementcontent=260;
}
else
printf("NA");
}
return 0;
}
int step6()
{
//fwatercontent
//wc
//sizeofaggregate-10,20,40`
printf("\n*******STEP 6:ESTIMATION OF RATIO's OF COARSE AND FINE AGGREGATE FOR 1 PART*******\n");
printf("->Enter the zone of aggregate:\n");
printf("->Enter 1:ZONE-1 2:ZONE-2 3:ZONE-3 4:ZONE-4:");
scanf("%d",&num6);
if(num6!=1 && num6!=2 && num6!=3 && num6!=4)
{
    printf("Invalid INPUT");
    exit(0);
}
if(num6==1) //zone-1
{
if(sizeofaggregate==10)
y_6=0.48;
else if(sizeofaggregate==20)
y_6=0.60;
else if(sizeofaggregate==40)
y_6=0.69;
else
printf("OUT OF BOUND");
}
else if(num6==2) //ZONE-2
{
if(sizeofaggregate==10)
y_6=0.50;
else if(sizeofaggregate==20)
y_6=0.62;
else if(sizeofaggregate==40)
y_6=0.71;
else
printf("OUT OF BOUND");
}
else if(num6==3) //zone 3
{
if(sizeofaggregate==10)
y_6=0.52;
else if(sizeofaggregate==20)
y_6=0.64;
else if(sizeofaggregate==40)
y_6=0.72;
else
printf("OUT OF BOUND");
}
else if(num6==4)
{
if(sizeofaggregate==10)
y_6=0.54;
else if(sizeofaggregate==20)
y_6=0.66;
else if(sizeofaggregate==40)
y_6=0.73;
else
printf("OUT OF BOUND");
}
else
{
printf("OUT OF BOUND");
}
if(num6==1||num6==2||num6==3||num6==4)
{
printf("For method of placing.Enter 1 if pumpable else Enter 2:");
scanf("%d",&pump6);
if(pump6==1)
{
k1=(y_6 - ((0.08)*(wc-0.5))/0.4);
k2=(k1*10)/100;
CAratio=k1-k2;
FAratio=1 - (CAratio);
}
else
{
CAratio=y_6 - ((0.08)*(wc-0.5))/0.4;
FAratio=1 - (CAratio);
}
}
else
{
printf("UNPREDICTABLE\n");
}
}
int step7()
{
printf("\n\n***STEP 7:FINAL ESTIMATION OF COARSE AND FINE AGGREGATE***\n\n");
printf("Assumed total volume to be:1m^3\n");
printf("Enter specific gravity of cement:");
scanf("%lf",&spgrcement);
if(n==1)
{
printf("Enter specific gravity of Super plasticzer:");
scanf("%lf",&spgrsp);
}
printf("Enter specific gravity of Coarse Aggregate:");
scanf("%lf",&spgrCA);
printf("Enter specific gravity of Fine Aggregate:");
scanf("%lf",&spgrFA);
//volum of cement
volcement= cementcontent / (spgrcement*1000);
volwater = fwatercontent / (1000);
if(n==1)
{
volsp=cementcontent/(100*1000*spgrsp);
}
if(n==1)
{
volaggr= 1 -(volwater)-(volsp)-(volcement)-(amountofair);
}
else
{
volaggr= 1 -(volwater)-(volcement)-(amountofair);
}
massCA=spgrCA*1000*CAratio*volaggr;
massFA=spgrFA*1000*FAratio*volaggr;

}
int step8()
{
int num8,condition8;
double WACA,WAFA;
printf("\n\n***STEP 8:Adjustment of moisture***\n\n");
printf("->Enter 1 if you want to consider mositure adjustments else Enter 2:");
scanf("%d",&num8);
if(num8!=1 && num8!=2)
{
printf("Invalid INPUT");
exit(0);
}
if(num8==1)
{
printf("Enter water absorption of Coarse Aggregate:");
scanf("%lf",&WACA);
printf("Enter water absorption of Fine Aggregate:");
scanf("%lf",&WAFA);
printf("Enter wet or dry condition:\n");
printf("Enter 1 for dry and 2 for wet condition:");
scanf("%d",&condition8);
if(condition8==1)
{
massCA=(massCA)/(1+(WACA*0.01));
massFA=(massFA)/(1+(WAFA*0.01));
}
else
{
massCA=(massCA)*(1+(WACA*0.01));
massFA=(massFA)*(1+(WAFA*0.01));
}
}
else
{
}
}
int step9()
{
printf("\n\n***FINAL RATIO:***\n\n");
printf("CEMENT:FA:CA = 1 :%.3lf : %.3lf \n\n\n",massFA/cementcontent,massCA/cementcontent);
printf("********* OBTAINED CONDITIONS ***\n\n");
printf("The obtained content based on the mix:\n\n");
printf("Cement content:%.3f Kg/m3\n", cementcontent);
printf("Coarse Aggregate :%.3f kg/m3\n", massCA);
printf("Fine aggregate :%.3f kg/m3\n", massFA);
printf("\n\n***THANK YOU**********");

}
