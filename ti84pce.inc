; TI-84 Plus CE Include file
; Various parts contributed by
;- BrandonW
;- calc84
;- tr1p1ea
;- Texas Instruments (Parts recycled from ti83plus.inc)
.nolist
#ifndef TI84PCE
#define TI84PCE

#define equ .equ
#define equ .equ
#define end .end
#define END .end

lcdWidth   .equ   320
lcdHeight   .equ   240

;-------------------------------------------------------------------------------
; Boot Calls
;-------------------------------------------------------------------------------
_getBootVerMajor   equ   0000080h
_getHardwareVersion   equ   0000084h
_getKeyID      equ   0000088h
_getBootVerMinor   equ   000008Ch
_getBootVerBuild   equ   0000090h
;0000094h ;outputs A to 0FFFEh and locks up, only on certain hardware revision?
__case   equ   000110h
__case16   equ   000114h
__case16D   equ   000118h
__case24   equ   00011Ch
__case24D   equ   000120h
__case8   equ   000124h
__case8D   equ   000128h
__frameset0   equ   000130h
__frameset   equ   00012Ch
__iand   equ   000134h
__icmpzero   equ   000138h
__idivs   equ   00013Ch
__idivu   equ   000140h
__idvrmu   equ   000144h
__ildix   equ   000148h
__ildiy   equ   00014Ch
__imul_b   equ   000150h
__imuls   equ   000154h
__imulu   equ   000158h
__indcall   equ   00015Ch
__ineg   equ   000160h
__sneg   equ   00022Ch
__inot   equ   000164h
__snot   equ   000230h
__ior   equ   000168h
__irems   equ   00016Ch
__iremu   equ   000170h
__ishl_b   equ   000178h
__ishl   equ   000174h
__ishrs_b   equ   000180h
__ishrs   equ   00017Ch
__ishru_b   equ   000188h
__ishru   equ   000184h
__istix   equ   00018Ch
__istiy   equ   000190h
__itol   equ   000194h
__ixor   equ   000198h
__ladd_b   equ   0001A0h
__ladd   equ   00019Ch
__land   equ   0001A4h
__lcmps   equ   0001A8h
__lcmpu   equ   0001ACh
__lcmpzero   equ   0001B0h
__ldivs   equ   0001B4h
__ldivu   equ   0001B8h
__ldvrmu   equ   0001BCh
__lldix   equ   0001C0h
__lldiy   equ   0001C4h
__lmuls   equ   0001C8h
__lmulu   equ   0001CCh
__lneg   equ   0001D0h
__lnot   equ   0001D4h
__lor   equ   0001D8h
__lrems   equ   0001DCh
__lremu   equ   0001E0h
__lshl   equ   0001E4h
__lshrs   equ   0001E8h
__lshru   equ   0001ECh
__bshru   equ   000104h
__bshl   equ   000100h
__bldiy   equ   0000FCh
__bstiy   equ   000108h
__bstix   equ   00010Ch
__lstix   equ   0001F0h
__lstiy   equ   0001F4h
__lsub   equ   0001F8h
__lxor   equ   0001FCh
__sand   equ   000200h
__scmp0   equ   000204h
__sdivs   equ   000208h
__sdivu   equ   00020Ch
__seqcase   equ   000210h
__seqcaseD   equ   000214h
__setflag   equ   000218h
__sldix   equ   00021Ch
__sldiy   equ   000220h
__smuls   equ   000224h
__smulu   equ   000228h
__sor   equ   000234h
__srems   equ   000238h
__sremu   equ   00023Ch
__sshl_b   equ   000244h
__sshl   equ   000240h
__sshrs_b   equ   00024Ch
__sshrs   equ   000248h
__sshru_b   equ   000254h
__sshru   equ   000250h
__sstix   equ   000258h
__sstiy   equ   00025Ch
__stoi   equ   000260h
__stoiu   equ   000264h
__sxor   equ   000268h
;00002D0h   ;checks something about field 80C0h in the OS header (value 0101h)
_WriteAByte   equ   00002D4h
_EraseFlash   equ   00002D8h
_EraseFlashPage   equ   00002DCh
_WriteFlash   equ   00002E0h
_WriteAByte2   equ   00002E4h   ;no difference
_WriteAByteA   equ   00002E8h   ;byte is in A, not B
;00002ECh   ;lots of writes/erases involving sectors 3Bh/3Fh
;00002F0h   ;zeroes out 4KB at 0D1887Ch and writes 0D18C7Ch to start of it
_WriteFlashUnsafe   equ   0000334h
_memchr   equ   00009Ch
_memcmp   equ   0000A0h
_memcpy   equ   0000A4h
_memmove   equ   0000A8h
_memset   equ   0000ACh
_memclear   equ   0000B0h
_DoNothing   equ   0000F8h
_setjmp   equ   0000B8h
_longjmp   equ   000098h
_sprintf   equ   0000BCh
_strcat   equ   0000C0h
_strchr   equ   0000C4h
_strcmp   equ   0000C8h
_strcpy   equ   0000CCh
_strcspn   equ   0000D0h
_strlen   equ   0000D4h
_strncat   equ   0000D8h
_strncmp   equ   0000DCh
_strncpy   equ   0000E0h
_strpbrk   equ   0000E4h
_strrchr   equ   0000E8h
_strspn   equ   0000ECh
_strstr   equ   0000F0h
_strtok   equ   0000F4h; Uses static 24-bit variable at 0D0FFFFh
__fppack   equ   00026Ch
FLT_MAX   equ   000294h; NOT A ROUTINE LOL
__fadd   equ   000270h
__fcmp   equ   000274h
__fdiv   equ   000278h
__ftol   equ   00027Ch
__ltof   equ   000284h
__fmul   equ   000288h
__fneg   equ   00028Ch
__fsub   equ   000290h
__ultof   equ   000280h
_fsqrt   equ   000298h
__frbtof   equ   00029Ch
__frftob   equ   0002A0h
__frftoi   equ   0002A8h
__frftos   equ   0002B0h
__frftoub   equ   0002A4h
__frftoui   equ   0002ACh
__frftous   equ   0002B4h
__fritof   equ   0002B8h
__frstof   equ   0002C0h
__frubtof   equ   0002C4h
__fruitof   equ   0002BCh
__frustof   equ   0002C8h
;-------------------------------------------------------------------------------
; System Calls
;-------------------------------------------------------------------------------
_OsSize      equ   020104h ; Not actually a routine, just a pointer to the end of the OS, san signature
_bootOS      equ   020108h
_interruptHandler   equ   02010Ch
_rst10Handler   equ   020110h
_rst18Handler   equ   020114h
_rst20Handler   equ   020118h
_rst28Handler   equ   02011Ch
_rst30Handler   equ   020120h
_DivHLBy10   equ   020140h
_DivHLByA   equ   020144h
_KbdScan   equ   020148h
_GetCSC   equ   02014ch
_coorMon   equ   020150h
_Mon   equ   020154h
_monForceKey   equ   020158h
_SendKPress   equ   02015ch
_JForceCmdNoChar   equ   020160h
_JForceCmd   equ   020164h
_sysErrHandler   equ   020168h
_NewContext   equ   02016ch
_NewContext0   equ   020170h
_PPutAwayPrompt   equ   020174h
_PPutAway   equ   020178h
_PutAway   equ   02017ch
_SizeWind   equ   020180h
_ErrorEP   equ   020184h
_CallMain   equ   020188h
_monErrHand   equ   02018ch
_AppInit   equ   020190h
_initialize   equ   020194h
_Min   equ   020198h
_Max   equ   02019ch
_AbsO1PAbsO2   equ   0201a0h
_Intgr   equ   0201a4h
_Trunc   equ   0201a8h
_InvSub   equ   0201ach
_Times2   equ   0201b0h
_Plus1   equ   0201b4h
_Minus1   equ   0201b8h
_FPSub   equ   0201bch
_FPAdd   equ   0201c0h
_DToR   equ   0201c4h
_RToD   equ   0201c8h
_Cube   equ   0201cch
_TimesPt5   equ   0201d0h
_FPSquare   equ   0201d4h
_FPMult   equ   0201d8h
_LJRnd   equ   0201dch
_InvOP1SC   equ   0201e0h
_InvOP1S   equ   0201e4h
_InvOP2S   equ   0201e8h
_Frac   equ   0201ech
_FPRecip   equ   0201f0h
_FPDiv   equ   0201f4h
_SqRoot   equ   0201f8h
_RndGuard   equ   0201fch
_RnFx   equ   020200h
_Int   equ   020204h
_Round   equ   020208h
_LnX   equ   02020ch
_LogX   equ   020210h
_LJNoRnd   equ   020214h
_EToX   equ   020218h
_TenX   equ   02021ch
_SinCosRad   equ   020220h
_Sin   equ   020224h
_Cos   equ   020228h
_Tan   equ   02022ch
_SinHCosH   equ   020230h
_TanH   equ   020234h
_CosH   equ   020238h
_SinH   equ   02023ch
_ACosRad   equ   020240h
_ATanRad   equ   020244h
_ATan2Rad   equ   020248h
_ASinRad   equ   02024ch
_ACos   equ   020250h
_ATan   equ   020254h
_ASin   equ   020258h
_ATan2   equ   02025ch
_ATanH   equ   020260h
_ASinH   equ   020264h
_ACosH   equ   020268h
_PToR   equ   02026ch
_RToP   equ   020270h
_HLTimes9   equ   020274h
_CkOP1Cplx   equ   020278h
_CkOP1Real   equ   02027ch
_Angle   equ   020280h
_COP1Set0   equ   020284h
_CpOP4OP3   equ   020288h
_Mov9OP2Cp   equ   02028ch
_AbsO1O2Cp   equ   020290h
_CpOP1OP2   equ   020294h
_OP3ToOP4   equ   020298h
_OP1ToOP4   equ   02029ch
_OP2ToOP4   equ   0202a0h
_OP4ToOP2   equ   0202a4h
_OP3ToOP2   equ   0202a8h
_OP1ToOP3   equ   0202ach
_OP5ToOP2   equ   0202b0h
_OP5ToOP6   equ   0202b4h
_OP5ToOP4   equ   0202b8h
_OP1ToOP2   equ   0202bch
_OP6ToOP2   equ   0202c0h
_OP6ToOP1   equ   0202c4h
_OP4ToOP1   equ   0202c8h
_OP5ToOP1   equ   0202cch
_OP3ToOP1   equ   0202d0h
_OP6ToOP5   equ   0202d4h
_OP4ToOP5   equ   0202d8h
_OP3ToOP5   equ   0202dch
_OP2ToOP5   equ   0202e0h
_OP2ToOP6   equ   0202e4h
_OP1ToOP6   equ   0202e8h
_OP1ToOP5   equ   0202ech
_OP2ToOP1   equ   0202f0h
_Mov11B   equ   0202f4h
_Mov10B   equ   0202f8h
_Mov9B   equ   0202fch      ; <--
_Mov9B2   equ   020300h      ; These two jump to the same thing... :)
_Mov8B   equ   020304h
_Mov7B   equ   020308h      ; <--
_Mov7B2   equ   02030Ch      ; These two jump to the same thing... Again. :)
_OP2ToOP3   equ   020310h
_OP4ToOP3   equ   020314h
_OP5ToOP3   equ   020318h
_OP4ToOP6   equ   02031Ch
_Mov9ToOP1   equ   020320h
_Mov9OP1OP2   equ   020324h
_Mov9ToOP2   equ   020328h
_MovFrOP1   equ   02032Ch
_OP4Set1   equ   020330h
_OP3Set1   equ   020334h
_OP2Set8   equ   020338h
_OP2Set5   equ   02033Ch
_OP2SetA   equ   020340h
_OP2Set4   equ   020344h
_OP2Set3   equ   020348h
_OP1Set1   equ   02034Ch
_OP1Set4   equ   020350h
_OP1Set3   equ   020354h
_OP3Set2   equ   020358h
_OP1Set2   equ   02035Ch
_OP2Set2   equ   020360h
_OP2Set1   equ   020364h
_Zero16D   equ   020368h
_OP5Set0   equ   02036Ch
_OP4Set0   equ   020370h
_OP3Set0   equ   020374h
_OP2Set0   equ   020378h
_OP1Set0   equ   02037Ch
_SetNum0   equ   020380h
_ZeroOP1   equ   020384h
_ZeroOP2   equ   020388h
_ZeroOP3   equ   02038Ch
_ZeroOP   equ   020390h
_OP2ExOP6   equ   0203DCh
_OP5ExOP6   equ   0203E0h
_OP1ExOP5   equ   0203E4h
_OP1ExOP6   equ   0203E8h
_OP2ExOP4   equ   0203ECh
_OP2ExOP5   equ   0203F0h
_OP1ExOP3   equ   0203F4h
_OP1ExOP4   equ   0203F8h
_OP1ExOP2   equ   0203FCh
_ExLp   equ   020400h
_CkOP1C0   equ   020404h
_CkOP1FP0   equ   020408h
_CkOP2FP0   equ   02040Ch
_PosNo0Int   equ   020410h
_CkPosInt   equ   020414h
_CkInt   equ   020418h
_CkOdd   equ   02041Ch
_CkOP1M   equ   020420h
_GetCon1   equ   020424h
_GetCon   equ   020428h
_PIDIV2   equ   02042Ch
_PIDIV4   equ   020430h
_TWOPI   equ   020434h
_PICON   equ   020438h
_ExpToHex   equ   02043Ch
_OP1ExpToDec   equ   020440h
_CkOP2Pos   equ   020444h
_CkOP1Pos   equ   020448h
_ClrOP2S   equ   02044Ch
_ClrOP1S   equ   020450h
_FDiv100   equ   020454h
_FDiv10   equ   020458h
_DecO1Exp   equ   02045Ch
_IncO1Exp   equ   020460h
_IncExp   equ   020468h
_CkValidNum   equ   06011Fh
_GetExp   equ   02046Ch
_HTimesL   equ   020470h      ; Kind of useless now; the instruction at this address is literally "mlt hl / ret"
_EOP1NotReal   equ   020474h
_ThetaName   equ   020478h
_RName   equ   02047Ch
_RegEqName   equ   020480h
_RecurNName   equ   020484h
_XName   equ   020488h
_YName   equ   02048Ch
_TName   equ   020490h
_RealName   equ   020494h
_SetEStoFPS   equ   020498h
_ChkTempDirt   equ   02049Ch
_OP1MOP2Exp   equ   0204A0h
_OP1ExpMDE   equ   0204A4h
_ChkErrBreak   equ   0204A8h
_IsA2ByteTok   equ   0204ACh
_GetLastEntry   equ   0204B0h
_GetLastEntryPtr equ   0204B4h
_RegrClrChng   equ   0204B8h
_ResetWinTop   equ   0204BCh
_IsO1NonTLstOrProg   equ   0204C0h
_IsO1NonTempLst   equ   0204C4h
_Is_A_LstOrCLst   equ   0204C8h
_Chk_HL_999   equ   0204CCh
_equ_or_Newequ   equ   0204D0h
_ErrD_OP1NotPos   equ   0204D4h
_ErrD_OP1Not_R   equ   0204D8h
_ErrD_OP1NotPosInt   equ   0204DCh
_ErrD_OP1_LE_0   equ   0204E0h
_ErrD_OP1_0   equ   0204E4h
_FindSym_Get_Size   equ   0204E8h
_Sto_StatVar   equ   0204ECh
_Rcl_StatVar   equ   0204F0h
_CkOP2Real   equ   0204F4h
_Get_X_Indirect   equ   0204F8h
_MemChk   equ   0204FCh      
_CmpPrgNamLen1   equ   020500h
_CmpPrgNamLen   equ   020504h
_FindProgSym   equ   020508h
_ChkFindSym   equ   02050Ch
_FindSym   equ   020510h
_InsertMem   equ   020514h
_InsertMemA   equ   020518h
_EnoughMem   equ   02051Ch               ;---
_CmpMemNeed   equ   020520h
_CreatePVar4   equ   020524h
_CreatePVar3   equ   020528h
_CreateVar3   equ   02052Ch
_CreateCplx   equ   020530h
_CreateReal   equ   020534h
_CreateTRList   equ   020538h
_CreateRList   equ   02053Ch
_CreateTCList   equ   020540h
_CreateCList   equ   020544h
_CreateTRMat   equ   020548h
_CreateRMat   equ   02054Ch
_CreateTStrng   equ   020550h
_CreateStrng   equ   020554h
_Create0equ   equ   020558h
_CreateTequ   equ   02055Ch
_Createequ   equ   020560h
_CreateGDB   equ   020564h
_CreateProg   equ   020568h
_ChkDel   equ   02056Ch
_ChkDelA   equ   020570h
_AdjParser   equ   020574h
_AdjMath   equ   020578h
_AdjM7   equ   02057Ch
_DelMemA   equ   020580h
_Get_Form_Num   equ   020584h
_DelVar   equ   020588h
_DelVarIO   equ   02058Ch
_DelMem   equ   020590h
_DelVar3D   equ   020594h
_DelVar3C   equ   020598h
_DelVar3DC   equ   02059Ch
_SymProgNonTLst   equ   0205A0h
_AdjSymPtrs   equ   0205A4h
_DataSizeA   equ   0205A8h
_DataSize   equ   0205ACh
_PopMCplxO1   equ   0205B0h
_PopMCplx   equ   0205B4h
_MovCplx   equ   0205B8h
_PopOP5   equ   0205BCh
_PopOP3   equ   0205C0h
_PopOP1   equ   0205C4h
_PopRealO6   equ   0205C8h
_PopRealO5   equ   0205CCh
_PopRealO4   equ   0205D0h
_PopRealO3   equ   0205D4h
_PopRealO2   equ   0205D8h
_PopRealO1   equ   0205DCh
_PopReal   equ   0205E0h
_FPopCplx   equ   0205E4h
_FPopReal   equ   0205E8h
_FPopFPS   equ   0205ECh
_DeallocFPS   equ   0205F0h
_DeallocFPS1   equ   0205F4h
_AllocFPS   equ   0205F8h
_AllocFPS1   equ   0205FCh
_PushRealO6   equ   020600h
_PushRealO5   equ   020604h
_PushRealO4   equ   020608h
_PushRealO3   equ   02060Ch
_PushRealO2   equ   020610h
_PushRealO1   equ   020614h
_PushReal   equ   020618h
_PushOP5   equ   02061Ch
_PushOP3   equ   020620h
_PushMCplxO3   equ   020624h
_PushOP1   equ   020628h
_PushMCplxO1   equ   02062Ch
_PushMCplx   equ   020630h
_ExMCplxO1   equ   020634h
_Exch9   equ   020638h
_CpyTo1FPS11   equ   02063Ch
_CpyTo2FPS5   equ   020640h
_CpyTo1FPS5   equ   020644h
_CpyTo2FPS6   equ   020648h
_CpyTo1FPS6   equ   02064Ch
_CpyTo2FPS7   equ   020650h
_CpyTo1FPS7   equ   020654h
_CpyTo1FPS8   equ   020658h
_CpyTo2FPS8   equ   02065Ch
_CpyTo1FPS10   equ   020660h
_CpyTo1FPS9   equ   020664h
_CpyTo2FPS4   equ   020668h
_CpyTo6FPS3   equ   02066Ch
_CpyTo6FPS2   equ   020670h
_CpyTo2FPS3   equ   020674h
_CpyCTo1FPS3   equ   020678h
_CpyTo1FPS3   equ   02067Ch
_CpyFPS3   equ   020680h
_CpyTo1FPS4   equ   020684h
_CpyTo3FPS2   equ   020688h
_CpyTo5FPST   equ   02068Ch
_CpyTo6FPST   equ   020690h
_CpyTo4FPST   equ   020694h
_CpyTo3FPST   equ   020698h
_CpyTo2FPST   equ   02069Ch
_CpyTo1FPST   equ   0206A0h
_CpyFPST   equ   0206A4h
_CpyStack   equ   0206A8h
_CpyTo3FPS1   equ   0206ACh
_CpyTo2FPS1   equ   0206B0h
_CpyTo1FPS1   equ   0206B4h
_CpyFPS1   equ   0206B8h
_CpyTo2FPS2   equ   0206BCh
_CpyTo1FPS2   equ   0206C0h
_CpyFPS2   equ   0206C4h
_CpyO3ToFPST   equ   0206C8h
_CpyO2ToFPST   equ   0206CCh
_CpyO6ToFPST   equ   0206D0h
_CpyO1ToFPST   equ   0206D4h
_CpyToFPST   equ   0206D8h
_CpyToStack   equ   0206DCh
_CpyO3ToFPS1   equ   0206E0h
_CpyO5ToFPS1   equ   0206E4h
_CpyO2ToFPS1   equ   0206E8h
_CpyO1ToFPS1   equ   0206ECh
_CpyToFPS1   equ   0206F0h
_CpyO2ToFPS2   equ   0206F4h
_CpyO3ToFPS2   equ   0206F8h
_CpyO6ToFPS2   equ   0206FCh
_CpyO1ToFPS2   equ   020700h
_CpyToFPS2   equ   020704h
_CpyO5ToFPS3   equ   020708h
_CpyO2ToFPS3   equ   02070Ch
_CpyO1ToFPS3   equ   020710h
_CpyToFPS3   equ   020714h
_CpyO1ToFPS6   equ   020718h
_CpyO1ToFPS7   equ   02071Ch
_CpyO1ToFPS5   equ   020720h
_CpyO2ToFPS4   equ   020724h
_CpyO1ToFPS4   equ   020728h
_ErrNotEnoughMem   equ   02072Ch
_FPSMinus9   equ   020730h
_HLMinus9   equ   020734h
_ErrOverflow   equ   020738h
_ErrDivBy0   equ   02073Ch
_ErrSingularMat   equ   020740h
_ErrDomain   equ   020744h
_ErrIncrement   equ   020748h
_ErrNon_Real   equ   02074Ch
_ErrSyntax   equ   020750h
_ErrDataType   equ   020754h
_ErrArgument   equ   020758h
_ErrDimMismatch   equ   02075Ch
_ErrDimension   equ   020760h
_ErrUndefined   equ   020764h
_ErrMemory   equ   020768h
_ErrInvalid   equ   02076Ch
_ErrBreak   equ   020770h
_ErrStat   equ   020774h
_ErrSignChange   equ   020778h
_ErrIterations   equ   02077Ch
_ErrBadGuess   equ   020780h
_ErrTolTooSmall   equ   020784h
_ErrStatPlot   equ   020788h
_ErrLinkXmit   equ   02078Ch
_JError   equ   020790h
_noErrorEntry   equ   020794h
_pushErrorHandler   equ   020798h
_popErrorHandler   equ   02079Ch
_StrCopy   equ   0207A0h
_StrCatCall   equ   0207A4h
_IsInSet   equ   0207A8h
_GetNameA   equ   0207ACh
_RecName   equ   0207B0h
_PutMap   equ   0207B4h
_PutC   equ   0207B8h
_DispHL   equ   0207BCh
;------------------------------
_NewLine   equ   0207F0h
_MoveDown   equ   0207F4h
_ScrollUp   equ   0207F8h
_ShrinkWindow   equ   0207FCh
_MoveUp   equ   020800h
_ScrollDown   equ   020804h
_ClrLCDFull   equ   020808h
_ClrLCD   equ   02080Ch
_ClrScrnFull   equ   020810h
_ClrScrn   equ   020814h
_ClrTxtShd   equ   020818h
_ClrWindow   equ   02081Ch
_EraseEOL   equ   020820h
_EraseEOW   equ   020824h
_HomeUp   equ   020828h
_GetCurLoc   equ   02082Ch
_VPutMap   equ   020830h
_VPutS   equ   020834h
_VPutSN   equ   020838h
_VPutSNG   equ   02083Ch
_VPutSNT   equ   020840h
_RunIndicOn   equ   020844h
_RunIndicOff   equ   020848h
;------------------------------
_ToFrac   equ   02096ch
_SeqSet   equ   020970h
_SeqSolve   equ   020974h
_Cmp_Num_Init   equ   020978h
_BinOPExec   equ   02097ch
_ExMean1   equ   020980h
_Set2MVLPtrs   equ   020984h
_SetMat1   equ   020988h
_CreateTList   equ   02098ch
_UnOPExec   equ   020990h
_ThreeExec   equ   020994h
_RestoreErrNo   equ   020998h
_FourExec   equ   02099ch
_FiveExec   equ   0209a0h
_CpyTo2ES1   equ   0209a4h
_CpyTo6ES1   equ   0209a8h
_CpyTo1ES1   equ   0209ach
_CpyTo3ES1   equ   0209b0h
_CpyTo3ES2   equ   0209b4h
_CpyTo2ES2   equ   0209b8h
_CpyTo1ES2   equ   0209bch
_CpyTo2ES3   equ   0209c0h
_CpyTo1ES3   equ   0209c4h
_CpyTo3ES4   equ   0209c8h
_CpyTo6ES3   equ   0209cch
_CpyTo2ES4   equ   0209d0h
_CpyTo1ES4   equ   0209d4h
_CpyTo2ES5   equ   0209d8h
_CpyTo1ES5   equ   0209dch
_CpyTo4EST   equ   0209e0h
_CpyTo2EST   equ   0209e4h
_CpyTo1EST   equ   0209e8h
_CpyTo2ES6   equ   0209ech
_CpyTo1ES6   equ   0209f0h
_CpyTo2ES7   equ   0209f4h
_CpyTo1ES7   equ   0209f8h
_CpyTo2ES8   equ   0209fch
_CpyTo1ES8   equ   020a00h
_CpyTo1ES9   equ   020a04h
_CpyTo2ES9   equ   020a08h
_CpyTo2ES10   equ   020a0ch
_CpyTo1ES10   equ   020a10h
_CpyTo2ES11   equ   020a14h
_CpyTo1ES11   equ   020a18h
_CpyTo2ES12   equ   020a1ch
_CpyTo1ES12   equ   020a20h
_CpyTo2ES13   equ   020a24h
_CpyTo1ES13   equ   020a28h
_CpyTo1ES14   equ   020a2ch
_CpyTo1ES16   equ   020a30h
_CpyTo1ES17   equ   020a34h
_CpyTo1ES18   equ   020a38h
_CpyTo1ES15   equ   020a3ch
_CpyTo2ES15   equ   020a40h
_CpyO1ToEST   equ   020a44h
_CpyO1ToES1   equ   020a48h
_CpyO6ToES1   equ   020a4ch
_CpyO6ToES3   equ   020a50h
_CpyO1ToES2   equ   020a54h
_CpyO2ToES2   equ   020a58h
_CpyO1ToES3   equ   020a5ch
_CpyO1ToES4   equ   020a60h
_CpyO1ToES5   equ   020a64h
_CpyO1ToES6   equ   020a68h
_CpyO1ToES7   equ   020a6ch
_CpyO2ToES4   equ   020a70h
_CpyO2ToES5   equ   020a74h
_CpyO2ToES6   equ   020a78h
_CpyO2ToES7   equ   020a7ch
_CpyO2ToES8   equ   020a80h
_CpyO2ToES9   equ   020a84h
_CpyO1ToES8   equ   020a88h
_CpyO1ToES9   equ   020a8ch
_CpyO1ToES10   equ   020a90h
_CpyO1ToES11   equ   020a94h
_CpyO1ToES12   equ   020a98h
_CpyO1ToES13   equ   020a9ch
_CpyO1ToES14   equ   020aa0h
_EvalF3A   equ   020aa4h
_GetK   equ   020aa8h
_SetTitle   equ   020aach
_DispVarVal   equ   020ab0h
_RecallEd   equ   020ab4h
_SetupBuffer   equ   020ab8h
_CreateNumEditBuf   equ   020abch
_CallCommon   equ   020ac0h
_CommonKeys   equ   020ac4h
_Leftmore   equ   020ac8h
_fDel   equ   020acch
_fClear   equ   020ad0h
_fInsDisp   equ   020ad4h
_fInsDisp02   equ   020ad8h
_SetIndicator   equ   020adch
_CloseEditBufNoR   equ   020ae0h
_ReleaseBuffer   equ   020ae4h
_VarNameToOP1HL   equ   020ae8h
_NameToOP1   equ   020aech
_numPPutAway   equ   020af0h
_numRedisp   equ   020af4h
_numError02   equ   020af8h
_Load_SFont   equ   020afch
_SFont_Len   equ   020b00h
_InitNumVec   equ   020b04h
_SetXXOP1   equ   020b08h
_SetXXOP2   equ   020b0ch
_SetXXXXOP2   equ   020b10h
;------------------------------
_StoOther   equ   020f4ch
_RclAns   equ   020f50h
_RclY   equ   020f54h
_RclN   equ   020f58h
_RclX   equ   020f5ch
_RclVarSym   equ   020f60h
_RclSysTok   equ   020f64h
_StMatEl   equ   020f68h
_StLstVecEl   equ   020f6ch
_ConvOP1   equ   020f70h
;------------------------------
;002114Ch   ;I think this forces the interrupt to scan the keypad (subroutine of _getKey)
_createAppVar   equ   021330h
_createProtProg   equ   021334h
_lockFlash   equ   0213ACh
_DelVarArc   equ   021434h
_Arc_Unarc   equ   021448h
_DispHL24   equ   021EE0h
_nmiHandler   equ   0220A8h
;-------------------------------------------------------------------------------
; RAM Locations / Address Space
;-------------------------------------------------------------------------------
flags   equ   0D00080h
curRow   equ   0D00595h
curCol   equ   0D00596h
OP1   equ   0D005F8h
OP2   equ   0D00603h
OP3   equ   0D0060Eh
OP4   equ   0D00619h
OP5   equ   0D00624h
OP6   equ   0D0062Fh
penCol   equ   0D008D2h
penRow   equ   0D008D5h
userMem   equ   0D1A881h

