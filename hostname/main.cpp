#include <windows.h>
#include <iostream>
#include <winsock.h>
#pragma comment(lib, "ws2_32")
#include <sstream>
#include<string>


using namespace std;

void main()
{

	int WSA_return;
	WSADATA WSAData;

	WSA_return = WSAStartup(0x0101, &WSAData);

	/* 结构指针 */
	HOSTENT *host_entry = NULL;

	cout << "如果您已经输入完毕，请直接关闭退出" << endl;
	/*设置循环不断的读入*/


	do{
		char host_name[256];
		cout << "请您输入要解析的网址:";
		cin.getline(host_name, 256);

		if (WSA_return == 0)
		{
			/* 即要解析的域名或主机名 */

			host_entry = gethostbyname(host_name);
			printf("%s\n", host_name);
			if (host_entry != 0)
			{
				string str1, str2, str3, str4, str5;

				int i1 = host_entry->h_addr_list[0][0] & 0x00ff,
					i2 = host_entry->h_addr_list[0][1] & 0x00ff,
					i3 = host_entry->h_addr_list[0][2] & 0x00ff,
					i4 = host_entry->h_addr_list[0][3] & 0x00ff;


				stringstream strconvert1, strconvert2, strconvert3, strconvert4;
				strconvert1 << i1;//把int型转换成string类型的数据
				strconvert1 >> str1;
				strconvert2 << i2;
				strconvert2 >> str2;
				strconvert3 << i3;
				strconvert3 >> str3;
				strconvert4 << i4;
				strconvert4 >> str4;
				str5 = str1 + '.' + str2 + '.' + str3 + '.' + str4;
				cout << "以字符串形式输出：" << str5 << endl;

				printf("解析IP地址: ");
				printf("%d.%d.%d.%d\n",
					(host_entry->h_addr_list[0][0] & 0x00ff),//得到的id
					(host_entry->h_addr_list[0][1] & 0x00ff),
					(host_entry->h_addr_list[0][2] & 0x00ff),
					(host_entry->h_addr_list[0][3] & 0x00ff));
			}

		}
	} while (false);
	WSACleanup();

	system("pause");
}