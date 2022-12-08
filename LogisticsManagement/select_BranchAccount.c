
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
           char  filnam[24];
};
static const struct sqlcxp sqlfpn =
{
    23,
    "select_BranchAccount.pc"
};


static unsigned int sqlctx = 648136187;


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
            void  *sqhstv[2];
   unsigned int   sqhstl[2];
            int   sqhsts[2];
            void  *sqindv[2];
            int   sqinds[2];
   unsigned int   sqharm[2];
   unsigned int   *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {13,2};

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
5,0,0,1,0,0,30,58,0,0,0,0,0,1,0,
20,0,0,2,0,0,24,211,0,0,1,1,0,1,0,1,97,0,0,
39,0,0,3,0,0,29,213,0,0,0,0,0,1,0,
54,0,0,4,0,0,24,241,0,0,1,1,0,1,0,1,97,0,0,
73,0,0,5,0,0,29,243,0,0,0,0,0,1,0,
88,0,0,6,0,0,17,300,0,0,1,1,0,1,0,1,97,0,0,
107,0,0,6,0,0,45,306,0,0,0,0,0,1,0,
122,0,0,6,0,0,13,311,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
145,0,0,6,0,0,17,380,0,0,1,1,0,1,0,1,97,0,0,
164,0,0,6,0,0,45,386,0,0,0,0,0,1,0,
179,0,0,6,0,0,13,391,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
};


// 최초작성자: 20183109 강상혁 [2022.12.03]
#define _CRT_SECURE_NO_WARNINGS
//-----------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>
/*------------*/

#define getch() _getch()

extern void select_BranchMain();
extern void Mod_ID();
extern void login();
extern char global_officenumber[100];

char officenum[100];
char cur_id[100];
char mod_id[100];
char cur_pass[100];
char mod_pass[100];

/*---------------  화면 커서 위치 제어 ----------------------*/
#include < windows.h >
void gotoxy(int x, int y);
void getxy(int* x, int* y);
void clrscr(void);
/*-----------------------------------------------------------*/

void BranchAccount();
void select_ModId();
void Search_BranchInfo();

void select_ModPass();
void Search_PassInfo();
void Mod_Pass();
void sql_error();

/* EXEC SQL BEGIN DECLARE SECTION; */ 

/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 



