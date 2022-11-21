#include <REG51.H>
#include <stdio.h>

int kat,tur,hiz;

tur=10;		//her kat için motorun dönme sayisi
hiz=10;	    //motorun dönüþ hizi		0 max  32000 min

bekle(c)
{
int i,j;
if(c==0)
{
for(i=0;i<500;i++)
{
for(j=0;j<hiz;j++)
{
;
}
}
}
return;
}


// asansor yukari cikiyor
yukari(b)
{
int i,j;
for (i=1;i<=b;i++)
{

for (j=0;j<=10;j++)
{
P3=1;
bekle(0);
P3=2;
bekle(0);
P3=4;
bekle(0);
P3=8;
bekle(0);
}
P2=kat+i;
}
kat=kat+b;
return;
}

// asansor asagi iniyor
asagi(b)
{
int i,j;
for (i=1;i<=b;i++)
{
for (j=0;j<=tur;j++)
{
P3=8;
bekle(0);
P3=4;
bekle(0);
P3=2;
bekle(0);
P3=1;
bekle(0);
}
P2=kat-i;
}
kat=kat-b;
return;
}



kontrol(a)
{
int fark;
if(a>kat)
{
fark=a-kat;
yukari(fark);
}

if(a<kat)
{
fark=kat-a;
asagi(fark);
}
return;
}


main()
{
int kat1;
kat=0;
P2=kat;
while(1)
{
if(P0==1)
{
kat1=1;
kontrol(1);
}

if(P0==2)
{
kat1=2;
kontrol(2);
}

if(P0==4)
{
kat1=3;
kontrol(3);
}

if(P0==8)
{
kat1=4;
kontrol(4);
}

if(P0==16)
{
kat1=5;
kontrol(5);
}
}
}