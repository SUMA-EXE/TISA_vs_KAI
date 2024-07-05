#include <Arduboy2.h>
#include "bitmap.h"

Arduboy2 arduboy;

#define ARDBITMAP_SBUF arduboy.getBuffer()//突っ込むバッファ
#include <ArdBitmap.h>
ArdBitmap<WIDTH, HEIGHT> ardbitmap;//ビットマップの奴



int AX[2]={0,56};
int AY[2]={47,47};
int AJ[2]={0,0};
int CC=0;
int M[2]={1,-1};
int Po[2]={0,0};

int GG[2]={0,0};


int XT=0;
int YT=0;

uint8_t hair=0;
uint8_t YURE=0;
uint8_t YURE_M=0;

uint8_t SF=0;

uint8_t mode=0;
uint8_t lev=0;
uint8_t sel=0;
uint8_t vs=0;

int CPUX=0;
int CPUY=0;
int CPUC=0;


int SC=20;
int winner=0;

int hold=0;
int hold2=0;
uint8_t ty=0;
uint8_t SPA[2]={0,0};

uint8_t loveC[4]={0,0,0,0};

uint8_t TIME=64;
uint8_t TC=0;

uint8_t EN[2]={0,0};

int loopY=0;
int loopX=0;
int loopMY=0;
int loopMX=0;

uint8_t toko=0;
uint8_t Jsw[2]={0,0};