vRam   equ   0D40000h
;-------------------------------------------------------------------------------
; Scan Codes
;-------------------------------------------------------------------------------
skDown   equ   01h
skLeft   equ   02h
skRight   equ   03h
skUp   equ   04h
skEnter   equ   09h
skAdd   equ   0Ah
skSub   equ   0Bh
skMul   equ   0Ch
skDiv   equ   0Dh
skPower   equ   0Eh
skClear   equ   0Fh
skChs   equ   11h
sk3   equ   12h
sk6   equ   13h
sk9   equ   14h
skRParen   equ   15h
skTan   equ   16h
skVars   equ   17h
skDecPnt   equ   19h
sk2   equ   1Ah
sk5   equ   1Bh
sk8   equ   1Ch
skLParen   equ   1Dh
skCos   equ   1Eh
skPrgm   equ   1Fh
skStat   equ   20h
sk0   equ   21h
sk1   equ   22h
sk4   equ   23h
sk7   equ   24h
skComma   equ   25h
skSin   equ   26h
skMatrix   equ   27h
skGraphvar   equ   28h
skStore   equ   2Ah
skLn   equ   2Bh
skLog   equ   2Ch
skSquare   equ   2Dh
skRecip   equ   2Eh
skMath   equ   2Fh
skAlpha   equ   30h
skGraph   equ   31h
skTrace   equ   32h
skZoom   equ   33h
skWindow   equ   34h
skYequ   equ   35h
sk2nd   equ   36h
skMode   equ   37h
skDel   equ   38h
skDownLeft   equ   252
skDownRight   equ   250
skUpLeft   equ   245
skUpRight   equ   243
;-------------------------------------------------------------------------------
; Tokens
;-------------------------------------------------------------------------------
EOSSTART   equ   0

