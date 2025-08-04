#pragma once
#include <mysql.h>
public ref class MySqlConnectionManager
{
public:
	static MYSQL* mysql;

	static void InitializeConnection()
	{
		mysql = mysql_init(nullptr);
		// Additional connection setup can be performed here if needed
	}

	static void CloseConnection()
	{
		if (mysql)
		{
			mysql_close(mysql);
			mysql = nullptr;  // Reset the pointer after closing
		}
	}
};