////최초작성자: 20183215 정현수 [2022.12.02]
//#define _CRT_SECURE_NO_WARNINGS
//#define PAGE_NUM 5
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <conio.h>
//
///* for oracle */
//#include <sqlda.h>
//#include <sqlca.h>
//#include <sqlcpr.h>
//
//
////win32 Visual C 2010 이상컴파일시 추가
//#define getch() _getch()
///*-----------------------------------------*/
//
//
///*---------------  화면 커서 위치 제어 ----------------------*/
//#include < windows.h >
//void gotoxy(int x, int y);
//void getxy(int* x, int* y);
//void clrscr(void);
///*-----------------------------------------------------------*/
//void select_product();
//void insert_storage();
//void find_product();
//void sql_error();
//static char find_pid[100] = { NULL, };
//static char find_pname[100] = { NULL, };
//static char find_pprice[100] = { NULL, };
//
//EXEC SQL BEGIN DECLARE SECTION;
//VARCHAR uid[80];
//VARCHAR pwd[20];
//EXEC SQL END DECLARE SECTION;
//
//#define getch() _getch()
//
//void addStorage()
//{
//	_putenv("NLS_LANG=American_America.KO16KSC5601"); //한글사용
//	DB_connect();
//	select_product();
//	insert_storage();
//	EXEC SQL COMMIT WORK RELEASE;
//	getch();
//}
//
//
//void select_product()
//{
//	clrscr();
//	gotoxy(0, 1);
//	print_screen("addStorage.txt");
//
//	EXEC SQL BEGIN DECLARE SECTION;
//	varchar id[100];
//	varchar name[100];
//	varchar amount[100];
//	varchar price[100];
//
//	char dynstmt[1000];
//	EXEC SQL END DECLARE SECTION;
//
//
//	/* Register sql_error() as the error handler. */
//	EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");
//
//
//	/* 실행시킬 SQL 문장*/
//	sprintf(dynstmt, "SELECT pid, pname, pamount, pprice FROM BusinessStorage");
//
//	EXEC SQL PREPARE S FROM : dynstmt;
//
//	/* cursor 선언 */
//	EXEC SQL DECLARE c_cursor CURSOR FOR S;
//
//	/* cursor open */
//	EXEC SQL OPEN c_cursor;
//
//	int y = 14;
//
//	for (;;) {
//		EXEC SQL WHENEVER NOT FOUND DO break;
//		EXEC SQL FETCH c_cursor INTO : id, : name, : amount, : price;
//
//		id.arr[id.len] = '\0';
//		name.arr[name.len] = '\0';
//		amount.arr[amount.len] = '\0';
//		price.arr[price.len] = '\0';
//
//		gotoxy(30, y);
//		printf(" %-10s|%-15s|%-10s|%-10s", id.arr, name.arr, amount.arr, price.arr);
//		y++;
//	}
//
//	EXEC SQL CLOSE c_cursor;
//
//	EXEC SQL COMMIT;
//}
//
//void insert_storage()
//{
//	EXEC SQL BEGIN DECLARE SECTION;
//	char dynstmt[1000];
//	EXEC SQL END DECLARE SECTION;
//
//	char pid[100];
//	char pamount[100];
//
//	EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");
//
//	//상품번호 입력
//	while (1) {
//		gotoxy(29, 8);
//		gets(pid);
//		if (strlen(pid) <= 0) {
//			printf("상품 번호를 입력하지 않았습니다.");
//		}
//		else {
//			break;
//		}
//	}
//
//	//수량 입력
//	gotoxy(55, 8);
//	gets(pamount);
//
//	sprintf(sql, "insert into storage values ( '100', '%s', '패딩', '%s', '20000')",
//		pid, pamount);
//	gotoxy(20, 9);
//	printf("주문 성공하였습니다.");
//	/* 실행시킬 SQL 문장*/
//	EXEC SQL EXECUTE IMMEDIATE : dynstmt;
//
//	EXEC SQL COMMIT WORK;
//
//}