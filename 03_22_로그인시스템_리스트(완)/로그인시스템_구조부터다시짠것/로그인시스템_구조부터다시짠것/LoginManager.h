#include"LinkedList.h"
#include"User.h"

class LoginManager{
private:
	LinkedList<User*>* List;
	User * nowuser;
public:
	LoginManager();
	~LoginManager();

	void Init();
	void SignUp();
	bool Login();
	void Logout();
	void DeleteAcc();

	User * GetNowuser();
	void SetNowuser(User*);
};