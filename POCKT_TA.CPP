#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
int main()
{
int gmode=EGAHI,gdriver=EGA;        //EnhancedGraphicsAdapter driver req for multiple pages.
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
int y=getmaxy();
int x=getmaxx();
float xp,x0=90,yp,y0=y-40;
xp=x0,yp=y0;

double angle;
int sum[2]={0,0};
int cc=1,cn=1;       //cc= no. of chances
nxt:
if(cc==5)
{
cleardevice();
cout<<"\nPlayer 1: "<<sum[0];
cout<<"\nPlayer 2: "<<sum[1];
if(sum[0]>sum[1])
{
cout<<"\nPlayer 1 is Winner.!!";
}
else if(sum[0]<sum[1]){
cout<<"\nPlayer 2 is Winner.!!";
}
else
{
cout<<"\nMatch Draw";
}
getch();
closegraph();
return 1;
}
setactivepage(0);
cleardevice();
pieslice(50,y-10,0,180,20);
pieslice(x-50,y-10,0,180,20);
if(cc%2==0)
{
line(50,y-10,x0,y0);
line(x-50,y-10,x-xp,yp);
}
else
{
line(50,y-10,xp,yp);
line(x-50,y-10,x-x0,y0);
}
xp=x0;
yp=y0;
setvisualpage(0);

if(cn==3)
{cn=1;}
cout<<"PLAYER "<<cn<<" Score= "<<sum[cn-1];
h:
cout<<"\nEnter the angle";
cin>>angle;
setactivepage(1);
clearviewport();
pieslice(50,y-10,0,180,20);
pieslice(x-50,y-10,0,180,20);
x0=50+(50*cos(angle*(atan(1)*4)/180));
y0=y-10-(50*sin(angle*(atan(1)*4)/180));
if(cc%2!=0)
{

line(50,y-10,x0,y0);
line(x-50,y-10,x-xp,yp);

}
else
{
line(50,y-10,xp,yp);
line(x-50,y-10,x-x0,y0);
}
setvisualpage(1);
char ch;
cout<<"Lock this angle (Y/N) ? ";
cin>>ch;
if(ch=='Y' || ch=='y')
{
float tym,u=0;
cout<<"\nSet speed: ";
cin>>u;
tym=2*u*sin(angle*(atan(1)*4)/180)/10;
int i=2;
int a,b;
for(float t=0;t<tym+0.75;t+=0.3,i++)
{
cleardevice();
pieslice(50,y-10,0,180,20);
pieslice(x-50,y-10,0,180,20);
a=x0+u*t*cos(angle*(atan(1)*4)/180);
b=y0-u*t*sin(angle*(atan(1)*4)/180)+5*t*t;

if(cc%2!=0)
{
line(50,y-10,x0,y0);
line(x-50,y-10,x-xp,yp);

pieslice(a,b,0,360,3);
delay(50);

}
else
{
line(50,y-10,xp,yp);
line(x-50,y-10,x-x0,y0);

pieslice(x-a,b,0,360,3);
delay(50);

}
}
if(a<x-27 && a>x-73)
{
cout<<"\nGreat hit.!!! ";
sum[cn-1]+=10;
getch();
}
else
{
cout<<"\nOops..better luck next time  ";
getch();
}
cc++;
cn++;
goto nxt;
}
else
{

goto h;
}
}