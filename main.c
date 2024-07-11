#include "Math.h"
#include "Stdlib.h"
#include "Stdio.h"
#include "Stdarg.h"
#include "Stddef.h"
#include "String.h"
extern char* em180mem;
extern char* em180_sa4resv;
unsigned int stackarearem = 3072;

#define GT_TASKMAX 15

char context[(GT_TASKMAX + 1)][3*16];

typedef unsigned int SVCID;

typedef signed int ID;
typedef void* VP;
typedef signed int VP_INT;
typedef void* FP;
typedef unsigned int PRI;
typedef unsigned int SIZE;
typedef unsigned int ATR;
typedef signed int ER;
typedef signed int ER_UINT;

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
	if (tskid==0){tskid = pidnow;}
	if (context[tskid][3*13]==0x00){
		if (pk_ctsk->stk == NULL){pk_ctsk->stk = malloc(pk_ctsk->stksz); if (pk_ctsk->stk == NULL){return E_NOMEM;}}
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
	if (tskid==0){tskid = pidnow;}
	if (tskid>=(GT_TASKMAX + 1)){return E_ID;}
	if (((*(T_CTSK**)&context[tskid][3*15])->tskatr & 2) == 0){return E_OBJ;}
	if (context[tskid][3*13]!=0x00){
		context[tskid][3*13] = 0;
		(*(T_CTSK**)&context[tskid][3*15]) = 0;
		return E_OK;
	}
	return E_NOEXS;
}

extern ER act_tsk(ID tskid){
	if (tskid==0){tskid = pidnow;}
	if (tskid>=(GT_TASKMAX + 1)){return E_ID;}
	if (context[tskid][3*13]!=0x00){
		T_CTSK* pk_ctsk = (*(T_CTSK**)&context[tskid][3*15]);
		pk_ctsk->tskatr &= ~(2);
		return E_OK;
	}
	return E_NOEXS;
}

extern ER_UINT can_act(ID tskid){
	return E_NOSPT;
}

extern void ext_tsk(void){
		T_CTSK* pk_ctsk = (*(T_CTSK**)&context[pidnow][3*15]);
		pk_ctsk->tskatr |= 2;
}

extern ER sta_tsk(ID tskid, VP_INT stacd){
	if (tskid==0){tskid = pidnow;}
	if (tskid>=(GT_TASKMAX + 1)){return E_ID;}
	if (((*(T_CTSK**)&context[tskid][3*15])->tskatr & 2) == 0){return E_OBJ;}
	if (context[tskid][3*13]!=0x00){
		T_CTSK* pk_ctsk = (*(T_CTSK**)&context[tskid][3*15]);
		pk_ctsk->tskatr &= ~(2);
		pk_ctsk->stk -= 3;
		(*(VP_INT*)(pk_ctsk->stk)) = stacd;
		pk_ctsk->stk -= 3;
		(*(VP_INT*)(pk_ctsk->stk)) = ((VP_INT)&ext_tsk);
		return E_OK;
	}
	return E_NOEXS;
}

extern void exd_tsk(){
	ext_tsk();
	del_tsk(0);
}

extern ER ter_tsk(ID tskid){
	if (tskid==0){tskid = pidnow;}
	if (tskid == pidnow){return E_ILUSE;}
	if (((*(T_CTSK**)&context[tskid][3*15])->tskatr & 2) != 0){return E_OBJ;}
	if (tskid>=(GT_TASKMAX + 1)){return E_ID;}
	if (context[tskid][3*13]!=0x00){
		T_CTSK* pk_ctsk = (*(T_CTSK**)&context[tskid][3*15]);
		pk_ctsk->tskatr &= ~(2);
		return E_OK;
	}
	return E_NOEXS;
}

extern ER chg_pri(ID tskid,PRI tskpri){
	if (tskid==0){tskid = pidnow;}
	if (tskid>=(GT_TASKMAX + 1)){return E_ID;}
	if (((*(T_CTSK**)&context[tskid][3*15])->tskatr & 2) != 0){return E_OBJ;}
	if (context[tskid][3*13]!=0x00){
		T_CTSK* pk_ctsk = (*(T_CTSK**)&context[tskid][3*15]);
		pk_ctsk->itskpri = tskpri;
		return E_OK;
	}
	return E_NOEXS;
}

extern ER get_pri(ID tskid,PRI *p_tskpri){
	if (tskid==0){tskid = pidnow;}
	if (tskid>=(GT_TASKMAX + 1)){return E_ID;}
	if (((*(T_CTSK**)&context[tskid][3*15])->tskatr & 2) != 0){return E_OBJ;}
	if (context[tskid][3*13]!=0x00){
		T_CTSK* pk_ctsk = (*(T_CTSK**)&context[tskid][3*15]);
		*p_tskpri = pk_ctsk->itskpri;
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
		for(pidnow=0;pidnow<(GT_TASKMAX + 1);pidnow++){
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