#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

struct account
{
	char name[64];
	char password[64];
};

struct archive 
{
	struct account ACCOUNTS[60];
	int counter_accounts;
};

struct archive ARCHIVE;
int login_true = 0;


void read_all_accounts()
{
	FILE* users = fopen("C:\\Users\\mrrim\\source\\repos\\telegram\\telegram\\TEXT.txt", "r");

	int name_password_i = 0;
	int password_now = 0;
	int counter_accounts = 0;
	ARCHIVE.counter_accounts = 0;


	struct account acc;
	
	char text = fgetc(users); // ����� �����

	acc.name[name_password_i] = text;
	name_password_i++;

	if (users == 0)
	{
		printf("can be open");
	}

	for (; text != EOF;)
	{
		text = fgetc(users);


		if (password_now == 0 && text != ':')
		{
			acc.name[name_password_i] = text; // 2
			name_password_i++;
		}
		if (text == ':') //���� ���� ���������
		{
			acc.name[name_password_i] = '\0';
			name_password_i = 0;

			password_now = 1;//<-
			continue;
		}
		// ���������� ������

		
		if (password_now == 1 && text != ';')
		{
			acc.password[name_password_i] = text; //1 pass
			name_password_i++;
		}
		if (text == ';') //���� ������ ���������
		{
			acc.password[name_password_i] = '\0';
			name_password_i = 0;

			password_now = 0;//<-

			ARCHIVE.ACCOUNTS[ARCHIVE.counter_accounts] = acc;
			ARCHIVE.counter_accounts++;
		}
		
	}
}
 
void print_all_accounts()
{
	for  (int o = 0; o < ARCHIVE.counter_accounts; o++)
	{
		printf("%s %s \n", ARCHIVE.ACCOUNTS[o].name, ARCHIVE.ACCOUNTS[o].password);
	}
}

void registration()
{
	struct account new_account;

	printf("input your name here:");
	scanf("%s", new_account.name);
	Sleep(500);
	printf("input your password here:");
	scanf("%s", new_account.password);
	Sleep(500);

	ARCHIVE.ACCOUNTS[ARCHIVE.counter_accounts] = new_account;
	ARCHIVE.counter_accounts++;

	FILE* users = fopen("C:\\Users\\mrrim\\source\\repos\\telegram\\telegram\\TEXT.txt", "a");

	fprintf(users, "%s:%s;", new_account.name , new_account.password);

	login_true = 1;

	FILE* file_of_friend = fopen(new_account.name, "w");
}

int correct = 0;

void login()
{
	//1 ������ ����
	char name[60];
	char password[60];

	login_true = 0;
	
	printf("Write your login-> ");
	scanf(" %s", name);

	//���� ����� ����� ��� ���� //2 ������ ������

	for (int i = 0; i < ARCHIVE.counter_accounts; i++)
	{
		if (strcmp(name, ARCHIVE.ACCOUNTS[i].name) == 0)
		{
			Sleep(300);
			printf("ok, write password [%d]\n", i);//����� ��� ���������� 
			correct = i;
			break;
		}
		else if (strcmp(name, ARCHIVE.ACCOUNTS[i].name) != 0)
		{
			Sleep(100);
			printf("this name doesnt exests [%d]\n", i);
			continue;
		}
	}
	//2 ������ ������

	printf("Write your password-> ");
	scanf("%s", password);

	//��������� �� �������� ������ � ����    //stas:1234;

	if (strcmp(password, ARCHIVE.ACCOUNTS[correct].password) == 0)
	{
		Sleep(300);
		printf("Welcome %s\n", ARCHIVE.ACCOUNTS[correct].name);
		login_true = 1;
	}
	else if (strcmp(password, ARCHIVE.ACCOUNTS[correct].password) != 0)
	{
		Sleep(100);
		printf("password incorrect [%d]\n", correct);
		login();
	}
	
}

void menu()
{
//1 ����
	int action = 0;

	printf("----------TELESTAS----------\n ");
	printf("1. -------login-------------\n ");
	printf("2. -------Regestration------\n ");
	printf("3. -------Print-all-acc-----\n ");
	printf("Input action ");
	scanf("%d", &action);
	
	if (action == 1)
	{
		Sleep(500);
		system("cls");
		login();
	}
	else if (action == 2)
	{
		Sleep(500);
		system("cls");
		registration();		
	}
	else if (action == 3)
	{
		Sleep(500);
		system("cls");
		print_all_accounts();	
		system("cls");
		menu();
	}
//registation
//input action
}