DCONV equ 01h   ; Display conversions come immediately before 'TSTORE'

tToDMS   equ   DCONV   ; 01h
tToDEC   equ   DCONV+1 ; 02h
tToAbc   equ   DCONV+2 ; 03h> A b/c
tStore   equ   DCONV+3 ; 04h Lstore      01
tBoxPlot equ   05h
BRACKS   equ   06h

tLBrack   equ   BRACKS   ; 06h '['
tRBrack   equ   BRACKS+1   ; 07h ']'
tLBrace   equ   BRACKS+2   ; 08h '{'
tRBrace   equ   BRACKS+3   ; 09h '}'

tPOST1   equ   BRACKS+4

tFromRad   equ   tPOST1   ; 0Ah Lradian
tFromDeg   equ   tPOST1+1 ; 0Bh Ldegree
tRecip   equ   tPOST1+2 ; 0Ch Linverse
tSqr   equ   tPOST1+3 ; 0Dh Lsquare
tTrnspos   equ   tPOST1+4 ; 0Eh Ltranspose
tCube   equ   tPOST1+5 ; 0Fh '^3'
tLParen   equ   10h   ; 10h '('
tRParen   equ   11h   ; 11h ')'

IMUN   equ   12h
tRound   equ   IMUN   ; 12h 'round'
tPxTst   equ   IMUN+1   ; 13h 'PXL-TEST'
tAug   equ   IMUN+2   ; 14h 'aug'
tRowSwap   equ   IMUN+3   ; 15h 'rSwap'
tRowPlus   equ   IMUN+4   ; 16h 'rAdd'
tmRow   equ   IMUN+5   ; 17h 'multR'
tmRowPlus   equ   IMUN+6   ; 18h 'mRAdd'
tMax   equ   IMUN+7   ; 19h 'max'
tMin   equ   IMUN+8   ; 1Ah 'min'
tRToPr   equ   IMUN+9   ; 1Bh 'R>Pr
tRToPo   equ   IMUN+10 ; 1Ch 'R>Po
tPToRx   equ   IMUN+11 ; 1Dh 'P>Rx
tPToRy   equ   IMUN+12 ; 1Eh 'P>Ry
tMedian   equ   IMUN+13 ; 1Fh 'MEDIAN
tRandM   equ   IMUN+14 ; 20h 'randM'
tMean   equ   IMUN+15 ; 21h
tRoot   equ   IMUN+16 ; 22h 'ROOT'
tSeries   equ   IMUN+17 ; 23h 'seq'
tFnInt   equ   IMUN+18 ; 24h 'fnInt'
tNDeriv   equ   IMUN+19 ; 25h 'fnIr'
tEvalF   equ   IMUN+20 ; 26h
tFmin   equ   IMUN+21 ; 27h
tFmax   equ   IMUN+22 ; 28h

