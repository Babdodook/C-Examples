#include"CoreManager.h"

int main()			//���� �޼ҵ�
{
	CoreManager::Create();		//�ھ�Ŵ��� ��ü ����
	CoreManager::GetInstance()->Run();								//���α׷� ���� �޼ҵ��� Run ȣ��
	CoreManager::Destroy();								//���α׷� ����� �޸� ����

	return 0;
}