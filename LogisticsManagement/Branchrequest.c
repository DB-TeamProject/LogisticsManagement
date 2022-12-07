
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[17];
};
static const struct sqlcxp sqlfpn =
{
    16,
    "Branchrequest.pc"
};


static unsigned int sqlctx = 4649163;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {13,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,1,0,0,30,65,0,0,0,0,0,1,0,
20,0,0,2,0,0,17,102,0,0,1,1,0,1,0,1,97,0,0,
39,0,0,2,0,0,45,107,0,0,0,0,0,1,0,
54,0,0,2,0,0,13,111,0,0,1,0,0,1,0,2,9,0,0,
73,0,0,2,0,0,15,120,0,0,0,0,0,1,0,
88,0,0,3,0,0,24,162,0,0,1,1,0,1,0,1,97,0,0,
107,0,0,4,0,0,29,163,0,0,0,0,0,1,0,
122,0,0,2,0,0,17,182,0,0,1,1,0,1,0,1,97,0,0,
141,0,0,2,0,0,45,187,0,0,0,0,0,1,0,
156,0,0,2,0,0,13,192,0,0,1,0,0,1,0,2,9,0,0,
175,0,0,2,0,0,15,201,0,0,0,0,0,1,0,
190,0,0,2,0,0,17,332,0,0,1,1,0,1,0,1,97,0,0,
209,0,0,2,0,0,45,338,0,0,0,0,0,1,0,
224,0,0,2,0,0,13,348,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
255,0,0,2,0,0,15,362,0,0,0,0,0,1,0,
};


// 최초 작성자 : 20183207 김성찬
/*-----------------------------------------------

-------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

//-----------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>

//#ifdef WIN32
#include < windows.h >
/*---------------  화면 커서 위치 제어 ----------------------*/
void gotoxy(int x, int y) ;
void getxy(int *x, int *y) ;
void clrscr(void) ;
/*-----------------------------------------------------------*/
#define getch() _getch()

int max=1;
void getmax();
void Branch();
void branchrequest();
void paintui();
void get_item();
void paintui_errorpid();
void paintui_erroramount();
void paintui_errortype();
char pid[15] ="";
char amount[15] ="";
char type[15] = "";
char tmp[25]="";
void DB_connect();
void rtrim();

extern void select_BranchMain();
extern char global_officenumber[100];
int count = 1;
int colcount=0;
void sql_error();

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

	/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 



void Branch()
{
	_putenv("NLS_LANG=American_America.KO16KSC5601"); //한글사용
    strcpy(pid,tmp);
    strcpy(amount,tmp);
    strcpy(type,tmp);
    DB_connect();
    branchrequest();
    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
    getch();
}