tEOSEL   equ   IMUN+23
tSpace   equ   tEOSEL   ; 29h ' '
tString   equ   tEOSEL+1 ; 2Ah'"'
tComma   equ   tEOSEL+2 ; 2Bh','
tii   equ   2Ch   ; i
;-------------------------------------------------------------------------------
; Postfix Functions
;-------------------------------------------------------------------------------
tPost   equ   2Dh

tFact   equ   tPost   ; 2Dh '!'
tCubicR   equ   2Eh
tQuartR   equ   2Fh
;-------------------------------------------------------------------------------
; Number Tokens
;-------------------------------------------------------------------------------
NUMS   equ   30h
t0   equ   NUMS   ; 30h
t1   equ   NUMS+1; 31h
t2   equ   NUMS+2; 32h
t3   equ   NUMS+3; 33h
t4   equ   NUMS+4; 34h
t5   equ   NUMS+5; 35h
t6   equ   NUMS+6; 36h
t7   equ   NUMS+7; 37h
t8   equ   NUMS+8; 38h
t9   equ   NUMS+9; 39h
tDecPt   equ   NUMS+10 ; 3Ah
tee   equ   NUMS+11 ; 3Bh
;-------------------------------------------------------------------------------
; BINARY OP
;-------------------------------------------------------------------------------
tOr   equ   3Ch   ; 3Ch'_or_'
tXor   equ   3Dh   ; 3Dh
tColon   equ   3Eh   ; 3Eh ':'
tEnter   equ   3Fh   ; 3FhLenter
tAnd   equ   40h   ; 40h'_and_'  
;-------------------------------------------------------------------------------
;   LETTER TOKENS
;-------------------------------------------------------------------------------
LET   equ   41h
tA   equ   LET   ; 41h
tB   equ   LET+1   ; 42h
tC   equ   LET+2   ; 43h
tD   equ   LET+3   ; 44h
tE   equ   LET+4   ; 45h
tF   equ   LET+5   ; 46h
tG   equ   LET+6   ; 47h
tH   equ   LET+7   ; 48h
tI   equ   LET+8   ; 49h
tJ   equ   LET+9   ; 4Ah
tK   equ   LET+10   ; 4Bh
tL   equ   LET+11   ; 4Ch
tM   equ   LET+12   ; 4Dh
tN   equ   LET+13   ; 4Eh
tO   equ   LET+14   ; 4Fh
tP   equ   LET+15   ; 50h
tQ   equ   LET+16   ; 51h
tR   equ   LET+17   ; 52h
tS   equ   LET+18   ; 53h
tT   equ   LET+19   ; 54h
tU   equ   LET+20   ; 55h
tV   equ   LET+21   ; 56h
tW   equ   LET+22   ; 57h
tX   equ   LET+23   ; 58h
tY   equ   LET+24   ; 59h
tZ   equ   LET+25   ; 5Ah
tTheta   equ   LET+26   ; 5Bh
;-------------------------------------------------------------------------------
; These VAR tokens are 1st of a double token
;-------------------------------------------------------------------------------
vToks    equ   LET+27;
tVarMat   equ   vToks   ; 5Ch - MATRIX token, 2nd token needed for name
tVarLst   equ   vToks+1 ; 5Dh - LIST token, 2nd token needed for name
tVarequ   equ   vToks+2 ; 5Eh - EQUATION token, 2nd token needed for name
tProg   equ   vToks+3 ; 5Fh
tVarPict   equ   vToks+4 ; 60h - PICT token, 2nd token needed for name
tVarGDB   equ   vToks+5 ; 61h - GDB token, 2nd token needed for name
tVarOut   equ   vToks+6 ; 62h
tVarSys   equ   vToks+7 ; 63h
;-------------------------------------------------------------------------------
; Mode Setting Commands
;-------------------------------------------------------------------------------
MODESA   equ   vToks+8    ; 64h
tRad   equ   MODESA      ; 64h 'Radian'
tDeg   equ   MODESA+1   ; 65h 'Degree'
tNormF   equ   MODESA+2   ; 66h 'Normal'
tSci   equ   MODESA+3   ; 67h 'Sci'
tEng   equ   MODESA+4   ; 68h 'Eng'
tFloat   equ   MODESA+5   ; 69h 'Float'
CMPS   equ   6Ah
tEQ   equ   CMPS      ; 6Ah '=='
tLT   equ   CMPS+1      ; 6Bh '<'
tGT   equ   CMPS+2      ; 6Ch '>'
tLE   equ   CMPS+3      ; 6Dh LLE
tGE   equ   CMPS+4      ; 6Eh LGE
tNE   equ   CMPS+5      ; 6Fh LNE
;-------------------------------------------------------------------------------
; BINARY OP
;-------------------------------------------------------------------------------
tAdd   equ   70h   ; 70h '+'
tSub   equ   71h   ; 71h '-'
tAns   equ   72h   ; 72h
;-------------------------------------------------------------------------------
; Mode Setting Commands
;-------------------------------------------------------------------------------
MODES   equ   73h

