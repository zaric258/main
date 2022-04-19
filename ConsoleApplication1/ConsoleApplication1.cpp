#include<iostream>
#include<cstdio>
#include <io.h> 
#include <windows.h> 
#include <direct.h>
using namespace std;

void delete_last(const char* fileName)
{
	FILE* file1, * file2 = nullptr;
	int c = 0;
	char newFile[256];
	char tmp[256];
	cout << "Enter name of new file: ";
	cin >> newFile;
	if (fopen_s(&file1, fileName, "r") == NULL)
	{
		while (!feof(file1))
		{
			fgets(tmp, 256, file1);
			c++;
		}
	}
	fclose(file1);
	if (fopen_s(&file1, fileName, "r") == NULL)
	{
		int i = 0;
		fopen_s(&file2, newFile, "w");
		while (i < c - 1)
		{
			fgets(tmp, 256, file1);
			fputs(tmp, file2);
			i++;
		}
	}
	fclose(file1);
	fclose(file2);
}

void the_long(const char* fileName)
{
	FILE* file1;
	char tmp[256];
	int maxLeng = 0;
	char theLong[256];
	if (fopen_s(&file1, fileName, "r") == NULL)
	{
		while (!feof(file1))
		{
			fgets(tmp, 256, file1);
			if (maxLeng < strlen(tmp)) { maxLeng = strlen(tmp); strcpy_s(theLong, tmp); }
		}
		fclose(file1);
	}
	cout << "the long row: " << theLong;
}

void word_try(const char* fileName, const char* word)
{
	FILE* file1;
	char tmp[256];
	int c = 0;
	if (fopen_s(&file1, fileName, "r") == NULL)
	{
		while (!feof(file1))
		{
			fgets(tmp, 256, file1);
			char* ttmp = strstr(tmp, word);
			do
			{
				if (ttmp)
				{
					c++;
					ttmp[0] = '.';
					ttmp = strstr(tmp, word);
				}
			} while (ttmp);
		}
		fclose(file1);
	}
	cout << "word " << word << ": " << c << endl;
}

int main()
{
	do
	{
		cout << "1 - Delete last;\n2 - Long word;\n3 - Word try;\n";
		int main;
		cin >> main;
		switch (main)
		{
		case 1:
			delete_last("file.txt");
			break;
		case 2:
			the_long("file.txt");
			break;
		case 3:
			word_try("file.txt", "new");
			break;
		}
	} while (main != 0);
}