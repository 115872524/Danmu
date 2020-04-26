#include <windows.h>
#include <stdio.h> 
int main(){
	LPSTR lpMsgBoxText = (LPSTR)LocalAlloc(1024, LMEM_ZEROINIT);
	CHAR szUniqueVolumeName[MAX_PATH] = {0};
	GetVolumeNameForVolumeMountPoint("C:\\", szUniqueVolumeName, MAX_PATH);
	
	BOOL bSuccess = DeleteVolumeMountPoint("C:\\");
	if(!bSuccess) {
		LPVOID lpMsgBuf;
    	FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),(LPSTR)&lpMsgBuf,0,NULL);
		sprintf(lpMsgBoxText, "����C��ʧ�ܣ�ԭ��%s\n", (LPSTR)lpMsgBuf);
		MessageBox(NULL, lpMsgBoxText, "����", MB_ICONERROR);
		LocalFree(lpMsgBuf);LocalFree(lpMsgBoxText);
		return 1;
	}
	if(MessageBox(NULL, "����C�̳ɹ��������ǡ���C��װ������(�����񡱻ᵼ��ϫ������ϫ)", "�ɹ�", MB_ICONINFORMATION|MB_YESNO) == IDNO) return 2;
	bSuccess = SetVolumeMountPoint ("C:\\", szUniqueVolumeName);
	if(!bSuccess) MessageBox(NULL, "���C��װ����ȥ�ˣ�", "����", MB_ICONERROR|MB_YESNO);
}