tFix   equ   MODES   ; 73h 'Fix_'
tSplitOn   equ   MODES+1 ; 74h
tFullScreen    equ   MODES+2 ; 75h
tStndrd   equ   MODES+3 ; 76h 'Func'
tParam   equ   MODES+4 ; 77h 'Param'
tPolar   equ   MODES+5 ; 78h 'Pol'
tSeqG   equ   MODES+6 ; 79h
tAFillOn   equ   MODES+7 ; 7Ah 'AUTO FILL ON
tAFillOff   equ   MODES+8 ; 7Bh
tACalcOn   equ   MODES+9 ; 7Ch
tACalcOff   equ   MODES+10; 7Dh 'AutoFill OFF
;-------------------------------------------------------------------------------
; Graph Format -- Tokens are 2 bytes
;-------------------------------------------------------------------------------
tGFormat   equ   MODES+11; 7Eh

tBoxIcon   equ   7Fh
tCrossIcon   equ   80h
tDotIcon   equ   81h
;-------------------------------------------------------------------------------
; Binary OP (Continuted)
;-------------------------------------------------------------------------------
tMul   equ   82h   ; 82h'*'
tDiv   equ   83h   ; 83h'/'
;-------------------------------------------------------------------------------
; Graph Commands
;-------------------------------------------------------------------------------
GRCMDS   equ   84h

tTrace   equ   GRCMDS+0   ; 84h 'Trace'
tClDrw   equ   GRCMDS+1   ; 85h 'ClDrw'
tZoomStd   equ   GRCMDS+2   ; 86h 'ZStd'
tZoomtrg   equ   GRCMDS+3   ; 87h 'Ztrg'
tZoomBox   equ   GRCMDS+4   ; 88h 'ZBOX'
tZoomIn   equ   GRCMDS+5   ; 89h 'ZIn'
tZoomOut   equ   GRCMDS+6   ; 8Ah 'ZOut'
tZoomSqr   equ   GRCMDS+7   ; 8Bh 'ZSqr'
tZoomInt   equ   GRCMDS+8   ; 8Ch 'ZInt'
tZoomPrev   equ   GRCMDS+9   ; 8Dh 'ZPrev'
tZoomDec   equ   GRCMDS+10   ; 8Eh 'ZDecm'
tZoomStat   equ   GRCMDS+11   ; 8Fh 'ZStat
tUsrZm   equ   GRCMDS+12   ; 90h 'ZRcl'
tPrtScrn   equ   GRCMDS+13   ; 91h 'PrtScrn'
tZoomSto   equ   GRCMDS+14   ; 92hZOOM STORE
tText   equ   GRCMDS+15   ; 93h
;-------------------------------------------------------------------------------
; Binary OP (Combination & Permutation)
;-------------------------------------------------------------------------------
tnPr   equ   GRCMDS+16 ; 94h '_nPr_'
tnCr   equ   GRCMDS+17 ; 95h '_nCr_'
;-------------------------------------------------------------------------------
; Graph Commands (Continuted)
;-------------------------------------------------------------------------------
tYOn   equ   GRCMDS+18 ; 96h 'FnOn_'
tYOff   equ   GRCMDS+19 ; 97h 'FnOff_'
tStPic   equ   GRCMDS+20 ; 98h 'StPic_'
tRcPic   equ   GRCMDS+21 ; 99h 'RcPic_'
tStoDB   equ   GRCMDS+22 ; 9Ah 'StGDB_'
tRclDB   equ   GRCMDS+23 ; 9Bh 'RcGDB_'
tLine   equ   GRCMDS+24 ; 9Ch 'Line'
tVert   equ   GRCMDS+25 ; 9Dh 'Vert_'
tPtOn   equ   GRCMDS+26 ; 9Eh 'PtOn'
tPtOff   equ   GRCMDS+27 ; 9Fh 'PtOff'
;-------------------------------------------------------------------------------
; Token A0 cannot be an eos function
; Since lOW MULT=A0 already
;-------------------------------------------------------------------------------
tPtChg   equ   GRCMDS+28 ; A0h 'PtChg'
tPXOn   equ   GRCMDS+29 ; A1h
tPXOff   equ   GRCMDS+30 ; A2h
tPXChg   equ   GRCMDS+31 ; A3h
tShade   equ   GRCMDS+32 ; A4h 'Shade'
tCircl   equ   GRCMDS+33 ; A5h 'Circl'
tHorz   equ   GRCMDS+34 ; A6h 'HORIZONTAL'
tTanLn   equ   GRCMDS+35 ; A7h 'TanLn'
tDrInv   equ   GRCMDS+36 ; A8h 'DrInv_'
tDrawF   equ   GRCMDS+37 ; A9h 'DrawF_'

tVarStrng   equ   0AAh
;-------------------------------------------------------------------------------
;   Functions with No Arguments
;-------------------------------------------------------------------------------            
NOARG equ 0ABh

tRand   equ   NOARG      ; ABh 'rand'
tPi   equ   NOARG+1      ; AChLpi
tGetKey   equ   NOARG+2      ; ADh 'getKy'
tAPost   equ   tGetKey+1   ; APOSTROPHY
tQuest   equ   tAPost+1   ; QUESTION MARK
UNARY   equ   tQuest+1   ; B0h
tChs   equ   UNARY      ; B0h
tInt   equ   UNARY+1    ; B1h
tAbs   equ   UNARY+2    ; B2h
tDet   equ   UNARY+3    ; B3h
tIdent   equ   UNARY+4    ; B4h
tDim   equ   UNARY+5      ; B5h
tSum   equ   UNARY+6    ; B6h
tProd   equ   UNARY+7    ; B7h
tNot   equ   UNARY+8    ; B8h
tIPart   equ   UNARY+9    ; B9h
tFPart   equ   UNARY+10   ; BAh
;-------------------------------------------------------------------------------
; 2 BYTE TOKENS (Continued)
;-------------------------------------------------------------------------------
t2ByteTok   equ   0BBh   ;

UNARYLR equ UNARY+12
tSqrt   equ   UNARYLR ; BCh
tCubRt   equ   UNARYLR+1 ; BDh
tLn   equ   UNARYLR+2 ; BEh
tExp   equ   UNARYLR+3 ; BFh
tLog   equ   UNARYLR+4 ; C0h
tALog   equ   UNARYLR+5 ; C1h
tSin   equ   UNARYLR+6 ; C2h
tASin   equ   UNARYLR+7 ; C3h
tCos   equ   UNARYLR+8 ; C4h
tACos   equ   UNARYLR+9 ; C5h
tTan   equ   UNARYLR+10; C6h
tATan   equ   UNARYLR+11; C7h
tSinH   equ   UNARYLR+12; C8h
tASinH   equ   UNARYLR+13; C9h
tCosH   equ   UNARYLR+14; CAh
tACosH   equ   UNARYLR+15; CBh
tTanH   equ   UNARYLR+16; CCh
tATanH   equ   UNARYLR+17; CDh
;-------------------------------------------------------------------------------
; Some Programming Commands
;-------------------------------------------------------------------------
PROGTOK equ UNARYLR+18

tIf   equ   PROGTOK      ; CEh
tThen   equ   PROGTOK+1   ; CFh
tElse   equ   PROGTOK+2   ; D0h
tWhile   equ   PROGTOK+3   ; D1h
tRepeat   equ   PROGTOK+4   ; D2h
tFor   equ   PROGTOK+5   ; D3h
tEnd   equ   PROGTOK+6   ; D4h
tReturn   equ   PROGTOK+7   ; D5h
tLbl   equ   PROGTOK+8   ; D6h 'Lbl_'
tGoto   equ   PROGTOK+9   ; D7h 'Goto_'
tPause   equ   PROGTOK+10   ; D8h 'Pause_'
tStop   equ   PROGTOK+11   ; D9h 'Stop'
tISG   equ   PROGTOK+12   ; DAh 'IS>'
tDSL   equ   PROGTOK+13   ; DBh 'DS<'
tInput   equ   PROGTOK+14   ; DCh 'Input_'
tPrompt   equ   PROGTOK+15   ; DDh 'Prompt_'
tDisp   equ   PROGTOK+16   ; DEh 'Disp_'
tDispG   equ   PROGTOK+17   ; DFh 'DispG'
tOutput   equ   PROGTOK+18   ; E0h'Outpt'
tClLCD   equ   PROGTOK+19   ; E1h'ClLCD'
tConst   equ   PROGTOK+20   ; E2h'Fill'
tSortA   equ   PROGTOK+21   ; E3h'sortA_'
tSortD   equ   PROGTOK+22   ; E4h'sortD_'
tDispTab   equ   PROGTOK+23   ; E5h'Disp Table
tMenu   equ   PROGTOK+24   ; E6h'Menu'
tSendMBL   equ   PROGTOK+25   ; E7h'SEND'
tGetMBL   equ   PROGTOK+26   ; E8h'GET'
;-------------------------------------------------------------------------------
; Stat Plot Commands
;-------------------------------------------------------------------------------                  
statPCmd   equ   PROGTOK+27
tPlotOn   equ   statPCmd; E9h ' PLOTSON'
tPlotOff   equ   statPCmd+1 ; EAh ' PLOTSOFF
tListName   equ   0EBh   ; LIST DESIGNATOR
tPlot1   equ   0ECh
tPlot2   equ   0EDh
tPlot3   equ   0EEh
tUnused01   equ   0EFh   ;   available?
tPower   equ   0F0h   ;   '^'
tXRoot   equ   0F1h   ;   LsupX,Lroot

