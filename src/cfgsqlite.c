#include <sqlite3.h>
#include "cfgsqlite.h"

extern sqlite3 *db;

int GetPrivateProfileString(const char *section, const char *key, const char *default_value, char *buffer, int buflen, const char *filepath)
{

    return strlen(buffer);
}

int WritePrivateProfileString(const char *section, const char *key, const char *value, const char *filepath)
{
    return 1;
}

sqlite3 *ConnectSQLite(char *fp)
{
    sqlite3 *handle;
    int retval;
    char create_table[100] = "CREATE TABLE IF NOT EXISTS FiSH (profile TEXT PRIMARY KEY,key TEXT NOT NULL)";

    retval = sqlite3_open(fp,&handle);
    // If connection failed, handle returns NULL
    if(retval)
    {
        printf("Database connection failed\n");
        return -1;
    }
    printf("Connection successful\n");

    retval = sqlite3_exec(handle,create_table,0,0,0);

    return handle;
}