void select_BranchAccount(){
	_putenv("NLS_LANG=American_America.KO16KSC5601"); //한글사용
	DB_connect();
	BranchAccount();
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

void BranchAccount(){
	clrscr();
	gotoxy(0, 1);
	print_screen("BranchAccount_Menu.txt");
	int cursor_position = 14; // 현재 커서 위치
	int input_status; // 입력 상태
	while (1) {
		gotoxy(42, cursor_position);
		input_status = _getch();
		if (input_status == 72 || input_status == 80) { //윗방향 또는 아래방향을 입력받았을 경우

			if (input_status == 72) { // 방향키↑를 입력받았을 경우
				if (cursor_position == 14) { // 커서가 첫번째 행에 있고, 윗방향키를 입력받았을 경우 마지막 행으로 감
					cursor_position = 18;
				}
				else {
					cursor_position -= 2;
				}
			}
			else if (input_status == 80) {// 방향키↓를 입력받았을 경우
				if (cursor_position == 18) { // 커서가 마지막 행에 있고, 윗방향키를 입력받았을 경우 마지막 행으로 감
					cursor_position = 14;
				}
				else {
					cursor_position += 2;
				}
			}
		}
		else if (input_status == 13) { // 엔터키를 입력받았을 경우			
			clrscr();
			if (cursor_position == 14) {//ID 변경 선택 시
				select_ModId();
			}
			else if(cursor_position == 16){//PASSWORD 변경 선택 시
				select_ModPass();
			}
			else if(cursor_position == 18){//뒤로가기 선택시
				select_BranchMain();
			}

			break;
		}
	}
}

void select_ModId(){ //ID 변경 선택 함수
	clrscr();
	gotoxy(0, 1);
	print_screen("BranchModID_Menu.txt");
	int cursor_position = 7; // 현재 커서 위치
	int input_status; // 입력 상태
	while (1) {
		gotoxy(44, cursor_position);
		input_status = _getch();
		if (input_status == 72 || input_status == 80) { //윗방향 또는 아래방향을 입력받았을 경우

			if (input_status == 72) { // 방향키↑를 입력받았을 경우
				if (cursor_position == 7) { // 커서가 첫번째 행에 있고, 윗방향키를 입력받았을 경우 마지막 행으로 감
					cursor_position = 18;
				}
				else {
					cursor_position = 7;
				}
			}
			else if (input_status == 80) {// 방향키↓를 입력받았을 경우
				if (cursor_position == 18) { // 커서가 마지막 행에 있고, 윗방향키를 입력받았을 경우 마지막 행으로 감
					cursor_position = 7;
				}
				else {
					cursor_position = 18;
				}
			}
		}
		else if (input_status == 13) { // 엔터키를 입력받았을 경우
			clrscr();						
			if (cursor_position == 18) {//뒤로가기 선택시
				select_BranchAccount();
			}
			Search_BranchInfo();	

			break;
		}
	}

}

void select_ModPass(){ //PASSWORD 변경선택 함수
	clrscr();
	gotoxy(0, 1);
	print_screen("BranchModPass_Menu.txt");
	int cursor_position = 7; // 현재 커서 위치
	int input_status; // 입력 상태
	while (1) {
		gotoxy(44, cursor_position);
		input_status = _getch();
		if (input_status == 72 || input_status == 80) { //윗방향 또는 아래방향을 입력받았을 경우

			if (input_status == 72) { // 방향키↑를 입력받았을 경우
				if (cursor_position == 7) { // 커서가 첫번째 행에 있고, 윗방향키를 입력받았을 경우 마지막 행으로 감
					cursor_position = 18;
				}
				else {
					cursor_position = 7;
				}
			}
			else if (input_status == 80) {// 방향키↓를 입력받았을 경우
				if (cursor_position == 18) { // 커서가 마지막 행에 있고, 윗방향키를 입력받았을 경우 마지막 행으로 감
					cursor_position = 7;
				}
				else {
					cursor_position = 18;
				}
			}
		}
		else if (input_status == 13) { // 엔터키를 입력받았을 경우
			clrscr();			
			Search_PassInfo();			
			if (cursor_position == 18) {//뒤로가기 선택시
				Search_PassInfo();
			}

			break;
		}
	}
}
void Mod_ID(){ //ID Update 함수
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


   	char dynstmt[1000];

	/* EXEC SQL END DECLARE SECTION; */ 


   	char  office[100];
   	char  currentid[100];
   	char  modifyid[100];
  
     /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


  	strcpy(office, officenum);
	strcpy(modifyid, mod_id);

	sprintf(dynstmt,"update account set id = '%s' where officenumber = %s ", modifyid, office);
	clrscr();
	gotoxy(0, 1);
	print_screen("BranchModID_Menu.txt");
	gotoxy(36, 16);
	printf("정보를 변경하였습니다. 로그인 창으로 돌아갑니다.");
	//printf("stmt:%s\n", dynstmt);
	Sleep (1000);
	/* EXEC SQL EXECUTE IMMEDIATE : dynstmt; */ 

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



	/* EXEC SQL COMMIT WORK; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


	login(); 
}

 void Mod_Pass(){ //패스워드 update 함수	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


   	char dynstmt2[1000];

	/* EXEC SQL END DECLARE SECTION; */ 


   	char  office2[100];
   	char  currentpass[100];
   	char  modifypass[100];
  
     /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


  	strcpy(office2, officenum);
	strcpy(modifypass, mod_pass);

	sprintf(dynstmt2,"update account set pw = '%s' where officenumber = %s ", modifypass, office2);
	clrscr();
	gotoxy(0, 1);
	print_screen("BranchModPass_Menu.txt");
	gotoxy(36, 16);
	printf("정보를 변경하였습니다. 로그인 창으로 돌아갑니다.");
	//printf("stmt:%s\n", dynstmt2);
	Sleep (1000);
	/* EXEC SQL EXECUTE IMMEDIATE : dynstmt2; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )54;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)dynstmt2;
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



	/* EXEC SQL COMMIT WORK; */ 

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


	login(); 	

}
void Search_BranchInfo(){ // 지사 정보 조회 함수
	int count = 0;
	while(1){
	
		clrscr();
		gotoxy(0, 1);
		print_screen("BranchModID_Menu.txt");
		if(count == 1){
			gotoxy(35, 15);
			printf("입력한 정보가 올바르지 않습니다 다시 시도해 주세요.");
		}
		count = 1;

		/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar officenumber[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } officenumber;

		/* varchar id[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } id;


		char dynstmt[1000];
		/* EXEC SQL END DECLARE SECTION; */ 


		char no_temp1[100];
		char no_temp2[100];
		char no_temp3[100];

		/* Register sql_error() as the error handler. */
		/* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 

		
		/* 사용자 입력 */
		gotoxy(44, 7);
		printf("%s",global_officenumber);
		strcpy(no_temp1,global_officenumber);
		
		
		gotoxy(44, 9);
		gets(no_temp2); // 현재 아이디 입력

		gotoxy(44, 11);
		gets(no_temp3); // 수정할 아이디 입력
		
		

		if(strlen(no_temp1) <=0 || strlen(no_temp2) <=0 || strlen(no_temp3) <=0){
			gotoxy(35, 15);
			printf("입력하지 않은 항목이 있습니다 다시 시도해주세요,\n");
			
		}else{
			strcpy(mod_id, no_temp3);
		
		}
		
		/* 실행시킬 SQL 문장*/
		sprintf(dynstmt, "SELECT officenumber, id  FROM account where officenumber = '%s' and id = '%s' ", no_temp1, no_temp2 );

		/* EXEC SQL PREPARE S FROM : dynstmt; */ 

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
  sqlstm.offset = (unsigned int  )107;
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



		/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

			
		for (;;) {
			/* EXEC SQL FETCH c_cursor INTO : officenumber, : id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 2;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )122;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (           int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (         void  *)&officenumber;
   sqlstm.sqhstl[0] = (unsigned int  )102;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)&id;
   sqlstm.sqhstl[1] = (unsigned int  )102;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
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


			officenumber.arr[officenumber.len] = '\0';
			id.arr[id.len] = '\0';
			gotoxy(35, 15);
			 
			if (officenumber.arr != NULL && id.arr != NULL) { // 데이터베이스에서 값을 찾았을 경우						
				clrscr();
				strcpy(officenum, officenumber.arr);
				strcpy(cur_id, id.arr);
				count = 0;
				Mod_ID();
				break;

			}
		}
	}	
}


 void Search_PassInfo(){ //지사 패스워드 조회 함수
		int count = 0;
		while(1){
	
		clrscr();
		gotoxy(0, 1);
		print_screen("BranchModPass_Menu.txt");
		if(count == 1){
			gotoxy(35, 15);
			printf("입력한 정보가 올바르지 않습니다 다시 시도해 주세요.");
		}
		count = 1;

		/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar officenumber[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } officenumber;

		/* varchar pw[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } pw;


		char dynstmt2[1000];
		/* EXEC SQL END DECLARE SECTION; */ 


		char no_temp1[100];
		char no_temp2[100];
		char no_temp3[100];

		/* Register sql_error() as the error handler. */
		/* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 

		
		/* 사용자 입력 */
		gotoxy(44, 7);
		printf("%s",global_officenumber);
		strcpy(no_temp1,global_officenumber);
		
		gotoxy(44, 9);
		gets(no_temp2); // 현재 패스워드 입력

		gotoxy(44, 11);
		gets(no_temp3); // 수정할 패스워드 입력
		
		if(strlen(no_temp1) <=0 || strlen(no_temp2) <=0 || strlen(no_temp3) <=0){
			gotoxy(35, 15);
			printf("입력하지 않은 항목이 있습니다 다시 시도해주세요,\n");
			
		}else{
			strcpy(mod_pass, no_temp3);
		
		}
		
		/* 실행시킬 SQL 문장*/
		sprintf(dynstmt2, "SELECT officenumber, pw  FROM account where officenumber = '%s' and pw = '%s' ", no_temp1, no_temp2 );

		/* EXEC SQL PREPARE S FROM : dynstmt2; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )145;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)dynstmt2;
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
		/* EXEC SQL DECLARE c_cursor2 CURSOR FOR S; */ 


		/* cursor open */
		/* EXEC SQL OPEN c_cursor2; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )164;
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



		/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

			
		for (;;) {
			/* EXEC SQL FETCH c_cursor2 INTO : officenumber, : pw; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 2;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )179;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (           int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (         void  *)&officenumber;
   sqlstm.sqhstl[0] = (unsigned int  )102;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)&pw;
   sqlstm.sqhstl[1] = (unsigned int  )102;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
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


			officenumber.arr[officenumber.len] = '\0';
			pw.arr[pw.len] = '\0';
			gotoxy(35, 15);
			if (officenumber.arr != NULL && pw.arr != NULL) { // 데이터베이스에서 값을 찾았을 경우	
				
				clrscr();
				strcpy(officenum, officenumber.arr);
				strcpy(cur_pass, pw.arr);
				count = 0;
				Mod_Pass();
				break;
			}
		}
	}	
}