STATCMD   equ   0F2h
tOneVar   equ   STATCMD ; F2h'OneVar_'
tTwoVar   equ   STATCMD+1 ; F3h
tLR   equ   STATCMD+2 ; F4h'LinR(A+BX
tLRExp   equ   STATCMD+3 ; F5h'ExpR_'
tLRLn   equ   STATCMD+4 ; F6h'LnR_'
tLRPwr   equ   STATCMD+5 ; F7h'PwrR_'
tMedMed   equ   STATCMD+6 ; F8h
tQuad   equ   STATCMD+7 ; F9h
tClrLst   equ   STATCMD+8 ; FAh'CLEAR LIST
tClrTbl   equ   STATCMD+9 ; FBhCLEAR TABLE
tHist   equ   STATCMD+10; FCh'Hist_'
txyLine   equ   STATCMD+11; FDh'xyline_'
tScatter   equ   STATCMD+12; FEh'Scatter_'
tLR1   equ   STATCMD+13; FFh'LINR(AX+B
;-------------------------------------------------------------------------------
; 2nd half of GRAPH FORMAT Tokens
;-------------------------------------------------------------------------------
GFMT   equ   0   ;Format settings commands

tSeq   equ   GFMT   ; 'SeqG'
tSimulG   equ   GFMT+1; 'SimulG'
tPolarG   equ   GFMT+2; 'PolarGC'
tRectG   equ   GFMT+3; 'RectGC'
tCoordOn   equ   GFMT+4; 'CoordOn'
tCoordOff   equ   GFMT+5; 'CoordOff'
tDrawLine   equ   GFMT+6; 'DrawLine'
tDrawDot   equ   GFMT+7; 'DrawDot'
tAxisOn   equ   GFMT+8; 'AxesOn'
tAxisOff   equ   GFMT+9; 'AxesOff'
tGridOn   equ   GFMT+10 ; 'GridOn'
tGridOff   equ   GFMT+11 ; 'GridOff'
tLblOn   equ   GFMT+12 ; 'LabelOn'
tLblOff   equ   GFMT+13 ; 'LabelOff'
tWebOn   equ   GFMT+14 ; 'WebOn'
tWebOff   equ   GFMT+15 ; 'WebOFF'
tuv   equ   GFMT+16 ; U vs V
tvw   equ   GFMT+17 ; V vs W
tuw   equ   GFMT+18 ; U vs W
;-------------------------------------------------------------------------------
; 2nd half of User MATRIX Tokens
;-------------------------------------------------------------------------------
tMatA   equ   00h   ; MAT A
tMatB   equ   01h   ; MAT B
tMatC   equ   02h   ; MAT C
tMatD   equ   03h   ; MAT D
tMatE   equ   04h   ; MAT E
tMatF   equ   05h   ; MAT F
tMatG   equ   06h   ; MAT G
tMatH   equ   07h   ; MAT H
tMatI   equ   08h   ; MAT I
tMatJ   equ   09h   ; MAT J
;-------------------------------------------------------------------------------
; 2nd half of User LIST Tokens
;-------------------------------------------------------------------------------
tL1   equ   00h   ; LIST 1
tL2   equ   01h   ; LIST 2
tL3   equ   02h   ; LIST 3
tL4   equ   03h   ; LIST 4
tL5   equ   04h   ; LIST 5
tL6   equ   05h   ; LIST 6
;-------------------------------------------------------------------------------
; 2nd half of User equATION Tokens
; "Y" equATIONS HAVE BIT 4 SET
;-------------------------------------------------------------------------------
tY1   equ   10h   ; Y1
tY2   equ   11h   ; Y2
tY3   equ   12h   ; Y3
tY4   equ   13h   ; Y4
tY5   equ   14h   ; Y5
tY6   equ   15h   ; Y6
tY7   equ   16h   ; Y7
tY8   equ   17h   ; Y8
tY9   equ   18h   ; Y9
tY0   equ   19h   ; Y0

; PARAM equATIONS have bit 5 set
tX1T   equ   20h   ; X1t
tY1T   equ   21h   ; Y1t
tX2T   equ   22h   ; X2t
tY2T   equ   23h   ; Y2t
tX3T   equ   24h   ; X3t
tY3T   equ   25h   ; Y3t
tX4T   equ   26h   ; X4t
tY4T   equ   27h   ; Y4t
tX5T   equ   28h   ; X5t
tY5T   equ   29h   ; Y5t
tX6T   equ   2Ah   ; X6t
tY6T   equ   2Bh   ; Y6t

; POLAR equATIONS have bit 6 set
tR1   equ   40h   ; R1
tR2   equ   41h   ; R2
tR3   equ   42h   ; R3
tR4   equ   43h   ; R4
tR5   equ   44h   ; R5
tR6   equ   45h   ; R6

; RECURSION equATIONS have bit 7 set
tun   equ   80h   ; Un
tvn   equ   81h   ; Vn
twn   equ   82h   ; Wn
;-------------------------------------------------------------------------------
; 2nd half of User PICTURE Tokens
;-------------------------------------------------------------------------------
tPic1   equ   00h   ; PIC1
tPic2   equ   01h   ; PIC2
tPic3   equ   02h   ; PIC3
tPic4   equ   03h   ; PIC4
tPic5   equ   04h   ; PIC5
tPic6   equ   05h   ; PIC6
tPic7   equ   06h   ; PIC7
tPic8   equ   07h   ; PIC8
tPic9   equ   08h   ; PIC9
tPic0   equ   09h   ; PIC0
;-------------------------------------------------------------------------------
; 2nd half of User GRAPH DATABASE Tokens
;-------------------------------------------------------------------------------
tGDB1   equ   00h   ; GDB1
tGDB2   equ   01h   ; GDB2
tGDB3   equ   02h   ; GDB3
tGDB4   equ   03h   ; GDB4
tGDB5   equ   04h   ; GDB5
tGDB6   equ   05h   ; GDB6
tGDB7   equ   06h   ; GDB7
tGDB8   equ   07h   ; GDB8
tGDB9   equ   08h   ; GDB9
tGDB0   equ   09h   ; GDB0
;-------------------------------------------------------------------------------
; 2nd half of User STRING VARS Tokens
;-------------------------------------------------------------------------------            
tStr1   equ   00h
tStr2   equ   01h
tStr3   equ   02h
tStr4   equ   03h
tStr5   equ   04h
tStr6   equ   05h
tStr7   equ   06h
tStr8   equ   07h
tStr9   equ   08h
tStr0   equ   09h
;-------------------------------------------------------------------------------
; 2nd half of SYSTEM OUTPUT ONLY VARIABLES        
;-------------------------------------------------------------------------------
;OPEN   equ   00h
tRegEq   equ   01h   ; REGRESSION equATION

