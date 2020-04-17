#include"TotalManager.h"

TotalManager::TotalManager(){
	memset(fruitArr, 0, NULL);
}

TotalManager::~TotalManager(){
	for (int i = 0; i < MAXSIZE; i++) {
		delete fruitArr[i];
		fruitArr[i] = nullptr;
	}
}

void TotalManager::Init() {
	for (int i = 0;i < MAXSIZE;i++) {
		fruitArr[i] = new Fruit(i + 1, 0, 0);
	}
}

void TotalManager::Run() {
	Init();

	while (1) {
		switch (Mainmenu()) {
		case MAINMENU::FRUITIN:
			FruitIn();
			break;
		case MAINMENU::FRUITOUT:
			FruitOut();
			break;
		case MAINMENU::SHOW:
			ShowState();
			break;
		case MAINMENU::EXIT:
			exit(0);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		}
	}
}

// ��ǰ �԰�
void TotalManager::FruitIn() {
	int fruitnum;
	int quantity;
	int cost;

	Nowfruit = nullptr;

	cout << "<<��ǰ ����Ʈ>>" << endl;
	cout << "1. ���" << endl;
	cout << "2. ��" << endl;
	cout << "3. �ٳ���" << endl;
	cout << "4. �ڸ�" << endl;
	cout << "5. ����" << endl;
	
	cout << "��ǰ ��ȣ: ";
	cin >> fruitnum;

	bool flag = false;
	for (int i = 0;i < MAXSIZE;i++) {
		if (fruitArr[i]->GetFruitNum() == fruitnum) {
			Nowfruit = fruitArr[i];
			flag = true;
		}
	}

	if (!flag) {
		cout << "�������� �ʴ� ��ǰ��ȣ �Դϴ�" << endl;
		return;
	}

	cout << "����: ";
	cin >> quantity;


	if ((Nowfruit->GetQuantity() + quantity) > 10) {
		int index = 10 - Nowfruit->GetQuantity();
		Nowfruit->SetQuantity(Nowfruit->GetQuantity() + index);
		cout << index << "���� �԰�Ǿ����ϴ�" << endl;
		cout << "�԰� ������ ������ �� á���ϴ�. ���̻� �԰� �Ұ����մϴ�" << endl;
	}
	else
		Nowfruit->SetQuantity(Nowfruit->GetQuantity()+quantity);

	if (Nowfruit->GetCost() == 0) {
		cout << "�ܰ�: ";
		cin >> cost;

		Nowfruit->SetCost(cost);
	}
}

// ��ǰ ���
void TotalManager::FruitOut() {
	int fruitnum;
	int quantity;
	int select=0;
	bool flag;

	Nowfruit = nullptr;

	while (1) {
		cout << "<<��ǰ ����Ʈ>>" << endl;
		cout << "1. ���" << endl;
		cout << "2. ��" << endl;
		cout << "3. �ٳ���" << endl;
		cout << "4. �ڸ�" << endl;
		cout << "5. ����" << endl;

		cout << "��ǰ ��ȣ: ";
		cin >> fruitnum;

		flag = false;
		
		for (int i = 0; i < MAXSIZE; i++) {
			if (fruitArr[i]->GetFruitNum() == fruitnum) {
				Nowfruit = fruitArr[i];
				flag = true;
			}
		}

		if (Nowfruit->GetQuantity() == 0) {
			cout << "���� ��ǰ�Դϴ� �ٽ��Է��ϼ���" << endl;
			cout << "�ٸ� ����ǰ�� �Է��Ͻðڽ��ϱ�?(yes:1. no:2)";
			cin >> select;	
		}

		if (select) {
			flag = false;
		}
		if (select == 2)
			break;
		if (flag)
			break;
	}

	if (select == 2)
		return;

	cout << "����: ";
	cin >> quantity;

	if (quantity < 0) {
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		return;
	}
	if (Nowfruit->GetQuantity() == 0) {
		cout << "��� ������ ��ǰ�� �����ϴ�" << endl;
		return;
	}
	if (quantity >= 10) {
		cout << Nowfruit->GetQuantity() << "���� ���Ǿ����ϴ�" << endl;
		Nowfruit->SetQuantity(0);
		Nowfruit->SetCost(0);
		return;
	}
	
	if (Nowfruit->GetQuantity() >= quantity) {
		Nowfruit->SetQuantity((Nowfruit->GetQuantity() - quantity));
		cout << "��������: " << Nowfruit->GetQuantity() << endl;
	}
	else if (Nowfruit->GetQuantity() <= quantity) {
		Nowfruit->SetQuantity((quantity - Nowfruit->GetQuantity()));
		cout << "��������: " << Nowfruit->GetQuantity() << endl;
	}
	
	cout << quantity << "���� ���Ǿ����ϴ�" << endl;

	if (Nowfruit->GetQuantity() == 0)
		Nowfruit->SetCost(0);
}

// ��ǰ ���
void TotalManager::ShowState() {
	for (int i = 0; i < MAXSIZE; i++) {
		if (fruitArr[i]->GetQuantity() != 0) {
			cout << "��ǰ��: ";
			switch (i+1) {
			case FRUITNAME::APPLE:
				cout << "���" << endl;
				break;
			case FRUITNAME::PEAR:
				cout << "��" << endl;
				break;
			case FRUITNAME::BANANA:
				cout << "�ٳ���" << endl;
				break;
			case FRUITNAME::GRAPEFRUIT:
				cout << "�ڸ�" << endl;
				break;
			case FRUITNAME::GRAPE:
				cout << "����" << endl;
				break;
			}
			cout << "�ܰ�:" << fruitArr[i]->GetCost() << endl;
			cout << "����:" << fruitArr[i]->GetQuantity() << endl;
		}
	}
}

int TotalManager::Mainmenu() {
	int select;
	cout << "��ǰ����" << endl;
	cout << "1. ��ǰ�԰�" << endl;
	cout << "2. ��ǰ���" << endl;
	cout << "3. ��ǰ���" << endl;
	cout << "4. ����" << endl;
	cin >> select;
	return select;
}