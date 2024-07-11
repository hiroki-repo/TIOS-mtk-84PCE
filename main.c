#include "Math.h"
#include "Stdlib.h"
#include "Stdio.h"
#include "Stdarg.h"
#include "Stddef.h"
#include "String.h"
extern char* em180mem;

char context[16][3*16];

typedef unsigned int SVCID;

typedef signed int ID;
typedef void* VP;
typedef signed int VP_INT;
typedef void* FP;
typedef unsigned int PRI;
typedef unsigned int SIZE;
typedef unsigned int ATR;
typedef signed int ER;

#define E_OK 0
#define E_SYS -5
#define E_NOSPT -9
#define E_RSFN -10
#define E_RSATR -11
#define E_PAR -17
#define E_ID -18
#define E_CTX -25
#define E_MACV -26
#define E_OACV -27
#define E_ILUSE -28
#define E_NOMEM -33
#define E_NOID -34
#define E_OBJ -41
#define E_NOEXS -42
#define E_OOVR -43
#define E_RLWAI -49
#define E_TMOUT -50
#define E_DLT -51
#define E_CLS -52
#define E_WBLK -57
#define E_BOVR -58

int pidnow;

typedef struct t_ctsk {
	ATR tskatr;
	VP_INT exinf;
	FP task;
	PRI itskpri;
	SIZE stksz;
	VP stk;
	VP context;
} T_CTSK;

extern ER unsup_svc(void){
	return E_NOSPT;
}

extern ER cre_tsk(ID tskid,T_CTSK* pk_ctsk){
	if (context[tskid][3*13]==0x00){
		context[tskid][3*13] = 0x5B;
		(*(FP*)&context[tskid][3*11]) = pk_ctsk->task;
		(*(VP*)&context[tskid][3*12]) = pk_ctsk->stk;
		pk_ctsk->context = &context[tskid];
		(*(T_CTSK**)&context[tskid][3*15]) = pk_ctsk;
		return E_OK;
	}
	return E_SYS;
}

extern ER del_tsk(ID tskid){
	if (tskid>=16){return E_ID;}
	if (tskid==pidnow){return E_OBJ;}
	if (context[tskid][3*13]!=0x00){
		context[tskid][3*13] = 0;
		(*(T_CTSK**)&context[tskid][3*15]) = 0;
		return E_OK;
	}
	return E_NOEXS;
}

/*ER(*syscalltable[])(void)={0,0,0,0,0,(ER(*)(void))cre_tsk};

extern ER syscallhandler(SVCID syscallid,VP prm_0,VP prm_1,VP prm_2,VP prm_3,VP prm_4,VP prm_5,VP prm_6,VP prm_7,VP prm_8,VP prm_9){
	return ((ER(*)(VP,VP,VP,VP,VP,VP,VP,VP,VP,VP))syscalltable[syscallid])(prm_0,prm_1,prm_2,prm_3,prm_4,prm_5,prm_6,prm_7,prm_8,prm_9);
}*/

extern int main(){
	while(1){
		for(pidnow=0;pidnow<16;pidnow++){
			if (context[pidnow][3*13]!=0x00){
				memcpy(&em180mem,context[pidnow],sizeof(context[pidnow]));
				em180();
				memcpy(context[pidnow],&em180mem,sizeof(context[pidnow]));
			}
		}
	}
	//memcpy(0xD40000,0xD40001,65536);
	return 0;
}