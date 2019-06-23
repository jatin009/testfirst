/*
 *Note: Compilation command should be [g++ main.cpp `mysql_config --cflags --libs`]
 *	Pass your own values in variables SERVER, USER, PASSWORD and DATABASE
 *	In case [#include <mysql/mysql.h>] does not work, use [#include <usr/include/mysql/mysql.h>]
 *	Also take care of 6th parameter (port no.) in mysql_real_connect function as per your configurations.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <mysql/mysql.h>

using namespace std;

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "root123"
#define DATABASE "test"

int main()
{
	cout << "India" << endl;

	MYSQL * connect;
	connect = mysql_init(NULL);

	if (!connect)
	{
		cout << "MySQL Initialization Failed." << endl;
		return 1;
	}

	connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

	if (connect)
	{
		cout << "Connection successful." << endl;
	}
	else
	{
		cout << "Connection failed." << endl;
		return 1;
	}

	MYSQL_RES * res_set;
	MYSQL_ROW row;

	mysql_query (connect, "show tables");

	unsigned int i=0;
	
	res_set = mysql_store_result(connect);

	unsigned int numrows = mysql_num_rows(res_set);
	cout << "Tables in " << DATABASE << " database" << endl;

	while ( (row = mysql_fetch_row(res_set))!=NULL )
		cout << row[i] << endl;

	mysql_close (connect);

	return 0;
}