tStatN   equ   02h   ; STATISTICS N
tXMean   equ   03h   ; X MEAN
tSumX   equ   04h   ; SUM(X)
tSumXSqr   equ   05h   ; SUM(X^2)
tStdX   equ   06h   ; STANDARD DEV X
tStdPX   equ   07h   ; STANDARD DEV POP X
tMinX   equ   08h   ; Min X VALUE
tMaxX   equ   09h   ; Max X VALUE
tMinY   equ   0Ah   ; Min Y VALUE
tMaxY   equ   0Bh   ; Max Y VALUE
tYmean   equ   0Ch   ; Y MEAN
tSumY   equ   0Dh   ; SUM(Y)
tSumYSqr   equ   0Eh   ; SUM(Y^2)
tStdY   equ   0Fh   ; STANDARD DEV Y
tStdPY   equ   10h   ; STANDARD DEV POP Y
tSumXY   equ   11h   ; SUM(XY)
tCorr   equ   12h   ; CORRELATION
tMedX   equ   13h   ; MED(X)
tQ1   equ   14h   ; 1ST QUADRANT OF X
tQ3   equ   15h   ; 3RD QUADRANT OF X
tQuadA   equ   16h   ; 1ST TERM OF QUAD POLY REG/ Y-INT
tQuadB   equ   17h   ; 2ND TERM OF QUAD POLY REG/ SLOPE
tQuadC   equ   18h   ; 3RD TERM OF QUAD POLY REG
tCubeD   equ   19h   ; 4TH TERM OF CUBIC POLY REG
tQuartE   equ   1Ah   ; 5TH TERM OF QUART POLY REG
tMedX1   equ   1Bh   ; x1 FOR MED-MED
tMedX2   equ   1Ch   ; x2 FOR MED-MED
tMedX3   equ   1Dh   ; x3 FOR MED-MED
tMedY1   equ   1Eh   ; y1 FOR MED-MED
tMedY2   equ   1Fh   ; y2 FOR MED-MED
tMedY3   equ   20h   ; y3 FOR MED-MED
tRecurn   equ   21h   ; RECURSION N
tStatP   equ   22h
tStatZ   equ   23h
tStatT   equ   24h
tStatChi   equ   25h
tStatF   equ   26h
tStatDF   equ   27h
tStatPhat   equ   28h
tStatPhat1   equ   29h
tStatPhat2   equ   2Ah
tStatMeanX1 equ   2Bh
tStatStdX1   equ   2Ch
tStatN1   equ   2Dh
tStatMeanX2 equ   2Eh
tStatStdX2   equ   2Fh
tStatN2   equ   30h
tStatStdXP   equ   31h
tStatLower   equ   32h
tStatUpper   equ   33h
tStat_s   equ   34h
tLRSqr   equ   35h   ; r^2
tBRSqr   equ   36h   ; R^2
;-------------------------------------------------------------------------------
; These next tokens are only used to access the data
; They are display only and the user cannot access them at all
;-------------------------------------------------------------------------------
tF_DF   equ 37h   ; ANOFAV FACTOR DF
tF_SS   equ 38h   ; ANOFAV FACTOR SS
tF_MS   equ 39h   ; ANOFAV FACTOR MS
tE_DF   equ 3Ah   ; ANOFAV ERROR DF
tE_SS   equ 3Bh   ; ANOFAV ERROR SS
tE_MS   equ 3Ch   ; ANOFAV ERROR MS
;-------------------------------------------------------------------------------
;   2nd half of SYSTEM INPUT/OUTPUT VARIABLES
;   SYSTEM VARIABLES
;-------------------------------------------------------------------------------
tuXscl   equ   0
tuYscl   equ   1
tXscl   equ   2
tYscl   equ   3
tRecuru0 equ   4   ; U 1ST INITIAL COND
tRecurv0 equ   5   ; V 1ST INITIAL COND
tun1   equ   6   ; U(N-1); NOT USED
tvn1   equ   7   ; V(N-1); NOT USED
tuRecuru0   equ   8   ;
tuRecurv0   equ   9   ;
tXmin   equ   0Ah
tXmax   equ   0Bh
tYmin   equ   0Ch
tYmax   equ   0Dh
tTmin   equ   0Eh
tTmax   equ   0Fh
tThetaMin   equ   10h
tThetaMax   equ   11h
tuXmin   equ   12h
tuXmax   equ   13h
tuYmin   equ   14h
tuYmax   equ   15h
tuThetMin   equ   16h
tuThetMax   equ   17h
tuTmin   equ   18h
tuTmax   equ   19h
tTblMin   equ   1Ah
tPlotStart equ   1Bh
tuPlotStart   equ   1Ch
tnMax   equ   1Dh
tunMax   equ   1Eh
tnMin   equ   1Fh
tunMin   equ   20h
tTblStep   equ   21h
tTStep   equ   22h
tThetaStep   equ   23h
tuTStep   equ   24h
tuThetStep   equ   25h
tDeltaX   equ   26h
tDeltaY   equ   27h
tXFact   equ   28h
tYFact   equ   29h
tTblInput   equ   2Ah
tFinN   equ   2Bh
tFinI   equ   2Ch
tFinPV   equ   2Dh
tFinPMT   equ   2Eh
tFinFV   equ   2Fh
tFinPY   equ   30h
tFinCY   equ   31h
tRecurw0   equ   32h   ; w0(1)
tuRecurw0   equ   33h
tPlotStep   equ   34h
tuPlotStep   equ   35h
tXres   equ   36h
tuXres   equ   37h
tRecuru02   equ   38h   ; u0(2)
tuRecuru02   equ   39h
tRecurv02   equ   3Ch   ; v0(2)
tuRecurv02   equ   3Dh
tRecurw02   equ   3Eh   ; w0(2)
tuRecurw02   equ   3Fh
;-------------------------------------------------------------------------------
; 2nd byte of t2ByteTok tokens
;-------------------------------------------------------------------------------
tFinNPV   equ   00h   ;
tFinIRR   equ   01h   ;
tFinBAL   equ   02h   ;
tFinPRN   equ   03h   ;
tFinINT   equ   04h   ;
tFinToNom   equ   05h   ;
tFinToEff   equ   06h   ;
tFinDBD   equ   07h   ;
tLCM   equ   08h   ;
tGCD   equ   09h   ;
tRandInt   equ   0Ah   ;
tRandBin   equ   0Bh   ;
tSubStrng   equ   0Ch   ;
tStdDev   equ   0Dh   ;
tVariance   equ   0Eh   ;
tInStrng   equ   0Fh   ;
tDNormal   equ   10h   ;
tInvNorm   equ   11h   ;
tDT   equ   12h   ;
tChI   equ   13h   ;
tDF   equ   14h   ;
tBINPDF   equ   15h   ;
tBINCDF   equ   16h   ;
tPOIPDF   equ   17h   ;
tPOICDF   equ   18h   ;
tGEOPDF   equ   19h   ;
tGEOCDF   equ   1Ah   ;
tNormalPDF   equ   1Bh   ;
tTPDF   equ   1Ch   ;
tChiPDF   equ   1Dh   ;
tFPDF   equ   1Eh   ;
tRandNorm   equ   1Fh   ;
tFinFPMT   equ   20h   ;
tFinFI   equ   21h   ;
tFinFPV   equ   22h   ;
tFinFN   equ   23h   ;
tFinFFV   equ   24h   ;
tConj   equ   25h   ;
tReal   equ   26h   ;
tImag   equ   27h   ;
tAngle   equ   28h   ;
tCumSum   equ   29h   ;
tExpr   equ   2Ah   ;
tLength   equ   2Bh   ;
tDeltaLst   equ   2Ch   ;
tRef   equ   2Dh   ;
tRRef   equ   2Eh   ;
tToRect   equ   2Fh   ;
tToPolar   equ   30h   ;
tConste   equ   31h   ;
tSinReg   equ   32h   ;
tLogistic   equ   33h   ;
tLinRegTTest   equ   34h   ;
tShadeNorm   equ   35h   ;
tShadeT   equ   36h   ;
tShadeChi   equ   37h   ;
tShadeF   equ   38h   ;
tMatToLst   equ   39h   ;
tLstToMat   equ   3Ah   ;
tZTest   equ   3Bh   ;
tTTest   equ   3Ch   ;
t2SampZTest equ   3Dh   ;
t1PropZTest equ   3Eh   ;
t2PropZTest equ   3Fh   ;
tChiTest   equ   40h   ;
tZIntVal   equ   41h   ;
t2SampZInt   equ   42h   ;
t1PropZInt   equ   43h   ;
t2PropZInt   equ   44h   ;
tGraphStyle equ   45h   ;
t2SampTTest equ   46h   ;
t2SampFTest equ   47h   ;
tTIntVal   equ   48h   ;
t2SampTInt   equ   49h   ;
tSetupLst   equ   4Ah   ;
tFinPMTend   equ   4Bh   ;
tFinPMTbeg   equ   4Ch   ;
tRealM   equ   4Dh   ;
tPolarM   equ   4Eh   ;
tRectM   equ   4Fh   ;
tExprOn   equ   50h   ;
tExprOff   equ   51h   ;
tClrAllLst   equ   52h   ;
tGetCalc   equ   53h   ;
tDelVar      equ   54h   ;
tequToStrng   equ   55h   ;
tStrngToequ   equ   56h   ;
tDelLast   equ   57h   ;
tSelect      equ   58h   ;
tANOVA      equ   59h   ;
tModBox      equ   5Ah   ;
tNormProb   equ   5Bh   ;

tMGT      equ   64h   ; VERTICAL SPLIT
tZFit      equ   65h   ; ZOOM FIT
tDiag_on   equ   66h   ; DIANOSTIC DISPLAY ON
tDiag_off   equ   67h   ; DIANOSTIC DISPLAY OFF
tOkEnd2v0   equ   67h   ;end of 2byte tokens for version 0.
tArchive   equ   68h   ;archive
tUnarchive   equ   69h   ;unarchive
tasm      equ   6Ah
tasmComp   equ   6Bh   ; assm compile
tasmPrgm   equ   6Ch   ; signifies a program is assm
tasmCmp    equ   6Dh   ; assm program is compiled
tLcapAAcute   equ   6Eh
tLcapAGrave   equ   6Fh
tLcapACaret   equ   70h
tLcapADier   equ   71h
tLaAcute   equ   72h
tLaGrave   equ   73h
tLaCaret   equ   74h
tLaDier      equ   75h
tLcapEAcute   equ   76h
tLcapEGrave   equ   77h
tLcapECaret   equ   78h
tLcapEDier   equ   79h
tLeAcute   equ   7Ah
tLeGrave   equ   7Bh
tLeCaret   equ   7Ch
tLeDier   equ   7Dh

tLcapIGrave   equ   7Fh
tLcapICaret   equ   80h
tLcapIDier   equ   81h
tLiAcute   equ   82h
tLiGrave   equ   83h
tLiCaret   equ   84h
tLiDier   equ   85h
tLcapOAcute   equ   86h
tLcapOGrave   equ   87h
tLcapOCaret   equ   88h
tLcapODier   equ   89h
tLoAcute   equ   8Ah
tLoGrave   equ   8Bh
tLoCaret   equ   8Ch
tLoDier   equ   8Dh
tLcapUAcute   equ   8Eh
tLcapUGrave   equ   8Fh
tLcapUCaret   equ   90h
tLcapUDier   equ   91h
tLuAcute   equ   92h
tLuGrave   equ   93h
tLuCaret   equ   94h
tLuDier   equ   95h
tLcapCCed   equ   96h
tLcCed   equ   97h
tLcapNTilde equ   98h
tLnTilde   equ   99h
tLaccent   equ   9Ah
tLgrave   equ   9Bh
tLdieresis   equ   9Ch
tLquesDown   equ   9Dh
tLexclamDown   equ   9Eh
tLalpha   equ   9Fh
tLbeta   equ   0a0h
tLgamma   equ   0a1h
tLcapDelta   equ   0a2h
tLdelta   equ   0a3h
tLepsilon   equ   0a4h
tLlambda   equ   0a5h
tLmu   equ   0a6h
tLpi   equ   0a7h
tLrho   equ   0a8h
tLcapSigma   equ   0a9h

