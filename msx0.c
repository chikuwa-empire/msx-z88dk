/*
  Copyright 2023 CHIKUWA TEIKOKU
*/
#include <stdio.h>
#include <string.h>
#include "msx0.h"


int iotfindc(const char* p_path)
{
    int ret;
    char r[2];

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x11);
    outp(IOT_PORT, 0x80);
    inp(IOT_PORT);

    r[0] = inp(IOT_PORT);
    r[1] = inp(IOT_PORT);

    ret = *(int*)r;

    return ret;
}

int iotfind(const char* p_path, char** p_list)
{
    int count, i, r, l;

    count = iotfindc(p_path);

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x13);
    outp(IOT_PORT, 0x80);

    for (r = 0; r < count; r++)
    {
        l = inp(IOT_PORT);

        p_list[r] = (char*)malloc(sizeof(char) * l + 1);

        for (i = 0; i < l; i++)
        {
            p_list[r][i] = inp(IOT_PORT);
        }
        p_list[r][l] = 0x00;
    }

    return count;
}

int iotgeti(const char* p_path, int* p_ret)
{
    char r[2];

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x80);

    inp(IOT_PORT);
    r[0] = inp(IOT_PORT);
    r[1] = inp(IOT_PORT);

    *p_ret = *(int*)r;

    return 2;
}

int iotgets(const char* p_path, char* p_str)
{
    int i, l;

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x03);
    outp(IOT_PORT, 0x80);

    l = inp(IOT_PORT);
    for (i = 0; i < l; i++)
    {
        p_str[i] = inp(IOT_PORT);
    }
    p_str[l] = 0x00;

    return l;
}

int iotgetb(const char* p_path, char* p_bytes)
{
    int i, l;

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x03);
    outp(IOT_PORT, 0x80);

    l = inp(IOT_PORT);
    for (i = 0; i < l; i++)
    {
        p_bytes[i] = inp(IOT_PORT);
    }

    return l;
}

int iotputi(const char* p_path, int val)
{
    char p[2];

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x41);
    outp(IOT_PORT, 0xC0);

    outp(IOT_PORT, 2);
    memcpy(p, &val, 2);
    outp(IOT_PORT, p[0]);
    outp(IOT_PORT, p[1]);

    return inp(IOT_PORT);
}

int iotputs(const char* p_path, const char* p_str)
{
    int i, l;

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x43);
    outp(IOT_PORT, 0xC0);

    l = strlen(p_str);
    outp(IOT_PORT, l);
    for (i = 0; i < l; i++)
    {
        outp(IOT_PORT, p_str[i]);
    }
    outp(IOT_PORT, 0);

    return inp(IOT_PORT);
}

int iotputb(const char* p_path, const char* p_bytes, unsigned char len)
{
    int i, l;

    if (sendnode(p_path) != 0)
    {
        printf("The specified device was not found.\n");
        printf("%s\n", p_path);
        return -1;
    }

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x43);
    outp(IOT_PORT, 0xC0);

    outp(IOT_PORT, len);
    for (i = 0; i < len; i++)
    {
        outp(IOT_PORT, p_bytes[i]);
    }

    return inp(IOT_PORT);
}

int sendnode(const char* p_path)
{
    int i, l;

    l = strlen(p_path);

    outp(IOT_PORT, 0xE0);
    outp(IOT_PORT, 0x01);
    outp(IOT_PORT, 0x53);
    outp(IOT_PORT, 0xC0);

    outp(IOT_PORT, l);
    for (i = 0; i < l; i++)
    {
        outp(IOT_PORT, p_path[i]);
    }
    outp(IOT_PORT, 0x00);

    return inp(IOT_PORT);
}
