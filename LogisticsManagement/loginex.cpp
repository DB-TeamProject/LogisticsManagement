//// �����ۼ���: 20183215 ������ [2022.12.02]
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
//// win32 Visual C 2010 �̻������Ͻ� �߰�
//#define getch() _getch()
////-----------------------------------------
//
//extern void select_main();
//
///*---------------  ȭ�� Ŀ�� ��ġ ���� ----------------------*/
//#include < windows.h >
//void gotoxy(int x, int y);
//void getxy(int* x, int* y);
//void clrscr(void);
///*-----------------------------------------------------------*/
//void login();
//void select_login();
//void sql_error();
//
//EXEC SQL BEGIN DECLARE SECTION;
//VARCHAR uid[80];
//VARCHAR pwd[20];
//EXEC SQL END DECLARE SECTION;
//
//#define getch() _getch()
//
//void login()
//{
//	_putenv("NLS_LANG=American_America.KO16KSC5601"); //�ѱۻ��
//
//	DB_connect();
//	select_login();
//	EXEC SQL COMMIT WORK RELEASE;
//	getch();
//}
//
//
//void select_login()
//{
//	int count = 0;
//	while (1) {
//		clrscr();
//		gotoxy(0, 0);
//		print_screen("login.txt");
//
//		if (count == 1) { // ������ ���̵� ��й�ȣ�� Ʋ���� ���
//			gotoxy(10, 12);
//			printf("���̵� �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�.");
//		}
//
//
//		EXEC SQL BEGIN DECLARE SECTION;
//		varchar id[100];
//		varchar pw[100];
//
//		char dynstmt[1000];
//		EXEC SQL END DECLARE SECTION;
//
//		char no_temp1[10];
//		char no_temp2[10];
//
//		/* Register sql_error() as the error handler. */
//		EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");
//
//
//		/* ����� �Է� */
//		gotoxy(23, 8);
//		gets(no_temp1); // ���̵� �Է�
//
//		gotoxy(23, 10);
//		gets(no_temp2); // ��й�ȣ �Է�
//
//
//		/* �����ų SQL ����*/
//		sprintf(dynstmt, "SELECT id, pw FROM account where id = '%s' and pw = '%s'  ",
//			no_temp1, no_temp2);
//
//		EXEC SQL PREPARE S FROM : dynstmt;
//
//		/* cursor ���� */
//		EXEC SQL DECLARE c_cursor CURSOR FOR S;
//
//		/* cursor open */
//		EXEC SQL OPEN c_cursor;
//
//		EXEC SQL WHENEVER NOT FOUND DO break;
//
//		for (;;) {
//			count = 1;
//			EXEC SQL FETCH c_cursor INTO : id, : pw;
//			id.arr[id.len] = '\0';
//			pw.arr[pw.len] = '\0';
//			if (id.arr != NULL && pw.arr != NULL) { // �����ͺ��̽����� ���� ã���� ���
//				clrscr();
//				select_main(); 
//				count = 2; // �α��ο� ������ ��� �ݺ��� break
//			}
//		}
//
//
//		EXEC SQL CLOSE c_cursor;
//		EXEC SQL COMMIT;
//
//		if (count == 2) {
//			break;
//		}
//	}
//}