tLphi   equ   0aBh
tLcapOmega   equ   0aCh
tLphat   equ   0aDh
tLchi   equ   0aEh
tLstatF   equ   0aFh
tLa   equ 0b0h
tLb   equ 0b1h
tLc   equ 0b2h
tLd   equ 0b3h
tLsmalle   equ   0b4h
tLf   equ   0b5h
tLsmallg   equ   0b6h
tLh   equ   0b7h
tLi   equ   0b8h
tLj   equ   0b9h
tLk   equ   0bAh

tLl   equ   0bCh
tLm   equ   0bDh
;tLnequ 0bEh
tLo   equ   0bFh
tLp   equ   0c0h
tLq   equ   0c1h
tLsmallr   equ   0c2h
tLs   equ   0c3h
tLsmallt   equ   0c4h
tLu   equ   0c5h
tLv   equ   0c6h
tLw   equ   0c7h
tLx   equ   0c8h
tLy   equ   0c9h
tLz   equ   0cAh
tLsigma   equ   0cbh
tLtau   equ   0cch
tLcapIAcute equ   0cdh
;
tGarbagec equ   0Ceh
LastToken   equ   0Ceh   ;Last token in this version...

;-----------------------------------------------
; Extended Tokens
;-----------------------------------------------
; These are new on OSes after 1.15
tExtTok      equ   0EFh

tSetDate   equ   00h
tSetTime   equ   01h
tCheckTmr   equ   02h
tSetDtFmt   equ   03h
tSetTmFmt   equ   04h
tTimeCnv   equ   05h
tDayOfWk   equ   06h
tGetDtStr   equ   07h
tGetTmStr   equ   08h
tGetDate   equ   09h
tGetTime   equ   0Ah
tStartTmr   equ   0Bh
tGtDtFmt   equ   0Ch
tGetTmFmt   equ   0Dh
tIsClockOn   equ   0Eh
tClockOff   equ   0Fh
tClockOn   equ   10h
tOpenLib   equ   11h
tExecLib   equ   12h
tInvT   equ   13h
tChiSquaredGofTest   equ   14h
tLinRegTInt   equ   15h
tManualFit   equ   16h

; MathPrint
tZQuadrant   equ   17h
tZFracHalf   equ   18h
tZFracThird   equ   19h
tZFracFourth   equ   1Ah
tZFracFifth   equ   1Bh
tZFracEighth   equ   1Ch
tZFracTenth   equ   1Dh
tFracSlash   equ   2Eh
tFracMixedNum   equ   2Fh
tSwapImProper   equ   30h
tSwapFracDec   equ   31h
tRemainder   equ   32h
tSummationSigma   equ   33h
tLogBase   equ   34h
tRandIntNoRep   equ   35h
tMathPrint   equ   37h
tClassic   equ   38h
tAutoAnswer   equ   3Bh
tDecAnswer   equ   3Ch
tFracAnswer   equ   3Dh

; TI-84+CSE
tBlue      equ   41h
tRed      equ   42h
tBlack       equ   43h
tMagenta   equ   44h
tGreen      equ   45h
tOrange      equ   46h
tBrown      equ   47h
tNavy      equ   48h
tLtBlue      equ   49h
tYellow      equ   4Ah
tWhite      equ   4Bh
tLtGray      equ   4Ch
tMedGray   equ   4Dh
tGray      equ   4Eh
tDarkGray   equ   4Fh

tGraphColor   equ   65h
tTextColor   equ   67h
tBackgroundOn   equ   5Bh
tBackgroundOff   equ   64h

tThin      equ   74h
;tThick - 0x7E 0x06 (was "Connected"?)
tAsm84CPrgm   equ   68h
tAsm84CCmp   equ   69h
tBorderColor   equ   6Ch

tAsm84CeCmp   equ   07Bh
tAsm84CePrgm   equ   07Ah
;-----------------------------------------------
; Data Types
;-----------------------------------------------
RealObj   equ   0
ListObj   equ   1
MatObj   equ   2
equObj   equ   3
StrngObj   equ   4
ProgObj   equ   5
ProtProgObj   equ   6
PictObj   equ   7
GDBObj   equ   8
UnknownObj   equ   9
UnknownequObj   equ   0Ah
NewequObj   equ   0Bh
CplxObj   equ   0Ch
CListObj   equ   0Dh
UndefObj   equ   0Eh
WindowObj   equ   0Fh
ZStoObj   equ   10h
TblRngObj   equ   11h
LCDObj   equ   12h
BackupObj   equ   13h
AppObj   equ   14h      ;application, only used in menus/link
AppVarObj   equ   15h      ;application variable
TempProgObj equ   16h   ;program, home deletes when finished
GroupObj   equ   17h   ;group.
;-----------------------------------------------
; System Error Codes
;-----------------------------------------------
E_EDITF   equ   7      ;allow re-entering application
E_EDIT   equ   1<<E_EDITF
E_Mask   equ   7Fh

E_Overflow   equ   1+E_EDIT
E_DivBy0   equ   2+E_EDIT
E_SingularMat   equ   3+E_EDIT
E_Domain   equ   4+E_EDIT
E_Increment   equ   5+E_EDIT
E_Break   equ   6+E_EDIT
E_NonReal   equ 7+E_EDIT
E_Syntax   equ 8+E_EDIT
E_DataType   equ 9+E_EDIT
E_Argument   equ 10+E_EDIT
E_DimMismatch   equ 11+E_EDIT
E_Dimension   equ 12+E_EDIT
E_Undefined   equ 13+E_EDIT
E_Memory   equ 14+E_EDIT
E_Invalid   equ 15+E_EDIT
E_IllegalNest equ 16+E_EDIT
E_Bound   equ 17+E_EDIT
E_GraphRange   equ 18+E_EDIT
E_Zoom   equ 19+E_EDIT
E_Label   equ 20
E_Stat   equ 21
E_Solver   equ 22+E_EDIT
E_Singularity   equ 23+E_EDIT
E_SignChange   equ 24+E_EDIT
E_Iterations   equ 25+E_EDIT
E_BadGuess   equ 26+E_EDIT
E_StatPlot   equ 27
E_TolTooSmall   equ 28+E_EDIT
E_Reserved   equ 29+E_EDIT
E_Mode   equ 30+E_EDIT
E_LnkErr   equ 31+E_EDIT
E_LnkMemErr   equ 32+E_EDIT
E_LnkTransErr   equ 33+E_EDIT
E_LnkDupErr   equ 34+E_EDIT
E_LnkMemFull   equ 35+E_EDIT
E_Unknown   equ 36+E_EDIT
E_Scale   equ 37+E_EDIT
E_IdNotFound   equ 38
E_NoMode   equ 39+E_EDIT
E_Validation   equ 40
E_Length   equ 41+E_EDIT
E_Application   equ 42+E_EDIT
E_AppErr1   equ 43+E_EDIT
E_AppErr2   equ 44+E_EDIT
E_ExpiredApp   equ   45
E_BadAddr   equ   46
E_Archived   equ 47+E_EDIT
E_Version   equ 48
E_ArchFull   equ 49
E_Variable   equ 50+E_EDIT
E_Duplicate   equ 51+E_EDIT
HigErrNum   equ 51
;-----------------------------------------------
; Stat Vars Equates
;-----------------------------------------------
FPLEN   equ   9      ;Length of a floating-point number.
StatN   equ   statVars
XMean   equ   StatN+FPLEN
SumX   equ   XMean+FPLEN
SumXSqr   equ   SumX+FPLEN
StdX   equ   SumXSqr+FPLEN
StdPX   equ   StdX+FPLEN
MinX   equ   StdPX+FPLEN
MaxX   equ   MinX+FPLEN
MinY   equ   MaxX+FPLEN
MaxY   equ   MinY+FPLEN
YMean   equ   MaxY+FPLEN
SumY   equ   YMean+FPLEN
SumYSqr   equ   SumY+FPLEN
StdY   equ   SumYSqr+FPLEN
StdPY   equ   StdY+FPLEN
SumXY   equ   StdPY+FPLEN
Corr   equ   SumXY+FPLEN
MedX   equ   Corr+FPLEN
Q1   equ   MedX+FPLEN
Q3   equ   Q1+FPLEN
QuadA   equ   Q3+FPLEN
QuadB   equ   QuadA+FPLEN
QuadC   equ   QuadB+FPLEN
CubeD   equ   QuadC+FPLEN
QuartE   equ   CubeD+FPLEN
MedX1   equ   QuartE +FPLEN
MedX2   equ   MedX1+FPLEN
MedX3   equ   MedX2+FPLEN
MedY1   equ   MedX3+FPLEN
MedY2   equ   MedY1+FPLEN
MedY3   equ   MedY2+FPLEN
PStat   equ   MedY3+2*FPLEN
ZStat   equ   PStat+FPLEN
TStat   equ   ZStat+FPLEN
ChiStat   equ   TStat+FPLEN
FStat   equ   ChiStat+FPLEN
DF   equ   FStat+FPLEN
Phat   equ   DF+FPLEN
Phat1   equ   Phat+FPLEN
Phat2   equ   Phat1+FPLEN
MeanX1   equ   Phat2+FPLEN
StdX1   equ   MeanX1+FPLEN
StatN1   equ   StdX1+FPLEN
MeanX2   equ   StatN1+FPLEN
StdX2   equ   MeanX2+FPLEN
StatN2   equ   StdX2+FPLEN
StdXP2   equ   StatN2+FPLEN
SLower   equ   StdXP2+FPLEN
SUpper   equ   SLower+FPLEN
SStat   equ   SUpper+FPLEN

;F_DF   equ anovaf_vars
;F_SS   equ F_DF + FPLEN
;F_MS   equ F_SS + FPLEN
;E_DF   equ F_MS + FPLEN
;E_SS   equ E_DF + FPLEN
;E_MS   equ E_SS + FPLEN
#endif
.list