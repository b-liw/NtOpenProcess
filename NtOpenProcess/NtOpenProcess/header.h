#pragma once
#include <Windows.h>
#include <winternl.h>
#include <iostream>

typedef struct _CLIENT_ID
{
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

HANDLE NtOpenProcess(DWORD dwProcessId);