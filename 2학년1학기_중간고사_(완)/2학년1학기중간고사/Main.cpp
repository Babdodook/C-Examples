#include"CoreManager.h"

int main()			//���� �޼ҵ�
{
	CoreManager* CoreM = new CoreManager();		//�ھ�Ŵ��� ��ü ����
	CoreM->Run();								//���α׷� ���� �޼ҵ��� Run ȣ��
	delete CoreM;								//���α׷� ����� �޸� ����

	return 0;
}