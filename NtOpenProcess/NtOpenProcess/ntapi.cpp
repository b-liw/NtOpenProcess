#include "header.h"

// definition for the function structure of NtOpenProcess
typedef NTSTATUS(NTAPI *pNtOpenProcess)(PHANDLE ProcessHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId);
pNtOpenProcess NtOpenProcess_;

HANDLE NtOpenProcess(DWORD dwProcessId)
{
	// get the address
	FARPROC fpNtOpenProcess = GetProcAddress(GetModuleHandle("NTDLL"), "NtOpenProcess");
	if (!fpNtOpenProcess) return 0; // dont continue or itll crash
	NtOpenProcess_ = (pNtOpenProcess)fpNtOpenProcess; // setup memory
	HANDLE ProcessHandle = 0; // used later to store the process handle
	OBJECT_ATTRIBUTES ObjectAttributes; // we need this for the call as its required
	CLIENT_ID ClientId; // contains information for the call like the PID target
	InitializeObjectAttributes(&ObjectAttributes, 0, 0, 0, 0); // set values to zero
	ClientId.UniqueProcess = (PVOID)dwProcessId;
	ClientId.UniqueThread = 0;
	NtOpenProcess_(&ProcessHandle, MAXIMUM_ALLOWED, &ObjectAttributes, &ClientId); // you can do NT_SUCCESS or set to an NTSTATUS and check the return for error handling 
	return ProcessHandle; // return process handle
}