void add_friend()
{
	//���� ���� �����
	char name_friend[30];
	int friend_found = 0;


	printf("Input your friend name: ");
	scanf("%s", name_friend);

	FILE* file_of_friend = fopen(ARCHIVE.ACCOUNTS[correct].name, "a");

	for (int i = 0; i < ARCHIVE.counter_accounts; i++)
	{
		if (strcmp(name_friend, ARCHIVE.ACCOUNTS[i].name) == 0)
		{
			Sleep(100);
			printf("Ok,this human registration in this site, now it's your friend\n");//������
			friend_found = i;
			fprintf(file_of_friend, "%s:", name_friend);
			break;

		}
		//���� ���� ���� ��� ���� ��� ��
		else if (strcmp(name_friend, ARCHIVE.ACCOUNTS[i].name) != 0)
		{
			Sleep(100);
			printf("Dont found[%d]\n", i);//�� ������
			continue;
		}
	}
}

void See_friend()
{
	FILE* file_of_friend = fopen(ARCHIVE.ACCOUNTS[correct].name, "r");
	
	char text_friend = ':';

	while (text_friend != EOF)
	{
		if (text_friend != EOF) //tipp //t t i p
		{
			text_friend = fgetc(file_of_friend);
			printf("%c", text_friend);
			
		}
		else if (text_friend == EOF)
		{
			break;
		}
	}
}

 /*FILE* users = fopen("C:\\Users\\mrrim\\source\\repos\\telegram\\telegram\\TEXT.txt", "r");

	
	
	
	char text = fgetc(users); // ����� �����

	acc.name[name_password_i] = text;
	name_password_i++;

	if (users == 0)
	{
		printf("can be open");
	}

	for (; text != EOF;)
	{
		text = fgetc(users);


		if (password_now == 0 && text != ':')
		{
			acc.name[name_password_i] = text; // 2
			name_password_i++;
		}
		if (text == ':') //���� ���� ���������
		{
			acc.name[name_password_i] = '\0';
			name_password_i = 0;

			password_now = 1;//<-
			continue;
		}
		// ���������� ������

		
		if (password_now == 1 && text != ';')
		{
			acc.password[name_password_i] = text; //1 pass
			name_password_i++;
		}
		if (text == ';') //���� ������ ���������
		{
			acc.password[name_password_i] = '\0';
			name_password_i = 0;

			password_now = 0;//<-

			ARCHIVE.ACCOUNTS[ARCHIVE.counter_accounts] = acc;
			ARCHIVE.counter_accounts++;
		}
		
	}*/











void menu_after_login()
{
	if (login_true == 1)
	{
		int action_for_2menu = 0;

		printf("----------TELESTAS @%s----------\n ", ARCHIVE.ACCOUNTS[correct].name);
		printf("1. -------Add-friend--------\n ");
		printf("2. -------See-friend--------\n" );
		printf("3. -------Send-message------\n ");
		printf("4. -------Read-message------\n ");
		printf("5. -------Exit--------------\n ");
		printf("Input action ");
		scanf("%d", &action_for_2menu);

		if (action_for_2menu == 1)
		{
			Sleep(500);
			system("cls");
			add_friend();
			menu_after_login();			
		}
		else if (action_for_2menu == 2)
		{
			system("cls");
			See_friend();
			Sleep(10000);
			menu_after_login();	
		}
		else if (action_for_2menu == 3)
		{
			printf("soon\n");
			Sleep(500);
			system("cls");
			menu_after_login();			
		}
		else if (action_for_2menu == 4)
		{
			printf("soon\n");
			Sleep(500);
			system("cls");
			menu_after_login();
		}
		else if (action_for_2menu == 5)
		{
			system("cls");
			printf("\nOK\n");
			Sleep(1500);
			return 0;
		}
	}
}

	//���� � ��� ������ ���� ���� � ������
	


	







	/*     
	void registration()
{
	struct account new_account;

	printf("input your name here:");
	scanf("%s", new_account.name);
	Sleep(500);
	printf("input your password here:");
	scanf("%s", new_account.password);
	Sleep(500);

	ARCHIVE.ACCOUNTS[ARCHIVE.counter_accounts] = new_account;
	ARCHIVE.counter_accounts++;

	FILE* users = fopen("C:\\Users\\mrrim\\source\\repos\\telegram\\telegram\\TEXT.txt", "a");

	fprintf(users, "%s:%s;", new_account.name , new_account.password);

	login_true = 1;

	
	
	
	
	*/











int main()
{
	 read_all_accounts();
	 menu();//hello stas
	 system("cls");
	 menu_after_login();
}
