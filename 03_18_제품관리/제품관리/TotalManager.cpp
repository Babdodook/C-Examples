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
			cout << "잘못 입력하셨습니다" << endl;
		}
	}
}

// 제품 입고
void TotalManager::FruitIn() {
	int fruitnum;
	int quantity;
	int cost;

	Nowfruit = nullptr;

	cout << "<<제품 리스트>>" << endl;
	cout << "1. 사과" << endl;
	cout << "2. 배" << endl;
	cout << "3. 바나나" << endl;
	cout << "4. 자몽" << endl;
	cout << "5. 포도" << endl;
	
	cout << "제품 번호: ";
	cin >> fruitnum;

	bool flag = false;
	for (int i = 0;i < MAXSIZE;i++) {
		if (fruitArr[i]->GetFruitNum() == fruitnum) {
			Nowfruit = fruitArr[i];
			flag = true;
		}
	}

	if (!flag) {
		cout << "존재하지 않는 제품번호 입니다" << endl;
		return;
	}

	cout << "수량: ";
	cin >> quantity;


	if ((Nowfruit->GetQuantity() + quantity) > 10) {
		int index = 10 - Nowfruit->GetQuantity();
		Nowfruit->SetQuantity(Nowfruit->GetQuantity() + index);
		cout << index << "개가 입고되었습니다" << endl;
		cout << "입고 가능한 갯수가 다 찼습니다. 더이상 입고가 불가능합니다" << endl;
	}
	else
		Nowfruit->SetQuantity(Nowfruit->GetQuantity()+quantity);

	if (Nowfruit->GetCost() == 0) {
		cout << "단가: ";
		cin >> cost;

		Nowfruit->SetCost(cost);
	}
}

// 제품 출고
void TotalManager::FruitOut() {
	int fruitnum;
	int quantity;
	int select=0;
	bool flag;

	Nowfruit = nullptr;

	while (1) {
		cout << "<<제품 리스트>>" << endl;
		cout << "1. 사과" << endl;
		cout << "2. 배" << endl;
		cout << "3. 바나나" << endl;
		cout << "4. 자몽" << endl;
		cout << "5. 포도" << endl;

		cout << "제품 번호: ";
		cin >> fruitnum;

		flag = false;
		
		for (int i = 0; i < MAXSIZE; i++) {
			if (fruitArr[i]->GetFruitNum() == fruitnum) {
				Nowfruit = fruitArr[i];
				flag = true;
			}
		}

		if (Nowfruit->GetQuantity() == 0) {
			cout << "없는 제품입니다 다시입력하세요" << endl;
			cout << "다른 출고상품을 입력하시겠습니까?(yes:1. no:2)";
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

	cout << "수량: ";
	cin >> quantity;

	if (quantity < 0) {
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}
	if (Nowfruit->GetQuantity() == 0) {
		cout << "출고 가능한 제품이 없습니다" << endl;
		return;
	}
	if (quantity >= 10) {
		cout << Nowfruit->GetQuantity() << "개가 출고되었습니다" << endl;
		Nowfruit->SetQuantity(0);
		Nowfruit->SetCost(0);
		return;
	}
	
	if (Nowfruit->GetQuantity() >= quantity) {
		Nowfruit->SetQuantity((Nowfruit->GetQuantity() - quantity));
		cout << "남은수량: " << Nowfruit->GetQuantity() << endl;
	}
	else if (Nowfruit->GetQuantity() <= quantity) {
		Nowfruit->SetQuantity((quantity - Nowfruit->GetQuantity()));
		cout << "남은수량: " << Nowfruit->GetQuantity() << endl;
	}
	
	cout << quantity << "개가 출고되었습니다" << endl;

	if (Nowfruit->GetQuantity() == 0)
		Nowfruit->SetCost(0);
}

// 제품 출력
void TotalManager::ShowState() {
	for (int i = 0; i < MAXSIZE; i++) {
		if (fruitArr[i]->GetQuantity() != 0) {
			cout << "제품명: ";
			switch (i+1) {
			case FRUITNAME::APPLE:
				cout << "사과" << endl;
				break;
			case FRUITNAME::PEAR:
				cout << "배" << endl;
				break;
			case FRUITNAME::BANANA:
				cout << "바나나" << endl;
				break;
			case FRUITNAME::GRAPEFRUIT:
				cout << "자몽" << endl;
				break;
			case FRUITNAME::GRAPE:
				cout << "포도" << endl;
				break;
			}
			cout << "단가:" << fruitArr[i]->GetCost() << endl;
			cout << "수량:" << fruitArr[i]->GetQuantity() << endl;
		}
	}
}

int TotalManager::Mainmenu() {
	int select;
	cout << "제품관리" << endl;
	cout << "1. 제품입고" << endl;
	cout << "2. 제품출고" << endl;
	cout << "3. 제품출력" << endl;
	cout << "4. 종료" << endl;
	cin >> select;
	return select;
}