void branchrequest()
{
gotoxy(0, 1);
/* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* varchar pamount[13]; */ 
struct { unsigned short len; unsigned char arr[13]; } pamount;

    char dynstmt[1000];

/* EXEC SQL END DECLARE SECTION; */ 


    char ordernumber[100];   

   /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


   clrscr();

   /* 데이터 입력 */

    FILE* fs;
    fs = fopen("Branchrequest.txt", "r");
    while (feof(fs) == 0) {
        char str[1000];
        fgets(str, 1000, fs);
        printf("%s", str);
    }
    get_item();


   /* 제품번호 입력 */
    do{
        gotoxy(53, 10);
        gets(pid);
        sprintf(dynstmt, "SELECT pamount  FROM storage where pid =  '%s'", pid);
        /* EXEC SQL PREPARE S FROM : dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )20;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)dynstmt;
        sqlstm.sqhstl[0] = (unsigned int  )1000;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


        /* cursor 선언 */
        /* EXEC SQL DECLARE c_cursor CURSOR FOR S; */ 


        /* cursor open */
        /* EXEC SQL OPEN c_cursor; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )39;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



        for (;;)
        {
            /* EXEC SQL FETCH c_cursor INTO : pamount; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 1;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )54;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&pamount;
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


	if (sqlca.sqlcode == 1403) break;
            pamount.arr[pamount.len] = '\0';
        }
        colcount= sqlca.sqlerrd[2];
        if(sqlca.sqlerrd[2] == 0){
	paintui_errorpid();
	}
            /* Close the cursor. */
            /* EXEC SQL CLOSE c_cursor; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 1;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )73;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


            }while (colcount== 0);
	if(count!=1) paintui();
	


   /* 수량 입력 */
    
    bool isamount = false;
    do {
        isamount = false;
        gotoxy(53, 12);
        gets(amount);
        for (int i = 0; amount[i] != '\0'; i++) //문자열 끝까지
        {
            if (!isdigit(amount[i])) { //숫자가 아니면
                paintui_erroramount();
                isamount = true;
            }

        }
    } while (isamount);
    paintui();
    
    bool istype = false;
   /* 타입 입력 */
    
    
    do {
        gotoxy(53, 14);
        gets(type);
        istype = false;
        if (strcmp("입고", type) != 0 && strcmp("출고", type) != 0)
        {
            paintui_errortype();
            istype = true;
        }
    } while (istype);
    paintui();
    getmax();
    gotoxy(51, 16);
    sprintf(dynstmt,"insert into warehousing values ( '%d', '%s','%s', '%s','%s',to_char(sysdate))" , max,type,global_officenumber, pid, amount);
    /* EXEC SQL EXECUTE IMMEDIATE :dynstmt ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )88;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)dynstmt;
    sqlstm.sqhstl[0] = (unsigned int  )1000;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


    /* EXEC SQL COMMIT WORK ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )107;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


    gotoxy(38, 17);
    printf("입/출고를 신청합니다.");
    Sleep(1500);
    select_BranchMain();
}

/* --------------------------------------------------------------------------
void sql_error()

   errrpt prints the ORACLE error msg and number.
-------------------------------------------------------------------------- */
void getmax(){
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* varchar ordernumber[13]; */ 
struct { unsigned short len; unsigned char arr[13]; } ordernumber;

    char dynstmt[1000];

    /* EXEC SQL END DECLARE SECTION; */ 

    sprintf(dynstmt, "SELECT  max(CAST (ordernumber AS int)) FROM warehousing");
        /* EXEC SQL PREPARE S FROM : dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )122;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)dynstmt;
        sqlstm.sqhstl[0] = (unsigned int  )1000;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


        /* cursor 선언 */
        /* EXEC SQL DECLARE order_cursor CURSOR FOR S; */ 


        /* cursor open */
        /* EXEC SQL OPEN order_cursor; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )141;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



        for (;;)
        {
            /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

            /* EXEC SQL FETCH order_cursor INTO : ordernumber; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 1;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )156;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&ordernumber;
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode == 1403) break;
            if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


            ordernumber.arr[ordernumber.len] = '\0';
        }
        if(sqlca.sqlerrd[2] == 0){
	        max=1;
    	}
	
        else max = atoi(ordernumber.arr)+1;
            /* Close the cursor. */
            /* EXEC SQL CLOSE order_cursor; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 1;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )175;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


}
void paintui() { //53 10 12 14
    clrscr();
    gotoxy(0, 1);
    FILE* fs;
    count = 1;
    fs = fopen("Branchrequest.txt", "r");
    while (feof(fs) == 0) {
        char str[1000];
        fgets(str, 1000, fs);
        printf("%s", str);
        if (count == 10) {
            gotoxy(53, 10);
            printf("%s", pid);
        }
        if (count == 12) {
            gotoxy(53, 12);
            printf("%s", amount);
        }
        if (count == 14) {
            gotoxy(53, 14);
            printf("%s", type);
        }
        count++;
    }
    get_item();
}
void paintui_errorpid() { //53 10 12 14
    clrscr();
    strcpy(pid," ");
    gotoxy(0, 1);
    FILE* fs;
    count = 1;
    fs = fopen("Branchrequest.txt", "r");
    while (feof(fs) == 0) {
        char str[1000];
        fgets(str, 1000, fs);
        printf("%s", str);
        if (count == 10) {
            gotoxy(53, 10);
            printf("%s", pid);            
        }
        if (count == 11) {
            gotoxy(23, 11);
            printf("확인할 수 없는 재품번호 입니다. 다시 입력해 주세요\n");
        }
        count++;
    }
    get_item();   

}
void paintui_erroramount() { //53 10 12 14
    clrscr();
    strcpy(amount, " ");
    gotoxy(0, 1);
    FILE* fs;
    count = 1;
    fs = fopen("Branchrequest.txt", "r");
    while (feof(fs) == 0) {
        char str[1000];
        fgets(str, 1000, fs);
        printf("%s", str);
        if (count == 10) {
            gotoxy(53, 10);
            printf("%s", pid);
        }
        if (count == 12) {
            gotoxy(53, 12);
            printf("%s", amount);
        }
        if (count == 13) {
            gotoxy(36, 13);
            printf("숫자만 입력해 주세요.\n");
        }
        count++;
    }
    get_item();
}
void paintui_errortype() { //53 10 12 14
    clrscr();
    strcpy(type, " ");
    gotoxy(0, 1);
    FILE* fs;
    count = 1;
    fs = fopen("Branchrequest.txt", "r");
    while (feof(fs) == 0) {
        char str[1000];
        fgets(str, 1000, fs);
        printf("%s", str);
        if (count == 10) {
            gotoxy(53, 10);
            printf("%s", pid);
        }
        if (count == 12) {
            gotoxy(53, 12);
            printf("%s", amount);
        }
        if (count == 14) {
            gotoxy(53, 14);
            printf("%s", type);
        }
        if (count == 15) {
            gotoxy(33, 15);
            printf("타입을 다시 입력해 주세요.\n");
        }
        count++;
    }
    get_item();

}

void get_item()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* varchar id[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } id;

	/* varchar name[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } name;

	/* varchar amount[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } amount;

	/* varchar price[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } price;


	char dynstmt[1000];
	/* EXEC SQL END DECLARE SECTION; */ 



	/* Register sql_error() as the error handler. */
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 



	/* 실행시킬 SQL 문장*/
	sprintf(dynstmt, "SELECT b.pid, p.pname, b.pamount, p.pprice FROM storage b join productinfo p on b.pid = p.pid");

	/* EXEC SQL PREPARE S FROM : dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )190;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)dynstmt;
 sqlstm.sqhstl[0] = (unsigned int  )1000;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



	/* cursor 선언 */
	/* EXEC SQL DECLARE p_cursor CURSOR FOR S; */ 


	/* cursor open */
	/* EXEC SQL OPEN p_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )209;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


	gotoxy(20, 20);
	printf(" 상품코드  |이름           |수량      |개당 가격    ");
	gotoxy(20, 21);
	printf("----------------------------------------------");
	int y = 22;

	for (;;)
	{

		/* EXEC SQL FETCH p_cursor INTO : id, : name, : amount, : price; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )224;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&id;
  sqlstm.sqhstl[0] = (unsigned int  )102;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&name;
  sqlstm.sqhstl[1] = (unsigned int  )102;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&amount;
  sqlstm.sqhstl[2] = (unsigned int  )102;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&price;
  sqlstm.sqhstl[3] = (unsigned int  )102;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


		if (sqlca.sqlcode == 1403) break;
		id.arr[id.len] = '\0';
		name.arr[name.len] = '\0';
		amount.arr[amount.len] = '\0';
		price.arr[price.len] = '\0';
		gotoxy(20, y);
		printf(" %-10s|%-15s|%-10s|%-10s", id.arr, name.arr, amount.arr, price.arr);
		y++;


	}

	/* Close the cursor. */
	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )255;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


}