int LX[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int LY[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() {
  // put your setup code here, to run once:
  
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.initRandomSeed();

for (uint8_t i = 0; i < 10; i++) {
LY[i]=-128+random(96);LX[i]=random(56);
}
}

void loop() {
  // put your main code here, to run repeatedly:
    if (!arduboy.nextFrame()) return;
  arduboy.clear();

arduboy.pollButtons();
  
  arduboy.fillRect(0,0,128,64,0);
  arduboy.fillRect(32,0,64,64,1);
  arduboy.drawLine(32,63,95,63,BLACK);
  arduboy.drawLine(32,60,95,60,BLACK);
  arduboy.fillRect(44,60,16,4,0);
  arduboy.fillRect(68,60,16,4,0);

if (mode==1){
if ((TIME==0)and(TC==0)and(SC==0)){SC=-1;}
if (SC==0){
if (vs==0){
if ((arduboy.justPressed(A_BUTTON)and(SPA[0]==0))){M[0]=-M[0];}
if ((arduboy.justPressed(B_BUTTON)and(SPA[0]==0)and(EN[0]==28)and(AY[0]>0))){SPA[0]=8;EN[0]=0;}
if (ty==0){//vsカイ
  if (lev==0){
  if ((abs(CPUX-AX[1])<=2)and(SPA[1]==0)){CPUC=random(10);CPUX=LX[CPUC];M[1]=-M[1];}
  if (EN[1]==28){CPUY++;}
  if ((CPUY>=30)and(SPA[1]==0)and(EN[1]==28)and(AY[1]>0)){SPA[1]=8;EN[1]=0;CPUY=0;}}
  if (lev==1){
  if ((LY[CPUC]>=AY[1]+4)or(LY[CPUC]<=-20)){CPUC=random(10);}
  if ((abs(AX[0]-AX[1])>=4)and(AY[0]<AY[1])and(abs(AY[0]-AY[1])>=20)){CPUC=random(10);}
  if ((abs(LX[CPUC]-AX[1])>=16)and(SPA[1]==0)){
    if ((LX[CPUC]>AX[1])and(M[1]==-1)){M[1]=-M[1];}
    if ((LX[CPUC]<AX[1])and(M[1]==1)){M[1]=-M[1];}
    }
  if (EN[1]==28){CPUY++;}
  if ((CPUY>=10)and(SPA[1]==0)and(EN[1]==28)and(AY[1]>0)and(AY[1]<AY[0])and(AY[1]+20>AY[0])){SPA[1]=8;EN[1]=0;CPUY=0;}}
  if (lev==2){
    loveC[0]=0;loveC[1]=0;loveC[2]=0;loveC[3]=0;CPUC=0;
    for (uint8_t i = 0; i < 10; i++) {
    if ((LY[i]<=AY[1]+4)and(LY[i]>=-24)){loveC[LX[i]/16]++;}
    if ((LY[i]<=AY[1]+4)and(LY[i]>=-16)){loveC[LX[i]/16]++;}
    if ((LY[i]<=AY[1]+4)and(LY[i]>=-8)){loveC[LX[i]/16]++;}
    }
    if (AY[0]<AY[1]){loveC[AX[0]/16]=loveC[AX[0]/16]-10;}
    for (uint8_t i = 0; i < 3; i++) {
    if (loveC[CPUC]<loveC[1+i]){CPUC=i+1;}
    }

  if ((abs(CPUC*16+8-AX[1])>=5)and(SPA[1]==0)){
    if ((CPUC*16+8>AX[1])and(M[1]==-1)){M[1]=-M[1];}
    if ((CPUC*16+8<AX[1])and(M[1]==1)){M[1]=-M[1];}
    }
  if (EN[1]==28){CPUY++;}
  if ((CPUY>=5)and(SPA[1]==0)and(EN[1]==28)and(AY[1]>0)and(AY[1]<AY[0])and(AY[1]+20>AY[0]and((AX[0]-AX[1])*M[1])>0)){SPA[1]=8;EN[1]=0;CPUY=0;}}
  }
if (ty==1){//vsチサ
  if (lev==0){
  if ((abs(CPUX-AX[1])<=2)and(SPA[1]==0)){CPUX=AX[0];M[1]=-M[1];}
  if (EN[1]==28){CPUY++;}
  if ((CPUY>=30)and(SPA[1]==0)and(EN[1]==28)and(AY[1]>0)){SPA[1]=8;EN[1]=0;CPUY=0;}}
  if (lev==1){
  if ((abs(AX[0]-AX[1])<=10)and(SPA[1]==0)){
    if (AY[0]>AY[1]){
    if ((AX[0]-6>AX[1])and(M[1]==-1)){M[1]=-M[1];}
    if ((AX[0]+6<AX[1])and(M[1]==1)){M[1]=-M[1];}}
    if (AY[0]<AY[1]){
    if ((AX[0]<AX[1])and(M[1]==-1)){M[1]=-M[1];}
    if ((AX[0]>AX[1])and(M[1]==1)){M[1]=-M[1];}}
    }else{
      CPUX++;
      if ((CPUX>=CPUC)and(SPA[1]==0)){CPUX=0;CPUC=random(16);}
      }
  if (EN[1]==28){CPUY++;}
  if ((CPUY>=30)and(SPA[1]==0)and(EN[1]==28)and(AY[1]>0)){SPA[1]=8;EN[1]=0;CPUY=0;}}
  if (lev==2){
  if ((abs(AX[0]-AX[1])<=16)and(SPA[1]==0)){
    if (AY[0]>AY[1]){
    if ((AX[0]-2>AX[1])and(M[1]==-1)){M[1]=-M[1];}
    if ((AX[0]+2<AX[1])and(M[1]==1)){M[1]=-M[1];}}
    if (AY[0]<AY[1]){
    if ((AX[0]<AX[1])and(M[1]==-1)){M[1]=-M[1];}
    if ((AX[0]>AX[1])and(M[1]==1)){M[1]=-M[1];}}
    }else{
      if (((LY[CPUC]>AY[1])or(LY[CPUC]<-8))and(SPA[1]==0)){
        CPUC=random(10);
      }else{
    if ((LX[CPUC]>AX[1]-2)and(M[1]==-1)and(SPA[1]==0)){M[1]=-M[1];}
    if ((LX[CPUC]<AX[1]+2)and(M[1]==1)and(SPA[1]==0)){M[1]=-M[1];}
      }
      }
  if (EN[1]==28){CPUY++;}
  if ((CPUY>=5)and(SPA[1]==0)and(EN[1]==28)and(AY[1]>0)and(AY[1]<AY[0])and(AY[1]+20>AY[0]and((AX[0]-AX[1])*M[1])>0)){SPA[1]=8;EN[1]=0;CPUY=0;}}
  
  

}

}
if (vs==1){
if ((arduboy.justPressed(A_BUTTON)and(SPA[1]==0))){M[1]=-M[1];}
if ((arduboy.justPressed(B_BUTTON)and(SPA[1]==0)and(EN[1]==28))and(AY[1]>0)){SPA[1]=8;EN[1]=0;}

if ((arduboy.justPressed(DOWN_BUTTON)and(SPA[0]==0))){M[0]=-M[0];}
if ((arduboy.justPressed(UP_BUTTON)and(SPA[0]==0)and(EN[0]==28))and(AY[0]>0)){SPA[0]=8;EN[0]=0;}
if ((arduboy.justPressed(RIGHT_BUTTON)and(SPA[0]==0))){M[0]=-M[0];}
if ((arduboy.justPressed(LEFT_BUTTON)and(SPA[0]==0)and(EN[0]==28))and(AY[0]>0)){SPA[0]=8;EN[0]=0;}
}

TC=(TC+1)%8;
if ((TIME!=0)and(TC==7)){TIME--;}
if ((TIME%2==0)and(TC==7)){EN[0]++;EN[1]++;}
if ((TIME%2==1)and(TC==7)){
  if (Po[0]>=Po[1]+3){EN[1]++;}
  if (Po[1]>=Po[0]+3){EN[0]++;}
  }
  if ((TIME%2==0)and(TC==3)){
  if (Po[0]>=Po[1]+6){EN[1]++;}
  if (Po[1]>=Po[0]+6){EN[0]++;}
  }
  if ((TIME%2==1)and(TC==3)){
  if (Po[0]>=Po[1]+9){EN[1]++;}
  if (Po[1]>=Po[0]+9){EN[0]++;}
  }
  if ((TIME%2==0)and(TC==1)){
  if (Po[0]>=Po[1]+15){EN[1]++;}
  if (Po[1]>=Po[0]+15){EN[0]++;}
  }
  if ((TIME%2==1)and(TC==1)){
  if (Po[0]>=Po[1]+21){EN[1]++;}
  if (Po[1]>=Po[0]+21){EN[0]++;}
  }
  if ((TC==5)){
  if (Po[0]>=Po[1]+30){EN[1]++;}
  if (Po[1]>=Po[0]+30){EN[0]++;}
  }

//if ((arduboy.justPressed(B_BUTTON))and(AJ==0)){AJ=1;}
//オリジナル
/*
if ((((AX[0]-AX[1])*(AX[0]-AX[1]))<=64)and(((AY[0]-AY[1])*(AY[0]-AY[1]))<=64)){
  if ((SPA[0]==0)and(SPA[1]==0)){
  if (((AX[0]-AX[1])*(AX[0]-AX[1]))<=((AY[0]-AY[1])*(AY[0]-AY[1]))){
  hold=AJ[0];AJ[0]=AJ[1];AJ[1]=hold;
  if ((AY[0]>AY[1])and(Po[0]!=0)){Po[1]++;Po[0]--;}
  if ((AY[1]>AY[0])and(Po[1]!=0)){Po[0]++;Po[1]--;}

  if (AJ[0]==0){AJ[0]=1;}
  if (AJ[1]==0){AJ[1]=1;}
  }else{
    if (AX[0]<AX[1]){M[0]=-1;M[1]=1;}else{M[0]=1;M[1]=-1;}
  }
  }else{if (SPA[0]!=0){Po[0]=Po[0]+4;Po[1]=Po[1]-4;}else{Po[1]=Po[1]+4;Po[0]=Po[0]-4;}}
}
*/
//分身用
for (uint8_t iii = 0; iii < 3; iii++) {
hold2=-64*iii;
if ((((AX[0]+64+hold2-AX[1])*(AX[0]+64+hold2-AX[1]))<=81)and(((AY[0]-AY[1])*(AY[0]-AY[1]))<=81)){
  if ((SPA[0]==0)and(SPA[1]==0)){
if (((AX[0]+64+hold2-AX[1])*(AX[0]+64+hold2-AX[1]))<=((AY[0]-AY[1])*(AY[0]-AY[1]))){
if ((((AJ[0]<10)and(AJ[1]>=10))or((AJ[1]<10)and(AJ[0]>=10)))and(GG[0]+GG[1]<=4)){
 hold=AJ[0];AJ[0]=AJ[1];AJ[1]=hold;
 if ((AY[0]>AY[1])and(Po[0]>0)){Po[1]++;Po[0]--;GG[0]=6;EN[0]++;}
 if ((AY[1]>AY[0])and(Po[1]>0)){Po[0]++;Po[1]--;GG[1]=6;EN[1]++;}

 if (AJ[0]==0){AJ[0]=1;}
 if (AJ[1]==0){AJ[1]=1;}
}
}else{
  if (AX[0]+64+hold2<AX[1]){M[0]=-1;M[1]=1;}else{M[0]=1;M[1]=-1;}
}
  }else{
    for (uint8_t iii5 = 0; iii5 < 3; iii5++) {
    if ((SPA[0]!=0)and(SPA[1]==0)and(Po[1]>0)){Po[0]=Po[0]+1;Po[1]=Po[1]-1;GG[1]=6;EN[1]++;}
    if ((SPA[1]!=0)and(SPA[0]==0)and(Po[0]>0)){Po[1]=Po[1]+1;Po[0]=Po[0]-1;GG[0]=6;EN[0]++;}
    }
        }
}
}
/*
if ((((AX[0]-64-AX[1])*(AX[0]-64-AX[1]))<=64)and(((AY[0]-AY[1])*(AY[0]-AY[1]))<=64)){
  if ((SPA[0]==0)and(SPA[1]==0)){
if (((AX[0]-64-AX[1])*(AX[0]-64-AX[1]))<=((AY[0]-AY[1])*(AY[0]-AY[1]))){
hold=AJ[0];AJ[0]=AJ[1];AJ[1]=hold;
if ((AY[0]>AY[1])and(Po[0]!=0)){Po[1]++;Po[0]--;EN[0]++;}
if ((AY[1]>AY[0])and(Po[1]!=0)){Po[0]++;Po[1]--;EN[1]++;}

if (AJ[0]==0){AJ[0]=1;}
if (AJ[1]==0){AJ[1]=1;}
}else{
  if (AX[0]-64<AX[1]){M[0]=-1;M[1]=1;}else{M[0]=1;M[1]=-1;}
}
  }else{if (SPA[0]!=0){Po[0]=Po[0]+4;Po[1]=Po[1]-4;}else{Po[1]=Po[1]+4;Po[0]=Po[0]-4;}}
}
*/

for (uint8_t i = 0; i < 10; i++) {
    LY[i]=LY[i]+2;
    for (uint8_t i2 = 0; i2 < 10; i2++) {
      if (((LX[i]-LX[i2])*(LX[i]-LX[i2])<=25)and((LY[i]-LY[i2])*(LY[i]-LY[i2])<=25)and(i!=i2)){LY[i]=LY[i]-20;}
      }
}

  for (uint8_t ip = 0; ip < 2; ip++) {
  Jsw[ip]=1;
  if (arduboy.getPixel(AX[ip]+5+32,62)==1){Jsw[ip]=0;}
  if ((AX[ip]-32)*(AX[ip]-32)>=784){Jsw[ip]=0;}
  
  if ((Jsw[ip]==1)and(AJ[ip]==0)){AJ[ip]=1;}

  if (GG[ip]!=0){GG[ip]--;}

  for (uint8_t i = 0; i < 10; i++) {
    if (LY[i]>=72){LY[i]=-128+random(96);LX[i]=random(56);}
    loopMX=AX[ip]+5;loopMY=AY[ip]+5;loopX=LX[i]+4;loopY=LY[i]+4;
    if (((loopMX-loopX)*(loopMX-loopX)<=25)and((loopMY-loopY)*(loopMY-loopY)<=25)){LY[i]=-128+random(96);LX[i]=random(56);Po[ip]++;}
    if (((loopMX-loopX+64)*(loopMX-loopX+64)<=25)and((loopMY-loopY)*(loopMY-loopY)<=25)){LY[i]=-128+random(96);LX[i]=random(56);Po[ip]++;}
  }

  if (AX[ip]>64){AX[ip]=0;}
  if (AX[ip]<0){AX[ip]=64;}
  
  if (SPA[ip]==0){
  if (AJ[ip]!=0){AY[ip]=AY[ip]-(10-AJ[ip]);AJ[ip]++;}
  AX[ip]=AX[ip]+2*M[ip];
  }else{AX[ip]=AX[ip]+8*M[ip];AY[ip]=AY[ip]+2;AJ[ip]=10;if (AY[ip]<4){SPA[ip]=0;AJ[ip]=10;};SPA[ip]--;}
  if (AY[ip]>=47){AY[ip]=47;AJ[ip]=0;}

  if (SPA[ip]>=8){SPA[ip]=0;}
  }
  toko=toko+1;
  if (toko==4){toko=0;}

  
  //Sprites::drawExternalMask(AX+32, 47, A_1,A_1M, 0, 0);
  //Sprites::drawExternalMask(AX-32, 47, A_1,A_1M, 0, 0);


}

for (uint8_t i = 0; i < 10; i++) {
  Sprites::drawExternalMask(LX[i]+32, LY[i], hart,hart_M, 0, 0);
}

for (uint8_t ip = 0; ip < 2; ip++) {
  arduboy.fillRect(0,0,15,64,0);
if((ty+ip)%2==0){
  if (AJ[ip]==0){
  if (toko<=1){
  Sprites::drawExternalMask(1, 0, A_2MK,A_2M, 0, 0);
  Sprites::drawExternalMask(1, 20, A_2,A_2M, 0, 0);
  }else{
  Sprites::drawExternalMask(1, 0, A_1MK,A_1M, 0, 0);
  Sprites::drawExternalMask(1, 20, A_1,A_1M, 0, 0);
  }
  }else{
    if(AJ[ip]<=10){
  Sprites::drawExternalMask(1, 0, A_3MK,A_3M, 0, 0);
  Sprites::drawExternalMask(1, 20, A_3,A_3M, 0, 0);
    }else{
  Sprites::drawExternalMask(1, 0, A_4MK,A_4M, 0, 0);
  Sprites::drawExternalMask(1, 20, A_4,A_4M, 0, 0);
    }
  }
}else{
  
  if (AJ[ip]==0){
  if (toko<=1){
  Sprites::drawExternalMask(0, 0, B_2MK,B_2M, 0, 0);
  Sprites::drawExternalMask(0, 20, B_2,B_2M, 0, 0);
  }else{
  Sprites::drawExternalMask(0, 0, B_1MK,B_1M, 0, 0);
  Sprites::drawExternalMask(0, 20, B_1,B_1M, 0, 0);
  }
  }else{
    if(AJ[ip]<=10){
  Sprites::drawExternalMask(0, 0, B_3MK,B_3M, 0, 0);
  Sprites::drawExternalMask(0, 20, B_3,B_3M, 0, 0);
    }else{
  Sprites::drawExternalMask(0, 0, B_4MK,B_4M, 0, 0);
  Sprites::drawExternalMask(0, 20, B_4,B_4M, 0, 0);
    }
  }
}

for (uint8_t i = 0; i < 13; i++) {
  for (uint8_t i2 = 0; i2 < 11; i2++) {
    CC=arduboy.getPixel(i2,i);
     if ((CC==1)and(M[ip]==1)){arduboy.drawPixel(AX[ip]+32+i2,AY[ip]+i,arduboy.getPixel(i2,i+20));if (AX[ip]>=56){arduboy.drawPixel(AX[ip]-32+i2,AY[ip]+i,arduboy.getPixel(i2,i+20));}}
     if ((CC==1)and(M[ip]==-1)){arduboy.drawPixel(AX[ip]+32+9-i2,AY[ip]+i,arduboy.getPixel(i2,i+20));if (AX[ip]>=56){arduboy.drawPixel(AX[ip]-32+9-i2,AY[ip]+i,arduboy.getPixel(i2,i+20));}}
  }
}
}
  //Sprites::drawExternalMask(32, 0, A_2,A_2M, 0, 0);

for (uint8_t i = 0; i < 2; i++) {
  if ((SPA[i]!=0)and(M[i]==1)){Sprites::drawExternalMask(AX[i]+32+4, AY[i]+4, D_1,D_1M, 0, 0);}
  if ((SPA[i]!=0)and(M[i]==-1)){Sprites::drawExternalMask(AX[i]+32-4, AY[i]+4, D_2,D_2M, 0, 0);}
  
  if ((SPA[i]!=0)and(M[i]==1)and(AX[i]>=56)){Sprites::drawExternalMask(AX[i]-32+4, AY[i]+4, D_1,D_1M, 0, 0);}
  if ((SPA[i]!=0)and(M[i]==-1)and(AX[i]>=56)){Sprites::drawExternalMask(AX[i]-32-4, AY[i]+4, D_2,D_2M, 0, 0);}
}

arduboy.fillRect(0,0,32,64,0);
arduboy.fillRect(96,0,32,64,0);

arduboy.fillRect(32,0,64,2,0);
arduboy.fillRect(32,0,TIME,1,1);
//arduboy.drawLine(32,0,32+TIME,0,WHITE);

for (uint8_t i = 0; i < 10; i++) {
  if (LY[i]<=-4){arduboy.drawPixel(LX[i]+32+4,2,0);}
  if ((LY[i]<=-4)and(LY[i]>=-32)){arduboy.drawPixel(LX[i]+32+4,3,0);}
  if ((LY[i]<=-4)and(LY[i]>=-16)){arduboy.drawPixel(LX[i]+32+4,4,0);}
  if ((LY[i]<=-4)and(LY[i]>=-8)){arduboy.drawPixel(LX[i]+32+4,5,0);}
}


for (uint8_t ip = 0; ip < 2; ip++) {
arduboy.fillRect(96,0,32,64,0);
XT=1;
YT=(10-AJ[ip])*(10-AJ[ip])/20;

if((ty+ip)%2==1){//チサ
if (TC%2==0){
if (AJ[ip]==0){
  if (YURE_M>1){YURE_M--;}
  else if (YURE_M<1){YURE_M++;}
  }
if ((AJ[ip]!=0)and(AJ[ip]<10)){
  if (YURE_M>=1){YURE_M--;}
  else if (YURE_M<1){YURE_M=2;}
  }
if ((AJ[ip]!=0)and(AJ[ip]>10)){
  if (YURE_M>2){YURE_M=1;}
  else if (YURE_M<=2){YURE_M++;}
  }
}
//if (YURE_M>YURE){YURE++;}
//if (YURE_M<YURE){YURE--;}
YURE=YURE_M;

if ((AJ[ip]!=0)and(AJ[ip]<10)and(TC%3==0)){hair=(hair+1)%5;}
if ((AJ[ip]>=10)){hair=(hair+1)%5;}
if (hair==0){
 //髪1
  arduboy.drawLine(125+XT,15+YT,125+XT,22+YT,WHITE);
  arduboy.drawLine(124+XT,23+YT,124+XT,34+YT,WHITE);
  
  arduboy.drawLine(104+XT,17+YT,104+XT,25+YT,WHITE);
  arduboy.drawLine(105+XT,26+YT,105+XT,28+YT,WHITE);
  arduboy.drawLine(106+XT,29+YT,106+XT,31+YT,WHITE);
}
if (hair==1){
  //髪2
  arduboy.drawLine(125+XT,15+YT,125+XT,28+YT,WHITE);
  arduboy.drawLine(124+XT,29+YT,124+XT,34+YT,WHITE);
  
  arduboy.drawLine(104+XT,17+YT,104+XT,23+YT,WHITE);
  arduboy.drawLine(105+XT,24+YT,105+XT,26+YT,WHITE);
  arduboy.drawLine(106+XT,27+YT,106+XT,28+YT,WHITE);
  arduboy.drawLine(107+XT,29+YT,106+XT,34+YT,WHITE);
}
if (hair==2){
  //髪3
  arduboy.drawLine(125+XT,15+YT,125+XT,20+YT,WHITE);
  arduboy.drawLine(126+XT,21+YT,126+XT,31+YT,WHITE);
  arduboy.drawLine(125+XT,32+YT,125+XT,34+YT,WHITE);
  
  arduboy.drawLine(104+XT,17+YT,104+XT,22+YT,WHITE);
  arduboy.drawLine(105+XT,23+YT,105+XT,25+YT,WHITE);
  arduboy.drawLine(106+XT,26+YT,108+XT,31+YT,WHITE);
}
if (hair==3){
  //髪4
  arduboy.drawLine(125+XT,15+YT,125+XT,28+YT,WHITE);
  arduboy.drawLine(126+XT,29+YT,126+XT,34+YT,WHITE);
  
  arduboy.drawLine(104+XT,17+YT,104+XT,23+YT,WHITE);
  arduboy.drawLine(105+XT,24+YT,105+XT,27+YT,WHITE);
  arduboy.drawLine(106+XT,28+YT,106+XT,29+YT,WHITE);
  arduboy.drawLine(107+XT,30+YT,108+XT,31+YT,WHITE);
}
if (hair==4){ 
  //髪5
  arduboy.drawLine(125+XT,15+YT,125+XT,22+YT,WHITE);
  arduboy.drawLine(124+XT,23+YT,124+XT,28+YT,WHITE);
  arduboy.drawLine(125+XT,29+YT,125+XT,32+YT,WHITE);
  arduboy.drawPixel(126+XT,33+YT,1);
  
  arduboy.drawLine(104+XT,17+YT,104+XT,24+YT,WHITE);
  arduboy.drawLine(105+XT,25+YT,105+XT,28+YT,WHITE);
  arduboy.drawLine(106+XT,29+YT,106+XT,30+YT,WHITE);
  arduboy.drawPixel(107+XT,31+YT,1);
}


  //後ろ腕
if ((AJ[ip]==0)and(GG[ip]==0)){
  arduboy.drawLine(104+XT,50+YT,104+XT,64+YT,WHITE);
  arduboy.drawLine(103+XT,53+YT,103+XT,64+YT,WHITE);
  arduboy.drawLine(102+XT,56+YT,102+XT,64+YT,WHITE);
  arduboy.drawLine(101+XT,61+YT,101+XT,64+YT,WHITE);
}
  
if ((AJ[ip]!=0)and(GG[ip]==0)){Sprites::drawExternalMask(  95+XT, 44+YT, JPB2,JPB2_M, 0, 0);}
if (GG[ip]!=0){Sprites::drawExternalMask(  95+XT, 24+YT, KAIHI3,KAIHI3_M, 0, 0);}
Sprites::drawExternalMask(  100+XT, 31+YT, UE,UE_M, 0, 0);
Sprites::drawExternalMask(  103+XT, 52+YT, SITA,SITA_M, 0, 0);
arduboy.fillRect(113+XT,29+YT,5,2,1);
arduboy.drawPixel(118+XT,17+YT,1);

//YURE=(YURE+(TC/15))%4;


if (YURE==1){Sprites::drawExternalMask(  96+XT, 37+YT, MUNE1,MUNE1_M, 0, 0);}
if (YURE==0){Sprites::drawExternalMask(  97+XT, 37+YT, MUNE2,MUNE2_M, 0, 0);}
if (YURE==2){Sprites::drawExternalMask(  95+XT, 36+YT, MUNE3,MUNE3_M, 0, 0);}
if (YURE==3){Sprites::drawExternalMask(  95+XT, 33+YT, MUNE4,MUNE4_M, 0, 0);}


Sprites::drawExternalMask(  108+XT, 18+YT, KAO,KAO_M, 0, 0);
if ((TIME%2==ip)and(TC%8==6)){Sprites::drawExternalMask(  108+XT, 18+YT, KAOAH3,KAOAH3_M, 0, 0);}
//if (Po[ip]+5>=Po[(ip+1)%2]){Sprites::drawExternalMask(  108+XT, 18+YT, KAOAH2,KAOAH2_M, 0, 0);}
//if (Po[ip]+10>=Po[(ip+1)%2]){Sprites::drawExternalMask(  108+XT, 18+YT, KAOAH2,KAOAH1_M, 0, 0);}
if (Po[ip]>=Po[(ip+1)%2]+4){arduboy.drawPixel(108+4+XT,18+7+YT,0);}
if (Po[ip]>=Po[(ip+1)%2]+7){Sprites::drawExternalMask(  108+XT, 18+YT, KAOAH2,KAOAH1_M, 0, 0);}
if (GG[ip]!=0){Sprites::drawExternalMask(  108+XT, 18+YT, KAOAH1,KAOAH1_M, 0, 0);}
Sprites::drawExternalMask(  105+XT, 7+YT, ATAMA1,ATAMA1_M, 0, 0);
if ((AJ[ip]==0)and(GG[ip]==0)){Sprites::drawExternalMask(  119+XT, 47+YT, UDEA2,UDEA2_M, 0, 0);}
if ((AJ[ip]==0)and(GG[ip]==0)){Sprites::drawExternalMask(  101+XT, 56+YT, UDEA1,UDEA1_M, 0, 0);}

if (GG[ip]!=0){Sprites::drawExternalMask(  95+XT, 12+YT, KAIHI2,KAIHI2_M, 0, 0);}
if (GG[ip]!=0){Sprites::drawExternalMask(  101+XT, 34+YT, KAIHI1,KAIHI1_M, 0, 0);}

if ((AJ[ip]!=0)and(GG[ip]==0)){Sprites::drawExternalMask(  119+XT, 47+YT, JPB1,JPB1_M, 0, 0);}
}
if((ty+ip)%2==0){//カイ
if ((AJ[ip]!=0)and(GG[ip]==0)){Sprites::drawExternalMask(  97, 5+YT, JP1,JP1_M, 0, 0);}
if ((AJ[ip]==0)and(GG[ip]==0)){Sprites::drawExternalMask(  96, 30+YT, UDEF2,UDEF2_M, 0, 0);}
if (GG[ip]!=0){Sprites::drawExternalMask(  96, 40+YT, GARD2,GARD2_M, 0, 0);}
Sprites::drawExternalMask(  104, 9+YT, KAOB,KAOB_M, 0, 0);
if ((TIME%2==ip)and(TC%8==6)){Sprites::drawExternalMask(  104+4+XT, 9+13+YT, KAOBH2,KAOBH2_M, 0, 0);}
if (Po[ip]>=Po[(ip+1)%2]+4){arduboy.drawPixel(108+4+XT,18+10+YT,0);}
if (Po[ip]>=Po[(ip+1)%2]+7){Sprites::drawExternalMask(  104+4+XT, 9+13+YT, KAOBH3,KAOBH1_M, 0, 0);}
if (GG[ip]!=0){Sprites::drawExternalMask(  104+4+XT, 9+13+YT, KAOBH1,KAOBH1_M, 0, 0);}


Sprites::drawExternalMask(  101, 34+YT, UE,UE_M, 0, 0);
Sprites::drawExternalMask(  104, 52+YT, SITA,SITA_M, 0, 0);
if ((AJ[ip]==0)and(GG[ip]==0)){Sprites::drawExternalMask(  111, 34+YT, UDEF1,UDEF1_M, 0, 0);}
if ((AJ[ip]!=0)and(GG[ip]==0)){Sprites::drawExternalMask(  120, 37+YT, JP2,JP2_M, 0, 0);}
if ((AJ[ip]!=0)and(GG[ip]==0)){
arduboy.drawLine(103,39+YT,106,36+YT,WHITE);
arduboy.drawLine(102,39+YT,102,44+YT,WHITE);
arduboy.drawLine(105,35+YT,108,35+YT,WHITE);
arduboy.drawLine(105,34+YT,106,34+YT,WHITE);
}
if (GG[ip]!=0){Sprites::drawExternalMask(  96, 26+YT, GARD1,GARD1_M, 0, 0);}
}

if (ip==0){
//左右反転
for (uint8_t i = 6; i < 64; i++) {
    for (uint8_t i2 = 0; i2 < 32; i2++) {
      CC=arduboy.getPixel(i2+96,i);
      if (CC==1){arduboy.drawPixel(31-i2,i,1);}
    }
}
}

}


arduboy.fillRect(1,0,30,5,1);
arduboy.fillRect(97,0,30,5,1);


  if (EN[0]>=28){EN[0]=28;}
  if (EN[1]>=28){EN[1]=28;}


arduboy.fillRect(2,1,EN[0],3,0);
arduboy.fillRect(98,1,EN[1],3,0);
if (EN[0]>=28){Sprites::drawExternalMask(  6, 0, MAX,MAX_M, 0, 0);}
if (EN[1]>=28){Sprites::drawExternalMask(102, 0, MAX,MAX_M, 0, 0);}






arduboy.setTextColor(1);
if (Po[0]/10==0){arduboy.setCursor(26,6);}
else if (Po[0]/100==0){arduboy.setCursor(20,6);}
else {arduboy.setCursor(14,6);}
if (SC>=0){arduboy.print(Po[0]);}
arduboy.setCursor(96,6);
if (SC>=0){arduboy.print(Po[1]);}


if (SC>0){
  SC--;
arduboy.setTextSize(2);

arduboy.setTextColor(0);
arduboy.setCursor(58,6);
if (SC/5!=0){arduboy.print(SC/5);}
arduboy.setCursor(40,6);
if (SC/5==0){arduboy.print("GO!!");}
arduboy.setTextSize(1); 
arduboy.setTextColor(1);

}

if (SC<0){
  if ((SC==-25)and((arduboy.justPressed(A_BUTTON)))){mode=3;}
  if (SC>-25){SC--;}
//arduboy.setTextSize(2);
//AJ[0]=0;AJ[1]=0;
winner=0;
for (uint8_t ip = 0; ip < 2; ip++) {
if (GG[ip]!=0){GG[ip]--;}
if (AJ[ip]!=0){AY[ip]=AY[ip]-(10-AJ[ip]);AJ[ip]++;}
if (AY[ip]>=47){AY[ip]=47;AJ[ip]=0;}
}



if (SC/8==0){arduboy.fillRect(40,6,48,8,1);}
if (SC/8<=-1){arduboy.fillRect(40,6,12,8,1);}
if (SC/8<=-2){arduboy.fillRect(76,6,12,8,1);}
if (SC/8<=-3){arduboy.fillRect(32,18,64,16,1);}

arduboy.setTextSize(1);
arduboy.setTextColor(0);
arduboy.setCursor(40,6);
if (SC/8==0){arduboy.print("finish!!");}
if (SC/8<=-1){arduboy.print(Po[0]);}
arduboy.setCursor(76,6);
if (SC/8<=-2){arduboy.print(Po[1]);}
arduboy.setTextSize(2); 
arduboy.setCursor(33,18);
if ((SC/8<=-3)and(Po[0]>Po[1])){arduboy.print("1P");winner=1+ty;if ((lev==2)and(vs==0)){SF=1;}}
if ((SC/8<=-3)and(Po[0]<Po[1])){arduboy.print("2P");winner=2-ty;}
arduboy.setCursor(60,18);
if ((SC/8<=-3)and(Po[0]!=Po[1])){arduboy.print("WIN");}
arduboy.setCursor(40,18);
if ((SC/8<=-3)and(Po[0]==Po[1])){arduboy.print("DRAW");}
arduboy.setTextSize(1); 
arduboy.setTextColor(1);

if (SC/8<=-3){
if (winner==1){
arduboy.fillRect(ty*96,0,32,64,0);
Sprites::drawExternalMask(  ty*96, 0, SPT,SPT_M, 0, 0);
Sprites::drawExternalMask(  ty*96+13, 0+14, SPTF,SPTF_M, 0, 0);}
if (winner==2){
arduboy.fillRect((1-ty)*96,0,32,64,0);
Sprites::drawExternalMask(  (1-ty)*96, 0, SPK,SPK_M, 0, 0);
Sprites::drawExternalMask(  (1-ty)*96+13, 0+13, SPKF,SPKF_M, 0, 0);}
}

}


}//mode用1
if (mode==2){//おまけ鑑賞モード
arduboy.fillRect(0,0,96,64,0);
if (ty==1){XT=48;Sprites::drawExternalMask(  XT, YT, SPK,SPK_M, 0, 0);}
if (ty==1){Sprites::drawExternalMask(  XT, YT+64, SPU,SPU_M, 0, 0);}
if (ty==0){XT=27;Sprites::drawExternalMask(  XT, YT, SPU2,SPU2_M, 0, 0);}
if (ty==0){Sprites::drawExternalMask(  XT+6, YT+49, SPU3,SPU3_M, 0, 0);}

arduboy.setTextColor(1);
arduboy.setCursor(0,0);
if (ty==1){arduboy.print("KAI");}
if (ty==0){arduboy.print("TISA");}

if (ty==1){arduboy.setCursor(0,YT+138);arduboy.print("She is quiet and \nserious.");arduboy.setCursor(0,YT+152);}
if (ty==0){arduboy.setCursor(0,YT+123);arduboy.print("She's an energetic, \nactive person.");arduboy.setCursor(0,YT+139);}
                                       arduboy.print("\nKai and Tisa are \nchildhood friends and \nvery close.");


if ((arduboy.pressed(UP_BUTTON))){YT=YT+2;}
if ((arduboy.pressed(DOWN_BUTTON))){YT=YT-2;}
if ((arduboy.justPressed(A_BUTTON))){mode=3;}

}
if (mode==0){
  
//if ((arduboy.justPressed(B_BUTTON))){ty=(ty+1)%2;}
if ((arduboy.justPressed(A_BUTTON))and(sel==0)){mode=1;vs=0;}
if ((arduboy.justPressed(A_BUTTON))and(sel==1)){lev=(lev+1)%3;}
if ((arduboy.justPressed(A_BUTTON))and(sel==2)){mode=1;vs=1;}
if ((arduboy.justPressed(A_BUTTON))and(sel==3)){ty=(ty+1)%2;}
if ((arduboy.justPressed(A_BUTTON))and(sel==4)){mode=2;}
if ((arduboy.justPressed(UP_BUTTON))and(SF==1)){sel=(sel+4)%5;}
if ((arduboy.justPressed(DOWN_BUTTON))and(SF==1)){sel=(sel+1)%5;}
if ((arduboy.justPressed(UP_BUTTON))and(SF==0)){sel=(sel+3)%4;}
if ((arduboy.justPressed(DOWN_BUTTON))and(SF==0)){sel=(sel+1)%4;}
Sprites::drawExternalMask(  ty*96, 0, SPT,SPT_M, 0, 0);
//Sprites::drawExternalMask(  ty*96+13, 0+14, SPTF,SPTF_M, 0, 0);
Sprites::drawExternalMask(  (1-ty)*96, 0, SPK,SPK_M, 0, 0);
//Sprites::drawExternalMask(  (1-ty)*96+13, 0+13, SPKF,SPKF_M, 0, 0);


arduboy.setTextColor(0);
arduboy.setCursor(33,0);
if (ty==1){arduboy.print("KAI");}
if (ty==0){arduboy.print("TISA");}

arduboy.setCursor(58,3);
arduboy.print("vs");

arduboy.setCursor(72,6);
if (ty==0){arduboy.print("KAI");}
if (ty==1){arduboy.print("TISA");}

arduboy.setTextSize(1);
arduboy.setCursor(48,18);
arduboy.print("VS CPU");

arduboy.setCursor(48,26);
if (lev==0){arduboy.print("Easy");}
if (lev==1){arduboy.print("Normal");}
if (lev==2){arduboy.print("Hard");}

arduboy.setCursor(48,34);
arduboy.print("VS 2P");
arduboy.setCursor(48,42);
arduboy.print("Change");
arduboy.setCursor(48,50);
if (SF==1){arduboy.print("Omake");}


arduboy.setCursor(42,18+sel*8);
arduboy.print(">");
}
if (mode==3){
mode=0;
for (uint8_t i = 0; i < 10; i++) {
LY[i]=-128+random(96);LX[i]=random(56);
}
AX[0]=0;
AX[1]=56;
AY[0]=47;
AY[1]=47;
CC=0;
M[0]=1;
M[1]=-1;
Po[0]=0;
Po[1]=0;
GG[0]=0;
GG[1]=0;

XT=0;
YT=0;

hair=0;
YURE=0;
YURE_M=0;



CPUX=0;
CPUY=0;
CPUC=0;


SC=20;

hold=0;
hold2=0;
SPA[0]=0;
SPA[1]=0;



TIME=64;
TC=0;
EN[0]=0;
EN[1]=0;

loopY=0;
loopX=0;
loopMY=0;
loopMX=0;

toko=0;
Jsw[0]=0;
Jsw[1]=0;
}

  //Sprites::drawExternalMask(0, 0, A_2MK,A_2M, 0, 0);
  //Sprites::drawExternalMask(0, 20, A_2,A_2M, 0, 0);
  


  arduboy.display();
}
