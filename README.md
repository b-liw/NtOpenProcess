# NtOpenProcess

Bonjour , NtOpenProcess is for opening handles to process. When you use OpenProcess it pass down to NTDLL where NtOpenProcess gets called so using NTAPI for opening process handle is a step up. When NTDLL is used for Nt* or Zw* functions a system call gets performed and the actions are completed in kernel mode.

# Merci Bien!!