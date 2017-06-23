#include "stdafx.h"
#include "Database_Interface.h"


Database_Interface::Database_Interface()
{
}


Database_Interface::~Database_Interface()
{
}


MYSQL_RES Database_Interface::SendQuery(string query)
{
	mysql.SendQuery(query);
	MYSQL_RES result = mysql.GetResult();
	mysql.FreeResult();

	return result;
}

void Database_Interface::SendQuery_void(string query)
{
	mysql.SendQuery(query);
}

bool Database_Interface::ConnectDB(string Host, string User, string Password, string DB_Name, int Port)
{
	return mysql.Initialize(Host, User, Password, DB_Name, Port);
}
