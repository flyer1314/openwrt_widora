/*******************************************************************
 *   > File Name: remoteUpgrade.c
 *   > Author: fly
 *   > Mail: 1358326274@qq.com
 *   > Create Time: 2018年11月27日 星期二 16时05分41秒
 ******************************************************************/

#include "remoteUpgrade.h"

bool FW_IsExist(const char *fw_name)
{
    if(access(fw_name, F_OK) == 0)
    {
        printf("%s is exist .\n", fw_name);
        return true;    
    }
    else
    {
        return false;
    }
}

char* get_download_cmd(void)
{
    return ("scp "DEFAULT_USER"@"DEFAULT_HOST":"DEFAULT_SRC_PWD""DEFAULT_FW_NAME" "DEFAULT_DEST_PWD);
}

int downloadFW(void)
{
    if(FW_IsExist(DEFAULT_FW_NAME))
    {
        return EEXIST;
    }
    else
    {
        printf("%s will download .\n", DEFAULT_FW_NAME);
        return system(get_download_cmd());
    }
}

bool IsUpgrade(void)
{
    if(FW_IsExist(DEFAULT_FW_NAME) || (downloadFW() == 0))
    {
        char retValue = 0;
        printf("Whether to upgrade the firmware ?(y/n):");
        scanf("%c", &retValue);

        printf("Input :"RED"%c\n"NONE,retValue);

        switch(retValue)
        {
            case 'y':
                puts(GREEN"will upgrade"NONE);
                return true;
                break;
            case 'n':
                puts(YELLOW"will not upgrade"NONE);
                return false;
                break;
            default:
                puts(RED"error input"NONE);
                return false;
                break;
        }
    }
    return false;
}

char* get_upgrade_cmd(void)
{
    return ("sysupgrade "DEFAULT_FW_NAME);
}

int UpgradeFW(void)
{
    if(IsUpgrade() == true)
    {
        if(system(get_upgrade_cmd()))
        {
            printf(RED"%s , upgrade fail !\n"NONE, get_upgrade_cmd());
            return EXIT_FAILURE;
        }else
        {
            printf(GREEN"%s , upgrade success !\n"NONE, get_upgrade_cmd());
            return EXIT_SUCCESS;
        }
    }
    else
    {
        puts(YELLOW"no upgrade"NONE);
        return 2;
    }
}

int main(int argc, char* argv[])
{
    if(UpgradeFW() == 0)
    {
        puts(GREEN"Upgarde firmware success !"NONE);
    }
    else
    {
        puts(YELLOW"Upgarde firmware fail !"NONE);
    }

    return 0;
}
