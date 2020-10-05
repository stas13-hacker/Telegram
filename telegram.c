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
	
	char text = fgetc(users); // ПЕРША БУКВА

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
		if (text == ':') //якщо нейм закінчився
		{
			acc.name[name_password_i] = '\0';
			name_password_i = 0;

			password_now = 1;//<-
			continue;
		}
		// починаэтья пароль

		
		if (password_now == 1 && text != ';')
		{
			acc.password[name_password_i] = text; //1 pass
			name_password_i++;
		}
		if (text == ';') //якщо пароль закінчився
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
}

int correct = 0;

void login()
{
	//1 ввести нейм
	char name[60];
	char password[60];

	login_true = 0;
	
	printf("Write your login-> ");
	scanf(" %s", name);

	//якщо нейму немаэ тоді немає //2 ввести пароль

	for (int i = 0; i < ARCHIVE.counter_accounts; i++)
	{
		if (strcmp(name, ARCHIVE.ACCOUNTS[i].name) == 0)
		{
			Sleep(300);
			printf("ok, write password [%d]\n", i);//перши лог правильний 
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
	//2 ввести пароль

	printf("Write your password-> ");
	scanf("%s", password);

	//перевірити чи сходятся пароль і логін    //stas:1234;

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
//1 логін
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

void menu_after_login()
{
	if (login_true == 1)
	{
		int action_for_2menu = 0;

		printf("----------TELESTAS @%s----------\n ", ARCHIVE.ACCOUNTS[correct].name);
		printf("1. -------See-friends-------\n ");
		printf("2. -------Send-message------\n ");
		printf("3. -------Read-message------\n ");
		printf("4. -------Exit--------------\n ");
		printf("Input action ");
		scanf("%d", &action_for_2menu);

		if (action_for_2menu == 1)
		{
			printf("soon\n");
			Sleep(500);
			system("cls");
			menu_after_login();			
		}
		else if (action_for_2menu == 2)
		{
			printf("soon\n");
			Sleep(500);
			system("cls");
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
			system("cls");
			printf("\nOK\n");
			Sleep(1500);
			return 0;
		}
	}
}




int main()
{
	 read_all_accounts();
	 menu();//hello stas
	 system("cls");
	 menu_after_login();
}
